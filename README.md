# Echoes of Wisdom ExeFS analysis

The game entry in this upload is **`nnMain` at `main+0x360b70`**. Its dynamic symbol and unwind record identify the same start, and the SDK calls it through a verified import stub. The ACI0 program ID is `01008CF01BAAC000`. The `main` NSO build ID is `9f221e1afa65ba5443e955158ab97da871e5e41f`. Use the build ID when comparing addresses across copies of the game.

| Start here | What it contains |
| --- | --- |
| [nnMain.asm](analysis/nnMain.asm) | Original instruction words, AArch64 disassembly, local branch labels, calls and unresolved exits |
| [nnMain.c](analysis/nnMain.c) | The same function lifted to C, with guest registers, memory operations and control flow explicit |
| [nnMain.graph.tsv.gz](analysis/nnMain.graph.tsv.gz) | The full static traversal from `nnMain`, with one row per transfer site and target |
| [baseline.json](analysis/baseline.json) | Input hashes and build IDs, function and switch counts, startup edges and unresolved transfers |
| [exports.json](analysis/exports.json) | Per-module assembly and C export counts, byte totals and unsupported instructions |

## How execution reaches the game

Offsets are relative to the named module's in-memory image. The first function in the loader and the application entry are distinct.

| Caller and instruction | Import stub and slot | Resolved destination |
| --- | --- | --- |
| Loader entry `rtld+0x0`, `bl` at `rtld+0x88` | `rtld+0x2530`, GOT slot `rtld+0x42e8` | `sdk+0x110dd0` · `nn::init::Start` |
| `nn::init::Start`, `bl` at `sdk+0x110e20` | `sdk+0x647140`, GOT slot `sdk+0xb6bd40` | `main+0x360b70` · `nnMain`, size `0x2108` bytes |

`nnMain` has 160 direct call sites reaching 61 distinct immediate targets, plus 80 calls through registers. For example, the call at `main+0x360bac` goes through the `_Znwm` (`operator new`) stub. At `main+0x360dd4`, the code loads a table pointer from `[x0]`, loads slot `+8` from that table and executes `blr x8`. The graph records the register and leaves the destination open until the receiver can be identified.

Following known targets reaches **3,970 entries**, including the root and import stubs. The compressed TSV contains 20,613 transfer rows. `caller_depth` is the shortest known distance from the root. The traversal follows direct calls, cross-function branches and resolved imports. It records an indirect transfer with an empty `target`. A `fallthrough` row records execution reaching the end of a recovered extent. The traversal stops at that boundary. Code pointers in data are indexed separately so an address stored in a table does not become an invented call edge.

## Scope of the export

| ExeFS module | Bounded functions and stubs | Of which import stubs |
| --- | ---: | ---: |
| `rtld` | 34 | 1 |
| `main` | 226,437 | 629 |
| `subsdk0` | 42,500 | 145 |
| `subsdk1` | 13,928 | 3,816 |
| `sdk` | 40,439 | 7,809 |
| **Total** | **323,338** | **12,400** |

Boundaries come from unwind frame description entries (FDEs), sized function symbols and verified 16-byte procedure linkage table (PLT) stubs. For each stub, the instructions identify the Global Offset Table (GOT) slot and its `JUMP_SLOT` relocation identifies the symbol. All 12,400 stubs have an indexed destination in this build. The index records 3,319 recognized switch sites and 499,115 relocated data slots pointing into module text.

Every bounded entry has been exported as both assembly and C. Stripped functions keep address-based names. Within an extent, the assembly shows a `.word` directive for bytes outside the recovered control flow and identifies referenced literal data where possible. The C uses the pinned lifter's portable operations and `Cpu` guest state. Register-indirect transfers retain a runtime dispatch path. One SDK instruction, `stg x8, [x8]` at `sdk+0x63e990`, still emits an explicit unsupported-instruction trap. Instruction coverage alone does not establish behavioral equivalence.

## Reproduce the analysis

Use Python 3.11 or newer. From the repository root, activate a Python virtual environment and run the following commands. The submodule pins the NSO decoder, AArch64 lifter and runtime headers used by these exports.

```sh
git submodule update --init
python -m pip install -r requirements.txt
python tools/eow.py index
python tools/eow.py summary --out build/baseline.json
python tools/eow.py data
```

`index` creates `build/index.sqlite` from all five NSOs and `main.npdm`. `data` writes decompressed `text.bin`, `rodata.bin` and `data.bin` plus `layout.json` under `build/segments/<module>/<build-id>/`. The images preserve original unrelocated bytes. The layout gives the RVA and length of zero-filled BSS. The ExeFS is sufficient for this code analysis. Running game paths that read levels, models or other assets will also require the corresponding RomFS content and host implementations for the services they call.

To inspect one function and the first two levels of outgoing transfers, run the commands below. A selector accepts a symbol or a module-relative start address, such as `main:0x360b70`. Graphviz can render the `.dot` file with `dot -Tsvg build/nnMain.dot -o build/nnMain.svg`.

```sh
python tools/eow.py function main:nnMain --format asm --out build/nnMain.asm
python tools/eow.py function main:nnMain --format dot --out build/nnMain.dot
python tools/eow.py function main:nnMain --format c --out build/nnMain.c
python tools/eow.py graph main:nnMain --depth 2 --out build/nnMain-depth2.tsv
python tools/eow.py graph main:nnMain --out build/nnMain.graph.tsv.gz
```

To regenerate the bulk exports, use `split`. Substitute one module name for `all` to work in smaller batches. The full pair writes 646,676 function files, so individual function queries are faster for exploration. Bulk results stay under `build/functions/<module>/<build-id>/`, grouped by the high bits of each function's RVA. Each format writes a manifest when the module completes.

```sh
python tools/eow.py split all --format asm
python tools/eow.py split all --format c
python tools/eow.py exports --out build/exports.json
```

## Compare the C with the original ARM64

Compare observable state at the same function boundary. The included test uses `main+0xbde10`, an 11-instruction floating-point setter. It selects zero for a negative input, compares the result with the float at `x0+0x19c`, and updates that field and flag bit `0x40` at `x0+0x198` when the value changes. Both the store and the early return can be checked without a Switch service implementation.

`check_leaf.py` reads the original bytes from this build, runs them in ARM64 Unicorn and runs the generated C natively on an x86-64 host with x86-64-v3 support. Each pair gets the same register state and 4 KiB memory image. The check compares X0–X30, SP, NZCV, all 32 vector registers and the entire buffer. It also checks that ARM64 returned to the expected address. On Linux x86-64, seed 42 matched **256/256 cases**. Memory changed in 133 cases and stayed unchanged in 123. This covers that function and those inputs.

```sh
python -m pip install ziglang==0.17.0.post0
python -m unittest discover -s tests -v
python tools/check_leaf.py --cases 256 --seed 42
```

The following command compiled the checked-in `nnMain.c` into a Windows x64 COFF object. Linking and running it requires a guest address space, a dispatcher for indirect calls, module relocations and the invoked runtime services.

```sh
python -m ziglang cc -target x86_64-windows-gnu -mcpu=x86_64_v3 -O1 -fno-strict-aliasing -Wno-deprecated-declarations -Ivendor/eowrecomp/runtime -c analysis/nnMain.c -o build/nnMain.obj
```

## Work plan

| Stage | Status and completion criterion |
| --- | --- |
| 1. Identify the build and recover the entry | Complete for these five modules. The baseline records the input hashes, verified function extents and both startup imports. |
| 2. Split code and data and export control flow | Complete for the 323,338 bounded entries. Assembly and C counts are reproducible per module. The SQLite index, raw segments, per-function CFGs and reachable graph can be regenerated independently. |
| 3. Resolve indirect game calls | Start at `main+0x360dd4`. Trace the receiver and its possible table initializers, cross-check each slot against relocated data, and record the evidence for each target. Repeat for the remaining register calls in `nnMain` and expand the graph from newly confirmed callees. |
| 4. Validate the C across more functions | The first differential fixture and the `nnMain` object build pass. Add fixtures for a recovered switch, a call with side effects and floating-point edge cases. Resolve the SDK `stg` trap or establish how the reference runtime handles its path. Record the first mismatching instruction or state field for any failure. |
| 5. Run a Windows startup slice | Build revision-specific dispatch and relocation tables, wire the SDK services reached by startup, then link and run from the loader to `nnMain` on Windows. Compare a startup trace with the ARM64 reference before expanding to assets and rendering. |

The upstream dependency has its own license and is pinned by the repository's submodule revision. [EoWRecomp](https://github.com/Nycolazs/EoWRecomp)
