# Echohearts UE 5.8 Architecture Framework — Sandbox Survival & Monster-Taming RPG

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

Status: DESIGN SPEC (supplied 2026-11-09). Implementation status is tracked per system below; per project rules, nothing here is VERIFIED without direct build/runtime evidence. The first implemented slice is noted at the end.

## Vision
A massive 3D sandbox survival + monster-taming RPG blending real-time action combat, deep crafting, and an extensive creature eco-system on a modular C++ framework in Unreal Engine 5.8 — sandbox building loops, tactical open-world hunting, and an original resonance-based companion system, without derivative templates.

## Step 1 — Architectural foundation (data & project management)
Data decoupled from scene actors, so hundreds of species, elemental matrices, and modular base layouts stay trackable.
- **Unified Blueprint/C++ Data Asset framework:** no raw hardcoded arrays. `UEchoDexDataAsset : UPrimaryDataAsset` registers creature records natively. Explicit `FGameplayTag` system enforces element classification, status alignment, and strict terminology, independent of hardcoded strings.
- **Component-driven player state:**
  - `UResonanceCompanionComponent` — team slots: 8 carried tracking slots, strict 3 active real-time combat companions.
  - `UChronicleQuestComponent` — chains of dynamic side quests and base progression tasks.

## Step 2 — Core systems integration
1. **Real-time monster-taming pipeline (purification, not capture-by-damage):** multi-stage target tracking; the player deploys spatial physical anchors via an interactive projectile line system. At critical thresholds a localized containment check runs a cleansing function converting chaotic alignment to pure resonance. **Custom evolution:** non-linear, state-driven form shifts from base interactions, alignment configuration, and tracking metrics — not level milestones.
2. **Open-world tactical hunting & action combat:** responsive melee + elemental projectiles, dodge-frames; **weakpoint mapping** with skeletal bone-break logic on large monster classes (target parts to down threats or farm elite crafting components); Behavior Trees for aggro/threat priority, long-range positioning, and boss arena phases.
3. **Modular 3D voxel sandbox & construction:** instanced static meshes + grid placement; `ASandboxGridManager` tracks layout coordinates with spatial hashing. **Automated base labor:** a base registration interface lets utility NPCs / purified base entities in Homeland/Skyisland quarters scan for workstations, harvest nodes, and storage chests and queue automation without blocking the main thread. **Crafting:** multi-tier tech-table progression (tools, environmental equipment, cosmetic banners, defensive fortifications).
4. **Economy & progression:** `UTradingTransactionComponent` validates exchanges — legendary classifications and seasonal elements are non-transferable; common cosmetics, materials, and custom trophies trade freely. **Specialist vendor engine:** a weekend vendor class + base warden loop pulling catalogs from an external localized server-time matrix.

## Step 3 — Production C++ (first slice)
The companion manager orchestrates team-slot boundaries and active deployment. As implemented (BUILD repo, `Source/Echohearts/Public/Companions/EchoCompanionManagerComponent.h` + Private .cpp):
- Carried/active contract enforced: 8 carried, 3 active, **no duplicate Dex IDs** (party contract from the canon README).
- Deploy is server-authoritative in networked modes.
- Resonance alignment = mean purity of active slots.
- Fixes vs. the draft supplied in chat: the invalid `#include "CoreMinimal.Widget.h"` (must be `CoreMinimal.h`), class renamed with the module's `Echo` prefix convention (`UEchoCompanionManagerComponent`), unused `Kismet/GameplayStatics.h` include removed, and the empty alignment function implemented.

Also implemented: `UEchoDexDataAsset` (`Source/Echohearts/Public/Data/`) with DexID tag, element tag container, and the canonical Vibrance/Density/Harmony/Purity attributes; PrimaryAsset type `EchoDex`.

## Open build order (owner's choice)
A. Spatial grid management (`ASandboxGridManager`, instancing, spatial hashing) for building mechanics.
B. Containment line + purification calculation loops for the trapping system.

## Verification boundary
Filed and statically reviewed only. UE 5.8 UHT/compile/Editor/PIE: NOT YET VERIFIED (no complete UE 5.8 Win64 install in the connected workspace).
