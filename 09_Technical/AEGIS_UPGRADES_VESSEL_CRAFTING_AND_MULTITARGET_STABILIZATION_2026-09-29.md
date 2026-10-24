# ECHOHEARTS: REBEARTH — A.E.G.I.S. UPGRADES, FIELD-TRAP CRAFTING & MULTI-TARGET STABILIZATION

**Date:** 2026-09-29  
**Status:** TECHNICAL DESIGN CONTRACT / NOT YET VERIFIED  
**Legacy filename note:** The repository path retains `VESSEL_CRAFTING` for intake traceability only. **Vessel Disc capture/storage is retired.** The implementation direction below replaces it with non-sentient field-trap components and A.E.G.I.S. stabilization hardware.

---

## 1. Intake audit

The pasted standalone C++ is a concept sketch, not production Unreal Engine code.

Critical corrections:

1. `Vessel Disc` crafting conflicts with current Eco-Kin autonomy/Havenlink canon and is retired.
2. `SpentKnowledgePoints` was accepted but never validated or deducted, so upgrades were effectively free.
3. `EVesselTier::PrimalAether` had no recipe entry and would fail at runtime without an authored diagnostic.
4. A single `PlayerInventoryMass` integer cannot prove ownership of the named material in the recipe.
5. Crafting did not perform an atomic inventory deduction/receipt transaction.
6. `CoreFrequenceHz` is misspelled and the entire universal-Hz assumption conflicts with current Resonance canon.
7. Multi-target logic used one global frequency for all individuals, which collapses authored behavior into one scalar.
8. `TrackingVarianceMitigation` could be stacked without a cap and silently widen every challenge.
9. Local vectors/maps/booleans are not persistent, replicated, authoritative or crash-safe world state.
10. `std::cout` is not UI, telemetry evidence or runtime verification.
11. Multi-target capture would violate the no-mass-capture rule. Multi-target stabilization is retained for rescue, hazard control and coordinated calming.

## 2. Replacement hardware families

### A.E.G.I.S. Field Modules

Suggested authored module families:

- `Aegis.Module.PrecisionLens` — improves readable tracking/scan fidelity for eligible encounters;
- `Aegis.Module.AnchorControl` — increases supported grounding-anchor count or placement reach;
- `Aegis.Module.HavenMesh` — enables coordinated multi-target rescue fields;
- `Aegis.Module.WeatherBaffle` — improves stability of field devices during severe weather;
- `Aegis.Module.SoftfieldControl` — improves safety envelope control and auto-release behavior;
- `Aegis.Module.EcologyScanner` — exposes known habitat/food/Heart Fruit guidance;
- `Aegis.Module.AccessibilityAssist` — player-selected interface/interaction accommodations, not a competitive power upgrade.

No module grants ownership over a sentient Eco-Kin.

## 3. Field-trap crafting replaces Vessel crafting

Crafted objects are non-sentient devices/materials such as:

- Heart Fruit Lure Cradle;
- Softfield Corral emitter;
- grounding anchor;
- Haven Mesh node;
- weather baffle;
- scent/wind marker;
- replacement scanner lens;
- field repair kit;
- non-sentient power cell.

Recommended static recipe definition:

```text
FieldRecipeID
OutputDefinitionID
RequiredMaterialStacks[]
RequiredWorkbenchTag
RequiredResearchTags
RequiredRegionStateTags
CraftTime
DurabilityPolicy
SalvagePolicy
```

Do not use a single generic `MineralMassCost` when the recipe names a specific material.

## 4. Atomic crafting transaction

A production crafting request should follow:

```text
Client requests Craft(FieldRecipeID, Quantity)
→ server validates session/workbench/recipe/research
→ server reads authoritative inventory
→ reserve exact material stacks
→ create CraftTransactionGUID
→ apply output + material deduction atomically
→ persist/replicate result
→ acknowledge to client
```

Failure must not deduct materials without granting the output.

## 5. Upgrade transaction

A.E.G.I.S. upgrades require authored costs and prerequisite validation.

Recommended definition:

```text
UpgradeNodeID
ModuleTag
PrerequisiteNodeIDs[]
RequiredResearchTags
KnowledgeCost
MaterialCosts[]
MutualExclusionTags[]
MaxRank
EffectDefinitionID
```

Runtime request:

```text
Request upgrade
→ validate authority
→ verify node exists and not already maxed
→ verify prerequisites
→ verify Archive Knowledge/materials
→ reserve costs
→ commit upgrade transaction
→ persist
→ replicate module state
```

Never accept a `SpentKnowledgePoints` argument and trust the client to have spent it.

## 6. Multi-target stabilization

### Purpose

Multi-target stabilization is for:

- evacuation of a herd/flock;
- calming multiple frightened Eco-Kin during a disaster;
- separating several Blight-distorted individuals from a shared source;
- maintaining several safe corridors during an Event Sovereign encounter;
- coordinated Sanctuary intake;
- environmental rescue.

It is **not** a mass-bond/mass-capture mechanic.

### Per-target profiles

Each target keeps an authored/runtime interaction state:

```text
TargetInstanceID
StabilizationProfileID
BehaviorState
StressState
SafetyState
ContributionProgress
ReleaseRequired
RescueDestinationID (optional)
```

The shared field may supply support, but each individual is evaluated independently.

## 7. No universal frequency scalar

Replace:

```text
CoreFrequencyHz
GlobalInputFrequency
```

with profile-driven requirements such as:

```text
MovementEnvelope
AnchorRequirement
HarmonyBand
DensitySupport
SpatialTolerance
WeatherTolerance
LineOfSightRequirement
TimingWindow
AllowedAegisToolTags
HeartFruitPreferenceTag
```

A specialist Echo/acoustic encounter may legitimately use frequency in Hz. That is encounter data, not universal Eco-Kin biology.

## 8. Heart Fruit integration

The Ecology Scanner module may expose already-known Heart Fruit guidance:

- preferred placement distance;
- known scent sensitivity;
- weather/wind effect;
- whether the individual has previously accepted Heart Fruit;
- safe waiting distance;
- whether a lure cradle is recommended.

Accessibility mode may display this guidance more clearly and widen placement/timing tolerances where appropriate.

No A.E.G.I.S. upgrade converts Heart Fruit into a guaranteed Bond.

## 9. Safety and auto-release

Every temporary field device capable of constraining movement needs an authored **Release Policy**.

Recommended fields:

```text
ReleasePolicyID
MaximumHoldSeconds
StressAbortThreshold
HazardClearAutoRelease
PlayerManualReleaseAllowed
EmergencyMedicalException
DisconnectPolicy
OwnerLeavesRegionPolicy
```

Required invariant:

> A player disconnect, crash or region unload must never leave a sentient Eco-Kin permanently trapped by stale runtime state.

## 10. Multiplayer authority

Client sends intent only:

```text
place trap
place anchor
activate module
offer Heart Fruit
open release
request rescue transfer
```

Server/world authority validates:

- inventory/device ownership;
- placement bounds;
- protected-zone rules;
- target/world state;
- cooldown/energy;
- active trap limits;
- accessibility profile where relevant;
- release policy;
- transaction/replay identity.

## 11. Suggested Unreal-facing data ownership

Static authored data may later use Primary Data Assets or equivalent authored assets for:

- field-trap definitions;
- upgrade definitions;
- Heart Fruit profiles;
- stabilization profiles;
- release policies.

Runtime/persistent state belongs in versioned authoritative save/world ledgers rather than static assets.

## 12. Test requirements

Once a real UE5.8 module exists, add automated tests/specs for at minimum:

1. upgrade cannot unlock without paying authoritative cost;
2. duplicate upgrade request is idempotent;
3. invalid recipe does not deduct inventory;
4. successful recipe deducts exact stacks once;
5. multi-target rescue does not automatically Bond any target;
6. Heart Fruit can open an approach window but cannot bypass refusal;
7. Softfield stress threshold triggers release;
8. disconnect/region unload releases or safely recovers active traps;
9. replayed network request cannot duplicate output;
10. Archive simulation cannot mutate canonical trap/relationship state.

## 13. Verification boundary

This file does not establish compiled A.E.G.I.S. modules, crafting, multiplayer, SaveGame integration or automated test results.

Status remains **NOT YET VERIFIED** until real `.uproject`/Source code, UHT/compile, automated tests, save/reload, network authority, packaging and runtime evidence exist.
