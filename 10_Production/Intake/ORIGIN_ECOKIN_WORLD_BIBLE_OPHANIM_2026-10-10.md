# ECHOHEARTS: REBEARTH
## Canon-Safe World Bible Addendum + EcoDex Design Record: OPHANIM

**Editorial status:** DESIGN PROPOSAL / SOURCE-RECONCILED / NOT CANON-APPROVED  
**Prepared:** 2026-10-10  
**Game:** Echohearts: Rebearth  
**Routing:** `01_Story` / `02_World` / `03_EcoKin_Dex/Intake` / `04_Systems` / `06_UI_UX` / `09_Technical` / `10_Production`  
**Executable authority:** `Dlomotion/ECHOHEARTS-REBEARTH-BUILD-` (Unreal Engine 5.8 C++)  
**Canon authority:** `Dlomotion/Echohearts-Rebearth`  
**Visual archive:** `Dlomotion/Echohearts-Ecokins`

> **Decision rule:** This addendum preserves useful features from the user-supplied Origin Eco-Kin / ECO-NET / Saviors / Battle Lab prototype. It does not replace the main campaign, create another Dex, assign a permanent production ID, verify a playable system, or approve third-party-derived imagery and names. All numbered values, skill behavior, forms, and build milestones below are **design targets**, not tested game data.

---

# 1. Executive creative direction

**One-line premise.** In the living world of Rebearth, a Core-Binder restores damaged ecology by learning how autonomous Eco-Kin live, protecting their right to choose, and recovering a planetary root network that still bears the scars of earlier attempts to control life. The later Star Rewrite reveals that the same choices matter beyond Rebearth.

**Three linked fantasies, one game:**

1. **Read the land.** Surface texture, migrating creatures, Blight patterns, water chemistry, ruins and weather reveal actionable history without requiring constant exposition.
2. **Earn a partnership.** Observe → Protect → Calm → Kindle → Bond / Release / Defer. A.E.G.I.S. assists; it neither owns nor stores a living being.
3. **Restore with consequences.** Each Sovereign Heartroot root-wound repaired changes access, migration routes, settlement support and nearby hazards; recovery does not erase scars or all natural danger.

**Core distinction:** Real-time player action + up to three voluntarily deployed Eco-Kin, sustained by a bi-directional **Anima-Link**. The player is not an invulnerable commander: unsafe tactics and ally strain feed back into the player's tactical cost. The remaining members of the eight-partner expedition roster are not inventory objects.

**Production promise:** a small, verifiable, authored vertical slice before a universe-spanning content promise. A 1,000+ name/species ambition remains a *long-term seasonal goal*, not an already approved or implemented roster. The original **125-ID Permanent Eco-Kin Dex** is protected; the **1,120-name historical pool** and the corrected **554-record review intake** are separate archival/review datasets.

# 2. Continuity and terminology repair table

| Pasted prototype language / contradiction | Canon-safe repair | Approval status |
|---|---|---|
| “Transmission 001 · Planet Earth”, “Idyll is only the first world” | Primary playable world = **Rebearth**. Earth is a possible later off-world source-message location, not a replacement origin. **Idyll** is a retired planet name. | Locked world precedence; Earth contact still proposal |
| Lord Dred begins the entire game | Rebearth Awakening and Sovereign Heartroot restoration remain the main opening campaign. Lord Dred and the Saviors belong to the later **War of Summoning → Star Rewrite** expansion bridge. | Expansion names recovered, final scenes pending |
| 18 elements; Light/Metal/Spirit/Dark/Primal and assorted cards | Exactly nine current Essences: **Flora, Torrent, Pyre, Terra, Aero, Glaze, Voltic, Aura, Shade**. Metal = material/Ancient Tech, celestial = presentation tag, Blight = condition, not extra Essences. | Locked |
| HP / Attack / Defense / Crit / Power / Resolve as public stats | Only **Vibrance, Density, Harmony, Purity** form the public Eco-Kin attribute matrix. Timing, recovery, stamina or status can exist as *mechanical state* without reviving alternate public character-stat roots. | Locked stat language; formulas pending |
| Capture, ownership, catch totals, capture device, trading Eco-Kin | **Discovery, documented field resolution, voluntary Kindling and partnership.** EcoDex stores encounters/help/bonds/research; supply markets never list sentient Eco-Kin or Eco-Eggs. | Locked |
| Breed/fuse/restart Eco-Kin as Eco-Egg upon defeat | No forced breeding, bodily fusion, sacrificial reboot, extracted cores or death-to-egg reward loops. Retain voluntary care, natural ecology, ethically managed nurseries and species-authored **Growth Rites / Biomimetic Shifts / Resonant Morphs**. | Locked boundary; replacement feature proposals |
| 8 party slots / 3 active | **Eight expedition partners, at most three active in real-time battles, no duplicate deployment**. No implied ownership or item storage. | Existing BUILD contract |
| Egg Heist / capture shrines / open trading | Replace with **Sanctuary Relay**, a consent-free *simulation token* contest, and **Accord Sites** restored/defended through ecological objectives. Never steal live eggs or trade beings. | Proposed modes; PvP fairness review required |
| “The Battle Lab is working” / listed hit numbers | **Battle Lab prototype specification only.** No gameplay, PIE, netcode, save, physical map or packaging is claimed implemented here. | NOT VERIFIED |
| Real-world angelic order names and direct sacred iconography | Keep in a **historical/cultural-source review lane**. Author original Echohearts factions and visual identity; do not copy recognizable religious iconography into launch art or assert new core creature categories. | Naming/originality review |
| Ophanim `#A-001` and other demo alphanumeric IDs | `#A-001`, `#E-014`, etc. are **legacy display-card labels**, not `EcoKinID`. Ophanim stays **UNASSIGNED** until a canonical identity/seasonal-ID decision. | Intake proposal only |
| Frequency Tamer vs Tamer of Beasts naming discrepancy | Repository core rules currently favor **Tamer of Beasts** (front-facing) while newer STARZ* and project briefs use **Frequency Tamer / Core-Binder**. Keep the conflict visible; use **Core-Binder** as neutral technical wording here pending product-facing name adjudication. | Governance decision open |
| Nature ordinary evolution / Legendary Monarch | **Nature is a Legendary Humanoid-Kin Guardian of Life with conditional Mutations**. Never replace Nature with a parallel guardian, generic evolution tree or forbidden title. | Locked |

# 3. EcoDex specification: discovery, history and hidden Eco-Kin

**EcoDex is a living ecological journal inside A.E.G.I.S.** It records evidence and relationships, not possessions. Each species has at least: `IdentityStatus`, `DisplayName`, `StableEcoKinID` (nullable until approved), `EncounterEvidence`, `BiomeEvidence`, `EssenceTags`, `ClassBodyPlan`, `ObservedForms`, `EcologicalRole`, `FieldAidHistory`, `KindlingStatus`, `ArtProvenance`, and `VerificationTier`. A game session records an encounter separately from a canonical species entry.

## The Hidden Eco-Kin discovery loop — proposed new feature

1. **Indirect sign.** Observe footprints, scent, pressure changes, unexpected pollination, repair marks, water movement, or habitat behavior. Not every trace means an Eco-Kin is available to bond.
2. **Triangulate.** A.E.G.I.S. overlays *evidence confidence* and ecological context without magical omniscience. False readings may be environmental, but should never trick players into harming a being.
3. **Resolve the habitat problem.** Repair a damaged channel, calm a disturbance, remove a Blight hazard, restore shelter or help another species.
4. **Witness / identify.** A rare Eco-Kin may reveal itself, leave new evidence, or decline contact. The EcoDex upgrades `TRACE_ONLY → OBSERVED → VERIFIED_IN_WORLD`; it never auto-promotes the *species design* to production canon.
5. **Consent branch.** Observe → Protect → Calm → Kindle → Bond / Release / Defer. All endings can count as successful field resolutions when safe and documented.
6. **Persistent ecosystem delta.** The world remembers: migration corridors open, root-wounds improve, shelters become used, and the player earns reliable knowledge rather than capture counts.

**Spawn fairness:** specify biome/time/weather/restoration prerequisites, authored discovery windows, readable clues, anti-grind pity/guaranteed clue logic if appropriate, accessibility cues for audio/visual impairments, and server-owned eligibility. Do not publish hidden-species names or assign IDs from prototype card labels. Discovery rarity is **not** a justification for aggressive randomized monetization.

**Versioned forms:** Each approved species may have a stable `SpeciesID` and multiple `FormIDs`, with form-state history, animation/mesh provenance and reversible or persistent rules depending on biology. Forms **do not** consume permanent species slots by default. Old artwork revisions are linked by provenance and never overwrite visual locks silently.

# 4. Canon-safe Codex record: OPHANIM (working label)

| Data key | Proposed record value |
|---|---|
| `WorkingName` | **Ophanim** — supplied historical/cultural label; originality, cultural context and public naming review **required** |
| `ProductionEcoKinID` | **UNASSIGNED**; do **not** use `A-001` or an `EK-###` card label as a permanent ID |
| `CanonStatus` | `SOURCE_CONCEPT_PENDING_CANON_REVIEW` |
| `CreatureKind` | **Autonomous Eco-Kin candidate**; no celestial species category inferred |
| `Order` | **Proto (candidate only)**; production biology/order classification unresolved |
| `BodyPlan` | **Suspended radial lamella-body**: six physically articulated mineral-organic sensing vanes around a living pressure-sensitive central core, small orientation tendrils, no forced humanoid anatomy |
| `Essences` | **Aura / Terra** *candidates only*; Ancient Tech as an affinity/material tag, not an extra Essence |
| `Habitat` | Damaged Meridian observation routes along Heartreach's Heartroot-linked highland fault margins (location pending level-map review) |
| `EcologicalRole` | Reads pressure fractures, dampens falling debris corridors, supports safe movement during localized terrain stress; does not control weather or survey all of Rebearth |
| `CombatRole` | **Defender / Survey Support** — deliberate projectile interception, hazard-marking and short protective windows rather than pure damage escalation |
| `Temperament` | Cautious and pattern-seeking; gravitates toward stable ground conditions and retreat routes; may refuse contact while protecting juveniles or under Blight strain |
| `BondMethod` | Repair a fractured survey route, demonstrate non-coercive evacuation assistance, document sustained calm behavior, then offer Kindling; release/defer remain valid |
| `Verification` | Naming, final artwork, Essence, stats, mechanics, UE5.8 DataAsset, animation, network and balance: **NOT YET VERIFIED** |

### Visual identity and cultural/originality firewall

The old card describes a spinning eye-filled heavenly wheel. **That is reference language, not a locked production silhouette.** The Echohearts-native proposal above uses six sensor vanes, irregular mineral layering, pressure-fed membrane motion, and small optical pores rather than rows of symbolic eyes. Art must demonstrate a distinct organic mechanism at silhouette distance; no copied sacred wheel/eye iconography or existing recognizable character design. Palette: weathered slate, verdigris, muted porcelain and localized amber diagnostic resonance (illustrative only). Six sensor vanes are **appendages, not legs**, with explicit collision, fold, and animation rules.

### Suggested attribute profile — design numbers only

| Vibrance | Density | Harmony | Purity | Source |
|---:|---:|---:|---:|---|
| **68** | **82** | **78** | **73** | Unapproved profile; 0–100; unbalanced |

These four scores must be calibrated against approved defensive/support baselines. **Purity is not a moral score**; it can represent a bounded project-defined quality only once the systems contract supplies semantics. The profile may be discarded after the canon and simulation tests.

### Combat role and four abilities — proposed

**1) Refraction Canopy — active protection.** Ophanim briefly rotates its pressure vanes to deflect a **bounded, line-of-sight** subset of projectiles within an authored arc. Counterplay: flanking, ground attacks, sustained pressure and timing windows. It does not grant invulnerability, global projectile immunity or unlimited reflection.

**2) Faultline Witness — scan/support.** Marks one nearby, validated terrain-stress zone for the team and highlights a safe crossing interval. Arena version reveals a **telegraphed** hazard cue instead of hidden opponent information. Access to enemy data is governed by authority/visibility rules.

**3) Counter-Arc — timing defense.** After a readable windup, redirects the momentum of one eligible incoming hit toward a nearby safe impact zone, with falloff and friendly-fire policy defined in data. Failure recovers normally; never displaces the entire world or guarantees hit cancellation.

**4) Haven Relay — cooperative field pulse.** Broadcasts a narrow safety route to allied rescuers/consenting Eco-Kin across unstable surfaces; can temporarily stabilize a rescue line, not permanently rewrite geology. The traversal effect has a timeout and fallback surface recovery.

**Anima-Link risk contract:** Protective intercepts expose Ophanim to strain. The player shares a *bounded and explicitly visible* tactical consequence when the link is sustained; reckless repeated guarding raises recovery cost and can trigger a voluntary disengagement. The exact cost function, cooldowns, replication authority and player feedback require approval and tests. Never treat injury as ammunition or consume an Eco-Kin to pay a skill cost.

### Growth Rite / forms (instead of forced “Evolution”)

| Identity-preserving state | Trigger proposal | Presentation / gameplay delta | Safeguard |
|---|---|---|---|
| **Survey Lattice** (baseline) | First calm, documented encounter | Six-vane survey stance; cautious hazard reading | Base species anchor, no alternate Dex ID |
| **Rootglass Relay** (Resonant Morph candidate) | Restore a linked Heartroot route **and** achieve voluntary stable partnership | Mineral membranes become translucent near living roots; stronger field-route legibility; not a universal heal | Same central core, six vanes, no identity reset |
| **Storm-Shear Mantle** (Biomimetic Shift candidate) | Complete a highland storm-shelter rescue and approve a habitat adaptation | Vanes fold into a wind-shedding arrangement; slightly wider protective arc traded against slower setup | Anatomical continuity and reversible-context review |
| **Blight-Stressed** (condition, NOT evolution) | Exposure to damaging Blight pressure | Distorted scan cues, strained motion, reduced willingness to act | Restoration/recovery path; never rewards deliberate harm |

No form is automatic from leveling, defeat or arbitrary fusion. Each must be species-authored, consent-aware, correctly rigged and balanced. Nature's separate **conditional Mutation** rules remain untouched.

### Field use and story encounter

- **Hidden encounter:** find repeating pressure ripples at three damaged observatory markers; the pattern is visible in sand and moving grasses before the player sees Ophanim.
- **First choice:** open an evacuation corridor for smaller wild Eco-Kin during a slope failure or exploit the exposed vault. Only the former advances trust; neither choice awards ownership.
- **Noncombat utility:** identify unsafe bridge anchors, redirect rescuers to a stable ledge, and document the extent of an ancient root-wound. Avoid making it a universal map-reveal shortcut.
- **Refusal:** if exhausted, frightened or guarding its habitat, Ophanim can withdraw. The EcoDex retains verified observation data even without partnership.
- **Environmental narrative:** old pressure markers reveal that the collapse was worsened by over-controlled Meridian infrastructure. A choice to restore a natural animal corridor versus recreate a rigid wall changes subsequent travel and migration outcomes.

### Art / animation / UI production requirements

Required art: silhouette sheet (front/side/top); six-vane joint-count map; ecological material pass; authored resting/scan/guard/retreat/stress animations; scale reference in actual Rebearth habitat; VFX that still reads with bloom reduced. Required A.E.G.I.S. presentation: scan confidence, shield arc, hazard certainty, strain warning, consent/withdrawal cue; no fake “heavenly rank” or new element badge.

**Codex UI card fields:** Working name, `PROPOSAL` banner, undisclosed stable-ID field, Essence candidates, observed behavior, provisional stat profile, **Combat Role**, **Growth Rites & Forms**, **Field Use**, provenance, and unavailable-runtime flag. For an in-game shipped card, only approved fields become public.

# 5. World Atlas — a map that changes when the world changes

The pasted world-grid names are **candidate local domain labels**, not replacements for the approved Heartreach continent and world map. Route each to existing regions before map production:

| Prototype locale | Canon-safe gameplay use | Gate |
|---|---|---|
| **Russet Highlands** | Fractured wind corridors, mineral pressure clues and provisional Ophanim encounter node | World-map and named-landmark collision review |
| **Mistwoods** | Opening-slice candidate: surface fog, fungal succession, injured migration network, species clues | Reconcile with approved Heartreach biomes; no duplicate continent |
| **Prismatic Coast** | Shoreline and reef restoration, safer currents, undersea sensing as later route | Connect to named existing regions |
| **Volcanic Ridge** | Pyre/Terra thermal corridor, disabled Meridian forge hazards | Link existing extreme-domain story |
| **Sky Island research hub** | Doctor/research contact and approved Riftway route; late unlock | Align with existing sky-locations, no omniscience |
| **Homeland / Sanctuary** | Rebuildable living settlement and voluntary Eco-Kin refuge; ecological capacity, care and restoration feedback | Align Echohearts Sanctuary; no forced labor |

**Atlas layers:** habitat health, root-wound history, observed tracks, safe routes, migration season, community requests, discovered Meridian nodes and confirmed EcoDex evidence. Fog-of-knowledge lifts only after relevant observations. Restoration deltas are visible in foliage, animals, currents, construction, NPC routines and dangerous-but-natural conditions.

**Added feature — Ecological memory overlays:** A.E.G.I.S. compares a player-observed current scene with one *authored* preserved state; players diagnose whether a blocked migration came from Blight, infrastructure or natural seasonality. This is not literal uncontrolled time travel. Narrative flags persist with source evidence and cannot be fabricated from global omniscience.

# 6. Battle Lab — bounded first-playable simulation spec

**Scope:** An optional **training/simulation** space for teaching real-time tactics; the existence of this chapter is **not a claim that the UI or playable simulation runs**. A proposed encounter may pit a player and three consenting partners against a telegraphed Blight-distressed hazard guardian in a safe authored arena.

**Input:** movement, light/heavy actions, guard, dodge, target selection, A.E.G.I.S. scan, issue partner *request* and swap active member (server validates three-active/eight-expedition limits). Partners may autonomously disengage due to consent, injury or unsafe tactics.

**Readability:** show skill windup, shield arcs, hit-reaction affordance, Essence interactions, environmental reaction and Anima-Link stress. Do not display unapproved HP/Attack/Defense as public Eco-Kin identity stats. Eight expedition slots do **not** mean eight simultaneous summons.

**Prototype success test:** player can identify a slope hazard, request Ophanim's shield at the right moment, use the noncombat survey clue to avoid harm and complete the encounter through restore/protect/retreat decisions. Failure teaches a safer route; it never rewards damaging a sentient partner.

**Balance validation:** ability use requires authored recovery and stamina budgets, predicted/server-reconciled state transitions, no unbounded reflect loop, deterministic hazard-trace permissions, AI refusal coverage, re-entry safety, and input accessibility. PvP variants require explicit simulated effects and equitable team visibility; no overworld PvP griefing.

# 7. STARZ* / Young Saviors continuity bridge (late expansion only)

**Recovered names for design work, not new Eco-Kin IDs:** Glitter, Sparkle, Bling, Dazzle, Bright, Light, Shimmer, Shine, Luminous; Radiant, Nova/Super Nova, Spectra, Milky Way, Nebula, Solar, Lunar; Lord Dred, Devoid, Darkvoid, Laseriz, Lunaz, Mena, Althea, Garth; Finao, Gradiaunt, Joyner and Joyce. Any contradictory role/class assignment must be adjudicated; e.g. a prototype card calls **Milky Way** a star-hound Eco-Kin while the current STARZ* integration lists Milky Way as an original Savior.

**A three-beat bridge:** (1) After substantial Heartroot and Riftway restoration, A.E.G.I.S./D.A.H.L.I.A. authenticates an intelligent stellar distress signal rather than declaring it a capture target. (2) The first STARZ* mission tests whether a rescuer can help damaged worlds without taking command of their inhabitants. (3) Lord Dred's fear-based regime is revealed as a post-Rebearth conflict in **Summoning Wars**, not a retcon of Rebearth's opening ecology campaign. An Earth transmission may become a later recovered scene if story review approves it.

**Original factions:** Define original, fictional relief/rift groups by function and character rather than importing literal sacred orders and ranks. User-supplied heavenly lists remain a **reference/retired rewrite-required** backlog pending cultural/context/originality review. The nine Young Saviors remain characters with voluntary alliances; a Huma-Link-capable human bond is not an Eco-Kin ownership record.

# 8. Multiplayer, Sanctuary and ethical economy — phased proposals

- **Co-op target:** four-player cooperative expeditions **after** the single-player vertical slice, with server ownership of discovery rewards, NPC trust and world deltas. The count is a design target, not tested network capacity.
- **World population target:** 32-player shared settlements are *future exploratory scope* requiring profiling, authority budget and anti-grief rules; not a launch promise.
- **Sanctuary and farm:** player/NPC management of crops, habitat, recovery wards and infrastructure; Eco-Kin choose voluntary partner aptitudes and can refuse or rest. Automated maintenance is machine/NPC-authorized, not forced sentient labor.
- **Trade:** equipment, crafted goods, seeds and research services only; **no sentient Eco-Kin, eggs, bonds or identity rights** as commodities.
- **PvP prototype:** Sanctuary Relay contests safe simulated markers; no real egg theft, coerced partner transfers or real-world griefing. Guild restoration quests reward ecological work rather than capturing shrines.
- **Growth:** protected living-nursery and natural lifecycle research; no breeding command, designer-assembled hybrid genome, death-to-egg restart or forced fusion.

# 9. Technical handoff — versioned payload, not fictional completed code

**Single source of truth:** Canon repo approves stable ID, season, name, Essence, forms and provenance. Visual archive maps actual asset checksums and visual-lock revisions. UE5.8 BUILD repo implements executable assets/components and retains build/runtime evidence. Web surfaces consume approved exports only.

**Suggested data boundaries:**

- `FEcoKinCoreAttributes` — **existing BUILD C++ header**: four float fields 0–100. This is a source contract, not proof every surrounding gameplay system exists.
- `FEcoKinCodexEntry` — **PROPOSED** stable ID (nullable in intake), approval flag, discovery knowledge state, non-sensitive ecological facts, observed forms and encounter log references.
- `FEcoKinFormState` — **PROPOSED** form/conditional-mutation identity, transition evidence, reversible behavior and visual asset provenance.
- `FEncounterEvidence` — **PROPOSED** scoped location, timestamp, trigger version, A.E.G.I.S. evidence and observed-only knowledge. No universal all-world tracker.
- `FSaveGameHeader` and `UCrossPlatformSaveManager` — **PROPOSED**, not verified implementations: schema/version, opaque account profile key, per-platform origin, UTC timestamp, signed revision/replay protection, authority and conflict resolution. Encrypt/authenticate in transit; minimize personal data; never expose credentials in save or repository.
- `ServerStateSnapshot / ClientCommandPayload` — **PROPOSED CONTRACT** for authoritative battle, Kindling, discovery, world state and inventory permissions. Client actions request; server verifies eligibility and produces versioned snapshots.

**Important correction:** progress must not be merged simply by `max()` across devices. Different values have different semantics: unlocked *immutable discoveries* may union after signed provenance and version checks; mutually exclusive quest choices need authoritative reconciliation; consumables/transactions require server ledger; partner relationships require authority and timestamps; form history must preserve causal transition order; no client-side false approval of an unassigned species. Offline conflict resolution must prevent replay, rollback and duplicate rewards.

**Suggested runtime modules (design grouping, not evidence of source files):** `EcoKinDiscovery`, `AnimaLinkCombat`, `EcoDexPresentation`, `WorldStateRestoration`, `SaveProfileSync`; implement within current `Echohearts` module unless architectural review warrants submodules. No COBOL/BASIC native UE gameplay modules. Standalone COBOL/BASIC utilities may validate CSV/JSON exports via shared golden test fixtures only.

**Automated checks to build before integration:** invariant 125 protected IDs; unassigned source candidates cannot spawn as production species; correct Essence enum and four-score bounds; form IDs do not mint species; server-only bond grants; no sentient market listing; bounded Anima-Link feedback; Refraction Canopy intercept limits; discovery clue determinism; no orphan asset paths; signed-save cross-device conflict replay; accessibility clue parity.

# 10. Vertical-slice implementation plan & evidence matrix

| Gate | Small demonstrable result | Pass evidence | Current designation |
|---|---|---|---|
| 0. Canon intake | Ophanim provisional entry approved/rejected for prototype; resolve name/cultural design, Order/Essence, world placement | Human review issue, provenance, art/identity decision | DESIGN PROPOSAL |
| 1. UE foundation | Stable BUILD 5.8 checkout, UHT/UBT Developer Editor compile and minimal map | Retained compiler/toolchain logs | NOT VERIFIED HERE |
| 2. Locomotion & input | One playable Core-Binder and one species-authored Eco-Kin with real animations | Editor launch, PIE 30s+, footage and functional tests | NOT VERIFIED HERE |
| 3. Hidden discovery | Three authored clues, habitat resolution, three possible outcomes (Bond/Release/Defer) | Acceptance tests of state machine and saved evidence | NOT VERIFIED HERE |
| 4. Real-time combat | Three-active roster validation, one telegraphed hazard, one defensive ability, Anima-Link consequence | Server/PIE tests, cost tracing, no reflect loop | NOT VERIFIED HERE |
| 5. World change | One small Mistwoods-like Heartreach biome and one root-wound with persistent visible restoration | Save/load, world-delta regression, map access tests | NOT VERIFIED HERE |
| 6. Build/profile | Development package and clean-launch; offline/reconnect test once cloud profile exists | Package logs, runtime, network/privacy tests | NOT VERIFIED HERE |
| 7. Scale decision | Four-player co-op, world atlas expansion and STARZ* planning only after gates 1–6 | Profiling and formal scope approval | FUTURE |

**First playable mission brief — “Faults Beneath the Canopy” (working name):** A weakened crossing causes local Eco-Kin to reroute through Blight-marked ground. A.E.G.I.S. detects pressure traces but cannot identify their cause. The player follows clues, prevents a small landslip, uses a consenting survey companion or authored equipment to locate stable anchors, and chooses a restoration path. The crossing reopens differently depending on the player’s solution. The encounter deliberately works with a different pre-approved Eco-Kin if Ophanim itself is not approved: **no vertical-slice dependency on promoting a new species**.

# 11. Outstanding decisions and release blockers

1. **Ophanim:** approve a new Echohearts-native name/design or retire source name; determine whether a unique species, an existing Eco-Kin form, a non-sentient guardian device or an archive legend. No permanent ID until reconciliation against protected 125 and historical 1,120-name pool.
2. **Professional title:** reconcile project brief's Frequency Tamer/Core-Binder with `CANON_CORE_RULES.md`'s front-facing Tamer of Beasts wording; do not quietly rewrite the lock.
3. **World grid:** map Mistwoods/Russet Highlands/etc. onto the actual Heartreach world index; no parallel planet or invented coordinates.
4. **Growth & care:** explicitly retire forced fusion/breeding/reboot, live-egg raids, sentient trade and incompatible score/element systems in UI drafts.
5. **Originality:** review sacred/mythic working names and generated art, including Ophanim, before consumer publication. Do not use original reference art as final asset.
6. **Existing PRs:** the corrected registry (#58) and visual catalog reconciliation (#62 in primary; #25 in art archive) are *draft/unmerged*, so this feature cannot override them or claim their provisional names as validated stable IDs.
7. **Build evidence:** no feature in this document may be marked compiled, optimized, secure or release-ready without direct tests in BUILD on a real UE5.8 environment.

## Source-of-truth references (repository paths)

- `Dlomotion/Echohearts-Rebearth/00_Canon_Lock/CANON_CORE_RULES.md`
- `Dlomotion/Echohearts-Rebearth/01_Story/ECHOHEARTS_REBEARTH_FINAL_STORY_CONTINUITY_2026-09-20.md`
- `Dlomotion/Echohearts-Rebearth/01_Story/STARZ_SAVIORS_UNIVERSE_INTEGRATION_2026-10-06.md`
- `Dlomotion/Echohearts-Rebearth/04_Systems/AEGIS_ECO_DEVICE_RECONCILIATION.md`
- `Dlomotion/Echohearts-Rebearth/04_Systems/GROWTH_RITES_RESONANCE_BRANCHES_AND_CHAMPIONSHIP_STATUS.md`
- `Dlomotion/ECHOHEARTS-REBEARTH-BUILD-/Source/Echohearts/Public/EcoKin/EcoKinCoreAttributes.h`
- Source discussions: primary draft PRs #58 and #62; art draft PR #25; STARZ* expansion lane.

*Editorial copyright / ownership: Echohearts: Rebearth project. This file is a proposed design handoff, not a legal copyright determination.*