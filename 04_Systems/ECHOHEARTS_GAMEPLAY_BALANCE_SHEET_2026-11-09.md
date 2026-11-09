# Echohearts — Combined Gameplay Mechanics Balance Sheet

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

Status: DESIGN SHEET (supplied 2026-11-09). Aggregates the balancing systems of the baseline inspirations as structural references — mechanics are condensed, never copied verbatim. Formulas are implemented in the BUILD repo as `EchoBalance` pure functions (`Source/Echohearts/Public/Gameplay/EchoBalanceFormulas.h`) for use by gameplay code and automation tests. NOT YET VERIFIED in UE 5.8 runtime.

## The matrix

| Balancing system | Core mechanics | Primary inputs | Mathematical intersection |
|---|---|---|---|
| Environmental Sandbox (Terraria-style) | Infinite voxel block modification · Tiered tool progression · Biome-dependent drop constraints | Tool Power % multipliers · Hardness class coordinates · Item placement matrix bounds | **Break formula:** Block HP − Tool Power per swing; drop flag triggers at 0 |
| Purification & Catching (crossover) | Multi-tier spatial trap projections · Scaling capture probability windows · Non-lethal cleansing | Current HP / Max HP ratio · Status ailment/resonance tags · Containment item efficiency tiers | **Capture equation:** Base Rate × Status Tag Scalar × (1 − CurrentHP/MaxHP) |
| Part-Break Hunting | Locational damage mesh tracking · Knockdown/stagger pacing · Severe drop multipliers for elite parts | Skeletal bone part hitboxes · Part health thresholds · Blunt/slashing/elemental weapon profiles | **Stagger rule:** parts hold independent hidden HP pools; reaching 0 triggers knockdown + specialized material |
| Base Automation Loop | NPC pathfinding · Storage auto-sorting · Satiety & Equilibrium fatigue modeling | Labor aptitude tiers 1–4 · Satiety decay constants · Energy/Equilibrium multipliers | **Labor velocity:** Base Output Speed × Work Aptitude × (Current Equilibrium / Max Equilibrium) |

## Data design validation tracker

For every `UEchoEntityDataAsset` configuration:

- [ ] **Scale ranges:** standard entities 50–500 base HP; above 5,000 HP reserved exclusively for tactical elite bosses (weapon pacing).
- [ ] **Element matrix normalized:** every entity has exactly 1 of the 18 essence assignments as primary; no conflicting sub-essence on basic wild entities.
- [ ] **Part-break hitboxes:** breakable skeletal components use a separate Part Health Modifier of 0.1–0.4 × Max HP, so part-break states trigger before the entity is drained or purified.
- [ ] **Worker behaviors isolated:** exactly one worker task per entity profile (Harvesting, Crafting, or Sorting Logistics) — keeps pathfinding arrays light and prevents workstation stalls.
- [ ] Capture windows use the HP-ratio equation above; a full-HP target has a zero purification probability by design.
- [ ] Labor uses the equilibrium-ratio formula; a fully fatigued worker produces zero, never negative, output.

## Related sheets
- Combined stats for all editions: `ECHOHEARTS_COMBINED_STATS_SHEETS_2026-11-09.md` (this folder).
- Architecture: `09_Technical/ECHOHEARTS_UE58_ARCHITECTURE_FRAMEWORK_2026-11-09.md`.
