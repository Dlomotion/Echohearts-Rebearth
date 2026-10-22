# Code Update Diff — Game Framework (2026-10-15)

**Scope:** local-only, `Source/Echohearts/`. Nothing branched, nothing pushed.
**Status:** IMPLEMENTED / NOT COMPILED / NOT TESTED / NOT RUNTIME VERIFIED. Windows UE 5.8.3 build is the gate.

## What was added (33 files)

**Player — Frequency Tamer** (`Tamer/`)
- `TamerTypes.h` — tamer vitals (stamina/health) + A.E.G.I.S. device state
- `FrequencyTamerCharacter` (.h/.cpp) — third-person character, Enhanced Input (move/look/jump/interact/scan/dodge), camera boom, stamina regen, A.E.G.I.S. scan, companion commands
- `TamerPlayerController` (.h/.cpp) — input mapping context, camera focus target

**Game framework** (`Game/`)
- `EchoheartsGameMode` (.h/.cpp) — wires pawn/controller/HUD; explicit game phases (Exploration/Combat/Ceremony/Dialogue/Menu) with broadcast transitions; ceremony locks combat input

**Companion** (`Companion/`)
- `EcoKinCompanion` (.h/.cpp) — bonded Eco-Kin in the world: Dex ID, four attributes, Ecoform, essences, health, withdraw-instead-of-death, damage routed through the Anima-Link combat subsystem
- `EcoKinAIController` (.h/.cpp) — follow/guard/engage/retreat/hesitate; low trust or strained link makes a partner hesitate instead of obeying

**Combat** (`Combat/`)
- `CombatTypes.h` — essence abilities + strike results
- `EssenceAbilitySubsystem` (.h/.cpp) — strain paid first through the link, damage scaled from Vibrance/Density/Harmony/Purity, Harmony precision strikes
- `TargetingComponent` (.h/.cpp) — soft target acquisition; never targets your own partner; refused during ceremonies

**Missions & dialogue** (`Mission/`, `Dialogue/`)
- `MissionTypes.h`, `MissionSubsystem` (.h/.cpp) — Restoration / Companion Acquisition / Story / Challenge missions; completion feeds trust rewards and restoration-deed counts (Growth Rite gates)
- `DialogueTypes.h`, `NPCCharacter` (.h/.cpp) — data-driven NPC conversations; NPCs never fight

**Persistence, audio, world** (`Save/`, `Audio/`, `World/`)
- `EchoheartsSaveGame` (.h/.cpp) — versioned save schema (vitals, companions, kindling, missions, regions)
- `SaveSubsystem` (.h/.cpp) — slots, atomic saves, forward migration, refuses newer-version saves
- `EchoheartsAudioManager` (.h/.cpp) — music moods, essence stingers, Binding chime, Rite chorus
- `WorldTypes.h`, `WorldSubsystem` (.h/.cpp) — regions with restoration %, forecast weather (clear/rain/snow/storm/tornado/hurricane), travel by flight or ride only — never teleportation

**UI** (`UI/`)
- `EchoheartsHUD` (.h/.cpp) — layer system (Main/Dex/MissionLog/Ceremony/Dialogue/Pause/Championship); widget classes assigned in Blueprint

**Build & tests**
- `Echohearts.Build.cs` — added AIModule (companion AI)
- `Tests/GameFrameworkTests.cpp` — vitals clamp/exhaustion, mission objective completion

## Canon guards honored
- Four attributes only, never ATK/HP/SPD/DEF
- Anima-Link bidirectional everywhere: partner pain → tamer stamina; commands cost link strain
- Binding/Resonance Alignment/Release language; no capture language anywhere
- Partners withdraw, never die; no sacrifice path exists in any new file
- Nature conditional-Mutation rule untouched; Echoprint logic untouched
- Travel = flight/ride, never teleportation

## Not yet done (honest)
- Nothing compiled — needs your Windows UE 5.8.3 machine
- No Blueprint widget assets, no input mapping asset, no character meshes — code contracts only
- Enemy AI (wild/Shadow encounters) not yet written — companions and targeting are ready for it
- Ceremony sequences (Binding rite interactive flow) are phase-gated but not choreographed

## Summoning via the Eco-Device (added 2026-10-16)
- `Summoning/SummoningTypes.h` — refusal reasons (always explained), summon results, bonded-partner roster entries
- `Summoning/SummoningSubsystem` (.h/.cpp) — RegisterBond/RemoveBond roster, RequestSummon, RequestReturn
- Rules: only Bound partners can be called (unbonded refused — summoning is not capture); low trust goes unanswered; withdrawn partners can't be called back; Eco-Device charge + Anima-Link strain paid per summon (distance-scaled); strain refusals fail closed; ceremonies never interrupted; one deployed partner at a time; return is free
- Canon note: the Eco-Device is the tamer's physical field instrument — the hardware running the A.E.G.I.S. intelligence (reconciles Tay's original term with locked canon)

## Corruption system (added 2026-10-16)
- `Corruption/CorruptionTypes.h` — ECorruptionSource (blight zones, domination remnants, tampering sites, weapon caches, neglect, forced strain), ECorruptionStage (Clean/Tainted/Corrupted/Severe/Fractured), FCorruptionState, FCorruptionFormDef
- `Corruption/CorruptionSubsystem` (.h/.cpp, tickable world subsystem) — zone exposure tick, AccumulateCorruption, Purify, form apply/revert with exact stat restoration, fracture handling
- Rules: corruption redistributes stats (never inflates); form manifests at 50, falls away below 30; at 100 Echoheart fractures into the Shadow condition (never death, never a new species); purification can't touch Fractured (needs a story-gated major rite)
- Design: `files/04-systems-proposals/corruption-forms-twelve-wounded-2026-10-16.md` — 12 Corruption forms with map territories (Blightstorm, Cinderwraith, Rustmaul, Nulldrift, Eventide, Rotwarden, Reefrevenant, Gloomtrot, Riftmaw, Drownchoir, Ashenmock, Grimcarnival)

## Fusion / Sanctuary / Boss package (added 2026-10-16)
- `Fusion/FusionTypes.h` — EFusionRiteStage (Attunement/Harmonization/SovereignConcord), FFusionResult, FFusionRecord (parents, fused Dex ID, inherited nodes A/B + unique fusion node, inherited essences, DNA stability, D.A.H.L.I.A. validation, dormant-resonance flag, Nature-lineage flag)
- `Fusion/FusionProgressionSubsystem` (.h/.cpp) — RegisterConcordPair (registered pairs only), RequestFusion (both parents mature + Concord Catalyst; fused Dex IDs from 100001), RequestUnfuse (restores parents fully, archives record), RequestFusionRite (trust 40/65/85 + accomplishments 1/3/5 + catalyst + D.A.H.L.I.A. gate below 60 stability), ValidateWithDahlia. HARD RULE: parents enter dormant resonance, never consumed.
- `Sanctuary/SanctuaryResidentTypes.h` — ESanctuaryRole (Mender/Artificer/Chronicler/Bondkeeper/Purifier/Scout), EResidentArrivalKind (6 milestones), FSanctuaryResidentDef/State
- `Sanctuary/SanctuaryResidentSubsystem` (.h/.cpp) — six founding residents with arrival conditions, services, welcome lines; NotifyMilestone moves residents in; RequestService; GetSanctuaryDefense scales with restoration %
- `Progression/BossProgressionTypes.h` — EWorldEra (5 eras), FBossDef (required/optional, order, corrupted Dex ID, world transition)
- `Progression/BossProgressionSubsystem` (.h/.cpp) — 14 canonical bosses in order (4 corrupted alphas, 6 of the Seven Beasts, 2 society champions, Shadow Beast Prime; 4 optional), CanChallenge (required-before gating), MarkBossDefeated (fires transitions once, advances era)
- Design docs: `files/04-systems-proposals/concord-fusion-progression-2026-10-16.md`, `sanctuary-residents-2026-10-16.md`, `boss-progression-2026-10-16.md`

## Residents & Bosses deep dive (added 2026-10-16)
- `Sanctuary/SanctuaryResidentTypes.h` — FResidentAnchorDef (Aura Pylon, role-flavored Tuning Station, Recharging Node, secure energy walls), FResidentServiceTier (progression-gated service expansion), DefenseBehavior; FSanctuaryResidentDef extended with Anchor, ExpansionTiers, DefenseBehavior
- `Progression/BossProgressionTypes.h` — FBossPhaseDef (phase index, health-% threshold, behavior tags, adds, phase rule), FArenaDef (arena mechanics), FBossDef extended with Arena, Phases, DefeatKind ("Subdued"/"DrivenOff"/"Purified" — nothing sentient killed)
- `Progression/BossProgressionSubsystem` (.h/.cpp) — minimal: TryGetBossPhases read path mirroring TryGetBossDef
- Design: `files/04-systems-proposals/guardians-bosses-deep-dive-2026-10-16.md` — full resident functions (anchors, base + expansion services, defense behavior) and all 14 boss fights phase-by-phase with arenas, thresholds, adds, and what makes each distinct; Shadow Beast Prime ends in a purification rite, Society Paragon's partner turns mid-fight
- Roster decision (vetoable): pasted Terraria 1:1 reskin NOT imported (methods-only per IP rule); "Resonance Guardians" not used (collides with Guardians emblem)

## 2026-10-17 — Wild encounter system (branch feature/wild-encounters-2026-10-17, commit 22fdb52)
8 files: Public/Encounter/EncounterTypes.h, WildBehaviorComponent.h, WildEcoKinSpawner.h, EncounterSubsystem.h; Private/Encounter/*.cpp; docs/INPUT_SETUP_CHECKLIST.md. Spawn tables + weighted rolls + state rolls (Calm/Rage/Alpha/Blight/Hollow), wild behavior state machine (wander/notice/curious/charge/warn/flee), encounter subsystem with OnBindingOffered delegate for the future ceremony. Blight spawns seed corruption 55 via Corruption subsystem; NeverAlphaIDs designer data (Nature canonical). Zero forbidden terms; enum refs verified; IMPLEMENTED/NOT COMPILED/NOT TESTED. Design: files/04-systems-proposals/wild-encounters-2026-10-17.md.
