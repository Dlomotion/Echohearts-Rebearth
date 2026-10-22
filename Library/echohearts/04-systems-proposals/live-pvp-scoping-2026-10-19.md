# Live PvP — Honest Scoping (2026-10-19)

**Status:** CONCEPT + scoping audit. Not canon. Routes to 04_Systems (duel design) and 09_Technical (netcode reality). Nothing here changes the duel circuit's existing design; this doc decides what "live" actually costs.

**Source:** Tay's ad-copy image ("dominate live PvP" — `workspace/user/files/7153_76_2ds4.jpg`, uploaded 2026-10-19 night). The ad promises it; this doc prices it honestly. Per Tay's standing posture: no basic code, no cliches, and the truth tiered plainly.

## Where PvP stands today

- **Duel circuit:** designed (CONCEPT + code, uncompiled) as the PvP seed — consenting Tamers, structured bouts, part of the base-building/duel/raids package.
- **Netcode:** scaffold-only. `server-architecture-2026-10-17.md` lays the path; the server-authoritative session-attestation module exists as headers, never compiled. Real live PvP needs server-authoritative state — this is the single biggest engineering lift in the whole project, bigger than any system or art batch.

## The three honest options

### Option A — Async / rival duels first (recommended for launch scope)
Battle-code duels: Tamers record a team + strategy, rivals fight the recording asynchronously, ladder ranks resolve on results. Everything runs on existing duel-circuit logic; no live netcode required. Kindling-vs-Kindling, Anima-Link strain fully simulated. This ships, it's fun, and it's honest — no "live" label on something that isn't.

### Option B — Local live duels (LAN / same-room)
Two clients, one authoritative host (the challenger's machine hosts, the guest's inputs are validated). Real-time, but the trust boundary is a handshake between people who know each other — no dedicated servers, no anti-cheat war. Feasible inside the current scaffold with the session-attestation module promoted from headers to compiled code.

### Option C — True live PvP (server-authoritative, ranked ladders)
Dedicated servers, tick-synced combat, anti-cheat attestation on every session, rollback or lockstep, region hosting costs. This is a studio-scale commitment — months of netcode, ongoing server bills, and a live-ops burden. It is *not* a launch feature for a team this size; it is a phase-2 expansion funded by a shipped game.

## Canon constraints on any PvP

- **Consent only.** Both Tamers agree; no ambush PvP, no griefing vectors. Wild encounters are for the wild.
- **Partners are never harmed by design.** Defeat in a duel costs strain and pride, never a companion's wellbeing — Care Consequence applies: a Tamer who duels recklessly and burns their partner's strain answers for it in the Kindling trust economy.
- **No sacrifice mechanics, ever.** Duels never consume, fuse, or destroy a partner. The Palworld paste's condenser was declined on exactly this ground; PvP doesn't reopen it.
- **Shadow stays out.** PvP cannot inflict the Shadow condition on another Tamer's partner — Shadow comes from forced domination, DNA over-tampering, environmental collapse, weaponization. A duel is none of those.

## Recommendation

Ship **A at launch** (async rival ladder on the duel circuit), prototype **B** during the base-building beta (it exercises the attestation module for free), and keep **C** as a named, costed phase-2 — scoped early, in writing, so it never gets bolted on late and broken. If live PvP matters for launch marketing, say "live local duels" and mean it.

## Open calls (Tay's)

1. Launch scope: A-only, or A+B?
2. Ranked ladders: seasonal (Aniimo runs 84-day seasons / 42-day halves) or persistent?
3. Spectating: is watching duels part of the social loop (Tavern screens, championship TV animations exist as CONCEPT)?
