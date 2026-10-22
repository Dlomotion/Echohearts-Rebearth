# Echohearts: Rebearth — Server Architecture (2026-10-17)

**Status:** ARCHITECTURE + SCAFFOLD. Honest label: **no netcode is implemented**. No sockets, no replication, no dedicated-server handshake exist in the codebase. `USessionSubsystem` (`Source/Echohearts/Public|Private/Server/`) defines the session lifecycle and matchmaking shape against a local registry; everything resolves locally today (solo Tamer + AI allies). When netcode arrives, it plugs into this interface.

## Server types
- **Sanctuary servers (co-op PvE, the default home).** Tamers restore the world together. Duels happen only by mutual consent (Sparring). Raids form freely.
- **Contested servers (consensual competitive).** Duel ladders run here. Every duel still requires both Tamers' agreement — nothing forced, ever. A Tamer's bonds travel with them across servers; no one is ever locked out of their partners.

## Regional shards
Shards are named for regions (Ashfall, Mist Coasts, Rift Plateaus…). They keep latency low and let regions feel lived-in: the Tamers restoring a region tend to share its shard. Cross-shard visiting is allowed; home-shard restoration progress is what counts.

## Matchmaking flow
1. Tamer issues a `FMatchmakingRequest`: battle mode (Duel/Raid/Sparring), preferred server type, preferred shard, trust band (Kindling-aware: sparring matches novices with novices, veterans with veterans).
2. The shard directory returns open sessions matching mode + type + shard + capacity.
3. Join is gated by the **anti-cheat session-attestation module** (`Source/Echohearts/Public/AntiCheat/AntiCheatTypes.h`): the client proves a clean session before the server accepts the Tamer. A failed attestation refuses the join — never a ban on first failure, always a re-check.
4. On accept, the Tamer's deployed partner, Kindling state, and corruption state replicate down from the server's authoritative copy.

## Server-authoritative combat (target design)
- The server owns: strike resolution, strain accounting, momentum, essence chains, boss phases, raid hazard zones.
- The client owns: input, camera, prediction of its own movement. Ability activations are requests; the server validates strain affordability and pulse timing before confirming.
- Desync policy: the server's bond state wins. If a client's predicted momentum diverges, it snaps to the server value with a UI shimmer — never a silent correction.

## What UE provides vs what must be built
- **UE provides:** replication framework (Actors, RPCs), dedicated-server builds, Online Subsystem session interfaces, EOS/Steam backends, server travel, network profiling.
- **Must be built:** the authoritative combat sim (strike validation, momentum/chain server logic), the shard directory service, attestation-gated join flow, anti-cheat server-side verdicts, lag-compensated pulse windows for Harmonic Momentum, raid instancing for Cataclysm-class targets, cross-shard visit handoff, and all backend infrastructure accounts.

## What exists today
`USessionSubsystem`: CreateSession / FindSession / JoinSession / LeaveSession against an in-memory registry. The request/response shapes (`FServerSession`, `FMatchmakingRequest`) are the contract the future netcode will implement. Everything else on this page is architecture waiting for its build.
