# Eco-Kin Animation Foundation

Status: **CANON-CORRECT ART/ANIMATION STANDARD — IMPLEMENTATION NOT YET VERIFIED**

This document replaces the old request for “the same animation as Aniimo” with an original Echohearts production standard. External creature games may be studied for broad quality benchmarks only. No proprietary animation clip, rig, timing, landmark, motion library, camera beat, silhouette, or VFX choreography is to be copied.

## Animation goal

Eco-Kin must feel like living creatures with weight, intent, anatomy, temperament, habitat awareness, and individual preference. Animation is part of characterization, not only movement.

The quality target is:

- responsive locomotion without foot sliding;
- readable anticipation, action, impact, recovery, and follow-through;
- believable mass and center-of-gravity changes;
- distinct idle personality;
- convincing terrain contact;
- smooth traversal/combat transitions;
- species-specific reactions to fear, trust, injury, weather, nearby Eco-Kin, and the player;
- strong silhouettes in gameplay camera distance;
- animation readability at real-time third-person combat speed.

## Do not use one identical rig for every Eco-Kin

The historical “one universal master rig for all creatures” idea is rejected. A fox, whale-shark, stag, beetle, serpent, stone construct, and humanoid guardian cannot safely share identical skeletal motion without deformation, foot-contact, silhouette, and personality problems.

Echohearts uses **rig families**. Animation may be shared or retargeted only within compatible anatomy groups.

### Initial rig families

1. **Small Quadruped** — foxes, pups, small feline/canine bodies.
2. **Large Quadruped** — stags, boars, large predators, heavy mammalian guardians.
3. **Heavy Grounded Beast** — tortoise-like, rhinoceros-like, stone-backed, low-center-of-gravity bodies.
4. **Avian / Winged** — birds and wing-dominant fliers.
5. **Serpentine / Elongated** — snakes, eels, long-bodied drakes.
6. **Aquatic** — fish, shark, whale-like, ray-like, fully aquatic forms.
7. **Amphibious** — crocodilian, salamander, frog-like, shoreline/wetland bodies.
8. **Arthropod** — insects, arachnids, crustacean hybrids.
9. **Bipedal Animal / Humanoid-Kin** — upright sentient anatomy that still preserves creature identity.
10. **Flora / Rooted / Amorphous** — plant, fungal, tendril, or non-standard locomotion.
11. **Ancient Tech Construct** — articulated engineered bodies such as E.C.O. Sentinel where joints may float or reconfigure.
12. **Primal / Titan** — encounter-scale rigs with authored locomotion and destruction-contact requirements.

New families are added only when anatomy requires them.

## Shared animation policy

Shared animation is an optimization, not an identity system.

Within a compatible rig family, common clips may include:

- locomotion bases;
- generic hit reactions;
- generic turn-in-place sets;
- simple jump/land cycles;
- baseline sleep/eat/drink loops.

Each named or gameplay-important Eco-Kin still needs original signature motion. At minimum, a production-ready species should have unique personality idles, alert behavior, bond interaction, primary attack language, signature ability motion, wounded behavior, and one ecology-specific behavior.

## Required animation state set

Each Eco-Kin receives only the states its anatomy supports.

### Core living states

- Idle A / Idle B / personality idle
- Look / listen / scent / environmental scan
- Alert
- Curious approach
- Cautious retreat
- Fear / stress
- Refusal
- Bond greeting
- Rest / sleep
- Wake
- Eat / drink where applicable
- Groom / shake / scratch / preen where applicable
- Wounded locomotion
- Recovery

### Traversal states

- Start / stop
- Walk
- Trot or equivalent medium gait
- Run
- Sprint where applicable
- Turn in place left/right
- Pivot / directional change
- Slope adaptation
- Step-up / obstacle response
- Jump / fall / land where applicable
- Swim surface / dive / breach where applicable
- Fly takeoff / cruise / bank / hover / land where applicable
- Climb / cling / burrow where applicable

### Combat states

- Combat ready
- Light attack family
- Heavy attack family
- Defensive action where appropriate
- Dodge / evade where appropriate
- Ability 1
- Ability 2
- Ability 3 where used
- Signature move
- Hit reactions by direction/weight class
- Stagger
- Knockdown
- Recovery from knockdown
- Retreat / regroup

### Restoration and story states

- Calm response
- Kindling acceptance
- Kindling hesitation
- Release farewell
- Treatment / care acceptance
- Blight distress
- Purification recovery
- Growth Rite / Biomimetic Shift / Resonant Morph / Primal Morph transformation where applicable
- Sanctuary aptitude behavior
- Story-specific interaction states

## Personality layer

Animation personality is data-driven. A species profile may define traits such as:

- bold;
- cautious;
- curious;
- territorial;
- social;
- solitary;
- playful;
- stoic;
- protective;
- skittish;
- patient;
- restless.

These traits select idle variants, gaze frequency, approach distance, recovery posture, social spacing, and animation timing. They do not create a second public stat system.

## Essence presentation

Essence does not automatically dictate the creature's whole animation set. It can add secondary presentation where biologically appropriate:

- **Flora:** leaf/tendril response, rooting, growth recoil, pollen or seed motion.
- **Torrent:** fluid body follow-through, water shedding, fin/tail stabilization.
- **Pyre:** heat posture, venting, ember response, thermal expansion.
- **Terra:** grounded weight, bracing, digging, impact settling.
- **Aero:** lift response, feather/fur flow, wind bracing, aerial correction.
- **Glaze:** careful traction, frost shedding, rigid-to-fluid thermal motion.
- **Voltic:** brief muscle twitch, charge buildup, discharge recoil.
- **Aura:** light/pressure reaction, controlled posture, spiritual/guardian presence.
- **Shade:** stealth posture, low-profile movement, darkness adaptation.

These are optional presentation layers, not universal templates.

## UE5.8 implementation direction

Use Unreal Engine 5.8 animation tooling according to anatomy and performance needs:

- **IK Rig / IK Retargeter** for animation sharing between compatible skeletons and proportion variants.
- **Animation Blueprints** for state, gait, personality, additive reactions, and gameplay-tag driven selection.
- **Control Rig / IK** for terrain contact, foot placement, head look, procedural corrections, and authored rig controls where appropriate.
- **Motion Warping** for target-aligned authored moves such as pounces, finish positions, contextual jumps, or large melee contacts.
- **Motion Matching / Pose Search** may be evaluated for high-value locomotion families after profiling proves the memory/content cost is justified.
- Root motion is used for attacks or traversal where authored displacement matters; normal locomotion remains consistent with authoritative movement design.
- Niagara events are triggered from authored animation events/notifies or gameplay ability state, not by hard-coded per-frame particle spam.

Epic's UE5.8 documentation confirms that IK Rig/IK Retargeter can transfer animations between different skeletal meshes while preserving contact goals, Motion Matching selects poses from a database based on runtime motion queries, and Motion Warping adjusts root motion to align authored animation with targets. These are production tools, not permission to reuse another game's assets.

## Animation data contract

Every EcoKin animation profile should eventually resolve:

- `EcoKinID`
- `RigFamilyID`
- `SkeletonID`
- `AnimProfileID`
- supported traversal modes
- locomotion database/set
- personality idle set
- combat montage/set IDs
- signature animation IDs
- hit-reaction class
- mass/scale class
- foot/contact solver profile
- look-at profile
- morph/variant overrides
- required Niagara/audio notify IDs
- network relevance notes
- LOD animation budget
- verification status

## Multiplayer and authority boundary

Animation is presentation. The server remains authoritative over position, movement capability, combat results, cooldowns, damage, bond state, and interaction validity. Clients may predict presentation where appropriate, but animation state must not become a trusted source of gameplay truth.

## Verification gate

This animation foundation is a design standard, **not yet a verified UE implementation**. Promotion requires:

`actual UE5.8 project source/assets → rig-family prototype → retarget tests → animation blueprint tests → foot-contact/terrain QA → network prediction QA → CPU/GPU/memory profiling → LOD validation → visual review on representative Eco-Kin`

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.
