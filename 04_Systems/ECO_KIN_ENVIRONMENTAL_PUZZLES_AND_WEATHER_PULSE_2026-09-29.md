# ECHOHEARTS: REBEARTH — ECO-KIN ENVIRONMENTAL PUZZLES & WEATHER PULSE

**Date:** 2026-09-29  
**Status:** CANON-CORRECTED SYSTEM DIRECTION / IMPLEMENTATION PENDING  
**Authority:** current Growth Rite/Earthline, Static Orchard, Event Sovereign, world-state and 125-ID Permanent Dex governance  
**Purpose:** Integrate environmental compatibility puzzles and Weather Pulse Forms without creating a capture system, forcing named Eco-Kin, mutating canonical stats cumulatively, or claiming unverified UE5.8 runtime code.

---

## 1. Governing rules

This file extends the existing Growth Rite system. It does not create a parallel evolution system.

- **Core-Binder** remains the player role.
- Eco-Kin are autonomous partners, not beasts, inventory objects or Vessel Disc contents.
- Field relationship remains **Observe → Protect → Calm → Kindle → Bond / Release / Defer**.
- Public partner attributes remain **Vibrance / Density / Harmony / Purity**.
- Weather Pulse is an identity-preserving form family already defined in the Growth Rite system.
- A weather event never creates a new Permanent Dex ID.
- Environmental puzzles must allow multiple valid team solutions and an accessibility-safe route.
- Pause, Settings, accessibility controls and truthful cooldown/health/objective UI are never part of a punishment mechanic.
- Main campaign remains real-time third-person action.

## 2. Intake code corrections

The pasted standalone C++ sample is **REFERENCE / NEEDS UE REWRITE**, not production UE5.8 code.

### Corrected errors

1. `EEcoKinForm` was referenced without being defined in the file.
2. The sample `FWeatherVector` initializer reversed pressure and temperature. Given the declared order `SystemTag, AmbientBarometricPressure, LocalThermalIndex, PulseIntensity`, the values must be `101.3f, -2.5f`, not `-2.5f, 101.3f`.
3. Weather application directly added `+25 Density` or `+35 Harmony` to the partner object. Repeated evaluation would permanently stack those bonuses. Weather Pulse must use **derived temporary modifiers or a form-state overlay**, never repeatedly mutate the canonical baseline.
4. `CurrentActiveThermalCap -= 10` had no defined unit or directionality and could make protection worse depending on interpretation. Thermal tolerance must use authored min/max operating ranges.
5. Static Orchard requirements were hard-coded into one class. Puzzle bands must be authored data so difficulty, accessibility and regional progression can be tuned without recompilation.
6. Aggregate raw stats can become exploitable when party size changes. The canonical combat context uses up to three active Eco-Kin; compatibility evaluation must account for active-slot count and authored contribution caps.
7. `std::string` player diagnostics are not the production localization path. Player-facing guidance should be represented as localized text or reason keys.
8. `std::cout` output is not runtime UI or verification evidence.
9. `"magical affinity"` is not Echohearts system terminology; use Harmony/Resonance/ecology language.
10. Weather values arriving from a client are never authoritative in multiplayer.

## 3. Static Orchard compatibility puzzle

### Canon purpose

The Static Orchard contains damaged phase-cancellation infrastructure. The Core-Binder does not solve it by matching one exact stat total or bringing one mandatory species.

The puzzle asks the active team to produce a **stable compatibility envelope** across two independent needs:

- **Harmony alignment** — enough coordinated Resonance to prevent destructive cancellation;
- **Density support** — enough structural stability to hold the temporary bridge/anchor field.

### Multiple-solution rule

A valid solution may come from:

- different Eco-Kin species;
- different role combinations;
- active A.E.G.I.S. field tools;
- environmental anchor activation;
- Sanctuary/quest upgrades already earned;
- accessibility assist that widens authored tolerance without falsifying the solution state.

Named partners such as Floauwer or Pigcasso may be authored examples if their Permanent Dex mappings are confirmed, but they are never mandatory simply because an old design packet named them.

## 4. Compatibility data contract

Recommended authored definition fields:

- `PuzzleID`
- `RegionStateID`
- `RequiredActiveSlotsMin`
- `RequiredActiveSlotsMax`
- `HarmonyBandMin`
- `HarmonyBandMax`
- `DensityFloor`
- `PerPartnerHarmonyContributionCap`
- `PerPartnerDensityContributionCap`
- `AllowedSupportToolTags`
- `AlternateSolutionTags`
- `AccessibilityBandExpansion`
- `FailureReasonKeys`
- `SuccessWorldStateTag`

The values belong in a data definition, not a hard-coded global class.

### Evaluation principle

For each eligible active partner:

1. read authoritative effective V/D/H/P state;
2. clamp contribution to the puzzle definition's authored cap;
3. apply active environmental modifiers once;
4. apply valid A.E.G.I.S./objective support modifiers;
5. evaluate the resulting Harmony band and Density floor;
6. return structured failure reasons.

A possible conceptual calculation is:

```text
HarmonyContribution_i = Clamp(EffectiveHarmony_i, 0, HarmonyContributionCap)
DensityContribution_i = Clamp(EffectiveDensity_i, 0, DensityContributionCap)

TeamHarmony = Sum(HarmonyContribution_i) + AuthorizedToolHarmony
TeamDensity = Sum(DensityContribution_i) + AuthorizedAnchorDensity

HarmonyValid = TeamHarmony >= HarmonyBandMin && TeamHarmony <= HarmonyBandMax
DensityValid = TeamDensity >= DensityFloor
PuzzleValid = HarmonyValid && DensityValid
```

This is a design contract, not a locked balance formula.

## 5. Structured A.E.G.I.S. feedback

A.E.G.I.S. should explain non-secret failure reasons clearly.

Examples:

- **Harmony below band:** “The field is under-aligned. Increase coordinated Harmony or activate an approved phase anchor.”
- **Harmony above band:** “The field is oversaturated. Reduce active Resonance output or redirect one support channel.”
- **Density below floor:** “The bridge field lacks structural support. Increase Density contribution or stabilize a nearby anchor.”
- **Environmental lock:** “The western cancellation node is still active.”
- **Success:** “Compatibility envelope stable. Temporary bridge window opened.”

No message should imply magic, capture ownership or hidden stat punishment.

## 6. Accessibility contract

The Static Orchard puzzle must remain solvable for players who cannot perform high-speed rhythm or precision visual tasks.

Approved assistance may include:

- wider compatibility bands;
- longer stabilization windows;
- stronger audiovisual/haptic telegraphs;
- reduced visual distortion;
- color-independent indicators;
- optional auto-hold once the correct solution is established;
- text/symbol diagnostics;
- alternate anchor objective route.

Accessibility settings do not change canonical story outcome quality and never secretly buff an enemy.

## 7. Weather Pulse Form — canonical behavior

A Weather Pulse Form is a temporary or semi-persistent identity-preserving expression caused by an authored environmental condition.

Examples remain:

- lightning storm;
- auroral event;
- drought;
- monsoon;
- solar flare;
- frost bloom;
- region-specific acid/sleet conditions where original Echohearts ecology supports them.

The weather system must not assume every species can express every Weather Pulse Form.

Eligibility is declared in the species/form definition.

## 8. Weather input contract

Recommended regional weather state:

- registered `WeatherTag`;
- temperature in °C;
- barometric pressure in kPa;
- humidity/precipitation where needed;
- wind vector/intensity where needed;
- anomaly intensity tier;
- world/region revision;
- source authority;
- start time / duration;
- optional contamination/Blight flags.

All numeric inputs must be finite and clamped to authored physically/gameplay-safe ranges before evaluation.

In shared play, the authoritative world/server state supplies weather. A client may render or predict presentation but cannot author a Weather Pulse transformation.

## 9. Weather Pulse definition

A species- or form-specific Weather Pulse definition should declare:

- `WeatherPulseFormID`;
- parent `EcoKinID`;
- required weather tag/query;
- allowed temperature range;
- allowed pressure range where relevant;
- minimum anomaly intensity;
- required habitat/region tags where relevant;
- minimum Kindling or story gate if appropriate;
- activation dwell time;
- deactivation dwell time / hysteresis;
- temporary V/D/H/P modifiers or reallocations;
- ability/traversal changes;
- visual/audio presentation;
- maximum duration where authored;
- cooldown/recovery behavior;
- whether the state is transient or semi-persistent;
- save/reconnect policy.

## 10. No cumulative stat mutation

Weather Pulse modifies an **effective stat layer**, not the permanent base every evaluation tick.

Conceptually:

```text
EffectiveStat = SpeciesBaseline
              + InstanceGrowth
              + KindlingContext
              + PersistentFormModifier
              + WeatherPulseModifier
              + TemporaryCombatModifier
```

When Weather Pulse ends, its modifier layer is removed.

A repeated weather evaluation does not add the same bonus again.

If a semi-persistent form is authored, its FormID/state is committed exactly once through the normal form/save transaction rather than through repeated arithmetic.

## 11. Hysteresis / anti-flicker rule

Weather conditions often cross thresholds repeatedly. Forms must not flash on/off every frame.

Use authored entry and exit conditions, for example:

- activation only after the condition remains valid for `ActivationDwellSeconds`;
- deactivation only after the condition remains invalid for `DeactivationDwellSeconds`;
- separate enter/exit temperature bands where useful;
- server-authoritative transition timestamp/revision.

## 12. Weather Pulse and Earthline distinction

Do not merge these two systems.

- **Earthline Adaptation** may represent long-term naturalistic development or acclimation.
- **Weather Pulse Form** is a weather-triggered expression layered on the existing identity.

A species may use both, one, or neither.

A temporary storm form does not automatically become a permanent biological evolution.

## 13. Sanctuary climate simulation

A later Sanctuary upgrade may simulate bounded climate conditions for **training, observation and safe acclimation research**.

It must not:

- force permanent mutation;
- bypass story/ecology Growth Rite requirements;
- create weather-only forms the species is not eligible for;
- damage partners to optimize Stress mutations;
- generate competitive advantages unavailable through normal gameplay;
- overwrite the real region's canonical weather state.

Possible uses:

- teach a known Weather Pulse trigger;
- test team composition safely;
- practice environmental abilities;
- unlock codex observations after legitimate discovery;
- help prepare for a restored-region expedition.

## 14. Save/persistence policy

### Transient Weather Pulse

Normally recompute from authoritative climate when loading/reconnecting. Do not serialize a permanent stat increase.

### Semi-persistent Weather Pulse

If specifically authored, save:

- current FormID;
- source weather/event ID;
- transition transaction/revision;
- expiration/recovery state if applicable.

### Static Orchard puzzle

Persist only meaningful world milestones such as:

- cancellation node repaired;
- bridge anchor stabilized;
- route permanently restored;
- Hushglass Warden event outcome;
- region moved from Suppressed → Recovering → Regenerated.

Do not save temporary arithmetic totals as canonical history.

## 15. Cross-platform fairness

The gameplay rules do not change simply because the player is on mobile, console or PC.

Input presentation may differ by platform, but:

- compatibility bands;
- boss damage;
- partner requirements;
- progression rewards;
- canonical outcome rules

must remain equivalent unless an explicit accessibility/difficulty setting applies consistently across platforms.

## 16. UE5.8 implementation direction

When a real Unreal project/module exists, the preferred architecture is data-driven:

- static puzzle/weather/form definitions may use `UPrimaryDataAsset`/Asset Manager patterns;
- event/weather/world labels use registered `FGameplayTag`, `FGameplayTagContainer` and `FGameplayTagQuery` rather than free-text prefix matching;
- player-facing diagnostics use localized text/reason IDs;
- world-state transitions are server-authoritative in shared play;
- save completion/failure is handled explicitly;
- repeated transition requests are idempotent.

Epic's UE5.8 Data Asset documentation confirms that Primary Data Assets provide Primary Asset IDs and asset-bundle support for Asset Manager loading/unloading. Gameplay Tags are registered hierarchical labels and support containers and queries. These are implementation references only; this repository still requires a real `.uproject` and module before any code can be called compiled or VERIFIED.

## 17. Test matrix before VERIFIED

### Static Orchard

- valid low-band solution;
- valid high-band solution;
- multiple distinct team compositions;
- under-Harmony failure;
- over-Harmony failure;
- Density failure;
- tool-assisted alternate route;
- accessibility widened band;
- one/two/three active partner handling;
- reconnect while bridge window active;
- server rejects client-forged stat/weather values.

### Weather Pulse

- eligible species activates;
- ineligible species remains baseline;
- correct weather tag but wrong temperature;
- correct temperature but wrong weather tag;
- repeated evaluation does not stack stats;
- activation/deactivation dwell prevents flicker;
- save/reload transient form recomputes correctly;
- semi-persistent form restores correctly where authored;
- weather authority is server-derived;
- missing form asset has safe fallback;
- accessibility presentation remains readable.

## 18. Verification boundary

This file defines canon/system behavior only.

It does **not** prove:

- working Static Orchard gameplay;
- compiled Weather Pulse C++;
- replicated weather;
- final balance values;
- working Sanctuary climate simulation;
- packaged UE5.8 runtime behavior.

Required evidence remains:

**Canon → Data Schema → Real UE Module → Compile/UHT → Automated Tests → Save/Reload/Network Validation → Packaged Runtime → VERIFIED.**
