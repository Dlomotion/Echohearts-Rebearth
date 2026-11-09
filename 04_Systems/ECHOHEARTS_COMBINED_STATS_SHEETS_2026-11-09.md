# Echohearts — Combined Stats Sheets (All Editions, One Matrix)

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

One combined stat reference for every Echohearts game: the 2D web, single-file playable, 3D C++, servers, and the UE 5.8 RPG. Genre mechanics are condensed structurally (never copied verbatim from other games) into the Unified Entity Data Matrix implemented in the BUILD repo as `UEchoEntityDataAsset` + `UEchoDexDataAsset`. Status: DESIGN SHEET — balance values from the shipped editions are as-built; matrix defaults are starting values, NOT YET VERIFIED in UE 5.8 runtime.

## Sheet 1 — Player (all editions)
| Stat | 2D / Playable / 3D (as-built) | UE 5.8 RPG (matrix) |
|---|---|---|
| HP | 100 (1 heart = 20 HP) | Vitality 100 |
| Mana | 100 (star drop +50) | — (Resonance Level instead) |
| Stamina | — | 50 (sprint / dodge-frames / heavy actions) |
| Posture/Shield | — | Shield Break Threshold 30 |
| Defence | 2 (+1 per Rebirth, max steps) | Hardness Rating 10 (entity scale) |
| I-frames | 0.66s after a hit | dodge-frames per combat spec |
| Regen | HP slow after 5s no-hit; mana faster standing still | Satiety/Equilibrium drive base efficiency |
| Party | — | 8 carried Eco-Kin, 3 active, no duplicates |
| Rebirth (boss kill) | +20 Max HP, +40 heal, +200 pts | Alignment/Purification progression (Sheet 5) |

## Sheet 2 — Weapons & Combat (as-built editions)
| Weapon | Damage | Cost / Use time | Crit | Notes |
|---|---|---|---|---|
| Echo Pulse | 22 | 0.27s use time | 10% (×2) | strong knockback |
| Echo Burst | 55 | 30 mana | 10% (×2) | heavy projectile |
| Contact damage | enemy dmg − defence (min 1) | — | — | then i-frames |
Matrix fields: Raw Potency, Hardness Rating, Crit Rate (default 0.05), Skeletal Part Health Modifiers (weakpoints), Aggro Weight.

## Sheet 3 — Enemies & Boss (as-built editions)
| Entity | HP | Damage | Defence | KB resist | Behaviour |
|---|---|---|---|---|---|
| Mischievous Imp | 20 | 12 | 0 | 0.2 | fast, darting; steals coins (playable) |
| Void Monster | 60 (×1.25 at night) | 20 | 2 | 0.5 | steady chase |
| Slime / Zombie / Flying Eye (playable) | edition values | — | — | — | sandbox survival set |
| Heartbreaker Boss | 600 + 60/level | 35 | 6 | 0.95 | void orbs, imp minions, enrages <25% HP |
| The Echo Devourer (playable boss) | edition values | charge attack | — | — | enrage + minions at 50%, drops Echo Heart |
Matrix fields: Scaling Archetype (Base / Elite / Apex / Frenzied / Purified), Vitals, Combat, Aggro Weight, part-break table.

## Sheet 4 — Drops & Economy (as-built + RPG)
| Drop | Chance | Effect |
|---|---|---|
| Heart | 25% | heal 20 HP (+10 score as pickup in UE slice) |
| Star | 20% | +50 mana |
| Echo Heart (boss) | boss kill | Rebirth progression |
Trading rules (RPG): legendary classifications and seasonal elements are non-transferable; common cosmetics, materials, and custom trophies trade freely. Weekend vendor + base warden pull catalogs from server time.

## Sheet 5 — Eco-Kin / Entity Matrix (UE 5.8 RPG, the unified sheet)
**Identity:** Unique ID (registry hash) · Taxonomy Class (FGameplayTag) · Scaling Archetype · Dex link (permanent 125-ID Dex; forms link to base IDs).
**Canonical attributes (Dex):** Vibrance · Density · Harmony · Purity.
**1. Vitals & Engine:** Max Vitality 100 · Stamina 50 · Shield Break 30 · Satiety Decay 1.0 · Equilibrium 100.
**2. Combat & Hunting:** Raw Potency 15 · Hardness 10 · Crit Rate 5% · Skeletal Part modifiers (map) · Aggro Weight 1.0.
**3. Elemental & Resonance:** Primary Essence (1 of 18, tag) · Sub-Essence (optional) · Resonance Level ×1.0 · Alignment Shift −100 (Frenzied) … +100 (Pure); purification moves it Pure-ward.
**4. Workstation & Base Utility:** Harvest Aptitude Tier 1 · Logistics Speed ×1.0 · Crafting Velocity ×1.0 · Structural Yield ×1.0.
**5. Progression:** Lineage Track (generation) · Mutation Potential 2% · Devotion Metric (attachment weight → special moves).
**Evolution rule:** form shifts trigger from base interactions + alignment configuration + tracking metrics — never level milestones alone.

## Sheet 6 — World & Survival (all editions)
Day/night cycle 120s (UE slice) — night: spawns ~2× faster, monsters stronger. Sandbox: mining/chopping, wood/stone/coal/gold, block placement, hotbar, quests, heal apples (playable edition). Homeland/Skyisland base: workstations, harvest nodes, storage chests, automated labor by purified entities (registration interface; off-main-thread queueing).

## Implementation map
- BUILD repo: `UEchoEntityDataAsset` (the five matrices), `UEchoDexDataAsset` (Dex identity + canonical attributes), `UEchoCompanionManagerComponent` (party contract), `EchoHeartsStats` equivalents per edition.
- Damage formula note: editions use `max(1, raw − defence) × (crit ? 2 : 1)`; the RPG matrix formula (potency/hardness/essence/shield-break interaction) is a separate design task — not yet defined, not guessed here.
