# Frequency Sanctuary & Atmospheric Simulation — UE5.8 Technical Contract
**Date:** 2026-10-16  
**Status:** TECHNICAL DESIGN / API PROPOSAL ONLY. **NO UHT/BUILD/RUNTIME VERIFICATION.**

## Ownership / prerequisites
Canon contract repository: `Dlomotion/Echohearts-Rebearth`. Build executable authority: `Dlomotion/ECHOHEARTS-REBEARTH-BUILD-` (not accessible through present GitHub installation; do not write production source into this public repo). The `Echohearts` runtime module and `ECHOHEARTS_API` export macro are authoritative. Do not revive obsolete `EchoheartsRebearth` module naming. Prerequisites: current BUILD project/targets inspected; BCT-001 building placement interface, player identity, world-state transaction API, A.E.G.I.S. / D.A.H.L.I.A., existing Sanctuary and Game Feature modules audited for duplicate class names.

## Data interfaces
```text
FFrequencySanctuaryDefinition
  ZoneId: FGuid
  OwnerAccountId: trusted registry handle (not plaintext personally identifying value)
  WorldCellId: FName
  Pylon: weak actor / persistent component GUID
  Station: weak actor / persistent component GUID
  RestNode: weak actor / persistent component GUID
  EnergyWallSegments: persistent GUID array
  Capacity: bounded int
  RequiredPowerUnits: bounded float
  Revision: uint32

FFrequencyResidentRequest
  GuardianIdentityId: FName (NPC registry identity; NOT EcoKinID)
  ZoneId: FGuid
  ConsentToken: server-issued signed capability, short expiry
  TransactionId: FGuid
  RequestorAccountHandle: authenticated identity

FFrequencyRegistrationResult
  Accepted: bool
  RejectReason: GameplayTag (MissingPylon | MissingStation | MissingRestNode |
      MissingWallContinuity | NoEgress | Unpowered | Unauthorized | NoConsent |
      Occupied | StoryLocked | WorldCellUnavailable | StaleRevision | AlreadyAnchored)
  CurrentRevision: uint32
  ResidentState: Anchored | AwaitingRepair | Travelling | Resting | VoluntarilyDeparted
```

### Representative Unreal interface sketch (NOT compiler-tested production code)
```cpp
// Target module: Echohearts (BUILD repository only).
// Unreal type/include paths and concrete dependencies must be resolved against BUILD.
UENUM(BlueprintType)
enum class EFrequencyResidentState : uint8
{
    Available, Invited, Travelling, Anchored,
    Resting, AwaitingRepair, VoluntarilyDeparted
};

USTRUCT(BlueprintType)
struct FFrequencyRegistrationOutcome
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    bool bAccepted = false;

    UPROPERTY(BlueprintReadOnly)
    FGameplayTag Reason;

    UPROPERTY(BlueprintReadOnly)
    EFrequencyResidentState NewState = EFrequencyResidentState::Available;
};

// Intended class: UFrequencySanctuaryComponent : UActorComponent.
// Only the owning server may execute TryRegisterGuardian;
// client actions are requests, not final state changes.
// NO implementation can bypass consent, occupant uniqueness,
// Energy Wall egress checks, or the existing BCT-001 transaction ledger.
//
// FFrequencyRegistrationOutcome TryRegisterGuardian(
//     const FGuid& ZoneId,
//     const FName& GuardianIdentityId,
//     const FGuid& TransactionId);
//
// bool IsZoneOperational(const FGuid& ZoneId) const;
// void OnModuleTopologyChanged(const FGuid& ZoneId);
// void RestoreZoneFromAuthoritativeSave(const FGuid& ZoneId);
```

**Critical implementation details:** Use `UPROPERTY` and strong references only for active streamed objects; save stable GUIDs rather than raw Actor pointers. Source of truth server; client replicated snapshots are view-only. The world partition owner validates actor membership in zone and adjacency graph. Validate perimeter continuity with graph flood-fill and an accessible safe egress path, not by comparing wall count to perimeter length. Rate-limit zone recalculations and debounce repeated structure events. Zone registration transaction must compare revision and use a unique `TransactionId`; replayed requests return stable outcomes. On destroyed/streamed-off module, mark residents `AwaitingRepair` while preserving identity and consent and keeping an escape route.

## Atmosphere
**Authority model:** `URebearthWeatherWorldSubsystem` (WorldSubsystem proposal) maintains a bounded set of active authoritative `FRegionWeatherState` descriptors, seeded per region/day/world-state version. The server publishes replicated regional state deltas (`WeatherProfileId`, `Phase`, `StartUtc`, `EndUtc`, `Seed`, `WindVector`, `HazardTag`, `Revision`). Rendering side consumes descriptors through SkyAtmosphere, Volumetric Cloud, Niagara/Material Parameter Collections and MetaSounds; **visual detail settings cannot affect the authoritative hazard footprint**.

**Budget boundaries:** region update at designed low frequency/event changes, zero unbounded global Ticks, deterministic active cell cap, pooled particles/projectors, LOD based on camera and accessibility. Avoid dense per-segment storm-lightning colliders. On World Partition unload preserve only authoritative phase/time/seed and restore deterministically. On ownership transfer/desync compare revision and absolute times.

**Cloud asset naming:** `CLD_DRIFT_01`, `CLD_CIRRUS_02`, `CLD_MARINEFOG_03`, `CLD_THUNDERHEAD_04`, `CLD_BLIGHTFRONT_05`, `CLD_ICEVEIL_06`, `CLD_AURORA_07`. Proposed directories in BUILD Content, after art naming policy check: `Content/Echohearts/Atmosphere/Clouds` and `.../Storms` (NOT created here).

## Marine simulation
**Domain services (proposed):**
- `UShipBlueprintValidationService`: signed versioned part definitions, snap-slot graph, structural load, power budget, flotation approximation, co-op permission, limits.
- `UCurrentAndPressureSubsystem`: streamed vector fields with authored/current-generated crossfades; **does not** demand unrestricted voxel water simulation.
- `UDiveSafetyComponent`: diver pressure tier, air supply consumption, seal integrity, ascent safety, rescue availability. Display as equipment/hazard state, not new public character stats.
- `UShipVoyageComponent`: server-authoritative navigational inputs, safe caps, damage events, passenger manifests, normalized rollback states.

Avoid mass/physics client cheating: commands carry timestamp and allowed bounds; server validates and simulates intended forces. Saved modular blueprint payload must use allowlisted module definitions and constrained numeric transforms; prohibit arbitrary classes, UObject paths, scripts, relative traversal or unrestricted imported executable data. Preserve creator attribution/license provenance and export no authentication tokens.

## NPC, boss and city subsystem interoperability
NPC roles use authored data assets and existing NPC identity roster. Frequency Sanctuary eligibility is infrastructure-driven, while NPC behavior can be StateTree/BT-driven; simulated projectiles are tag-filtered by friendly-fire and resident-safety rules. Boss candidate slots are `ENCP-01...ENCP-11`, not new official creature Dex entries; use encounter data separately from NPC logic.

Bowling minigame data is located within the established Echohearts City/social system: `VenueId`, `LaneId`, `MatchTransactionId`, `RoundState`, `BallInput`, `AuthoritativePinState`, `ScoreRevision`. Score totals should be recomputed from server-validated fallen pin sets under a deterministic ruleset; protect against input spoofing and repeated frame award events. The **13:30** proposed league time is in-world context until local-world-time/UTC conversion is explicitly approved.

## Validation gates / regression plan
1. **Schema:** JSON parses; IDs unique, working status present, all elements from approved registry.
2. **Sanctuary graph:** disconnected wall, single unattached segment, blocked door, powered-off node, invalid actor ID, two parallel registrations, conflicting owners, consent revoked, save migration, unloaded cell then reload.
3. **Frequency conditions:** balanced region → weather damage → shelter → world restoration; Harmony/Purity modifiers do not grant invulnerability or create a new public stats row.
4. **Weather:** clock rewind attempt rejected; reconnect during warning, storm, and clearing; LOD parity of damage; no client-controlled lightning; accessibility variants.
5. **Ship/diving:** invalid part graph, unsafe buoyancy, over-cap cargo, import with malformed fields, two simultaneous editors, storm/ship collision, underwater reconnection, safe-ascent and voluntary companion leave.
6. **Encounter:** non-combat outcomes and failure recoveries for each candidate; 07 Parallax pair one-node loss, dual shutdown, pressure-storm transition, pause/resume; no softlock.
7. **Bowling:** double-event pin scoring, reconnect, spectator spoof, invited versus uninvited session changes.
8. **Runtime proof:** exact UE5.8.x Build.version, UHT, `Echohearts` module compilation, UE automation tests, Development Win64 package, launched build, save migration, dedicated server replication and 60 FPS profiling. Only proven scopes receive `VERIFIED` status.

## Suggested implementation order (after BUILD access)
1. Integrate Sanctuary zone validator **without** NPC combat; unit/automation tests.
2. Add weather descriptor replication & cloud art hooks; make one functioning storm on a small map.
3. Add simple skiff assembly/buoyancy and one dive pocket with rescue.
4. Integrate one original encounter `ENCP-07` with evidence-gated phase tree.
5. Add city bowling prototype after location and schedule owners sign off.
No claim of platform certification, live service, release date or runtime completion at this stage.
