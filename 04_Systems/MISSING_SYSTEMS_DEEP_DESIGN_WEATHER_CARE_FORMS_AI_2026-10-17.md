# Missing Systems — Weather, Recovery, Strain, Forms, Farming, D.A.H.L.I.A., and Combat AI
**Date:** 2026-10-17 · **Status:** Detailed integration designs for PR #71 (M06–M12); NOT compiled, not a replacement for existing M01–M20 ledger.

## Canon and branch reconciliation
Main-authority identity remains the established **Frequency Tamer / Core-Binder** labels until a reviewed and merged canon change says otherwise. Draft PR #70 explores an alternative front-facing profession and an eight-linked/one-active campaign contract; implementation must compare those staged definitions with the authoritative current master before writing macros or HUD labels. **Never treat an unmerged PR as a fully locked canon overwrite.** Eco-Kin remain autonomous, voluntary Kindling applies, public attributes remain V/D/H/P, and the nine supported Essences remain Flora/Torrent/Pyre/Terra/Aero/Glaze/Voltic/Aura/Shade.

This packet does not turn every Eco-Kin into a musical entity. Weather, VFX and relationship signals may be light, pressure, scent, temperature, movement, vibration or sound.

## M06 — Hostile AI: tactical behaviors by *source of hostility*
A universal "AttackPlayer" action is **not** the entire AI. Use one common **decision interface** with differentiated data-driven motivation. Hostile humans evaluate mission/protection/objective; machines evaluate programmed patrol/sensor/power; wild Eco-Kin evaluate threat, territory, injury, dependents and escape. Distressed living Eco-Kin retain nonviolent restoration paths.

**Blackboard input:** authoritative perceived stimuli, actor validity, target transform age, nav accessibility, shelter/cover, friendly safety, known target last location, allowed lethal/nonlethal action list, world state, Anima-Link feedback if appropriate.

**Proposed StateTree:** `Observe → EvaluateThreat → (Warn | NavigateToSafety | DefendTerritory | EngageHostile)` → `Recover/Retreat`. Branch priorities change by motivation/biology. Target loss transitions to Search or disengage; no omniscient teleport pursuit. An attack must have telegraph and cooldown separated; client VFX never authorizes damage. Do not use a nonexistent stance enum; resolve the real BUILD type before building this StateTree.

**Test:** stunned target, occluded sightline, unloaded nav cell, partner moves across firing line, target surrenders/disengages, Blight stress removed, two-player threat arbitration.

## M07 — Boss director: encounter objectives, phases and restoration
Do not replace existing boss progression. Compose a reusable **authored EncounterPhase definition**:
`PhaseID, EnterReason, ActiveObjectiveIDs, TelegraphCueIDs, SafeZoneLocatorIDs, AllowedActions, RecoveryCheckpoint, ExitReason, AwardTransactionID`.
Transitions happen on approved **objectives or guarded events** (e.g. restore a relay and survive three warning sweeps), never solely on copied damage percentages. For bosses who are Sovereign Eco-Kin, respect treatment, release and habitat repair; nonliving environmental threats can be disabled by disconnection/isolation.

**Example original first boss practice slice:** a damaged mobile pump rig threatens the Field Academy irrigation channel. Players read its repeated pressure-release tell, guard a repair technician (existing NPC registry selection), divert one safe overflow channel and disconnect the powered cutter. Success repairs water supply even if player never destroys the whole rig. This can teach ally-protection and mission-state exits while remaining separate from the campaign's canonical final opponent.

**Test:** both levers activated at once, combat party wiped after last objective, save between phase transitions, respawn/reload, noncombat shutdown, first reward delivered once.

## M08 — Shimmer Form
**StateMachine:** `Dormant → EligibleToInvite → VoluntaryReadiness → FormPreparation → ShimmerExpression → Recovery → Stable`, with `Declined`, `Interrupted`, `BlockedByUnsafeHabitat` branches. Do not create permanent Dex identities, bonus Essences or body fusion. Required gates are read from **existing Forms Registry/Growth Rite contract**, not hardcoded guessed thresholds. Record `BaseIdentityID, FormRegistryID, ConsentRevision, HabitatEvidence, GrowthRiteEvidence, WorldVersion`.

Art requirements: silhouette respects approved anatomy; rare Shimmer appearance arises from a perceptible biological/resonance state and has material/animation deltas, not just color replacement. Cooldown/recovery respects Strain and voluntariness. Offline-form proposal may be unit tested, but actual transformation/rollback needs the UE actor+save integration.

## M09 — Resonance Strain
This is a **bounded technical derived condition**, not a fifth public stat or a way to compel better performance. Sources: a distinct combat injury event, overextended remote Anima-Link activation, exceptional field exposure, risky forms. Each event has unique `DamageOrExposureEventID`, source, timestamp, condition tag and mitigation; **never** accumulate again every visual impact tick. Recovery reads existing care and rest service; free/safe recall follows current approved summoning contract. The UI describes posture and recovery need with readable cues.

**Escalation proposal:** `Stable → Fatigued → NeedsRest → CareRequired`; an Eco-Kin can refuse activity at any state, and consent is not a numeric scalar derived by the player. At `CareRequired`, player may visit **Recovery Ward / Nurse Calla** (existing story) or safe remote care if permitted. Anima-Link transmits bounded player impact costs under its real combat contract. **Do not compute strain from arbitrary int32 HP unless actual AttributeComponent API is verified.**

## M10 — Restoration Farming
**Plot lifecycle:** `Unrestored → Diagnosed → Water/SoilTreatment → Seeded → GrowthWindow → Harvestable → Regeneration`, with StormDamage, Drought and Quarantine side paths. Produce a **visible before/after** on soil coloration, stream clarity and plant growth. The player's contribution is restoring conditions, not manufacturing an automatic unlimited resource factory.

A plot is keyed by existing `WorldPlotGUID` and transaction ID; save seed registry, planted epoch, nutrient-water condition, bounded elapsed growth, approved item recipe and regional restoration contribution. Weather simulation changes the *environmental process* but must not change server UTC or allow free growth by toggling client clock. Voluntary Eco-Kin help requires aptitude/trust/health and an exit choice; forced work and predatory breeding are prohibited.

**Interaction with encounters:** clearing a blocked creek changes local Flora/Torrent resources and wild habitat profile weights after an ecological recovery window; it should **not** cause endless new spawn rolls whenever a crop is harvested.

## M11 — D.A.H.L.I.A.
D.A.H.L.I.A. is a **contextual safety, confidence and ethics companion**, not a generative backend allowed to decide world events. Architecture:
1. Ingest tagged *observations* from A.E.G.I.S. scans, story facts and hazards (read only).
2. Convert into an explanation candidate with `StatementID, FactSource, FactAge, ConfidenceCategory, NextSafeActions`.
3. Show a compact text/voice card; player may dismiss/collapse, and repetition is bounded by state revision.
4. On unavailable/unknown readings, use authored fallback and clearly label uncertainty.
5. Never mutate a relationship ledger, boss phase, actor spawn, inventory, player attribute or save directly.

**Scene example:** fog obscures a trail. D.A.H.L.I.A. says an echo trace may point toward sheltered vegetation but cannot tell which Eco-Kin made it. Player decides to investigate or help first. No invented objective or made-up entity.

## M12 — Weather, clouds and seasonal hazards
Extend existing frequency/cloud designs only **after** approved file review; do not merge conflicting drafts wholesale. Weather simulation uses `RegionId + ClimateSeed + WorldRevision + ServerEpoch + WeatherPhase`, with client visual instancing and server hazard volumes. Real weather includes rain, snow and autumn wind/leaf fall; **autumn is a seasonal condition**, not an Essence or a combat school.

| Weather condition | World cues | Actual gameplay change | Fair counter |
|---|---|---|---|
| **Warm Rain** | low gray towers, soil darkening, runoff | hydrology changes, slippery banks, Flora response | bridges and route timing; Torrent-informed scan |
| **Convective Storm** | anvil cloud, gust-line, strike forecast | region-authoritative lightning zones, exposed-device interference | grounded shelter, insulation, wait or detour |
| **Dry Autumn Front** | colorful leaf fall, cool wind, migration calls | leaf obscuration, seed drift, faster scent trail decay | ecological audio cues, markers, sheltered observation |
| **Snow Squall** | crystal cloud, visible windward buildup | traction, glacial field hazard, animal shelter behavior | thermal layer, sheltered route, safe slowdown |
| **Coastal Fog** | moving low cloud bank and hornlike resonance | limited sightline, slower ship navigation; scan source uncertainty | calibrated beacons, clear shoreline landmarks |
| **Blight Pressure Cell** | anomaly noise and irregular cloud edges | rare, authored scan interference and environmental damage | restore contaminated relay, avoid, use approved Purity care |

**No universally fixed +20% damage/−30% accuracy modifiers.** Existing Essences/V-D-H-P may influence derived hazard outcomes, but numeric balance belongs to the authoritative data dictionary, not an imported combat template. Story dangers must telegraph and never create unavoidable insta-kills.

**Encounter integration:** weather changes habitat eligibility only at the *next validated ecology tick*; a live individual shelters/migrates rather than disappearing into a new species. The storm server event is immutable and idempotent by identity/revision; offscreen cells do not tick costly cloud particles.

## Cross-system first-playable dependency proof
A winter storm begins while the player explores. A.E.G.I.S. detects a sheltered wild Eco-Kin; D.A.H.L.I.A. warns about uncertain clues. The player repairs a blocked stream route, waits for the creature to approach voluntarily, and receives a Kindling invitation. If injured, the individual is safely referred to medical care; if refusing, mission still advances. World weather clears, the repaired stream visibly flows, and save/rejoin restores one consistent outcome. This **single encounter** proves M02/M03/M04/M05/M09/M10/M11/M12/M13/M14/M18/M20 integration before expanding to multi-city combat content.

**Release gate:** design approved → BUILD implementation → actual Windows UE compile → playable scene → save/network QA → engine content/performance → publication. None is completed by creating this Markdown document.
