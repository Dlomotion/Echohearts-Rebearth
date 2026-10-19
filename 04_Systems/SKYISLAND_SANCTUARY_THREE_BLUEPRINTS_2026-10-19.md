# Skyisland Sanctuaries — Three Deployable Layout Specifications
**Date:** 2026-10-19  
**Status:** PROPOSED BLUEPRINT DATA + STATIC GEOMETRY CHECKS; not placed in Unreal, not gameplay-verified  
**Authority:** existing `MASTER_PROJECT_INDEX.md`, `00_Canon_Lock/CANON_CORE_RULES.md`, Sanctuary, BCT-001 placement/authorization, Living Soil, Kindling, Anima-Link, Forms Registry and Data Dictionary.

## Why the submitted catalog requires conversion
The source text repeats itself and includes external franchise terms, a sanity (SAN) stat, creature spheres/capsules, infinite resources, forced labor, stress-for-output, genetically breeding "perfect" companions and consuming duplicate Eco-Kin to upgrade another. **Those systems must not enter production.** Only Vibrance, Density, Harmony, Purity are public character attributes; existing nine Essences apply. The planet is Rebearth, beings are Eco-Kin, and their participation is voluntary.

### Canon-compatible structure replacement registry
| Intake label / intent | Safe project-facing structure/handling | Rule |
|---|---|---|
| Echo-Core territory anchor | **Sanctuary Core Relay** | extends existing core/beacon; world claim only if BCT-001 authorizes; no duplicate world-hub |
| Dormant Moss-Cradle, Blossom Canopy, Elder-Root Pavilion | **Moss Rest, Blossom Shelter, Elder-Root Retreat** | species-compatible voluntary rest; no SAN statistic or mandatory enclosures |
| Hearth-Trough | **Habitat Feed & Water Point** | ecology-based nutrition and hygiene; does not own residents |
| Resonance Altar | **Frequency Craft Station** | early tools and *non-sentient* restorative supplies |
| Anima-Sphere Loom / Celestial Assembly Array | **Rescue Equipment Loom / Restoration Assembly Line** | sterile field kits, environmental dampeners, beacon parts; no creature-capture spheres |
| Prismatic Crucible | **Prismatic Refinery** | closed industrial process with purification, heat isolation and emissions capture |
| Frequency Crusher | **Material Recovery Mill** | approved plant fiber/stone recovery; no externally branded substances |
| Timber-Sprout Grove / Geo-Pulse Quarry | **Managed Coppice / Regenerative Quarry** | capped yields and elapsed regrowth; no infinite loops |
| Sun-Drop, Glow-Wheat, Astral-Tomato | **Living Soil crop plots** | crops/recipes require existing game-data registry; names pending |
| Sanctuary Pasture | **Open Habitat Meadow** | Eco-Kin can graze/rest/leave; no manufactured collectible drops |
| Harmonizer Podium | **Environmental Comfort Console** | adjusts lighting/rest music and ambience, **never** pushes unwilling Eco-Kin into higher output |
| Anima Condenser | **Growth Rite Preparation Basin** | approved Shimmer/Resonance Trait Infusion with active consent; **no merging/consumption of individuals** |
| Glow-Spring / Luminescent Geyser | **Glow-Spring Care Pools** | timed, species-sensitive, voluntary therapeutic relief; not universal instant healing |
| Spiritual Apothecary | **Recovery Apothecary** | clean-sourced salves, care and triage; invasive treatment requires established health logic |
| Brier-Rose, Living Stone | **Living Perimeter** | anti-Blight/hostile-device containment with guarded egress; no imprisoning residents |
| Echo-Cannon, Seed-Gatling | **Nonlethal Signal Interceptor** | automated protection of base from validated hostile incursions; friendly safety and retreat lanes |
| Leyline Siphon | **Grounded Ambient Energy Collector** | capped charging from solar/wind/Voltic weather; no extraction from sentient Eco-Kin |
| Breeding Grounds | **Glow-Spring Recovery & Habitat Garden** | **breeding/eugenics mechanics explicitly rejected**; care, voluntary socializing and habitat research are in scope |

## Module coordination & grid contract
Data source: `04_Systems/Data/skyisland_sanctuary_layouts.v1.json`. All units are abstract cells **not centimeters or approved world coordinates**. The geometry defines 35 nonoverlapping rectangles across three independent plots. Blueprints become actual placed level assets only after map/collision/World Partition owners resolve plot geometry, ramp slopes and building footprints. Energy Walls are an **additional continuous perimeter graph around approved Sanctuary zone**, not represented by the rectangles; wall/egress validation must be implemented before Guardian residence activates.

**Global placement invariant:** validate claim and ownership → terrain support → non-overlap/nav corridors → accessibility/evacuation → power/fire safety → BCT-001 materials reservation → commit placement once → save/replicate authoritative result → activate voluntary residents only if welfare/consent and support are valid. Do not instantiate a second save manager or second NPC registry.

## Blueprint A — Starter Sanctuary (DEPLOY FIRST)
**Grid:** 32 × 32, starting `SKY_STARTER`, Tier 1 candidate. **Key buildings:** Core Relay at (13,13), Aura Pylon (8,12), Tuning Station (8,17), Recharging Node (21,13), north/south access and safe egress. Rest and feed garden are in western arc; care pavilion to east; field craft southwest; Living Soil plots southeast.

### Sequential construction plan
1. Inspect playable Skyisland foundation and confirm nav, ground contact, weather shelter and safe stairs.
2. Use existing BCT-001 permitted claim and Core Relay, not a new radius rule.
3. Mark walkable clear lane (recommended minimum clearance remains **tunable**), validate accessible retreat to south entrance.
4. Install a Pylon + Tuning Station + Recharging Node, with repair path and lightning grounding.
5. Add safe, non-confining **Energy Wall perimeter** that protects the rest area while leaving two verified evacuation routes. Do not seal off residents.
6. Place Moss Rest and Habitat Feed & Water Point; make restorative gardens readable.
7. Add First Frequency Craft Station and Living Soil plot; lock materials behind approved research.
8. Add Recovery Pavilion, readable medical access and voluntary partner routes.
9. Validate save/rejoin, no overlap, plot bounds, one-time cost, terrain collision and NPC safety before activating Guardian invitation.

### First gameplay slice
Player enters starter plot, places core, repairs a damaged shelter, plants a seed, offers a weary Eco-Kin an opt-in care space, and crafts a restoration kit. The partner may accept help, refuse or leave. World-state flags reflect cleaner water and restored path; no automatic bonding.

## Blueprint B — Prismatic Star-Metal Refinery (ADVANCED)
**Grid:** 48 × 40, `SKY_REFINERY`, Tier 3 candidate. Intake and quarantine chamber are toward north; environmental wash and thermal crucible in center-east; cooling and clean stock in southeast; owner controls/power west and separate personnel escape north/west. **This is a materials refinery, not a companion factory.**

### Process route and safety
`Found mineral deposit → survey + obtain legal provenance → sealed intake → Blight contamination scan → quarantine or reject → low-temperature wash/purification → controlled Prismatic Refinery heat step → regulated cooling basin → approved alloy storage → sanitized manufacturing output`.

- **Hazard control:** Raw Blight Husk is hazardous and cannot be traded/refined as an ordinary stockpile. Dedicated quarantine never shares direct route with clean rooms. Anti-contamination readings are server-authoritative.
- **Energy:** controlled ambient charging, insulated batteries, fail-closed overload, grounded power, wind/solar/Voltic weather only; zero living Eco-Kin power extraction.
- **Processing:** batches have input recipe identity, allowed source items, positive/finite quantity, approved costs, time and output bounds. **No infinite duplication:** atomically reserve raw materials, write `BatchTransactionId`, apply conversion once, then release certified output. Failed heat/cooling step redirects to safe quarantine rather than destructive pollution.
- **Voluntary help:** Eco-Kin may *opt into* comfort-appropriate assistance only if safe; nobody assigned to blast furnaces or unsafe conditions. Fully operable solo/by machines.
- **Environmental feedback:** process cleanly or risk *temporary, remediable* pollution events, with informed warnings and realistic player agency.

### Tier gates
Requires approved mining/restoration quest, ecological survey, safe-area plot claim, prerequisite craft station, energy collector, clean water supply, environmental inspection and story approval. Boss victory alone is not authorization to bypass research or pollution rules.

## Blueprint C — Glow-Spring Recovery & Habitat Garden (CARE FIRST)
**Grid:** 42 × 42, `SKY_RECOVERY`, Tier 2 candidate. Core Relay and three Guardian-ready modules on the north. Care ward west, thermal Glow-Spring center, low-stimulus quiet garden east, habitat meadow south-west, filtered water and voluntary rest south-east, central staff evacuation path.

### Services
- **Reception/triage** staffed by approved NPC identities after story approval; existing Recovery Ward/Nurse Calla continuity takes precedence, no unreviewed physician replaces them.
- **Aquatic vs terrestrial access:** adjustable temperature/chemistry, shade, shallow entry, ramps and species-safe independent rest zones.
- **Treatment:** separate prevention, wound care, Blight-exposure isolation, strain/fatigue recovery, discharge and post-care follow-up. Clinical care uses existing health/condition tags, **not SAN**.
- **Growth Rite Preparation Basin (optional future add-on):** only registry-approved, identity-preserving voluntary forms and trait infusion. Never combines bodies, consumes duplicates, forces offspring or manufactures a "perfect" bloodline.
- **Voluntary helper Eco-Kin:** healing/comfort activity only with welfare and consent; player/NPC treatment can succeed without one.

### Gameplay mission
Storm survivors need care after a damaged canal floods. Player samples water, neutralizes pollutants, tunes spring temperature, assists a nurse and makes a safe habitat choice. Outcome: residents regain trust, local watershed improves and optional academy research credit; **no new permanent species minted**.

## Craft tier technical model
These are **workstation tiers**, not new Eco-Kin evolution stages or public attributes.

| Workstation tier | Production capabilities | Gate |
| --- | --- | --- |
| T0: Field Repair | survey, rest facilities, basic non-sentient field supplies | beginner world safety/crafting tutorial |
| T1: Frequency Craft | simple restoration tools, habitat repairs, water filtration | Core Relay and verified Sanctuary footprint |
| T2: Ecological Workshop | upgraded medical/clean-water gear, weatherproofing, safe component assembly | recovered waterway + research assignment + BCT-001 permit |
| T3: Prismatic Refinery | contaminant isolation, metal and composite purification, modular ship/Skyisland repair components | vetted resource provenance + monitored power + approved engineering research |
| T4: Skyisland Civic Array | large infrastructure, advanced energy storage, community transport/safety upgrades | story gate, long-term restoration and civic authorization; no mass creature-capture production |

Recipes require approved item registry IDs and cannot assign made-up numeric crafting costs. Use server-owned `RecipeID, Inputs, Outputs, StationTier, EcologicalPermit, BatchRevision, TransactionId`; apply costs and rewards atomically. Never equate D.A.H.L.I.A. advice with authoritative authorization.

## UE5.8 integration seam (CONTRACT; not compiled code)
- Current BCT-001 construction system owns create/modify/destroy building and inventory transactions.
- Placement layouts are imported as read-only templates; user can mirror/rotate only when bounds and validated walkways remain safe. No raw UObject or arbitrary paths in cloud exports.
- `UPrimaryDataAsset` templates for `SkyislandLayoutDefinition` or existing equivalent; gameplay tags for scene status; World Partition streamed placement owned by server.
- `USanctuaryModuleValidator` and `UResourceBatchProcessor` are **conceptual adapters only**, not guaranteed class names or preexisting C++.
- `TryPlaceLayout(Owner, PlotId, LayoutId, Rotation, Revision, TransactionId)` checks authorization, support geometry, module IDs, zone egress, energy, inventory, server revision; emits explicit safe failure reasons. Transaction idempotency and rollback on missing save are mandatory.
- `TryStartBatch(StationId, RecipeId, InputSource, Revision, TransactionId)` locks input quantities and records one outcome. On disconnect, resume from server journal rather than paying/rewarding twice.
- No unsandboxed Lua execution, custom external network packet authority, duplicate serializer, or speculative thread-safe UObject calls. Use actual UE5.8 APIs only after BUILD checkout.

## Acceptance matrix
- [ ] Grid bounds and overlap checks pass for 3 layouts / 35 modules.
- [ ] Entrance and egress remain reachable after Energy Wall deployment, with emergency opening.
- [ ] Guardian registration rejects missing/offline modules and cannot register twice.
- [ ] No Eco-Kin is traded, captured by sphere, merged, forced to work, drained for power or subjected to automatic breeding.
- [ ] Resource transactions reject zero/negative quantities, dupes, invalid items and raw hazardous stock.
- [ ] Batch resumes/reconnects safely; emissions and temperature are bounded.
- [ ] Voluntary care and refusal both complete related missions.
- [ ] Visual weather and loaded/unloaded Skyisland safety remain consistent.
- [ ] Actual UE5.8 UHT/compile, PIE placement, save rollback, dedicated server and 60 FPS are evidenced in **BUILD**, not claimed from this design.

**Build evidence state:** JSON placement rectangles validated locally during authoring; actual terrain, collisions, nav, inventories, residents and asset meshes still require real UE5.8 integration and QA. All proposed names require registry/name collision review.
