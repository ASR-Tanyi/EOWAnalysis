#!/usr/bin/env python3
"""Compile C for AArch64 and compare one bounded function with the uploaded NSO."""

import argparse
from contextlib import closing, contextmanager
from dataclasses import dataclass
import difflib
from functools import cache
import hashlib
from importlib import metadata
import json
import os
from pathlib import Path
import re
import shutil
import sqlite3
import struct
import subprocess
import sys
import tempfile

import capstone
from elftools.common.exceptions import ELFError
from elftools.elf.descriptions import describe_reloc_type
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

from eow import Exporter, verified_image
from images import ROOT
from indexer import address_name, select_function

TARGET = "aarch64-linux-musl"
FLAGS = ["-fno-omit-frame-pointer", "-momit-leaf-frame-pointer", "-fno-stack-protector",
         "-fno-strict-aliasing", "-ffunction-sections", "-mno-outline", "-Wno-deprecated-declarations", "-g0"]
JUMP26, CALL26 = 282, 283
WORD = struct.Struct("<I")


@dataclass(frozen=True)
class Reloc:
    offset: int
    kind: int
    name: str
    symbol: str
    undefined: bool
    addend: int | None


@contextmanager
def object_functions(path, linked_at=None):
    """Read any number of bounded symbols while parsing the ELF section index once."""
    expected_type = "ET_REL" if linked_at is None else "ET_EXEC"
    expected = f"Expected a 64-bit little-endian AArch64 {expected_type} ELF"
    with path.open("rb") as stream:
        if stream.read(4) != b"\x7fELF":
            raise ValueError(expected)
        stream.seek(0)
        elf = ELFFile(stream)
        if (elf.elfclass, elf.little_endian, elf["e_machine"], elf["e_type"]) != (64, True, "EM_AARCH64", expected_type):
            raise ValueError(expected)
        symbols = elf.get_section_by_name(".symtab")
        symbol_index = elf.get_section_index(".symtab")
        relocations = {}
        for section in elf.iter_sections():
            if isinstance(section, RelocationSection):
                relocations.setdefault(section["sh_info"], []).append(section)

        def read(name):
            matches = symbols.get_symbol_by_name(name) if symbols is not None else []
            matches = [s for s in matches or [] if s["st_info"]["type"] == "STT_FUNC" and isinstance(s["st_shndx"], int)]
            if len(matches) != 1:
                raise ValueError(f"Expected one defined function named {name!r}, found {len(matches)}. Check --symbol")
            sym = matches[0]
            section = elf.get_section(sym["st_shndx"])
            start, size = sym["st_value"], sym["st_size"]
            if linked_at is not None:
                if any(seg["p_type"] in ("PT_DYNAMIC", "PT_INTERP") for seg in elf.iter_segments()):
                    raise ValueError("--linked requires a statically linked executable")
                if start != linked_at:
                    raise ValueError(f"Linked symbol is at {start:#x}, expected {linked_at:#x}")
                start -= section["sh_addr"]
            if (not section["sh_flags"] & 4 or section["sh_type"] != "SHT_PROGBITS" or not size or start < 0 or
                    start % 4 or size % 4 or start + size > section.data_size):
                raise ValueError(f"Invalid AArch64 function extent for {name!r}")
            body = section.data()[start:start + size]
            if linked_at is not None:
                return body, []
            relocs = []
            for rs in relocations.get(sym["st_shndx"], ()):
                table = symbols if rs["sh_link"] == symbol_index else elf.get_section(rs["sh_link"])
                for r in rs.iter_relocations():
                    offset, kind = r["r_offset"] - start, r["r_info_type"]
                    width = 8 if kind in (257, 260) else 2 if kind in (259, 262) else 4
                    if kind == 0 or offset + width <= 0 or offset >= size:
                        continue
                    target = table.get_symbol(r["r_info_sym"])
                    label = target.name
                    if not label and target["st_info"]["type"] == "STT_SECTION":
                        label = elf.get_section(target["st_shndx"]).name
                    kind_name = describe_reloc_type(kind, elf)
                    if kind_name == "<unknown>":
                        kind_name = {299: "R_AARCH64_LDST128_ABS_LO12_NC"}.get(kind, f"R_AARCH64_{kind}")
                    relocs.append(Reloc(offset, kind, kind_name, label, target["st_shndx"] == "SHN_UNDEF",
                                        r["r_addend"] if rs.is_RELA() else None))
            return body, relocs

        yield read


def object_function(path, name, linked_at=None):
    with object_functions(path, linked_at) as read:
        return read(name)


def target_lookup(db, module, entry, entry_name):
    @cache
    def resolve(name, undefined):
        if name == entry_name and not undefined:
            return entry
        encoded = re.fullmatch(r"f_([0-9a-fA-F]{1,16})", name)
        if encoded:
            addr = int(encoded[1], 16)
            if addr < 1 << 63 and db.execute("SELECT 1 FROM functions WHERE addr=?", (addr,)).fetchone():
                return addr
        if undefined and name:
            rows = db.execute("SELECT addr FROM functions WHERE module=? AND name=? AND evidence='PLT'",
                              (module, "plt:" + name)).fetchall()
            if len(rows) == 1:
                return rows[0][0]
        return None
    return resolve


def place_branches(raw, relocs, entry, resolve):
    """Place known PC-relative branches using only object fixups and indexed targets."""
    data = bytearray(raw)
    records = []
    for r in relocs:
        record = dict(offset=r.offset, type=r.name, symbol=r.symbol, addend=r.addend, status="pending")
        records.append(record)
        if r.kind not in (CALL26, JUMP26) or r.addend is None:
            record["reason"] = "requires linker layout or another relocation type"
            continue
        target = resolve(r.symbol, r.undefined)
        if target is None:
            record["reason"] = "destination has no verified guest address"
            continue
        delta = target + r.addend - (entry + r.offset)
        opcode = 0x94000000 if r.kind == CALL26 else 0x14000000
        if r.offset < 0 or r.offset + 4 > len(data) or r.offset % 4 or WORD.unpack_from(data, r.offset)[0] >> 26 != opcode >> 26:
            record["reason"] = "relocation site does not contain the expected branch"
        elif delta % 4 or not -(1 << 27) <= delta < 1 << 27:
            record["reason"] = "unaligned or out of direct branch range"
        else:
            WORD.pack_into(data, r.offset, opcode | ((delta // 4) & 0x3ffffff))
            record.update(status="applied", destination=address_name(target + r.addend))
    return bytes(data), records


def differing_bytes(a, b):
    return max(len(a), len(b)) - sum(x == y for x, y in zip(a, b))


def measure(original, raw, placed, relocs):
    pending = sum(r["status"] == "pending" for r in relocs)
    diff = differing_bytes(original, placed)
    first = next((i for i, (a, b) in enumerate(zip(original, placed)) if a != b), None)
    if first is None and len(original) != len(placed):
        first = min(len(original), len(placed))
    return dict(compiled_bytes=len(placed), raw_different_bytes=differing_bytes(original, raw),
                placed_different_bytes=diff, first_different_byte=first,
                equal_words_at_same_offset=sum(x == y for x, y in zip(WORD.iter_unpack(original), WORD.iter_unpack(placed))),
                applied_relocations=len(relocs) - pending, pending_relocations=pending,
                placed_sha256=hashlib.sha256(placed).hexdigest(), exact=(diff == 0 and pending == 0))


def write_disassembly(folder, original, placed, relocs, entry):
    md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
    notes = {}
    for r in relocs:
        notes.setdefault(r["offset"], []).append(f"{r['status']} {r['type']} {r['symbol']}")

    def listing(data, annotations):
        lines = []
        for off in range(0, len(data), 4):
            word = data[off:off + 4]
            insn = next(md.disasm_lite(word, entry + off), None)
            asm = " ".join(insn[2:]).rstrip() if insn else ".word"
            note = "  // " + ", ".join(annotations[off]) if off in annotations else ""
            lines.append(f"+0x{off:04x}  {WORD.unpack(word)[0]:08x}  {asm}{note}\n")
        return lines

    left, right = listing(original, {}), listing(placed, notes)
    (folder / "original.asm").write_text("".join(left), encoding="utf-8")
    (folder / "rebuilt.asm").write_text("".join(right), encoding="utf-8")
    matcher = difflib.SequenceMatcher(None, list(WORD.iter_unpack(original)), list(WORD.iter_unpack(placed)))
    with (folder / "diff.txt").open("w", encoding="utf-8") as out:
        out.write("--- original\n+++ rebuilt at original address\n")
        for group in matcher.get_grouped_opcodes(2):
            out.write(f"@@ original +0x{group[0][1]*4:x}, rebuilt +0x{group[0][3]*4:x} @@\n")
            for tag, a, b, c, d in group:
                if tag == "equal":
                    out.writelines(" " + line for line in left[a:b])
                else:
                    out.writelines("-" + line for line in left[a:b])
                    out.writelines("+" + line for line in right[c:d])
        if original == placed:
            out.write("Identical instruction bytes.\n")
        out.write(f"Pending relocations: {sum(r['status'] == 'pending' for r in relocs)}\n")


def compile_object(cc, cpu, opt, source, obj, *, extra_flags=(), **run_options):
    # The pinned Zig driver maps O1/O3 to O2 and Oz to Os. Forward the exact
    # requested level to Clang cc1 as well so the sweep runs distinct profiles.
    subprocess.run([*cc, "-target", TARGET, "-mcpu=" + cpu, "-" + opt, "-Xclang", "-" + opt, *FLAGS,
                    *extra_flags, "-I", str(ROOT / "vendor/eowrecomp/runtime"), "-c", str(source), "-o", str(obj)],
                   check=True, **run_options)


def compare(args, db, folder, image, fn):
    start = fn.start - image.base
    original = bytes(image.nso.image[start:fn.end - image.base])
    name = args.symbol or f"f_{fn.start:x}"
    resolve = target_lookup(db, image.name, fn.start, name)
    report = dict(function=address_name(fn.start), build_id=image.build_id, symbol=name,
                  original_bytes=len(original), original_sha256=hashlib.sha256(original).hexdigest())
    supplied = args.linked or args.object
    if supplied:
        opts = ["linked" if args.linked else "object"]
        report["input_sha256"] = hashlib.sha256(supplied.read_bytes()).hexdigest()
    else:
        source = args.source
        if source is None:
            source = folder / "lifted.c"
            source.write_text(Exporter(db, image).render(fn, "c"), encoding="utf-8")
        try:
            zig_version = metadata.version("ziglang")
        except metadata.PackageNotFoundError:
            raise ValueError("Install ziglang==0.17.0.post0 or pass an existing AArch64 ELF with --object") from None
        cc = [sys.executable, "-m", "ziglang", "cc"]
        version = subprocess.check_output([*cc, "--version"], text=True).splitlines()[0]
        report.update(source=source.name, source_sha256=hashlib.sha256(source.read_bytes()).hexdigest(),
                      compiler=dict(ziglang=zig_version, clang=version, target=TARGET, cpu=args.cpu,
                                    flags=["-{profile}", "-Xclang", "-{profile}", *FLAGS]))
        opts = list(dict.fromkeys(args.opts or ["O2"]))

    candidates = []
    best_rank = None
    for opt in opts:
        obj = supplied or folder / f"{opt}.o"
        if not supplied:
            compile_object(cc, args.cpu, opt, source, obj)
        raw, relocs = object_function(obj, name, linked_at=fn.start if args.linked else None)
        placed, records = place_branches(raw, relocs, fn.start, resolve)
        metric = measure(original, raw, placed, records)
        candidates.append(dict(profile=opt, **metric))
        rank = (not metric["exact"], metric["placed_different_bytes"], metric["pending_relocations"])
        print(f"{opt}: {len(original)} original, {len(placed)} compiled, {metric['placed_different_bytes']} differing bytes, "
              f"{metric['pending_relocations']} pending relocations", flush=True)
        if best_rank is None or rank < best_rank:
            best_rank = rank
            best_opt, best_obj, best_raw, best_placed, best_records = opt, obj, raw, placed, records

    report.update(selected=best_opt, candidates=candidates)
    (folder / "original.bin").write_bytes(original)
    (folder / "input.bin").write_bytes(best_raw)
    (folder / "rebuilt.bin").write_bytes(best_placed)
    shutil.copyfile(best_obj, folder / ("rebuilt.elf" if args.linked else "rebuilt.o"))
    write_disassembly(folder, original, best_placed, best_records, fn.start)
    for filename, value in (("relocations.json", best_records), ("report.json", report)):
        (folder / filename).write_text(json.dumps(value, indent=2) + "\n", encoding="utf-8")
    return report


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("selector", help="module:symbol or module:0xRVA")
    inputs = p.add_mutually_exclusive_group()
    inputs.add_argument("--source", type=Path, help="C source (default: generate the existing Cpu-state lift)")
    inputs.add_argument("--object", type=Path, help="compare an existing AArch64 relocatable ELF")
    inputs.add_argument("--linked", type=Path, help="compare a statically linked AArch64 ELF at the original guest address")
    p.add_argument("--symbol", help="rebuilt ELF symbol (default: f_<guest address>)")
    p.add_argument("--opts", nargs="+", choices=("O0", "O1", "O2", "O3", "Os", "Oz"), help="compile and rank profiles (default: O2)")
    p.add_argument("--cpu", help="Zig AArch64 CPU (default: cortex_a57)")
    p.add_argument("--require-exact", action="store_true", help="exit 1 unless all bytes and all fixups match")
    p.add_argument("--out", type=Path, help="directory for this comparison")
    p.add_argument("--exefs", type=Path, default=ROOT / "ExeFS")
    p.add_argument("--db", type=Path, default=ROOT / "build/index.sqlite")
    args = p.parse_args()
    if (args.object or args.linked) and (args.opts or args.cpu):
        p.error("--opts and --cpu apply when compiling C")
    if not args.db.is_file():
        p.error("run python tools/eow.py index first")
    args.cpu = args.cpu or "cortex_a57"
    try:
        with closing(sqlite3.connect(args.db.resolve().as_uri() + "?mode=ro", uri=True)) as db:
            module, fn = select_function(db, args.selector)
            image = verified_image(db, args.exefs, module)
            supplied = args.source or args.object or args.linked
            label = supplied.stem if supplied else "lifted"
            out = args.out or ROOT / "build/matching" / module / image.build_id / f"{fn.start - image.base:08x}" / label
            out.mkdir(parents=True, exist_ok=True)
            with tempfile.TemporaryDirectory(dir=out) as temp:
                folder = Path(temp)
                report = compare(args, db, folder, image, fn)
                artifact = "rebuilt.elf" if args.linked else "rebuilt.o"
                artifacts = ["original.bin", "input.bin", "rebuilt.bin", artifact, "original.asm", "rebuilt.asm",
                             "diff.txt", "relocations.json"]
                if (folder / "lifted.c").is_file():
                    artifacts.append("lifted.c")
                for filename in [*artifacts, "report.json"]:
                    os.replace(folder / filename, out / filename)
    except (ValueError, OSError, ELFError, subprocess.CalledProcessError) as error:
        p.exit(2, f"match: {error}\n")
    selected = next(c for c in report["candidates"] if c["profile"] == report["selected"])
    print(f"Selected {report['selected']}. Exact: {selected['exact']}. Report: {out / 'report.json'}")
    return int(args.require_exact and not selected["exact"])


if __name__ == "__main__":
    raise SystemExit(main())
