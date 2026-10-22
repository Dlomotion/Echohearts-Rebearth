# Rebearth 3D Terrain Blueprint — Triage (2026-10-21)

Status: **CONCEPT — reconciliation evidence, not canon.** Pasted blueprint (ChatGPT-style output) audited against locked canon by Love, 2026-10-21. Nothing here renames or replaces existing regions, systems, or the terrain study path. Tay rules on flagged items.

## What fits and is kept

- **Open vertical world, 360° traversal.** Matches our flight-or-ride traversal and the Sky Isles design. Rebearth was never a side-scroller in canon; this confirms direction, changes nothing.
- **Macro-geometry:** Fractured Crust canyons, Hollow Mountain Mesas (buried skyscrapers/containment facilities under soil and waterfalls), Echo Cavities (vast subterranean pockets with whole sub-ecosystems). Fits the restoration thesis and existing region candidates (Blackfell, Boiling Abyss, the Deep Echo culture). Suspension bridges = physical traversal, allowed.
- **Hybrid asset rule — every asset is tech + nature.** Already our visual identity (restoration theme, Guardians emblem). Kept verbatim as an art-direction rule.
- **Landscape material:** tri-planar, slope-blended (moss → cracked concrete → rusted iron). Sound UE 5.8 technique; goes into the material spec (see Recommendation).
- **Sunken Vaults:** bioluminescent fungal forests, buried geothermal machinery, underground lakes in old reservoirs. Fits the Hollowed / Deep Echo layer of the world.

## Reframed (kept, in our language)

- **"Zone C: Resonance Chasms (Infected Zones)"** → corrupted/fractured ground. The hexagonal geode splitting, pink/crimson crystal veining, pulsing terrain and low rumble read as **corruption geography** — Shadow is a condition, never a category, and "infected" is not our word. These are places where the land itself carries the fracture; purification/restoration should visibly heal them (ties to Restoration Farming and region restoration states already in the terrain study).
- **Zones A–D are biome LAYERS, not tiers or numbered levels.** Canon regions are interconnected ecological regions (13-region map: Sky Haven, Great Plains, Blackfell, Cinderfall, Azure Coastline, Neon Sea, etc.). Surface / highland-megastructure / corrupted / subterranean layers cut *across* named regions; they do not replace the map.

## Flagged — Tay's call

1. **Grappling networks** as traversal tech. Physical traversal, so it does not violate the no-teleportation lock — but it is a NEW traversal system next to flight/ride. Proposal only until Tay approves.
2. **"Echoheart Core structures"** — colossal levitating crystal monoliths *powering* the underground. The Echoheart is the bond that fractures at 100 corruption; a physical Core that powers the world is new lore with big story weight. Levitating crystal fits the resonance-lift precedent (Sky Isles), but the "powering the environment" claim needs Tay's explicit ruling before it enters 02_World.

## Recommendation on the closing question (engine vs. concept first)

**Layout and concept first, material spec written now, engine build at the terrain phase.** Reasons:
- Nothing in UE has compiled yet — the first-compile gate (milestone Phase 1) comes before in-engine landscape work, or the material work risks rework.
- We already have the sequence: terrain study path (Mesh Terrain → PCG → World Partition) against the 13 region vistas. This blueprint slots into that path as sculpting reference.
- The tri-planar material spec can be written today as a ready-to-build document, so the engine step is fast when its phase opens (milestone Phase 4, art/animation/sound).

Routing: 02_World (layers + macro-geometry), 07_Art (hybrid asset kit, foliage kit), 09_Technical (material spec, PCG/World Partition). Nothing to 00_Canon_Lock.
