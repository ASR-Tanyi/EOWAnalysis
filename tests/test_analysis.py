import csv
import io
from collections import Counter
from pathlib import Path
import sqlite3
import struct
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
from flow import call_edges, local_literals, walk
from images import BASE, Function, relr_slots
from indexer import SCHEMA, reachable_count, write_graph


class Instructions:
    lo = BASE["main"]

    def __init__(self, *words):
        self.words = words
        self.fn = Function(self.lo, self.lo + 4 * len(words), "", "FDE")

    def word(self, pc):
        return self.words[(pc - self.lo) // 4]


class AnalysisTests(unittest.TestCase):
    def test_relr_bitmap_advances_63_slots(self):
        data = bytearray(0x300)
        struct.pack_into("<4Q", data, 0, 0x40, 1 | (1 << 1) | (1 << 3), 3, 0x258)
        self.assertEqual(list(relr_slots(data, 0, 32)), [0x40, 0x48, 0x58, 0x240, 0x258])
        with self.assertRaisesRegex(ValueError, "no base"):
            list(relr_slots(data, 8, 8))

    def test_bl_reaches_an_interior_subroutine_after_a_return(self):
        image = Instructions(0x94000002, 0xd65f03c0, 0xd63f0060, 0xd65f03c0)
        seen, edges, _ = walk(image, image.fn)
        base = image.lo
        self.assertEqual(seen, set(range(base, base + 16, 4)))
        self.assertEqual(list(call_edges(image, image.fn, edges, Counter())), [
            (base, base, "call", base + 8, ""), (base, base + 8, "call-register", None, "x3")])

    def test_literal_pool_is_separate_from_skipped_padding(self):
        image = Instructions(0x18000060, 0x14000003, 0xd503201f, 0x33e425af, 0xd65f03c0)
        seen, _, _ = walk(image, image.fn)
        base = image.lo
        self.assertEqual(seen, {base, base + 4, base + 16})
        self.assertEqual(local_literals(image, image.fn, seen), {base + 12: base})

    def test_call_graph_preserves_sites_and_does_not_follow_extent_fallthrough(self):
        db = sqlite3.connect(":memory:")
        self.addCleanup(db.close)
        db.executescript(SCHEMA)
        root, stub = BASE["main"], BASE["sdk"]
        other, leaf = root + 0x100, stub + 0x100
        db.executemany("INSERT INTO functions VALUES(?,?,?,?,?)", [
            (root, root + 16, "main", "nnMain", "FDE+symbol"), (other, other + 16, "main", "", "FDE"),
            (stub, stub + 16, "sdk", "plt:f", "PLT"), (leaf, leaf + 16, "sdk", "f", "FDE+symbol")])
        db.executemany("INSERT INTO edges VALUES(?,?,?,?,?)", [
            (root, root, "call", stub, ""), (root, root + 4, "call-register", None, "x8"),
            (root, root + 12, "fallthrough", other, ""), (stub, stub + 12, "plt", leaf, "f"),
            (leaf, leaf, "call", root, ""), (other, other, "jump", leaf, "")])
        self.assertEqual(reachable_count(db, root), 3)
        out = io.StringIO()
        write_graph(db, root, None, out)
        rows = list(csv.DictReader(io.StringIO(out.getvalue()), delimiter="\t"))
        self.assertEqual([r["kind"] for r in rows], ["call", "call-register", "fallthrough", "plt", "call"])
        self.assertEqual((rows[1]["target"], rows[1]["detail"]), ("", "x8"))
        self.assertEqual((rows[3]["caller_depth"], rows[3]["target_name"]), ("1", "f"))


if __name__ == "__main__":
    unittest.main()
