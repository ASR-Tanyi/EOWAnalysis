#!/usr/bin/env python3
"""Differential check for a floating-point setter in the uploaded main NSO."""

import argparse
from contextlib import closing
import ctypes as ct
import importlib.util
import mmap
from pathlib import Path
import platform
import random
import shutil
import sqlite3
import struct
import subprocess
import sys
import tempfile

from unicorn import Uc, UC_ARCH_ARM64, UC_MODE_ARM
from unicorn import arm64_const as arm
from eow import Exporter, verified_image
from images import ROOT
from indexer import select_function

BUILD_ID = "9f221e1afa65ba5443e955158ab97da871e5e41f"
SELECTOR = "main:0xbde10"
GPRS = [arm.UC_ARM64_REG_X0 + i for i in range(29)] + [arm.UC_ARM64_REG_X29, arm.UC_ARM64_REG_X30]
VREGS = [arm.UC_ARM64_REG_Q0 + i for i in range(32)]
U64 = ct.c_uint64


def build_native(folder, src, start):
    if importlib.util.find_spec("ziglang"):
        cc = [sys.executable, "-m", "ziglang", "cc", "-mcpu=x86_64_v3"]
    elif shutil.which("clang"):
        cc = ["clang", "-march=x86-64-v3"]
    else:
        raise SystemExit("Install clang or the ziglang Python package")
    c_file = folder / "leaf.c"
    wrapper = """
#ifdef _WIN32
__declspec(dllexport)
#endif
void run_leaf(uint64_t *gpr, uint64_t *sp_flags, void *vectors) {
    Cpu state = {0};
    memcpy(state.x, gpr, 31 * 8);
    memcpy(state.v, vectors, sizeof state.v);
    state.sp = sp_flags[0];
    state.nzcv = sp_flags[1];
    FUNCTION(&state);
    memcpy(gpr, state.x, 31 * 8);
    memcpy(vectors, state.v, sizeof state.v);
    sp_flags[0] = state.sp;
    sp_flags[1] = state.nzcv;
}
"""
    c_file.write_text(src + wrapper.replace("FUNCTION", f"f_{start:x}"), encoding="utf-8")
    lib = folder / ("leaf.dll" if sys.platform == "win32" else "leaf.so")
    if sys.platform != "win32":
        cc.append("-fPIC")
    subprocess.run([*cc, "-shared", "-O1", "-fno-strict-aliasing", "-Wno-deprecated-declarations",
                    "-I", str(ROOT / "vendor/eowrecomp/runtime"), str(c_file), "-o", str(lib)], check=True)
    return ct.CDLL(str(lib))


def exercise(lib, code, start, cases, seed):
    rng = random.Random(seed)
    mu = Uc(UC_ARCH_ARM64, UC_MODE_ARM)
    page = start & ~4095
    stop = page + 4092
    mu.mem_map(page, 4096)
    mu.mem_write(start, code)
    mu.reg_write(arm.UC_ARM64_REG_CPACR_EL1, 0x300000)
    native = lib.run_leaf
    native.argtypes = [ct.POINTER(U64), ct.POINTER(U64), ct.c_void_p]
    native.restype = None
    changed = 0
    with mmap.mmap(-1, 4096) as buffer:
        address = ct.addressof(ct.c_char.from_buffer(buffer))
        mu.mem_map(address, 4096)
        for case in range(cases):
            original = bytearray(rng.randbytes(4096))
            incoming = rng.randrange(-1024, 1025) / 8
            old = (max(incoming, 0.0), incoming + 300.0, -0.0, +0.0)[case % 4]
            struct.pack_into("<f", original, 0x19c, old)
            buffer[:] = original
            mu.mem_write(address, bytes(original))
            gpr = (U64 * 31)(*(rng.getrandbits(64) for _ in GPRS))
            gpr[0], gpr[30] = address, stop
            sp_flags = (U64 * 2)(address + 0xf00, rng.getrandbits(4) << 28)
            vectors = bytearray(rng.randbytes(512))
            struct.pack_into("<f", vectors, 0, incoming)
            for reg, value in zip(GPRS, gpr):
                mu.reg_write(reg, value)
            for i, reg in enumerate(VREGS):
                mu.reg_write(reg, int.from_bytes(vectors[16*i:16*i+16], "little"))
            for reg, value in [(arm.UC_ARM64_REG_SP, sp_flags[0]), (arm.UC_ARM64_REG_NZCV, sp_flags[1]),
                               (arm.UC_ARM64_REG_FPCR, 0), (arm.UC_ARM64_REG_FPSR, 0)]:
                mu.reg_write(reg, value)
            mu.emu_start(start, stop, count=64)
            native(gpr, sp_flags, (ct.c_ubyte * 512).from_buffer(vectors))
            comparisons = {
                "return PC": mu.reg_read(arm.UC_ARM64_REG_PC) == stop,
                "X0-X30": list(gpr) == [mu.reg_read(reg) for reg in GPRS],
                "SP/NZCV": list(sp_flags) == [mu.reg_read(arm.UC_ARM64_REG_SP), mu.reg_read(arm.UC_ARM64_REG_NZCV)],
                "V0-V31": vectors == b"".join(mu.reg_read(reg).to_bytes(16, "little") for reg in VREGS),
                "4 KiB memory": buffer[:] == mu.mem_read(address, 4096),
            }
            if not all(comparisons.values()):
                failed = [k for k, ok in comparisons.items() if not ok]
                raise SystemExit(f"Mismatch at seed {seed}, case {case}: {failed}")
            changed += buffer[:] != original
    if not 0 < changed < cases:
        raise SystemExit("Inputs did not cover both the update and unchanged paths")
    print(f"{SELECTOR}: {cases} matched, {changed} changed memory, {cases-changed} unchanged (seed {seed})")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--cases", type=int, default=256)
    parser.add_argument("--seed", type=int, default=42)
    args = parser.parse_args()
    if args.cases < 2:
        parser.error("--cases must be at least 2 to exercise both paths")
    if platform.machine().lower() not in ("x86_64", "amd64"):
        parser.error("this check compiles and executes the x64 lowering on an x64 host")
    path = ROOT / "build/index.sqlite"
    with closing(sqlite3.connect(path.as_uri() + "?mode=ro", uri=True)) as db:
        name, fn = select_function(db, SELECTOR)
        image = verified_image(db, ROOT / "ExeFS", name)
        if image.build_id != BUILD_ID:
            raise SystemExit("This test fixture belongs to a different main build")
        src = Exporter(db, image).render(fn, "c")
        code = bytes(image.nso.image[fn.start-image.base:fn.end-image.base])
    with tempfile.TemporaryDirectory() as directory:
        lib = build_native(Path(directory), src, fn.start)
        try:
            exercise(lib, code, fn.start, args.cases, args.seed)
        finally:
            if sys.platform == "win32":
                import _ctypes
                _ctypes.FreeLibrary(lib._handle)


if __name__ == "__main__":
    main()
