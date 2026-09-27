# ECHOHEARTS: REBEARTH — CHRONO REWIND TECHNICAL CONTRACT

**Date:** 2026-09-26  
**Status:** TECHNICAL CONTRACT / NOT YET VERIFIED  
**Engine target:** Unreal Engine 5.8  
**Depends on:** canonical `.uproject` + `Source/` foundation, PR #14 infrastructure validation, Issue #10 first real runtime slice

## 1. Scope

This contract defines the smallest safe implementation path for localized Chrono rewind and Chrono-Echo encounter support.

It does **not** claim that whole-world time travel, 125 simultaneous Eco-Kin snapshotting, persistent global voxel rewind, MassEntity-scale rollback, or multiplayer temporal authority are already implemented.

## 2. Core rule

Only actors explicitly tagged/registered as `Chrono.RewindEligible` record temporal state.

The 125-ID Permanent Dex is a species/identity registry; it is **not** a requirement to keep all 125 creatures in memory or record all of them every 100 ms.

## 3. Recommended runtime structure

### `FChronoSnapshot`

Capture only authored rewindable state:

- server frame/timestamp;
- world transform;
- linear/angular velocity where relevant;
- movement mode;
- health/energy values actually sourced from authoritative components;
- whitelisted status-effect tags + remaining duration;
- whitelisted cooldown markers;
- animation/montage state only when deterministic restoration is explicitly supported;
- temporary destructible-object state where authored.

Do not capture permanent inventory/economy/progression state inside this struct.

### `UChronoRewindComponent`

Responsibilities:

- fixed-size preallocated snapshot ring;
- configurable capture rate;
- explicit capture policy;
- server authority for shared gameplay;
- rewind start/stop validation;
- physics/movement pause and restoration;
- deterministic cursor playback;
- final authoritative correction/replication;
- telemetry for cost and failure reason.

### Buffer strategy

Prefer a preallocated `TArray<FChronoSnapshot>` plus integer head/count/cursor over allocation-heavy linked-list storage.

Example budget for a single active hero actor:

- 10 s window;
- 10 samples/s;
- 100 fixed snapshots.

Actual snapshot size and actor count must be profiled before expanding the window.

## 4. Persistence boundary

Chrono rewind must never roll back server-ledger transactions such as:

- item acquisition/consumption;
- currency;
- crafting commits;
- trades;
- quest rewards;
- permanent world restoration;
- Kindling history;
- Dex/Form registration;
- account progression;
- save-slot commits.

A rewind can restore temporary combat state without reversing an already-committed economy transaction.

## 5. Multiplayer authority

For networked play:

1. client requests rewind;
2. server validates ability, state, cooldown, encounter rules, and target eligibility;
3. server controls authoritative rewind cursor/result;
4. clients receive replicated/predicted presentation;
5. server commits final authoritative transform/gameplay state;
6. any non-rewindable transactions remain untouched.

Never trust a client-submitted position/history buffer as the authoritative past.

## 6. Physics / movement restoration

If simulation is disabled during rewind, it must be restored explicitly.

Record and restore as required:

- movement mode;
- velocity;
- gravity/physics state;
- collision enablement;
- attachment/base relationships;
- movement-component state;
- ragdoll/physical-animation mode if supported.

`DisableComponentsSimulatePhysics()` without symmetric restoration is not acceptable.

## 7. Actor lifecycle

Version 1 should support only actors that remain alive/existing for the rewind window.

Spawn/despawn resurrection requires a later authored transaction model with stable Actor/Entity IDs and must not be approximated by raw pointers.

## 8. Destruction interaction

Chrono rewind should initially support **bounded authored destructibles**, not planet-scale arbitrary terrain history.

Recommended V1:

- doors;
- bridge panels;
- arena cover;
- puzzle stones;
- selected Chaos Geometry clusters;
- small authored terrain-state volumes.

World-scale voxel reconstruction enters R&D only after persistence, replication, and performance contracts are proven.

## 9. MassEntity relationship

MassEntity is optional for high-density background simulation.

Do not force hero Eco-Kin or bosses into Mass solely because Mass exists.

If Chrono applies to Mass entities later, use a fragment/processor design with strict spatial and temporal budgets rather than copying Actor rewind code directly.

## 10. Chrono-Echo level implementation

Prefer World Partition/Data Layers or authored sub-level/data-layer states for major historical presentations.

A Chrono mission can stream:

- present layer;
- historical layer;
- anomaly overlay;
- restored state.

Do not keep every full era loaded simultaneously merely to avoid loading screens.

Streaming strategy must be platform/profile-driven.

## 11. Corrected code-review findings from legacy snippet

The old `UERTimeRewindComponent` is not production-ready because:

- health is incorrectly filled from `Velocity.Size()`;
- energy is uninitialized;
- linked list is misidentified as a circular buffer;
- rewind speed depends on render frame rate;
- physics is disabled and not restored;
- no authoritative transaction boundary exists;
- collision/movement mode/status/cooldown state is missing;
- no network reconciliation exists;
- no inventory anti-duplication rules exist;
- no capacity/memory budget exists;
- no automated or packaged runtime evidence exists.

Disposition: **REFERENCE / REWRITE**.

## 12. UI contract

A.E.G.I.S. Chrono Archive should expose:

- local anomaly stability;
- active Chronicle objective;
- causal class (C1–C4);
- rewind charge/cooldown when relevant;
- warnings for non-rewindable actions;
- clear accessibility-safe temporal distortion cues.

Do not hide critical information exclusively in screen distortion/color.

## 13. Accessibility

Temporal effects must support:

- reduced-motion mode;
- reduced flash intensity;
- non-color-only past/present distinction;
- subtitle/caption support for Time-Echo voices;
- configurable camera shake;
- readable rewind direction indicator;
- input remapping.

## 14. Validation ladder

### T0 — Compile contract
- UHT success;
- Development Editor compile;
- no generated-header/include errors.

### T1 — Local actor rewind
- one actor;
- transform + velocity;
- health/energy;
- 5–10 second bounded ring;
- deterministic playback independent of render FPS.

### T2 — Gameplay state
- whitelisted statuses/cooldowns;
- authored destructible;
- no inventory rollback.

### T3 — Packaged build
- Development package launch;
- controller + keyboard/mouse;
- save/reload around Chrono encounter.

### T4 — Network
- dedicated/listen setup as applicable;
- server-authoritative rewind;
- simulated latency/loss;
- disconnect/reconnect boundary;
- duplication/exploit checks.

### T5 — Performance
- Unreal Insights trace;
- snapshot memory budget;
- CPU cost per active rewind actor;
- stress actor count;
- platform targets.

Only after these gates may localized Chrono rewind be labeled **VERIFIED**.

## 15. Repository connection

- PR #14 / Issue #13: infrastructure and real UE foundation prerequisite.
- Issue #10: first original NPC + Eco-Kin runtime body/animation proof; Chrono should not delay it.
- PR #7/#9 / Issue #8: tactical-online work remains later and bounded.
- PR #15: canon and production consolidation containing this contract.

Chrono is an expansion of the real-time core, not a substitute for finishing the core.
