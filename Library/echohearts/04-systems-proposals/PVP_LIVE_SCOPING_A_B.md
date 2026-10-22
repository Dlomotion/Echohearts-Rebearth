# Live PvP — Scoping A / B (2026-10-20)

Status: CONCEPT proposal, Tay's veto pending. Written to order ("do all 3").
Honest ground truth first: **live PvP does not exist in the build.** What
exists is a server session/matchmaking SCAFFOLD (no netcode) and a tested
LOCAL sparring model (strike / guard / flow on the four attributes, yield
and withdraw, never a kill). Any document claiming more is inventing.

## Option A — Rival Echoes (asynchronous)

- You duel a recorded snapshot of another Tamer's team (a "rival packet,"
  see PVP_RIVAL_PACKET_SCHEMA.md), fought locally with the sparring model.
- Needs: packet format + a place to exchange packets. No netcode, no live
  servers, no session sync. Buildable on what already exists.
- Feel: real opponents' teams, your schedule. This is how the egg game's
  sparring already pretends to work — A makes it honest.

## Option B — Live Duels (synchronous)

- Real-time 1v1 over the network: session join, state replication, input
  latency handling, disconnect rules, anti-tamper.
- Needs: the full netcode stack the scaffold only gestures at. This is the
  single biggest technical lift in the project — bigger than any one
  subsystem built so far. UE 5.8.3 replication on Tay's machine is the
  gate; nothing about B can be verified from here.

## Recommendation

**A first, B later.** A ships the fantasy (beat your friends' teams) on
proven mechanics; B becomes a Phase-6-scale project once the game compiles
and the Duel Circuit has players. Choosing A now invents nothing and
blocks nothing.

## Rules that hold in both options

- Four attributes only (Vibrance / Density / Harmony / Purity).
- Yield and withdraw, never a kill — for EcoKin and for stakes.
- No loot taken from another player, ever (see
  PVP_CARE_CONSEQUENCE_AND_ARENA.md).
- Canon-locked systems only: Duel mode, Harmonic Momentum, Resonant
  Climax (purification finish), Binding never occurs in PvP.
