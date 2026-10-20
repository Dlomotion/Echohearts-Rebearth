# Echohearts: Rebearth — Eco-Kin 3D Intake (proposed integration)

Status: **NOT YET VERIFIED IN UNREAL**. This is a C++ source intake and art pipeline contract, not a packaged game build. No mesh, FBX, GLB, OBJ, rig, texture bake, UHT/UBT, PIE, or platform test is claimed.

## Three production stages
1. **Reference and orthographic sheets:** Use only approved original Eco-Kin designs. Generate clean front/side/back and facial/emote sheets; match silhouettes, scales, element and form IDs. Reference images are not automatically canon. Preserve human NPC identity and Mario's human appearance across quests.
2. **Game-ready mesh and texture:** Retopologize deformation areas; create UV0 and material slots, normal/roughness/base-color/emissive maps, skeleton/skin weights, collision, LODs. Triangle budgets are platform- and screen-size-dependent, not a single universal 'low-poly' limit. Avoid making every creature watertight if articulated openings require otherwise.
3. **UE integration:** Import FBX skeletal mesh and animations into the existing Unreal project; GLB for interchange/web; OBJ for static reference geometry. Create data-driven identity-to-asset mappings, Animation Blueprint, cosmetic material variants, validation and automated asset audits. Do not modify production module files until its actual name, UE version, and module dependencies are confirmed.

## C++ intake
The provided files are intended for an existing Unreal runtime module **only after** adapting their paths to the actual module name. The component class intentionally has no module export macro, so it is not exported to other modules until the project's actual API macro is known. It exposes replicated visual identity and four canonical attributes. Attach to a replicated Eco-Kin Actor and bind BP_OnVisualIdentityChanged to asset resolution via approved Data Assets.

**Security gate:** SetValidatedIdentity checks authority and nonempty IDs, but DOES NOT implement canonical roster lookup, entitlement checks, or anti-spoofing. Only trusted server gameplay code may call it, after those checks. Do not expose a client RPC that forwards arbitrary IDs.

**Identity rule:** PermanentEcoKinID remains stable. FormID and SkinID are distinct. Blessed forms, rare variants and Nature's conditional Mutations must use approved form records, not overwrite a base Eco-Kin.

**Canon rule:** NPCs are human unless an explicitly classified Humanoid-Kin is a separate creature. No player/Eco-Kin fusion, capture devices, or noncanonical element/stat substitution.

## Acceptance gates
- Source files compile under the actual project UE version and UHT/UBT; no assumption that UE5.8 is installed.
- Dedicated server replicates the same identity to two clients; late join receives correct identity; invalid ID and unauthorized caller are rejected.
- Cosmetic switches do not change the canonical attributes or gameplay authority.
- Verify import scale, pivot, orientation, skeleton/retargeting, physics asset, skinning, normals, UVs, material slots, LODs and mobile budgets.
- Verify each character against locked art manifest and the 125-ID production Dex; archive proposed/historical names separately.
- Package and smoke-test Windows, macOS and iOS targets where toolchains exist; Unity/Godot use export bridges, not this Unreal C++ directly.

## Repository integration
This staging folder deliberately avoids guessing the existing module's name or silently changing game source. Merge into the real module only after inspecting its Build.cs, .uproject, existing Eco-Kin actor/data architecture, and active CI matrix.
