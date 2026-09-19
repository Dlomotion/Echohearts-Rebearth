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
3. Test the reload/recovery marker at 150/250/350 ms.
4. Implement `ECO-API-001`, the shared authoritative ability/transaction event contract.
5. Implement the smallest `BCT-001` reservation/commit/rollback kernel.

Do not skip directly into large gameplay modules before these gates pass.

### P0: Public Website / Eco-Kin Bestiary
- Install dependencies for `/web`.
- Run `npm run build` and record evidence.
- Validate the home page, `/eco-kin`, and every current `/eco-kin/[slug]` route.
- Verify search by canonical name, EcoKinID, and habitat.
- Verify filters for element, status, and classification.
- Test keyboard navigation, focus visibility, reduced motion, 320px mobile width, and empty-result recovery.
- Keep numeric V/D/H/P values hidden until source data explicitly contains approved values.
- Keep canon-status labels visible so development material cannot be mistaken for locked canon.
- Replace seed roster records with an authoritative in-repo EcoDex export when available.

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

### P1: Technical Hygiene
- Inspect repository before adding unnecessary C++.
- Prefer Data Assets/Data Tables, Gameplay Tags, Blueprint configuration, and UI specs when sufficient.
- Keep Unreal Engine 5.8 as the sole production game runtime.
- Do not maintain parallel Godot/Unity implementations.
- Reject copied outside-game code, identities, item catalogs, and game-specific naming.
- Keep capture spheres/cages/forced work/forced evolution out of active runtime.
- Document compile, test, profile, multiplayer, persistence, and regression evidence.

## Current Technical Documents
- `08_Technical/BCT-001_BUILDING_CRAFTING_TRANSACTION_CONTRACT.md`
- `08_Technical/CHAT_CODE_INTAKE_AUDIT_2026-09-19.md`

## Current Website Documents
- `10_Marketing_Publication/WEBSITE_ECOKIN_BESTIARY.md`
- `/web` Next.js implementation

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
