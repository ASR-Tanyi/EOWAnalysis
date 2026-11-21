#!/usr/bin/env python3
"""Inspect the uploaded ExeFS, using module-relative addresses at the command line."""

import argparse
from collections import defaultdict, deque
from contextlib import closing, contextmanager
import gzip
import io
import json
import os
from pathlib import Path
import sqlite3
import sys
import tempfile

import capstone

from flow import cfg_dot, local_literals, walk
from images import BASE, ROOT, SDK_START, Function, Image
from indexer import address_name, build, reachable_count, select_function, write_graph
from lifter import Insn


def verified_image(db, exefs, module):
    image = Image(exefs, module)
    stored = db.execute("SELECT sha256 FROM modules WHERE name=?", (module,)).fetchone()
    if not stored or image.sha256 != stored[0]:
        raise ValueError(f"{module}: input changed; rebuild the index")
    return image


def dump_data(exefs, out, names):
    for module in names:
        image = Image(exefs, module)
        folder = out / module / image.build_id
        folder.mkdir(parents=True, exist_ok=True)
        sections = {}
        for name, (rva, size) in image.segments.items():
            sections[name] = {"rva": rva, "size": size}
            if name != "bss":
                filename = name + ".bin"
                (folder / filename).write_bytes(memoryview(image.nso.image)[rva:rva + size])
                sections[name]["file"] = filename
            else:
                sections[name]["fill"] = 0
        layout = {"module": module, "build_id": image.build_id, "sha256": image.sha256,
                  "analysis_base": image.base, "mapped_size": image.nso.size, "relocated": False,
                  "sections": sections}
        (folder / "layout.json").write_text(json.dumps(layout, indent=2) + "\n", encoding="utf-8")


class Exporter:
    def __init__(self, db, image):
        self.db, self.image = db, image
        self.md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
        self.md.skipdata = True
        self.names = dict(db.execute("SELECT addr,name FROM functions WHERE module=?", (image.name,)))
        self.unsupported_sites = {}

    def render(self, fn, fmt):
        image = self.image
        image.cache.clear()
        if fmt == "c":
            return self.c_source(fn)
        seen, edges, _ = walk(image, fn)
        if fn.evidence == "PLT":
            site, target = self.db.execute("SELECT site,target FROM edges WHERE src=? AND kind='plt'",
                                           (fn.start,)).fetchone()
            edges = [(site, "plt", target)]
        if fmt == "dot":
            return cfg_dot(image, fn, seen, edges)
        literals = local_literals(image, fn, seen)
        outgoing = defaultdict(list)
        labels = {fn.start}
        for site, kind, target in edges:
            if target is None:
                outgoing[site].append(kind)
            elif fn.start <= target < fn.end:
                labels.add(target)
                outgoing[site].append(f"{kind} L_{target:x}")
            else:
                name = self.names.get(target, "")
                outgoing[site].append(f"{kind} {address_name(target)} {name}".rstrip())
        out = [f"// {address_name(fn.start)} {fn.name} ({fn.evidence}), end {address_name(fn.end)}"]
        code = bytes(image.nso.image[fn.start-image.base:fn.end-image.base])
        decoded = {pc: (mnemonic, args) for pc, _, mnemonic, args in self.md.disasm_lite(code, fn.start)}
        for pc in range(fn.start, fn.end, 4):
            if pc in labels:
                out.append(f"L_{pc:x}:")
            word = image.word(pc)
            mnemonic, args = decoded.get(pc, (".word", f"0x{word:08x}"))
            notes = ", ".join(outgoing[pc])
            if pc not in seen:
                mnemonic, args, notes = ".word", f"0x{word:08x}", "outside recovered control flow"
                if pc in literals:
                    notes = f"literal read at {address_name(literals[pc])}"
            line = f"  {pc:010x}  {word:08x}  {mnemonic:9s} {args}".rstrip()
            out.append(line + ("  // " + notes if notes else ""))
        return "\n".join(out) + "\n"

    def c_source(self, fn):
        image = self.image
        before = image.stats["unsupported"]
        literals = local_literals(image, fn)
        for address, reader in literals.items():
            # The value stays in the guest image. A transfer to its bytes must trap.
            image.cache[address] = Insn("trap", f"rt_udf(c, 0x{address:x}ull); /* literal read at {address_name(reader)} */")
        labels, _, tables = image.scan(fn.start, fn.end)
        body = image.emit_function(fn.start, fn.end, labels, tables, {})
        if image.stats["unsupported"] > before:
            for pc, ins in image.cache.items():
                if ins.kind == "trap" and "/*" in ins.code and pc not in literals:
                    word = image.word(pc)
                    decoded = next(self.md.disasm_lite(word.to_bytes(4, "little"), pc), None)
                    self.unsupported_sites[pc] = dict(site=address_name(pc), function=address_name(fn.start),
                                                      word=f"{word:08x}", asm=" ".join(decoded[2:]) if decoded else "")
        out = [f"// Lifted AArch64: {address_name(fn.start)} {fn.name} ({fn.evidence}).",
               '#include "cpu.h"', '#include "simd.h"', ""]
        for target in sorted(image._refs):
            if target in self.names:
                name = self.names[target]
                comment = f"  // {name}" if name else ""
                out.append(f"void f_{target:x}(Cpu *c);{comment}")
            else:
                # Another entry into a function, or a block with no recovered extent.
                # Keep its actual guest address even if it has no standalone C symbol.
                out.extend([f"static void f_{target:x}(Cpu *c) {{",
                            f"    c->pc = 0x{target:x}ull;", "    rt_dispatch(c);", "}"])
        return "\n".join([*out, "", *body, ""])


def startup_path(db, start, goal):
    queue = deque([start])
    parents = {start: None}
    while queue:
        addr = queue.popleft()
        if addr == goal:
            path = []
            while parents[addr] is not None:
                parent, site, kind, detail = parents[addr]
                path.append(dict(source=address_name(parent), site=address_name(site), kind=kind,
                                 target=address_name(addr), symbol=detail))
                addr = parent
            return list(reversed(path))
        for site, kind, target, detail in db.execute("""SELECT e.site,e.kind,e.target,e.detail
                FROM edges e JOIN functions f ON f.addr=e.target
                WHERE e.src=? AND e.kind!='fallthrough' ORDER BY e.site""", (addr,)):
            if target not in parents:
                parents[target] = (addr, site, kind, detail)
                queue.append(target)
    return None


def summary(db):
    result = {"program_id": db.execute("SELECT value FROM meta WHERE key='program_id'").fetchone()[0],
              "modules": {}}
    for mod, base, bid, digest, stats in db.execute("SELECT name,base,build_id,sha256,stats FROM modules ORDER BY base"):
        values = json.loads(stats)
        values["code_pointers"] = dict(db.execute("""SELECT encoding,count(*) FROM pointers
            WHERE target >= ? AND target < ? GROUP BY encoding""", (base, base + values["text_bytes"])))
        values["unresolved_import_stubs"] = db.execute("""SELECT count(*) FROM edges e JOIN stubs s ON s.addr=e.src
            WHERE s.module=? AND e.kind='plt' AND e.target IS NULL""", (mod,)).fetchone()[0]
        result["modules"][mod] = dict(build_id=bid, file_sha256=digest, **values)
    _, loader = select_function(db, "rtld:0x0")
    _, sdk = select_function(db, "sdk:" + SDK_START)
    _, app = select_function(db, "main:nnMain")
    result["entry_points"] = {k: dict(address=address_name(f.start), size=f.end-f.start, evidence=f.evidence)
                              for k, f in [("loader", loader), ("sdk_start", sdk), ("nnMain", app)]}
    result["loader_to_sdk"] = startup_path(db, loader.start, sdk.start)
    result["sdk_to_nnMain"] = startup_path(db, sdk.start, app.start)
    result["reachable_from_nnMain_including_root_and_stubs"] = reachable_count(db, app.start)
    result["outgoing_sites_in_nnMain"] = dict(db.execute("""SELECT kind,count(*) FROM edges
        WHERE src=? GROUP BY kind""", (app.start,)))
    return result


def export_summary(db, folder):
    result = {"assembly_files": 0, "c_files": 0, "unsupported_lift_events": 0, "modules": {}}
    for module, build_id, count in db.execute("""SELECT m.name,m.build_id,count(*) FROM modules m
            JOIN functions f ON f.module=m.name GROUP BY m.name ORDER BY m.base"""):
        directory = folder / module / build_id
        entry = {"build_id": build_id}
        for fmt in ("asm", "c"):
            path = directory / f"manifest-{fmt}.json"
            if not path.is_file():
                raise ValueError(f"Missing {path}. Run split {module} --format {fmt} first")
            manifest = json.loads(path.read_text(encoding="utf-8"))
            metadata = (manifest["module"], manifest["build_id"], manifest["format"], manifest["files"])
            if metadata != (module, build_id, fmt, count):
                raise ValueError(f"{path} does not match the index")
            entry[fmt] = {k: v for k, v in manifest.items() if k not in ("module", "build_id", "format")}
        result["assembly_files"] += entry["asm"]["files"]
        result["c_files"] += entry["c"]["files"]
        result["unsupported_lift_events"] += entry["c"]["unsupported_lift_events"]
        result["modules"][module] = entry
    return result


@contextmanager
def output_handle(path):
    if path is None:
        yield sys.stdout
        return
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, tmp = tempfile.mkstemp(dir=path.parent)
    try:
        with os.fdopen(fd, "wb") as raw:
            if path.suffix == ".gz":
                with gzip.GzipFile(filename="", fileobj=raw, mode="wb", mtime=0) as packed:
                    with io.TextIOWrapper(packed, encoding="utf-8", newline="") as output:
                        yield output
            else:
                with io.TextIOWrapper(raw, encoding="utf-8", newline="") as output:
                    yield output
        os.replace(tmp, path)
    finally:
        if os.path.exists(tmp):
            os.unlink(tmp)


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--exefs", type=Path, default=ROOT / "ExeFS")
    p.add_argument("--db", type=Path, default=ROOT / "build" / "index.sqlite")
    commands = p.add_subparsers(dest="cmd", required=True)
    commands.add_parser("index", help="rebuild the module, function and call-site database")
    data = commands.add_parser("data", help="write decompressed segments and BSS layout")
    data.add_argument("--module", choices=[*BASE, "all"], default="all")
    data.add_argument("--out", type=Path, default=ROOT / "build" / "segments")
    one = commands.add_parser("function", help="render a function from a symbol or hexadecimal RVA")
    one.add_argument("selector", help="e.g. main:nnMain or main:0x360b70")
    one.add_argument("--out", type=Path)
    many = commands.add_parser("split", help="write one file for each bounded function")
    many.add_argument("module", choices=[*BASE, "all"])
    many.add_argument("--out", type=Path, default=ROOT / "build" / "functions")
    for export in (one, many):
        export.add_argument("--format", choices=("asm", "dot", "c"), default="asm")
    graph = commands.add_parser("graph", help="walk the indexed call graph from one root")
    graph.add_argument("selector", nargs="?", default="main:nnMain")
    graph.add_argument("--depth", type=int, help="number of edges from root; default is unlimited")
    graph.add_argument("--out", type=Path)
    report = commands.add_parser("summary", help="emit a reproducible build-specific JSON report")
    report.add_argument("--out", type=Path)
    exports = commands.add_parser("exports", help="check the bulk assembly/C manifests against the index")
    exports.add_argument("--from-dir", type=Path, default=ROOT / "build" / "functions")
    exports.add_argument("--out", type=Path)
    args = p.parse_args()
    if args.cmd == "index":
        return build(args.exefs, args.db)
    if args.cmd == "data":
        return dump_data(args.exefs, args.out, BASE if args.module == "all" else [args.module])
    if not args.db.is_file():
        p.error("run the index command first")
    with closing(sqlite3.connect(args.db.resolve().as_uri() + "?mode=ro", uri=True)) as db:
        if args.cmd in ("summary", "exports"):
            report = summary(db) if args.cmd == "summary" else export_summary(db, args.from_dir)
            with output_handle(args.out) as out:
                print(json.dumps(report, indent=2), file=out)
        elif args.cmd == "graph":
            if args.depth is not None and args.depth < 0:
                p.error("--depth must be nonnegative")
            _, fn = select_function(db, args.selector)
            with output_handle(args.out) as out:
                write_graph(db, fn.start, args.depth, out)
        elif args.cmd == "function":
            mod, fn = select_function(db, args.selector)
            image = verified_image(db, args.exefs, mod)
            text = Exporter(db, image).render(fn, args.format)
            with output_handle(args.out) as out:
                out.write(text)
        else:
            for mod in BASE if args.module == "all" else [args.module]:
                image = verified_image(db, args.exefs, mod)
                exporter = Exporter(db, image)
                files = 0
                size = 0
                root = args.out / mod / image.build_id
                for row in db.execute("SELECT addr,end,name,evidence FROM functions WHERE module=? ORDER BY addr", (mod,)):
                    fn = Function(*row)
                    rva = fn.start - image.base
                    path = root / f"{rva >> 16:04x}" / f"{rva:08x}.{args.format}"
                    text = exporter.render(fn, args.format)
                    with output_handle(path) as output:
                        output.write(text)
                    size += len(text.encode("utf-8"))
                    files += 1
                totals = dict(module=mod, build_id=image.build_id, format=args.format, files=files, bytes=size)
                if args.format == "c":
                    totals["unsupported_lift_events"] = image.stats["unsupported"]
                    totals["unsupported_sites"] = [exporter.unsupported_sites[a] for a in sorted(exporter.unsupported_sites)]
                with output_handle(root / f"manifest-{args.format}.json") as output:
                    print(json.dumps(totals, indent=2), file=output)
                print(json.dumps(totals), flush=True)


if __name__ == "__main__":
    main()
