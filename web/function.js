import {
  allCatalogs,
  decoder,
  details,
  escape as e,
  getFunction,
  hex,
  link,
  location,
  number,
  originalWords,
  rebuildWords,
  standalone,
  state,
  title,
} from "./data.js";

export const tag = (text, kind = "") =>
  `<span class="badge ${kind}">${e(text)}</span>`;
export const metrics = (rows) =>
  `<div class="metric-grid">${rows.map(([n, s]) => `<div class="metric"><b>${e(n)}</b><span>${e(s)}</span></div>`).join("")}</div>`;
export const header = (label, name, subtitle = "") =>
  `<p class="overline">${e(label)}</p><h1>${e(name)}</h1>${subtitle ? `<p class="sub">${e(subtitle)}</p>` : ""}`;
export function table(head, body, cls = "") {
  return `<div class="table-wrap"><table class="${cls}"><thead><tr>${head.map((h) => `<th scope="col">${e(h)}</th>`).join("")}</tr></thead><tbody>${body}</tbody></table></div>`;
}
export function pager(total, page, size) {
  const count = Math.max(1, Math.ceil(total / size));
  return `<div class="pager"><span>${total ? number(page * size + 1) + "–" + number(Math.min(total, (page + 1) * size)) + " of " + number(total) : "0 results"}</span>
    <button class="smallbtn" data-step="-1" ${page === 0 ? "disabled" : ""}>Previous</button><button class="smallbtn" data-step="1" ${page + 1 >= count ? "disabled" : ""}>Next</button></div>`;
}
export function bindPager(host, page, draw) {
  host
    .querySelectorAll("[data-step]")
    .forEach((b) => (b.onclick = () => draw(page + Number(b.dataset.step))));
}
function download(text, name) {
  const u = URL.createObjectURL(new Blob([text], { type: "text/plain" }));
  const a = document.createElement("a");
  a.href = u;
  a.download = name;
  a.click();
  setTimeout(() => URL.revokeObjectURL(u), 1200);
}
function markLine(line, language) {
  if (language === "asm") {
    if (line.startsWith("L_")) return `<span class="label">${e(line)}</span>`;
    const m = /^(\s*[a-f0-9]+\s+)([a-f0-9]{8}\s+)(\S+)(.*?)(  \/\/.*)?$/.exec(
      line,
    );
    if (m)
      return `<span class="addr">${e(m[1])}</span>${e(m[2])}<span class="op">${e(m[3])}</span>${e(m[4])}<span class="comment">${e(m[5])}</span>`;
  }
  if (line.trimStart().startsWith("//"))
    return `<span class="comment">${e(line)}</span>`;
  return e(line);
}
function codePanel(host, text, name, language, at) {
  const lines = text.trimEnd().split("\n"),
    size = 180;
  function draw(page) {
    host.innerHTML = `<section class="panel"><div class="code-tools"><span>${e(name)}</span><label><button class="smallbtn" data-save>Download</button></label></div>
      <pre class="code" tabindex="0">${lines
        .slice(page * size, (page + 1) * size)
        .map((l) => markLine(l, language))
        .join("\n")}</pre>
      ${pager(lines.length, page, size)}</section>`;
    bindPager(host, page, draw);
    host.querySelector("[data-save]").onclick = () => download(text, name);
  }
  const selected = at
    ? lines.findIndex((l) => l.trimStart().startsWith(at + " "))
    : 0;
  draw(Math.max(0, Math.floor(selected / size)));
}
const addrLink = (va, tab = "graph") => {
  const f = state.byAddress.get(va);
  return f
    ? `<a href="${link(f, tab)}" title="${e(location(va))}">${e(title(f))}</a>`
    : `<span>${e(location(va))}</span>`;
};
async function graphPanel(host, f, rec) {
  await allCatalogs();
  if (!host.isConnected) return;
  const neighbors = (edges) =>
    [
      ...new Set(
        edges
          .filter((x) => x[1] !== "fallthrough" && state.byAddress.has(x[2]))
          .map((x) => x[2]),
      ),
    ].slice(0, 3);
  const branch = (list) =>
    list.length
      ? list
          .map(
            (va) =>
              `<a class="neighbor" href="${link(state.byAddress.get(va), "graph")}" title="${e(location(va))}">${e(title(state.byAddress.get(va)))}</a>`,
          )
          .join("")
      : '<span class="muted">None indexed</span>';
  host.innerHTML = `<section class="panel"><div class="panel-head"><h2>Call graph</h2><a class="text-link" href="nnMain.graph.tsv.gz" download>Download nnMain graph ↓</a></div>
    <div class="neighborhood"><div><p class="overline">Callers →</p>${branch(neighbors(rec.incoming))}</div><div><p class="overline">Selected function</p><div class="gcenter">${e(title(f))}</div></div><div><p class="overline">→ Callees</p>${branch(neighbors(rec.outgoing))}</div></div></section>
    <div class="filters"><select aria-label="Edge direction" data-dir><option value="outgoing">Outgoing transfers (${number(rec.outgoing.length)})</option><option value="incoming">Incoming transfers (${number(rec.incoming.length)})</option></select>
    <select aria-label="Transfer filter" data-filter><option value="all">All transfers</option><option value="unknown">Unresolved targets</option><option value="known">Indexed targets</option></select></div><div class="panel" data-edges></div>`;
  const view = host.querySelector("[data-edges]"),
    dir = host.querySelector("[data-dir]"),
    filter = host.querySelector("[data-filter]");
  function draw(page = 0) {
    const edges = rec[dir.value].filter(
      (x) =>
        filter.value === "all" ||
        (filter.value === "unknown" ? x[2] == null : state.byAddress.has(x[2])),
    );
    const body = edges
      .slice(page * 35, (page + 1) * 35)
      .map(([site, kind, other, detail]) => {
        const caller =
          dir.value === "incoming" ? state.byAddress.get(other) : f;
        const siteCell = caller
          ? `<a class="mono" href="${link(caller)}?at=${site.toString(16)}">${e(location(site))}</a>`
          : e(location(site));
        return `<tr><td>${siteCell}</td><td>${tag(kind, other == null ? "warn" : "")}</td><td class="wide-name">${addrLink(other)}</td><td class="mono">${e(detail || "—")}</td></tr>`;
      })
      .join("");
    view.innerHTML =
      table(
        [
          "Instruction",
          "Transfer",
          dir.value === "incoming" ? "Caller" : "Target",
          "Register / symbol",
        ],
        body,
      ) +
      (edges.length
        ? ""
        : '<p class="empty">No transfers match this filter.</p>') +
      pager(edges.length, page, 35);
    bindPager(view, page, draw);
  }
  dir.onchange = filter.onchange = () => draw();
  draw();
}
function reportRows(report) {
  return table(
    ["Profile", "Rebuilt bytes", "Differing bytes", "Pending fixups", "Result"],
    report.candidates
      .map(
        (c) =>
          `<tr><td class="mono">-${e(c.profile)}</td><td>${number(c.compiled_bytes)}</td><td>${number(c.placed_different_bytes)}</td><td>${number(c.pending_relocations)}</td><td>${tag(c.exact ? "Exact" : "Different", c.exact ? "ok" : "")}</td></tr>`,
      )
      .join(""),
  );
}
async function comparisonPanel(host, f, rec) {
  const available = standalone(f);
  host.innerHTML = `<div class="filters"><label for="compare-source">Comparison</label><select id="compare-source">${available ? `<option value="standalone">Individual build · ${e(available.source)}</option>` : ""}<option value="bulk">Corpus build · lifted C · -O2</option></select></div><div data-body></div>`;
  const selector = host.querySelector("select"),
    area = host.querySelector("[data-body]");
  let version = 0;
  async function show() {
    const gen = ++version,
      single = selector.value === "standalone";
    area.innerHTML = '<div class="loading">Loading rebuild results…</div>';
    try {
      const d = single ? await details(f) : null;
      if (gen !== version || !host.isConnected) return;
      if (!single && rec.rebuild.error) {
        area.innerHTML = `<div class="panel"><h3 class="tight">Compiler diagnostic</h3><pre class="code">${e(rec.rebuild.error)}</pre></div>`;
        return;
      }
      const winner = d?.report.candidates.find(
        (x) => x.profile === d.report.selected,
      );
      const m = single
        ? {
            size: winner.compiled_bytes,
            different: winner.placed_different_bytes,
            pending: winner.pending_relocations,
            applied: winner.applied_relocations,
            first: winner.first_different_byte,
            exact: winner.exact,
          }
        : rec.rebuild;
      const orig = originalWords(rec.asm),
        ready = single
          ? [
              ...d.assembly.matchAll(
                /^\+0x[0-9a-f]+\s+([0-9a-f]{8})\s+(.+)$/gm,
              ),
            ].map((x) => [x[1], x[2]])
          : null;
      const packed = single ? null : rebuildWords(m.bytes);
      const words = single ? ready.map((x) => x[0]) : packed.words;
      const rows = Math.max(orig.length, words.length),
        fixes = single
          ? d.fixups.map((x) => [
              x.offset,
              x.type,
              x.symbol,
              x.destination || null,
            ])
          : m.fixups;
      const fx = new Map(fixes.map((x) => [x[0], x]));
      let dis = null;
      area.innerHTML = `<div class="row"><h2>AArch64 rebuild</h2>${tag(m.exact ? "Byte-exact" : "Bytes differ", m.exact ? "ok" : "warn")}</div>
        ${metrics([
          [number(f.size), "Original bytes"],
          [number(m.size), "Rebuilt bytes"],
          [number(m.different), "Differing bytes"],
          [number(m.pending), "Pending fixups"],
        ])}
        <p class="note">${single ? "Individual compilation · selected -" + e(d.report.selected) : "Grouped compilation · Clang -O2 · function inlining disabled between lifted entries"} · ${number(m.applied)} branch fixups applied. ${m.first == null ? "The byte sequences are identical." : "First differing byte at +" + hex(m.first) + "."}</p>
        ${single ? `<details class="panel spaced"><summary>Optimization profiles (${d.report.candidates.length})</summary>${reportRows(d.report)}</details>` : ""}
        ${d?.linked ? `<p class="tight note">Independent LLD link: ${d.linked.candidates[0].exact ? "exact" : "different"} at the original address.</p>` : ""}
        <div class="section-head"><h2>Instruction comparison</h2><label class="compact"><input type="checkbox" data-changed> Changed words only</label></div>
        <div class="panel" data-words></div><p class="note tight" data-decode></p>
        <details class="panel"><summary>Relocations (${number(fixes.length)})</summary><div data-fix></div></details>`;
      const changed = area.querySelector("[data-changed]"),
        grid = area.querySelector("[data-words]"),
        info = area.querySelector("[data-decode]");
      let ids = Array.from({ length: rows }, (_, i) => i),
        cur = 0;
      function draw(page = 0) {
        cur = page;
        const body = ids
          .slice(page * 60, (page + 1) * 60)
          .map((i) => {
            const off = i * 4,
              raw = words[i],
              left = orig[i],
              diff = left?.[0] !== raw;
            let op = single ? ready[i]?.[1] : "";
            if (dis && raw)
              try {
                const x = dis.disasm(
                  packed.bytes.subarray(off, off + 4),
                  f.va + off,
                  1,
                )[0];
                if (x) op = x.mnemonic + " " + x.op_str;
              } catch {
                op = ".word";
              }
            const fix = fx.get(off),
              annotation = fix ? ` · ${fix[3] || "pending " + fix[1]}` : "";
            return `<tr><td>+${hex(off)}</td><td class="${diff ? "old" : ""}"><span class="bytes">${e(left?.[0] || "—")}</span>  ${e(left?.[1] || "")}</td><td class="${diff ? "new" : ""}"><span class="bytes">${e(raw || "—")}</span>  ${e((op || "") + annotation)}</td></tr>`;
          })
          .join("");
        grid.innerHTML =
          table(
            ["Offset", "Original AArch64", "Rebuilt AArch64"],
            body,
            "diff",
          ) +
          (ids.length
            ? ""
            : '<p class="empty">No differing instruction words.</p>') +
          pager(ids.length, page, 60);
        bindPager(grid, page, draw);
      }
      changed.onchange = () => {
        ids = Array.from({ length: rows }, (_, i) => i).filter(
          (i) => !changed.checked || orig[i]?.[0] !== words[i],
        );
        draw();
      };
      draw();
      const fixHost = area.querySelector("[data-fix]");
      function fixPage(page = 0) {
        fixHost.innerHTML =
          table(
            ["Offset", "Type", "Symbol", "Destination"],
            fixes
              .slice(page * 35, (page + 1) * 35)
              .map(
                (x) =>
                  `<tr><td class="mono">+${hex(x[0])}</td><td>${e(x[1])}</td><td class="wide-name">${e(x[2])}</td><td>${e(x[3] || "Pending")}</td></tr>`,
              )
              .join(""),
          ) + pager(fixes.length, page, 35);
        bindPager(fixHost, page, fixPage);
      }
      fixPage();
      if (!single)
        try {
          dis = await decoder();
          if (gen === version && grid.isConnected) draw(cur);
        } catch (err) {
          if (gen === version)
            info.textContent =
              err.message + " Instruction words remain available.";
        }
    } catch (err) {
      if (gen === version) area.textContent = err.message;
    }
  }
  selector.onchange = show;
  await show();
}

export async function functionView(host, module, rva, tab, params) {
  const [f, rec] = await getFunction(module, rva);
  if (!host.isConnected) return;
  document.title = title(f) + " · ExeFS Explorer";
  const labels = {
    asm: "Assembly",
    c: "C source",
    graph: "Call graph",
    rebuild: "Rebuild",
  };
  if (!Object.hasOwn(labels, tab)) tab = "asm";
  host.innerHTML = `<p class="overline">${e(module)} module / Function</p><h1 class="fn-title">${e(title(f))}</h1>
    <div class="fn-meta"><span class="mono">${e(location(f.va))}</span><span>${number(f.size)} bytes</span>${tag(f.evidence)}${f.reachable ? tag("Reachable from nnMain") : ""}</div>
    <nav class="tabs" aria-label="Function views">${Object.entries(labels)
      .map(
        ([key, name]) =>
          `<a class="tab ${tab === key ? "current" : ""}" href="${link(f, key)}" ${tab === key ? 'aria-current="page"' : ""}>${name}</a>`,
      )
      .join("")}</nav><div data-function></div>`;
  const body = host.querySelector("[data-function]");
  if (tab === "asm")
    codePanel(
      body,
      rec.asm,
      f.module + "-" + f.rva.toString(16) + ".asm",
      "asm",
      params.get("at"),
    );
  else if (tab === "graph") await graphPanel(body, f, rec);
  else if (tab === "rebuild") await comparisonPanel(body, f, rec);
  else {
    const alt = standalone(f);
    body.innerHTML = `<div class="filters"><label for="source-kind">Source</label><select id="source-kind"><option value="lift">Lifted C · guest CPU state</option>${alt ? `<option value="native">${e(alt.source)}</option>` : ""}</select></div><div data-code></div>`;
    const select = body.querySelector("select"),
      area = body.querySelector("[data-code]");
    const show = async () => {
      const native = select.value === "native",
        d = native ? await details(f) : null;
      if (area.isConnected && (select.value === "native") === native)
        codePanel(
          area,
          native ? d.source : rec.c,
          native ? alt.source : f.module + "-" + f.rva.toString(16) + ".c",
          "c",
        );
    };
    select.onchange = () =>
      show().catch((err) => (area.textContent = err.message));
    await show();
  }
}
