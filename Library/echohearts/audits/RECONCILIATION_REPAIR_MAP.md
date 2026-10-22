# ECHOHEARTS: REBEARTH — Reconciliation Repair Map
**Date:** 2026-10-14
**Status:** AUDIT SURFACE — not canon, not a ruling. Reconciliation evidence only.
**Sources:** `~/workspace/echohearts-reconciliation/review-ledger.md` (2026-10-05) and `~/workspace/echohearts-reconciliation/consolidated-working-package.md` (2026-10-05). This map covers both documents fully: duplicates collapsed, ChatGPT self-claims stripped, superseded versions removed.

**Governing chain (unchanged):** MASTER_PROJECT_INDEX.md → ECHOHEARTS: REBEARTH Master Project Index → *Echohearts: Resonance Arena | Master Game Bible* → ECO_KIN_ART_MANIFEST.md
**Rule:** Nothing here enters `00_Canon_Lock` or `11_Publication` without Tay's review. Routes use only the existing `01_Story`–`10_Production` / `99_Reference_Retired_Needs_Redesign` folders. No new Bibles, Dexes, or structures.

## Evidence-tier key (exactly one per item)
- **CONCEPT** — proposed or pasted material; no repo presence, no verification.
- **SYSTEM CONTRACT** — locked canon ruling, merged contract/review verdict, or design authority; not runtime.
- **IMPLEMENTED** — exists in a repo (code or docs committed); not compiled, not run.
- **RUNTIME VERIFIED** — compiled / packaged / run with evidence. **Nothing in either source document qualifies. Stated explicitly so no item is ever misread as done.**

**Pasted-material rule:** every paste is reconciliation evidence, never auto-canon. ChatGPT's "approved / locked / verified / routed" self-claims are treated as CONCEPT unless Tay has ruled.

---

## PART A — ERRORS AND FIXES FIRST (working order)

### A1. Engineering errors (Kindling Bond Mechanics batch + CI/code samples)

| # | Error | Fix (working order) | Tier | Route |
|---|-------|---------------------|------|-------|
| E1 | Module/API contract conflict: `Echohearts`/`ECHOHEARTS_API` vs `EchoheartsRebearth`/`ECHOHEARTSREBEARTH_API` | **Resolved 2026-10-05 by direct BUILD- inspection:** project `EchoheartsRebearth`, targets `EchoheartsRebearthTarget(s)`, module **`Echohearts`** / **`ECHOHEARTS_API`**, `FEcoKinCoreAttributes` confirmed. Unify both repos on `Echohearts`/`ECHOHEARTS_API`; revise PR #18/#19's contract before any merge. Deviation noted: targets use BuildSettingsVersion.V6 + IncludeOrderVersion.Latest (not V7/Unreal5_8). | IMPLEMENTED | 09_Technical |
| E2 | Concatenated invalid `#include` directives (pasted C++) | Split and verify before any compile attempt. | CONCEPT | 09_Technical |
| E3 | Unsafe raw `USTRUCT` `Memcpy` over TCP | Replace with structured serialization. | CONCEPT | 09_Technical |
| E4 | Incorrect fixed packet-size claims | Recompute from actual struct layouts. | CONCEPT | 09_Technical |
| E5 | Reliable high-frequency RPC concerns | Redesign with unreliable/state-sync patterns where appropriate. | CONCEPT | 09_Technical |
| E6 | Insufficient authority checks | Server-authoritative validation required everywhere. | CONCEPT | 09_Technical |
| E7 | Hard thread termination | Replace with cooperative shutdown. | CONCEPT | 09_Technical |
| E8 | UE5.4 CI conflict (target is UE5.8) | CI must build against 5.8 only. | CONCEPT | 09_Technical |
| E9 | `.class` header typo | Fix filename/extension. | CONCEPT | 09_Technical |
| E10 | Client-supplied "integrity hash" treated as trusted | Must be server-validated. | CONCEPT | 09_Technical |
| E11 | Resource regression case rounds to **14**, not 15 | Correct the arithmetic in the case doc. | CONCEPT | 09_Technical |
| E12 | GitHub Actions YAML sample invalid (`name:`/`on:` joined; mixed PowerShell/bash; `cache: pip` without dependency file) | Rewrite against a known-good workflow. | CONCEPT | 09_Technical |
| E13 | Errno 2 on `verify_infrastructure.py` read as proof of checkout cause | Path-resolution failure — inspect actual repo state before changing CI. | CONCEPT | 09_Technical |
| E14 | Pasted claim "UEchoWorldStateSubsystem already exists" | Repo audit found only `FEcoKinCoreAttributes`. Unverified — no subsystem claims without code. | CONCEPT | 09_Technical |
| E15 | UE5.8 API claims (Niagara Data Channels etc.) in weather proposal | Unverified — verify against 5.8 headers before use. | CONCEPT | 09_Technical |
| E16 | Pasted Unity C# asset pack (EchoheartsCoreManager.cs, EchoheartsDevConsole.cs) | Prototype/reference only — singleton lifetime, OnGUI, legacy input, GameObject.FindWithTag, missing build guards. Production target is UE5 C++; translate, don't adopt. | CONCEPT | 99_Reference_Retired_Needs_Redesign |
| E17 | Code batch #33 (EchoJSONWebExporterSubsystem.h, DeployWebToS3.ps1, Unity combat UI with FLE_FLEE typo, PostgreSQL schema, Mecanim layout) | DRAFT/REFERENCE, NOT VERIFIED: concatenated #includes, hand-built JSON, hard-coded metrics, false CORS claim, SQL security issues. | CONCEPT | 99_Reference_Retired_Needs_Redesign |
| E18 | "Attunement Prism capture below 25% HP" (#40) | Capture mechanic vs Binding/Resonance Alignment — cut. | SYSTEM CONTRACT | 04_Systems |
| E19 | "AUTOMATED DOMESTICATION" (#40) | **Hard cut.** Violates the core partnership ethic (EcoKin choose to remain; Keeper is relational, not ownership). | SYSTEM CONTRACT | 99_Reference_Retired_Needs_Redesign |
| E20 | Parts 265–266 (EchoCompanionFollowSmokeTest, EchoStealthComponent) NOT VERIFIED | Non-standard mock-world API, false-pass on null world, Duration>0 proves nothing, smoke-test misuse; client-provided concealment state must be server-validated; use UAISense_Hearing::ReportNoiseEvent. "266 complete modules" is an unverified ChatGPT self-claim. | CONCEPT | 09_Technical |
| E21 | Parts 267/268/271/272/263/264/259/260 NOT VERIFIED | Same stealth/tag defects; cloud code is logging-only (needs real material-instance implementation); EC2 metadata endpoint wrong; `aws s3 sync --acl public-read` no longer a secure default. | CONCEPT | 09_Technical |
| E22 | "Echoheart" vs "Echohearts" naming mismatch ("Echoheart Rebearth," "Echoheart Game Studio") | Audit target; canonical is "Echohearts: Rebearth." | CONCEPT | 10_Production |
| E23 | Parts 13–255 C++ batches (v9/v10) NOT VERIFIED | UE 5.5 vs 5.8 version gate; repeating-key XOR ≠ AES-256; "214/255 modules" is reference numbering; UGameInstanceSubsystem/UWorldSubsystem are not replicated Actors; FluidFriction is an APhysicsVolume property; sandbox TArrays need Fast Array delta replication; altitude must not grant flight by coordinate; POI labels ("Windy City") are placeholders; Fire/Ice/Bio/Cosmic retired as competing element system. Canon repo has no .uproject/Source — next milestone: establish the Unreal runtime spine in a controlled branch. | CONCEPT | 09_Technical |
| E24 | "capture Terra-Crag with Prism" (#47) | Capture mechanic — cut. | SYSTEM CONTRACT | 04_Systems |
| E25 | 100-item asset index (#58) — PROPOSED/QA REQUIRED, not canon | "Sektor Anchors" → **Resonance Anchors** (stabilize voluntary Harmonization, never imprison, never guarantee bond); Sanity → fold into Harmony/Purity; **Vibrite Evolution Shard → Resonance Growth Catalyst** (satisfies a growth-state prerequisite, cannot force); Mythril/Chlorophyte/Luminite = poor final-production names; Sector Zero key count inconsistent (eight vs five); weapons support restoration, not creature-killing. | CONCEPT | 04_Systems |
| E26 | PR #9 (Issue #8 authoritative battle core): C++17 harness compiled warnings-as-errors, tests passed | **NOT YET VERIFIED** at Unreal level: packaged 5.8 build, real online session/RPC replication, two-client consistency, controller-first UI, real reconnect, latency, accessibility, battle-to-hub transition. Issue #8 stays open. | IMPLEMENTED | 09_Technical |

**Engineering direction (locked):** one module/API contract (E1), one naming prefix convention (`EH_` vs `Echohearts` — Tay decides, Part D.12), server-authoritative everywhere, UE5.8-only CI, no subsystem claims without code.

### A2. Canon conflicts (with fixes)

| # | Conflict | Fix | Tier | Route |
|---|----------|-----|------|-------|
| C1 | Module/API contract (sessions disagree) | See E1 — resolved by direct inspection; unify on `Echohearts`/`ECHOHEARTS_API`. | IMPLEMENTED | 09_Technical |
| C2 | Nature / DEX-002: Dictionary says BodyClass='Spirit', Recruitable=True; locked canon says Legendary Humanoid-Kin, never capturable | Correct row to Humanoid-Kin, Recruitable=False, add `HK_` naming convention. **Needs Tay (Part D.1).** | SYSTEM CONTRACT | 03_EcoKin_Dex |
| C3 | "Capture" language regenerating in pastes (capture/catch/Evolution Stones) | Terminology sweep on any adopted text → Binding / Resonance Alignment / Release; Growth Rites (no level-reset evolution). | SYSTEM CONTRACT | 04_Systems |
| C4 | Player identity: Frequency Tamer (locked) vs Core-Binder (locked combat discipline) vs Savior (cosmic layer) vs DZYN (NPC-012, not protagonist) vs "Tamer of Beasts" in 00_Canon_Lock | Proposed reconciliation: Frequency Tamer = profession/class; Keeper = relational term (pending); Core-Binder = combat discipline; Savior = cosmic-history layer. "Tamer of Beasts" must be revised or reconciled. **Needs Tay (Part D.2).** | SYSTEM CONTRACT | 01_Story |
| C5 | Stats: VIT/MGT/AGS/RSN/FORT/VEL, HP/Attack/Crit regenerating in pastes | Reject substitutions; locked matrix is Vibrance / Density / Harmony / Purity. | SYSTEM CONTRACT | 04_Systems |
| C6 | Elements: 18-element chart vs 12-element variants vs nine Essences (Flora, Torrent, Pyre, Terra, Aero, Glaze, Voltic, Aura, Shade) | Nine Essences are operational authority until the Elemental Matrix sheet is verified. Captured principle: ONE canonical matchup matrix, whatever the count. **Needs Tay (Part D.4).** | SYSTEM CONTRACT | 04_Systems |
| C7 | Professor Jackson vs Dr. Amara Quell (NPC-012) vs Dr. Valeri Vance | Proposal: keep Jackson + Quell distinct (both exist); retire Vance or map her into the archive. **Needs Tay (Part D.5).** | CONCEPT | 01_Story |
| C8 | "Splicer Guilds / DNA Fusion" as player culture (#4) | Conflicts with locked canon-development (DNA tampering = antagonist science). Keep as faction concept under 10_Production review; never player-default culture. | SYSTEM CONTRACT | 10_Production |
| C9 | "Lethal capture" of Rage Eco-Kin | Ruled correctly and locked: the ENCOUNTER may be lethal; the CAPTURE cannot be — a dead Eco-Kin cannot become a companion. | SYSTEM CONTRACT | 04_Systems |
| C10 | Outside-film copies: #17's "Sovereign Frequency" names **Korben Dallas** and **The Mondoshawan Matrix** | Other people's IP — hard cut. Strip from any adopted text. Inspiration-only rule. | SYSTEM CONTRACT | 99_Reference_Retired_Needs_Redesign |
| C11 | Astraea claimed Dex ID #115 | Candidate-not-weapon stands; Dex placement governed by the 125-ID authority only after the real xlsx is verified. **Needs Tay (Part D.11).** | CONCEPT | 03_EcoKin_Dex |
| C12 | Nova collision: DEX-032 "Nova" (Star Savior) vs Nova Star (five Stars) | Resolve during Dex verification. | CONCEPT | 03_EcoKin_Dex |
| C13 | "War on Life" vs "War on Humanity" (locked: War on Humanity, Era 3) | Adoptable only as in-fiction survivor quote: "the forests remembered it as the War on Life" — not a second war. | SYSTEM CONTRACT | 01_Story |
| C14 | Fusion: EMBER.md ban vs Concord Fusion (registered pairs only) | Resolve in 10_Production: Concord Fusion = the single controlled exception, or retire the ban. **Needs Tay (Part D.3).** | SYSTEM CONTRACT | 10_Production |
| C15 | Weather proposal exists; direction unapproved | Tay requested snow/rain/tornadoes/hurricanes with forecasts (2026-10-05). Forecast-driven design exists. Tay approves the design; implementation stays NOT VERIFIED. **Needs Tay (Part D.6).** | CONCEPT | 02_World |
| C16 | G.L.Y.T.C.H. roles across sessions (mech companion / mission-chain Ecoform / robotic Eco-Kin) | **Locked per Tay's latest direction:** G.L.Y.T.C.H. = robotic Eco-Kin creation; studyable in the Dex; "its glitch became freedom." | SYSTEM CONTRACT | 03_EcoKin_Dex |
| C17 | 8-carried/3-active (encounter lock) vs old "squads of five" dump | **Keep 8/3** until a design decision changes it. | SYSTEM CONTRACT | 04_Systems |
| C18 | Six direct-to-main commits (BUILD- `e5a0119`, canon `9d61194`, Echohearts-Rebearth `b2a54cf`, Echohearts `0a5fb6a`, Echohearts-Ecokins `a574555`, ECO-KIN-Game `e5882fe`) | Tay decides: revert or move to branches. No direct main pushes going forward. **Needs Tay (Part D.7).** | IMPLEMENTED | 10_Production |
| C19 | Level-70 evolution trigger (#42, Apis Regina via Maat's Blessing trial) vs Growth Rites | The trigger's *mechanism* (trial + bond) fits; the *level number* doesn't. Reconcile as a Growth Rite gated by trial completion and Kindling, not a level. | CONCEPT | 04_Systems |
| C20 | "Hunting Eco-Kin for crafting materials" (#33, weapons from hunted furs) vs Care Consequence | **Cut.** Materials come from shed/gathered sources, boss-cleansing, or restoration — never hunting companions. (Superseded 2026-10-14 by the willing-release-and-harvest ruling: shed/gifted resources only.) | SYSTEM CONTRACT | 04_Systems |
| C21 | Eco-Flux Growth Engine (#33: "insert multiple captured Eco-Kin to convert potential into EXP/stat boosts") | **Cut.** The banned duplicate-consumption pattern. Duplicates yield research/resonance, never consumed. | SYSTEM CONTRACT | 04_Systems |
| C22 | Armor/Weapon/Material "Evolution" (#33) vs fusion ban + conditional-Mutations-only | Armor Evolution (symbiotic plating) blurs into the fusion ban; "evolution path" language for Nature conflicts with conditional-Mutations-only. **Needs Tay's reconciliation** — keep Growth Rites as the mechanism. | CONCEPT | 04_Systems |
| C23 | "Echohearts: Veridian Keepers" as product subtitle (#55) vs Tay's fold-in ruling | Tay ruled Veridian material folds into Rebearth as connected missions, not a separate game. **Needs Tay (Part D.22).** | SYSTEM CONTRACT | 05_Levels |
| C24 | Dex V2 185-entry roster (#53) vs 125-ID Dex authority | V2 is a candidate, not canon. Names, Attribute Families, stages, legacy combat stats, Card Aura Forms, reclamation functions, "EchoStable Network," Bond% table stay proposal until adjudicated against the 125-ID registry. | CONCEPT | 03_EcoKin_Dex |
| C25 | "City = Echohearts" (#34's claimed canon correction) | Confirm the city name, or strike it. **Needs Tay (Part D.18).** | CONCEPT | 02_World |
| C26 | "Binder" (#35's player class title) vs Frequency Tamer (locked) | Reconcile or retire. **Needs Tay (Part D.20).** | CONCEPT | 01_Story |
| C27 | "Core-Bound Champions" (#28) vs Core-Binder (locked combat discipline) | Reconcile or retire. **Needs Tay (Part D.17).** | CONCEPT | 01_Story |
| C28 | Heart-Code Resonance (#36) vs Kindling/Resonance (locked) | Fold as synonym/era term, or retire. **Needs Tay (Part D.23).** | CONCEPT | 04_Systems |

### A3. Terminology sweep list (apply to any adopted text)

| Locked term | Drift to sweep out | Tier | Route |
|-------------|-------------------|------|-------|
| EcoKin (creature) | "Eco-Kin" / "ECO-KIN'S" variants | SYSTEM CONTRACT | 10_Production |
| Ecoform = form/state | "Ecoforms as creatures" | SYSTEM CONTRACT | 03_EcoKin_Dex |
| Binding / Resonance Alignment / Release | capture / catch / deployment | SYSTEM CONTRACT | 04_Systems |
| Growth Rites | evolution / Evolution Stones / level evolution | SYSTEM CONTRACT | 04_Systems |
| Keeper (relational, pending) | Tamer-as-ownership | CONCEPT | 04_Systems |
| Vibrance / Density / Harmony / Purity | any substituted stats | SYSTEM CONTRACT | 04_Systems |
| Shadow = condition | "Shadow-Kin" as category | SYSTEM CONTRACT | 04_Systems |
| Blight (locked term) | "Void-Blight" variants | SYSTEM CONTRACT | 04_Systems |
| Humanoid-Kin | "Kin" / "Humanoids" loose usage | SYSTEM CONTRACT | 03_EcoKin_Dex |
| G.L.Y.T.C.H. (spelling locked) | GLYTCH / Glitch variants | SYSTEM CONTRACT | 03_EcoKin_Dex |
| Genomic Grafting | loose "DNA splicing / DNA fusion" | SYSTEM CONTRACT | 04_Systems |
| "Echohearts: Rebearth" | "Echoheart Rebearth" / "Echoheart Game Studio" | SYSTEM CONTRACT | 10_Production |

---

## PART B — VALID MATERIAL BY FOLDER (working order)

### 01_Story
- Sovereign Resonance Arc (reconciled): Heartroot Resonance Array (ecological immune response, not weapon); four Resonance Keys = the four attributes; Sovereign Resonance = synchronization; Virus = fear→control cycle + false-prophecy alteration; Wardens of Seconds; D.A.H.L.I.A. mystery; imperfect endings. — **SYSTEM CONTRACT**
- Ancient civilization / portal package: EcoKin, Sanctuaries, portal tech predate humanity; Grand Fracture from accumulated strain; portal network name proposed: **Echo-Warp Gates**; First Crossing Era; Sanctuary loop (Discover → Observe → Protect → Stabilize → Kindle → Restore → Reconnect). — **CONCEPT**
- 30-NPC registry (Working/Locked statuses as written; DZYN stays NPC until Tay decides); manuscript series (six titles); 8-act/20-chapter campaign spine. — **CONCEPT**
- War continuum + U.N.I.T.Y. ("United Network of Individuals, Tribes & Yonderworlds"); Event Sovereigns (Morrowmire Colossus, Vesperwing Parallax, Crownspore Regent, Riftback Leviathan, Hushglass Warden, Basalith Warden — one-time world encounters); Homeland = Sanctuary hub; Sky Haven = research hub. Five ideas to protect: (1) Eco-Kin can choose not to join; (2) relationship changes gameplay; (3) the planet remembers; (4) growth tells a story; (5) letting go can be progression. — **CONCEPT**
- Nature profile: supreme Legendary Humanoid-Kin, protector of the Circle of Life. "She does not rule Rebearth. She keeps it alive." — **SYSTEM CONTRACT**
- Aetherland-era material: parallel draft — migration only; contradictory terminology → 99. — **CONCEPT**
- Circle of Life mission (Tree of Life world-organ; 4 factions; Circle Verdict endings Restore/Rewrite/Shatter); endgame systems (Resonance Rifts, Eco-Scars, Grand Binder Trials, Anomaly-Kin); "Your World. Your Ecosystem." — **CONCEPT**

### 02_World
- Four cultures: The Rooted (First Grove), The Ascendant (Sky Haven), The Hollowed (Deep Echo), The Unbroken (Iron Exile). Canon regions list (Sanctuary, Sky Haven/Sky Island, Great Plains, Blackfell, Arkam, Cinderfall, Azure Coastline, Silica Glade Fracture, Neon Sea, Rotting Maw, Scorched Barrens, Steel Frost, Crystal Desert, Shadowed Highlands, Boiling Abyss + biomes) — interconnected ecological regions, not level zones. — **CONCEPT**
- Living ecosystem simulation (statistical background model, trophic cascades, Eco-Kin vs Eco-Kin encounters mostly non-lethal). — **CONCEPT**
- Weather: forecast-driven design exists per Tay's request — **needs Tay's design approval (Part D.6)**; implementation NOT VERIFIED. — **CONCEPT**
- ERA I–V world progression; Restoration Gameplay Backbone loop (SURVIVE → CARE+FARM → BUILD → RESEARCH → REVERSE-ENGINEER → EXPLORE → SOLVE → FIGHT → ACQUIRE → RESTORE → EXPAND → REPEAT); visible restoration states; evolution pressures (not level thresholds); 8 parallel player progressions. — **CONCEPT**
- Reclamation Protocol (subterranean excavation, Living Architecture, forging tiers, Boss Summoning Relics — goal is cleanse, not murder); Sky Exploration (8 sky zones; "Ground restores roots. Sky restores breath."); settlement economy (8 currencies); research-as-progression; Chil-Kin daily work system (Legendary/Ancient/Mythic never farm workers). — **CONCEPT**

### 03_EcoKin_Dex
- Dex authority = 125-ID registry (**not canon-confirmed until the real xlsx is uploaded**). Encounter states as classification (Rage/Alpha/Blight/Hollow/Omega); Omega = Humanoid-Kin, never bound; Nature exception. — **SYSTEM CONTRACT**
- 8/6/4/2 Ecological Morphology Capacity (8-State Hyper-Adaptive, 6-State Branching, 4-State Adaptive, 2-State Reactive lists). — **CONCEPT**
- New creature candidates — **ALL pending Dex-collision adjudication** (package §4 table: Resonance Kit lines, Iron-Spark line, Botan-Bug line, Stone-Treader line, Aether-Wisp line, Xochiprowl, Ignisoul/Blazewarden [now mid-game candidate per 2026-10-12 starter ruling], Vuyamba/Starfisheron/Frost Lion, Paw, LUNA MOTH, Ferronix/Cinderplate/Perchara, Veridian roster, Mime/Misery Mime, Wave 1 Baby Eco-Kin, AZURA, Dante Inferno queue, Ghoul dossier, bee lines, Dryad, Glow Worm, card system, neon wolf-girl poster, Worm Eco-Kin, Unbound, Guardian Beast roster). — **CONCEPT**
- Protected identities: Nature, Plainsman, Ash-Brawler, Twilight-Tricker, Reaper-Skull, Cygnoris, Cygnaturis, Terravox, Azurithor, Blossomi, Hellomi, Chimpanzion. — **SYSTEM CONTRACT**

### 04_Systems
- 14-path companion acquisition matrix; core rule: **"A COMPANION IS A RELATIONSHIP, NOT A CONTAINER."** — **SYSTEM CONTRACT**
- Growth Framework: Echoprint, Growth Rites, no sacrifice, Anima-Link strain costs, Concord Fusion (registered pairs only), Shimmer as identity-preserving ascension. — **SYSTEM CONTRACT**
- Resonance Mutation system (triggers/outcomes; villains force Mutation, the Tamer unlocks it through trust/restoration/care). — **CONCEPT**
- Player-path system (14 paths) + reputation + Circle Balance Gauge; Gift Code system (no power rewards; Nature never via code); Field Journal evidence system; Resonance Counter Window; FWorldState (four attributes as simulation variables); FEcoKinMemory (fits Care Consequence); combat support systems (Command Burst, SYNC, Neural Overload, Villain Pressure). — **CONCEPT**
- Master Items & Materials Registry (737 entries, doc ChatGPT-side): rejected items — Unity C# scripts, "Eco-Traps" language, Poké-Ball-equivalent modules, outside-game item mappings. Candidates pending Dex-collision: Basalt-Maw, Shard-Back, Chrono-Hound, Shock-Stinger, Thistle-Crown, Mire-Stalker. — **CONCEPT**
- **Willing-release-and-harvest ruling (2026-10-14, Tay):** willing release of a duplicate yields shed/gifted bodily resources (molted scales, shed feathers, fallen petals, sap, spores, crystal shards, essence traces); star tiers Yellow → Bronze → Silver → Gold → Platinum → Purple → Red (one star per 100 units); part-based crafting (method only, never outside content); **release is not sacrifice; sacrifice is forbidden.** — **SYSTEM CONTRACT** (code: IMPLEMENTED, not compiled)
- Nature design sheet (Tay's own spec): Guardian of Life / Elemental Flora, Legendary Humanoid-Kin; abilities Life Burst, Growth Shield, Nature's Embrace, Ancient Bloom; "Seedling → Verdant → Prime Guardian" path conflicts with conditional-Mutations-only — needs reconciliation. — **CONCEPT**
- 6 Primordial Wardens (CONCEPT candidates, pending Dex collision; Umbrenox needs Shadow-as-condition check). — **CONCEPT**
- AI Narrative Director as "World Director" (AI never invents canon; validation hierarchy CANON → GAME RULES → WORLD SIM → PLAYER ACTION → AI INTERPRETATION → VALIDATION → CONSEQUENCE). — **CONCEPT**
- Visual-development rules (unique silhouettes, correct anatomy, no recycling rejected concepts). — **CONCEPT**

### 05_Levels
- Veridian fold-in map: Aethelgard material folds into Rebearth as connected missions (Tay's ruling); Five Stars = main-story missions. — **SYSTEM CONTRACT**
- Landscape/Isles/World Map track: WorldRegionID → IslandID → LandmarkID → MapLayerID architecture; AWorldPartitionMiniMap is editor-only. Hard rule: Unity/C# material must not turn Echohearts back into Unity. — **CONCEPT**
- Level 8 / bond 35% branch data (Piplin → DEX-106) preserved as artifact evidence; conflicts with manual's 40% Kindling claim — flagged, not resolved. — **CONCEPT**

### 06_UI_UX
- A.E.G.I.S. six-view UI + mutation meter / shard menus / form unlock screens; UI terminology sweep doc stays the reference; no outside-game UI copies. — **CONCEPT**

### 07_Art
- **Tay's study-only rule (standing IP boundary):** study other creature games; never put their characters in this game; create original content; don't mention predecessors publicly. — **SYSTEM CONTRACT**
- CHARACTER_VISUAL_CONTINUITY_LOCK: approved identities immutable; variants attach to CharacterID/DexID. — **SYSTEM CONTRACT**
- Visual naming `EK_[DexID]_[Name]_BASE_LOCK` + state variants (RAGE/ALPHA/BLIGHT/HOLLOW/WEATHERPULSE/SHIMMER). — **CONCEPT**
- Zodiac Eco-Kin art series exists as concept art; creature names not captured — needs classification when images surface. — **CONCEPT**
- Naming bible / form-stage roster sheet / PNG asset-pack checklist — **to build** (Tay requested in #23).

### 08_Audio
- 89 EcoKin audio entries + 17 score cues + 18 soundscapes + 186 generated WAVs — **CANDIDATE, NOT CANON, NOT RUNTIME VERIFIED.** — **CONCEPT**
- Theme song (working title "Echoheart — Every World for You") — needs lossless WAV + Tay's approval (Part D.10). — **CONCEPT**

### 09_Technical
- Worldrunner QA architecture (developer-only QA tool; NOT the shipped game); ECO-TEL-001 / ECO-API-001 / BCT-001 contract IDs (evidence unverified); naming QA gate (names/IDs/tags must agree with the canonical registry). — **CONCEPT**
- Foundation gate: UE5.8 UHT → Development Editor Win64 compile → Editor launch → PIE → packaging evidence. **All unverified.** Canonical identity per #74/#75: EchoheartsRebearth.uproject, module EchoheartsRebearth, ECHOHEARTSREBEARTH_API — **conflicts with BUILD- inspection (E1); do not merge PR #18/#19 blindly.** — **CONCEPT** (spec) / **IMPLEMENTED** (BUILD- side)
- Issue #10 vertical slice spec (Professor Jackson + Tidequill DEX-046): NOT YET VERIFIED. Production-gate order: PR #14 → UE5.8 foundation → Issue #10 slice → 4–6 Eco-Kin funding slice → Growth Rite → Event Sovereign → registry/UI/save → Oligarch → networking/destruction → seasonal. — **CONCEPT**
- Cloud/MMORPG architecture reference — **FUTURE OPTION only**; locked direction is single-player + optional 4-player co-op first. — **CONCEPT**

### 10_Production
- PR verdicts: #1 rebase+normalize (Tay's decision); #2 CODED, NOT YET VERIFIED (gates 0–4); #14 request-changes (competing sync standards, unsafe CI template); #17 ACCEPTABLE TO MERGE AS CANON/SYSTEM/TECHNICAL CONTRACTS only (pre-merge: compact PR17_ACCEPTANCE doc; minimum evidence chain); PR #16 merged (closes no runtime gate). — **SYSTEM CONTRACT** (verdicts) / **IMPLEMENTED** (merged items)
- 18-stage production order (from #84, supersedes 13-stage). — **SYSTEM CONTRACT**
- Authority tiers: CANON PREMISE / APPROVED-PENDING BACKLOG / VERTICAL-SLICE CANDIDATE / FUTURE OPTION / NOT COMMITTED. — **SYSTEM CONTRACT**
- Mutation Tree canon-safe architecture (EcoKinID → Instance GUID → Current FormID → Mutation Profile; Genomic Grafting safe classes; Fusion boundary; Heritage Pairing species-specific). Retired list (generic stat matrices, universal three-stage evolution, duplicate-sacrifice, forced DNA extraction, universal cross-species fusion, commodity trading, permanent sentient storage, universal death→egg, level-based transformation, auto-generated Dex numbers). — **SYSTEM CONTRACT**
- Master Publisher & Investor Pitch (33 sections): $3M milestone ask; ~$23–24M envelope; M1→M4; Issue #10 = production gate; $49.99 premium AA, no buying Bond/Eco-Kin/power/loot-boxes. Pitch-only claims (market forecasts, unit benchmarks) are NOT production facts. — **SYSTEM CONTRACT** (production facts)
- BUILD- repo facts (Oct 3): private, initialized only (.gitignore + README, generic C/CMake); authority split — PR #17 = design-and-contract, BUILD- = implementation/build. Verification gate BUILD-01 defined. — **IMPLEMENTED**
- Locked Encounter Rank Ladder: Common → Uncommon → Rare → Unique → Alpha → Omega → Legendary (encounter classification, not power stat). — **SYSTEM CONTRACT**
- Catch interaction: Survey → Lure/Approach → Safehold → Calm → Kindling Offer → Bond/Release/Defer; "Catch" = containing the encounter long enough to reach voluntary Kindling (NOT a probability roll); trap families listed. — **SYSTEM CONTRACT**
- Physical Form Registry (no new Dex IDs): Base, Growth/Evolution, Healthy Adaptation, Environmental Adaptation, Deviant Mutation, Purified/Recovered, Temporary Resonance, Shimmer, Seasonal, Holy, Dark Void, Conditional Legendary Mutation. — **SYSTEM CONTRACT**
- DNA/Mutation correction: Exon Expression Remap, Regulatory Sequence Tuning, Point Mutation, Genomic Graft (shed material only); DNA Fusion = Heritage Pairing / Genomic Grafting / authored Fusion Forms; no duplicate-sacrifice. Collection Tracker: Unknown → Sighted → Surveyed → Safeheld → Kindling Offered → Bonded/Released/Deferred. — **SYSTEM CONTRACT**
- Direct-to-main policy: no more direct main pushes; six existing commits await Tay's decision (C18). — **SYSTEM CONTRACT**
- Seasonal DLC lists (~172 names) stay archive/DLC proposals. — **CONCEPT**

### 11_Publication
- Public verification-status page exists; keep current. Nothing new routes here without review. — **IMPLEMENTED**

### 99_Reference_Retired_Needs_Redesign
- Retired names: Flare-Vulpix (→Flarevane), Storm-Zues, Abyssal-Hades, "Nuture" typo, "Tamer of Beasts" (pending reconciliation). — **SYSTEM CONTRACT**
- Superseded: old "Ecoforms-as-creatures" proposal, capture/catch language, VIT/MGT stats, 18-element chart (pending Essences decision), squads-of-five dump, Korben Dallas / Mondoshawan Matrix references (hard-cut). — **SYSTEM CONTRACT**
- Unity C# packs, #33 code batch, Terraria-structure progression paste (functions only, never content/bosses), "North Korean fauna" theme, failed-read link #18, superseded Master Bible Word docs + alternate folder numbering. — **CONCEPT**

---

## PART C — MISSING EVIDENCE REGISTER (what would promote each claim)

| Missing | Blocks | Tier until received |
|---------|--------|---------------------|
| Real `Echohearts_Game_Data_Dictionary.xlsx` (only artifacts recovered) | 125-ID Dex canon confirmation; Elemental Matrix sheet (C6/Part D.4) | CONCEPT |
| Expanded manual `.docx` (claimed 54 pages) | Story/production text adoption | CONCEPT |
| Audio pack ZIP (186 files) | 08_Audio canonization | CONCEPT |
| PR #17 breakdown Markdown files | PR #17 merge evidence chain | CONCEPT |
| ECO-TEL-001 telemetry package | Telemetry contract | CONCEPT |
| `ECHOHEARTS_REBEARTH_VERIFICATION_STATUS.md` | Verification-status claims | CONCEPT |
| All UE5.8 compile/package/runtime evidence | Every IMPLEMENTED → RUNTIME VERIFIED promotion | IMPLEMENTED (code) |
| PR #18/#19 live status | Any merge action | CONCEPT |
| PR #3 on BUILD- (draft, `architecture/core-systems-foundation-2026-10-04`) | Merge/revise/close decision (Part D.15) | IMPLEMENTED |
| Issue #12 contents | PR #18/#19 audit action | CONCEPT |
| Ten uploaded images (2026-10-05) | Classification | CONCEPT |
| Cartography/weather material provenance | 02_World adoption | CONCEPT |
| Link #18 "Audit UE5.8 Pull Requests" body | Consolidation completeness | CONCEPT |
| Upload order (Tay's priority): xlsx → docx → PR #17 files | — | — |

---

## PART D — PARKED CREATOR DECISIONS (verbatim, unresolved — Tay only)

1. DEX-002 Nature row correction (Humanoid-Kin, Recruitable=False).
2. "Tamer of Beasts" in 00_Canon_Lock vs Frequency Tamer.
3. EMBER.md fusion ban vs Concord Fusion.
4. 18 elements vs nine Essences (pending Elemental Matrix sheet).
5. Jackson / Quell / Vance NPC lineup.
6. Weather direction: **Tay requested it** (snow/rain/tornadoes/hurricanes with forecasts); the forecast-driven design now exists — Tay approves the design, then implementation stays NOT VERIFIED until it compiles and runs.
7. Revert or branch the six direct-to-main commits.
8. Module/API contract — **RESOLVED 2026-10-05 by direct inspection:** BUILD- = project `EchoheartsRebearth`, targets `EchoheartsRebearthTarget(s)`, module **`Echohearts`** / **`ECHOHEARTS_API`**, log `LogEchohearts`, `FEcoKinCoreAttributes` confirmed. Recommendation: unify both repos on `Echohearts`/`ECHOHEARTS_API`; revise PR #18/#19's contract before merge.
9. Seasonal/Holy/Dark Void lists: archive/DLC or cut.
10. Theme-song approval/provenance + lossless master.
11. Astraea Dex placement (candidate-not-weapon stands; ID only via verified registry).
12. `EH_` vs `Echohearts` code prefix convention.
13. Upload order: Data Dictionary xlsx first, then manual docx, then PR #17 files.
14. **Name generation:** pick the #25 (May 8) or #19 (Sep) cleaned-name generation — or pick per line (see §9 table). Neither generation is canon until Tay picks.
15. **PR #3 on ECHOHEARTS-REBEARTH-BUILD-** (draft, opened 2026-10-04 by the ChatGPT session; branch `architecture/core-systems-foundation-2026-10-04`): UEchoWorldStateSubsystem, FEchoRegionRuntimeState, UEchoRegionDefinition, tests, architecture doc, build script, CI workflows. Review and decide: merge, revise, or close.
16. **PR #18/#19 action:** live status (Oct 3–4): #18 mergeable:false, #19 mergeable:true, both open drafts in the canon repo, both using the contradicted `EchoheartsRebearth`/`ECHOHEARTSREBEARTH_API` contract. **Update 2026-10-05:** direct BUILD- inspection confirms module `Echohearts`/`ECHOHEARTS_API`. Revise both PRs to the `Echohearts`/`ECHOHEARTS_API` contract before any merge; do not merge blindly.
17. **"Core-Bound Champions" term** (#28) vs Core-Binder (locked combat discipline) — reconcile or retire.
18. **"City = Echohearts"** (#34's claimed canon correction) — confirm the city name, or strike it.
19. **Aetherland-era migration** (#35): adopt the useful ideas (Circle of Life mission, endgame systems, factions) via canon migration, or archive the whole era to 99. Older terminology must not overwrite Rebearth canon.
20. **"Binder"** (#35's player class title) vs Frequency Tamer (locked) — reconcile or retire.
21. **Starter selection — DECIDED 2026-10-12 (Tay): Option C, Hybrid.** Piplin is every Frequency Tamer's first Kindling — the universal tuning-fork partner whose four Resonance Accent forms (Quickleaf, Barkguard, Chorusvine, Clearsap) teach the four Resonance Keys. All further partners come through the 14-path companion-acquisition matrix; "ReBearth picks you a responsibility" is reserved as the story device for key story partners (e.g., Nature-adjacent beats). Consequence: the Ignisoul/Blazewarden line is NOT a starter — it becomes a Dex-collision candidate for mid-game Flora/Pyre placement (or cut); final placement still open. Note: the accent-forms→Keys mapping is an inference, not locked canon.
22. **Veridian Keepers order name** (#36) vs the fold-in map (Aethelgard material folds into Rebearth as connected missions — Tay's ruling stands). Keep the order name as a faction, or retire it.
23. **Heart-Code Resonance** (#36) vs Kindling/Resonance (locked) — fold as a synonym/era term, or retire.

*These are listed, not decided. Nothing above is resolved, reworded, or merged into canon by this map.*

---

## PART E — CUT LIST (routed to 99)

1. Outside-film copies (Korben Dallas, The Mondoshawan Matrix) — hard cut, never canon.
2. ChatGPT self-claims ("approved / locked / verified / routed") — treated as CONCEPT unless Tay ruled.
3. The Daily Game Work schedule — ChatGPT-side artifact; not part of this project's evidence.
4. Superseded terminology (Ecoforms-as-creatures, capture language, VIT/MGT, 18-element authority, Evolution Stones, squads-of-five).
5. IP-collision names (Flare-Vulpix → Flarevane done; Storm-Zues, Abyssal-Hades → 99).
6. Failed-read link #18 — excluded until re-shared.
7. "North Korean fauna" theme — never approved.
8. Splicer Guilds as player-default culture — kept only as possible antagonist faction concept.
9. Compile/runtime/packaging claims with no evidence — all stay NOT VERIFIED.
10. Ignisoul/Blazewarden as starter — retired by 2026-10-12 ruling; mid-game candidate or cut.
11. Superseded Master Bible Word docs + alternate folder numbering — contents survive as CONCEPT where valid.
12. Terraria-structure progression paste — design functions only; never content, names, or bosses.
13. Problematic names (Dr. Evil, Sylar, "Ken Jen — Asian fighter", "Prince of Persia") — cut or rename before any use; ~180-name roster needs uniqueness audit.
14. Old core-gameplay dump (18 elements, Eco-Device capture, level evolution, IVs/EVs, squads of five, breeding/fusion-as-consumption, stat blocks) — retired.
15. "Kin-Master" term — retired (conflicts with Frequency Tamer).
16. "Keisha" — accidentally generated; replace in naming audit.
17. AI co-designer stage "MUTATION" as ordinary stage — retired (conflicts with conditional-Mutation canon).
18. "Hunting Eco-Kin for crafting materials" / Eco-Flux Growth Engine — cut (superseded by the 2026-10-14 willing-release-and-harvest ruling).
19. "AUTOMATED DOMESTICATION" — hard cut (partnership ethic).
20. Unity C# packs treated as production code — translate, don't adopt.

---

*End of repair map. Audit surface only — it changes no canon, resolves no parked decision, and creates no new authority.*
