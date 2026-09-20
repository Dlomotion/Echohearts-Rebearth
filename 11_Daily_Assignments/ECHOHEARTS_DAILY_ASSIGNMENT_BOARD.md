# Echohearts Daily Assignment Board

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

## Daily Production Rule
Every work session should produce at least:
- one concrete game/story/design deliverable, and
- one concrete engineering/technical/QA deliverable when relevant.

Nothing is marked VERIFIED without evidence.

## Current Priority Queue
### P0: Player Clarity
- Define the first 30 minutes of gameplay.
- Finalize A.E.G.I.S. Quick Wheel behavior.
- Simplify Journey Journal routing.
- Confirm mission objective readability.

### P0: Living Eco-Kin
- Build first 10 Eco-Kin behavior sheets.
- Require calm, fear, and defensive animation states.
- Add flee, warn, hide, protect-young, watch, and approach behavior where appropriate.

### P0: World Response
- Define visible restoration delta for first playable region.
- Track persistent world-state flags.
- Connect region recovery to NPC/Eco-Kin reactions.

### P0: Technical Engine Gate
Current execution order is fixed until evidence changes it:
1. Build `EchoheartsEditor` under Unreal Engine 5.8.
2. Run `Echohearts.Partners.CommandBuffer`.
3. Test the reload/recovery marker at 150/250/350 ms plus travel, reconnect and late join.
4. Implement `ECO-API-001`, the shared authoritative ability/transaction event contract.
5. Implement the smallest `BCT-001` reservation/commit/rollback kernel.

Do not skip directly into large gameplay modules before these gates pass.

### P1: Resonance Kit / Shard-Arc Integration
Use:
- `02_EcoKin_Dex/RESONANCE_KIT_SHARD_ARC_CANON_INTAKE.md`
- `04_Systems/RESONANCE_SHARD_ARC_ADAPTATION_SYSTEM.md`
- `11_Daily_Assignments/RESONANCE_KIT_SHARD_ARC_ASSIGNMENTS.md`
- `99_Reference_Retired_Needs_Redesign/RESONANCE_MUTATION_LEGACY_NAME_AND_SYSTEM_AUDIT.md`

Current lock: Resonance Kit remains the adaptive star-furred fox-like Eco-Kin baseline with `Frequency Shift`. Resonance Shards feed the existing Growth Rite/forms structure through **Shard-Arc Adaptation**. Do not create a duplicate forced-evolution system.

Assignments:
1. `EH-EK-RKIT-001` Base Canon Lock: classification, scale, body plan, current twelve-element treatment, Frequency Shift behavior and first-story placement.
2. `EH-EK-RKIT-002` Shard Family Audit: Vineshard, Cinderstone/Ashpulse, Tide-Pearl/Boilreef, Static-Core/Oilstatic and Void-Glass/Voidglitch.
3. `EH-EK-RKIT-003` Branch Form Review: Sylva-Lynx, Flarevane, Aqua-Drift, Volt-Shifter and Umbra-Soul.
4. `EH-EK-RKIT-004` Growth Rite / Consent Rules: proceed, defer, refuse, unstable, specialist intervention and Discordance warnings.
5. `EH-EK-RKIT-005` A.E.G.I.S. UI: compatibility, willingness, Harmony, Purity, biome readiness and accessibility.
6. `EH-EK-RKIT-006` Persistence & Multiplayer Contract: permanent EcoKinID continuity, form state, authority, reconnect, save migration and idempotency.
7. `EH-EK-RKIT-007` Legacy Line Triage: Iron-Spark/Ferrumwarden/Magnetarion Ward; Botan-Bug/Grove-Beetle/Canopyrex; Stone-Treader/Basalt-Crusher/Magmaweld Golem; Aether-Wisp/Aetherwing Seraphin/Aurelior Prime.
8. `EH-EK-RKIT-008` Playtest: confirm players understand Shards as place-memory catalysts rather than coercive evolution items.

Hard rules:
- no thirteenth core element from old `Null-Aether`/Light/Dark/etc. labels,
- no forced mutation/evolution,
- no player/Eco-Kin fusion,
- no raw Blight growth/crafting,
- no 'living battery' or forced-work framing,
- every branch must change world/traversal/restoration gameplay, not only stats.

### P1: Pupular Canon & Character Integration
Use:
- `02_EcoKin_Dex/PUPULAR_CHAOS_WOOF_CANON_INTEGRATION.md`
- `07_Art_Animation/PUPULAR_VISUAL_REFERENCE_AND_QA.md`
- `99_Reference_Retired_Needs_Redesign/CHAOS_WOOF_LEGACY_PROPOSAL.md`

Current lock: `Chaos Woof → Pupular`. Do not create a second Chaos Woof species.

Assignments:
1. `EH-EK-PUP-001` Canon Classification: class, twelve-element typing, EcoDex ID, habitat, ecology, combat/world role.
2. `EH-EK-PUP-002` Visual Identity Sheet: front/side/back, scale, expressions, material notes, anatomy QC, franchise-ready key pose.
3. `EH-EK-PUP-003` Behavior Sheet: calm, curious, fear, defensive, social, Sanctuary, urban, recovery states.
4. `EH-EK-PUP-004` Gameplay Integration: one world interaction, one combat role, one restoration use, one Sanctuary interaction, one quest consequence.
5. `EH-EK-PUP-005` QA: originality, silhouette, element readability, naming, animation feasibility, accessibility, duplicate-role risk.

Legacy Reverb/Shadow-Sound/Neon Drift/Wooflet-Chaos Howler/CW-004 material remains PROPOSAL until these reviews resolve it.

### P1: Leonix Canon & Character Integration
Use:
- `02_EcoKin_Dex/LEONIX_CANON_INTEGRATION.md`
- `07_Art_Animation/LEONIX_VISUAL_REFERENCE_AND_QA.md`
- `99_Reference_Retired_Needs_Redesign/LEONIX_LEGACY_CARD_PROPOSALS.md`

Current lock: **LEONIX**. Original artwork remains primary visual reference. Preserve the celestial/prismatic lion-warrior baseline while reviewing unapproved generated-card details.

Assignments:
1. `EH-EK-LEO-001` Canon Classification: lock class, Guardian status, current twelve-element typing, EcoDex ID, habitat, ecology, and story function.
2. `EH-EK-LEO-002` Visual Identity Sheet: front/side/back, scale, wing-fold and full-spread poses, crown/face detail, tail/energy structure, material notes, anatomy QC, hero pose.
3. `EH-EK-LEO-003` Behavior Sheet: calm, watchful, warning, defensive, protective, injured, recovery, social, flight, landing, landmark interaction, and player-recognition states.
4. `EH-EK-LEO-004` Combat & World Role: one frontline guardian role, one protective ability family, one traversal/world interaction, one restoration interaction, and one major story consequence.
5. `EH-EK-LEO-005` QA: originality, silhouette, wing/anatomy consistency, element readability, naming, VFX accessibility, animation feasibility, Guardian-agency compliance, and overlap risk with Nature/Sol-Spectra/other high-order guardians.

Generated-card `Cosmic`, `Spirit`, `Celestial Humanoid-Kin`, exact measurement/weight, Mythic rarity, origin and signature-ability details remain PROPOSAL or REJECTED DATA until these reviews resolve them. `Light-aligned` is a continuity descriptor pending mapping through the current twelve-element system, not a new core element.

### P1: Historical Eco-Kin Batch Reconciliation
Use:
- `02_EcoKin_Dex/HISTORICAL_BATCH_INTAKE_MANIFEST_2026-09-19.md`
- `99_Reference_Retired_Needs_Redesign/ECO_KIN_BATCH_COLLISION_AND_LEGACY_AUDIT.md`
- `07_Art_Animation/HISTORICAL_BATCH_ART_RECOVERY_QUEUE.md`

The historical `Eco-Kin Creation Batch` archive is source/proposal material only. Do not promote batch numbers as EcoDex IDs and do not create a second roster.

Assignments:
1. `EH-EK-BATCH-001` Build a one-row-per-historical-name intake table with source batch, proposed body plan, habitat, old element labels, role, image-reference availability, and current status.
2. `EH-EK-BATCH-002` Resolve name collisions beginning with Veripaw, Verithorn, Aerowisp, Shadowfin/Shadowlurk, Glacifin/Frosttusk, Luminix/Lumoray, Solarion/Solrider, and Stonequill.
3. `EH-EK-BATCH-003` Map valid old element labels into the current twelve-element system without creating new core elements.
4. `EH-EK-BATCH-004` Audit `Chil-Kin → Mega Kin → Ultimate Kin`, Ancient-DNA, mutation, and evolution wording against current Growth Rite/forms and agency rules.
5. `EH-EK-BATCH-005` Flag repeated ecological roles and Legendary inflation so each surviving Eco-Kin has a distinct reason to exist.
6. `EH-EK-BATCH-006` Recover art only for active review targets, then run anatomy, artifact, originality/IP, silhouette, element-readability, accessibility, and animation-feasibility QA.
7. `EH-EK-BATCH-007` Assign permanent EcoKinID/EchoprintID only after canon approval.
8. `EH-EK-BATCH-008` For each reviewed entry, record exactly one result: CANON, APPROVED-PENDING, MERGED/RENAMED, RETIRED/REFERENCE-ONLY, or REJECTED.

Do not let this archive intake generate hundreds of new production tasks at once. Process bounded groups and preserve review evidence.

### P1: First Playable Slice
- Chapter 1 opening flow.
- First Eco-Kin rescue/bond decision.
- First Sanctuary restoration interaction.
- First wild tracking mission.
- First visible before/after world change.

### P1: Building/Crafting Vertical Slice
After the Technical Engine Gate:
- Create one approved BuildPiece definition.
- Create one approved CraftRecipe definition.
- Implement one authoritative reservation/commit/rollback path.
- Add placement/crafting UI feedback.
- Add ecological veto feedback.
- Prove no duplicate spend/output under request retry.
- Persist and reload the committed result.

### P1: Mini-Game Vertical Slice
Use `04_Systems/MINIGAME_PRODUCTION_TRACK.md`.
Priority order:
1. `MG-001 A.E.G.I.S. Signal Trace`
2. `MG-002 Kindling Rhythm`
3. `MG-003 Purity Flow`

For each mini-game:
- define input and tutorial flow,
- define success, partial and failure states,
- define accessibility and reduced-motion/audio alternatives,
- define rewards and anti-exploit limits,
- define save/data hooks,
- define multiplayer authority if any,
- define the visible world/story consequence,
- choose Data/Blueprint vs C++ based on actual need,
- keep NOT YET VERIFIED until played in the real UE 5.8 project.

### P1: Rendering / Presentation
Use `08_Technical/UNREAL_RENDERING_INTEGRATION_PLAN.md`.
First proof target:
- one Vespera/Whispering Glade damaged state,
- one restoration event,
- material/Niagara/lighting/Data Layer transition,
- Eco-Kin/NPC reaction,
- save/reload persistence,
- GPU/profile/scalability evidence.

### P1: Legacy Prototype Intake
Use `08_Technical/UNITY_PROTOTYPE_INTAKE_AUDIT_2026-09-19.md`.
- Keep Unity/C# and generic C++ prototypes reference-only.
- Translate useful intent into Unreal-native Subsystems, ActorComponents, Enhanced Input, UMG/CommonUI, Gameplay Tags, delegates and authoritative requests.
- Do not port direct client item mutation, fake deterministic tick claims, OnGUI tooling, global tag searches, singleton overreach, unguarded development commands or unsupported security/network claims.

### P1: Technical Hygiene
- Inspect repository before adding unnecessary C++.
- Prefer Data Assets/Data Tables, Gameplay Tags, Blueprint configuration, and UI specs when sufficient.
- Keep Unreal Engine 5.8 as the sole production runtime.
- Do not maintain parallel Godot/Unity implementations.
- Reject copied outside-game code, identities, item catalogs, and game-specific naming.
- Keep capture spheres/cages/forced work/forced evolution out of active runtime.
- Document compile, test, profile, multiplayer, persistence, rendering and regression evidence.

### P1: Public Website
- Keep the Eco-Kin Bestiary data-driven.
- Distinguish CANON, APPROVED-PENDING and IN DEVELOPMENT.
- Do not advertise unverified engine/network/rendering features as completed.
- Reuse authoritative Eco-Kin data rather than duplicating public-site values.

## Current Technical Documents
- `08_Technical/BCT-001_BUILDING_CRAFTING_TRANSACTION_CONTRACT.md`
- `08_Technical/CHAT_CODE_INTAKE_AUDIT_2026-09-19.md`
- `08_Technical/UNITY_PROTOTYPE_INTAKE_AUDIT_2026-09-19.md`
- `08_Technical/UNREAL_RENDERING_INTEGRATION_PLAN.md`
- `04_Systems/MINIGAME_PRODUCTION_TRACK.md`
- `04_Systems/RESONANCE_SHARD_ARC_ADAPTATION_SYSTEM.md`

## Assignment Template
### Assignment ID
`EH-AREA-###`

### Goal
What player-facing problem are we solving?

### Target Folder
Which official project folder owns the work?

### Dependencies
What existing systems/content does it depend on?

### Deliverable
What concrete file, asset, data row, mission, test, or implementation should exist afterward?

### Acceptance Criteria
- [ ] Strengthens at least one Heart Statement pillar.
- [ ] Does not violate canon.
- [ ] No duplicate system created.
- [ ] UI/player feedback defined.
- [ ] Persistent consequence defined when applicable.
- [ ] QA/test method defined.
- [ ] Verification status stated accurately.

## Heart Statement Check
Before closing any assignment, answer:
1. How does this make the player feel the world needs them?
2. How does this make Eco-Kin feel alive?
3. How does this prove the player's choices changed Rebearth?
