# EchoHearts Rebirth — Unreal Engine 5.8 Edition

> **⚠️ SUPERSEDED PROTOTYPE — kept for reference only.**
> This chat-built UE project (module `EchoHeartsRebirth`) is **not** the authoritative Echohearts UE project. Development moved to the BUILD repository — **`IN2Deep-Studios/ECHOHEARTS-REBEARTH-BUILD-`** (module `Echohearts`, `EchoheartsRebearth.uproject`) — which owns the executable UE 5.8 build, the companion/Dex/entity systems, and all runtime evidence per `FOUNDATION_STATUS.md` there. Do not build new work on this folder; see assignment EH-CANON-002 in `11_Daily_Assignments/CANON_GAME_AND_ART_FILING_ASSIGNMENT_2026-11-09.md`. (Marked superseded by owner decision, 2026-11-09.)

The UE5 (C++) edition of EchoHearts Rebirth, updated for **Unreal Engine 5.8** (the last planned UE5 release, out June 2026). Original code — Terraria-style generic rules, no Terraria or Epic sample code, art, or text copied.

Collect echo hearts, defeat mischievous imps and void monsters, survive the day/night cycle, and take down the Heartbreaker boss.

## Open it

**Requirements:** Unreal Engine **5.8** (Epic Games Launcher) and the latest Visual Studio with the **Game development with C++** workload. Migration guides for 5.8 note the preferred MSVC toolchain is the newer v145 (Visual Studio 2026 generation) — VS 2022's v143 may warn that it is not the preferred version.

**Upgrading from the 5.4 version?** See [`UPGRADE-5.8.md`](UPGRADE-5.8.md) — in short: delete `Binaries/`, `Intermediate/`, `Saved/` and `.vs/`, regenerate project files, rebuild. Keep the 5.4 engine installed until the 5.8 build is confirmed.

1. Right-click `EchoHeartsRebirth.uproject` → **Generate Visual Studio project files** (or just double-click it and let Unreal prompt you to build).
2. Open `EchoHeartsRebirth.sln` in Visual Studio, build **Development Editor | Win64**, then launch the editor.
   - GitHub Copilot works in Visual Studio as usual once you're signed in there.
3. In the editor, follow [`Content/README.md`](Content/README.md) to make the `L_EchoHearts` level and the thin Blueprint wrappers (meshes) — about 10 minutes, all logic is already C++.
4. Press Play: WASD + mouse, Space to jump, Click/F for Echo Pulse, R for Echo Burst.

> Note: UE projects are normally pushed as source and built on your machine — binary assets (`.uasset`, Binaries/, Intermediate/) are git-ignored on purpose, which is the standard Unreal + Git setup.

## What's in the C++

| File | What it does |
|---|---|
| `EchoHeartsStats.h` | The shared rulebook: HP/mana, weapon stats, enemy stats, drops, defence/crit math |
| `EchoHeartsCharacter` | Player — 100 HP / 100 mana, i-frames, HP/mana regen rules, Echo Pulse & Burst, pickups |
| `EchoHeartsProjectile` | Pulses/Bursts/void orbs — 10% crits, knockback data |
| `EchoHeartsEnemy` | Imp (20 HP, mischievous darting) & Monster (60 HP, chaser) — chase AI in Tick, contact damage, drops |
| `EchoHeartsBoss` | Heartbreaker — 600+ HP, awaken message, void orbs, imp minions, enrages <25% HP, Rebirth on defeat (+20 Max HP) |
| `EchoHeartsPickup` | Heart (heals) & Star (mana) drops: 25% / 20% drop chances |
| `EchoHeartsGameMode` | Day/night cycle (night = faster, stronger spawns), waves, level from hearts, boss every 3 levels, Best score |

## Terraria-style rules (same as the other editions)

100 HP (each HUD heart = 20) · 100 mana, faster regen standing still · contact damage minus defence, then ~0.66s invincibility frames · weapons have damage / knockback / use-time / 10% crit (double) · enemies have defence + knockback resistance · heart drops heal 20, star drops restore 50 mana · night spawns more and stronger monsters · boss awaken message + HP bar + enrage · death = “You were slain…”, Best score kept.

## Other editions in this repo

- `echohearts-rebirth-game/` — 2D web (HTML/CSS/JS)
- `echohearts-playable/` — single-file playable Terraria-style game
- `echohearts-rebirth-3d/` — 3D C++ (raylib)
- `echohearts-servers/` — C++ multiplayer dedicated server + Python web server

## License

MIT.
