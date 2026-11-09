# EchoHearts Servers

Both servers for EchoHearts Rebirth — original code, Terraria-style dedicated-server idea: one host runs the world, everyone else joins it.

## 1. Multiplayer game server (`multiplayer/`)

C++17, no dependencies. One authoritative world for up to **8 players**: shared day/night cycle, server-owned monsters, mischievous imps, score, and the Heartbreaker boss (awaken message, enrage, Rebirth on defeat).

```bash
cd multiplayer
g++ -std=c++17 -pthread src/server.cpp -o echohearts-server   # or: cmake -B build && cmake --build build
./echohearts-server            # port 7777
./echohearts-server 7778       # or any port
```

On Windows: open the folder in Visual Studio (CMake) or compile with MSVC — Winsock support is built in.

Test it:
```bash
python3 multiplayer/tests/test_client.py 127.0.0.1 7777 YourName
```

Protocol (join, move, hit enemies, chat, summon the boss): see [`multiplayer/PROTOCOL.md`](multiplayer/PROTOCOL.md).

## 2. Web server (`web/`)

Python, no dependencies (standard library only). Hosts the playable game for anyone with a browser, and tells clients where the multiplayer server is.

```bash
python3 web/server.py                 # http://127.0.0.1:8080
python3 web/server.py 8080 /path/to/games-root
```

- `/` — the single-file playable Terraria-style game
- `/2d/` — the 2D web game
- `/health` — `{"ok": true}`
- `/api/status` — JSON with uptime, game links, and the multiplayer join address (set `ECHOHEARTS_MP_HOST` / `ECHOHEARTS_MP_PORT` when the multiplayer server runs elsewhere)

## Run both together

```bash
# Linux / macOS / Git Bash
./start-servers.sh
# Windows
start-servers.bat
# Or with Docker
docker compose up --build
```

Then: play in a browser at `http://127.0.0.1:8080/`, and join the world with a game client at `<host>:7777`.
To let friends join from the internet, forward ports **8080** (web) and **7777** (multiplayer) on your router, or run both on a VPS / cloud VM and open those ports in its firewall.
