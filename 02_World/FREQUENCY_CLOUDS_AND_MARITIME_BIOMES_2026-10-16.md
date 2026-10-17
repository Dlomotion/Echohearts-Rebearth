# Frequency Clouds & Coastal Depths — Rebearth World Expansion
**Date:** 2026-10-16 · **Status:** APPROVED-PENDING geographic/biome proposals · **UE5.8 proof:** NOT YET VERIFIED

## Placement and world-map authority
This document extends existing **Rebearth / Heartreach Continent** and campaign-connected shoreline travel; it does **not** mint a second planet, parallel continent, locked archipelago, or exact map coordinates. Existing world geography and named locations (including Azuredeep, Sky Haven and Echohearts City where appropriate) take precedence. World-map owner must approve entrance/exits and region bounding boxes before any new landmark is canon. Ocean sites connect to **Sovereign Heartroot / Tree of Life** watersheds and historical Meridian infrastructure. Riftways remain the fast-travel authority.

The following eight proposed coastal and offshore **ecological districts** can span multiple existing regions. Biomes are defined by flora/fauna, pressure, substrate, currents and restoration consequence—not cosmetic palette swaps.

| Candidate district / working name | Ecology, weather and material identity | Play/secret interaction | Persistent restoration delta |
| --- | --- | --- | --- |
| **Mirrorglass Littoral** | terraced silica beach, Torrent/Aura microtidal pools, prismatic shallow sand | find buried tidal gauges when a long-cloud shadow aligns with low tide | sea turtle passages reopen; beachcombing changes from debris to living seed casts |
| **Siltweave Delta** | braided muddy freshwater/saltwater estuary, Flora/Torrent reed stands, monsoon-flood cycles | route a skiff by measuring floodmark rings; discover an archival culvert | clean spawning marsh and settled water quality |
| **Crownkelp Shelf** | towering algae/kelp forests, thermal upwelling, daylight filtered green | dive through oscillating kelp corridors; recover sonar seeds without disturbing nesting | current and nursery stability; sustainable fishing restored |
| **Vellumice Floes** | drifting porous ice shelves, Glaze/Torrent/Aero, brine seep | tune echo buoys across shifting floe passages to reveal a weather station | safe transit corridor while preserving cold ecology |
| **Copperwake Shoals** | mineral-rich shoal reefs, Voltic/Terra storms from exposed relic grounding | restore ground cables to stop shock arcs; salvage nonliving relic fragments | safer currents and protected reef spawning |
| **Veinwater Trench** | dark vertical canyon, Torrent/Shade/bioluminescent ecology, hydrothermal vents | staged decompression chambers and passive acoustic riddles locate an old observation pod | vent waters reoxygenated; Deep Root relays recover |
| **Skydrift Breakwater** | high sea-cliffs, Aero uplift bands, seabird nesting ledges, stratiform cloud inversion | glider/skiff coordination and a wind-direction cipher reveal a lighthouse record | avian migration and signal towers return |
| **Hollowtide Caverns** | flooded Karst chambers, Terra/Torrent, salt-dependent microbes | atmospheric pressure switches expose an otherwise flooded survey maze | cave groundwater drains cleanly; towns regain freshwater |
| **Cinderbrine Mouth** | geothermal black-sand coastline, Pyre/Torrent, cooling mineral fans | remote submersible maps safe passages to an abandoned geothermal exchange | thermal cycles stabilized without extinguishing natural vent life |

**Ecological authenticity:** restorative gameplay may rebuild connections, but never erase native cold, heat, wetland flood or deep-water pressure. Existing approved extreme biome labels remain candidates and cannot be silently superseded.

## Cloud-building manifest
Each weather state has an authored cloud mesh/material template, scientific baseline and a fantasy resonance overlay where story authorizes it.

| Cloud prototype | Engine visual | Weather telegraph | Gameplay state |
| --- | --- | --- | --- |
| `CLD_DRIFT_01` | low cotton-cloud layers with soft shadow masks | rising humidity / calm | daylight grows Living Soil; mild visibility change |
| `CLD_CIRRUS_02` | high wind-sheared ice strands with anisotropic highlights | high-level wind-front movement | hints at offshore travel window |
| `CLD_MARINEFOG_03` | near-ground volumetric sea-mist bank and depth fade | cooling sea-surface inversion | limited navigation; A.E.G.I.S. coastline pings |
| `CLD_THUNDERHEAD_04` | thick anvil-capped vertical storm core, stratified turbulence, rain shafts | clear gust front and lightning preflash | torrential rain, directional wind, shelter recommendation |
| `CLD_BLIGHTFRONT_05` | localized spectral grain/negative halo over ordinary cloud physics | distortion signatures and audible anomaly pulses | temporary pylon interference; restoration encounter |
| `CLD_ICEVEIL_06` | layered supercooled mist and drifting glint particles | rapid temperature and pressure drop | sea-spray ice buildup; thermal countergear |
| `CLD_AURORA_07` | rare weak scattering high-altitude ribbons, independent of cloud water | cold clear upper atmosphere | visual scanning opportunity, optional lore |

### Storm profile contracts
**WEA_COPPER_ANVIL** (Aero/Voltic): wind-shear and lightning strike zones; high salinity changes exposed infrastructure grounding. Lightning targeting is authoritative and must telegraph strike windows and safe grounding.

**WEA_TIDAL_BRINEVEIL** (Torrent/Aero): rolling sea fog and swell; A.E.G.I.S. reveals safe harbor soundings but does not cheat visibility for enemies. Fog density scaled by render quality without changing server-safe-visibility checks.

**WEA_VELLUMICE_SQUALL** (Glaze/Aero): snow drift and spray freezing around exposed ship equipment; require sail trim, insulation and partial shelter.

**WEA_ROOTMIST** (Flora): ordinary eco-transpiration fog after warm nights. Carries ecosystem knowledge and movement cues, not a universal poison.

**WEA_BLIGHT_PRESSURE** (existing Blight with optional Gloom source): distorted weather-local scan signatures and localized equipment failures; hazards resolve through world repair or retreat, not a permanent "Discordant" species spawn table.

**WEA_CHRONO_SURGE** (story-gated Chrono-Rift scar): short duration interference with timed actuators at an authored site; does not globally change clock truth, growth rate, inventory spoilage or client simulation speed.

### Engineering / world-partition acceptance
- Region volumes contain `BiomeID`, `WeatherProfileID`, `ClimateSeed`, `WorldStateVersion`, parent Heartroot watershed link, unload/reload policy and authoring owner.
- Local weather forecast uses **authoritative** time, world state, bounded climate transitions; client materials/particles are cosmetic.
- On a storm threshold, populate ocean swells, soundscape, NPC shelter schedules and local ship hazard surfaces. Save only coarse progression and significant deltas, not particle particles or visual sprites.
- Sun exposure, brightness, lightning, motion effects and distortion accessibility options are first-class.
- Area names, native Eco-Kin membership, exact positions, species art, fauna counts and spawn tables need approval against Permanent Dex records first.

## Secrets and exploration puzzles (working catalog)
1. **The Zero-Wake Chart:** survey coastal current direction at three tide stages to reveal a historically misfiled Meridian shipping route. Not a random drop: solve by recorded measurements.
2. **The Quiet Bell:** an abandoned warning buoy emits a missing beat; players reconstruct a station's frequency-correction timeline using scanner evidence; opens a safe harbor.
3. **Root Inversion Garden:** below kelp canopy, inverted root growth signals a leaking Heartroot conduit. Restore the conduit before collecting seeds; restored reef animates visibly.
4. **The Glass Interval:** natural sunlight crossing a cliff crack aligns once per weather cycle; optical puzzle can be solved using repeatable observation logs, with non-time-gated accessibility alternate.
5. **Twelve Broken Bearings:** navigate an old gauge array by calibrated distance and ocean-current sound, then recover an authenticated archive log (not a new Essence).
6. **The Floodmark Witness:** reconstruct last safe flood line in the city and river outflow using debris chronology, addressing displacement/settlement restoration.
7. **The Living Buoy:** an existing, Dex-approved Eco-Kin may voluntarily assist with route signaling after trust development; no mandatory species ownership gate.
8. **Blue Lantern Run:** emergency response across three offshore shelters during a forecasted storm; co-op assistance allowed, solo equivalent required.

## Named landmarks pending cartography
- Echohearts City social district: proposed **community bowling hall** with six playable lanes, optional 13:30 in-world league check-in; placement and city zoning require map approval.
- **Tideglass Beacon:** coastal navigation tower and archival signal hub.
- **Kelp Chamber:** pressure-gradient research/outpost access node.
- **Rootfall Vent:** a seafloor hydrothermal site with persistent restoration effects.
- **West Sill Drydock:** modular ship assembly, repair and sanitary salvage inspection.
- **Harbor Listening Steps:** community dock where weather observations and local quests are exchanged.
All names above are **working names**; do not stamp final coordinates or map-pin authority until reviewed.

## Originality and progress gating
The submitted third-party-like ocean-release story, 21-day mandatory online campaign, capture-and-breed aquatic predators, borrowed archetype personalities and unrestricted PvPvE warzone remain **REFERENCE-ONLY**. This expansion's differentiator is **visible watershed recovery, ethical partner ecology, forecast-driven sailing and authenticated historical evidence**, not reproducing any third-party patch.

**Implementation state:** design written, not asset-built, not UE weather-compiled, not packaged, not simulated under multiplayer or performance tests.
