"""Exercise the assembled site over HTTP, including its actual WebAssembly decoder."""
from functools import partial
from http.server import SimpleHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
import sys
from threading import Thread

from playwright.sync_api import expect, sync_playwright


def check(url):
    with sync_playwright() as runner:
        browser = runner.chromium.launch()
        page = browser.new_page(viewport={"width": 1400, "height": 920})
        errors = []
        page.on("pageerror", lambda error: errors.append(str(error)))
        page.goto(url)
        expect(page.get_by_role("heading", name="Echoes of Wisdom", exact=True)).to_be_visible()
        page.get_by_role("link", name="Inspect transfers").click()
        expect(page.get_by_text("rtld+0x88", exact=True)).to_be_visible()
        page.keyboard.press("/")
        page.locator("#search-box").fill("main+0xbde10")
        hit = page.locator("#search-results a").first
        expect(hit).to_contain_text("main+0xbde10", timeout=45000)
        hit.click()
        expect(page.locator("pre.code")).to_contain_text("fcmp")
        page.get_by_role("link", name="C source", exact=True).click()
        expect(page.locator("pre.code")).to_contain_text("Cpu")
        page.locator("#source-kind").select_option("native")
        expect(page.locator("pre.code")).to_contain_text("struct SetterFields")
        page.get_by_role("link", name="Rebuild", exact=True).click()
        expect(page.get_by_text("Byte-exact", exact=True)).to_be_visible()
        expect(page.locator("table.diff")).to_contain_text("fcsel")
        page.locator("#compare-source").select_option("bulk")
        expect(page.get_by_text("Bytes differ", exact=True)).to_be_visible()
        page.wait_for_function(r"() => /^[a-f0-9]{8}\s+[a-z]/.test(document.querySelector('table.diff tbody td:nth-child(3)')?.textContent || '')")
        page.get_by_label("Changed words only").check()
        page.goto(url + "#graph")
        page.locator("[data-filter]").select_option("unknown")
        expect(page.locator("[data-edges]")).to_contain_text("call-register")
        expect(page.locator("[data-edges]")).to_contain_text("80")
        page.goto(url + "#fn/main/2362258/rebuild")
        expect(page.get_by_text("Independent LLD link:", exact=False)).to_be_visible()
        page.goto(url + "#functions/main")
        page.get_by_label("Filter functions").fill("nnMain")
        expect(page.locator("[data-results]")).to_contain_text("main+0x360b70")
        page.set_viewport_size({"width": 390, "height": 844})
        page.goto(url + "#overview")
        expect(page.get_by_role("heading", name="Echoes of Wisdom")).to_be_visible()
        assert page.evaluate("document.documentElement.scrollWidth <= innerWidth + 1")
        page.get_by_label("Toggle navigation").click()
        expect(page.locator("#primary")).to_be_in_viewport()
        assert not errors, errors
        browser.close()


if __name__ == "__main__":
    path = Path(sys.argv[1]).resolve()
    with ThreadingHTTPServer(("127.0.0.1", 0), partial(SimpleHTTPRequestHandler, directory=str(path))) as server:
        Thread(target=server.serve_forever, daemon=True).start()
        try:
            check(f"http://127.0.0.1:{server.server_port}/")
        finally:
            server.shutdown()
