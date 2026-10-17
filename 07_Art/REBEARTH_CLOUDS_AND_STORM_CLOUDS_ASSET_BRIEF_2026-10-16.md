# Rebearth Skybox, Volumetric Clouds & Storm Clouds — Asset Production Brief
**Date:** 2026-10-16 · **Status:** ART DIRECTION / PENDING ORIGINAL ASSETS AND UE5.8 TESTS

## Art goal
Build visually distinctive, physically grounded **cloud systems** for Rebearth. A cloud is not a generic static sky sphere: density, vertical structure, shadows and water load should communicate actual gameplay wind, safety and region state. Fantasy glow is layered sparingly over a recognizable meteorological structure and only when triggered by appropriate regional Essence/Blight story context.

These are **instructions to create original assets**, not a claim that texture maps, Niagaras, 3D models, cloud materials or rendered concept images have already been produced. Existing `07_Art` identity/asset provenance rules apply.

## Seven authored cloud families
| Asset key | Silhouette / layer design | Tonal direction | In-motion cues |
|---|---|---|---|
| `CLD_DRIFT_01` | staggered shallow cumulus arcs, frayed rim wisps | warm ivory and cool slate underside | rolling convection and soft penumbra shadows |
| `CLD_CIRRUS_02` | very thin shear-stretched fibrous upper bands | blue-white with pale silver | high-level crosswind drag |
| `CLD_MARINEFOG_03` | broken horizontal fog banks at sea level, gaps near heated rock | desaturated blue-gray with warm scatter | low-speed advection, boat wake breakup |
| `CLD_THUNDERHEAD_04` | towering convective column, asymmetrical multi-level anvil, rain foot | storm indigo / charcoal underlit with restrained bronze reflection | twisting updraft, gust front, intermittent internal discharge |
| `CLD_BLIGHTFRONT_05` | asymmetrical weather cell with local material interference and torn edge; **natural physics still readable** | murky shadow tones with localized frequency shimmer; not a universal purple corruption filter | brief scan flickers, displacement near node edges |
| `CLD_ICEVEIL_06` | suspended crystals, large smooth glacial shelf cloud and spray haze | pale gray, lavender-blue natural ambient bounce | horizontal blowing snow, salt spray crystallization |
| `CLD_AURORA_07` | loose high-altitude translucent field, not a persistent star-portal | cool mint and faded violet, low luminance | slowly changing curtain topology |

### Storm-specific visual sequence: `CLD_THUNDERHEAD_04`
**0. Seed:** a small fair-weather vertical build, normal exposure.  
**1. Formation:** dark cloud-bottom gradient spreads over local horizon. Rain shafts remain distant; gust-line particles appear in vegetation/sea spray.  
**2. Warning:** physical anvil cap and funnel *morphology* (not constant tornado) grow; subtle internal lightning reflection; A.E.G.I.S. storm band with text/icon warning.  
**3. Active:** layered billowing volume, directional precipitation curtains, far/mid/near cloud channels, pooled lightning emitters, wind-reactive sail rig and exposed structures. Lightning hazards telegraph independently from purely decorative flashes.  
**4. Exit:** rain line passes, layered cloud shelf softens, shafts retreat, sun shafts and wet surface response recover. Player recognizes where the storm moved by terrain saturation.

**Do not** use unreadable full-screen strobing, aggressive camera shaking, unbounded particle density or 2D billboards at obvious cloud intersection. Respect photosensitivity, motion reduction, brightness controls and performance scalability.

## UE5.8 implementation handoff (BUILD only)
- Sky Atmosphere for solar transmission/airlight, Volumetric Cloud for main weather cells, Exponential Height Fog for lower coastal visibility, directional lights/cloud shadow projection for grounded cues, Niagara for local rain/spray/lightning and audio integration through existing audio layer.
- **Material function candidates:** `MF_CloudBaseNoise`, `MF_CloudDetailErosion`, `MF_CloudHeightFalloff`, `MF_CloudWindAdvection`, `MF_BlightriftEdgeOverlay`. Avoid magic "full ray marching everywhere" quality assumptions.
- **Variant data fields:** `CloudTypeID`, `BaseAltitudeM`, `CloudThicknessM`, `Coverage01`, `Humidity01`, `ErosionScale`, `FlowVelocity`, `ShadowIntensity`, `LodBudget`, `BiomeTag`, `HazardProfileID`.
- Author cloud material behavior once and instance variations per biome/weather. Pair with existing 60 FPS target under representative platform budgets; do not claim target achieved before profiling.
- Atmosphere server profile controls wind and damage; GPU visuals are cosmetic and allowed to differ in resolution. Never use local cloud particle intersections to grant an advantage over authoritative hazard volume.
- Group all cloud assets in the current canonical art manifest with creator, license, source, moodboard/provenance, revision and review status before final art lock.

## Shot/QA acceptance plan
1. Wide shot: calm coastal basin, readable low cloud and stable Harbor Listening Steps sightline.
2. Formation shot: Copper Anvil building while boats take shelter.
3. Storm shot: rain curtains and a single readable impending lightning strike.
4. Recovery shot: repaired pylon through clearing cloud, water reflections consistent with atmosphere.
5. Night shot: moonlit fog with adequate silhouette contrast.
6. Ice shot: cloud/floes tonal separation at accessibility brightness extremes.
7. Split quality capture: base scalability vs high scalability show the **same** hazard zone and safe path.

**Missing production assets:** texture volumes/noise tiles, material instances, Niagara emitters, sound hooks, screenshots, LFS provenance, engine runtime profile and packaging results. All are pending.
