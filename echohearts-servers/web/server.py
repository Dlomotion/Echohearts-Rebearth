#!/usr/bin/env python3
"""EchoHearts web server — hosts the playable games, no dependencies (Python stdlib only).

Serves:
  /                     -> echohearts-playable/index.html (the single-file playable game)
  /2d/                  -> echohearts-rebirth-game/ (2D web game source version)
  /health               -> {"ok": true}
  /api/status           -> JSON: web server uptime + how to join the multiplayer server

Run:
  python3 server.py [port] [site-root]
  port defaults to 8080. site-root defaults to the repo staging layout where
  echohearts-playable/ and echohearts-rebirth-game/ sit next to this project,
  or a folder containing index.html directly.
"""
import json, os, sys, time
from http.server import SimpleHTTPRequestHandler, ThreadingHTTPServer

START = time.time()
MULTIPLAYER_HOST = os.environ.get("ECHOHEARTS_MP_HOST", "127.0.0.1")
MULTIPLAYER_PORT = int(os.environ.get("ECHOHEARTS_MP_PORT", "7777"))

def find_root(given: str | None) -> str:
    if given:
        return os.path.abspath(given)
    here = os.path.dirname(os.path.abspath(__file__))
    # Layouts: (a) inside echohearts-servers/web in a repo/staging tree with siblings,
    #          (b) next to the game folders, (c) serving this folder itself.
    candidates = [
        os.path.join(here, "..", ".."),          # staging/repo root (siblings are game folders)
        os.path.join(here, ".."),
        here,
    ]
    for c in candidates:
        c = os.path.abspath(c)
        if os.path.exists(os.path.join(c, "echohearts-playable", "index.html")):
            return c
    return os.path.abspath(candidates[0])

ROOT = find_root(sys.argv[2] if len(sys.argv) > 2 else None)

class Handler(SimpleHTTPRequestHandler):
    def __init__(self, *a, **kw):
        super().__init__(*a, directory=ROOT, **kw)

    def _json(self, obj, code=200):
        body = json.dumps(obj).encode()
        self.send_response(code)
        self.send_header("Content-Type", "application/json")
        self.send_header("Content-Length", str(len(body)))
        self.end_headers()
        self.wfile.write(body)

    def do_GET(self):
        if self.path == "/health":
            return self._json({"ok": True, "service": "echohearts-web"})
        if self.path == "/api/status":
            return self._json({
                "ok": True,
                "service": "echohearts-web",
                "uptimeSeconds": round(time.time() - START, 1),
                "games": {"playable": "/", "2d": "/echohearts-rebirth-game/", "3d": "C++ download — see the GitHub repo, folder echohearts-rebirth-3d/"},
                "multiplayer": {"host": MULTIPLAYER_HOST, "port": MULTIPLAYER_PORT, "maxPlayers": 8,
                                "join": f"Connect a game client to {MULTIPLAYER_HOST}:{MULTIPLAYER_PORT} (see multiplayer/PROTOCOL.md)"},
            })
        if self.path == "/":
            self.path = "/echohearts-playable/index.html"
        elif self.path == "/2d/" or self.path == "/2d":
            self.path = "/echohearts-rebirth-game/index.html"
        return super().do_GET()

    def log_message(self, fmt, *args):
        sys.stderr.write("[web] %s - %s\n" % (self.address_string(), fmt % args))

if __name__ == "__main__":
    port = int(sys.argv[1]) if len(sys.argv) > 1 else 8080
    print(f"EchoHearts web server on http://127.0.0.1:{port}  serving {ROOT}")
    print(f"  Play: http://127.0.0.1:{port}/   Status: http://127.0.0.1:{port}/api/status")
    ThreadingHTTPServer(("0.0.0.0", port), Handler).serve_forever()
