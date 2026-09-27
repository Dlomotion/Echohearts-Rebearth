# Issue #8 — Online Tactical Battle Authority Core

**Status:** PARTIAL ENGINEERING IMPLEMENTATION / NOT YET VERIFIED AS UNREAL RUNTIME  
**Issue:** #8 — Implement console online turn-based Eco-Kin battle prototype

This change adds a small deterministic C++ authority core and executable verification harness for the highest-risk battle-state rules before Unreal integration.

## Implemented in this branch

- server-owned turn state;
- stable Eco-Kin IDs supplied as authoritative snapshots rather than Arena-owned progression copies;
- four command categories: Move, Ability, Partner Action, Tactical;
- command validation for match, player, turn, actor, sequence, action/category and target;
- deterministic integer damage resolution;
- one status effect: Static;
- one authored resonance interaction;
- monotonic result-event sequencing;
- reconnect snapshot;
- match completion;
- server-side reward finalization gate before return-to-hub eligibility.

## Local logic verification

The standalone verification harness was compiled with C++17, warnings-as-errors, and executed successfully before commit.

Covered assertions:
- wrong-side action rejected;
- valid command accepted;
- resonance modifier resolved server-side;
- stale/replayed command rejected;
- Static status persisted in authoritative state;
- reconnect returned the current authoritative snapshot;
- event IDs remained monotonic;
- match completed through server resolution;
- return-to-hub remained blocked until server reward finalization.

## What this does NOT verify

This repository still does not contain a complete Unreal Engine project/module required to claim the issue complete. Therefore the following issue gates remain **NOT YET VERIFIED**:

- Unreal Engine 5.8 packaged build launch;
- online session establishment;
- Unreal RPC/replication integration;
- consistent result replication across two runtime clients;
- controller-first UI navigation;
- real disconnect/reconnect through the Online Subsystem/session layer;
- battle-map to real-time-hub travel;
- latency measurements;
- accessibility pass in the actual tactical UI;
- proof that runtime progression/stat ownership is wired to the final authoritative project subsystem.

## Unreal integration contract

When the UE runtime module exists, wrap this rule layer behind server-only gameplay authority (for example GameMode/server subsystem), publish replicated snapshots/results through GameState/replicated components, and source Eco-Kin identity/progression from the established authoritative progression owner. Clients submit intents; clients must never author damage, initiative, victory, or rewards.

Do not close #8 from this change alone. The code is a tested authority-core increment, not packaged/runtime evidence.
