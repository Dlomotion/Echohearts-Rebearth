# ECHOHEARTS: REBEARTH — TECTONIC ALIGNMENT & RESTORATION BLOOM MATRIX

**Date:** 2026-09-29  
**Status:** CANON-CORRECTED SYSTEM DIRECTION / IMPLEMENTATION PENDING  
**Purpose:** Reconcile land-shelf stabilization and Restoration Bloom progression into authored regional world state without hard-coded universal thresholds or false runtime verification.

---

## 1. Scope correction

Not every region of Rebearth is a floating land shelf.

Tectonic/levitating shelf mechanics apply only to authored regions where the world and story support them, including Anchorfall-style fracture shelves, selected Sky Island approaches, Chrono-Rift scars and other explicitly designated unstable masses.

The system does not globally convert the planet into a single floating-block sandbox.

## 2. Intake code errors

The pasted standalone sample is **REFERENCE / NEEDS UE REWRITE**.

Corrections:

1. `FBloomRitePrerequisite` defines only `bMilestoneAchieved`; the sample writes `Prereq.bIsUnlocked`, which would not compile.
2. Milestones such as `Morrowmire.Purity.Restored_Above_50` are encoded as free-text logic. Production requirements should use authored IDs/tags and world-state queries.
3. `MaxAllowedDisplacementError = 0.5f` is a local hard-coded constant rather than authored per-region tolerance.
4. `CoreThermalPressureBar` is never used.
5. A local `bool bAnchorsLocked` cannot represent authoritative anchor health, count, transaction revision or network state.
6. A single successful function call must not write permanent world truth without persistence/recovery.
7. Unlocking a Restoration Bloom Rite should create **eligibility** for authored species/forms; it must not globally upgrade every local Eco-Kin.
8. Failure should not silently delete major content unless that permanent consequence is deliberately authored, telegraphed and tested.
9. `std::cout` is not gameplay UI or evidence.

## 3. Tectonic region state

Recommended regional fields:

```text
RegionStateID
TectonicProfileID
WorldRevision
DisplacementVector
DriftVelocity
AnchorNetworkState
AnchorIntegrityByID[]
ThermalPressure
RiftPressure
WeatherLoad
CivilianRisk
HabitatRisk
RecoveryState
LastCommittedTransactionGUID
```

The exact units and tolerances belong to the `TectonicProfileID` definition.

## 4. Tectonic stability states

Recommended state family:

```text
Stable
Strained
Drifting
Critical
EmergencyHeld
Recovering
Restored
```

Avoid using only `true/false` anchor state for a complex regional system.

## 5. Alignment gameplay loop

A regional stabilization mission can use:

**Detect → Survey → Secure evacuation routes → Restore/replace anchors → Apply ballast/field support → Reduce drift → Verify habitat safety → Persist world revision → Monitor.**

Possible player actions:

- repair damaged anchor pylons;
- deploy temporary A.E.G.I.S. grounding anchors;
- restore power to an ancient stabilizer;
- relocate wildlife from a failing shelf edge;
- redirect water/mass distribution;
- use an eligible Eco-Kin traversal/restoration role;
- clear Blight from an anchor root;
- coordinate Reclamation Cohorts;
- choose between fast emergency stabilization and slower ecological repair.

## 6. Failure philosophy

Failure should generate gameplay rather than arbitrary deletion.

Examples:

- route temporarily closes;
- habitat shifts;
- migration pressure rises;
- rescue mission becomes available;
- new temporary access route is required;
- restoration cost increases;
- a settlement relocates;
- a future U.N.I.T.Y. support route becomes weaker.

Permanent destruction is reserved for specifically authored story decisions/events with clear warning and recovery implications.

## 7. Restoration Bloom Rite

A **Restoration Bloom Rite** becomes eligible when the player restores a species' ecological niche or relationship to the region.

It is not simply `Purity > 50`.

Possible authored prerequisites:

- Event Sovereign outcome;
- wetland/forest/reef restoration milestone;
- migration corridor reopened;
- regional food source returned;
- pollinator network recovered;
- Blight source removed;
- Sanctuary population stabilized;
- Kindling threshold;
- species-specific life stage;
- season/weather requirement;
- story permission.

## 8. Data-driven requirement sets

Recommended definition:

```text
RestorationBloomRiteID
ParentEcoKinID
ResultFormID or GrowthRiteID
RequirementSetID
RequiredWorldStateTags
RequiredEventOutcomeTags
RequiredHabitatMetrics
RequiredKindlingRange
RequiredSeasonWeatherTags
RequiredNonSentientCatalysts[]
PermanentOrReversible
```

A region may satisfy the habitat portion for several species without automatically granting every Rite.

## 9. Milestone transaction

A milestone completion should follow:

```text
objective resolved
→ server/world authority validates outcome
→ create milestone transaction GUID
→ update regional world state/revision
→ persist
→ evaluate affected authored RequirementSets
→ expose newly eligible rites in A.E.G.I.S.
```

Eligibility does not automatically perform a Growth Rite.

## 10. A.E.G.I.S. guidance

For a known Restoration Bloom Rite, A.E.G.I.S. should explain:

- which habitat milestone remains incomplete;
- where the relevant region is;
- whether the blocking condition is story, ecology, season, Kindling or catalyst-related;
- current progress;
- whether the Rite is permanent or reversible.

Do not force players to consult external guides for ordinary progression.

## 11. Morrowmire example

The Morrowmire example may use an authored requirement set such as:

```text
EventOutcome.Morrowmire.Stabilized
Ecology.Morrowmire.WaterSafe
Ecology.Morrowmire.RootNetworkRecovered
Ecology.Morrowmire.NativeFoodWebRecovered
```

Exact thresholds remain tuning data.

No generic `Purity > 50` string is canonically required unless a later authored profile explicitly uses it.

## 12. Anchorfall / Basalith connection

The Basalith Warden's **Anchorfall** event is a strong candidate for the first proof of this system because it already connects:

- land-shelf drift;
- external anchors;
- ecological risk;
- a non-kill Sovereign resolution;
- persistent world consequence.

Implementation still follows Event Sovereign transaction rules:

**validate → durably reserve → spawn → resolve → persist outcome/world delta → reward/archive.**

## 13. Vertical-slice boundary

Do not build a planet-wide tectonic simulation before the core slice works.

First proof should include only:

- one unstable shelf/region;
- 2–4 anchor nodes;
- one visible drift/stability variable;
- one evacuation/ecology consequence;
- one restoration state change;
- save/reload;
- clear before/after scenery.

## 14. Verification boundary

This document does not prove world streaming, physics, save transactions, Event Sovereign integration or Growth Rite execution.

Status remains:

**System design → Data definitions → UE implementation → Automated tests → Save/reload/package/runtime evidence → VERIFIED.**
