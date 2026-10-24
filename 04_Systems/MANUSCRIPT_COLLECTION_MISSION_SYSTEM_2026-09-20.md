# Manuscript Collection Mission System

**Status:** APPROVED-PENDING DESIGN  
**Implementation:** NOT YET VERIFIED  
**Runtime target:** Unreal Engine 5.8 production path only  
**Project:** Echohearts: Rebearth / Into Deep Studios

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

## Purpose

Add manuscript recovery to the main exploration and mission loop so lore is discovered through play rather than delivered only through menus or exposition.

The system has two initial collections:

1. **Eco-Kin Manuscripts** — field notes, ecological records, care observations, habitat maps, relationship journals, migration records and historical accounts concerning Eco-Kin.
2. **War on Life Manuscripts** — eyewitness accounts, field journals, damaged orders, maps, letters, research notes, memorial records, propaganda, counter-records and surviving testimony from the War on Life.

The feature expands the already approved physical-scroll discovery direction. Manuscripts are physical world objects or reconstructable fragments, not automatic menu keys.

## Core Design Rule

A manuscript should do at least one meaningful thing beyond increasing a collectible counter.

A recovered manuscript must provide one or more of:
- an EcoDex knowledge unlock;
- a habitat or route clue;
- a mission lead;
- a restoration clue;
- a dialogue option;
- a puzzle solution;
- an environmental history reveal;
- a relationship/care insight;
- a cosmetic/archive reward;
- evidence that changes how a player understands a faction, character, battle or historical event.

## Player Loop

**Explore → notice clue → investigate → recover fragment/page → authenticate/reconstruct → read or inspect → update EcoDex/War Archive → unlock consequence or lead → continue mission/world restoration.**

The player should often discover manuscripts through environmental reasoning rather than glowing-object cleanup.

Examples:
- tracks or nesting behavior point toward a hidden Eco-Kin field journal;
- a damaged Purity structure contains a sealed war report;
- rainfall exposes ink or markings on a protected stone page;
- an Eco-Kin reacts to a place tied to an old record;
- a Resonance reading reveals that two manuscript fragments belong together;
- a restored biome opens a previously inaccessible archive chamber.

## Collection A — Eco-Kin Manuscripts

### Content categories
- habitat and migration records;
- diet/care observations;
- social behavior and partner-bond observations;
- defensive and survival behavior;
- environmental role;
- historical encounters with communities;
- restoration responses;
- evolution/growth-rite observations when canon-approved;
- myths versus verified field observations;
- rare regional variants or unusual Echoprint observations when approved by the Eco-Kin Dex.

### Design safeguards
- Eco-Kin are partners, not inventory commodities.
- Manuscripts must never frame capture, ownership or consumption as the default relationship model.
- A manuscript can be incomplete, biased or wrong. Later evidence may correct an earlier writer.
- Unknown Eco-Kin identities remain unnamed until they have a valid Dex intake.

### Gameplay value
Recovering pages can progressively unlock additional EcoDex fields rather than granting full knowledge on first sight.

Example progression:
- Observation 1: silhouette / general habitat
- Observation 2: environmental role
- Observation 3: behavior/care clue
- Observation 4: ability interaction or restoration clue
- Observation 5: historical relationship entry

Exact progression counts remain tunable.

## Collection B — War on Life Manuscripts

The War collection is not a single omniscient history book. It is assembled from conflicting records.

### Content categories
- events leading into the War on Life;
- battles and damaged regions;
- orders issued by leaders or factions;
- field medic / researcher / engineer journals;
- civilian and survivor accounts;
- evacuation and missing-person records;
- Eco-Kin displacement and ecological damage records;
- restoration attempts that succeeded or failed;
- propaganda and redacted material;
- counter-records that contradict official narratives;
- memorial lists and last-known-location records;
- records connected to the Circle of Life, corruption, control, forced survival and restoration.

### Narrative rule
No single manuscript automatically defines objective truth. Important historical conclusions should be built from corroborated evidence, environmental state, living witnesses and other mission content.

This creates playable historical investigation instead of passive encyclopedia reading.

## Mission Integration

Manuscripts can appear in:
- main-story missions;
- Academy lessons;
- field missions;
- biome restoration missions;
- Sanctuary return sequences;
- optional exploration missions;
- boss-region investigations;
- hidden relic routes;
- late-game truth/reconstruction missions.

A manuscript mission should connect to the existing mission rhythm:
**lesson → field objective → consequence → Eco-Kin reaction → world change → story clue → next unlock.**

## Reconstruction System

Some records are complete objects. Others require 2–5 authored fragments.

Fragment reconstruction may require:
- finding physical pieces;
- placing pages in sequence;
- matching symbols or handwriting;
- comparing a page with a map or environmental landmark;
- Resonance/A.E.G.I.S. scanning;
- restoring damaged ink or encoded layers;
- visiting the location described by the writer.

Do not turn every manuscript into the same jigsaw minigame. Use multiple authored interaction types.

## Authenticity and Contradiction

Each important record may carry metadata such as:
- author/source;
- approximate era;
- region;
- collection type;
- condition;
- confidence/authenticity state;
- related EcoKinID or mission ID;
- related War event ID;
- contradiction links;
- reconstruction completeness;
- player-discovered evidence.

Recommended states:
- Unverified
- Partially Corroborated
- Corroborated
- Disputed
- Forged/Manipulated

These are narrative-data states, not claims that the overall implementation is technically verified.

## Rewards

Primary reward is knowledge with gameplay consequence.

Secondary rewards may include:
- EcoDex completion progress;
- Archive completion milestones;
- lore-linked cosmetics;
- Sanctuary display items or reproductions;
- recipes or restoration techniques when narratively justified;
- hidden route access;
- optional dialogue choices;
- investigation XP/progression;
- region-history badges/titles if later approved.

Do not lock combat power behind exhaustive collectible completion.

## Sanctuary / Archive Presentation

Recovered records should be viewable from a Sanctuary archive interface or equivalent approved hub presentation.

The original physical artifact remains meaningful. The player may create a readable archival copy after recovery so the world object does not become a disposable key.

Potential presentation modes:
- page viewer;
- reconstructed timeline;
- region map pins;
- author/source index;
- Eco-Kin cross-links;
- War event cross-links;
- contradiction/evidence view.

Final UI name and visual treatment remain pending `06_UI_UX` review.

## Accessibility / UX

- readable scalable type;
- high-contrast manuscript transcription option;
- text-to-speech compatibility target for manuscript text;
- no critical clue communicated only by color;
- replayable clue summaries;
- optional navigation assistance after sufficient investigation;
- collectible audio cue must have visual equivalent;
- long lore entries should provide short summary plus full transcription.

## Anti-Checklist Rules

Avoid placing dozens of unrelated pages merely to inflate playtime.

Every authored manuscript should pass at least two of these tests:
1. teaches something about a living Eco-Kin or ecosystem;
2. changes understanding of the War on Life;
3. reveals character/faction motive;
4. opens or clarifies gameplay;
5. points to a physical location;
6. creates a contradiction the player can investigate;
7. changes later dialogue or mission context;
8. contributes to an authored collection payoff.

## Initial Vertical-Slice Use

The first playable slice can demonstrate the entire concept with only three records:

1. one Eco-Kin field manuscript;
2. one damaged War on Life page;
3. one final record that connects the local ecological wound to both histories.

This proves environmental storytelling, EcoDex integration, mission design and archive UX without building the full collection system.

## Technical Data Direction — Design Only

Suggested authored data fields for future UE5 implementation:

- ManuscriptID
- CollectionType
- Title
- AuthorID / SourceLabel
- RegionID
- EraTag
- RelatedEcoKinIDs[]
- RelatedMissionIDs[]
- RelatedEventIDs[]
- FragmentIDs[]
- RequiredFragmentCount
- ReconstructionMethod
- AuthenticityState
- SummaryText
- FullText
- UnlockTags[]
- ContradictionLinks[]
- AccessibilityTranscript

Prefer data-driven Primary Data Assets / Data Tables and Gameplay Tags where appropriate. Exact C++/Blueprint architecture requires current project/build review before implementation.

## Production Routing

- War/Eco-Kin manuscript writing → `01_Story`
- regional placement → `02_World`
- Eco-Kin cross-links → `03_EcoKin_Dex`
- collection/reconstruction/progression rules → `04_Systems`
- physical placement / puzzle layout → `05_Levels`
- archive reader / map / evidence UI → `06_UI_UX`
- manuscript props / icons / effects → `07_Art`
- discovery / reconstruction audio → `08_Audio`
- UE5 implementation after dependency review → `09_Technical`
- milestone planning / validation → `10_Production`

## Verification Rule

This document approves the design direction only. No gameplay, UI, save persistence, accessibility behavior or UE5 implementation is considered VERIFIED until it exists in the repository and has appropriate build/runtime/test evidence.

**Final status:** MANUSCRIPT COLLECTION SYSTEM ADDED TO THE APPROVED-PENDING GAME DESIGN PATH; ECO-KIN AND WAR ON LIFE COLLECTIONS DEFINED; IMPLEMENTATION NOT YET VERIFIED.
