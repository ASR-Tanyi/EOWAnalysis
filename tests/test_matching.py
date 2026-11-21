from contextlib import closing
import importlib.util
from pathlib import Path
import sqlite3
import struct
import subprocess
import sys
import tempfile
import unittest
import lz4.block

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
from images import ROOT
from indexer import select_function
from match import CALL26, JUMP26, Reloc, compile_object, measure, object_function, place_branches, target_lookup


class MatchTests(unittest.TestCase):
    def test_signed_forward_and_backward_branches_with_addends(self):
        raw = struct.pack("<2I", 0x94000000, 0x14000000)
        relocs = [Reloc(0, CALL26, "CALL26", "next", True, 4), Reloc(4, JUMP26, "JUMP26", "prev", True, -4)]
        result, records = place_branches(raw, relocs, 0x1000, lambda name, _: {"next": 0x1004, "prev": 0x1000}[name])
        self.assertEqual(struct.unpack("<2I", result), (0x94000002, 0x17fffffe))
        self.assertEqual([r["status"] for r in records], ["applied", "applied"])

    def test_pending_fixup_prevents_false_exact(self):
        raw = struct.pack("<I", 0x94000000)
        ref = Reloc(0, CALL26, "CALL26", "unknown", True, 0)
        for dest in (None, 0x1002, 0x1000 + (1 << 27)):
            with self.subTest(dest=dest):
                placed, records = place_branches(raw, [ref], 0x1000, lambda *_: dest)
                result = measure(raw, raw, placed, records)
                self.assertEqual(result["placed_different_bytes"], 0)
                self.assertEqual(result["pending_relocations"], 1)
                self.assertFalse(result["exact"])
        wrong_opcode = struct.pack("<I", 0xd65f03c0)
        placed, records = place_branches(wrong_opcode, [ref], 0x1000, lambda *_: 0x1008)
        self.assertEqual(placed, wrong_opcode)
        self.assertEqual(records[0]["status"], "pending")

    def test_unmatched_tail_counts_in_both_directions(self):
        small = bytes.fromhex("c0035fd6")
        large = small + bytes(4)
        for original, candidate in [(small, large), (large, small)]:
            result = measure(original, candidate, candidate, [])
            self.assertEqual((result["placed_different_bytes"], result["first_different_byte"]), (4, 4))
            self.assertEqual(result["equal_words_at_same_offset"], 1)
            self.assertFalse(result["exact"])

    @unittest.skipUnless(importlib.util.find_spec("ziglang"), "requires ziglang")
    def test_empty_compiler_section_and_unsized_symbol(self):
        with tempfile.TemporaryDirectory() as temp:
            src, obj = (Path(temp) / name for name in ("empty.s", "empty.o"))
            src.write_text('.section .text.empty,"ax"\n.globl empty\n.type empty,%function\nempty:\n.size empty,.-empty\n'
                           '.section .text.unknown,"ax"\n.globl unknown\n.type unknown,%function\nunknown:\nret\n')
            subprocess.run([sys.executable, "-m", "ziglang", "cc", "-target", "aarch64-linux-musl",
                            "-c", str(src), "-o", str(obj)], check=True)
            raw, relocs = object_function(obj, "empty")
            self.assertEqual((raw, relocs), (b"", []))
            result = measure(bytes.fromhex("c0035fd6"), raw, raw, relocs)
            self.assertEqual((result["compiled_bytes"], result["placed_different_bytes"], result["first_different_byte"]),
                             (0, 4, 0))
            self.assertFalse(result["exact"])
            with self.assertRaisesRegex(ValueError, "Invalid AArch64 function extent"):
                object_function(obj, "unknown")

    @unittest.skipUnless(importlib.util.find_spec("ziglang") and (ROOT / "build/index.sqlite").is_file(),
                         "requires ziglang and the ExeFS index")
    def test_six_game_functions_match_compiled_c(self):
        fixtures = [("setters.c", "O2", [0xbde10, 0xbde3c, 0xbde5c, 0xbde7c, 0xbde9c]),
                    ("tree.c", "Os", [0x2362258])]
        # Read the original text independently of the comparator's NSO loader.
        nso = (ROOT / "ExeFS/main").read_bytes()
        self.assertEqual(nso[0x40:0x54].hex(), "9f221e1afa65ba5443e955158ab97da871e5e41f")
        offset, text_rva, size = struct.unpack_from("<III", nso, 0x10)
        if struct.unpack_from("<I", nso, 0x0c)[0] & 1:
            packed_size = struct.unpack_from("<I", nso, 0x60)[0]
            text = lz4.block.decompress(nso[offset:offset + packed_size], uncompressed_size=size)
        else:
            text = nso[offset:offset + size]
        uri = (ROOT / "build/index.sqlite").as_uri() + "?mode=ro"
        with closing(sqlite3.connect(uri, uri=True)) as db, tempfile.TemporaryDirectory() as temp:
            for source, opt, rvas in fixtures:
                obj = Path(temp) / (source + ".o")
                compile_object([sys.executable, "-m", "ziglang", "cc"], "cortex_a57", opt, ROOT / "matching" / source, obj)
                for rva in rvas:
                    with self.subTest(source=source, rva=hex(rva)):
                        module, fn = select_function(db, f"main:{rva:#x}")
                        offset = rva - text_rva
                        original = text[offset:offset + fn.end - fn.start]
                        symbol = f"f_{fn.start:x}"
                        raw, relocations = object_function(obj, symbol)
                        placed, records = place_branches(raw, relocations, fn.start, target_lookup(db, module, fn.start, symbol))
                        self.assertEqual(placed, original)
                        self.assertTrue(all(r["status"] == "applied" for r in records))
                        if source == "tree.c":
                            self.assertNotEqual(raw, original)
                            self.assertEqual([r["destination"] for r in records],
                                             ["main+0x2362258", "main+0x2362258", "main+0x2833e20"])
                            linked = Path(temp) / "tree.elf"
                            subprocess.run([sys.executable, "-m", "ziglang", "ld.lld", "-m", "aarch64elf",
                                            f"-Ttext={fn.start:#x}", "--defsym=_ZdlPv=0x7002833e20",
                                            "-e", symbol, "-o", str(linked), str(obj)], check=True)
                            self.assertEqual(object_function(linked, symbol, linked_at=fn.start), (original, []))
                            with self.assertRaisesRegex(ValueError, "Linked symbol is at"):
                                object_function(linked, symbol, linked_at=fn.start + 4)
                        else:
                            self.assertEqual(records, [])


if __name__ == "__main__":
    unittest.main()
