# ECHOHEARTS: REBEARTH — MASTER PROJECT INDEX

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

## Heart Statement
Echohearts becomes great when players feel three things:
1. This world needs me.
2. These Eco-Kin are alive.
3. My choices changed Rebearth.

## Source-of-Truth Rule
All new Echohearts work routes into this workflow. No duplicate canon, duplicate Dex, duplicate GDD, duplicate technical runtime, duplicate mini-game project, or parallel art pipeline.

## Current Project Pillars
- Living planet restoration.
- Autonomous Eco-Kin with agency.
- Sanctuary rebuilding and Havenlink care networks.
- Wild tracking, rescue, combat, and exploration.
- Real-time Keeper combat, with Harmony Circuit/EchoDeck for turn-based simulation.
- Player choices visibly change Rebearth.
- Mini-games reinforce the main story/systems rather than existing as disconnected filler.

## Production Runtime
- Unreal Engine 5.8 is the sole production runtime target.
- Godot, Unity, and standalone code examples may be studied only as references, not maintained as parallel implementations.
- Prefer Data Assets/Data Tables, Gameplay Tags, Blueprint configuration, UMG/CommonUI, Niagara/material authoring, and UI specifications before adding unnecessary C++.

## Folder Routing
- `00_Canon_Lock`: finalized rules, protected terms, no-capture/no-fusion/no-selling laws.
- `01_Game_Bible`: full GDD, tone, player loop, region structure.
- `02_EcoKin_Dex`: Eco-Kin entries, behavior, stats, art notes.
- `03_Story_Missions`: chapters, missions, dialogue, cutscenes.
- `04_Systems`: gameplay systems, progression, seasons, Havenlink, Sanctuary, integrated mini-games.
- `05_Items_Economy`: item ledgers, crafting, resources, rewards.
- `06_UI_UX`: Journey Journal, A.E.G.I.S. quick wheel, HUD, menus.
- `07_Art_Animation`: visual identity, animation priorities, art QC.
- `08_Technical`: implementation notes, data architecture, Unreal tasks, code-intake audits, transaction contracts, rendering integration.
- `09_QA_Playtests`: testing plans, survey answers, improvement ratings.
- `10_Marketing_Publication`: pitch, creator strategy, store-page language, public website planning.
- `11_Daily_Assignments`: daily task board and review packets.
- `99_Reference_Retired_Needs_Redesign`: retired terms and incompatible drafts.

## Current Technical Authority Chain
`owned request → server validation → atomic commit → authoritative event ID → replication/save/progression → local presentation`

For building/crafting, the expanded contract is:
`owned request → server validation → inventory reservation → ecological/world veto → atomic commit → authoritative event ID → replication → asynchronous persistence → local presentation`

## Current Technical Documents
- `08_Technical/BCT-001_BUILDING_CRAFTING_TRANSACTION_CONTRACT.md`
- `08_Technical/CHAT_CODE_INTAKE_AUDIT_2026-09-19.md`
- `08_Technical/UNITY_PROTOTYPE_INTAKE_AUDIT_2026-09-19.md`
- `08_Technical/UNREAL_RENDERING_INTEGRATION_PLAN.md`
- `04_Systems/MINIGAME_PRODUCTION_TRACK.md`

## Legacy/Prototype Intake Rule
Unity/C#, generic C++, copied cross-franchise examples, direct client inventory mutation, fake deterministic tick claims, OnGUI debug panels, global tag searches, unguarded dev commands, and unsupported secure/complete/zero-desync claims are reference-only until audited. Useful concepts must be translated into Unreal-native Subsystems, ActorComponents, Enhanced Input, UMG/CommonUI, Gameplay Tags, delegates, authoritative requests, Automation tests and development-only diagnostics.

## Rendering Rule
Use Unreal Engine 5.8 rendering systems first: authored materials/material instances, Niagara, lighting, post-process, animation, World Partition/Data Layers, scalability settings and profiling. Do not build a custom renderer unless project evidence demonstrates a requirement. STARZ* remains a presentation language, not a separate core element.

## Mini-Game Rule
Mini-games live inside the main workflow. They must reinforce A.E.G.I.S., Kindling, restoration, purification, Living Soil, Sanctuary care, crafting, traversal, Resonance puzzles, seasonal ecology, EchoDeck, Academy training or ethical Arena simulation. Each mini-game must define input, onboarding, success/failure, accessibility, rewards, save/data hooks, anti-exploit constraints, authority rules, replayability, world consequence and an Unreal implementation path.

## Current Technical Execution Order
1. Build `EchoheartsEditor` under UE 5.8.
2. Run `Echohearts.Partners.CommandBuffer`.
3. Test reload/recovery at 150/250/350 ms plus travel/reconnect/late-join cases.
4. Implement `ECO-API-001`.
5. Implement the smallest `BCT-001` reservation/commit/rollback kernel.
6. Prove one BuildPiece and one CraftRecipe end to end.
7. Begin the first playable mini-game slice only through the approved shared authority/data paths.

These steps remain NOT YET VERIFIED until evidence is produced from the actual Unreal project.

## Production Rule
Every new asset, system, mission, Eco-Kin, item, UI feature, story beat, art concept, animation, mini-game, website feature, or code change must:
1. identify its target folder,
2. declare its canon status,
3. list dependencies,
4. state a player-experience reason,
5. include QA criteria,
6. avoid duplicate systems,
7. remain NOT YET VERIFIED until evidence exists.
