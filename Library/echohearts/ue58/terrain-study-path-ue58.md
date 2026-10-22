# UE5.8 Terrain Study Path — 13 Rebearth Regions
**Study only, 2026-10-15.** No terrain built, nothing compiled, no runtime claims. This is the learning sequence for turning the 13 CONCEPT region vistas (`maps/` on PR #67's branch, catalogued in `MAP_THUMBNAIL_MANIFEST.csv`) into real UE5.8 landscapes later.

## Study order
1. **Mesh Terrain first** — sculpt one Landscape per region from its vista; paint material layers (rock, soil, snow, crystal, lava) to match.
2. **PCG second** — scatter biome dressing procedurally (vegetation, rocks, crystals, ruins) with per-region rules; hook density to weather.
3. **World Partition third** — only after a region reads well standalone: streaming cells, per-region data layers (notably restoration states — healed vs blighted looks).

**MetaHuman:** pointers only, and only where crowd needs justify them (settlement hubs). No MetaHuman work is part of terrain study.

## Per-region study notes

| # | Region | Vista | Terrain focus | PCG scattering focus |
|---|---|---|---|---|
| 1 | Moonridge | Snowy ridge, aurora, crystal outcrops | Alpine ridgeline sculpt; snow/rock/crystal layers | Crystal clusters, pine variants, snowfall-driven density |
| 2 | Red Canyons | Red rock canyon, sunset, river | Canyon carving; strata rock layers; riverbed | Desert scrub, river rocks, heat shimmer dressing |
| 3 | Deepwood | Misty ancient forest, giant glowing trees | Rolling forest floor; mist volume placement | Giant glowing trees (hero), undergrowth, fireflies |
| 4 | Great Plains | Golden grassland, mesas, storm clouds | Flat-to-mesa heightmap; grass layer | Grass swaths (wind), mesa rock, storm-debris |
| 5 | Skycurrents | Floating islands, waterfalls, above clouds | Island meshes (not standard Landscape — study floating-island construction) | Cloud flora, waterfall ribbons, sky fauna perches |
| 6 | Wetland Forge | River dam works, ancient-tech structures, dusk | River + dam basin sculpt; tech-structure pads | Reeds, dam machinery dressing, dusk lighting refs |
| 7 | Moonlit Bayou | Moonlit swamp, hanging moss, glowing water | Swamp water table; mud layers | Cypress/moss, glowing water plants, mist |
| 8 | Frostwind Peaks | Icy peaks, blizzard, aurora | Glacial sculpt; ice/snow layers | Ice shards, blizzard particles, aurora sky |
| 9 | Volcanic Ridge | Lava flows, obsidian cliffs | Volcanic cones; lava emissive layers | Obsidian shards, ember particles, cooled-rock variants |
| 10 | Coralus Depths | Underwater crystal grotto, light shafts | Cavern/grotto sculpt; underwater fog | Crystals, light-shaft volumes, aquatic flora |
| 11 | Open Range | Open savanna, crystal formations | Savanna plain; crystal-embedded soil | Savanna grass, crystal formations, herd-grazing clearings |
| 12 | Prism Cloud Temples | Sky temples, prismatic clouds | Temple platforms among clouds (floating construction, like Skycurrents) | Prismatic cloud volumes, temple dressing |
| 13 | Rebearth Overview | Planet map, glowing zones | **Reference only** — not a playable region; use for world-map UI | n/a |

## Cross-region study threads
- **Weather hooks:** Tay wants snow, rain, tornadoes, hurricanes with forecasts. Study how PCG density + material parameters respond to a weather state per region (e.g., blizzard density in Frostwind Peaks, storm debris in Great Plains).
- **Restoration states:** the world visibly heals. Study data layers carrying a per-cell "restoration" value that shifts materials (blighted → recovering → restored) without rebuilding terrain.
- **Flight:** travel is flight/ride, never teleportation — study terrain LOD and streaming with fast aerial traversal in mind from the start.

## What "done" looks like (later, on the UE machine)
One region taken through all three phases and walked/flown in-editor. The other twelve follow the same path. Until then, this document is the map, not the territory.
