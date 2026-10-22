# Echohearts: Rebearth — Game Gap Analysis (2026-10-17)

**Method:** full walk of `Source/Echohearts/` (89 files: 52 headers, 37 cpp), cross-checked against MEMORY.md canon, all six `04-systems-proposals/` docs, and `code-update-diff-2026-10-15.md`.
**Read-only audit. Nothing modified.**
**Standing caveat:** nothing has ever been compiled. "Coded" below means *written*, not *proven*.

---

## 1. Coded and real

These systems exist as genuine implementations (logic, gates, state — not just types):

| System | Files | What it does |
|---|---|---|
| Anima-Link (component) | `AnimaLink/AnimaLinkComponent` | Bidirectional link state: strain, fracture risk, tamer overexertion, transformation cost gate |
| Anima-Link combat | `AnimaLink/AnimaLinkCombatSubsystem` | EcoKin damage → tamer stamina; tamer commands pay strain; hit resolution |
| Kindling / trust | `EcoKin/KindlingProgressionSubsystem`, `EcoKinKindling.h` | Trust % 0–100, trust events, 80% threshold, rite eligibility |
| Growth Rites | `EcoKin/GrowthRiteSubsystem` | All 4 gates enforced (Biological Maturity, Kindling, Ecology accomplishments, Catalyst); catalyst consumed |
| Mutation director | `Mutation/` | Nature identity gate (conditional-only), mutation trigger kinds incl. ResonanceStrain |
| Dex + Forms registry | `EcoKin/EcoKinDexSubsystem` | Identity registration, form attach incl. Shimmer identity-preservation validation, 8-carried/3-active squad contract |
| Summoning | `Summoning/` | Bonded-only calls, trust gate, device charge, distance-scaled strain, fail-closed refusals, ceremony lock, free return |
| Corruption | `Corruption/` | 5-stage path, zone-exposure tick, stat redistribution (never inflation), exact-stat purification revert, fracture → Shadow (**2 compile errors — see §3**) |
| Concord Fusion | `Fusion/` | Registered pairs only, rite stages 40/65/85, DNA stability + D.A.H.L.I.A. gate, dormant-resonance no-sacrifice, unfuse restores |
| Sanctuary residents | `Sanctuary/` | 6 roles, milestone arrivals, services, anchors, expansion tiers, defense scaling |
| Boss progression | `Progression/` | 14-boss order, required/optional gating, world-era transitions, phase + arena defs |
| Release + harvest | `Release/` | Willing release → shed resources, star tiers (Yellow→RedStar), flora harvest nodes |
| Save system | `Save/` | Versioned schema, slots, atomic saves, forward migration |
| Game phases | `Game/EchoheartsGameMode` | Exploration/Combat/Ceremony/Dialogue/Menu with broadcast transitions, ceremony input lock |
| Tamer character | `Tamer/FrequencyTamerCharacter` | Third-person pawn, vitals, A.E.G.I.S. state, camera boom, companion commands (**no input assets — see §3**) |
| Companion + AI | `Companion/` | Bonded EcoKin actor, withdraw-instead-of-death, 5-stance AI (Follow/Guard/Engage/Retreat/Hesitate), trust-based hesitation |
| Targeting + abilities | `Combat/` | Soft targeting (never own partner, ceremony-refused), essence abilities, strain-first damage |
| World regions | `World/` | Region registry, restoration %, flight/ride travel (**weather types only, no sim — see §3**) |
| Championship TV | `Broadcast/` | Exhibition-sport subsystem + in-world TV actor (canon: voluntary exhibition) |
| Tests | `Tests/` (5 files, 68 assertions) | Taxonomy, attributes, broadcast, framework, release/harvest |

**Partially coded (real skeleton, thin depth):** Crafting (`SeedRecipes/AddResources/TryCraft` — no recipe content depth verified), Mission framework (types + accept/progress/complete — **zero seeded missions**), Dialogue (`BeginDialogue/ChooseDialogueOption` — no content), Audio manager (6 functions — no content wired), HUD (layer contracts — no widgets), AntiCheat (types only, server-validated design, no implementation).

---

## 2. Designed but not coded

Each of these is promised by canon or a design doc and has **no implementation**:

| Missing system | Promised by | Notes |
|---|---|---|
| Interactive Binding ceremony | Canon (Binding replaces capture); `EGamePhase::Ceremony` exists but nothing choreographed | The core relationship fantasy — phase-gated, no flow |
| 14-path companion acquisition matrix | Canon lock ("a companion is a relationship, not a container") | Only a mission-type enum entry exists |
| Shimmer Form ascension path | Canon (universal ascension, preserves identity) | Taxonomy enum + Dex validation exist; no way to *attain* it |
| Resonance Strain assignment | Canon (redistributed budgets + mutation nodes) | Trigger kind exists; no spawn/grant system |
| Restoration Farming | Canon (retained system) | Only a greenhouse-dome crafting recipe mentions it |
| Care Consequence | Canon (retained system) | **Zero references in code** |
| D.A.H.L.I.A. as a system | Canon (Sky Archive intelligence, Dex initializer, Forms Registry validator) | Only comments + a bool-setting `ValidateWithDahlia` stub |
| G.L.Y.T.C.H. mission chain | Canon (optional Synth-Origin chain) | Zero references |
| Forecast weather simulation | Weather proposal (CONCEPT, Tay-requested) | `EWeatherState` types only; `WorldSubsystem.cpp` has no weather code |
| Day/night cycle | Implied by night-spawning bosses, Prism Seraph day-weakness | Zero references |
| Tutorial / onboarding | Standard for the genre; Piplin first-Kindling starter ruling exists | Zero references |
| Input mapping assets | Needed to play | `DefaultInput.ini` has **zero** mappings; C++ holds `UInputAction*` pointers to nonexistent assets |
| UI widgets | Needed to play | HUD has 4 functions, no widgets; "assigned in Blueprint" — no Blueprints exist |
| Character/creature meshes & animations | Needed to see the game | `Content/` holds only 4 mp4 files |
| Enemy/wild/boss combat AI | Boss fights designed phase-by-phase | Only the companion AI controller exists; nothing to fight |
| Story/quest content | Mission framework exists | Zero seeded missions; no opening arc |
| Major (story-gated) purification rites | Corruption design (fracture recovery) | Comments only; rite-circle exists as a boss-phase concept |
| Economy / shops / currency | Resident design (Chrono-Merchant trades for Resonance Shards) | No currency, no shop, no transactions; shards are data-only |
| Breeding | Superseded original concept only — **not locked canon** | Zero code; correctly deprioritized |
| PvP / multiplayer | Superseded original concept only — **not locked canon** | Zero code; AntiCheat types anticipate a server model |

---

## 3. Coded but stub / incomplete / broken

| Location | Issue | Severity |
|---|---|---|
| `Private/Corruption/CorruptionSubsystem.cpp:96` | References `ECompanionStance::Aggressive` — **the enum has no such value** (Follow/Guard/Engage/Retreat/Hesitate only) | **Compile error** |
| `Private/Corruption/CorruptionSubsystem.cpp` (`ApplyCorruptionForm`/`RevertCorruptionForm`) | Writes `Companion->Vibrance` etc. — **no such fields**; stats live at `Companion->Attributes.Vibrance` | **Compile error** |
| `Private/Fusion/FusionProgressionSubsystem.cpp:172` | `AllocateFusedDexID` uses a mutable in-memory counter; flagged in comments as belonging in the save record | Data loss on reload |
| `Private/World/WorldSubsystem.cpp:45` | "Journey simulation placeholder: real implementation streams the world" | Travel is a stub |
| `Config/DefaultInput.ini` | Zero action/axis mappings | Character cannot move |
| `Public/World/WorldTypes.h` | Full forecast-weather design in comments; no simulation code | Design-as-comment |
| `Public/AntiCheat/AntiCheatTypes.h` | Server-validated attestation designed; no implementation | Types only |
| `Summoning` ↔ `Corruption` | No integration: a Fractured (Shadow) partner can still be summoned — header comment flags it as future work | Logic gap |
| `Private/Save/` | Fused Dex counter, corruption state, resident state not yet in the save schema | Partial persistence |

---

## 4. Core-loop assessment

Tracing explore → encounter → bind → battle → summon → grow → restore **in code terms**:

| Step | Status | Evidence |
|---|---|---|
| **Explore** | Partial | Tamer pawn + camera exist; regions register; but no input mappings, no traversable content, no wild spawns |
| **Encounter wild EcoKin** | **Missing** | No spawn system, no encounter states in code (Rage/Alpha/Blight/Hollow are canon with no implementation) |
| **Bind** | **Missing** | Ceremony phase exists; no interactive Binding flow — the game's central fantasy has no mechanic |
| **Battle** | Partial | Abilities, targeting, Anima-Link damage all real — but only the companion has AI; there is nothing to fight |
| **Summon** | Implemented | Full subsystem (bonded-only, strain/charge costs, refusals) |
| **Grow (rites)** | Implemented | All four gates enforced; fusion rites staged |
| **Restore world** | Partial | `AddRestoration` + region % exist; no restoration gameplay (farming, purification loops are unwritten) |

**Thinnest step: Encounter.** There is currently no way to meet a wild EcoKin at all — Binding, the game's thesis mechanic, has no on-ramp. Binding itself is the second-thinnest. Everything downstream (battle, summon, grow) is built for creatures the player can never obtain.

---

## 5. Blocked on Tay's decisions

These canon calls gate implementation — building around them risks rework:

- **Approval queue** (`approval-queue.md`, 10 open items): PR #67 merge/placement; 6 `index.html` main-branch commits (revert vs archive); private-repo access grant (blocks Copilot + comparisons); **Keeper reconciliation + Celestine Bang** (terminology the code must use); 5 creature-name picks (batch 100); Dex flags (FLAG-21/22/23/24); Copilot model pin + Oct-22 policy (deadlines Oct 19/22); **weekend build transfer route** (blocks the compile gate); fusion/resident/boss roster veto; Dex 498–511 flags (**Vaeruun vs Vaeluun**, essence mappings).
- **Dex collision queue** (`dex-collision-queue.md`, 5 conflicts, zero rulings): Nature DEX-002, Nova DEX-032, Zebrask variants, Veridan/Verdantis, Shadepaw 132/343. Any code touching these identities (Dex registry content, spawns) waits on rulings.
- **Weekend build transfer** (approval item 8): the 110-file archive is verified, but until Tay picks download-link vs branch-push, the Windows compile — the one honest gate — can't start.

---

## 6. Recommended build order (top 10)

1. **Fix the two Corruption compile errors** (`Aggressive` stance, `Attributes.` indirection) — nothing else matters until the code can compile.
2. **First Windows UE 5.8.3 compile; fix what surfaces** — the honest gate for all 89 files; Tay sends back the error log.
3. **Input mapping assets** (IA_Move/Look/Jump/Interact/Scan/Dodge + mapping context) — the character currently cannot move.
4. **Wild encounter system** (spawn tables per region, encounter states, approach/initiate flow) — the thinnest loop step; unlocks everything downstream.
5. **Interactive Binding ceremony** — the thesis mechanic; phase-gating already exists, choreograph the flow.
6. **Enemy combat AI** (wild, corrupted, boss encounter behavior on the existing AI controller base) — abilities and targeting are waiting for something to fight.
7. **Core UI widgets** (HUD vitals/strain, Dex screen, dialogue box, summon roster) — unplayable and untestable without them.
8. **Seeded story/mission content** (opening arc, Piplin first Kindling, early bosses) — the mission framework is empty.
9. **Greybox meshes + base animations** (tamer, Piplin line, 2–3 early EcoKin) — a game you can't see isn't a game yet.
10. **Shimmer Form ascension + Resonance Strain assignment** — locked canon mechanics with fully-designed rules and zero path to attain them.

*Honorable mentions (next tier):* weather simulation + day/night; Care Consequence; D.A.H.L.I.A. as a real system; 14-path acquisition matrix; restoration farming gameplay; major purification rites; economy/shops; tutorial; audio content; fused-Dex save persistence; Summoning↔Corruption integration.
