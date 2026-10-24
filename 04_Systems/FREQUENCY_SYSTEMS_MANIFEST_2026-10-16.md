# Echohearts: Rebearth — Frequency Systems & Manifest
**Date:** 2026-10-16  
**Status:** APPROVED-PENDING systems design intake; **NOT YET VERIFIED** in UE5.8  
**Authority:** `MASTER_PROJECT_INDEX.md` → `00_Canon_Lock` → existing Game Bible and system contracts. This is an extension, **not** a new master bible, Dex, timeline, or runtime.

## 0. Intake and originality correction
The supplied text combines desired functionality with externally styled encounter/update descriptions, repeated passages, unsupported launch statements and incompatible treatment of sentient life. Do not promote those external names, enemy choreography, lore, or October 21, 2026 multi-platform release assertion as Echohearts canon. The eleven encounter descriptions are **REFERENCE-ONLY**, undergoing independent redesign in `05_Levels/FREQUENCY_ENCOUNTERS_REDESIGN_2026-10-16.md`. New names, dates, quest stages, NPC biographies, drops, spawn rates and balance figures remain **PROPOSED** until narrative/originality/QA approval. Do not silently create permanent EcoKinIDs. Never copy externally branded update schedules, characters, bosses, names, or assets.

Canon guardrails:
- Planet **Rebearth**; primary city **Echohearts City**, starter district **Meridian**; restored central hub **Sky Haven / Echohearts Sanctuary**.
- Player is the **Core-Binder** (Frequency Tamer as a compatible contextual descriptor); A.E.G.I.S. is the bracer and D.A.H.L.I.A. is the ethical/systems module.
- Public attributes: **Vibrance, Density, Harmony, Purity** only. Harmonic and Discordant are situational resonance **conditions**, not new character attributes, alignments that decide morality, Essences, or replacement factions.
- Active Essences as locked: **Flora, Torrent, Pyre, Terra, Aero, Glaze, Voltic, Aura, Shade**. An Echo effect is a Harmony-driven interaction tag, not an Essence. Blight/Data Virus remains ecological corruption; Gloom is its separate story-linked fear/memory axis.
- Nature remains the canonical Legendary Humanoid-Kin Guardian of Life, with conditional Mutations rather than default evolution.
- Do not force Eco-Kin capture, breeding, labor, summoning, mutations, or containment; the existing Kindling/bond/agency contract governs voluntary companion activity.
- World mission progression must join existing Heartroot restoration, factions, Riftways, sanctuary, and story chronology. The expansion does not redefine the main campaign's ending.

## 1. Frequency state architecture
**Purpose:** make storms, buildings, sentient residents, vessels, ecology and boss arenas share an observable, reversible world-state simulation rather than disconnected minigames.

**Inputs:** regional restoration flags; natural climate; humidity, atmospheric pressure and wind; current Blight/Gloom conditions; terrain and water chemistry; authoritative time; occupied Sanctuary components; local A.E.G.I.S. scans; player/Eco-Kin Vibrance, Density, Harmony, Purity; active Anima-Link strain; voluntary NPC/partner participation.

**Derived technical quantities:** `LocalSignalStability`, `DistortionPressure`, `BarrierIntegrity`, `CloudWaterLoad`, `CurrentVector`, `DiverExposure`, `ShipSeaworthiness`. These are **internal simulation gauges**, *not* public fifth-through-twelfth stats. No public "sanity" or "mana" meter. Gloom can produce authored navigation/perception interference with optional accessibility alternatives.

**Conditions** (non-exclusive world tags):
- `Frequency.Harmonic`: coherent local signal, stronger restoration opportunities, safer beacon registrations.
- `Frequency.Discordant`: interference or Blight/rift damage, disabled equipment, disrupted tracking, habitat stress; **not** inherently hostile Eco-Kin.
- `Frequency.Unstable`: oscillation between states where signal evidence is contradictory.
- `Frequency.Recovering`: player actions have begun a persisted world-state restoration process.

Suggested internal computation only: normalize the project's four attributes per their authoritative balancing tables, then derive stability from Harmony/Purity, infrastructure state, environmental pressure and independent hazards. Do **not** hardcode a canon formula or resistance table before balance review. Record source, units, clamps, tick interval and server-authoritative result for each system.

**Anima-Link rule:** bonded Eco-Kin damage and excessive combat strain feed a bounded, bi-directional strain consequence to the Core-Binder, with clear telegraph, agency and recovery options. Harmonic barriers moderate harm but never erase consent/trust checks; hazard sources must not exploit per-frame repeated damage events.

## 2. Frequency Sanctuary / Guardian registration
A **Frequency Sanctuary** is a specialized functional sub-zone inside the established Sanctuary/housing system, *not* a replacement hub, new claimable species enclosure or compulsory resident dormitory.

### Required structures (all four)
1. **Aura Pylon** — unique `SanctuaryZoneID`, beacon radius, world-partition anchor and registered frequency signature.
2. **Tuning Station** — owner/authorized co-op interaction, repair/calibration UI, validation feedback and research unlock interface.
3. **Recharging Node** — ethically designated rest/service point; voluntary NPC rest, powered state, replenishment and failure feedback.
4. **Energy Walls** — a connected navigable perimeter with validated collision, egress and hazard protection. Walls shield living residents; they must not confine sentient Eco-Kin or block evacuation.

### Registration transaction
`Zone discovered → Pylon online → Station accessible → Node powered → perimeter flood-fill/egress checked → World Partition owner/permissions checked → request resident consent → register Guardian → persist authoritative signature → replicate display state`

Validation is **server-authoritative**, idempotent by `SanctuaryZoneID + GuardianIdentityID` and race-safe in multiplayer. A single Guardian cannot register as an active resident in two zones. Missing module, broken path, hostile overlap, insufficient power, offline story gate, registration collision, absent consent and occupancy limits must return separate rejection reason tags. Recover gracefully after streaming unload, device relink, weather outage or save restore. Sanctuary placement uses existing BCT-001 transaction and housing authorization contracts, not a second build grid.

### Gameplay behavior
Guardian resident status: `Available → Invited → Travelling → Anchored → Resting → VoluntarilyDeparted`; suspended infrastructure moves Anchored → AwaitingRepair without deleting the identity or relationship. A.E.G.I.S. displays state, hazard warnings and repair/escort tasks. Resident NPCs cannot engage threats outside authored defensive areas, shoot across allies, or bypass player/world safe-zone rules.

## 3. Spark Guides, vital specialists and technicians (PROPOSED-NPC-ROLES)
Seven role titles provided in intake are working role handles, **not** claims that characters already exist in official cast. Narrative naming, silhouette and relationships must be reconciled to the existing NPC registry before approval.

| Role | Sanctuary/public service | Field defense behavior | Technical dependency |
| --- | --- | --- | --- |
| Attuner | scan found raw/structural material; reveal researchable Frequency Gear recipes only after provenance/scanning | slow, readable Aura-aligned pulse darts and threat-mark support | Research, A.E.G.I.S. scanning |
| Chrono-Merchant | safe trade of Pulse Flares, Flux Nets used for environmental work, base Aura Batteries | throws salvage decoys to divert intruders, not sentient capture traps | economy price/ownership rules |
| Vitamist | repairs A.E.G.I.S.-linked integrity with collected, authenticated fragments | throws ally-only restorative ampoules; no hostile medical needles | Anima-Link care, consent |
| Catalyst Specialist | supplies rock-clearing seismic charges for surveyed mineral strata | compact ground tremor with controlled blast radius | structure-safe blast permissions |
| Bloom Weaver | reports local restoration/Blight pressure with source and uncertainty; sells seeds/aerosol collectors | deploys temporary perimeter dampener, protects residents, damages only tagged hostile threats | Living Soil, weather sensing |
| Scrapwright | merges compatible modifications, offers capped, auditable recalibration | deploys retractable localized defense spikes with warning arcs | crafting provenance, modification rules |
| Cyber-Mechanic | wiring, relays, triggers, interval timers, actuators for custom defenses | throws an autonomous-return service implement with anti-friendly-fire constraints | building network authority |

Do not conflate the role-handle **Chrono-Merchant** with Aevoryn's canonical Time Guardian role. No role can sell Eco-Kin, convert free beings into commodities, or bypass sanctuary/consent gates.

## 4. Dynamic clouds, storm clouds, sky-state gameplay
The **Rebearth Atmospheric Field** simulates cloud strata that telegraph humidity, wind, lightning and local frequency damage. Visual identity is authored per region, season, elevation, waterway and recovery state; cloud shapes are not hardcoded "dark sky = evil."

Cloud classes:
- **Lowland Drift** — fair-weather cumulus with moving shadows and soft precipitation possibility.
- **Spindrift Shelf** — high-altitude Glaze/Aero ice crystals before shelf winds.
- **Copper Anvil** — tall convective storm mass: layered cloud base, safe lightning countdown, gust fronts, flood risk.
- **Brine Veil** — ocean fog banking over reef and ship approach lanes, affecting visibility and acoustics.
- **Rootmist Canopy** — transpiration fog around healthy Flora biomes, with vegetation-driven morning dissipation.
- **Blightfront Umbra** — localized environmental-frequency corruption with intermittent scan noise; visibly reversible through restoration.
- **Aurora Threadcloud** — rare high-atmosphere visual phenomenon; not an automatically new Essence or celestial species.

Storm logic: forecast → cloud thickening → pressure/wind change → localized hazard telegraph → active interval → dispersal → recovery. Lightning and mechanical impacts are server-authoritative, bounded and seeded; volumetric cloud materials, sky atmosphere, sound and Niagara are client-side presentation. Storms may damage unattended ship rigging, alter water currents, interrupt sanctuary pylon signal, redistribute seeds or unlock scan clues. Every hazard needs a non-combat mitigation or shelter path, color-blind legibility and photosensitivity option. Weather must persist and reproduce across travel/loads without spawning the entire planet's storm FX simultaneously.

## 5. New maritime / diving / shipbuilding loop
Rebearth has an **approved-pending coastal expansion direction**, not an imported archipelago map or a new origin planet. See `02_World/FREQUENCY_CLOUDS_AND_MARITIME_BIOMES_2026-10-16.md` for candidate regions.

### Gameplay loop
`Observe sky → scan current → plot safe channel → prepare hull / diving loadout → voyage → explore/salvage/restore → return with evidence → research → unlock ethical upgrades → persistent world delta`

**Shipbuilding:** keel slot → hull panels → buoyancy compartments → deck/support → propulsion/sail/engine → navigation/A.E.G.I.S. relay → storage → rescue gear → optional non-lethal defense. Components validate attachment graph, center-of-mass envelope, collision, floatation budget, passenger capacity, energy/power links and co-op editing permissions. Ships have condition and cargo mass limits. Blueprints export **versioned, signed/sanitized configurations only**, no executable scripts, path traversal, unauthorized assets, or ownership tokens. Native full fluid simulation is **not promised**; water interaction should be bounded, performant and network-safe.

**Diving:** pressure tiers, breathing-gas supply, thermal exposure, visibility, current strength, decompression-safe ascent and partner wellbeing are derived hazards, not new public attributes. Establish ascent routes, dive buddy signals, emergency surface options and an A.E.G.I.S. distress beacon. Deep trench entry requires earned pressure-shell research and approved location gates. No instant fatal exposure without clear information and reachable counters.

**Marine Eco-Kin welfare:** map ecology, listen/scan, restore pollution, observe migration and develop voluntary Kindling where the authoritative Dex permits. No forced capture/breeding of reef apex beings; any aquatic mount/escort requires a bonded, consenting identity in the existing roster and habitat-appropriate anatomy. Do not create a new Leviathan EcoKinID from the reference text.

**Coastal activities:** tidal salvage, trench sampling/fishing under sustainable harvest limits, reef mapping, wreck memory reconstruction (for evidence only), cooperative rescue voyages and optional player-authorized **uncrewed** expedition drones/ships. Passive fleets must not assign forced Eco-Kin labor or create idle exploits.

**Anomalies:** natural weather is distinct from **Blight pressure scars**. Memory fog is Gloom-linked and not a medical "sanity" stat; temporal surface rain is only local authored Chrono-Rift equipment timing; electric downpours use Voltic/Aero environmental behavior, not radiation by default. Counters include insulated sails, lantern refractors, freshwater condensers, hull grounding and pressure seals. All have research source and failure feedback.

### Optional campaign cadence
The 21-day, two-phase proposal is a **replayable expedition scenario option**, not a mandatory real-time reset of the main Rebearth world and not a confirmed release schedule. Candidate split:
- **Days 1–10 / Reconnaissance:** coastal rescue, survey, sanctuary outpost, diving training, initial modular ship commissioning.
- **Days 11–21 / Deep Accord:** expanded offshore map, controlled anomaly repairs, encounter windows, relic provenance and watershed restoration.
The permanent campaign stores restored ecosystems and story consequences separately from any seasonal instance reset. Authoritative UTC governs any live-service events; offline/single-player use a local-simulation equivalent with an explicit mode boundary. No competitive extraction/PvEvP mode is approved simply because it appeared in source material.

### Original narrative integration
A storm-broken vessel brings the Core-Binder to a coastal aid network seeking damaged Heartroot-linked seabed relays. Two **unnamed pending** navigator/engineer roles investigate a wreck-signature archive and a disputed salvage liability; their eventual identity/relationship must be reconciled with existing cast and Meridian history, not copied from supplied examples. A.E.G.I.S. cross-checks artifact origin; D.A.H.L.I.A. prevents inferred memories from being mistaken for verified testimony.

## 6. Echohearts City — bowling alley district attraction
Add a **PROPOSED** interactive bowling alley in Echohearts City as a playable community space rather than a static landmark:
- six original lane environments, shared or solo sessions, rolling physics with server-validated scoring, aim/spin/curve assist, arcade/casual accessibility options, and spectating;
- visibly repaired/reopened through district restoration tasks, with a city resident staff roster, equipment maintenance mini-quest, optional co-op tournament and non-power rewards;
- weather affects the exterior streets and travel, not unfairly changing indoor ball physics; no pay-to-win equipment;
- **13:30** is a proposed *in-world* daily league check-in (user's "bowling alley at 1:30"), **not** evidence of a real-world appointment. Confirm story/map and in-world timezone before making a locked scheduled event.
Use Echohearts City existing point-of-interest map and social activity layer; do not invent exact world coordinates.

## 7. Encounter set / world progression
There are **eleven supplied encounter slots**, not automatically eleven canon bosses. The source configurations are reference material. `05_Levels/FREQUENCY_ENCOUNTERS_REDESIGN_2026-10-16.md` defines eleven independent, original mechanics concepts with playable telegraphs, ecological/restoration outcomes, and specific non-copying changes. Labels `Pre-Awakening` / `Grand Awakening` do not override the established Six Eras, eight acts or campaign gate; map those labels only after story review. Bosses that are actually injured sentient Eco-Kin must use Sovereign Encounter welfare/resolution rules.

## 8. Data, multiplayer, platform and implementation ownership
- Contract/data authority: this repository `Dlomotion/Echohearts-Rebearth` under `04_Systems`, `02_World`, `05_Levels` and `09_Technical`.
- **Executable UE5.8 authority** according to existing project index: `Dlomotion/ECHOHEARTS-REBEARTH-BUILD-`; **repository currently inaccessible through this connection**, so do not claim runtime code was added or compiled.
- Suggested UE layers when BUILD access exists: `UWorldSubsystem` for regional frequency/weather; `UActorComponent` for Sanctuary registration and module states; `UPrimaryDataAsset` / DataTable definitions for NPC roles and vessels; `UStateTree` or Behavior Trees for encounters; `AActor` for authored weather volumes, ship hulls and interactables; `IGameplayTagsModule` tags; replicated fast-array summaries only for active streamed regions; async saves through existing account registry.
- Never trust client save files, weather/time overrides, blueprint payloads, drop rolls or NPC registration. Use BCT-001 transaction / authority. Cloud-sync requires authenticated user identity, least privilege, conflict resolution, schema migrations and no plaintext secrets.
- Cross-platform **design target**, not shipping proof; gamepad/touch/keyboard adaptation, portable UI, deterministic simulation tests and per-platform build/certification evidence are separate gates. UE performance target remains 60 FPS under representative hardware budgets, **not verified**.

## 9. Quality and acceptance checklist
- [ ] Originality and narrative owners approve names, phase structure and NPC identities.
- [ ] All public displayed stats are V/D/H/P; Essences use registry only.
- [ ] The 125-ID Dex is unchanged; no sentient capture/trade/breeding/forced work.
- [ ] Sanctuary graph validation rejects broken wall, inaccessible station, unpowered node and absent consent; retries are idempotent.
- [ ] Storm fronts are deterministic/reconnect-safe; hazard counterplay is telegraphed, accessible and bounded.
- [ ] Voyages, dives and boat blueprint import reject unsupported/unsafe/oversized structures.
- [ ] Boss phases cannot softlock, skip restoration gates, or instant-kill through unreadable damage.
- [ ] Bowling scores validate authoritatively, including reconnection.
- [ ] UE5.8/UHT/compile, Windows Development packaging, network authority, rollback and 60 FPS evidence are actually collected in BUILD before `VERIFIED` labels appear.

**Provenance:** Derived from user-requested feature intent, with reference-only elements redesigned under `MASTER_PROJECT_INDEX.md` intake/originality rules. All above expansions are **PROPOSED / APPROVED-PENDING review** unless independently supported by existing canon.
