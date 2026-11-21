import argparse
import gzip
import json
from pathlib import Path
import sqlite3
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
from images import BASE
from indexer import SCHEMA
from pages import BLOCKS_PER_JOB, SHIFT, block_counts, finish, job_plan, json_file


class PagesTests(unittest.TestCase):
    def test_plan_covers_each_populated_block_once(self):
        db = sqlite3.connect(":memory:")
        self.addCleanup(db.close)
        db.executescript(SCHEMA)
        expected = set()
        for module in ("main", "sdk"):
            for block in (0, BLOCKS_PER_JOB - 1, BLOCKS_PER_JOB, BLOCKS_PER_JOB + 3):
                addr = BASE[module] + (block << SHIFT)
                db.execute("INSERT INTO functions VALUES(?,?,?,?,?)", (addr, addr + 4, module, "", "FDE"))
                expected.add((module, block))
        covered = [(j["module"], b) for j in job_plan(db) for b in block_counts(db, j["module"])
                   if j["first"] <= b <= j["last"]]
        self.assertCountEqual(covered, expected)

    def test_missing_block_prevents_publication(self):
        db = sqlite3.connect(":memory:")
        self.addCleanup(db.close)
        db.executescript(SCHEMA)
        db.execute("INSERT INTO functions VALUES(?,?,?,?,?)", (BASE["main"], BASE["main"] + 4, "main", "entry", "FDE"))
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            with self.assertRaisesRegex(ValueError, "Missing 1 required function blocks"):
                finish(argparse.Namespace(out=root / "site", shards=root / "chunks"), db)
            self.assertFalse((root / "site/index.html").exists())

    def test_unicode_symbols_round_trip_through_compressed_json(self):
        with tempfile.TemporaryDirectory() as tmp:
            file = Path(tmp) / "module/0.json.gz"
            value = {"0": {"c": "/* café <&> */\n", "outgoing": [[BASE["rtld"], "call-register", None, "x8"]]}}
            json_file(file, value)
            self.assertEqual(json.loads(gzip.decompress(file.read_bytes())), value)


if __name__ == "__main__":
    unittest.main()
