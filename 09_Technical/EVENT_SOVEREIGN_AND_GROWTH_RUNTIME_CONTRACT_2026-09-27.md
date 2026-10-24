# ECHOHEARTS: REBEARTH — EVENT SOVEREIGN & GROWTH RUNTIME CONTRACT

**Date:** 2026-09-27  
**Status:** TECHNICAL DESIGN CONTRACT / NOT YET VERIFIED  
**Engine target:** Unreal Engine 5.8  
**Purpose:** Define a clean implementation direction for one-time Event Sovereigns and Eco-Kin Growth Rites without claiming code exists or compiles in the current repository.

## 1. Architecture goals

The runtime must guarantee:

- one canonical event-spawn transaction per save/world state;
- no duplicate canonical rewards through reload, reconnect or RPC replay;
- clear event prerequisites;
- server authority in shared play;
- replayable simulation after canonical completion without changing world history;
- stable EcoKinID and FormID relationships;
- data-driven Growth Rite requirements;
- readable UI reasons when a Growth Rite/event is locked;
- versioned save migration;
- bounded asset loading.

## 2. Separate static definition from persistent state

Do not serialize all event definitions, all 125 species definitions or all Growth Rite data into every SaveGame.

Use read-only authored data for definitions and SaveGame/world state for progress.

### Static authored definition layer

Recommended assets/data:

- `UEcoKinDefinition` — stable Permanent Dex identity data;
- `UGrowthRiteDefinition` — one authored growth transition;
- `UEventSovereignDefinition` — one authored event encounter;
- `URegionDefinition` — region/world-state identity;
- `URewardProfileDefinition` — non-sentient bounded reward/world unlock definitions.

Where appropriate, these can derive from `UPrimaryDataAsset` so they have stable Primary Asset IDs and Asset Manager support.

### Persistent state layer

Save only instance/progression data such as:

- completed canonical event IDs;
- active event ID/state;
- event transaction GUID/revision;
- selected outcome;
- granted canonical reward transaction IDs;
- region state changes;
- bonded Eco-Kin instance growth state;
- completed Growth Rite IDs;
- current FormID;
- Kindling state;
- relevant story/ecology milestone tags.

## 3. Conceptual Event Sovereign definition

Illustrative schema only — not production code:

```cpp
UENUM(BlueprintType)
enum class EERSovereignEventResolution : uint8
{
    None,
    Cleansed,
    Stabilized,
    Allied,
    Migrated,
    Sealed,
    Defeated
};

UCLASS(BlueprintType)
class UEREventSovereignDefinition : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly)
    FGameplayTag EventTag;

    UPROPERTY(EditDefaultsOnly)
    FPrimaryAssetId EncounterIdentity;

    UPROPERTY(EditDefaultsOnly)
    FGameplayTagContainer RequiredStoryTags;

    UPROPERTY(EditDefaultsOnly)
    FGameplayTagContainer RequiredWorldTags;

    UPROPERTY(EditDefaultsOnly)
    FGameplayTagContainer BlockingTags;

    UPROPERTY(EditDefaultsOnly)
    FName RegionStateID;

    UPROPERTY(EditDefaultsOnly)
    FName CanonicalRewardProfileID;
};
```

### Rule

A definition never stores 'HasSpawned' or 'RewardClaimed'. Those are save/world-state facts.

## 4. Persistent one-time event ledger

Illustrative state:

```cpp
USTRUCT(BlueprintType)
struct FERSovereignEventLedgerEntry
{
    GENERATED_BODY()

    UPROPERTY()
    FGameplayTag EventTag;

    UPROPERTY()
    FGuid TransactionId;

    UPROPERTY()
    int32 Revision = 0;

    UPROPERTY()
    bool bCanonicalSpawnCommitted = false;

    UPROPERTY()
    bool bCanonicalResolutionCommitted = false;

    UPROPERTY()
    EERSovereignEventResolution Resolution = EERSovereignEventResolution::None;

    UPROPERTY()
    FGuid CanonicalRewardTransactionId;
};
```

### Required invariant

For a canonical event:

`CanonicalSpawnCommitted == true` means the world cannot create a second canonical instance by normal loading/reconnection.

A replay simulation uses a separate simulation/session ID and never clears or reuses the canonical transaction ID.

## 5. Server-authoritative event start

Shared-play flow:

**Client discovers trigger → Server validates requirements → Server creates/commits event transaction → Server spawns encounter → Replicated event state → Clients present encounter.**

Server validation should include:

- event not already canonically completed;
- region/world revision matches;
- prerequisite story tags;
- prerequisite restoration/ecology tags;
- event availability state;
- party/match instance legitimacy;
- no conflicting event in protected volume;
- rate/replay protection;
- required streamed assets ready or safely pending.

Clients must never authoritatively set `bCanonicalSpawnCommitted`.

## 6. Failure/recovery policy

A one-time canonical event must not become permanently broken because:

- the client crashed;
- host disconnected;
- network timed out;
- player abandoned the region;
- save operation failed.

Therefore distinguish:

- **Spawn Reserved** — transaction created;
- **Encounter Active** — authoritative actor/state exists;
- **Suspended/Recoverable** — session ended before resolution;
- **Resolved** — outcome committed;
- **Archived** — simulation replay unlocked.

On load, an unresolved reserved/active event should resume from an authored checkpoint or safely reset the encounter presentation while preserving the same canonical transaction.

## 7. Async save requirement

Do not use a fire-and-forget save call for canonical one-time event resolution.

The commit flow must handle save completion/failure.

Conceptual order:

1. validate resolution;
2. build world/event transaction;
3. mark pending commit;
4. request async save/persistence operation;
5. receive completion result;
6. only then finalize UI/reward acknowledgment according to platform-safe policy;
7. on failure, retain recoverable pending state and retry/notify without granting duplicate rewards.

Do not allow save and load operations to race on platforms where the engine/platform does not support that safely.

## 8. Growth Rite definition schema

Illustrative data structure:

```cpp
UENUM(BlueprintType)
enum class EERGrowthRiteFamily : uint8
{
    Earthline,
    ResonanceBranch,
    HabitatForm,
    WeatherPulse,
    Mutation,
    Shimmer,
    Aurivelle,
    AncestralEcho,
    RestorationBloom
};

UCLASS(BlueprintType)
class UERGrowthRiteDefinition : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly)
    FName GrowthRiteID;

    UPROPERTY(EditDefaultsOnly)
    FName ParentEcoKinID;

    UPROPERTY(EditDefaultsOnly)
    EERGrowthRiteFamily Family;

    UPROPERTY(EditDefaultsOnly)
    FName ResultIdentityOrFormID;

    UPROPERTY(EditDefaultsOnly)
    bool bIdentityPreservingForm = false;

    UPROPERTY(EditDefaultsOnly)
    FGameplayTagContainer RequiredStoryTags;

    UPROPERTY(EditDefaultsOnly)
    FGameplayTagContainer RequiredEcologyTags;

    UPROPERTY(EditDefaultsOnly)
    FGameplayTagContainer RequiredWeatherTags;

    UPROPERTY(EditDefaultsOnly)
    float MinimumKindling = 0.0f;
};
```

Exact field types/names require implementation review against the real project module and save architecture.

## 9. Growth validation order

Recommended deterministic check order:

1. stable parent EcoKinID matches bonded instance;
2. rite exists and is release-available;
3. rite has not already been irreversibly completed where relevant;
4. story gates;
5. ecology/restoration gates;
6. Kindling gate;
7. habitat/region gate;
8. weather/season gate;
9. catalyst inventory transaction;
10. health/stress/safety gate;
11. animation/asset availability;
12. server authority for shared play;
13. commit result to save/world ledger.

UI should expose every non-secret failed check in player-readable language.

## 10. Growth transaction safety

Never mutate identity and consume a catalyst as two unrelated operations.

Use one authored growth transaction containing:

- transaction GUID;
- bonded instance ID;
- parent EcoKinID;
- source FormID;
- GrowthRiteID;
- destination identity/form;
- consumed non-sentient catalyst IDs/quantities;
- resulting V/D/H/P delta/reallocation;
- timestamp/revision;
- animation/presentation result;
- save commit result.

If the commit fails, the system must not consume the catalyst permanently while leaving the Eco-Kin unchanged.

## 11. Static Orchard technical correction

The Static Orchard suppression mechanic should operate as authored gameplay state, not by corrupting Pause UI state.

Recommended tags:

- `Region.StaticOrchard`
- `Hazard.ResonanceSuppression`
- `Hazard.PhaseCancellation`
- `Event.Sovereign.HushglassWarden`
- `WorldState.StaticOrchard.Suppressed`
- `WorldState.StaticOrchard.Recovering`
- `WorldState.StaticOrchard.Regenerated`

The pause/settings/accessibility interface remains outside combat-buff logic.

## 12. Boss/Sovereign phase architecture

Do not implement phases as one giant switch statement tied to HP percentages only.

Prefer authored phase/state objects or data-driven phase definitions with conditions such as:

- health threshold;
- environmental objective state;
- pylon/anchor state;
- region state;
- timer;
- player objective completion;
- recovery threshold;
- ally rescue state.

Each phase transition should be server-authoritative in shared play and emit an idempotent event for presentation/audio/VFX.

## 13. Replay simulation contract

Archive replay is a separate non-canonical context.

Replay state should include:

- source canonical EventTag;
- chosen difficulty modifier;
- simulation seed where used;
- party data;
- no persistent world mutation permissions;
- no canonical reward profile;
- bounded simulation reward profile;
- leaderboard eligibility if later approved.

Replay cannot:

- reopen the canonical first-spawn flag;
- duplicate Sovereign relationship outcomes;
- duplicate one-time blueprints;
- rewrite region restoration;
- re-trigger story cinematics as canonical history.

## 14. Performance/streaming direction

Event Sovereign definitions should reference encounter asset bundles rather than force all Sovereign assets resident globally.

Possible bundle groups:

- mesh/rig/animations;
- phase VFX;
- audio;
- arena data;
- cinematic assets;
- accessibility telegraphs.

Load only when the event becomes likely/active and unload when safe after resolution/archive return.

## 15. Test matrix required before VERIFIED

### Event ledger tests

- fresh save trigger;
- fail encounter and retry;
- quit during phase transition;
- crash/restart recovery;
- disconnect/reconnect;
- host migration policy where supported;
- canonical reward only once;
- simulation replay cannot duplicate reward;
- corrupted/old save migration;
- event trigger after region restoration reload.

### Growth Rite tests

- every requirement failure reason;
- catalyst rollback on failed commit;
- save/reload after successful rite;
- reversible form switching;
- permanent maturation state;
- parent/form ID integrity;
- multiplayer authority/reconnect;
- animation interruption;
- missing asset fallback;
- version migration after data changes.

## 16. Current status

This file is a technical contract only.

No C++ class above is claimed to exist, compile, replicate correctly or pass packaging in the current repository.

Before implementation is called VERIFIED, the project still requires the canonical UE project/module foundation and evidence ladder already defined elsewhere.
