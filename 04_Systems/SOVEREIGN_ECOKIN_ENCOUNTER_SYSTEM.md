# SOVEREIGN ECO-KIN ENCOUNTER SYSTEM

**Status:** CANON direction; tuning and implementation remain APPROVED-PENDING.

## Purpose

This system replaces generic `Alpha Eco-Kin capture boss` design with an original Echohearts encounter class that preserves Eco-Kin agency and the established restoration loop.

`Alpha` may remain as historical shorthand in old notes, but publication-facing terminology is **Sovereign Eco-Kin** or **Sovereign Encounter**.

A Sovereign is a regionally dominant Eco-Kin whose size, age, ecology, Resonance condition, Ancient Beast lineage, territorial role or Blight pressure makes it a major world encounter.

Sovereign does **not** automatically mean evil, capturable, Legendary, Titan or corrupted.

---

## 1. Encounter goals

A Sovereign encounter can resolve through one or more of these outcomes:

- protect a region from its destructive panic;
- cleanse Blight pressure;
- restore habitat conditions;
- prove non-hostile intent;
- survive a territorial challenge;
- complete a Guardian test;
- drive the creature away from civilians without killing it;
- earn trust through repeated encounters;
- unlock a future Kindling opportunity where authored;
- document its ecology for the EcoDex;
- expose a faction or environmental cause behind its behavior.

No standard encounter requires caging, harpooning, genome extraction or permanent restraint.

---

## 2. Scale and phase structure

Sovereigns can use multi-phase real-time encounters.

A typical structure:

1. **Warning Phase** — territorial displays, environmental hazards, readable telegraphs.
2. **Pressure Phase** — direct combat / protection / pursuit mechanics.
3. **Breakthrough Phase** — player discovers the ecological or emotional cause.
4. **Resolution Phase** — calm, cleanse, protect, retreat, bond opportunity or story consequence.

Health gates may exist internally for encounter pacing, but the public design language should emphasize **behavior phases**, not a generic five-times-HP boss template.

---

## 3. Derived encounter metrics

Do not expose old copied stats as a parallel public system.

Internal boss tuning may derive from:

- Vibrance;
- Density;
- Harmony;
- Purity;
- body scale;
- armor / shell / fur / hide structure;
- current Strain;
- Blight state;
- terrain advantage;
- active phase;
- encounter difficulty setting;
- player party composition.

Possible internal runtime values include health pool, stagger threshold, guard resistance, ability cooldowns and phase thresholds. These are implementation details, not replacement public stats.

---

## 4. Ethical field tools

Retire the old `Harpoon Ballista → Pitfall → Induction Cage` capture loop.

Allowed Sovereign encounter tools include:

- A.E.G.I.S. Scan;
- Listening Posts;
- Resonance Anchors for area stabilization;
- Purity Field Rings;
- terrain braces / breakaway barriers;
- evacuation beacons;
- safe food or water placement;
- scent masking for nonviolent observation;
- Recovery Sleds for injured creatures where physically appropriate;
- Open-Gate Recovery Pens for temporary voluntary shelter;
- Echo Cradles only for small injured Eco-Kin, never as a Sovereign containment device;
- partner-assisted calming and route control;
- environmental restoration objectives.

These tools manage **space, safety and stress**, not ownership.

---

## 5. Tracking and hunting correction

The useful tracking gameplay is retained as **Ecological Tracking**, not trapping-to-capture.

Players can study:

- footprints;
- shed feathers / fur / scales;
- damaged bark;
- feeding remains;
- disturbed water;
- nesting material;
- Blight residue;
- call patterns;
- migration routes;
- weather changes;
- elemental traces.

Food and scent systems may be used to observe, redirect, rescue or create safe distance. They may not bait a sentient Eco-Kin into a cage for ownership.

Food spoilage can remain an ecology/survival mechanic if balanced, but it is not a capture requirement.

---

## 6. Sovereign rewards

Do not reward sentient genome harvesting.

Valid rewards include:

- Resonance Shards shed naturally or granted after a resolved encounter;
- purified environmental materials;
- Ancient Tech fragments with provenance;
- EcoDex knowledge;
- Sanctuary upgrades;
- traversal access;
- faction standing;
- championship invitations;
- Growth Rite catalysts;
- cosmetic trophies that do not use body parts taken through cruelty;
- world-state restoration;
- future Kindling / trust flags.

No body-part farming loop is required.

---

## 7. Encounter classes

A Sovereign may carry one or more tags:

- `Sovereign.Territorial`
- `Sovereign.Guardian`
- `Sovereign.AncientBeast`
- `Sovereign.DarkBeast`
- `Sovereign.BlightTouched`
- `Sovereign.Migratory`
- `Sovereign.TitanScale`
- `Sovereign.Ritual`
- `Sovereign.ArenaExhibition`

These are gameplay tags / design labels, not new elements.

---

## 8. Championship connection

Defeating or resolving a Sovereign in the campaign does not automatically increase Arena rank.

A special **Sovereign Exhibition** may exist inside Resonance Arena as a simulation challenge. Successful sanctioned championship fights contribute to **Resonance Circuit Standing**.

This keeps world ecology and competitive status connected without making living wild Eco-Kin into rank-farming targets.

---

## 9. Technical posture

No new C++ should be written for this system until the current UE5.8 technical gates are satisfied.

When implementation begins, prefer:

- Data Assets / Data Tables for Sovereign definitions;
- Gameplay Tags for phase and state labels;
- StateTree / Behavior Tree only where justified by actual AI architecture;
- server-authoritative phase transitions;
- world-state and save flags;
- event-driven UI;
- World Partition-aware encounter streaming;
- deterministic reward resolution;
- testable phase transition conditions.

The pasted Python-like `AlphaEcoKinComponent` is reference-only pseudocode and is not production code.

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.
