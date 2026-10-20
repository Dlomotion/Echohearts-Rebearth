# Echohearts: Rebearth — Living AI Humanoids, Eco-Kin Ecosystem Navigation & Nanonite

**Status:** APPROVED-PENDING — user-directed design and compiled portable C++ reference; runtime UE5.8 integration NOT YET VERIFIED.
**Origin:** User requests, October 2026.
**Routing:** This is an intake/integration contract **inside the existing Master Project Index workflow**; it is not a replacement Master Game Bible, story spine, EcoDex, standalone canon or runtime.

## Source-of-truth cross-links
- `MASTER_PROJECT_INDEX.md` and `00_Canon_Lock/CANON_CORE_RULES.md` control naming, roles, protected story authority, roster #001–125, and validation.
- `04_Systems/AI_NARRATIVE_DIRECTOR_GOVERNANCE.md` controls every adaptive NPC narrative proposal and world consequence.
- `04_Systems/AEGIS_ECO_DEVICE_RECONCILIATION.md` owns A.E.G.I.S. and D.A.H.L.I.A. presentation.
- `02_World/ECHO_WARP_NETWORK_RECONCILIATION.md` controls route/portal travel validation.
- `04_Systems/CHARACTER_ECOKIN_RELATIONSHIP_RULES.md` controls Eco-Kin consent, independent AI/Synth-Origin agency and voluntary bonds.
- `04_Systems/ECONOMY_RECONCILIATION.md` and the current master inventory registry govern shops and vendor item IDs.
- Existing story `01_Story/ECHOHEARTS_REBEARTH_FINAL_STORY_CONTINUITY_2026-09-20.md` and `04_Systems/ECO_SENTINEL_UE58_DESIGN_RECONCILIATION_2026-09-20.md` govern character/faction/villain chronology.

## Three gameplay implementation threads

### 1. AI NPC humanoids, local life and services
C.H.A.R.V.I.S. (privacy, archive security), S.U.N.D.A.Y. (social interpretation), M.A.R.Y. (expedition guidance), D.O.R.M. (repair/workshop), I (analysis) are proposed distinct humanoid synthetic NPCs with daily routines, authored fallback dialogue, interpersonal memory and accessible service presentations. They are not automatically classified as biological Humanoid-Kin or Eco-Kin, and none may be listed in the 125-ID Permanent Dex without proper approval.

- `AI_CHARVIS` -> `SERVICE_ARCHIVE_LOCKBOX`.
- `AI_SUNDAY` -> `SERVICE_COMMON_GROUND`.
- `AI_MARY` -> `SERVICE_EXPEDITION_WINDOW`.
- `AI_DORM` -> `SERVICE_ROOT_RELAY` (reuse current Root & Relay stock and economy).
- `AI_I` -> `SERVICE_SIGNAL_STUDY`.
A.E.G.I.S. remains the player's physical bracer. D.A.H.L.I.A. remains a linked advisory module, **not** an independent gameplay or database authority. G.L.Y.T.C.H. retains independent Synth-Origin Eco-Kin agency; ULTRA remains an adversarial AI identity under story review and has no ordinary shop.

### 2. Ecological route navigation
Proposed route intents: Careful / Discovery / Expedition. Route input contains *only* validated, stable SegmentID/POIID/PortalID links. A.E.G.I.S. UI may propose alternate paths based on hazard, Blight, ecological stress and authorized survey data. All modes **reject** protected nesting/recovery habitats, inaccessible World Partition areas, unapproved story/restoration gates and unvalidated portal destinations. D.A.H.L.I.A. interprets evidence; it cannot authorize travel or create new species discovery, quests or save flags. The **existing** authoritative travel service checks the selected segment IDs and can refuse travel even after UI guidance.

### 3. NANONITE — high-speed AI reconstruction boss
**User-specified core premise:** Nanonite is a boss villain, a fast computational intelligence that recreated other AIs and resents humanity's arrival on Rebearth. It bridges questions of synthetic identity, Humanoid-Kin autonomy and living-world ecology.

Proposed fight sequence:
`Dormant -> Route Mirage -> Reconstruction Court -> Habitat Sieve -> Final Calculation -> Resolved`.
Counterplay emphasizes signal provenance, exposing counterfeit re-creations, protecting Eco-Kin habitats and interrupting a telegraphed prediction core. Existing combat, four public stats (Vibrance, Density, Harmony, Purity), Anima-Link, authoritative character health/stamina and actual damage balance remain the owners of attack/strain consequences. **No compulsory mutation, ownership of Humanoid-Kin/Eco-Kin, or AI-approved canonical ending changes.**

Nanonite is **not** silently conflated with or replacing the existing E.C.O. Sentinel, Nature, Echolord Vorlag, Dr. Hugo, or other established bosses. Identity and precise Six-Eras/Act placement require story approval. Reconstructed C.H.A.R.V.I.S./S.U.N.D.A.Y./M.A.R.Y./D.O.R.M./I may be independent persons; reconstruction is not ownership, and it cannot retroactively rewrite preexisting AI origins.

## Concrete code work and verification state
- **Design/data source:** `Dlomotion/EcoKin-A.i.` (`docs/AI_HUMANOID_ECOLOGY_NAVIGATION.md`, `docs/NANONITE_STORY_BOSS.md`, `data/ai_npc_registry.json`, `data/nanonite_encounters.json`).
- **UE5.8 source staging:** `Dlomotion/EcoKin-patch` PR #4 — `ue5/Source/Echohearts/Public/EcoKinAIWorldTypes.h`, `EcoKinAIRouteLibrary.h`, `EcoKinAIServiceNPC.h`, `NanoniteEncounterComponent.h`, matching `Private/*.cpp`, `Private/Tests/EcoKinAISystemsTests.cpp` and `docs/UE58_AI_NANONITE_INTEGRATION_HANDOFF.md`.
- **Runtime authority:** existing `Dlomotion/ECHOHEARTS-REBEARTH-BUILD-` must receive reviewed code when access is available; legacy `IN2Deep-Studios/ECO-KIN-Game` is not an acceptable authority substitute.
- **Evidence:** portable C++ checks may pass in patch CI; that is *not* UE5.8 UHT/UnrealBuildTool/editor, World Partition, actor/AI behavior tree, animation, save, network or packaged-game proof.

## Required next production gate and acceptance
1. Restore authorized read/write access to BUILD; inspect real module, classes, targets and build agents.
2. Resolve canonical placement and NPC identity/approval; map to existing quest/faction/story flags; assign owners for VO, rigging, behavior trees and shops.
3. Cherry-pick/port reviewed C++ into actual production module after symbol collision audit; run UHT and both Editor/Game Development builds (real engine 5.8).
4. Test world snapshot gate-denial, Anima-Link cost propagation, NPC vendor transaction replay, client/server replication, World Partition portal readiness, Eco-Kin consent, boss phase spoof and phase replay, offline fallback, save/load/reconnect, 60-FPS profiling and package launch.
5. Once evidenced, record implementation in `09_Technical` and `10_Production` and promote only approved canon elements from intake.

**No new locked NPC origin, studio storefront, full AI model backend, playable boss or compiled game claimed by this document.**

© 2026 IN 2 DEEP STUDIOS LLC. All rights reserved.
