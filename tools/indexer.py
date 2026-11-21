"""Build and query a revision-specific SQLite index of the supplied ExeFS."""

from collections import Counter, defaultdict
import json
import os
import sqlite3
import tempfile

from flow import call_edges, walk
from images import BASE, Function, Image, program_id


SCHEMA = """
CREATE TABLE modules(name TEXT PRIMARY KEY, base INTEGER, build_id TEXT, sha256 TEXT,
    layout TEXT, stats TEXT);
CREATE TABLE functions(addr INTEGER PRIMARY KEY, end INTEGER, module TEXT, name TEXT, evidence TEXT);
CREATE TABLE symbols(module TEXT, idx INTEGER, name TEXT, info INTEGER, visibility INTEGER,
    addr INTEGER, size INTEGER, PRIMARY KEY(module,idx)) WITHOUT ROWID;
CREATE TABLE pointers(slot INTEGER, target INTEGER, encoding TEXT);
CREATE TABLE stubs(addr INTEGER PRIMARY KEY, slot INTEGER, module TEXT, symbol_idx INTEGER);
CREATE TABLE edges(src INTEGER, site INTEGER, kind TEXT, target INTEGER, detail TEXT);
CREATE TABLE meta(key TEXT PRIMARY KEY, value TEXT);
"""


def add_module(db, exefs, name):
    image = Image(exefs, name)
    functions = image.functions()
    db.executemany("INSERT INTO functions VALUES(?,?,?,?,?)",
                   ((f.start, f.end, name, f.name, f.evidence) for f in functions))
    db.executemany("INSERT INTO symbols VALUES(?,?,?,?,?,?,?)",
                   ((name, i, sym, info, other & 3, image.base + val if sec else None, size)
                    for i, (sym, info, other, sec, val, size) in enumerate(image.symbols)))
    db.executemany("INSERT INTO pointers VALUES(?,?,?)", image.code_pointers())
    db.executemany("INSERT INTO stubs VALUES(?,?,?,?)",
                   ((a, slot, name, i) for a, (i, slot) in image.stubs.items()))
    counts = Counter()
    rows = []
    for f in functions:
        if f.start in image.stubs:
            counts["visited_words"] += 4
            continue
        seen, branches, switches = walk(image, f)
        counts["visited_words"] += len(seen)
        counts["switch_sites"] += len(switches)
        rows.extend(call_edges(image, f, branches, counts))
        image.cache.clear()
        if len(rows) >= 8192:
            db.executemany("INSERT INTO edges VALUES(?,?,?,?,?)", rows)
            rows.clear()
    db.executemany("INSERT INTO edges VALUES(?,?,?,?,?)", rows)
    counts.update({
        "functions": len(functions), "bounded_bytes": sum(f.end - f.start for f in functions),
        "text_bytes": image.nso.text[1], "plt_stubs": len(image.stubs),
        "jump_slots": sum(kind == 1026 for _, kind, _, _ in image.nso.relocs),
    })
    db.execute("INSERT INTO modules VALUES(?,?,?,?,?,?)",
               (name, image.base, image.build_id, image.sha256, json.dumps(image.segments), json.dumps(counts)))
    print(f"{name}: {len(functions):,} bounded entries, {counts['switch_sites']:,} recognized switches",
          flush=True)


def link_stubs(db):
    exports = defaultdict(set)
    for name, addr in db.execute("""SELECT name,addr FROM symbols
            WHERE addr IS NOT NULL AND (info & 15)=2 AND (info >> 4) IN (1,2) AND visibility IN (0,3)"""):
        exports[name].add(addr)
    rows = []
    for addr, name, local in db.execute("""SELECT stubs.addr,s.name,s.addr
            FROM stubs JOIN symbols s ON s.module=stubs.module AND s.idx=stubs.symbol_idx"""):
        matches = exports[name]
        target = local
        if target is None and len(matches) == 1:
            target = next(iter(matches))
        rows.append((addr, addr + 12, "plt", target, name))
    db.executemany("INSERT INTO edges VALUES(?,?,?,?,?)", rows)


def build(exefs, path):
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, tmp = tempfile.mkstemp(dir=path.parent, suffix=".sqlite")
    os.close(fd)
    try:
        db = sqlite3.connect(tmp)
        try:
            db.execute("PRAGMA journal_mode=OFF")
            db.executescript(SCHEMA)
            db.execute("INSERT INTO meta VALUES('program_id',?)", (program_id(exefs),))
            for name in BASE:
                add_module(db, exefs, name)
            link_stubs(db)
            db.executescript("""
                CREATE INDEX by_source ON edges(src);
                CREATE INDEX by_target ON edges(target);
                CREATE INDEX by_module ON functions(module, addr);
                CREATE INDEX by_symbol ON symbols(module,name);
                CREATE INDEX pointer_targets ON pointers(target);
            """)
            db.commit()
        finally:
            db.close()
        os.replace(tmp, path)
    finally:
        if os.path.exists(tmp):
            os.unlink(tmp)


def select_function(db, selector):
    module, sep, value = selector.partition(":")
    if not sep or module not in BASE:
        raise ValueError("Use module:symbol or module:0xRVA")
    if value.startswith("0x"):
        addr = BASE[module] + int(value, 16)
    else:
        found = db.execute("""SELECT addr FROM functions WHERE module=? AND name=?
                              UNION SELECT addr FROM symbols WHERE module=? AND name=? AND addr IS NOT NULL""",
                           (module, value, module, value)).fetchall()
        if len(found) != 1:
            raise ValueError(f"{selector}: expected one definition, found {len(found)}")
        addr = found[0][0]
    row = db.execute("SELECT addr,end,name,evidence FROM functions WHERE addr=? AND module=?",
                     (addr, module)).fetchone()
    if not row:
        raise ValueError(f"{selector}: no bounded function starts here")
    return module, Function(*row)


def reachable_count(db, root):
    return db.execute("""WITH RECURSIVE reach(addr) AS (
      VALUES(?) UNION SELECT e.target FROM reach r JOIN edges e ON e.src=r.addr
      JOIN functions f ON f.addr=e.target WHERE e.kind!='fallthrough')
      SELECT count(*) FROM reach""", (root,)).fetchone()[0]


def address_name(addr):
    for name, base in reversed(sorted(BASE.items(), key=lambda pair: pair[1])):
        if addr >= base:
            return f"{name}+0x{addr-base:x}"
    return hex(addr)


def write_graph(db, root, depth, out):
    """Breadth-first, cycle-safe, one row per call site with its exact target."""
    import csv
    writer = csv.writer(out, delimiter="\t", lineterminator="\n")
    writer.writerow(["caller_depth", "caller", "caller_name", "site", "kind", "target", "target_name", "detail"])
    frontier = [root]
    reached = {root}
    level = 0
    while frontier and (depth is None or level < depth):
        following = set()
        for i in range(0, len(frontier), 500):
            batch = frontier[i:i + 500]
            params = ",".join("?" for _ in batch)
            sql = f"""SELECT e.src,a.name,e.site,e.kind,e.target,b.name,e.detail
                      FROM edges e JOIN functions a ON a.addr=e.src
                      LEFT JOIN functions b ON b.addr=e.target
                      WHERE e.src IN ({params}) ORDER BY e.src,e.site,e.kind,e.target"""
            for src, name, site, kind, target, callee, detail in db.execute(sql, batch):
                writer.writerow([level, address_name(src), name, address_name(site), kind,
                                 address_name(target) if target is not None else "", callee or "", detail])
                if kind != "fallthrough" and callee is not None and target not in reached:
                    following.add(target)
        frontier = sorted(following)
        reached.update(following)
        level += 1
