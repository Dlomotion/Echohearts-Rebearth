# ECHOHEARTS: REBEARTH — SECTIONS XXVII–XXXI NETWORK / REGISTRY / SAVE / UI AUDIT

**Date:** 2026-09-27  
**Status:** TECHNICAL RECONCILIATION / NOT YET VERIFIED  
**Engine target:** Unreal Engine 5.8  
**Authority:** `MASTER_PROJECT_INDEX.md` → canon locks → current PR/issue validation chain  

## 1. Scope and evidence boundary

This audit covers the pasted Sections XXVII–XXXI material for:

- raid replication;
- Eco-Kin registry/DataTable shape;
- UMG/MVVM companion panels;
- persistent save data;
- claims that the architecture is compiled, production-ready or fully synchronized.

The useful intentions are preserved. The pasted code and prose do **not** prove UE5.8 compilation, multiplayer correctness, persistence safety, MVVM performance, packaged runtime behavior or production readiness.

No material in this packet may be labeled VERIFIED until the repository contains direct build/test/runtime evidence.

## 2. Raid replication — corrected authority model

The proposed `AERRaidNetworkController` captures the correct high-level principle — client request → server authority → synchronized presentation — but the sample is not safe or complete.

### Concrete code defects / risks

1. `DORP_LIFETIME_CONDITION` is a typo. The Unreal replication macro is `DOREPLIFETIME_CONDITION`.
2. A `PlayerController` is the wrong place to broadcast persistent world deformation to every participant. PlayerController ownership/relevancy is connection-oriented; a NetMulticast only executes on clients for which the actor is relevant.
3. The client payload supplies `ImpactTargetLocation` and `RawStructuralDamage`. The server must not trust client-selected persistent damage, radius, victims or world cells.
4. `RawStructuralDamage <= 10000` is not meaningful anti-cheat validation by itself. An attacker can still submit valid-range fraudulent values.
5. `AssociatedNetworkID` is not a sufficiently defined persistent identity or anti-replay token.
6. A reliable multicast for every deformation event can create queue pressure during rapid destruction. Persistent world truth should come from authoritative replicated state/deltas; transient VFX may use bounded RPCs.
7. The sample has no distance/LOS checks, ability-state checks, cooldown, team/faction policy, protected-volume test, destruction budget, sequence validation, replay protection or persistence transaction.
8. `bIsActiveRaidEnforced` has no shown state machine or OnRep behavior.
9. Nothing in the sample updates navigation, saves world deltas, reconciles late joiners, restores after reconnect, or proves deterministic deformation.

### Required network contract

Use a server-owned world/raid state actor or replicated component that is relevant to all raid participants.

A client should request an **ability action**, not submit authoritative damage. Minimum request data:

- stable source actor/entity ID;
- stable AbilityID;
- client input sequence number;
- optional target hint/aim sample;
- client timestamp only for reconciliation, never as authority.

The server then derives:

- legal origin/range;
- hit results;
- damage profile;
- allowed deformation profile;
- protected/no-destroy masks;
- world-delta transaction ID;
- cooldown/resource consumption;
- reward eligibility.

Persistent deformation should be represented by authoritative, versioned deltas that late joiners and reconnecting clients can replay. Cosmetic debris, camera shake and Niagara/audio can be separate transient presentation events.

## 3. Recommended raid-world data path

Working contract:

`Client Input → Server Ability Validation → Server Hit/Deformation Resolve → Persistent World Delta Commit → Replicated Delta State → Client Presentation`

Each persistent delta should carry at minimum:

- `WorldDeltaID` / transaction GUID;
- region/chunk identifier;
- deformation profile ID;
- bounded shape/origin;
- source ability/encounter ID;
- revision number;
- save-commit state;
- restore/rollback policy.

Never use Chrono rewind to reverse an already committed reward, trade, currency or durable world-state transaction.

## 4. Master registry — preserve identity authority, do not fabricate IDs

The proposed `FEREcoKinDatabaseRow` is a reasonable starting shape for data-driven runtime records, but the sample CSV cannot become authoritative roster data by itself.

### Required corrections

- `PermanentDexID` must map to the existing 125-ID production authority and must never be silently invented by a chat sample.
- `ReferenceName` should not be the only runtime key. Use a stable namespaced identity such as an authored `EcoKinID` / Primary Asset identity and keep display names localizable.
- `CoreDropTag` should become a non-sentient **RewardProfileTag / EcologyRewardProfileTag**. Living Eco-Kin are not body-part loot containers by default.
- `DropProbabilityRate` must be validated/clamped and resolved through an authored reward table, not trusted from arbitrary runtime mutation.
- Add release/availability metadata so a permanent identity can be `RegistryLocked`, `InProduction`, `LaunchAvailable`, `SeasonalAvailable`, etc. without changing identity.
- Forms such as Shimmer/Aurivelle/corrupted/purified states must reference a parent identity rather than consuming a new permanent ID unless governance explicitly approves a new species.

### Sample-row disposition

The pasted rows assigning IDs 6–10 to `Floauwer`, `Galactorra`, `Kendo`, `Pigcasso`, and `Hexxin` are **REFERENCE-ONLY** unless the authoritative game-data dictionary independently confirms those exact ID mappings.

`Hexxin — Aurivelle Form` remains a parent/form mapping candidate under the current naming lock. It does not create a new ID, and the retired Prismana/Prusmana labels must not return.

## 5. Seasonal Eco-Kin rule

The user’s latest production rule is reaffirmed:

**Eco-Kin are introduced and completed over future development sessions, seasons, story chapters, events and expansions.**

The current 125-ID Permanent Dex remains the identity authority until a deliberate versioned roster expansion is approved. A season changes release availability, not identity authority by itself.

Do not fill missing rows with placeholder stats, loot, abilities or art merely to make the table look complete.

## 6. MVVM / UMG correction

The architectural direction — separate gameplay state from UI presentation and push updates through ViewModels — is valid.

However:

- UE5.8 UMG Viewmodel/MVVM uses FieldNotify/event-driven updates; it is not automatically an asynchronous worker-thread UI system.
- A FieldNotify update can still cause widget/layout/render work on the game/UI thread.
- “No text blocks re-rendering” is not a valid blanket guarantee.
- A live 3D Eco-Kin viewport can be expensive and requires explicit render-target/update-rate/visibility budgets.
- D.A.H.L.I.A. logs should be fed from bounded event/state data rather than per-frame polling.
- Large roster lists should use virtualized list/tile views and incremental updates.

### UI data contract

Recommended ViewModels:

- `VM_ActiveEcoKin` — identity, V/D/H/P, conditions, Kindling state, active techniques;
- `VM_SanctuaryOps` — voluntary Partner Assist status, queues, care alerts and resource summaries;
- `VM_ChronoArchive` — anomaly stability, causal class, objectives and safe rewind warnings;
- `VM_RaidState` — boss phase, restoration objective, network/persistence warning state.

Accessibility remains mandatory: scalable text, input remapping, non-color-only warnings, reduced motion/flash, captions, readable focus/navigation.

## 7. Save-system audit

The proposed `UERSaveGameSystem` is a useful schema sketch, not a production save architecture.

### Compile/API correction

For UE5.8 native C++, `UGameplayStatics::AsyncSaveGameToSlot` takes a completion delegate. The pasted three-argument call is incomplete for the documented native API and must not be called compiled/verified.

The save path must handle success/failure explicitly.

### Schema corrections

Replace ownership-oriented naming:

- `TamedRosterStorage` → `BondedRosterState` or equivalent current-canon term;
- `MutationResonanceTags` → `FormStateTags` / authored growth-state tags where appropriate.

Add at minimum:

- save schema version;
- content/canon data version;
- player/platform profile identifier where appropriate;
- world seed/world-state revision;
- stable EcoKinID rather than name-only identity;
- current form/state identity;
- Kindling relationship state needed for gameplay;
- Sanctuary assignments/availability by stable IDs;
- transaction/revision metadata for persistent world deltas.

### World-delta storage

Do not assume the entire destructible world can safely live in one ever-growing `TArray<FERVoxelDeltaData>` inside one slot.

Use bounded/chunked/versioned world-delta records with compaction/checkpoint strategy. Profile serialization time, memory, disk size and migration cost before scaling arbitrary terrain persistence.

Save/load must not race blindly. Some target platforms may not support simultaneous load/save operations safely, so the project needs an explicit save-state queue/guard.

## 8. V/D/H/P and gameplay-data separation

Vibrance, Density, Harmony and Purity remain the public Eco-Kin stat language.

Do not confuse:

- species baseline data;
- per-instance current state;
- temporary combat modifiers;
- regional ecology modifiers;
- corrupted/purified form modifiers;
- permanent Growth Rite unlocks.

A save file should persist only the per-instance/per-world state required to reconstruct runtime state; the canonical species definition should remain data-driven and versioned outside the save.

## 9. Production-claim correction

Retire statements such as:

- “all 30 components are compiled and verified”;
- “the framework is fully completed”;
- “Patch 1.0 is successfully implemented”;
- “all directories are synced on main”;
- “the complete system engine specification is compiled and ready for development.”

Correct status:

**DESIGN/TECHNICAL SPECIFICATION + PARTIAL REPOSITORY PROTOTYPES — IMPLEMENTATION AND RUNTIME VERIFICATION PENDING.**

## 10. Validation ladder

### T0 — Repository foundation
- canonical `.uproject`;
- valid UE5.8 `Source/` module;
- fresh clone + Git LFS evidence;
- Development Editor compile.

### T1 — Registry/UI
- one authoritative Eco-Kin row loaded by stable ID;
- one ViewModel with FieldNotify update evidence;
- no per-frame polling for static roster fields;
- packaged UI smoke test.

### T2 — Save
- create/load slot;
- schema/version field;
- async completion success/failure handling;
- one bonded Eco-Kin state round-trip;
- one bounded world delta round-trip;
- corruption/partial-write recovery plan.

### T3 — Raid authority
- client request with server-derived damage;
- protected-area rejection;
- authoritative boss/world state;
- late-join/reconnect state synchronization;
- duplicate/replay request rejection.

### T4 — Destruction persistence
- bounded destructible region;
- replicated delta;
- save/reload;
- navigation recovery;
- performance trace.

### T5 — Scale
- latency/loss simulation;
- multi-client stress;
- bandwidth/CPU/memory profiling;
- only then evaluate larger raid/player/destruction targets.

## 11. Current dependency order

1. PR #14 infrastructure validation / real UE foundation.
2. Issue #10 original humanoid + Eco-Kin body/animation/runtime evidence.
3. 4–6 Eco-Kin vertical slice.
4. Registry/UI/save proof for that bounded slice.
5. Raid replication and persistent destruction proof.
6. Larger seasonal roster and multiplayer scaling.

This keeps the game fundable and testable without pretending design documents equal runtime proof.
