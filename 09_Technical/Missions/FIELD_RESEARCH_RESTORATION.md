# Exploration, Research and Restoration — Canon Quest Intake
User-authorized expansion; additive to original GitHub missions and earlier PR #85–#89. Target UE **5.8.3**.

## 42 individually described quests
### Cartographer's Resonance
- **MAP-01 The First Survey Line:** Map a safe Sanctuary-to-Deepwood route using A.E.G.I.S.. 
- **MAP-02 The Unheard Landmark:** Identify an unlogged landmark by its ambient Harmony signature. Prerequisite: MAP-01.
- **MAP-03 The Broken Trail:** Reconstruct a storm-damaged Scout route without disturbing nests. Prerequisite: MAP-02.
- **MAP-04 Three Horizons:** Survey three connected regions using existing travel routes. Prerequisite: MAP-03.
- **MAP-05 The Hidden Watershed:** Chart a subterranean watershed and its natural outlets. Prerequisite: MAP-04.
- **MAP-06 The Living Atlas:** Validate region survey evidence with the Chronicler. Prerequisite: MAP-05.

### The Living Dex Initiative
- **RES-01 A Record of Kindness:** Observe an Eco-Kin without initiating Binding. 
- **RES-02 An Echoprint in Context:** Compare an approved Echoprint to habitat observations. Prerequisite: RES-01.
- **RES-03 Five Orders, One World:** Document ecological roles across the five sentience Orders. Prerequisite: RES-02.
- **RES-04 The Patient Watch:** Record feeding, shelter and migration behavior without interference. Prerequisite: RES-03.
- **RES-05 The Unaltered Record:** Reject a forged observation and restore authentic research provenance. Prerequisite: RES-04.
- **RES-06 A Living Entry:** Submit verified observations to D.A.H.L.I.A. for Dex review. Prerequisite: RES-05.

### The Sanctuary Research Wing
- **LAB-01 The Clean Bench:** Prepare a contamination-free research station. 
- **LAB-02 The Gifted Sample:** Catalog a naturally shed or voluntarily gifted sample. Prerequisite: LAB-01.
- **LAB-03 Reading the Fracture:** Analyze noninvasive corruption signatures without forced testing. Prerequisite: LAB-02.
- **LAB-04 The Control Habitat:** Compare healthy and recovering ecosystem measurements. Prerequisite: LAB-03.
- **LAB-05 The Missing Reagent:** Recover an ethical Catalyst substitute from an approved seam. Prerequisite: LAB-04.
- **LAB-06 Findings Without Harm:** Publish research to the Chronicler without modifying Echoprints. Prerequisite: LAB-05.

### Roots of Recovery
- **ECO-01 Where the Water Stops:** Trace and clear a blocked clean-water route. 
- **ECO-02 The Seed Carriers:** Restore pollination routes with willing Flora partners. Prerequisite: ECO-01.
- **ECO-03 The Quiet Bank:** Stabilize eroding habitat without disrupting nesting Eco-Kin. Prerequisite: ECO-02.
- **ECO-04 The Returning School:** Reopen a Torrent migration corridor. Prerequisite: ECO-03.
- **ECO-05 A Region Responds:** Defend repaired Heartroot infrastructure from sabotage. Prerequisite: ECO-04.
- **ECO-06 The Imperfect Spring:** Validate restoration gains and record remaining ecological scars. Prerequisite: ECO-05.

### The Kinward Stories
- **KIN-01 The First Recognition:** Learn a selected approved Eco-Kin's natural habitat signals. 
- **KIN-02 A Memory of Shelter:** Discover the species' preferred refuge without disturbing it. Prerequisite: KIN-01.
- **KIN-03 The Choice to Help:** Support an individual Eco-Kin without requiring Binding. Prerequisite: KIN-02.
- **KIN-04 The Long Way Home:** Guide an individual safely through its native corridor. Prerequisite: KIN-03.
- **KIN-05 The Offered Resonance:** Accept or decline an Eco-Kin's voluntary interaction. Prerequisite: KIN-04.
- **KIN-06 The Kinward Chronicle:** Record the individual's story without creating a new Dex species. Prerequisite: KIN-05.

### The Responsible Harvest
- **MAT-01 What Was Shed:** Gather naturally fallen and shed resources. 
- **MAT-02 The Safe Seam:** Survey a Catalyst seam for ecological stability. Prerequisite: MAT-01.
- **MAT-03 The Repair Ledger:** Match approved materials to Sanctuary repair needs. Prerequisite: MAT-02.
- **MAT-04 The Flooded Supply Cache:** Recover abandoned supplies from a safe route. Prerequisite: MAT-03.
- **MAT-05 The Artisan's Test:** Craft a repair component without consuming any Eco-Kin. Prerequisite: MAT-04.
- **MAT-06 Leave the Ground Whole:** Restore the extraction site and validate its recovery. Prerequisite: MAT-05.

### The Rescue Network
- **RSC-01 The Missing Signal:** Locate a missing Eco-Kin from noninvasive resonance traces. 
- **RSC-02 The Narrow Passage:** Clear a collapsed route and escort trapped residents. Prerequisite: RSC-01.
- **RSC-03 A Link Unbound:** Break a forced link without harming either party. Prerequisite: RSC-02.
- **RSC-04 The Deepwater Refuge:** Guide stranded aquatic Eco-Kin through safe passages. Prerequisite: RSC-03.
- **RSC-05 After the Storm:** Coordinate Mender treatment and Sanctuary shelter. Prerequisite: RSC-04.
- **RSC-06 The Safe Return:** Return rescued Eco-Kin to suitable habitat or voluntary residency. Prerequisite: RSC-05.

## Per-Eco-Kin research generator
Five deterministic stages for **each approved Permanent Dex ID**, not five new species: Observe, Study, Assist, Understand, Restore. Research ID namespace: `KIN-RESEARCH-{approvedDexId}-{stage}`. For 125 approved entries this yields capacity for 625 research objectives. The repository's **actual approved Dex identifiers must be loaded from its authoritative registry**; no placeholder species IDs are promoted or fabricated. Forms attach to base Eco-Kin. Completion must be recorded per species and stage in existing profile/save architecture.

## Canon and implementation safeguards
- Sanctuary, Chronicler, A.E.G.I.S., D.A.H.L.I.A., Mender, Scout, Purifier, Artificer and Bondkeeper use existing roles.
- No lethal hunting, forced Binding, capture, sacrifices or Nature encounters as opponents.
- Four attributes: Vibrance, Density, Harmony, Purity; nine Essences: Flora, Torrent, Pyre, Terra, Aero, Glaze, Voltic, Aura, Shade.
- Rewards limited to validated Dex research, Kindling, restoration, corruption cleansed and resident services; no invented currencies.
- All environmental restoration and resource extraction must be ecologically sustainable and recorded.
- The 42 quest definitions and portable C++ gating helpers are **not** a playable UE module; runtime objectives, Blueprint interfaces, SaveGame integration, UI and verification remain pending.
- Verify existing original quest IDs and authoritative Dex data before merging; retain Layer 0 without changes.
