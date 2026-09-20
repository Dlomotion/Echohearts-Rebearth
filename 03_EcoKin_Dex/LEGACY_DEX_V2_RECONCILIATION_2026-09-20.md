# Legacy Eco-Kin Dex V2 — Canon Reconciliation

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

Status: REFERENCE-ONLY SOURCE / ACTIVE RECONCILIATION
Verification: NOT YET VERIFIED in UE5.8 runtime.

## Purpose
Preserve useful structure from the historical Eco-Kin Dex V1/V2 work without allowing superseded stats, attribute families, stage labels, storage/trading systems or roster counts to overwrite current Echohearts canon.

## Keep from the historical Dex
The historical work contains useful production fields that should survive as internal design/data concepts where canon-compatible:
- permanent identity fields, EcoKinID/Echoprint identity and species DNA/body-plan records;
- name, class, ecology, biome, habitat affinity, personality and behavior;
- Bond theme, personality skill and partner-assist behavior;
- combat role, traversal role and fighting style;
- four active skill candidates plus signature/ultimate concept;
- resistance/weakness design as internal combat data;
- Growth Rite/evolution/adaptation requirements;
- Sanctuary Aptitude and Reclamation Function;
- model, animation, VFX, audio and AI references;
- story/world connection and save-state requirements.

## Canon corrections
### Public stats
Historical HP/MP/SP/ATK/DEF/ESA/ESD/INT/SPD/ACC/CRI/RES packages are not the public identity system. Public Echohearts stats remain:
- Vibrance
- Density
- Harmony
- Purity

Additional combat numbers may exist internally only after the current combat architecture defines them. They must not become a copied monster-tamer stat presentation by default.

### Elements
The locked core elements are:
Solar, Lunar, Hydro, Magma, Aero, Flora, Volt, Terra, Iron/Tech, Spirit, Chaos, Radiant.

Historical Nature, Light, Shadow, Star, Sound, Psychic, Frost, Toxic, Beast, Crystal and similar labels must be mapped to current elements, creature class, status language, ability tags or visual descriptors instead of becoming extra core elements.

### Historical attribute families
Veridian, Cipher and Hollow may remain only where current Resonance Arena or historical classification work explicitly uses them. They do not replace the locked 12-element system. Primal, Celestine, Abyssal, Forge and Mythic Rare are not automatic core attributes; route them into class, rarity, ecology, role or presentation as appropriate.

### Stages
Historical Chil-Kin / Rookie / Crest / Champion / Apex / Legendary / Mega Ultimate / Deviant labels are SOURCE/PROPOSAL. Current evolution must use the established Growth Rite / form / mastery architecture and the user's locked progression rules. Do not force a universal stage ladder onto every species.

### Bond
Bond is trust, relationship memory and coordination. Remove obedience/ownership framing. A low-Bond Eco-Kin may be fearful, uncertain, distant or unwilling, but it is not a disobedient possession.

### Sanctuary
Historical `worker` language is retired. Use voluntary Sanctuary Aptitudes and Partner Assist. Overwork is a welfare failure state, never an optimization strategy.

### Storage / trading
Eco-Kin are not stored as inventory boxes and are not trade commodities. A.E.G.I.S./Havenlink records location, care, bond and availability; Sanctuary/Haven spaces physically host residents. Players may trade approved materials, gear, food, cosmetics and EchoDeck cards, not sentient Eco-Kin.

### Breeding / mutation
No forced breeding, selective stat optimization, forced mutation or sentient trait extraction. Valid development uses ethical Growth Rites, environmental adaptation, Shard-Arc Adaptation, Primal Reversion and other approved identity-preserving systems.

### Corruption
Blight/Chaos pressure can cause distress, scars and dangerous states, but corrupted forms are not a power-farming mechanic. Restoration is the preferred path where possible. Never describe cleansing vs `weaponizing` a sentient partner as equivalent choices.

## Roster count correction
The historical `185-entry` figure is a source inventory estimate, not the permanent canon Dex count. Every named entry must pass:
1. duplicate and alias audit;
2. outside-IP/name audit;
3. body-plan/anatomy audit;
4. element mapping;
5. ecology and region placement;
6. story role check;
7. current-stat translation;
8. art provenance/quality check;
9. final status: CANON / APPROVED-PENDING / MERGED-RENAMED / RETIRED-REFERENCE-ONLY / REJECTED.

## Known name/collision risks in the historical roster
Generic real-animal names, celebrity-adjacent names, direct dinosaur/common-species names, mythology-derived identities and names that strongly echo outside entertainment IP require review before publication. Existing locked names and completed art always take precedence over newly inferred aliases.

## Data architecture direction
Do not implement the entire historical spreadsheet schema as C++ now. Preserve a data-driven target for UE5.8 using Primary Data Assets/Data Tables plus Gameplay Tags where needed. The current technical gates still come first.

Minimum current Eco-Kin data record should prioritize:
- stable identity;
- class/body plan;
- locked element(s);
- V/D/H/P profile;
- personality and Bond theme;
- ecology/biome;
- role and behavior;
- abilities;
- Growth Rite/forms;
- Sanctuary Aptitudes;
- Reclamation Function;
- story/world links;
- art/audio/animation references;
- save/network identifiers;
- canon and verification status.

Final status: LEGACY DEX V2 PRESERVED AS SOURCE / PARTIALLY REUSABLE / NOT A SECOND DEX.