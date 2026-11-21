export const number = (n) => Number(n).toLocaleString("en-US");
export const hex = (n) => "0x" + Number(n).toString(16);
export const escape = (v) =>
  String(v ?? "").replace(
    /[&<>"']/g,
    (ch) =>
      ({ "&": "&amp;", "<": "&lt;", ">": "&gt;", '"': "&quot;", "'": "&#39;" })[
        ch
      ],
  );
export const state = {
  manifest: null,
  modules: new Map(),
  byAddress: new Map(),
};
const catalogs = new Map(),
  blocks = new Map(),
  reports = new Map();

async function load(path) {
  const suffix = state.manifest
    ? "?v=" + encodeURIComponent(state.manifest.revision)
    : "";
  const response = await fetch(path + suffix, {
    cache: path === "manifest.json" ? "no-cache" : "default",
  });
  if (!response.ok)
    throw Error("Could not load " + path + " (HTTP " + response.status + ")");
  if (!path.endsWith(".gz")) return response.json();
  const bytes = new Uint8Array(await response.arrayBuffer());
  if (bytes[0] !== 31 || bytes[1] !== 139)
    return JSON.parse(new TextDecoder().decode(bytes));
  const stream = new Blob([bytes])
    .stream()
    .pipeThrough(new DecompressionStream("gzip"));
  return new Response(stream).json();
}
function cached(map, key, read) {
  if (!map.has(key))
    map.set(
      key,
      read().catch((err) => {
        map.delete(key);
        throw err;
      }),
    );
  return map.get(key);
}
export async function initialize() {
  state.manifest = await load("manifest.json");
  for (const module of state.manifest.modules)
    state.modules.set(module.name, module);
  return state.manifest;
}
export function catalog(name) {
  if (!state.modules.has(name)) throw Error("Unknown module " + name);
  return cached(catalogs, name, async () => {
    const m = state.modules.get(name);
    const data = await load("catalog/" + name + ".json.gz");
    return data.map(([rva, size, symbol, evidence, reachable]) => {
      const f = {
        module: name,
        rva,
        size,
        symbol,
        evidence,
        reachable,
        va: m.base + rva,
      };
      state.byAddress.set(f.va, f);
      return f;
    });
  });
}
export const allCatalogs = () =>
  Promise.all([...state.modules.keys()].map(catalog));
export function location(va) {
  if (va == null) return "Unresolved";
  let owner;
  for (const m of state.modules.values())
    if (m.base <= va && (!owner || m.base > owner.base)) owner = m;
  return owner ? owner.name + "+" + hex(va - owner.base) : hex(va);
}
export const title = (f) =>
  f.symbol || "sub_" + f.rva.toString(16).padStart(8, "0");
export const link = (f, tab = "asm") =>
  "#fn/" + f.module + "/" + f.rva.toString(16) + "/" + tab;
export function queryMatches(f, input) {
  const q = input.trim().toLowerCase();
  if (!q) return true;
  const exact =
    /^(?:(rtld|main|subsdk0|subsdk1|sdk)[+:])?(?:0x|f_|sub_)?([0-9a-f]+)$/.exec(
      q,
    );
  if (exact && (!exact[1] || exact[1] === f.module)) {
    const n = parseInt(exact[2], 16);
    if (f.rva === n || f.va === n) return true;
  }
  return f.symbol.toLowerCase().includes(q);
}
export async function getFunction(module, rva) {
  await catalog(module);
  const f = state.byAddress.get(state.modules.get(module).base + rva);
  if (!f) throw Error("No indexed function at " + module + "+" + hex(rva));
  const key =
    module + "/" + Math.floor(rva / 2 ** state.manifest.shift).toString(16);
  if (!blocks.has(key) && blocks.size >= 5)
    blocks.delete(blocks.keys().next().value);
  const data = await cached(blocks, key, () =>
    load("data/" + key + ".json.gz"),
  );
  const record = data[rva.toString(16)];
  if (!record) throw Error("Function data is missing for " + location(f.va));
  return [f, record];
}
export function standalone(f) {
  return state.manifest.comparisons.find(
    (r) => r.module === f.module && r.rva === f.rva,
  );
}
export function details(f) {
  return cached(reports, f.va, () =>
    load("comparisons/" + f.rva.toString(16) + ".json.gz"),
  );
}
let decoderPromise;
export function decoder() {
  if (!decoderPromise)
    decoderPromise = new Promise((resolve, reject) => {
      const script = document.createElement("script");
      script.src = "decoder/capstone_arm64.js";
      script.onerror = () =>
        reject(Error("The rebuilt disassembler could not load."));
      script.onload = () =>
        window
          .MCapstone()
          .then((cs) => resolve(new cs.Capstone(cs.ARCH_ARM64, cs.MODE_ARM)))
          .catch(reject);
      document.head.append(script);
    }).catch((err) => {
      decoderPromise = null;
      throw err;
    });
  return decoderPromise;
}
export function originalWords(text) {
  return [...text.matchAll(/^\s*([0-9a-f]+)\s+([0-9a-f]{8})\s+(.+)$/gm)].map(
    (m) => [m[2], m[3].split("  //")[0]],
  );
}
export function rebuildWords(text) {
  const bytes = Uint8Array.from(atob(text), (c) => c.charCodeAt(0));
  const view = new DataView(bytes.buffer),
    words = [];
  for (let i = 0; i < bytes.length; i += 4)
    words.push(view.getUint32(i, true).toString(16).padStart(8, "0"));
  return { bytes, words };
}
