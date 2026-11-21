"""Publish compact Pages data and comparison logs from an assembled local explorer."""
import argparse
import base64
import csv
import gzip
from itertools import zip_longest
import json
from pathlib import Path
import re
import shutil
import struct

from eow import output_handle
from pages import PUBLIC_LIMIT, json_file

ASM_WORD = re.compile(r"^\s*[0-9a-f]+\s+([0-9a-f]{8})\s+\S", re.M)


def unpack(path):
    with gzip.open(path, "rt", encoding="utf-8") as stream:
        return json.load(stream)


def disk_size(folder):
    return sum(p.stat().st_size for p in folder.rglob("*") if p.is_file())


def log_function(out, name, rec, original_size):
    m = rec["rebuild"]
    if "error" in m:
        out.write(f"\n{name}  COMPILER ERROR\n{m['error']}\n")
        return
    out.write(f"\n{name}  original={original_size}  rebuilt={m['size']}  differing_bytes={m['different']}  "
              f"applied={m['applied']}  pending={m['pending']}  exact={m['exact']}\n")
    if m["different"]:
        rebuilt = base64.b64decode(m["bytes"], validate=True)
        original = ASM_WORD.findall(rec["asm"])
        if len(rebuilt) != m["size"] or len(original) * 4 != original_size:
            raise ValueError(f"Invalid instruction data for {name}")
        out.write("offset\toriginal_word\trebuilt_word\n")
        for i, (old, new) in enumerate(zip_longest(original, (f"{w:08x}" for w, in struct.iter_unpack("<I", rebuilt)))):
            if old != new:
                out.write(f"+0x{i*4:x}\t{old or '-'}\t{new or '-'}\n")
    for offset, kind, symbol, dest in m["fixups"]:
        out.write(f"fixup\t+0x{offset:x}\t{kind}\t{symbol}\t{dest or 'pending'}\n")


def publish(source, public, logs, run_url="", budget=PUBLIC_LIMIT):
    paths = [p.resolve() for p in (source, public, logs)]
    if any(p == q or p in q.parents for i,p in enumerate(paths) for j,q in enumerate(paths) if i != j):
        raise ValueError("Use separate local HTML, public site and log directories")
    for p in (public, logs):
        if p.exists() and any(p.iterdir()):
            raise ValueError(f"Choose an empty output directory: {p}")
        p.mkdir(parents=True, exist_ok=True)
    manifest = json.loads((source / "manifest.json").read_text())
    if manifest.get("reportMode", "detailed") != "detailed":
        raise ValueError("A detailed local explorer is required to generate comparison logs")
    shutil.copytree(source, public, dirs_exist_ok=True,
                    ignore=lambda parent, names: {"data","comparisons","decoder","manifest.json"} if Path(parent) == source else set())
    manifest.update(reportMode="summary", runUrl=run_url)
    for fixture in manifest["comparisons"]:
        key = f"{fixture['rva']:x}"
        report = unpack(source / "comparisons" / f"{key}.json.gz")
        public_report = {k:report[k] for k in ("source", "report", "linked") if k in report}
        json_file(public / "comparisons" / f"{key}.json.gz", public_report)
        directory = logs / "individual" / f"{fixture['module']}-{key}"
        directory.mkdir(parents=True)
        (directory / "diff.txt").write_text(report["diff"], encoding="utf-8")
        (directory / "rebuilt.asm").write_text(report["assembly"], encoding="utf-8")
        for k in ("fixups", "report", "linked"):
            if k in report:
                json_file(directory / (k + ".json"), report[k])

    count = 0
    with output_handle(logs / "functions.tsv.gz") as stream:
        tsv = csv.writer(stream, delimiter="\t", lineterminator="\n")
        tsv.writerow(("function","original_bytes","rebuilt_bytes","differing_bytes","pending_fixups","result","detail_log"))
        for module in manifest["modules"]:
            name = module["name"]
            sizes = {r[0]:r[1] for r in unpack(source / "catalog" / (name+".json.gz"))}
            for src in sorted((source / "data" / name).glob("*.json.gz")):
                rows = unpack(src)
                rel = Path("corpus") / name / src.name.replace(".json.gz", ".log.gz")
                with output_handle(logs / rel) as log:
                    for key, rec in rows.items():
                        identifier = f"{name}+0x{key}"
                        size = sizes.pop(int(key,16))
                        m = rec["rebuild"]
                        log_function(log, identifier, rec, size)
                        status = "compiler-error" if "error" in m else "exact" if m["exact"] else "different"
                        tsv.writerow([identifier,size,m.get("size"),m.get("different"),m.get("pending"),status,rel.as_posix()])
                        rec["rebuild"] = {k:v for k,v in m.items() if k not in ("bytes","fixups")}
                        count += 1
                json_file(public / "data" / name / src.name, rows)
            if sizes:
                raise ValueError(f"Missing comparison records for {len(sizes)} functions in {name}")
    if count != manifest["functions"]:
        raise ValueError(f"Expected {manifest['functions']} log entries, found {count}")
    json_file(public / "manifest.json", manifest)
    if disk_size(public) > budget:
        # Retain source for the documented entry points and the comparison fixtures.
        keep = {v["address"] for v in manifest["baseline"]["entry_points"].values()}
        keep.update(f"{r['module']}+0x{r['rva']:x}" for r in manifest["comparisons"])
        for payload in (public / "data").glob("*/*.json.gz"):
            rows = unpack(payload)
            for key, rec in rows.items():
                if f"{payload.parent.name}+0x{key}" not in keep:
                    rec.pop("asm", None)
                    rec.pop("c", None)
            json_file(payload, rows)
        manifest["reportMode"] = "index"
        json_file(public / "manifest.json", manifest)
    size = disk_size(public)
    if size > budget:
        raise ValueError(f"Public index exceeds the publishing budget: {size:,} bytes")
    for p in public.rglob("*"):
        if p.is_file():
            p.chmod(0o644)
    summary = [f"## ExeFS comparison report", "", f"Public site: {size:,} bytes · {count:,} functions and stubs.", "",
               "| Module | Entries | Exact grouped rebuilds | Compiler errors |", "| --- | ---: | ---: | ---: |"]
    summary += [f"| {m['name']} | {m['functions']:,} | {m['exact']:,} | {m['errors']:,} |" for m in manifest["modules"]]
    summary += ["", "The comparison-logs artifact contains functions.tsv.gz and a per-block log of changed instruction words and fixups.",
                "Individual builds include the disassembly diff, relocation details and every tested profile.",
                "Extract local-html and run python -m http.server in the extracted folder to open the detailed explorer."]
    (logs / "README.md").write_text("\n".join(summary)+"\n", encoding="utf-8")
    print("\n".join(summary))
    return manifest


if __name__ == "__main__":
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("local_html", type=Path)
    p.add_argument("--out", type=Path, required=True)
    p.add_argument("--logs", type=Path, required=True)
    p.add_argument("--run-url", default="")
    a = p.parse_args()
    publish(a.local_html, a.out, a.logs, a.run_url)
