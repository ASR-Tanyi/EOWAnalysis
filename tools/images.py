"""Metadata for the AArch64 NSOs in this ExeFS. Internal addresses are analysis VAs."""

from dataclasses import dataclass
import hashlib
from pathlib import Path
import struct
import sys

ROOT = Path(__file__).resolve().parents[1]
UPSTREAM = ROOT / "vendor" / "eowrecomp" / "tools"
if not (UPSTREAM / "gen.py").is_file():
    raise SystemExit("Initialize the pinned tools with git submodule update --init")
sys.path.insert(0, str(UPSTREAM))
from gen import Module


# Stable analysis addresses. The four application modules follow runtime/modules.h.
# The loader is given a separate range so its entry and imports can share the graph.
BASE = dict(rtld=0x6FFF000000, main=0x7000000000, subsdk0=0x7008000000,
            subsdk1=0x700A000000, sdk=0x700C000000)
SDK_START = "_ZN2nn4init5StartEmmPFvvES2_S2_"
U32 = struct.Struct("<I")
U64 = struct.Struct("<Q")
SYMBOL = struct.Struct("<IBBHQQ")


def program_id(exefs):
    data = (exefs / "main.npdm").read_bytes()
    if data[:4] != b"META":
        raise ValueError("Expected META in main.npdm")
    aci, size = struct.unpack_from("<II", data, 0x70)
    if size < 0x18 or aci + size > len(data) or data[aci:aci + 4] != b"ACI0":
        raise ValueError("Invalid ACI0 range in main.npdm")
    return f"{U64.unpack_from(data, aci + 0x10)[0]:016X}"


def relr_slots(image, start, size):
    """ELF64 RELR stores an address followed by zero or more 63-slot bitmaps."""
    if size % 8 or start + size > len(image):
        raise ValueError("Invalid RELR table")
    cursor = None
    for (entry,) in struct.iter_unpack("<Q", memoryview(image)[start:start + size]):
        if not entry & 1:
            if entry % 8 or entry + 8 > len(image):
                raise ValueError("Invalid RELR address")
            yield entry
            cursor = entry + 8
        else:
            if cursor is None:
                raise ValueError("RELR bitmap has no base address")
            bits = entry >> 1
            while bits:
                bit = bits & -bits
                address = cursor + 8 * (bit.bit_length() - 1)
                if address + 8 > len(image):
                    raise ValueError("RELR bitmap points outside the image")
                yield address
                bits ^= bit
            cursor += 63 * 8


@dataclass(frozen=True, slots=True)
class Function:
    start: int
    end: int
    name: str
    evidence: str


class Image(Module):
    def __init__(self, exefs, name):
        path = exefs / name
        with path.open("rb") as f:
            header = f.read(0x100)
            f.seek(0)
            self.sha256 = hashlib.file_digest(f, "sha256").hexdigest()
        if len(header) != 0x100 or header[:4] != b"NSO0":
            raise ValueError(f"{name} is not an NSO0 module")
        super().__init__(name, str(path), BASE[name], simd="c")
        n = self.nso
        raw_id = header[0x40:0x60]
        self.build_id = (raw_id[:20] if raw_id[20:] == bytes(12) else raw_id).hex()
        self.segments = {"text": n.text, "rodata": n.rodata, "data": n.data}
        flags = U32.unpack_from(header, 0x0c)[0]
        for i, (off, size) in enumerate(self.segments.values()):
            if flags & (8 << i):
                digest = hashlib.sha256(memoryview(n.image)[off:off + size]).digest()
                if digest != header[0xa0 + i * 32:0xc0 + i * 32]:
                    raise ValueError(f"{name}: segment {i} hash mismatch")
        self.segments["bss"] = (n.bss_start, n.bss_end - n.bss_start)
        if any(base > self.base and self.base + n.size > base for base in BASE.values()):
            raise ValueError(f"{name}: analysis addresses overlap another module")

        # The NSO0 header gives the dynsym extent even in GNU-hash-only NSOs.
        st_rel, st_size = struct.unpack_from("<II", header, 0x98)
        st = n.rodata[0] + st_rel
        if (st != n.dyn[6] or st_size % SYMBOL.size or n.dyn.get(11) != SYMBOL.size
                or st_rel + st_size > n.rodata[1]):
            raise ValueError(f"{name}: inconsistent dynamic symbol table")
        self.symbols = [(n.cstr(n.dyn[5] + sn), info, other, section, value, size)
                        for sn, info, other, section, value, size in
                        SYMBOL.iter_unpack(memoryview(n.image)[st:st + st_size])]

    def code_pointers(self):
        """Relocated data slots pointing into .text; these establish no call by themselves."""
        n = self.nso
        for slot, kind, symbol, addend in n.relocs:
            if kind == 257 and self.symbols[symbol][3]:
                target = self.symbols[symbol][4] + addend
            elif kind == 1027:
                target = addend
            else:
                continue
            if self.in_text(self.base + target):
                yield self.base + slot, self.base + target, "RELA"
        if 36 in n.dyn:
            if n.dyn.get(37) != 8:
                raise ValueError("Unsupported RELR entry size")
            for slot in relr_slots(n.image, n.dyn[36], n.dyn[35]):
                target = n.u64(slot)
                if self.in_text(self.base + target):
                    yield self.base + slot, self.base + target, "RELR"

    def unwind_ranges(self):
        """Read actual FDE extents, validating both PC encodings against the header."""
        n = self.nso
        h = n.eh_start
        data = n.image
        if data[h:h + 4] != bytes.fromhex("01 1b 03 3b"):
            raise ValueError(f"{self.name}: unsupported .eh_frame_hdr encoding")
        count = n.u32(h + 8)
        if h + 12 + count * 8 > n.eh_end:
            raise ValueError("Truncated unwind index")
        table = memoryview(data)[h + 12:h + 12 + count * 8]
        for rel_pc, rel_fde in struct.iter_unpack("<ii", table):
            fde = h + rel_fde
            if fde < 0 or fde + 16 > len(data) or not 12 <= n.u32(fde) <= len(data) - fde - 4:
                raise ValueError("Invalid FDE length")
            delta, size = struct.unpack_from("<iI", data, fde + 8)
            start = h + rel_pc
            if (fde + 8 + delta != start or not self.in_text(self.base + start)
                    or not size or size % 4 or self.base + start + size > self.hi):
                raise ValueError(f"{self.name}: invalid or unsupported FDE at {fde:#x}")
            yield self.base + start, self.base + start + size

    def plt_stubs(self):
        """Verify the ADRP/LDR/ADD/BR stub and its GOT slot against JUMP_SLOT."""
        slots = {slot: index for slot, kind, index, _ in self.nso.relocs if kind == 1026}
        data = self.nso.image
        needle = bytes.fromhex("20 02 1f d6")  # BR X17
        pos = self.nso.text[0]
        stop = pos + self.nso.text[1]
        while True:
            end = data.find(needle, pos, stop)
            if end < 0:
                break
            pos = end + 1
            if end % 4 or end < self.nso.text[0] + 12:
                continue
            entry = end - 12
            adrp, load, add = struct.unpack_from("<III", data, entry)
            if (adrp & 0x9f00001f != 0x90000010 or load & 0xffc003ff != 0xf9400211
                    or add & 0xffc003ff != 0x91000210):
                continue
            offset = ((load >> 10) & 4095) * 8
            if offset != (add >> 10) & 4095:
                continue
            pages = ((adrp >> 5 & 0x7ffff) << 2) | (adrp >> 29 & 3)
            pages = (pages ^ 0x100000) - 0x100000
            slot = (entry & ~4095) + (pages << 12) + offset
            if slot in slots:
                yield self.base + entry, slots[slot], self.base + slot

    def functions(self):
        recovered = {a: Function(a, b, "", "FDE") for a, b in self.unwind_ranges()}
        self._eh = sorted(recovered)  # upstream switch resolver uses this exact unwind index
        for name, info, _, section, rva, size in self.symbols:
            a = self.base + rva
            if not section or info & 15 != 2 or not self.in_text(a):
                continue
            previous = recovered.get(a)
            if previous is not None:
                if not previous.name:
                    recovered[a] = Function(a, previous.end, name, "FDE+symbol")
            elif size and not size % 4 and a + size <= self.hi:
                recovered[a] = Function(a, a + size, name, "symbol")
        self.stubs = {a: (idx, slot) for a, idx, slot in self.plt_stubs()}
        for a, (idx, _) in self.stubs.items():
            recovered[a] = Function(a, a + 16, "plt:" + self.symbols[idx][0], "PLT")
        ordered = sorted(recovered.values(), key=lambda f: f.start)
        if any(a.end > b.start for a, b in zip(ordered, ordered[1:])):
            raise ValueError(f"{self.name}: overlapping function evidence requires review")
        return ordered
