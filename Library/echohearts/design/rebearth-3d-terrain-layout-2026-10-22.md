# Rebearth 3D Terrain Layout — Layers Across the 13 Regions (2026-10-22)

Status: **CONCEPT layout, Tay-approved direction 2026-10-22 ("Do both").** Companion to the terrain blueprint triage (2026-10-21) and the UE5.8 terrain study path (2026-10-15). The 13 named regions stand; the blueprint's four zones are **biome layers** that cut across them. Grappling networks and Echoheart Core monoliths remain **flagged proposals** — this layout does not assume either; where a grapple network would help, the layout marks a bridge/flight route instead.

## The four layers

- **L1 Reborn Overgrowth (surface):** rolling green over brutalist concrete bones; rivers through ancient plazas; canopy light. The default face of a healing Rebearth.
- **L2 Mega-Structure Horizons (highland/ruin):** tiered geometric ruins, sheer composite cliffs, collapsed overpasses as land bridges, dormant security pylons. Extreme verticality.
- **L3 Resonance Chasms (corruption geography):** jagged hexagonal geode splits, pink/crimson crystal veining, pulsing ground, low rumble. This is land carrying the fracture — **purification visibly heals it** toward L1. Never a fixed "zone type"; a region's L3 footprint shrinks as restoration rises.
- **L4 Sunken Vaults (subterranean):** colossal domes, underground lakes in old reservoirs, bioluminescent fungal forests, buried geothermal machinery. Reached through Echo Cavities — open sinkholes, never loading-screen tunnels.

## Layer map per region (from the terrain study path)

| # | Region | Primary layer | Secondary | Layout notes |
|---|---|---|---|---|
| 1 | Moonridge | L1 alpine | L2 outposts | Crystal outcrops on ridgelines; mesa-top ruin pads |
| 2 | Red Canyons | L1 canyon | L3 pockets | Fractured Crust carving; chasm floors carry corruption pockets that heal |
| 3 | Deepwood | L1 forest | L4 mouths | Giant glowing trees; Echo Cavities open under root systems into vault groves |
| 4 | Great Plains | L1 plains | L2 mesas | Hollow Mountain Mesas — the "mesas" are buried structures; enterable |
| 5 | Skycurrents | L2 sky | — | Floating-island construction; waterfalls off island edges; flight-first |
| 6 | Wetland Forge | L2 works | L1 banks | Dam/industrial structures as terrain; river basin sculpt |
| 7 | Moonlit Bayou | L1 swamp | L4 grottos | Water table terrain; glowing water; vault grottos below the bayou |
| 8 | Frostwind Peaks | L1 alpine | L2 ruins | Glacial sculpt; buried facility roofs as plateaus |
| 9 | Volcanic Ridge | L3-leaning | L1 slopes | Obsidian + emissive flows; corruption reads volcanic here — same heal arc |
| 10 | Coralus Depths | L4 grotto | — | The showcase Sunken Vault: light shafts, crystal, underwater fog |
| 11 | Open Range | L1 savanna | L3 seams | Crystal-embedded soil; hexagonal seams mark chasm starts |
| 12 | Prism Cloud Temples | L2 sky | — | Temple platforms among clouds; tiered geometric steps |
| 13 | Rebearth Overview | — | — | Reference only (world-map UI), not playable |

## Vertical transitions (how players move between layers)

- **Surface ↔ highland:** mesa ramps, overpass land bridges, elevator ruins (L2 interiors), flight.
- **Surface → vaults:** Echo Cavities (open sinkholes you descend through in 360°), reservoir shafts at Wetland Forge, root wells in Deepwood.
- **Chasm crossing:** suspension bridges, land bridges, flight/ride. Grapple networks would slot here **only if Tay approves the flagged proposal**.
- **Everywhere:** flight or ride. Never teleportation, never wall-phasing — locked.

## Macro-geometry placement

- **Fractured Crust:** canyon systems anchor Red Canyons and seam the Open Range; ravines break up plains so no region is a flat plane.
- **Hollow Mountain Mesas:** Great Plains mesas + Frostwind/Moonridge plateau roofs — each is a buried structure with an enterable interior (L2 inside L1).
- **Echo Cavities:** at least one major cavity per L4-bearing region (Deepwood, Moonlit Bayou, Coralus Depths), sized for whole sub-ecosystems, lit by glowing formations.

## Build sequence (unchanged from study path)

Mesh Terrain sculpt per region → PCG scatter with per-region rules → World Partition with restoration data layers. One region end-to-end first (recommendation: Deepwood — it exercises L1 + L4 + a cavity descent in a single region), then the rest follow the same path.
