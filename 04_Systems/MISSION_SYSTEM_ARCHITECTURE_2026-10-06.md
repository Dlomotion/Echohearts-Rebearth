# Echohearts: Rebearth — Mission System Architecture

**Status:** APPROVED-PENDING IMPLEMENTATION / NOT YET UE5.8 VERIFIED  
**Runtime authority:** `Dlomotion/ECHOHEARTS-REBEARTH-BUILD-`  
**Canon/contracts authority:** `Dlomotion/Echohearts-Rebearth`

## Purpose

Provide one event-driven mission framework for main-story missions, side missions, multi-stage objectives, dialogue-gated progression, co-op shared-world state, UI updates, save integration, and later reward transactions without per-frame Tick polling.

## Corrections to the submitted prototype

The submitted design contains useful intent but is not compile-ready as written. Required corrections are:

- each `#include` must be on its own preprocessor line;
- use the active runtime export macro `ECHOHEARTS_API`, not `ECHOHEARTSREBEARTH_API`;
- do not include a CPP file from itself; `MissionTrackerSubsystem.cpp` must include its header;
- `ConstructorHelpers::FObjectFinder` is not the mission subsystem's runtime loading mechanism; mission definitions must be injected/data-driven through an authored DataTable/DataAsset/asset-management path;
- a `UWorldSubsystem` does not replicate by itself, so co-op state needs an authoritative replicated owner/actor/component;
- Blueprint callers must not have an unrestricted `SetMissionStateDirect` function;
- mission identity must not depend only on positional integers. Use a stable `FName MissionId`; retain `TrackingIndex` only as a secondary tooling/debug field;
- definition data and mutable runtime progress must be separate structures;
- objective progress injection is server-authoritative and rejects non-positive deltas unless a future objective type explicitly supports reversible progress;
- completion/reward signaling must be idempotent so reconnect/retry cannot duplicate rewards;
- prerequisite evaluation should collect transitions before broadcasting to avoid re-entrant mutation hazards;
- one objective event may legitimately progress more than one active mission; do not `break` after the first completed mission;
- the first example mission may use `bAutoActivate=true`; otherwise a prerequisite-free mission begins Available rather than Active;
- UMG refresh is **event-driven on the game thread**, not a background-thread UI mutation;
- dialogue nodes should carry typed mission actions, not arbitrary strings that directly mutate mission state.

## Identity and state contract

Mission identity:

`MissionId: FName` — stable authored identifier.  
`TrackingIndex: int32` — optional human/tooling index; not save or network authority.

Objective identity:

`ObjectiveId: FName` — stable objective identifier inside the mission.  
`TrackingIndex: int32` — optional tooling index.

Mission states:

`Locked → Available → Active → Completed`

A mission may also declare `bAutoActivate` and `bRequiresDialogueUnlock`.

## Data separation

Definition data is immutable authored content:

- MissionId
- title
- prerequisite MissionIds
- objective definitions
- reward definition
- auto-activation/dialogue-gate flags

Runtime data is mutable state:

- MissionId
- current mission state
- objective progress counters
- dialogue-unlocked state
- completion-handled/idempotency state

Do not write mutable progress back into a shared DataTable row.

## Authority and replication

The server/world authority owns mission mutations.

The mission tracker subsystem validates and mutates shared mission state. A replicated mission-state actor/component publishes a bounded snapshot to clients. Clients may display state and submit intent through approved server-authoritative gameplay/dialogue paths; clients do not mark missions complete locally.

Per-player/private missions require a PlayerState/profile-owned lane and should not be faked with one global world map. The first implementation may prove shared-world missions only and must state that boundary.

## UI update contract

UMG mission widgets subscribe to mission-state/progress delegates or replicated snapshot change notifications.

Do not Tick-poll mission state every frame.

UI refresh sequence:

`authoritative mission mutation → replicated/local state update → delegate/event → UMG refresh`

## Dialogue integration

Dialogue nodes use typed actions:

- UnlockMission
- AcceptMission
- AddObjectiveProgress

A dialogue action may unlock a dialogue-gated mission only when its prerequisite contract is satisfied. Free-form dialogue text is presentation, not authority.

## Reward boundary

Mission completion emits an idempotent completion/reward-ready event. Currency and inventory grants must eventually execute through their authoritative transaction services and persist a committed transaction marker.

Do not grant rewards repeatedly because the Completed state is set more than once or a connection retries.

## Sample configuration — proposal only

These rows demonstrate structure and are **not canon-name or balance locks**.

| MissionId | Tracking | Start rule | Objective examples | Reward examples |
|---|---:|---|---|---|
| `Mission_OutpostRestore` | 0 | Auto-active, no prerequisite | InteractWithNPC / `NPC_SanctuaryQuartermaster` / 1 | authored currency key + `Recipe_WoodFloor` |
| `Mission_FoundationGathering` | 1 | Requires OutpostRestore | HarvestMaterial / `Material_Wood` / 15; DefendBaseStructure / `Structure_Gate` / 1 | authored currency key + `Blueprint_FieldSafehold` |
| `Mission_DeepPurification` | 2 | Requires FoundationGathering | PurifyContamination / `Sector_CavernA` / 1 | authored currency key + approved tool/catalyst rows |

`Blueprint_KinCage` is not used as the default reward because Eco-Kin are autonomous partners and containment mechanics must remain temporary, non-coercive rescue/safety systems.

## Submitted standalone C++ processor correction

The isolated sample is not production mission identity logic. Its compile errors include:

- missing newlines between includes;
- missing `<cstdint>` for `int32_t`;
- invalid conversion from `std::string` to `char`;
- declaration/use mismatch between `CompiledIntegerMaskCode` and `CompiledIntegerTokenCode`;
- potential index mismatch if empty strings are skipped.

If retained as a toolchain exercise, use `StringIdentityToken.front()` after an emptiness check, push the same declared variable, and keep it classified as a standalone C++ smoke/example tool. Character codes are not authoritative MissionIds.

## Verification gate

The mission system remains NOT YET VERIFIED until the BUILD repository demonstrates, as applicable:

1. UHT success;
2. Development Editor compile;
3. initialization with an authored mission data source;
4. prerequisite/unlock/accept/progress/completion Automation tests;
5. server-authority rejection of client-side mutation;
6. replicated co-op snapshot behavior;
7. reconnect/save/load idempotency;
8. UMG event-driven refresh;
9. packaged runtime execution.

This mission feature must not displace the current foundation → Issue #10 → 4–6 Eco-Kin vertical-slice order unless explicitly reprioritized.
