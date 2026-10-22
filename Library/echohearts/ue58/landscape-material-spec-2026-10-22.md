# UE 5.8 Landscape Material Spec — Rebearth Tri-Planar Slope Blend (2026-10-22)

Status: **SPEC — ready to build in-engine when the terrain phase opens. Nothing here is compiled or runtime-verified.** Tay approved 2026-10-22 ("Do both"). Written against UE 5.8.3, our locked target. Pairs with the terrain layout doc (`files/design/rebearth-3d-terrain-layout-2026-10-22.md`) and the terrain study path.

## Goal

One master landscape material for all 13 regions: technology-and-nature in a single blend, driven by slope, height, and a per-cell **restoration value** — so the same terrain reads blighted, recovering, or restored without ever being rebuilt.

## Material layers (paint + auto-blend)

| Layer | Look | Driver |
|---|---|---|
| **Moss/Soil** | Lush green moss over dark soil | Default on gentle slopes; density scales with restoration |
| **Structural Concrete** | Cracked brutalist concrete, panel seams | Mid slopes + painted ruin pads (mesa tops, plazas, L2 structures) |
| **Rusted Iron** | Rusted metal tiling, exposed-panel edges | Steep slopes and painted structure faces; tri-planar projected (see below) |
| **Rock/Strata** | Natural stone, canyon strata bands | Steepest slopes; strata banding by world height |
| **Crystal Vein (corruption)** | Dark metallic stone, emissive pink/crimson crystal | Painted L3 chasm areas only; emissive intensity + pulse driven by corruption value (inverse of restoration) |
| **Snow/Ice** | Snow with rock break-through | Height + slope cap for Moonridge/Frostwind |

## Blending rules

- **Tri-planar projection** on Rock, Rusted Iron, and Crystal Vein — no stretching on sheer L2 cliffs or chasm walls.
- **Slope thresholds (starting values, tune in-editor):** Moss/Soil < 35°; Concrete 30–50° where painted; Rock > 55°; Iron takes painted faces at any angle; Snow > 2,200 m world height and < 40°.
- **Height blending** with soft falloff between every pair — no hard lines; macro variation noise breaks up tiling at distance; detail normal fades in near camera.
- **Restoration parameter (0–1 per World Partition data layer cell):** drives moss density/tint, crystal emissive (1 → 0 as restoration rises), and a subtle saturation lift. This is the "world visibly heals" hook — materials change, geometry doesn't.
- **Weather hooks:** wetness darkening + roughness drop on rain state; snow accumulation raises the snow line; both are scalar parameters on the master material, set per region from the forecast system (concept — weather canon direction still Tay's call).

## PCG scatter rules (per layer)

- **L1:** terrestrial trees + bioluminescent flora mixed; glowing vines on structure faces; shelf fungi on metal.
- **L2:** rebar meshes, broken slabs, panel debris clustered near painted structure faces; dormant pylons as hero props (separate meshes, not scatter).
- **L3:** crystal growths clustered on the Crystal Vein layer, density ∝ corruption; hexagonal rock shards.
- **L4:** fungal forest set, glow flora; light-shaft volumes placed by hand per vault.

## Performance guardrails

- One master material + instances per region (parameter overrides only: tint, snow line, strata colors).
- Max 6 blended layers per Landscape component; virtual textures (RVT) for the landscape so slope/height blends stay cheap.
- Nanite for structure meshes only — **not** for skinned meshes (project avoid list). Landscape itself stays standard UE Landscape/Mesh Terrain per the study path.

## Build order in-engine (terrain phase)

1. Master material with Moss/Soil, Concrete, Rock tri-planar — walk test on one sculpt.
2. Add Iron + Snow, tune thresholds.
3. Add Crystal Vein + restoration parameter; test heal transition on a painted chasm patch.
4. RVT pass + per-region instances.
5. PCG rule sets per layer.

Acceptance: Deepwood sculpt (layout doc's recommended first region) reads L1 at the surface, descends through an Echo Cavity, and its chasm patch visibly heals when the restoration parameter is raised — in-editor, on Tay's machine.
