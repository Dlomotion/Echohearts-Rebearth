# ECHOHEARTS: REBEARTH — MASTER PROJECT INDEX

This file is the routing map for the existing Echohearts project. It does not replace the Master Game Bible, Eco-Kin art manifest, or structured game-data dictionary.

## Source-of-truth chain

1. `00_Canon_Lock`
2. `01_Story`
3. `02_World`
4. `03_EcoKin_Dex`
5. `04_Systems`
6. `05_Levels`
7. `06_UI_UX`
8. `07_Art`
9. `08_Audio`
10. `09_Technical`
11. `10_Production`
12. `11_Publication`
13. `99_Reference_Retired_Needs_Redesign`

## Canonical directory registry

These folder names are authoritative routing labels and should match the repository README and Copilot routing rules.

| Folder | Required contents / responsibility |
|---|---|
| `00_Canon_Lock` | Locked canon, protected terminology, authority decisions, continuity constraints, and rules that downstream files may not silently override. |
| `01_Story` | Main story, chapters, character/NPC arcs, dialogue/story beats, DLC/expansion narrative, and chronology. |
| `02_World` | Rebearth regions, biomes, cities, landmarks, ecology, world-state changes, travel/portal geography, and environmental lore. |
| `03_EcoKin_Dex` | The 125-ID Permanent Eco-Kin Dex, Forms Registry links, ecology/biology, named Eco-Kin records, historical-name review, and Dex governance. |
| `04_Systems` | Gameplay-system contracts including Anima-Link, Huma-Link, Kindling, combat, Growth Rites, inventory/economy, Sanctuary, missions/progression, traversal, and other systemic rules. |
| `05_Levels` | Missions, encounters, dungeons, maps, coordinates, puzzles, vertical-slice level implementation plans, and level-specific validation. |
| `06_UI_UX` | A.E.G.I.S., HUD, EcoDex, mission tracking presentation, menus, accessibility, interaction feedback, and UX contracts. |
| `07_Art` | Character/Eco-Kin art briefs, rig/animation art requirements, asset manifests, visual provenance, anatomy/identity QA, and technical-art direction. |
| `08_Audio` | Music, ambience, VO, Eco-Kin audio, combat/resonance audio, implementation cues, and audio-direction contracts. |
| `09_Technical` | UE5.8/C++ architecture contracts, schemas, networking/save/cloud/security/telemetry requirements, build/tooling standards, and technical audits. Executable UE source itself belongs in the BUILD repository. |
| `10_Production` | Backlog, dependency maps, QA/evidence requirements, assignments, provenance, intake routing, release gates, and production status. |
| `11_Publication` | Approved public-facing manuscripts, pitch/marketing material, ebook/publication standards, release manifests, and publication evidence. |
| `99_Reference_Retired_Needs_Redesign` | Superseded, derivative, contradictory, unsafe, historical, or redesign-required material retained only for traceability/reference. |

Do not substitute alternate folder names such as `05_Art_Direction`, `06_Audio`, `07_UI_UX`, or `08_Narrative_Production` for this routing map. Those labels belong only to historical/proposal material if encountered and must not become a parallel directory authority.

## Repost / intake rule

Every reposted chat, image, document, code block, Eco-Kin concept, NPC, lore fragment, mechanic, or art reference must be:

`INTAKE → AI MISTAKE PATCH → CONTINUITY CHECK → ORIGINALITY/IP CHECK → CORRECT FOLDER → STATUS → GAME/STORY LINK → IMPLEMENTATION EVIDENCE`

Do not create a parallel canon or duplicate implementation path.

## Status vocabulary

- **CANON** — approved source-of-truth fact.
- **APPROVED-PENDING** — accepted direction awaiting implementation/art/data proof.
- **MERGED/RENAMED** — useful material reconciled into an existing identity/system.
- **REFERENCE-ONLY** — inspiration or historical material that cannot overwrite canon.
- **RETIRED** — superseded or contradictory material kept for traceability.
- **NOT YET VERIFIED** — technical claim without build/test/profile evidence.
- **VERIFIED** — supported by direct evidence.

## Reconciled packet: Shattered Frontier / legacy intake

- Shattered Frontier character cast and NPC roles.
- Kaelen/Kale + Sherlock Hound merge.
- Liora, Elder Thorne, Mora, Silas, Nurse Calla, Commander Vex, Ryn, Nature, Ancient Oracle.
- Void-Scholar merged as an alias/title connected to existing villain continuity instead of a duplicate grand antagonist.
- Animal-reference Eco-Kin intake: okapi, echidna, coati, Patagonian mara, tarsier, bat-eared fox.
- Historical Eco-Kin origin/capture drafts reconciled into current Rebearth/Kindling canon.
- Historical UE5.5 Parts 215–255 preserved as technical proposals under active correction, not as verified production code.

## Story / publication consolidation: 2026-09-20

- `01_Story/ECHOHEARTS_REBEARTH_FINAL_STORY_CONTINUITY_2026-09-20.md` — canon-corrected Six Eras, eight-act campaign, 20-chapter story spine, major cast, four primary endings, five reserved secret-variant slots, and Living Chorus bridge.
- `03_EcoKin_Dex/ECO_KIN_STORY_INTEGRATION_TEMPLATE.md` — one identity/anatomy/ecology/story/Kindling/production template for permanent roster development.
- `07_Art/ART_REPOST_ROUTING_AND_QA.md` — image intake, identity matching, anatomy QA, originality review, story connection, and approval-state rules.
- `10_Production/REPOST_STORY_CONSOLIDATION_QA_2026-09-20.md` — records the corrections applied to legacy story and systems material and the unresolved items kept honest.
- `11_Publication/WORD_EXPORT_MANIFEST_2026-09-20.md` — publication-facing Word package manifest and release gate.
- `06_UI_UX/README.md` and `08_Audio/README.md` — complete the repository's intended source-of-truth folder map and define routing boundaries.

### Ending rule

The current story supports four primary ending families: **Heal / Order**, **Break / Severance**, **Balance / True Rebirth**, and **Transcend / Star Rewrite**. Five additional secret-variant slots are preserved for faction/boss/Eco-Scar/relationship outcomes. Their individual names and exact condition bundles are not to be fabricated as locked canon until the ending matrix is approved.

### Publication rule

The master story and Word templates are publication drafts that summarize and operationalize the existing canon. They do not independently supersede the Master Game Bible. Final public release still requires canon, continuity, rights/provenance, art, layout, and technical-claim review.

## Theater / portal / Dryad / legacy 258–272 intake: 2026-09-20

The reposted dungeon/portal/game-development material is integrated into the existing workflow without creating a second game mode, world map, Dex, or runtime.

- `02_World/ECHO_WARP_NETWORK_RECONCILIATION.md` — routes restored warps/portals across the existing Rebearth map with PortalID, unlock, restoration, safety, save and World Partition requirements.
- `03_EcoKin_Dex/Named_EcoKin/DRYAD.md` — preserves Dryad as an approved-pending Humanoid-Kin production reference with Flora-first guardian direction and non-extractable resonance symbolism.
- `05_Levels/THEATER_NETWORK_RECONCILIATION.md` — converts historical dungeon/Theater concepts into current mission/world-state requirements and keeps campaign combat real-time.
- `09_Technical/LEGACY_PARTS_258_272_CODE_AUDIT_2026-09-20.md` — retires unsupported production claims and audits the historical web exporter, S3, telemetry, companion, stealth, volumetric-cloud, pseudo-test and raw-UDP load-test material.
- `11_Daily_Assignments/THEATER_PORTAL_DRYAD_LEGACY258_272_ASSIGNMENTS.md` — carries content and technical reconciliation into the existing daily workflow without jumping current technical gates.

### Originality rule for this packet

Historical outside-franchise dungeon names, bosses, tournaments, game structures, copied formulas and branded terminology are REFERENCE-ONLY. Echohearts may study transferable ideas such as route gating, challenge escalation, cooperative raid structure, competitive fairness, boss counterplay and replayable dungeons, but publication-facing names, creatures, mechanics, code and art must remain original to Echohearts.

### Combat/stat correction for this packet

Main campaign combat remains real-time third-person action. Tactical grid or turn-based combat is restricted to approved Resonance Arena / Harmony Circuit / EchoDeck simulation contexts. Public gameplay stats remain **Vibrance, Density, Harmony and Purity**; historical VIT/RSN/SYNC/Hertz/Velocity packs do not replace them.

## Bee / legacy Dex / guardian art / Hometown intake: 2026-09-20

This repost batch is routed into the existing workflow only. It does not create a second Dex, legendary roster, art queue, economy, story bible or daily schedule.

- `03_EcoKin_Dex/Intake/AFRICANIZED_BEE_LINE_INTAKE_2026-09-20.md` — preserves the user's Africanized honey-bee inspiration as an approved-pending Bug-Kin evolution line with current elements/stats, ethical Kindling and strict six-leg insect anatomy.
- `03_EcoKin_Dex/LEGACY_DEX_V2_RECONCILIATION_2026-09-20.md` — keeps useful identity/ecology/personality/ability/data fields from the historical Dex while retiring conflicting public stats, storage/trading, forced-work, forced-breeding and duplicate-stage architecture.
- `07_Art/GUARDIAN_BEAST_REPOST_INTAKE_2026-09-20.md` — routes Vaelthundra, Cindervault, Auralyss, Kharuvane, Orokharn, Thalassyr, Zephyrahn, Vharomaw, Astravault, Mycelith, Aquanith, Sylvornith and Lumineth through duplicate-art, element, anatomy, guardian-role and originality review.
- `01_Story/HOMETOWN_DLC_RECONCILIATION_2026-09-20.md` — preserves the destroyed-hometown/rebuilding story concept as source material while requiring timeline, location, faction and survivor continuity before canon promotion.
- `11_Daily_Assignments/BEE_DEX_GUARDIAN_HOMETOWN_RECONCILIATION.md` — carries the batch into the one existing daily game-development workflow.

### Bee line working direction

Historical `Hive Spark`, `Swarm Guard`, `Africanized Queen`, displayed stats/requirements and Maat connections remain source labels until review. Current production direction uses a three-stage Bug-Kin concept with Flora/Aero mapping, pollinator restoration, swarm defense, voluntary Sanctuary Aptitudes and no capture/forced evolution. `Crownsting Matriarch` is the current working final-stage name pending naming review.

### Legacy Dex correction

The historical `185-entry` count is a source inventory estimate, not a locked canon roster size. Historical HP/MP/SP/ATK/DEF/etc. public stats and Veridian/Cipher/Hollow-style replacement attribute systems cannot supersede the current public V/D/H/P stats or locked 12 elements. Useful internal fields may be migrated after deduplication and originality review.

### Farm / Hometown correction

Preserve farming, colorful biome storytelling, care/sickness, rebuilding and community-economy value. Retire forced `worker` automation, sentient storage/trading, breeding-station optimization and old squad-of-five rules. Use voluntary Sanctuary Aptitudes/Partner Assist, Living Soil, Havenlink, Healing Incubator recovery/Echo-Egg care and the current 8-roster / 3-active campaign combat contract.

## Glow Worm / EchoCode / image archive / legacy Technical Spine intake: 2026-09-20

This repost batch is integrated into the existing workflow and does not create a second card game, Dex, art library, backend stack, runtime or daily schedule.

- `03_EcoKin_Dex/Named_EcoKin/GLOW_WORM.md` — preserves **Glow Worm** as one approved-pending bioluminescent invertebrate Eco-Kin identity. Historical `Light-Kin` presentation is not a new element; Radiant is the strongest current mapping candidate pending final ecology/balance review. Historical card/art variants attach to this identity rather than generating duplicate species.
- `04_Systems/ECHOCODE_CARD_SYSTEM_RECONCILIATION_2026-09-20.md` — keeps the physical/digital card, EchoCode, Genesis Bloom, community-card and tabletop ideas while correcting sentient-partner ownership, pay-to-win risk, obsolete stats/elements and campaign-combat conflicts. Cards may unlock opportunities, cosmetics, lore, quests, encounter/Kindling leads and approved simulation content, not ownership of living Eco-Kin.
- `07_Art/HISTORICAL_ECOKIN_IMAGE_ARCHIVE_INTAKE_2026-09-20.md` — records the requirement to preserve recoverable created images as organized individual PNG assets, while keeping the recovery status honest. Historical URLs/file IDs are source references; a complete raw-PNG archive is not yet verified. Rejected/bad variants route to `99_Reference_Retired_Needs_Redesign` instead of replacing approved art.
- `09_Technical/LEGACY_TECHNICAL_SPINE_UNITY_SQL_AUDIT_2026-09-20.md` — retires the old Unity/C#/Mecanim/PostgreSQL `production-ready` claim, flags `ActionType.FLE_FLEE`, lifecycle/null/polling issues, schema/canon mismatches and preserves only transferable requirements for future UE5.8/account-service design.
- `11_Daily_Assignments/GLOW_WORM_CARDS_IMAGE_ARCHIVE_SPINE_RECONCILIATION.md` — carries this packet through the one existing `Echohearts Daily Game Work` workflow without jumping the current technical gates.

### Card / EchoCode ethics rule

An Echo-Kin card represents a sentient partner; it does not contain, sell or transfer that being. EchoCode redemption must remain server-authoritative when implemented and may grant eligible content such as an EchoDeck representation, cosmetic, lore entry, quest, encounter/Kindling opportunity, Sanctuary decoration or balanced technique path. Historical VIT/AGS/VEL/RSN/SYNC and Frost/Light/Storm element families are prototype language, not replacements for V/D/H/P or the locked 12 elements.

### Image archive rule

Recover and preserve original created art when actual source bytes are available. Keep originals and edits separately, use stable identity-based filenames, and record source/provenance/status. Never claim a downloadable complete PNG archive exists until the raw assets have actually been recovered and checked.

## Dark Beasts / Ancient Beasts / creation-chat visual source: 2026-09-20

Dark Beasts and Ancient Beasts are now official Eco-Kin lineup classifications within the **existing** registry, not separate creature systems.

- `03_EcoKin_Dex/DARK_AND_ANCIENT_BEASTS_LINEUP_2026-09-20.md` — defines Dark Beasts as nocturnal / abyssal / spectral / anomaly-associated Eco-Kin without making them inherently evil, distinguishes Blight corruption as a state rather than a species, and defines Ancient Beasts as primordial / heritage lineages tied to Rebearth's deep ecosystems, ruins, relics and pre-war history. Rarity, Legendary/Titan status and Kindling eligibility remain independent authored properties.
- `07_Art/ECOKIN_CREATION_CHAT_VISUAL_SOURCE_RULE.md` — makes previously approved Eco-Kin Creation / character-design images the visual production source for future images. Preserve approved DNA, anatomy, silhouette, colors, materials, gear, biome and name; correct only actual errors unless the user explicitly orders a redesign.

### Dark / Ancient gameplay correction

Dark Beasts and Ancient Beasts use the same `EcoKinID` / `EchoprintID`, Kindling, V/D/H/P, canonical 12 elements, combat, growth, card, save and QA pipelines as every other Eco-Kin. Historical `capture/taming` wording is reconciled to the current ethical field loop: **Observe → Protect → Calm → Kindle → Bond / Release / Defer**. Forced mutation/evolution, ownership transfer and sentient storage remain non-canon.

### Image-generation continuity rule

When an already-created Eco-Kin has approved prior art, use that recovered creation-chat image/design record as the source of truth for new images here instead of inventing a different creature under the same name. One Eco-Kin per image by default, coherent anatomy, original Echohearts visual identity, and no accidental redesign merely for novelty.

## Growth Rites / Sovereign encounters / Championship status: 2026-09-20

The reposted mutation, DNA-fusion, hunting/trapping, Alpha-boss, Champion-tier and outside-franchise evolution research has been reconciled into original Echohearts systems rather than copied.

- `04_Systems/GROWTH_RITES_RESONANCE_BRANCHES_AND_CHAMPIONSHIP_STATUS.md` — replaces forced mutation and copied evolution tiers with voluntary **Growth Rites / Resonance Branches**, keeps Kindling and the 12 core elements, replaces DNA splicing with **Resonance Trait Infusion / Bio-Synergy Weaving**, replaces Genetic Instability with **Resonance Strain / Spirit Load**, keeps V/D/H/P as the only public stats, and establishes **Resonance Circuit Standing** where sanctioned championship victories raise competitive status.
- `04_Systems/SOVEREIGN_ECOKIN_ENCOUNTER_SYSTEM.md` — replaces capture-oriented Alpha boss design with **Sovereign Eco-Kin** encounters focused on protection, ecology, purification, territorial challenges and earned trust. No harpoon/cage/genome-extraction progression.
- `99_Reference_Retired_Needs_Redesign/LEGACY_MUTATION_FUSION_CAPTURE_REFERENCE_RETIRED_2026-09-20.md` — preserves Aniimo / Digimon / Pokémon material only as broad reference questions while explicitly retiring copied terminology, donor consumption, DNA/body fusion, capture cages, stat replacement tables and raw Python pseudocode claims.

### Championship rule

Winning sanctioned Resonance Arena / Harmony Circuit championship fights increases **Resonance Circuit Standing** through the current ladder: **Qualifier → Challenger → Crestbearer → Champion → Grand Champion → Harmonic Crown**. This standing is separate from biological growth and Kindling. It can unlock titles, cosmetics, invitations, advanced trials and competitive content without forcing evolution or creating pay-to-win stat inflation.

### Current uploaded form-art routing

Current images such as Totemflare Rainforest Strider / Galecrest / Stormbringer, Psylopath Mindcoil / Mirefiend, Marmara Seedling / Verdant / Prime Guardian, Flames Emberling / Cinderstride / Blazewarden, Sandveil Burrowkin / Sandshield / Sandshaper, ZuriStripe variants, Ho-kanko variants and Jazzy & Drako pair art are preserved as visual/source references. They require naming, element, anatomy and story audit before final data lock. Human + Eco-Kin pair imagery represents partnership, never fusion.

## Final universe / creature / PR consolidation: 2026-09-26

This final pass connects the latest project-chat intake to the current repository and open PR/issue dependency chain without creating a new canon track.

- `00_Canon_Lock/FINAL_UNIVERSE_CONSOLIDATION_2026-09-26.md` — final reconciliation for 125-ID creature governance, Aurivelle rename, Geo/Echo interaction tags, Aurelian/Great Somatic Fracture placement, original story/cosmic salvage, faction/trial/automation/growth corrections, infinite-continuation rules, and the technical verification boundary.
- `10_Production/FINAL_CONSOLIDATION_PR_AND_IMPLEMENTATION_MAP_2026-09-26.md` — maps open PRs #1/#2/#6/#7/#9/#11/#14 and Issues #8/#10/#12/#13 into one execution order from infrastructure through the first UE5.8 body/animation slice and later tactical/online work.
- `99_Reference_Retired_Needs_Redesign/FINAL_LEGACY_REFERENCE_RETIREMENT_2026-09-26.md` — explicitly retires one-to-one outside-franchise adaptations, forced fusion/ownership drift, unsafe legacy player/body concepts, and unsupported production-ready technical claims while preserving abstract transferable lessons.

### Final naming correction

`Prismana` / `Prusmana` is retired from active Echohearts naming. **Aurivelle Form** is the replacement working name. Current evidence does not establish Hexxin as a permanent 125-ID identity, so `Hexxin — Aurivelle Form` remains a parent-mapping/form candidate and cannot create a 126th permanent species.

### Final element/Essence correction

The current production Essence keys remain **Flora, Torrent, Pyre, Terra, Aero, Glaze, Voltic, Aura, Shade**. `Geo` is a Terra geological specialization and `Echo` is a Harmony-driven Resonance interaction tag. The requested Geo row is preserved: Geo dominates Solar/Aero and is dominated by Flora, Hydro/Torrent, and Echo; Echo retains its authored 1.6× advantage over Geo/Aero and 1.6× weakness to Flora/Hydro-Torrent when the Echo interaction tag applies.

### Final originality rule

Direct Terraria/Digimon/Nexomon/Pokémon/Aniimo/Roots names, plots, creatures, tiers, boss structures, capture/fusion logic, code, art, rigs, and animation are reference-only. Only abstract lessons may be re-authored through original Echohearts identities, mechanics, story, art, and code.

### Final production order

1. Review PR #15 canon/production consolidation.
2. Validate PR #14 infrastructure and resolve overlap with #11.
3. Establish the real UE5.8 `.uproject` / `Source` foundation and clone/LFS/build evidence.
4. Execute Issue #10 as the first evidence-backed NPC + Eco-Kin 3D body/animation slice.
5. Build the 4–6 Eco-Kin funding vertical slice.
6. Reconcile/validate PR #2 public Bestiary.
7. Advance PR #6 story/manuscript content only after current-canon terminology review.
8. Advance #7/#9 and Issue #8 as bounded tactical/online work after the real-time core is proven.
9. Scale MassEntity, deep destruction, nested-city streaming, orbital events, and other large R&D systems only after profiling proves the core foundation.

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.


## 2026-10-06 Inventory, Echo Eggs, and Upgrade Highlights

Current design-intake sources:
- `04_Systems/Inventory/ECHOHEARTS_MASTER_ITEMS_MATERIALS_REGISTRY_2026-10-06.md` — consolidated inventory/material/shop/equipment registry: 737 categorized records, 694 unique named entries, 28 categories. Preserve per-entry canon/legacy/retired status.
- `04_Systems/ECHO_EGGS_AND_UPGRADE_HIGHLIGHTS_2026-10-06.md` — current Echo Egg variants, incubation/care rules, upgrade-highlight pillars, UI/art direction, repository ownership, and UE5.8 implementation contract.
- `.github/instructions/echohearts-current-design.instructions.md` — current GitHub Copilot implementation/fix guidance synchronized across the seven Echohearts repositories.

- `09_Technical/LANGUAGE_DIAGNOSTIC_AND_TOOL_SELECTION_STANDARD_2026-10-06.md` — language-aware repair policy: fix the failing layer in its owning language/toolchain instead of mixing unrelated languages into UE code.
- `04_Systems/MISSION_SYSTEM_ARCHITECTURE_2026-10-06.md` — corrected event-driven mission contract covering stable IDs, server authority, replicated co-op state, typed dialogue mission actions, UMG event refresh, and idempotent completion/reward boundaries.

These additions extend the existing canon/contracts. They do not replace the Master Game Bible, the 125-ID Permanent Dex, or executable runtime evidence requirements.

## 2026-10-06 STARZ* / Saviors universe integration

- `01_Story/STARZ_SAVIORS_UNIVERSE_INTEGRATION_2026-10-06.md` — connects recovered STARZ*/Saviors material to the existing War of Summoning → Star Rewrite expansion lane without creating a second canon, second Dex, or duplicate runtime. It accepts the current original Savior/antagonist/support roster for continued design, quarantines legacy mixed-language build material, routes executable ownership to the BUILD repository, and keeps Summoning Wars → Saviors of the Universe → Ancient Tech Wars behind the established production/runtime gates.
- `git-ecosystem/git-credential-manager` is recognized only as a workstation credential-helper reference; it is not an Echohearts runtime dependency and no credentials/auth cache belong in source control.

Verification remains **NOT VERIFIED — UE BUILD/RUNTIME EVIDENCE REQUIRED** until the BUILD repository supplies actual UE5.8 compile/runtime proof.

## 2026-10-06 recovered Unity package inventory

- `09_Technical/RECOVERED_UNITY_PACKAGE_INVENTORY_2026-10-06.md` — byte-level inventory of the uploaded Unity-era Echohearts packages, including SHA-256 hashes, placeholder/empty-package detection, duplicate ProceduralWorld package detection, recoverable procedural-world requirements, dialogue/shader routing, and explicit UE5.8 port boundaries. The recovered Unity/C# code remains reference-only; executable ownership stays in the BUILD repository.
- Source-control transport guidance for this recovery lane: prefer HTTPS + Git Credential Manager on Windows, use GitHub CLI for auth/PR/workflow operations, and treat SSH as an optional key-based alternative. No credentials or auth caches belong in source control.

Verification remains **NOT VERIFIED — UE BUILD/RUNTIME EVIDENCE REQUIRED**.

## 2026-10-06 Unity gameplay recovery batch 2

- `09_Technical/UNITY_GAMEPLAY_RECOVERY_BATCH2_UE58_PORT_MAP_2026-10-06.md` — audits the uploaded character-creator/customization, dialogue, animation, VFX, multiplayer/netcode, shader, full-demo, foundation and complete-export packages and maps only source-supported behavior into the UE5.8 BUILD lane. BUILD PR #34 carries the bounded C++ port for appearance/customization, dialogue records, VFX cues and battle synchronization contracts. Placeholder boss/multiplayer/VFX/demo claims are not promoted to implemented status.

Verification remains **NOT VERIFIED — UE BUILD/RUNTIME EVIDENCE REQUIRED**.

## 2026-10-08 A.E.G.I.S. restoration UI and engineering evidence

- [Restoration display acceptance](06_UI_UX/AEGIS_RESTORATION_DISPLAY_ACCEPTANCE_2026-10-08.md) — PROPOSAL; unavailable/zero/stale readings, travel context, mission authority and accessibility cases.
- [Daily evidence and unified carry-forward queue](10_Production/ECHOHEARTS_DAILY_GAME_WORK_2026-10-08.md) — BUILD PR36 input-budget correction, 15 offline tests, native checks, PR20 mergeability delta and web PR17 intake routing. UE5.8/runtime NOT YET VERIFIED.
