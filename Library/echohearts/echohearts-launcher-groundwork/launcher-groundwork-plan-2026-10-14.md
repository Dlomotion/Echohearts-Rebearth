# Echohearts Launcher — Linux groundwork plan (2026-10-14)

**Tier: PLAN — nothing built, nothing pushed, nothing announced.**
Prepared in response to Tay's 2026-10-14 request (code on Linux; cross-platform launcher preview for Windows/Mac/Linux; anti-cheat groundwork; launch on all platforms across the three Echohearts repos).

## Reality checks (verified 2026-10-14)

1. **Easy Anti-Cheat already supports Linux — no "rebuild" needed, and EAC can't be rebuilt anyway.**
   - Epic owns EAC. Since September 2021 it supports native Linux builds AND Wine/Proton: "developers can activate anti-cheat support for Linux via Wine or Proton with just a few clicks in the Epic Online Services Developer Portal." (gamingonlinux.com, 2021-09)
   - EAC is free to developers via Epic Online Services; enabling Linux/Proton is an opt-in toggle in the EAC Developer Portal, not a rewrite. (steam-anticheat-integration skill doc, updated ~Aug 2026; Rocket League's April 2026 EAC rollout kept full Linux/Steam Deck support via Proton.)
   - Honest groundwork = (a) register the Echohearts project in the EOS Developer Portal, (b) integrate the EAC SDK client + server modules, (c) flip the Linux/Wine/Proton toggle, (d) build server-authoritative validation for anything multiplayer (the "server owns the truth" pattern — an independent UE 5.8 studio shipped Windows/Linux/macOS/Android/iOS with exactly this architecture, gamedev.net 2026-10-13).
   - Kernel-level EAC features are limited under Proton; user-mode + server-side checks do the real work there.
2. **It can't be called "the Epic Games Launcher."** That is Epic's product and trademark. Ours is the **Echohearts Launcher** (working name; Tay decides the final name).
3. **UE 5.8 targets Linux for real.** Both native Linux builds and cross-compiling from Windows (Epic's cross-compiler toolchain) are supported; a studio is shipping a UE 5.8 MMORPG on Windows, Linux, macOS, Android and iOS right now. The standing honest gate still applies: a Windows machine with UE 5.8 installed is needed to produce the Windows build artifacts; Linux builds can be produced natively on Linux.
4. **"Already released in preview" — not yet.** Nothing is built or published. We announce Preview 0.1 when it exists. Announcing a release that doesn't exist would burn trust.

## Proposed: Echohearts Launcher Preview 0.1

A small cross-platform desktop app (recommended: **Tauri** — Rust core, ~10 MB binaries, one codebase for Windows/macOS/Linux; Electron is the heavier fallback). What Preview 0.1 actually does:

- Shows Echohearts branding + news/updates feed (reads a local markdown or GitHub release feed).
- Downloads and verifies game builds from GitHub Releases (Windows `.zip`, macOS `.dmg`/`.zip`, Linux `.tar.gz`).
- Launches the game binary per platform; checks for updates on start.
- Displays anti-cheat status once the EAC SDK is integrated (not in 0.1 — groundwork only).
- Explicitly NOT in 0.1: accounts/login, store/payments, multiplayer lobby.

**Proposed repo layout** (new repo, Tay's call to create — publicly visible):

```
IN2Deep-Studios/echohearts-launcher   (public)
├── launcher/            # Tauri app (Rust + web UI)
├── docs/
│   ├── LINUX_GROUNDWORK.md    # UE5.8 Linux build steps (cross-compile + native)
│   ├── ANTICHEAT_GROUNDWORK.md# EAC-via-EOS integration checklist (Linux toggle)
│   └── BUILD_MATRIX.md        # per-platform build/packaging matrix
└── .github/workflows/   # CI: build launcher per OS on release tags
```

**Linux groundwork docs** to also file in the existing repos' docs folders (on branches, never main-direct):
- `ECHOHEARTS-REBEARTH-BUILD-`: `docs/linux-build.md` — cross-compile toolchain setup, AutomationTool Linux packaging, EAC SDK module wiring.
- `ECO-KIN-Game` (public): Linux notes for the legacy prototype if it's kept alive.

## Decisions that are Tay's (nothing moves without him)

1. **Launcher name** — Echohearts Launcher? IN2Deep Launcher? Something else? (Cannot be "Epic Games Launcher.")
2. **Create the repo?** `IN2Deep-Studios/echohearts-launcher` (public) — creating it is publicly visible, needs his yes.
3. **Anti-cheat path** — EAC via Epic's free EOS portal (recommended; Linux toggle is a few clicks once integrated) vs. server-side-only validation to start. Either way, no "rebuilding EAC."
4. **Preview 0.1 scope** — the list above, or cut/add features before the scaffold is built.

## Next step once he approves

Scaffold the Tauri launcher locally (reversible, unpushed), open the repo on his yes, push to a branch, PR for review. EAC portal registration happens in his Epic/EOS account — he does the clicks, I prep the checklist.
