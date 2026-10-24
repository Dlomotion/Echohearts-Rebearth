# Unreal Engine 5.8 Rendering Integration Plan

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

Status: ARCHITECTURE PLAN, NOT YET VERIFIED.

## Purpose
Define how Echohearts visual systems should enter the real Unreal project without inventing a second rendering stack or adding unneeded custom rendering code before the actual project tree is available.

## Production Principles
- Use Unreal Engine 5.8 rendering systems first.
- Prefer authored materials, Niagara, lighting, post-process, animation, World Partition/Data Layers and scalable quality settings before custom render code.
- Keep STARZ* as an Echohearts visual language, not a separate gameplay element.
- Do not advertise visual/network features as implemented until evidence exists.

## Visual Pillars
1. **Living Planet Response**: restoration visibly changes terrain, vegetation, water, weather, particles, ambience and creature behavior.
2. **Eco-Kin Readability**: silhouette, material language, elemental effects and emotional state must remain readable during gameplay.
3. **Cozy-Crazy Contrast**: Sanctuary/home spaces are warm, legible and restful; wild hazard states are dramatic without destroying navigational clarity.
4. **Blight vs Recovery**: Blight visual language must be distinct from healthy Rebearth and from ordinary night/weather effects.

## Unreal-Native System Mapping

### Materials / Shaders
Use Material Instances and parameter collections for:
- regional Purity/Blight blending,
- wetness/snow/heat response,
- restoration state transitions,
- Eco-Kin elemental accents,
- STARZ* particles/emissive accents,
- Sanctuary comfort states.

### Niagara
Use Niagara for:
- Blight motes,
- Purity cleansing flow,
- Echo-Dew,
- storm sparks,
- root-growth accents,
- Eco-Kin ability telegraphs,
- Kindling/Command Sync feedback,
- STARZ* presentation effects.

### Lighting
Use Lumen/standard Unreal lighting pipeline where appropriate for target hardware. Define separate authored looks for:
- Sanctuary warm-state,
- normal wild exploration,
- storm/hazard state,
- Zero-Veil/Blightfront state,
- recovery aftermath.

### World State Visual Changes
Persistent mission/world flags should drive Data Layers or authored state swaps for major before/after changes. Avoid expensive fully procedural rebuilding when authored transformations give better control and performance.

### UI Rendering
Gameplay UI stays in UMG/CommonUI. No OpenGL-specific custom UI layer is part of the current production direction.

### Performance
Each visual feature requires scalability tiers and profiling evidence. Track:
- GPU time,
- overdraw,
- Niagara particle cost,
- material instruction complexity,
- shadow cost,
- streaming behavior,
- memory footprint,
- split-screen/multiplayer impact when applicable.

## First Visual Slice
The first verified rendering slice should prove one region state change:
1. damaged Whispering Glade/Vespera location,
2. visible Blight pressure,
3. player completes a restoration objective,
4. Data Layer/material/Niagara/audio state transitions,
5. Eco-Kin/NPC behavior changes,
6. state persists after save/reload.

## Eco-Kin Presentation Minimum
Each production Eco-Kin needs:
- calm state,
- fear/stress state,
- defensive state,
- locomotion set,
- idle behaviors,
- hit/recovery feedback where relevant,
- element VFX budget,
- readable distance silhouette,
- accessibility-safe telegraphs.

## C++ Boundary
Do not build a custom renderer. C++ is justified only for runtime systems that need authoritative/shared state or high-performance coordination, such as exposing world restoration state to presentation systems. Visual authoring remains primarily materials, Niagara, animation, Blueprint and data-driven configuration.

## Verification Requirements
- actual UE 5.8 project build,
- representative gameplay capture,
- Unreal Insights/GPU profiling evidence,
- scalability test,
- save/reload state persistence,
- no misleading VERIFIED label before those tests pass.
