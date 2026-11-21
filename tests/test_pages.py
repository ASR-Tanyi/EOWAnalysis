import argparse
import base64
import gzip
import json
from pathlib import Path
import sqlite3
import sys
import tempfile
import unittest
import random

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
from images import BASE
from indexer import SCHEMA
from pages import BLOCKS_PER_JOB, SHIFT, block_counts, finish, job_plan, json_file
from pages_report import disk_size, publish, unpack


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

    def test_public_metrics_and_private_details_come_from_same_bytes(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            local, public, logs = (root / name for name in ("local", "public", "logs"))
            manifest = dict(reportMode="detailed", functions=1, comparisons=[], baseline={"entry_points":{}},
                            modules=[dict(name="main", functions=1, exact=0, errors=0)])
            json_file(local / "manifest.json", manifest)
            json_file(local / "catalog/main.json.gz", [[4,4,"test","FDE",0]])
            record = dict(asm="  7000000004  d65f03c0  ret\n",
                          c="/*" + random.Random(7).randbytes(12000).hex() + "*/",
                          outgoing=[], incoming=[], rebuild=dict(size=4, different=4, rawDifferent=4, first=0,
                          applied=0, pending=0, exact=False, bytes=base64.b64encode(bytes.fromhex("1f2003d5")).decode(), fixups=[]))
            json_file(local / "data/main/0.json.gz", {"4":record})
            publish(local, public, logs, "https://github.com/example/repo/actions/runs/1")
            compact = unpack(public / "data/main/0.json.gz")["4"]
            self.assertEqual(compact["asm"], record["asm"])
            self.assertEqual(compact["rebuild"]["different"], 4)
            self.assertNotIn("bytes", compact["rebuild"])
            self.assertNotIn("fixups", compact["rebuild"])
            with gzip.open(logs / "corpus/main/0.log.gz", "rt") as f:
                self.assertIn("+0x0\td65f03c0\td503201f", f.read())
            self.assertEqual(unpack(local / "data/main/0.json.gz")["4"], record)
            small = root / "smaller"
            result = publish(local, small, root / "logs2", budget=disk_size(public) - 500)
            self.assertEqual(result["reportMode"], "index")
            self.assertNotIn("asm", unpack(small / "data/main/0.json.gz")["4"])
            self.assertIn("rebuild", unpack(small / "data/main/0.json.gz")["4"])


if __name__ == "__main__":
    unittest.main()
