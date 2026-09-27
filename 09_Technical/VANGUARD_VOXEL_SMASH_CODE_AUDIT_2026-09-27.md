# ECHOHEARTS: REBEARTH — VANGUARD VOXEL-SMASH CODE AUDIT

**Date:** 2026-09-27  
**Status:** REFERENCE / NEEDS REWRITE — NOT YET VERIFIED  
**Engine target:** Unreal Engine 5.8  
**Scope:** pasted `AERBehemothGoliath` / voxel-smash concept and its connection to the existing technical roadmap.

## 1. Disposition

The pasted `ERBehemothGoliath.h/.cpp` is a useful ability prototype description, but it is **not production-ready C++** and does not prove a working UE5.8 ability, voxel system, replication path, navigation update, hit reaction, or packaged build.

The valid design intention is retained:

- a colossal Behemoth-Goliath slam;
- authored terrain deformation;
- radial knockback/stagger;
- Niagara impact presentation;
- exact attack timing tied to animation;
- server-authoritative gameplay state;
- bounded destruction compatible with world/save/network rules.

## 2. Concrete problems in the pasted sample

1. `EnemyCreature->SetCharacterMovementVelocity(0.0f)` is not a valid standard `ACharacter`/`UCharacterMovementComponent` API call.
2. No replicated/server-authoritative execution contract exists; any client-accessible direct world modification would be unsafe for multiplayer.
3. The `AEchoheartsWorldVoxelManager` call is commented placeholder code and therefore proves no terrain deformation implementation.
4. No verified voxel plugin/API is present in the repository and no compile evidence establishes those symbols.
5. The slam fires immediately from a callable function instead of being bound to an authored animation notify / montage impact frame.
6. No cooldown, resource cost, state gate, interruption rule, dead/stunned gate, or re-entry protection is specified.
7. `OverlapMultiByObjectType(... ECC_Pawn ...)` is too broad by itself: team/faction, friendly-fire, dead/invalid actor and damageability filters are required.
8. Root-component physics impulse affects only actors whose root component is simulating physics. Character movement generally needs an explicit launch/knockback path.
9. No damage calculation or authoritative stagger duration is actually applied.
10. No destruction budget, no-destroy volume, navmesh invalidation policy, save transaction, rollback contract or replication payload exists.
11. Niagara spawning is presentation only; it does not prove damage or geometry changes.
12. The sample directly stores a display species string. Runtime identity must bind to stable registry identity/data, not rely only on free-text creature names.
13. No exact hit-location feedback, directional hit reaction, attack-notify evidence or terrain-contact proof is present; these remain part of Issue #10's vertical-slice evidence requirements.

## 3. Correct implementation contract

### Authority

- Gameplay execution begins on the server/authority path.
- Client input requests the ability but cannot authoritatively choose hit victims, destroyed cells, rewards or persistent world deltas.
- The authority validates ability state, cooldown/cost and current encounter phase.

### Animation timing

- Start attack animation/montage.
- Use an authored impact notify (`Vanguard.Smash.Impact` or equivalent project naming) at the exact contact frame.
- Only the authoritative impact event applies gameplay effects.
- Presentation can be predicted locally only if later networking evidence supports it.

### Entity impact

At impact:

1. perform a bounded overlap or shape trace;
2. filter self, allies, invalid/dead actors and non-damageable targets;
3. compute direction from impact center;
4. apply project-standard damage;
5. apply character launch/knockback through the proper movement path for Characters;
6. apply physics impulse only to physics-simulating primitives;
7. apply authored stagger through the project status/effect system;
8. emit hit-location/direction metadata for reaction animation and feedback.

### Terrain deformation

Terrain deformation must be treated as a separate subsystem request, not raw actor destruction.

Required request fields:

- deformation origin;
- radius/shape;
- energy/strength;
- source ability ID;
- instigator/encounter ID;
- material hardness response;
- no-destroy masks;
- maximum affected cells/triangles/chunks;
- restoration/save policy;
- replicated delta/event identity.

The world system may reject, clamp or convert the request to a cosmetic-only fracture if the area is protected or over budget.

### Navigation

After an accepted persistent collision change:

- enqueue local navigation update rather than forcing unrestricted synchronous global rebuild;
- preserve critical mission paths;
- use authored fallback traversal if the new topology would trap required actors;
- measure nav update cost in profiling before increasing destruction scale.

### VFX/audio pooling

Niagara/audio pooling is optional optimization work, not a requirement to claim the ability works. Use pooling only after profiling demonstrates an allocation/lifecycle problem.

## 4. Suggested data-driven definition

The ability should ultimately resolve from stable content data, for example:

- `AbilityID = Vanguard.BehemothGoliath.VoxelPulverizer`
- parent encounter identity / registry key;
- Essence/resonance tags (working candidate: Flora + Terra/Geo interaction);
- base radius;
- knockback curve;
- stagger tag/duration;
- damage profile;
- deformation profile;
- cooldown/cost;
- animation montage / impact notify name;
- Niagara/audio presentation references;
- PvE/PvP normalization policy.

Exact class names remain implementation choices after the canonical `.uproject` and module tree exist.

## 5. Corrupted-raid reward authority

Reward generation must be server/save-authoritative when shared/online persistence exists.

For each raid completion:

1. validate boss/echo state reached its legitimate cleansed terminal state;
2. generate one completion transaction ID;
3. resolve eligible reward table;
4. commit reward to persistent inventory once;
5. record the Chrono/archive purification state;
6. reject duplicate/replayed completion requests;
7. resume safely after disconnect/travel from the last committed state.

Chrono rewind may never rewind the reward ledger.

## 6. Required evidence before VERIFIED

The Vanguard smash/raid implementation remains **NOT YET VERIFIED** until repository evidence includes, at minimum:

- canonical UE5.8 `.uproject` and Source module;
- UHT + compile success;
- editor launch;
- one authored Behemoth-Goliath or proxy rig/body;
- locomotion and terrain contact;
- montage/notify impact timing;
- exact hit-location/directional hit-reaction evidence;
- authoritative damage/knockback/stagger behavior;
- bounded deformation behavior or an explicitly scoped non-voxel substitute;
- nav/pathing recovery after deformation;
- save/reload proof for accepted persistent world deltas;
- multiplayer authority proof if networked;
- Development packaged build evidence;
- performance capture for the tested encounter.

Until those artifacts exist, the design and code remain specification/reference work only.
