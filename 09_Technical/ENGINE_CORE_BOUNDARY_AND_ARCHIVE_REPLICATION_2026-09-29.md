# ECHOHEARTS: REBEARTH — ENGINE CORE BOUNDARY & ARCHIVE REPLICATION

**Date:** 2026-09-29  
**Status:** TECHNICAL DESIGN CONTRACT / NOT YET VERIFIED  
**Engine target:** Unreal Engine 5.8  
**Purpose:** Reconcile the pasted containment, Chrono Archive and Morrowmire code into current Echohearts canon, multiplayer authority, save safety and one-time Event Sovereign transaction rules.

---

## 1. Critical intake corrections

The pasted `main()` programs are useful algorithm sketches only. They are **not production-ready UE5.8 C++** and are not runtime verification.

The following terms/behaviors are retired from implementation:

- `capture field` as ownership/capture;
- `TargetBeast` / `WildBeastTarget` for sentient Eco-Kin;
- `Vessel Disc` storage;
- `Capture Verified`;
- universal Hz/frequency matching derived directly from species stats;
- a generic `UmbralFrame` global form enum;
- storing canonical event truth only in local booleans;
- treating a local `std::map` counter as replicated/persistent state;
- allowing a local execution-scope enum to be the only barrier preventing world mutation;
- permanent content deletion from an unverified local threshold branch;
- claims that console output proves database/branch/runtime integration.

Current relationship canon remains:

**Observe → Protect → Calm → Kindle → Bond / Release / Defer.**

A.E.G.I.S. stabilization is a **safety/environment interaction**, not a creature ownership mechanic.

## 2. A.E.G.I.S. Boundary Stabilization

### Purpose

A.E.G.I.S. may project a temporary **Stabilization Boundary** around:

- a dangerous environmental anomaly;
- a Blight-distorted Eco-Kin that needs nonlethal de-escalation;
- a collapsing Rift interface;
- a damaged containment/anchor structure;
- an Event Sovereign phase objective.

The goal is to create a safe interaction window, restore local stability, or make Kindling/cleansing possible.

Success never places a sentient Eco-Kin into storage.

### Recommended boundary states

```text
Inactive
Calibrating
Stable
Slipping
Failed
Recovered
```

Avoid `Locked` when it implies captured ownership.

## 3. No universal frequency formula

The old sample calculated target Hz from `DensityRating` or `SpatialFrameVelocity`.

That conflicts with the canon rule that Resonance is not universally music/sound.

Instead, every stabilization interaction references an authored **Stabilization Profile** containing the signals relevant to that encounter, for example:

- spatial drift tolerance;
- movement envelope;
- phase offset;
- anchor alignment;
- elemental/environmental tags;
- Harmony tolerance;
- Density support requirement;
- timing window;
- line-of-sight/position requirement;
- safe tool tags;
- accessibility settings.

Some specialist encounters may use acoustics/Echo frequency, including the Static Orchard. That is encounter-specific, not universal creature biology.

## 4. Data-driven stabilization definition

Recommended static definition fields:

- `StabilizationProfileID`
- `RequiredTargetTags`
- `RequiredWorldTags`
- `AllowedAegisToolTags`
- `RequiredAnchorTags`
- `HarmonyBand`
- `DensityFloor`
- `SpatialTolerance`
- `TimingTolerance`
- `ProgressPerValidWindow`
- `RegressionPerInvalidWindow`
- `FailureRecoveryPolicy`
- `AccessibilityOverrides`
- `CompletionActionTag`

A production implementation may use Primary Data Assets for this authored data where appropriate.

## 5. Player input / authority boundary

In shared play, the client sends **intent**, not authoritative success.

Example:

```text
Client input intent
→ Server validates player/session/action eligibility
→ Server samples authoritative target/world state
→ Server evaluates stabilization window
→ Server updates objective progress
→ Replicated presentation state reaches clients
```

The client must not authoritatively send:

- final stabilization percentage;
- target state;
- Event Sovereign resolution;
- reward result;
- canonical world revision;
- Growth Rite completion;
- canonical weather;
- permanent regional restoration.

## 6. Replicated state direction

A runtime implementation should key state by stable encounter/transaction identity, not one global context.

Conceptual replicated state:

```cpp
USTRUCT(BlueprintType)
struct FERStabilizationRepState
{
    GENERATED_BODY()

    UPROPERTY()
    FGuid TransactionId;

    UPROPERTY()
    FGameplayTag ObjectiveTag;

    UPROPERTY()
    int32 Revision = 0;

    UPROPERTY()
    float Progress01 = 0.0f;

    UPROPERTY()
    FGameplayTag StateTag;
};
```

This is illustrative only. Exact project/module/API names require the real UE project.

Replication should communicate objective truth. Cosmetic VFX/audio can predict locally where safe but reconcile to server state.

## 7. Chrono Archive Simulation Layer

### Canon purpose

Chrono Archive replay exists so a one-time canonical Sovereign encounter can be practiced/replayed without rewriting history.

### Hard separation

Archive Simulation is a separate permission context.

Simulation may read canonical encounter definitions but receives **no permission** to commit:

- canonical event spawn/resolution flags;
- permanent region restoration;
- unique story blueprints;
- faction outcomes;
- Sovereign relationship state;
- U.N.I.T.Y. coalition variables;
- one-time canonical rewards.

This separation must be architectural, not a single local `if (Scope == Simulation)` guard.

## 8. Archive reward rules

Archive replays may grant bounded, non-canonical rewards such as:

- Archive Knowledge progression;
- cosmetics;
- practice medals/titles;
- leaderboard records where later approved;
- bounded non-unique crafting/training resources;
- simulation challenge unlocks.

They must not duplicate:

- canonical story rewards;
- unique Growth Rite permissions tied to first resolution unless explicitly authored;
- permanent world-state changes;
- one-time Sovereign alliance outcomes.

If Sanctuary simulation upgrades exist, their unlock must be deliberately authored and capped rather than infinitely farmed by a local replay counter.

## 9. Archive persistence / replication

A local `std::map<std::string,int>` does not provide save persistence or multiplayer replication.

Recommended separation:

- canonical world ledger: authoritative save/world service;
- profile/simulation records: player profile/save service;
- live simulation state: transient authoritative session/instance;
- leaderboard records: separate online/backend path if later implemented.

Simulation clear counters are profile data, not proof of canonical world history.

## 10. Morrowmire Colossus trigger correction

The old sample used:

```text
EnvironmentalPurity < 30
TectonicStability < 0.4
```

as hard-coded universal trigger logic.

Those values are design placeholders only.

The real event should be driven by an authored Event Sovereign definition that can combine:

- region state revision;
- Blight severity;
- tectonic/land-shelf stability;
- story milestone tags;
- restoration state;
- active conflicting-event tags;
- availability/season rules;
- required streamed assets;
- event already-reserved/resolved state.

## 11. Canonical Morrowmire transaction

The one-time event uses the existing durable transaction sequence:

```text
Trigger candidate detected
→ Server validates authored prerequisites
→ Create Transaction GUID + revision
→ Stage SpawnReserved ledger entry
→ Async persistence request
→ Save succeeds
→ Spawn canonical encounter
→ EncounterActive
→ Outcome resolved
→ Stage outcome/world/reward transaction
→ Async persistence request
→ Save succeeds
→ Commit reward/world consequence
→ Archive replay permission becomes available
```

If the reservation save fails, the canonical Sovereign must not spawn.

If the game crashes after reservation but before resolution, reload uses the same GUID/revision and enters the authored **Suspended/Recoverable** path.

## 12. Morrowmire consequence philosophy

A meaningful failure can damage access, ecology or infrastructure without accidentally deleting irreplaceable content forever because one local boolean evaluated false.

Examples of authored consequences:

- travel corridor becomes damaged/inaccessible until a recovery chain is completed;
- migration route shifts;
- Sanctuary logistics become more difficult;
- regional Blight severity rises;
- alternate rescue route opens;
- later restoration cost/time increases;
- faction response changes.

This preserves consequence while remaining compatible with the project's **Life Continues / Regeneration** philosophy.

Permanent irreversible losses may exist only when deliberately story-authored, clearly telegraphed and tested.

## 13. Eco-Kin outcome language

For sentient Eco-Kin/Sovereigns, use outcomes such as:

- Cleansed;
- Stabilized;
- Allied;
- Migrated;
- Sealed when a non-sentient/anomaly target justifies it;
- Defeated where combat defeat is appropriate;
- Deferred/Unresolved where story permits.

Do not equate encounter success with capture.

## 14. Weather Pulse integration

Weather/region state used by Event Sovereigns must come from authoritative world state.

Weather Pulse Forms are evaluated from species/form eligibility plus authoritative weather data. They do not mutate canonical baseline stats every tick.

The technical weather rules are defined in:

`04_Systems/ECO_KIN_ENVIRONMENTAL_PUZZLES_AND_WEATHER_PULSE_2026-09-29.md`

## 15. UE5.8 reference architecture

When the real project exists, use Unreal-native systems rather than STL stand-ins for gameplay architecture where appropriate.

### Gameplay Tags

Use registered `FGameplayTag`, `FGameplayTagContainer` and `FGameplayTagQuery` for hierarchical state/requirement logic rather than string-prefix emulation.

### Data Assets

Static encounter, puzzle, Growth Rite, weather/form and stabilization definitions may derive from `UPrimaryDataAsset` where Asset Manager loading/bundles are useful.

### SaveGame

`UGameplayStatics::AsyncSaveGameToSlot` is a real asynchronous save API. In UE5.8, serialization occurs on the game thread, the platform write occurs on a worker thread, and the completion delegate is called on the game thread. Canonical event transitions therefore must react to completion/failure rather than assume a write succeeded immediately.

### Important save race rule

Do not launch conflicting save/load operations on platforms where simultaneous operations are unsupported. Queue/serialize persistence transactions.

## 16. Conceptual persistence interface

A future runtime subsystem should expose operations closer to:

```text
ReserveCanonicalEvent(EventTag, WorldRevision, Completion)
CommitCanonicalResolution(TransactionId, Outcome, DeltaSet, RewardTxn, Completion)
LoadOrRecoverPendingEvents(Completion)
CommitGrowthRite(GrowthTransaction, Completion)
CommitRegionDelta(RegionTransaction, Completion)
```

Each operation must be idempotent using stable transaction identity.

## 17. World transition / U.N.I.T.Y. safety

Do not serialize U.N.I.T.Y. as one client-selected ending enum during a level transition.

World transitions should load/commit the authoritative underlying variables, including as applicable:

- faction Accord states;
- community trust;
- Tree of Life restoration;
- Sanctuary state;
- regional restoration;
- Eco-Kin autonomy protection;
- E.C.O. Sentinel relationship;
- cosmic allies;
- coercion flags;
- abandoned communities;
- final coalition integrity.

The ending resolver derives the eligible outcome from those persisted facts.

## 18. Network failure / recovery matrix

Before any Event Sovereign system is VERIFIED, test at minimum:

- disconnect before reservation save completes;
- disconnect after reservation but before spawn;
- host/server crash during active encounter;
- reconnect to active encounter;
- quit during resolution save;
- duplicate resolution RPC;
- replayed/stale transaction revision;
- two clients trigger same event simultaneously;
- Archive session tries canonical mutation;
- old save migration with pending event;
- reward commit succeeds once only;
- region delta and reward commit remain consistent.

## 19. Automated test targets

Once the repository exposes a real `.uproject` and Source module, implement Unreal Automation Tests/Specs for:

- event reservation idempotency;
- pending-event recovery;
- no spawn before durable reservation;
- no reward before durable resolution;
- replay cannot commit canonical mutations;
- stabilization progress clamps to `[0,1]`;
- stale revision rejection;
- client-forged world state rejection;
- Weather Pulse no-stack invariant;
- Static Orchard multiple-solution invariant;
- Growth Rite rollback/commit behavior.

Standalone `main()` output is not sufficient verification.

## 20. Repository evidence boundary

At the time of this 2026-09-29 integration, PR #17 remains a documentation/canon/system branch and its current head still does not expose a canonical `.uproject`/real runtime module in the reviewed tree.

Therefore this file does **not** claim:

- UE5.8 compilation;
- actual replication;
- working RPCs;
- working SaveGame migration;
- Morrowmire gameplay;
- Chrono Archive runtime isolation;
- Weather Pulse runtime behavior;
- packaged build verification.

Status remains:

**DESIGN CONTRACT / NOT YET VERIFIED.**

Required evidence remains:

**Real UE foundation → UHT/Compile → Automated Tests → Save/Reload/Recovery → Network Validation → Packaging → Runtime Evidence → VERIFIED.**
