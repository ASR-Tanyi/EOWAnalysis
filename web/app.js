import {
  allCatalogs,
  catalog,
  escape as e,
  hex,
  initialize,
  link,
  location,
  number,
  queryMatches,
  state,
  title,
} from "./data.js";
import {
  bindPager,
  functionView,
  header,
  metrics,
  pager,
  table,
  tag,
} from "./function.js";

const repo = "https://github.com/ASR-Tanyi/EOWAnalysis";
const glyphs = {
  overview: "M3 3h7v7H3z M14 3h7v7h-7z M3 14h7v7H3z M14 14h7v7h-7z",
  functions: "m8 6-5 6 5 6 m8-12 5 6-5 6 m-3-15-3 18",
  entries: "M5 20V4m0 0h13l-3 4 3 4H5",
  graph: "M4 5h5v4H4z M15 3h5v4h-5z M15 16h5v4h-5z M9 7h3v11h3 M12 5h3",
  rebuilds: "M3 5h7v14H3z M14 5h7v14h-7z M5 10h3 m8 3h3",
  module: "m3 7 9-4 9 4-9 4z m0 5 9 4 9-4 m-18 5 9 4 9-4",
};
const icon = (key) =>
  `<svg viewBox="0 0 24 24" aria-hidden="true"><path d="${glyphs[key]}"/></svg>`;
const routeNames = {
  overview: "Overview",
  functions: "Functions",
  entries: "Entry points",
  graph: "Call graph",
  rebuilds: "Rebuild comparisons",
};
const ready = initialize();
const main = document.querySelector("main"),
  finder = document.querySelector("#finder"),
  box = document.querySelector("#search-box");
function address(text) {
  const [module, num] = text.split("+");
  return { module, rva: Number(num) };
}
function endpoint(f, tab = "asm") {
  return link(f, tab);
}
function setup(m) {
  document.querySelector("#primary").innerHTML = Object.entries(routeNames)
    .map(([k, v]) => `<a href="#${k}" data-nav="${k}">${icon(k)}${v}</a>`)
    .join("");
  document.querySelector("#module-nav").innerHTML = m.modules
    .map(
      (mod) =>
        `<a class="module" data-module="${e(mod.name)}" href="#functions/${e(mod.name)}">${icon("module")}${e(mod.name)}<span class="count">${number(mod.functions)}</span></a>`,
    )
    .join("");
  const rev = document.querySelector("#revision");
  if (/^[0-9a-f]{40}$/.test(m.revision))
    rev.innerHTML = `<a href="${repo}/commit/${m.revision}">main · ${m.revision.slice(0, 8)}</a>`;
  else rev.textContent = "Local build";
}
function pathCard(m) {
  const points = m.baseline.entry_points;
  const nodes = [
    ["Loader entry", points.loader],
    ["nn::init::Start", points.sdk_start],
    ["nnMain", points.nnMain],
  ];
  return `<section class="startup"><div class="row"><div><p class="overline">Entry points</p><h2>Startup path</h2></div><a class="text-link" href="#entries">Inspect transfers →</a></div>
    <div class="path">${nodes.map(([n, v]) => `<a class="path-node" href="${link(address(v.address))}"><strong>${e(n)}</strong><small>${e(v.address)}</small></a>`).join('<span class="path-arrow" aria-hidden="true">→</span>')}</div></section>`;
}
function overview(host, m) {
  const exact = m.comparisons.filter((x) => x.exact).length;
  host.innerHTML =
    header(
      "Executable analysis",
      "Echoes of Wisdom",
      "Nintendo Switch · AArch64 · Program " + m.baseline.program_id,
    ) +
    metrics([
      [number(m.functions), "Indexed functions and stubs"],
      [
        number(m.baseline.reachable_from_nnMain_including_root_and_stubs),
        "Reachable from nnMain",
      ],
      [number(m.modules.length), "Executable modules"],
      [number(exact), "Exact individual rebuilds"],
    ]) +
    pathCard(m) +
    `<div class="split spaced"><section class="panel"><div class="panel-head"><h2>Modules</h2><a class="text-link" href="#functions">All functions →</a></div>${table(["Module", "Entries", "Import stubs"], m.modules.map((x) => `<tr><td><a class="mono" href="#functions/${x.name}">${x.name}</a></td><td>${number(x.functions)}</td><td>${number(m.baseline.modules[x.name].plt_stubs)}</td></tr>`).join(""))}</section>
    <section class="panel"><div class="panel-head"><h2>Rebuild comparisons</h2><a class="text-link" href="#rebuilds">View all →</a></div>${[
      m.comparisons[0],
      m.comparisons.find((x) => x.source === "tree.c"),
      m.comparisons.find((x) => x.source === "setters.c"),
    ]
      .filter(Boolean)
      .map(
        (x) =>
          `<a class="quick-link" href="${link(x, "rebuild")}"><span><strong>${e(x.source)}</strong><br><small class="rva">${e(x.module + "+" + hex(x.rva))}</small></span>${tag(x.exact ? "Exact" : number(x.different) + " byte differences", x.exact ? "ok" : "warn")}</a>`,
      )
      .join("")}</section></div>`;
}
function entries(host, m) {
  const b = m.baseline,
    edges = [...b.loader_to_sdk, ...b.sdk_to_nnMain];
  host.innerHTML =
    header(
      "Startup",
      "Entry points",
      "Follow the loader, the SDK initializer and the application entry in execution order.",
    ) +
    '<div class="spaced">' +
    pathCard(m) +
    '</div><div class="section-head"><h2>Startup transfers</h2></div><section class="panel">' +
    table(
      ["Caller / instruction", "Transfer", "Destination", "Resolved symbol"],
      edges
        .map(
          (x) =>
            `<tr><td><a class="mono" href="${link(address(x.source))}?at=${(state.modules.get(address(x.site).module).base + address(x.site).rva).toString(16)}">${e(x.site)}</a></td><td>${tag(x.kind)}</td><td><a class="mono" href="${link(address(x.target), "graph")}">${e(x.target)}</a></td><td class="wide-name">${e(x.symbol || "—")}</td></tr>`,
        )
        .join(""),
    ) +
    '</section><div class="section-head"><h2>Entry evidence</h2></div><div class="panel">' +
    table(
      ["Entry", "Function", "Extent", "Evidence"],
      Object.entries(b.entry_points)
        .map(
          ([k, x]) =>
            `<tr><td>${e(k)}</td><td><a class="mono" href="${link(address(x.address))}">${e(x.address)}</a></td><td>${number(x.size)} bytes</td><td>${tag(x.evidence)}</td></tr>`,
        )
        .join(""),
    ) +
    "</div>";
}
function comparisons(host, m) {
  const total = m.modules.reduce((n, x) => n + x.functions - x.errors, 0),
    errors = m.functions - total,
    exact = m.modules.reduce((n, x) => n + x.exact, 0);
  host.innerHTML =
    header(
      "AArch64 verification",
      "Rebuild comparisons",
      "Every entry has its compiler result and an instruction comparison. Selected functions also have independent optimization sweeps.",
    ) +
    metrics([
      [number(total), "Successful corpus rebuilds"],
      [number(errors), "Compiler diagnostics"],
      [number(exact), "Exact grouped rebuilds"],
      [
        number(m.comparisons.filter((x) => x.exact).length),
        "Exact individual rebuilds",
      ],
    ]) +
    '<div class="section-head"><h2>Individual builds</h2></div><div class="panel">' +
    table(
      [
        "Function",
        "C source",
        "Selected",
        "Original",
        "Rebuilt",
        "Different bytes",
        "Result",
      ],
      m.comparisons
        .map(
          (x) =>
            `<tr><td><a class="mono" href="${link(x, "rebuild")}">${e(x.module + "+" + hex(x.rva))}</a></td><td><a href="${link(x, "c")}">${e(x.source)}</a></td><td class="mono">-${e(x.profile)}</td><td>${number(x.original)}</td><td>${number(x.size)}</td><td>${number(x.different)}</td><td>${tag(x.exact ? "Exact" : "Different", x.exact ? "ok" : "warn")}</td></tr>`,
        )
        .join(""),
    ) +
    '</div><p class="note spaced">Exact requires equal lengths, identical bytes at the original guest address and zero pending fixups. Tail bytes count toward the difference. Individual builds use the pinned compiler and the same scoring as the command-line matcher.</p>';
}
async function functions(host, m, module) {
  const specific = m.modules.find((x) => x.name === module);
  host.innerHTML =
    header(
      "Function index",
      specific ? specific.name + " functions" : "Functions",
      specific
        ? "NSO build " + specific.build
        : "Browse by symbol, module-relative offset or guest address.",
    ) +
    `<div class="filters"><input data-query aria-label="Filter functions" type="search" placeholder="Search name or address" autocomplete="off"><select aria-label="Module" data-mod><option value="">All modules</option>${m.modules.map((x) => `<option ${x.name === module ? "selected" : ""}>${x.name}</option>`).join("")}</select>
    <label><input type="checkbox" data-reach> Reachable from nnMain</label></div><div class="panel" data-results><p class="loading">Loading function catalog…</p></div>`;
  host.querySelector("[data-mod]").onchange = (ev) =>
    (window.location.hash = "functions/" + ev.target.value);
  const rows = specific ? await catalog(module) : (await allCatalogs()).flat();
  if (!host.isConnected) return;
  const area = host.querySelector("[data-results]"),
    input = host.querySelector("[data-query]"),
    filter = host.querySelector("[data-reach]");
  let filtered = rows,
    timer;
  function draw(page = 0) {
    area.innerHTML =
      table(
        ["Function", "Module offset", "Size", "Boundary"],
        filtered
          .slice(page * 40, (page + 1) * 40)
          .map(
            (f) =>
              `<tr><td class="wide-name"><a href="${link(f)}">${e(title(f))}</a></td><td class="rva">${e(location(f.va))}</td><td>${number(f.size)} B</td><td>${tag(f.evidence)}</td></tr>`,
          )
          .join(""),
      ) +
      (filtered.length ? "" : '<p class="empty">No matching functions.</p>') +
      pager(filtered.length, page, 40);
    bindPager(area, page, draw);
  }
  function apply() {
    filtered = rows.filter(
      (f) => (!filter.checked || f.reachable) && queryMatches(f, input.value),
    );
    draw();
  }
  input.oninput = () => {
    clearTimeout(timer);
    timer = setTimeout(apply, 100);
  };
  filter.onchange = apply;
  draw();
}
async function navigate() {
  const host = document.createElement("section");
  main.replaceChildren(host);
  host.innerHTML = '<p class="loading" role="status">Loading analysis…</p>';
  try {
    const m = await ready;
    if (!host.isConnected) return;
    const [path, query = ""] = window.location.hash.slice(1).split("?"),
      parts = path.split("/");
    const active = parts[0] || "overview";
    let nav = active;
    if (active === "fn") nav = parts[3] === "graph" ? "graph" : "functions";
    document.querySelector("#crumb").textContent =
      "Workspace / " + (routeNames[nav] || "Function");
    document.querySelectorAll("[data-nav]").forEach((a) => {
      a.classList.toggle("active", a.dataset.nav === nav);
    });
    document
      .querySelectorAll("[data-module]")
      .forEach((a) =>
        a.classList.toggle("active", parts[1] === a.dataset.module),
      );
    document.body.classList.remove("nav-open");
    window.scrollTo(0, 0);
    document.title = (routeNames[active] || "Function") + " · ExeFS Explorer";
    if (active === "overview") overview(host, m);
    else if (active === "entries") entries(host, m);
    else if (active === "rebuilds") comparisons(host, m);
    else if (active === "functions") await functions(host, m, parts[1]);
    else if (active === "graph") {
      const entry = address(m.baseline.entry_points.nnMain.address);
      await functionView(
        host,
        entry.module,
        entry.rva,
        "graph",
        new URLSearchParams(),
      );
    } else if (active === "fn" && /^[\da-f]+$/i.test(parts[2] || ""))
      await functionView(
        host,
        parts[1],
        parseInt(parts[2], 16),
        parts[3],
        new URLSearchParams(query),
      );
    else throw Error("This page address is not in the explorer.");
  } catch (err) {
    host.innerHTML = `<div class="panel error"><h2>Analysis unavailable</h2><p>${e(err.message)}</p><a href="#overview">Open overview</a> · <button class="smallbtn">Retry</button></div>`;
    host.querySelector("button").onclick = () => locationReload();
  }
}
function locationReload() {
  window.location.reload();
}
let searchVersion = 0;
async function search() {
  const seq = ++searchVersion,
    area = document.querySelector("#search-results"),
    q = box.value.trim();
  if (!q) {
    area.innerHTML =
      '<p class="empty">Try nnMain, main+0xbde10 or a symbol name.</p>';
    return;
  }
  area.innerHTML = '<div class="loading">Searching modules…</div>';
  try {
    const groups = await allCatalogs();
    if (seq !== searchVersion) return;
    const hits = [];
    for (const fs of groups) {
      for (const f of fs) {
        if (queryMatches(f, q)) hits.push(f);
        if (hits.length === 30) break;
      }
      if (hits.length === 30) break;
    }
    area.innerHTML =
      hits
        .map(
          (f) =>
            `<a href="${link(f)}"><span>${e(title(f))}</span><span class="rva">${e(location(f.va))}</span></a>`,
        )
        .join("") || '<p class="empty">No matching functions.</p>';
  } catch (err) {
    area.textContent = err.message;
  }
}
document.querySelector("#open-search").onclick = () => {
  finder.showModal();
  box.focus();
  search();
};
box.oninput = search;
box.onkeydown = (ev) => {
  if (ev.key === "Enter") {
    const first = finder.querySelector("#search-results a");
    if (first) {
      finder.close();
      window.location.hash = first.hash;
    }
  }
};
finder.onclick = (ev) => {
  if (ev.target.closest("#search-results a")) finder.close();
};
document.addEventListener("keydown", (ev) => {
  if (
    ev.key === "/" &&
    !ev.ctrlKey &&
    !ev.metaKey &&
    !["INPUT", "TEXTAREA", "SELECT"].includes(ev.target.tagName)
  ) {
    ev.preventDefault();
    document.querySelector("#open-search").click();
  }
});
document.querySelector(".mobile-menu").onclick = () =>
  document.body.classList.toggle("nav-open");
document.querySelector(".skip").onclick = (ev) => {
  ev.preventDefault();
  main.focus();
};
window.addEventListener("hashchange", navigate);
ready.then(setup).catch(() => {});
navigate();
