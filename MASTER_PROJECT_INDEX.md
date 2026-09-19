# ECHOHEARTS: REBEARTH — MASTER PROJECT INDEX

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

## Heart Statement
Echohearts becomes great when players feel three things:
1. This world needs me.
2. These Eco-Kin are alive.
3. My choices changed Rebearth.

## Source-of-Truth Rule
All new Echohearts work routes into this workflow. No duplicate canon, duplicate Dex, duplicate GDD, duplicate technical runtime, duplicate public website data source, or parallel art pipeline.

## Current Project Pillars
- Living planet restoration.
- Autonomous Eco-Kin with agency.
- Sanctuary rebuilding and Havenlink care networks.
- Wild tracking, rescue, combat, and exploration.
- Real-time Keeper combat, with Harmony Circuit/EchoDeck for turn-based simulation.
- Player choices visibly change Rebearth.

## Production Runtime
- Unreal Engine 5.8 is the sole production game-runtime target.
- Godot, Unity, and standalone code examples may be studied only as references, not maintained as parallel implementations.
- Prefer Data Assets/Data Tables, Gameplay Tags, Blueprint configuration, and UI specifications before adding unnecessary C++.

## Public Website Runtime
- The public project website lives under `/web`.
- Website stack: Next.js App Router, React, TypeScript, and Tailwind CSS v4.
- Public Eco-Kin cards and profiles must render from structured data rather than duplicate hard-coded JSX records.
- Public pages must distinguish `CANON`, `APPROVED-PENDING`, and `IN DEVELOPMENT` material.
- Unverified game-engine claims must not be presented publicly as completed features.

## Folder Routing
- `00_Canon_Lock`: finalized rules, protected terms, no-capture/no-fusion/no-selling laws.
- `01_Game_Bible`: full GDD, tone, player loop, region structure.
- `02_EcoKin_Dex`: Eco-Kin entries, behavior, stats, art notes.
- `03_Story_Missions`: chapters, missions, dialogue, cutscenes.
- `04_Systems`: gameplay systems, progression, seasons, Havenlink, Sanctuary.
- `05_Items_Economy`: item ledgers, crafting, resources, rewards.
- `06_UI_UX`: Journey Journal, A.E.G.I.S. quick wheel, HUD, menus.
- `07_Art_Animation`: visual identity, animation priorities, art QC.
- `08_Technical`: implementation notes, data architecture, Unreal tasks, code-intake audits, transaction contracts.
- `09_QA_Playtests`: testing plans, survey answers, improvement ratings.
- `10_Marketing_Publication`: pitch, creator strategy, store-page language, public website product specifications.
- `11_Daily_Assignments`: daily task board and review packets.
- `99_Reference_Retired_Needs_Redesign`: retired terms and incompatible drafts.
- `web`: public Next.js website implementation.

## Current Technical Authority Chain
`owned request → server validation → atomic commit → authoritative event ID → replication/save/progression → local presentation`

For building/crafting, the expanded contract is:
`owned request → server validation → inventory reservation → ecological/world veto → atomic commit → authoritative event ID → replication → asynchronous persistence → local presentation`

## Current Technical Documents
- `08_Technical/BCT-001_BUILDING_CRAFTING_TRANSACTION_CONTRACT.md`
- `08_Technical/CHAT_CODE_INTAKE_AUDIT_2026-09-19.md`

## Current Website Documents
- `10_Marketing_Publication/WEBSITE_ECOKIN_BESTIARY.md`
- `web/app/page.tsx`
- `web/app/eco-kin/page.tsx`
- `web/app/eco-kin/[slug]/page.tsx`
- `web/components/EcoKinExplorer.tsx`
- `web/data/ecoKin.ts`

## Current Technical Execution Order
1. Build `EchoheartsEditor` under UE 5.8.
2. Run `Echohearts.Partners.CommandBuffer`.
3. Test reload/recovery at 150/250/350 ms.
4. Implement `ECO-API-001`.
5. Implement the smallest `BCT-001` reservation/commit/rollback kernel.

These steps remain NOT YET VERIFIED until evidence is produced from the actual Unreal project.

## Current Website Execution Order
1. Install `/web` dependencies.
2. Run the production build.
3. Test `/`, `/eco-kin`, and every seeded profile route.
4. Run keyboard, reduced-motion, mobile-width, and empty-filter-state QA.
5. Replace seed records with exported authoritative EcoDex data once that source is available in-repo.

Website runtime/build status remains NOT YET VERIFIED until install/build/browser evidence exists.

## Production Rule
Every new asset, system, mission, Eco-Kin, item, UI feature, story beat, art concept, animation, website feature, or code change must:
1. identify its target folder,
2. declare its canon status,
3. list dependencies,
4. state a player-experience reason,
5. include QA criteria,
6. avoid duplicate systems,
7. remain NOT YET VERIFIED until evidence exists.
