# ECHOHEARTS: REBEARTH — PR #17 TRANSACTION & VALIDATION CODE REVIEW

**Date:** 2026-09-27  
**Status:** TECHNICAL REVIEW / CORRECTIVE CONTRACT / NOT YET VERIFIED  
**Target:** Unreal Engine 5.8  
**Branch:** `canon/seasonal-main-story-training-2026-09-27`

## 1. Executive disposition

The pasted standalone C++ examples contain useful architectural intent but are **not production UE5.8 code** and must not be merged into a future `Source/` tree unchanged.

Retain:

- explicit encounter states;
- explicit Sovereign outcomes;
- one-time canonical world-event semantics;
- separate replay/archive context;
- readable Growth Rite lock reasons;
- transaction IDs/revisions;
- async persistence completion as a required boundary;
- server authority for canonical multiplayer state.

Correct or retire:

- `std::map` as a fake persistent SaveGame backend;
- immediate callback labeled as asynchronous persistence;
- one global `ActiveContext` for all event transactions;
- spawning a canonical Sovereign before durable reservation commit;
- using only `Archived` string state to prevent duplication;
- hard-coded Earthline logic for one biome/species inside a generic validator;
- hand-made string-prefix `FGameplayTag` emulation;
- `EvolutionState { Alpha, Mega, Omega, Cube, Umbral, Echo }` because those are not the authoritative Echohearts growth/form families;
- blocking gameplay input on odd frame/tick values;
- treating a visual/environmental glitch as an input-security mechanism;
- alphanumeric stripping presented as protection against “memory injection”;
- arbitrary `inputTick <= 100000` as a trust/security boundary.

## 2. Epic UE5.8 API facts that govern implementation

### Async save

UE5.8 native `UGameplayStatics::AsyncSaveGameToSlot` takes four parameters:

```cpp
UGameplayStatics::AsyncSaveGameToSlot(
    USaveGame* SaveGameObject,
    const FString& SlotName,
    const int32 UserIndex,
    FAsyncSaveGameToSlotDelegate SavedDelegate);
```

The save object is serialized on the game thread, the platform write occurs asynchronously, and the completion delegate is invoked on the game thread with success/failure.

Therefore the canonical transaction code must react to the delegate result. A local map write plus immediate callback does not test this contract.

### Gameplay Tags

Use the engine's registered `FGameplayTag`, `FGameplayTagContainer`, and `FGameplayTagQuery` types. `FGameplayTag::MatchesTag` has hierarchical semantics; do not replace it with `std::string::find(Query) == 0`.

Examples of intended namespaces:

- `Event.Sovereign.Anchorfall`
- `Event.State.SpawnReserved`
- `Event.State.EncounterActive`
- `Event.State.SuspendedRecoverable`
- `Event.State.Resolved`
- `Event.State.Archived`
- `Growth.Earthline`
- `Growth.RestorationBloom`
- `Ecology.Restored.Mire`
- `Region.StaticOrchard`

### Primary Data Assets

Static authored Sovereign/Growth definitions may derive from `UPrimaryDataAsset` so they receive Primary Asset IDs and can participate in Asset Manager loading/bundles. Persistent state belongs in save/world ledgers, not in the definition asset.

### Testing

Use Unreal Automation Tests/Specs for API-level/state-machine testing once the real project module exists. Standalone `main()` console tests can be useful for algorithm sketches but do not prove UObject, SaveGame, Asset Manager, replication, packaging, or platform behavior.

## 3. Correct canonical event transaction order

The previous sample moved directly from discovery to `EncounterActive` and only saved at resolution. That leaves a duplication/recovery gap.

Required order:

1. **Discover Trigger** — client/local world detects candidate trigger.
2. **Server Validate** — authority checks release availability, world revision, prerequisites, replay status, protected-volume conflicts, party/session legitimacy, and current ledger.
3. **Create Transaction ID** — server creates a stable `FGuid` plus revision.
4. **Set SpawnReserved Pending State** — ledger entry is staged with the transaction ID.
5. **Persist Reservation** — save/database operation completes successfully.
6. **Only after successful reservation persistence:** spawn the canonical encounter and mark `EncounterActive`.
7. **Replicate Encounter State** — clients receive the authoritative state/transaction identifier.
8. **Resolve Outcome** — server validates Cleansed/Stabilized/Allied/Migrated/Sealed/Defeated outcome.
9. **Stage Resolution + Reward Transaction** — reward ID and world-state delta are generated idempotently.
10. **Persist Resolution** — completion callback must succeed.
11. **Acknowledge Canonical Rewards / World Delta** — grant or confirm according to the chosen platform-safe transaction model.
12. **Mark Archived** — Archive replay is enabled; the canonical transaction can never be reopened by normal gameplay.

### Failure behavior

- reservation save fails → do **not** spawn canonical Sovereign;
- crash after successful reservation but before spawn → load same transaction as `SpawnReserved` and resume/reset presentation safely;
- crash during encounter → same transaction becomes/resumes `SuspendedRecoverable`;
- resolution save fails → do not create a second reward transaction; retry using the same transaction ID;
- replay mode always uses a separate simulation/session ID and has no canonical mutation permission.

## 4. Persistent state must retain more than `"Archived"`

Minimum ledger concept:

```cpp
USTRUCT(BlueprintType)
struct FERSovereignEventLedgerEntry
{
    GENERATED_BODY()

    UPROPERTY(SaveGame)
    FGameplayTag EventTag;

    UPROPERTY(SaveGame)
    FGuid CanonicalTransactionId;

    UPROPERTY(SaveGame)
    int32 Revision = 0;

    UPROPERTY(SaveGame)
    EERSovereignEncounterState State = EERSovereignEncounterState::SpawnReserved;

    UPROPERTY(SaveGame)
    EERSovereignEventResolution Resolution = EERSovereignEventResolution::None;

    UPROPERTY(SaveGame)
    FGuid RewardTransactionId;

    UPROPERTY(SaveGame)
    bool bReservationCommitted = false;

    UPROPERTY(SaveGame)
    bool bResolutionCommitted = false;
};
```

Exact UPROPERTY flags and ownership require real project-module review, but the important invariant is that transaction identity, state, outcome, revision and reward identity remain reconstructable after load.

## 5. Do not use one `ActiveContext`

A single manager field:

```cpp
FEventSovereignContext ActiveContext;
```

is insufficient for production because multiple regions/sessions/instances may exist and recovery must reference persistent transaction identity.

Use a keyed runtime map or authoritative subsystem concept keyed by event/transaction ID, while the SaveGame/world ledger remains the persistent truth.

Possible runtime key:

```text
<EventTag, CanonicalTransactionId, WorldRevision>
```

Do not key only by display name or mutable string.

## 6. Growth Rite validation must be data-driven

The generic processor must not hard-code:

```text
Earthline == Ecology.Restored.Mire && Density >= 50
```

That rule may belong to a particular species/rite definition, not to the entire Earthline family.

A Growth Rite definition should own authored requirements such as:

- parent Permanent EcoKinID;
- source FormID/state;
- destination identity/form ID;
- Growth Rite family;
- minimum/maximum V/D/H/P conditions where truly needed;
- minimum Kindling;
- required/blocked Story Tags;
- required/blocked Ecology Tags;
- region/habitat requirements;
- weather/season requirements;
- restoration milestones;
- non-sentient catalyst profile;
- health/stress/safety conditions;
- release availability;
- reversible/permanent behavior.

The validator evaluates the definition; it does not invent the definition.

## 7. Correct player-facing lock diagnostics

A.E.G.I.S. should explain unmet non-secret requirements clearly, but avoid hostile/internal-engine phrasing such as:

`CRITICAL COGNITIVE GAP`.

Preferred structure:

```text
Earthline Rite unavailable.
Habitat requirement: Restore the Mire ecosystem.
Current Density: 45 / Required: 50.
Suggested action: Continue mineral-bed acclimation or complete the Mire restoration chain.
```

Secret story requirements may remain intentionally undisclosed, but the UI should distinguish `Unknown Requirement` from a bug/error.

## 8. Input validation correction

The pasted `RebearthInputValidator` mixes gameplay mechanics, security validation and text sanitation. Split those responsibilities.

### A. Network/action validation

Do not trust client-provided:

- hit result;
- target actor;
- damage amount;
- inventory ownership;
- event completion;
- Growth Rite eligibility;
- world revision;
- catalyst consumption result;
- canonical transaction state.

Server/authority recomputes or validates against authoritative state.

Validate action requests using:

- authenticated/authorized player/session;
- expected transaction GUID;
- monotonically valid request/sequence/revision data;
- action availability/cooldown;
- distance/LOS/region constraints where relevant;
- owned/eligible Eco-Kin instance ID;
- authored Growth Rite ID or ability ID;
- registered Gameplay Tags/Queries;
- inventory/catalyst truth from authoritative inventory;
- replay/idempotency guards;
- numeric finite/range checks;
- protected-volume/team/faction rules.

### B. Input timing

Do **not** reject odd frames/ticks because a fictional glitch is active.

Environmental interference must be a deterministic gameplay state such as suppression buildup, altered ability timing, telegraphed input windows, or debuffs that respect accessibility options. Player controls/settings remain responsive.

A client frame number is not a security boundary. If sequence numbers are used for anti-replay/order, they must be protocol/session-relative and validated against authoritative connection state rather than magic bounds like `0..100000`.

### C. Growth/Form transitions

Retire the pasted enum:

```text
Standard, Alpha, Mega, Omega, Cube, Umbral, Echo
```

Use the current Echohearts families:

- Earthline;
- ResonanceBranch;
- HabitatForm;
- WeatherPulse;
- Mutation;
- Shimmer;
- Aurivelle;
- AncestralEcho;
- RestorationBloom.

Specific source → destination legality comes from an authored `UGrowthRiteDefinition`/form graph, not switch statements over generic franchise-like tier names.

### D. Text validation

`std::isalnum` stripping is not a general memory-injection defense.

For Unreal-facing text:

- use `FString`/`FText`/`FName` according to semantics;
- enforce length limits appropriate to the field;
- validate/normalize only what the field actually requires;
- do not strip legitimate Unicode names unless the product requirement explicitly restricts them;
- use safe UI rendering paths rather than constructing code/commands from player text;
- never use display strings as authoritative IDs;
- authoritative species/forms use stable IDs/Data Assets, not player-entered names.

## 9. Compatibility-Range Puzzle contract

The Static Orchard puzzle should not require exact equality between Harmony and Density.

Example abstract validation:

```text
PartyHarmony within authored band Hmin..Hmax
PartyDensity within authored band Dmin..Dmax
abs(NormalizedHarmony - NormalizedDensity) <= CompatibilityTolerance
At least one valid counter-suppression role present
No accessibility-blocking timing dependency
```

The puzzle definition should expose multiple viable team compositions and an assist/accessibility path.

The pause/settings menu cannot alter puzzle validity.

## 10. U.N.I.T.Y. state validation

U.N.I.T.Y. ending state should use a read-only evaluation snapshot assembled from persistent world/faction/ecology ledgers, not accept a client-selected ending enum.

Examples:

- faction Accord dispositions;
- Community Trust milestones;
- Eco-Kin autonomy protections;
- Tree of Life restoration;
- Sanctuary health;
- regional restoration;
- E.C.O. Sentinel relationship;
- cosmic allies;
- coercion flags;
- abandoned communities;
- final coalition integrity.

The final ending evaluator produces a result from authoritative facts. It never writes missing prerequisites merely because the player selected a dialogue option.

## 11. Save versioning / migration

Before Event Sovereigns or Growth Rites ship, define:

- Save schema version;
- content/canon version;
- migration path for renamed EventTags/GrowthRiteIDs/FormIDs;
- invalid/deleted asset fallback;
- stale pending transaction recovery;
- corrupted-save handling policy;
- deterministic idempotency behavior after migration.

A renamed Sovereign or Growth Rite must not accidentally look “unseen” and retrigger a canonical one-time reward.

## 12. Recommended Unreal module split once `.uproject` / `Source/` exist

Possible module ownership:

- `EchoheartsCore` — stable IDs, shared tags, transaction structs;
- `EchoheartsWorld` — regional state and Sovereign event subsystem;
- `EchoheartsEcoKin` — Eco-Kin definitions, Growth Rites, Forms Registry bridge;
- `EchoheartsPersistence` — SaveGame schema, migration, async operation queue/guard;
- `EchoheartsUI` — A.E.G.I.S. diagnostics/presentation only;
- `EchoheartsTests` or module `Private/Tests` — Automation Tests/Specs.

This is a planning split, not a requirement to create modules before the vertical-slice architecture proves what separation is actually useful.

## 13. Required first tests

When the real UE module exists, the smallest useful automated suite is:

### Event transaction

1. reservation persists before spawn;
2. failed reservation prevents spawn;
3. reload after reserved state reuses same GUID;
4. disconnect/crash path enters recoverable state;
5. successful resolution persists one outcome;
6. failed resolution save does not duplicate reward;
7. replay simulation cannot mutate canonical ledger;
8. renamed/migrated event retains completion state.

### Growth Rite

1. wrong parent ID rejected;
2. wrong source form rejected;
3. missing story/ecology/Kindling condition produces deterministic reason;
4. catalyst transaction rolls back if persistence fails;
5. successful commit survives reload;
6. reversible form returns through authored reverse path only;
7. permanent maturation cannot be replayed for duplicate stats/rewards;
8. migrated GrowthRiteID/FormID preserves bonded instance identity.

### Static Orchard

1. multiple valid party compositions satisfy compatibility range;
2. pause/settings never changes combat state;
3. accessibility timing assist produces equivalent objective validity;
4. Hushglass Warden canonical reward cannot duplicate through Archive replay.

## 14. Repository evidence boundary

At review time, repository search does not expose a canonical `.uproject` on this branch. Therefore:

- no pasted class is VERIFIED UE5.8 code;
- no `Build.cs` dependency set is verified;
- no UHT reflection result exists;
- no Development Editor compile is proven;
- no Automation Test execution is proven;
- no packaged save/reload is proven;
- no multiplayer authority/reconnect behavior is proven.

The correct current status remains:

**DESIGN/TECHNICAL CONTRACT → NOT YET VERIFIED.**

## 15. Promotion gate

Do not promote this work to VERIFIED until evidence exists for:

**canonical `.uproject` + Source module → UHT/compile → Automation tests → editor runtime → save/failure/reload → multi-client authority/reconnect → Development package → fresh-clone/LFS reproduction → rollback/recovery evidence.**
