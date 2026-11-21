# Echoes of Wisdom ExeFS analysis

The game entry in this upload is **`nnMain` at `main+0x360b70`**. Its dynamic symbol and unwind record identify the same start, and the SDK calls it through a verified import stub. The ACI0 program ID is `01008CF01BAAC000`. The `main` NSO build ID is `9f221e1afa65ba5443e955158ab97da871e5e41f`. Use the build ID when comparing addresses across copies of the game.

Open the [ExeFS Explorer](https://asr-tanyi.github.io/EOWAnalysis/) to browse the analysis in a browser. [Entry points](https://asr-tanyi.github.io/EOWAnalysis/#entries) · [Call graph](https://asr-tanyi.github.io/EOWAnalysis/#graph) · [Rebuild comparisons](https://asr-tanyi.github.io/EOWAnalysis/#rebuilds)

| Start here | What it contains |
| --- | --- |
| [nnMain.asm](analysis/nnMain.asm) | Original instruction words, AArch64 disassembly, local branch labels, calls and unresolved exits |
| [nnMain.c](analysis/nnMain.c) | The same function lifted to C, with guest registers, memory operations and control flow explicit |
| [nnMain.graph.tsv.gz](analysis/nnMain.graph.tsv.gz) | The full static traversal from `nnMain`, with one row per transfer site and target |
| [baseline.json](analysis/baseline.json) | Input hashes and build IDs, function and switch counts, startup edges and unresolved transfers |
| [exports.json](analysis/exports.json) | Per-module assembly and C export counts, byte totals and unsupported instructions |
| [AArch64 rebuild results](#match-rebuilt-aarch64-instruction-bytes) | Commands, real binary differences and six functions that rebuild byte-for-byte |

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

## Match rebuilt AArch64 instruction bytes

Use an **AArch64 build** to match the Switch instructions. Use the x64 build and the differential test above to check Windows-port behavior. The existing C lift takes a `Cpu *` and explicitly maintains guest registers. C written with the original calling convention can instead pass an object pointer in `x0` and a float in `s0`. The compiler can then emit the same loads, comparisons and stores as the game. [Arm procedure call standard](https://github.com/ARM-software/abi-aa/blob/main/aapcs64/aapcs64.rst)

From the repository root, initialize the tools and build the index once.

```sh
git submodule update --init
python -m pip install -r requirements.txt ziglang==0.17.0.post0
python tools/eow.py index
```

Compile the checked-in `nnMain.c` and compare it to precisely the `nnMain` extent in the decompressed `main` NSO. Then compile two native-ABI reconstructions. The optimization sweep retains the closest result and reports every profile it tested.

```sh
python tools/match.py main:nnMain --source analysis/nnMain.c --opts O1 O2 O3 Os Oz --out build/match/nnMain
python tools/match.py main:0xbde10 --source matching/setters.c --opts O2 --require-exact --out build/match/setter
python tools/match.py main:0x2362258 --source matching/tree.c --opts O2 Os --require-exact --out build/match/tree
```

Open `diff.txt` in the selected output directory for the instruction diff. `original.bin` holds the original function bytes, `input.bin` holds the rebuilt symbol bytes before any comparator fixups, and `rebuilt.bin` holds the result at the original guest address. The directory also contains both disassemblies, the compiled ELF, `relocations.json` and `report.json`. Omitting `--source` generates and compiles the existing CPU-state lift for any indexed function. Use `--symbol` if the compiled C uses a different function name.

| Function and source | Profile | Original bytes | Rebuilt bytes | Differing bytes after placement |
| --- | --- | ---: | ---: | ---: |
| [Setter, CPU-state lift](analysis/matching/setter-lifted.json) | `-Os` | 44 | 204 | 201 |
| [Setter, native arguments](analysis/matching/setter.json) | `-O2` | 44 | 44 | **0** |
| [Recursive tree cleanup, native arguments](analysis/matching/tree.json) | `-O2` | 56 | 60 | 45 |
| Same tree cleanup | `-Os` | 56 | 56 | **0** |
| [nnMain, checked-in CPU-state lift](analysis/matching/nnMain.json) | `-Oz` | 8,456 | 23,936 | 23,393, with 143 pending relocations |

These measurements use Clang 22.1.8, the `aarch64-linux-musl` target and `cortex_a57` tuning. The original compiler version and flags are unknown. The comparison build uses per-function sections and disables machine outlining to keep repeated instruction sequences in the function being scored.

**How the score works.** A differing byte at the same function offset counts once. Extra or missing tail bytes also count once each. An exact result requires equal lengths, identical bytes and zero pending relocations. The sweep picks an exact result first, then minimizes differing bytes, then pending relocations, keeping the first profile on a tie. `diff.txt` aligns matching instruction runs so an inserted instruction is easier to see. The byte score always uses the original offsets.

**How branches are compared.** An ELF object can contain placeholders for `bl` and `b`. The tool resolves `CALL26` and `JUMP26` from the symbol, addend, rebuilt instruction address and verified guest target. Targets may be the function itself, an indexed address-based function or a unique import stub in the caller's module. Other fixups remain visible as pending. [Actual tree fixups](analysis/matching/tree-relocations.json) · [Arm ELF relocation definitions](https://github.com/ARM-software/abi-aa/blob/main/aaelf64/aaelf64.rst)

For an independent check, let LLVM's linker place the recursive function at its original address and bind `_ZdlPv` to the address of the game's import stub. Run these commands after the tree comparison above. The resulting ELF's function body matches all 56 bytes, including both recursive calls and the tail branch to `operator delete`. [Linked ELF comparison](analysis/matching/tree-linked.json)

```sh
python -m ziglang ld.lld -m aarch64elf -Ttext=0x7002362258 --defsym=_ZdlPv=0x7002833e20 -e f_7002362258 -o build/match/tree.elf build/match/tree/rebuilt.o
python tools/match.py main:0x2362258 --linked build/match/tree.elf --require-exact --out build/match/tree-linked
```

**How to reduce a new difference.** Start with the first changed instruction in a short function with known inputs. Recover the parameter types, signedness and field offsets from its callers and loads. If the difference is in a branch immediate, inspect its relocation. If it is an extra load, register move or stack spill, check the C signature and value lifetimes first, then sweep the optimization levels. In the tree cleanup, `-O2` produced an extra move before its first recursive call. `-Os` removed it. For another compiler or SDK build, pass its unstripped AArch64 ELF using `--object path/to/file.o`, or use `--linked` for a static ELF linked at the original address.

The regression test rebuilds the five setters at `main+0xbde10`, `+0xbde3c`, `+0xbde5c`, `+0xbde7c` and `+0xbde9c`, plus the cleanup at `main+0x2362258`. It reads the original text independently and checks the cleanup again with LLD. Run `python -m unittest discover -s tests -v` after setup. [Setter source](matching/setters.c) · [Tree cleanup source](matching/tree.c)

## Publish the HTML explorer

[Publish ExeFS explorer](.github/workflows/pages.yml) runs on pushes to `main` and from **Actions → Publish ExeFS explorer → Run workflow**. The repository's Pages source is configured under **Settings → Pages → Build and deployment → Source → GitHub Actions**.

Every indexed function and import stub gets a bookmarkable page with assembly, C, incoming and outgoing transfers, and a short rebuild report. The report gives original and rebuilt sizes, differing bytes, first difference and pending relocations. Follow a caller or callee to re-center the graph, or select a call site to open the original assembly. The entry-point page traces the startup path to `nnMain`. The complete reachable graph is also available as a TSV download.

**Detailed comparisons** are attached to each successful workflow run for 14 days. The public Rebuild tab links to both downloads. GitHub may ask you to sign in to download an Actions artifact.

| Download | Contents |
| --- | --- |
| `comparison-logs` | `functions.tsv.gz` locates each function and its per-block log. The logs list all differing original and rebuilt instruction words by offset, size differences, fixups and compiler diagnostics. The `individual/` folders include complete disassembly diffs and per-profile reports. |
| `local-html` | The full explorer, including a side-by-side instruction diff, a changed-words filter and individual relocations. Extract the archive, run `python -m http.server 8000` in the directory containing `index.html`, then open `http://localhost:8000`. The decoder and analysis data are bundled. |

The workflow indexes the ExeFS once and assigns address ranges to build jobs. Grouped compilations use AArch64 `-O2`, per-function sections, interposable calls and explicit function boundaries. An individual compiler error is isolated to its function. The standalone reports rerun five optimization profiles for `nnMain` and the six native C fixtures, including the independently linked tree cleanup. The Actions job summary reports counts by module.

Before deployment, the workflow checks the count and checksum of every required group and exercises the public and detailed views in Chromium. The public site omits rebuilt byte streams and full relocation lists. If the compressed public site exceeds 1 GB, it retains the complete function index, graph and rebuild summaries and keeps online source listings for the entry points and comparison fixtures. Every function's assembly and C remain in the detailed HTML download. [GitHub Pages limits](https://docs.github.com/en/pages/getting-started-with-github-pages/github-pages-limits) · [Capstone.js](https://github.com/AlexAltea/capstone.js/releases/tag/v5.0.9)

To reproduce the outputs locally, install the analysis requirements and Zig, then use empty output directories.

```sh
python tools/eow.py index
python tools/pages.py build --out build/local-html
python tools/pages_report.py build/local-html --out build/site --logs build/comparison-logs
python -m http.server 8000 --directory build/local-html
```

## Work plan

| Stage | Status and completion criterion |
| --- | --- |
| 1. Identify the build and recover the entry | Complete for these five modules. The baseline records the input hashes, verified function extents and both startup imports. |
| 2. Split code and data and export control flow | Complete for the 323,338 bounded entries. Assembly and C counts are reproducible per module. The SQLite index, raw segments, per-function CFGs and reachable graph can be regenerated independently. |
| 3. Resolve indirect game calls | Start at `main+0x360dd4`. Trace the receiver and its possible table initializers, cross-check each slot against relocated data, and record the evidence for each target. Repeat for the remaining register calls in `nnMain` and expand the graph from newly confirmed callees. |
| 4. Validate the C across more functions | Six native-ABI functions reproduce the original AArch64 bytes, including a callee of `nnMain`. The CPU-state lift also has a passing x64 differential fixture. Recover more native signatures along the `nnMain` call path, add fixtures for a switch and floating-point edge cases, and resolve the SDK `stg` path. |
| 5. Run a Windows startup slice | Build revision-specific dispatch and relocation tables, wire the SDK services reached by startup, then link and run from the loader to `nnMain` on Windows. Compare a startup trace with the ARM64 reference before expanding to assets and rendering. |

The upstream dependency has its own license and is pinned by the repository's submodule revision. [EoWRecomp](https://github.com/Nycolazs/EoWRecomp)
