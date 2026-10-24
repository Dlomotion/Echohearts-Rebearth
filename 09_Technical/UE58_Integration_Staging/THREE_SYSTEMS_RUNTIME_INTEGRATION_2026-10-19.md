# Echohearts: Rebearth — Three-System UE5.8 Runtime Integration

**Date:** 2026-10-19  
**Status:** IMPLEMENTATION STAGED / UE5.8 COMPILE + RUNTIME VERIFICATION REQUIRED  
**Canon authority:** `Dlomotion/Echohearts-Rebearth`  
**Executable runtime authority:** `Dlomotion/ECHOHEARTS-REBEARTH-BUILD-`  
**Target runtime module:** `Echohearts` / `ECHOHEARTS_API`

## Scope delivered

This integration implements the three previously requested systems without creating a parallel canon, second Dex, or replacement runtime architecture.

### 1. A.E.G.I.S. Binding / Eco-Kin Extraction

Files:
- `Source/Echohearts/Public/EHRGameplayTypes.h`
- `Source/Echohearts/Public/EHRSanctuaryPolicyLibrary.h`
- `Source/Echohearts/Private/EHRSanctuaryPolicyLibrary.cpp`
- `Source/Echohearts/Public/EHRFrequencyTamerLinkComponent.h`
- `Source/Echohearts/Private/EHRFrequencyTamerLinkComponent.cpp`

Rules:
- only approved Permanent Dex IDs are eligible;
- Kindling must be complete;
- consent must be server-confirmed;
- Purity gate is explicit;
- Harmony is the binding resource cost;
- extraction requires an existing link, completed Kindling, consent, sufficient Harmony, and Sanctuary capacity;
- no client RPC is provided by this component. Server gameplay code must derive consent, Kindling, Dex eligibility and Sanctuary capacity from authoritative state.

## 2. NPC Sanctuary Housing / Quest Automation

Files:
- `Source/Echohearts/Public/EHRSanctuaryWorldSubsystem.h`
- `Source/Echohearts/Private/EHRSanctuaryWorldSubsystem.cpp`

Rules:
- the world subsystem rejects client-side mutation;
- housing checks resident identity, assignment state, capacity, restoration and the four-attribute Sanctuary matrix;
- quest automation starts only authored auto-start quests whose restoration, resident, attribute and prerequisite-quest gates are satisfied;
- quest completion is tracked by stable `FName` IDs.

## 3. Skyisland Crafting Tiers

Files:
- `Source/Echohearts/Public/EHRGameplayTypes.h`
- `Source/Echohearts/Public/EHRSanctuaryPolicyLibrary.h`
- `Source/Echohearts/Private/EHRSanctuaryPolicyLibrary.cpp`
- `Source/Echohearts/Public/EHRSanctuaryWorldSubsystem.h`
- `Source/Echohearts/Private/EHRSanctuaryWorldSubsystem.cpp`

Rules:
- recipes have explicit authored tier, restoration and Vibrance/Density/Harmony/Purity gates;
- material and output IDs must be valid;
- quantities must be positive;
- crafting is rejected on clients;
- inputs are debited only after full eligibility validation;
- output quantity addition is integer-overflow bounded.

## Anima-Link loop

`FEHRAnimaLinkPulse` models the required bidirectional strain loop:
- direct Eco-Kin Vibrance/Density strain transfers a configured share to the Frequency Tamer;
- direct Frequency Tamer Vibrance/Density strain transfers a configured share to the linked Eco-Kin;
- Harmony and Purity remain authored relationship/ecology gates rather than generic mana/magic substitutions;
- transferred strain is expressed only through the project attribute matrix.

## Verification coverage

`Source/Echohearts/Private/Tests/EHRSanctuaryPolicyTests.cpp` adds automation coverage for:
1. Kindling + consent + Purity binding eligibility;
2. bidirectional Anima-Link pulse transfer;
3. housing and quest eligibility;
4. tiered Skyisland crafting eligibility.

## BUILD-repository migration

When access to `Dlomotion/ECHOHEARTS-REBEARTH-BUILD-` is available:

1. copy the staged `Public/` and `Private/` files into the existing `Source/Echohearts/` module;
2. keep module name `Echohearts` and API macro `ECHOHEARTS_API`;
3. do not port the legacy `EchoheartsRebearth` module name or `ECHOHEARTSREBEARTH_API`;
4. verify the existing `Echohearts.Build.cs` already includes `Core`, `CoreUObject`, `Engine`, and `NetCore`. No additional module dependency is required by this staged code;
5. run UHT/UBT through the supported UE5.8 toolchain;
6. run the `Echohearts.Sanctuary.*`, `Echohearts.AnimaLink.*`, and `Echohearts.Skyisland.*` automation tests;
7. attach compile, test and runtime evidence before changing verification status.

## Current blocker

The connected GitHub integration can read the accessible prototype project, but organization writes to `IN2Deep-Studios/ECO-KIN-Game` are blocked with `403 Resource not accessible by integration`, and the authoritative BUILD repository is not accessible through the current installation. Therefore this change is staged in the canonical repository and must not be described as UE5.8 compiled, packaged, or runtime-verified yet.
