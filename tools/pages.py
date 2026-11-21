"""Build the GitHub Pages function explorer from the same ExeFS index as the CLI."""

import argparse
import base64
from collections import Counter, defaultdict
from contextlib import closing
import gzip
import hashlib
import itertools
import json
from pathlib import Path
import re
import shutil
import sqlite3
import subprocess
import sys
import tempfile
from io import BytesIO
from urllib.request import urlopen
from zipfile import ZipFile

from eow import Exporter, output_handle, summary, verified_image
from images import BASE, ROOT, Function
from indexer import select_function, write_graph
from match import compile_object, measure, object_functions, place_branches, target_lookup

SHIFT = 15
BLOCKS_PER_JOB = 48
PUBLIC_LIMIT = 1_000_000_000
CC = [sys.executable, "-m", "ziglang", "cc"]
GROUP_FLAGS = ("-fPIC", "-fsemantic-interposition")
FIXTURES = [(rva, "setters.c") for rva in (0xbde10, 0xbde3c, 0xbde5c, 0xbde7c, 0xbde9c)] + [(0x2362258, "tree.c")]
FALLBACK = re.compile(r"^static void f_[0-9a-f]+\(Cpu \*c\) \{\n[^}]+\}\n", re.M)
DECODER_URL = "https://github.com/AlexAltea/capstone.js/releases/download/v5.0.9/capstone_arm64_5.0.9.zip"
DECODER_SHA = "7ef8e92c49c3fd75db3fe1078e45ba80f02147e094f3754c8cc438ed543f47eb"


def json_file(path, value):
    with output_handle(path) as out:
        json.dump(value, out, ensure_ascii=False, separators=(",", ":"))
        out.write("\n")


def digest(path):
    with path.open("rb") as stream:
        return hashlib.file_digest(stream, "sha256").hexdigest()


def block_counts(db, module):
    return dict(db.execute("SELECT (addr-?) >> ?,count(*) FROM functions WHERE module=? GROUP BY 1 ORDER BY 1",
                           (BASE[module], SHIFT, module)))


def job_plan(db):
    jobs = []
    for mod in BASE:
        for key, group in itertools.groupby(block_counts(db, mod), lambda block: block // BLOCKS_PER_JOB):
            blocks = list(group)
            jobs.append(dict(module=mod, first=blocks[0], last=blocks[-1], key=f"{mod}-{key:03}"))
    return jobs


def compile_group(db, module, image, rows, folder):
    """Keep function boundaries in a grouped TU. Isolate a compiler error to its own function."""
    src, obj = folder / "group.c", folder / "group.o"
    fallbacks = set()

    def unique_stub(match):
        stub = match[0]
        if stub in fallbacks:
            return ""
        fallbacks.add(stub)
        return stub

    with src.open("w", encoding="utf-8") as out:
        out.write('#include "cpu.h"\n')
        for fn, _ in rows:
            out.write(f"__attribute__((noinline)) void f_{fn.start:x}(Cpu *);\n")
        for _, rec in rows:
            out.write(FALLBACK.sub(unique_stub, rec["c"]))
    try:
        compile_object(CC, "cortex_a57", "O2", src, obj, extra_flags=GROUP_FLAGS,
                       stdout=subprocess.DEVNULL, stderr=subprocess.PIPE, text=True)
    except subprocess.CalledProcessError as err:
        if err.returncode < 0 or not err.stderr or "error:" not in err.stderr:
            raise RuntimeError(f"Compiler failed: {err.stderr}") from err
        if len(rows) == 1:
            rows[0][1]["rebuild"] = {"error": err.stderr.replace(str(folder), "<build>")[:2500]}
            return
        mid = len(rows) // 2
        compile_group(db, module, image, rows[:mid], folder)
        compile_group(db, module, image, rows[mid:], folder)
        return
    with object_functions(obj) as read:
        for fn, rec in rows:
            symbol = f"f_{fn.start:x}"
            raw, relocs = read(symbol)
            resolve = target_lookup(db, module, fn.start, symbol)
            placed, records = place_branches(raw, relocs, fn.start, resolve)
            orig = image.nso.image[fn.start-image.base:fn.end-image.base]
            metrics = measure(orig, raw, placed, records)
            rec["rebuild"] = {
                "size": len(placed), "different": metrics["placed_different_bytes"], "rawDifferent": metrics["raw_different_bytes"],
                "first": metrics["first_different_byte"], "exact": metrics["exact"], "applied": metrics["applied_relocations"],
                "pending": metrics["pending_relocations"], "bytes": base64.b64encode(placed).decode("ascii"),
                "fixups": [[r["offset"], r["type"], r["symbol"], r.get("destination")] for r in records],
            }


def edge_groups(db, column, low, high):
    groups = defaultdict(list)
    if column == "src":
        query = "SELECT src,site,kind,target,detail FROM edges WHERE src>=? AND src<? ORDER BY src,site,kind,target"
    else:
        query = "SELECT target,site,kind,src,detail FROM edges WHERE target>=? AND target<? ORDER BY target,src,site,kind"
    for address, site, kind, other, detail in db.execute(query, (low, high)):
        groups[address].append([site, kind, other, detail])
    return groups


def build_block(db, image, exporter, block, scratch, output):
    base = image.base
    low = base + (block << SHIFT)
    high = low + (1 << SHIFT)
    outgoing = edge_groups(db, "src", low, high)
    incoming = edge_groups(db, "target", low, high)
    rows = []
    article = {}
    batch_size = 0
    for row in db.execute("SELECT addr,end,name,evidence FROM functions WHERE module=? AND addr>=? AND addr<? ORDER BY addr",
                          (image.name, low, high)):
        fn = Function(*row)
        rec = {"asm": exporter.render(fn, "asm"), "c": exporter.render(fn, "c"),
               "outgoing": outgoing[fn.start], "incoming": incoming[fn.start]}
        article[f"{fn.start-base:x}"] = rec
        rows.append((fn, rec))
        batch_size += len(rec["c"])
        if batch_size >= 750_000 or len(rows) >= 256:
            compile_group(db, image.name, image, rows, scratch)
            rows = []
            batch_size = 0
    if rows:
        compile_group(db, image.name, image, rows, scratch)
    path = output / "data" / image.name / f"{block:x}.json.gz"
    json_file(path, article)
    errors = sum("error" in rec["rebuild"] for rec in article.values())
    return dict(block=block, functions=len(article), errors=errors,
                exact=sum(bool(rec["rebuild"].get("exact")) for rec in article.values()), sha256=digest(path))


def shard(args, db):
    image = verified_image(db, args.exefs, args.module)
    exporter = Exporter(db, image)
    blocks = [b for b in block_counts(db, args.module) if args.first <= b <= args.last]
    if not blocks:
        raise ValueError("No function starts in the requested range")
    records = []
    args.out.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(dir=args.out) as tmp:
        for block in blocks:
            records.append(build_block(db, image, exporter, block, Path(tmp), args.out))
            print(f"{args.module} block {block:x}: {records[-1]['functions']} functions", flush=True)
    if sum(r["functions"] - r["errors"] for r in records) == 0:
        raise ValueError("The compiler produced no objects for this shard")
    json_file(args.out / "parts" / f"{args.module}-{args.first:x}.json",
              dict(module=args.module, build=image.build_id, blocks=records))


def reference_comparisons(db_path, exefs, output):
    """Run the standalone matching workflow for nnMain and every native C fixture."""
    entries = []
    with tempfile.TemporaryDirectory(dir=output.parent) as tmp:
        folder = Path(tmp)
        for rva, source in [(0x360b70, "nnMain.c"), *FIXTURES]:
            mod = "main"
            work = folder / f"{rva:x}"
            path = ROOT / ("analysis" if source == "nnMain.c" else "matching") / source
            cmd = [sys.executable, str(ROOT / "tools/match.py"), f"{mod}:{rva:#x}", "--source", str(path),
                   "--exefs", str(exefs), "--db", str(db_path), "--opts", "O1", "O2", "O3", "Os", "Oz", "--out", str(work)]
            subprocess.run(cmd, check=True)
            report = json.loads((work / "report.json").read_text())
            selected = next(c for c in report["candidates"] if c["profile"] == report["selected"])
            details = dict(report=report, source=path.read_text(), diff=(work / "diff.txt").read_text(),
                           assembly=(work / "rebuilt.asm").read_text(), fixups=json.loads((work / "relocations.json").read_text()))
            if source == "tree.c":
                linked = work / "tree.elf"
                subprocess.run([sys.executable, "-m", "ziglang", "ld.lld", "-m", "aarch64elf", "-Ttext=0x7002362258",
                                "--defsym=_ZdlPv=0x7002833e20", "-e", "f_7002362258", "-o", str(linked), str(work / "rebuilt.o")], check=True)
                subprocess.run([*cmd[:3], "--linked", str(linked), "--exefs", str(exefs), "--db", str(db_path),
                                "--out", str(work / "linked")], check=True)
                details["linked"] = json.loads((work / "linked/report.json").read_text())
            json_file(output / "comparisons" / f"{rva:x}.json.gz", details)
            entries.append(dict(module=mod, rva=rva, source=source, original=report["original_bytes"],
                                profile=report["selected"], size=selected["compiled_bytes"],
                                different=selected["placed_different_bytes"], exact=selected["exact"]))
    return entries


def install_decoder(output, archive):
    if archive:
        payload = archive.read_bytes()
    else:
        with urlopen(DECODER_URL, timeout=60) as response:
            payload = response.read()
    if hashlib.sha256(payload).hexdigest() != DECODER_SHA:
        raise ValueError("Capstone.js ARM64 release checksum mismatch")
    dest = output / "decoder"
    dest.mkdir(exist_ok=True)
    with ZipFile(BytesIO(payload)) as packed:
        for filename in ("capstone_arm64.js", "capstone_arm64.wasm"):
            (dest / filename).write_bytes(packed.read(filename))


def finish(args, db):
    output = args.out
    if output.exists() and any(output.iterdir()):
        raise ValueError("Choose an empty --out directory for the assembled site")
    output.mkdir(parents=True, exist_ok=True)
    counts = {name: block_counts(db, name) for name in BASE}
    expected = {(name, k): v for name, blocks in counts.items() for k, v in blocks.items()}
    checked = set()
    totals = defaultdict(Counter)
    builds = dict(db.execute("SELECT name,build_id FROM modules"))
    for part in sorted((args.shards / "parts").glob("*.json")):
        meta = json.loads(part.read_text())
        name = meta["module"]
        if builds.get(name) != meta["build"]:
            raise ValueError(f"Mismatching input build in {part}")
        for row in meta["blocks"]:
            b = row["block"]
            key = (name, b)
            if key in checked or expected.get(key) != row["functions"]:
                raise ValueError(f"Incorrect or duplicated function block {key}")
            rel = Path("data") / name / f"{b:x}.json.gz"
            if digest(args.shards / rel) != row["sha256"]:
                raise ValueError(f"Damaged function payload {rel}")
            dest = output / rel
            dest.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(args.shards / rel, dest)
            checked.add(key)
            totals[name].update({k:row[k] for k in ("functions", "errors", "exact")})
    if checked != set(expected):
        raise ValueError(f"Missing {len(set(expected)-checked)} required function blocks")
    report = summary(db)
    _, root = select_function(db, "main:nnMain")
    reach = {r[0] for r in db.execute("""WITH RECURSIVE reach(a) AS (VALUES(?) UNION SELECT e.target FROM reach r
        JOIN edges e ON e.src=r.a JOIN functions f ON f.addr=e.target WHERE e.kind!='fallthrough') SELECT a FROM reach""", (root.start,))}
    modules = []
    for name, base in BASE.items():
        catalog = [[addr-base, end-addr, label, evidence, int(addr in reach)]
                   for addr,end,label,evidence in db.execute(
                       "SELECT addr,end,name,evidence FROM functions WHERE module=? ORDER BY addr", (name,))]
        json_file(output / "catalog" / f"{name}.json.gz", catalog)
        modules.append(dict(name=name, base=base, build=builds[name], **totals[name]))
    with output_handle(output / "nnMain.graph.tsv.gz") as stream:
        write_graph(db, root.start, None, stream)
    comparisons = reference_comparisons(args.db.resolve(), args.exefs.resolve(), output)
    manifest = dict(revision=args.revision, reportMode="detailed", shift=SHIFT, modules=modules, baseline=report,
                    functions=sum(r["functions"] for r in modules), comparisons=comparisons)
    json_file(output / "manifest.json", manifest)
    shutil.copytree(ROOT / "web", output, dirs_exist_ok=True)
    install_decoder(output, args.decoder_archive)
    public_files = [p for p in output.rglob("*") if p.is_file()]
    for p in public_files:
        p.chmod(0o644)
    size = sum(p.stat().st_size for p in public_files)
    print(f"Local HTML verified: {manifest['functions']:,} entries, {len(checked):,} blocks, {size:,} bytes")


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--db", type=Path, default=ROOT / "build/index.sqlite")
    p.add_argument("--exefs", type=Path, default=ROOT / "ExeFS")
    cmds = p.add_subparsers(dest="cmd", required=True)
    cmds.add_parser("plan")
    sh = cmds.add_parser("shard")
    sh.add_argument("module", choices=list(BASE))
    sh.add_argument("first", type=int)
    sh.add_argument("last", type=int)
    sh.add_argument("--out", type=Path, default=ROOT / "build/shards")
    pub = cmds.add_parser("finish")
    pub.add_argument("--shards", type=Path, default=ROOT / "build/shards")
    pub.add_argument("--out", type=Path, default=ROOT / "build/site")
    pub.add_argument("--revision", default="local")
    pub.add_argument("--decoder-archive", type=Path, help="use a local copy of the pinned Capstone.js release")
    full = cmds.add_parser("build", help="build all blocks and assemble the explorer locally")
    full.add_argument("--out", type=Path, default=ROOT / "build/site")
    full.add_argument("--revision", default="local")
    full.add_argument("--decoder-archive", type=Path)
    args = p.parse_args()
    with closing(sqlite3.connect(args.db.resolve().as_uri() + "?mode=ro", uri=True)) as db:
        if args.cmd == "plan":
            print(json.dumps({"include": job_plan(db)}, separators=(",", ":")))
        elif args.cmd == "shard":
            shard(args, db)
        elif args.cmd == "finish":
            finish(args, db)
        else:
            args.out.parent.mkdir(parents=True, exist_ok=True)
            with tempfile.TemporaryDirectory(dir=args.out.parent) as tmp:
                args.shards = Path(tmp)
                for job in job_plan(db):
                    shard(argparse.Namespace(**job, exefs=args.exefs, out=args.shards), db)
                finish(args, db)


if __name__ == "__main__":
    main()
