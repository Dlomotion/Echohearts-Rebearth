# EcoKin-patch Retry Packet — 2026-10-18

One short action sequence: fix access, verify it, say `retry` in chat. Nothing here pushes anything — the push moves only when you say the word.

## 1. Fix access (the install page)

Open: https://github.com/apps/meta-muse-ai/installations/new

- [ ] Find **Dlomotion/EcoKin-patch** in the repository list and **check it**.
- [ ] Confirm the app has **Contents: Read and write** (not read-only) for the installation.
- [ ] Click **Save** / **Update** — closing the page without saving was the likely cause of the last failure.
- [ ] Wait about a minute for GitHub to propagate the change.

Why this is the fix: both pushes (Oct 17) were refused by GitHub with `403 Resource not accessible by integration` on the write step, while reads work fine. That means the app can see the repo but is not granted write on it.

## 2. Verify before you retry

There is no read-only way to prove write access from here, so verification is two honest steps:

1. Reopen the install page and confirm EcoKin-patch is still checked **after** saving (proves the save took).
2. Say `retry` in chat. The push itself is the write test — it either lands on branch `project/initial-ue5-2026-10-17` or fails fast with the same 403, which means the save did not take and step 1 needs repeating.

## 3. File manifest (rebuilt 2026-10-18, verified)

Verified against live branch `feature/binding-ceremony-2026-10-17` at commit `a511d62` plus working tree. **123 files**, all UTF-8, NUL-delimited manifest rebuilt today (yesterday's temp copy did not survive).

Deliberately excluded: the 4 Content/Movies MP4s (~40 MB), Python cache files, the repo's own `.gitignore`, and its `.github/copilot-instructions.md` (neither remote file will be overwritten).

What could not be verified from here: the GitHub App installation state itself — only you can see that page.

- `.gitattributes`
- `.github/workflows/unreal-foundation.yml`
- `.github/workflows/unreal-linux.yml`
- `BuildScripts/BuildFoundation.ps1`
- `BuildScripts/Linux/build-linux.sh`
- `BuildScripts/Linux/package-linux.sh`
- `Config/DefaultGame.ini`
- `Config/DefaultInput.ini`
- `EchoheartsRebearth.uproject`
- `FOUNDATION_STATUS.md`
- `Launcher/echohearts_launcher.py`
- `README.md`
- `Source/Echohearts/Echohearts.Build.cs`
- `Source/Echohearts/Private/AnimaLink/AnimaLinkCombatSubsystem.cpp`
- `Source/Echohearts/Private/AnimaLink/AnimaLinkComponent.cpp`
- `Source/Echohearts/Private/Audio/EchoheartsAudioManager.cpp`
- `Source/Echohearts/Private/Broadcast/ChampionshipBroadcastSubsystem.cpp`
- `Source/Echohearts/Private/Broadcast/ChampionshipTVActor.cpp`
- `Source/Echohearts/Private/Combat/EssenceAbilitySubsystem.cpp`
- `Source/Echohearts/Private/Combat/TargetingComponent.cpp`
- `Source/Echohearts/Private/Companion/EcoKinAIController.cpp`
- `Source/Echohearts/Private/Companion/EcoKinCompanion.cpp`
- `Source/Echohearts/Private/Corruption/CorruptionSubsystem.cpp`
- `Source/Echohearts/Private/Crafting/CraftingSubsystem.cpp`
- `Source/Echohearts/Private/Dialogue/NPCCharacter.cpp`
- `Source/Echohearts/Private/EchoheartsModule.cpp`
- `Source/Echohearts/Private/EcoKin/EcoKinDexSubsystem.cpp`
- `Source/Echohearts/Private/EcoKin/GrowthRiteSubsystem.cpp`
- `Source/Echohearts/Private/EcoKin/KindlingProgressionSubsystem.cpp`
- `Source/Echohearts/Private/Fusion/FusionProgressionSubsystem.cpp`
- `Source/Echohearts/Private/Game/EchoheartsGameMode.cpp`
- `Source/Echohearts/Private/Mission/MissionSubsystem.cpp`
- `Source/Echohearts/Private/Mutation/MutationDirector.cpp`
- `Source/Echohearts/Private/Progression/BossProgressionSubsystem.cpp`
- `Source/Echohearts/Private/Release/EcoKinReleaseSubsystem.cpp`
- `Source/Echohearts/Private/Resonance/ResonanceShardData.cpp`
- `Source/Echohearts/Private/Sanctuary/SanctuaryResidentSubsystem.cpp`
- `Source/Echohearts/Private/Save/EchoheartsSaveGame.cpp`
- `Source/Echohearts/Private/Save/SaveSubsystem.cpp`
- `Source/Echohearts/Private/Summoning/SummoningSubsystem.cpp`
- `Source/Echohearts/Private/Tamer/FrequencyTamerCharacter.cpp`
- `Source/Echohearts/Private/Tamer/TamerPlayerController.cpp`
- `Source/Echohearts/Private/Tests/ChampionshipBroadcastTests.cpp`
- `Source/Echohearts/Private/Tests/EcoKinCoreAttributesTests.cpp`
- `Source/Echohearts/Private/Tests/EcoKinTaxonomyTests.cpp`
- `Source/Echohearts/Private/Tests/GameFrameworkTests.cpp`
- `Source/Echohearts/Private/Tests/ReleaseHarvestTests.cpp`
- `Source/Echohearts/Private/UI/EchoheartsHUD.cpp`
- `Source/Echohearts/Private/World/WorldSubsystem.cpp`
- `Source/Echohearts/Public/AnimaLink/AnimaLinkCombatSubsystem.h`
- `Source/Echohearts/Public/AnimaLink/AnimaLinkComponent.h`
- `Source/Echohearts/Public/AnimaLink/AnimaLinkTypes.h`
- `Source/Echohearts/Public/AntiCheat/AntiCheatTypes.h`
- `Source/Echohearts/Public/Audio/EchoheartsAudioManager.h`
- `Source/Echohearts/Public/Broadcast/ChampionshipBroadcastSubsystem.h`
- `Source/Echohearts/Public/Broadcast/ChampionshipTVActor.h`
- `Source/Echohearts/Public/Broadcast/ChampionshipTypes.h`
- `Source/Echohearts/Public/Combat/CombatTypes.h`
- `Source/Echohearts/Public/Combat/EssenceAbilitySubsystem.h`
- `Source/Echohearts/Public/Combat/TargetingComponent.h`
- `Source/Echohearts/Public/Companion/EcoKinAIController.h`
- `Source/Echohearts/Public/Companion/EcoKinCompanion.h`
- `Source/Echohearts/Public/Corruption/CorruptionSubsystem.h`
- `Source/Echohearts/Public/Corruption/CorruptionTypes.h`
- `Source/Echohearts/Public/Crafting/CraftingSubsystem.h`
- `Source/Echohearts/Public/Crafting/CraftingTypes.h`
- `Source/Echohearts/Public/Dialogue/DialogueTypes.h`
- `Source/Echohearts/Public/Dialogue/NPCCharacter.h`
- `Source/Echohearts/Public/Echohearts.h`
- `Source/Echohearts/Public/EcoKin/EcoKinCoreAttributes.h`
- `Source/Echohearts/Public/EcoKin/EcoKinDexSubsystem.h`
- `Source/Echohearts/Public/EcoKin/EcoKinKindling.h`
- `Source/Echohearts/Public/EcoKin/EcoKinTaxonomy.h`
- `Source/Echohearts/Public/EcoKin/GrowthRiteSubsystem.h`
- `Source/Echohearts/Public/EcoKin/KindlingProgressionSubsystem.h`
- `Source/Echohearts/Public/Fusion/FusionProgressionSubsystem.h`
- `Source/Echohearts/Public/Fusion/FusionTypes.h`
- `Source/Echohearts/Public/Game/EchoheartsGameMode.h`
- `Source/Echohearts/Public/Mission/MissionSubsystem.h`
- `Source/Echohearts/Public/Mission/MissionTypes.h`
- `Source/Echohearts/Public/Mutation/MutationDirector.h`
- `Source/Echohearts/Public/Mutation/MutationTypes.h`
- `Source/Echohearts/Public/Progression/BossProgressionSubsystem.h`
- `Source/Echohearts/Public/Progression/BossProgressionTypes.h`
- `Source/Echohearts/Public/Release/EcoKinReleaseSubsystem.h`
- `Source/Echohearts/Public/Release/ReleaseHarvestTypes.h`
- `Source/Echohearts/Public/Resonance/ResonanceShardData.h`
- `Source/Echohearts/Public/Sanctuary/SanctuaryResidentSubsystem.h`
- `Source/Echohearts/Public/Sanctuary/SanctuaryResidentTypes.h`
- `Source/Echohearts/Public/Save/EchoheartsSaveGame.h`
- `Source/Echohearts/Public/Save/SaveSubsystem.h`
- `Source/Echohearts/Public/Summoning/SummoningSubsystem.h`
- `Source/Echohearts/Public/Summoning/SummoningTypes.h`
- `Source/Echohearts/Public/Tamer/FrequencyTamerCharacter.h`
- `Source/Echohearts/Public/Tamer/TamerPlayerController.h`
- `Source/Echohearts/Public/Tamer/TamerTypes.h`
- `Source/Echohearts/Public/UI/EchoheartsHUD.h`
- `Source/Echohearts/Public/World/WorldSubsystem.h`
- `Source/Echohearts/Public/World/WorldTypes.h`
- `Source/EchoheartsRebearth.Target.cs`
- `Source/EchoheartsRebearthEditor.Target.cs`
- `docs/ANTI_CHEAT_LINUX_PLAN.md`
- `docs/LINUX_PLATFORM_GROUNDWORK.md`
- `docs/REPO_ECOSYSTEM.md`
- `docs/UE58_BUILD_TARGET_DECISION_2026-10-15.md`
- `Source/Echohearts/Private/Battle/BattleSubsystem.cpp`
- `Source/Echohearts/Private/Binding/BindingCeremonySubsystem.cpp`
- `Source/Echohearts/Private/Encounter/EncounterSubsystem.cpp`
- `Source/Echohearts/Private/Encounter/WildBehaviorComponent.cpp`
- `Source/Echohearts/Private/Encounter/WildEcoKinSpawner.cpp`
- `Source/Echohearts/Private/Server/SessionSubsystem.cpp`
- `Source/Echohearts/Public/Battle/BattleSubsystem.h`
- `Source/Echohearts/Public/Battle/BattleTypes.h`
- `Source/Echohearts/Public/Binding/BindingCeremonySubsystem.h`
- `Source/Echohearts/Public/Binding/BindingTypes.h`
- `Source/Echohearts/Public/Encounter/EncounterSubsystem.h`
- `Source/Echohearts/Public/Encounter/EncounterTypes.h`
- `Source/Echohearts/Public/Encounter/WildBehaviorComponent.h`
- `Source/Echohearts/Public/Encounter/WildEcoKinSpawner.h`
- `Source/Echohearts/Public/Server/SessionSubsystem.h`
- `Source/Echohearts/Public/Server/SessionTypes.h`
- `docs/INPUT_SETUP_CHECKLIST.md`
- `docs/PATCH_NOTES_2026-10-17_BATTLE_MODES.md`
