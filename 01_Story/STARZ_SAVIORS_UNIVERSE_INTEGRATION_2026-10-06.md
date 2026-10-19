# STARZ* / Saviors of the Universe — Echohearts: Rebearth Integration

**Status:** CANON-INTEGRATED EXPANSION LANE / RUNTIME NOT VERIFIED  
**Date:** 2026-10-06  
**Authority:** This file extends the existing Echohearts: Rebearth universe. It does not create a second canon, second runtime, or second Eco-Kin Dex.

## Integration decision

STARZ* / **Saviors of the Universe** is connected to the existing **Star Rewrite** / post-Rebearth cosmic expansion lane.

The material is not a replacement campaign and does not overwrite the Rebearth restoration story. Its entry point is earned after the player reaches the late **War of Summoning → Star Rewrite** progression boundary and the wider Riftway network becomes accessible.

The playable universe remains anchored to:

- **Rebearth** as the primary planet and restoration authority;
- **Echohearts Sanctuary** as the central restored hub;
- **Frequency Tamer / Core-Binder** player identity;
- **A.E.G.I.S.** as the field interface;
- **Vibrance, Density, Harmony, Purity** as the public attribute matrix;
- **Anima-Link** and **Huma-Link** consequence contracts where applicable;
- the **125-ID Permanent Dex** as Eco-Kin roster authority;
- **Nature** as a Legendary Humanoid-Kin with conditional Mutations.

STARZ* is expansion language, not a new core element and not a new Eco-Kin species category.

## Recovered STARZ* material accepted into the universe

### Young Saviors
- Glitter
- Sparkle
- Bling
- Dazzle
- Bright
- Light
- Shimmer
- Shine
- Luminous

### Original Saviors
- Radiant
- Nova / Super Nova
- Spectra
- Milky Way
- Nebula
- Solar
- Lunar

### Primary antagonists and independent actors
- Mena
- Althea
- Garth
- Lord Dred
- Devoid
- Darkvoid
- Laseriz
- Lunaz
- Finao
- Gradiaunt
- Joyner
- Joyce

### Supporting NPC lane
- The Watchers
- Finn
- Guiding Light

These names are accepted as the **legacy-recovered STARZ* roster** for continued design work. Exact species/classification, final visual identity, gameplay kit, age presentation, and unlock timing remain subject to current canon review before implementation.

## Story bridge

### Entry condition
The bridge begins after the player has restored enough of Rebearth's Riftway network for A.E.G.I.S. and D.A.H.L.I.A. to distinguish stable off-world frequencies from Blight/Gloom interference.

A STARZ* signal is not treated as a capture target. It is treated as an intelligent contact request.

### First contact
A.E.G.I.S. receives a multi-source stellar pulse that resolves into nine young signatures and several older responder signatures. The signals are connected to damaged worlds beyond Rebearth.

The Frequency Tamer / Core-Binder can:

1. authenticate the signal;
2. compare it against Meridian and Heart-Code records;
3. establish a Huma-Link-compatible communication boundary where the contacted being is humanoid;
4. open a bounded Riftway connection;
5. accept or defer a request for help.

No STARZ* entity is automatically enrolled, owned, stored, captured, or converted into an Eco-Kin record.

### Expansion thesis
The Saviors lane extends Echohearts' central question:

> What does responsible power look like when the consequences are no longer limited to one world?

Rebearth's restoration history becomes the Saviors' evidence that survival does not justify permanent control.

## Summoning Wars

**Summoning Wars** becomes the first STARZ*-connected expansion conflict.

Summoning in this lane is not Eco-Kin capture. It is a separate contract system for calling already-consenting allied fighters, constructs, projections, or temporary combat manifestations through authenticated artifacts and banners.

Allowed design language:
- crystals;
- runes;
- sigils;
- banners;
- star-linked contracts;
- temporary summoned allies;
- authored trial/unlock requirements.

Not allowed:
- converting summoned beings into Eco-Kin Dex entries;
- bypassing consent;
- consuming sentient beings as crafting materials;
- creating a second inventory ownership system for living beings;
- replacing A.E.G.I.S., Kindling, Anima-Link, or Huma-Link.

## Saviors of the Universe

**Saviors of the Universe** is the broader post-Rebearth cosmic continuation.

Core pillars:

- damaged-world rescue;
- star-linked traversal;
- team assembly through earned alliances;
- real-time action combat;
- large-scale faction threats;
- planetary restoration consequences;
- choices that affect whether outside powers cooperate with, exploit, or fear Rebearth;
- persistent consequences recorded through the existing save/profile authority.

The young Saviors are not reduced to generic party slots. Their identities, trust, and progression must be represented through authored records and persistent relationship state.

## Ancient Tech Wars

**Ancient Tech Wars** remains a later expansion lane.

Its production rule is strict: only original Echohearts technology, factions, entities, landmarks, terminology, and artifacts may be promoted into current canon. Historical material based directly on real-world mythology, scripture, or outside media remains **REFERENCE / RETIRED / REWRITE REQUIRED** unless the user explicitly commissions a benchmark or a transformed original replacement.

The usable design core is:

- forgotten high-energy infrastructure;
- ancient interplanetary conflict;
- relic networks;
- dimensional gateways;
- lost machine civilizations;
- old weapons whose original purpose is uncertain;
- competing interpretations of recovered technology.

## Runtime routing

Executable ownership belongs only in:

`Dlomotion/ECHOHEARTS-REBEARTH-BUILD-`

The canon repository owns:
- roster approval;
- naming;
- story placement;
- DLC order;
- design contracts;
- classification;
- world/quest continuity.

The BUILD repository owns:
- Unreal C++ data structures;
- Blueprint-facing records;
- save/network implementation;
- replication;
- runtime tests;
- packaging/runtime evidence.

Legacy C++, C#, JavaScript, HTML, Python, SDL, Unity, Visual Studio cache/output, and mixed-language recovery files must **not** be copied into the Unreal module as a single source file.

## Legacy source recovery disposition

### KEEP AS DESIGN SOURCE
- STARZ story material;
- Savior rosters;
- antagonist rosters;
- Summoning Wars concepts;
- crystals/runes/sigils/banners;
- relationship and alliance concepts;
- cosmic rescue and damaged-world progression;
- multiplayer/PvE/PvP concepts that survive current systems review.

### REWRITE FOR UE5.8
- combat components;
- summon contracts;
- roster data;
- story scenes;
- inventory references;
- online/session hooks;
- UI;
- persistence;
- networking;
- movement;
- AI.

### RETIRE AS BUILD INPUT
- standalone `main()` programs;
- SDL loops;
- Unity `MonoBehaviour` code;
- raw HTML/JavaScript/Python embedded inside C++;
- Visual Studio `.vs/`, `ipch/`, `x64/Debug/`, `*.tlog`, Copilot index/session caches;
- duplicate function/class definitions;
- hard-coded generic HP/Attack/Mana roots where they replace the four Echohearts attributes.

## Git Credential Manager note

`git-ecosystem/git-credential-manager` may be used as a **developer workstation credential helper reference** only.

It is not:
- an Echohearts runtime dependency;
- game code;
- a packaged game library;
- a source of canon;
- a reason to commit credentials or machine-local authentication state.

No secrets, access tokens, credential caches, or machine-specific auth files belong in the repositories.

## Production order

STARZ* integration does not bypass the established runtime sequence:

1. UE5.8 executable foundation;
2. clean clone + Git LFS;
3. UHT / Development Editor build;
4. authored map load + PIE;
5. bounded Automation;
6. packaged Development runtime;
7. first verified humanoid + Eco-Kin runtime slice;
8. 4–6 Eco-Kin vertical slice;
9. save/network/platform proof;
10. late-story and expansion implementation;
11. Summoning Wars;
12. Saviors of the Universe;
13. Ancient Tech Wars.

## Verification boundary

This integration establishes a repository/canon contract only.

**REPOSITORY CONTRACT PASSED** may be used after merge.

Do not claim UE5.8 compilation, UHT/UBT, editor launch, PIE, networking, save/load, packaging, performance, or target-hardware behavior from this document.

**NOT VERIFIED — UE BUILD/RUNTIME EVIDENCE REQUIRED**
