"""Intraprocedural A64 traversal. Preserve unknown register targets explicitly."""

def signed(value, bits):
    sign = 1 << (bits - 1)
    return (value ^ sign) - sign


def branch(word, pc):
    if word & 0x7c000000 == 0x14000000:  # B / BL immediate
        return ("call" if word >> 31 else "jump",
                pc + 4 * signed(word & 0x3ffffff, 26))
    if word & 0xff000000 == 0x54000000 or word & 0x7e000000 == 0x34000000:
        return "conditional", pc + 4 * signed(word >> 5 & 0x7ffff, 19)
    if word & 0x7e000000 == 0x36000000:
        return "conditional", pc + 4 * signed(word >> 5 & 0x3fff, 14)
    op = word & 0xfffffc1f
    if op == 0xd61f0000:
        return "jump-register", None
    if op == 0xd63f0000:
        return "call-register", None
    if op == 0xd65f0000:
        return "return", None
    if word >> 16 == 0 or word & 0xffe0001f in (0xd4200000, 0xd4400000):
        return "trap", None
    return None


def walk(image, fn):
    """Explore both conditional paths, assume calls may return, stop at unknown jumps."""
    seen = set()
    edges = []
    tables = {}
    todo = [fn.start]
    words, lo = image.words, image.lo
    while todo:
        pc = todo.pop()
        while fn.start <= pc < fn.end and pc not in seen:
            seen.add(pc)
            word = words[(pc - lo) // 4]
            # All A64 branch/system encodings use op0=101x; UDF is outside that space.
            flow = branch(word, pc) if word & 0x1c000000 == 0x14000000 or word >> 16 == 0 else None
            if flow:
                kind, dest = flow
                if kind == "jump-register" and image.computed_target(pc, fn.start):
                    targets = image.jump_table(pc, fn.start, fn.end)
                    if targets:
                        tables[pc] = targets
                        for t in targets:
                            edges.append((pc, "switch", t))
                            if fn.start <= t < fn.end:
                                todo.append(t)
                        # The upstream C lift also keeps a dynamic fallback for these tables.
                        edges.append((pc, "switch-fallback", None))
                        break
                edges.append((pc, kind, dest))
                if kind in ("jump", "conditional", "call") and fn.start <= dest < fn.end:
                    todo.append(dest)
                if kind in ("jump", "jump-register", "return", "trap"):
                    break
            if pc + 4 == fn.end:
                edges.append((pc, "fallthrough", fn.end))
            pc += 4
    return seen, edges, tables


def call_edges(image, fn, edges, counts):
    """Keep inter-function transfers and register calls. PLT bindings are linked separately."""
    for site, kind, target in edges:
        counts[kind] += 1
        if kind in ("return", "trap"):
            continue
        if kind != "call" and target is not None and fn.start <= target < fn.end:
            continue
        detail = ""
        if target is None:
            detail = f"x{image.word(site) >> 5 & 31}"
        yield fn.start, site, kind, target, detail


def local_literals(image, fn, seen=None):
    """Unreached words read by an instruction-local PC-relative literal load."""
    candidates = []
    for pc in range(fn.start, fn.end, 4):
        word = image.word(pc)
        if word & 0x3b000000 != 0x18000000 or word >> 30 == 3:  # excludes PRFM
            continue
        dest = pc + 4 * signed(word >> 5 & 0x7ffff, 19)
        width = (4, 8, 16 if word & (1 << 26) else 4)[word >> 30]
        if fn.start <= dest and dest + width <= fn.end:
            candidates.append((pc, dest, width))
    if candidates and seen is None:
        seen, _, _ = walk(image, fn)
    return {a: pc for pc, dest, width in candidates if pc in seen
            for a in range(dest, dest + width, 4) if a not in seen}


def cfg_dot(image, fn, seen, edges):
    """Render reachable basic blocks, including fallthrough and unresolved exits."""
    from collections import defaultdict
    ordered = sorted(seen)
    leaders = {fn.start}
    outgoing = defaultdict(list)
    for site, kind, target in edges:
        outgoing[site].append((kind, target))
        if target in seen:
            leaders.add(target)
        if site + 4 in seen:
            leaders.add(site + 4)
    leaders.update(b for a, b in zip(ordered, ordered[1:]) if b != a + 4)
    blocks = []
    for pc in ordered:
        if pc in leaders:
            blocks.append([])
        blocks[-1].append(pc)
    lines = ["digraph function {", '  node [shape=box];']
    for block in blocks:
        a, b = block[0], block[-1]
        lines.append(f'  n{a:x} [label="+0x{a-image.base:x} .. +0x{b-image.base:x}"];')
        transfers = outgoing.get(b, [])
        for kind, target in transfers:
            if target in leaders:
                dst = f"n{target:x}"
            else:
                dst = f"exit_{b:x}_{target or 0:x}"
                label = f"0x{target:x}" if target is not None else kind
                lines.append(f'  {dst} [label="{label}",shape=ellipse];')
            lines.append(f'  n{a:x} -> {dst} [label="{kind}"];')
        if b + 4 in leaders and (not transfers or transfers[0][0] in ("conditional", "call", "call-register")):
            lines.append(f'  n{a:x} -> n{b+4:x} [label="fallthrough"];')
    return "\n".join([*lines, "}", ""])
