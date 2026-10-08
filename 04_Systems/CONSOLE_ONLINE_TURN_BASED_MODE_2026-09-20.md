# Console Online Turn-Based Battle Mode

**Status:** APPROVED-PENDING GAMEPLAY / NETWORK DESIGN  
**Implementation:** NOT YET VERIFIED  
**Runtime target:** Unreal Engine 5.8 production path  
**Project:** Echohearts: Rebearth / Into Deep Studios

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

## Canon Decision

Echohearts keeps its existing split between campaign combat and tactical online combat:

- **Main campaign / exploration:** third-person real-time action with the player active beside Eco-Kin.
- **Online server tactical battles:** when a console player enters an approved online battle instance, the combat layer switches to **server-authoritative turn-based or timeline-based Eco-Kin combat**.
- **Online social/exploration spaces:** remain real-time unless a later mode explicitly defines otherwise.

The turn-based layer is a gameplay mode inside the same Echohearts game, not a second game and not a second engine.

## Engine / Naming Correction

Historical Unity, `Chil-Kin`, `MonoBehaviour`, Mecanim, Unity UI and related C# campaign architecture are **not** restored as production runtime.

Useful design intent from those prototypes may be migrated into the current Unreal Engine 5.8 stack.

Canonical creature terminology remains **Eco-Kin** unless a separate future canon decision explicitly introduces another category.

## Player Experience

### Entering Online Tactical Play

A console player may enter online tactical play through an approved in-world or menu-facing entry point such as:
- Resonance Arena;
- Harmony Circuit;
- EchoDeck competition;
- tournament event;
- ranked/unranked matchmaking;
- private friend match;
- approved co-op tactical encounter.

Flow:

**Real-time hub/exploration → matchmaking/session handshake → battle instance load → turn-based battle UI/control profile → results/rewards → return to real-time hub/world.**

The transition should feel intentional and readable. Players should never lose control because the game silently changes modes.

## Online Battle Rule

Once the match begins:
- the server owns the authoritative battle state;
- players submit legal commands rather than directly mutating combat state;
- the server validates turn ownership, targets, resources, cooldowns/statuses and timing;
- the server resolves actions in deterministic authored order;
- all clients receive the same confirmed result events;
- the next decision window opens only after the previous result is committed.

No client may decide damage, turn order, victory state or reward outcome by itself.

## Turn Structure

Initial design target:

1. **Turn Start**
   - server publishes active side/unit and legal-action context;
2. **Command Window**
   - player selects Move / Ability / Partner Action / Item-equivalent if allowed / Tactical option;
3. **Target Selection**
   - UI shows only legal targets;
4. **Command Lock**
   - player confirms;
5. **Server Validation**
   - illegal/late commands are rejected cleanly;
6. **Resolution**
   - animation/VFX/camera sequence plays from authoritative result data;
7. **Status Resolution**
   - damage-over-time, shields, field effects, recovery and authored triggers resolve;
8. **Turn Advance**
   - next unit/side becomes active;
9. **Victory / Draw / Disconnect Rule**
   - server finalizes match state and rewards.

Exact initiative model—alternating sides, speed/timeline initiative, simultaneous planning or hybrid—is still tunable and must be playtested before canon lock.

## Eco-Kin Team Rules

The tactical mode must reuse the authoritative Eco-Kin identity, progression, relationship and approved stat data from the main game.

Do not create separate online-only creature copies or a second independent stat ownership system.

Arena-specific derived values may exist only when they are deterministic, documented and derived from authoritative data.

Turn-based balance may normalize selected values for competitive fairness without deleting campaign progression.

## Console Control Scheme

The online tactical interface must be controller-first.

Recommended interaction pattern:
- **Left Stick / D-pad:** navigate command list and targets;
- **A / Cross:** confirm;
- **B / Circle:** back/cancel before command lock;
- **X / Square:** inspect Eco-Kin / battlefield details;
- **Y / Triangle:** tactical overview or contextual information;
- **LB/RB or L1/R1:** cycle Eco-Kin/targets/tabs;
- **LT/RT or L2/R2:** quick category switching where useful;
- **Menu/Options:** settings only when allowed by match state.

Final platform glyphs must use platform-approved iconography and input abstraction rather than hard-coded text.

## Battle UI

Console tactical UI should clearly show:
- active turn/initiative;
- current Eco-Kin;
- health/status/resource state;
- legal commands;
- target preview;
- elemental/resonance information where relevant;
- ally/opponent field state;
- turn timer when enabled;
- network/reconnect state;
- command confirmation state.

Avoid dense PC-style panels that become unreadable on television viewing distance.

## Match Types

Approved-pending categories:

### Unranked
Casual online tactical play with standard rules.

### Ranked
Skill-rated play with stricter disconnect, anti-exploit and version-compatibility rules.

### Private Match
Invite/friend code/lobby based play for testing or social competition.

### Event / Tournament
Authored rulesets, seasonal restrictions or narrative competitions without creating a separate game architecture.

### Co-op Tactical Encounter
Multiple players can coordinate against server-controlled enemies where an authored mode supports it.

## Real-Time to Turn-Based Transition

The mode switch occurs at a clean encounter boundary.

Do **not** freeze a live real-time combat encounter midway and reinterpret it as turn-based without authored transition rules.

Preferred transitions:
- enter Arena gate/terminal;
- accept challenge;
- join matchmaking queue;
- load dedicated battle space;
- synchronize teams;
- begin turn-based match.

Return to real-time play only after battle finalization and state synchronization are complete.

## Online Server Architecture Direction

Design target:
- authoritative dedicated or hosted server process;
- authenticated session ownership;
- validated player commands;
- replicated confirmed state/results;
- sequence IDs for commands/results;
- idempotent result handling;
- reconnect snapshot support;
- explicit match version/ruleset ID;
- server-owned timeout/forfeit policy;
- telemetry for desync, rejection and latency analysis.

Implementation must align with the existing Echohearts shared result-event envelope and current networking architecture once those dependencies are verified.

## Latency Design

Turn-based play should make network latency less disruptive than real-time PvP, but latency still matters for:
- matchmaking handshakes;
- command acknowledgment;
- turn timers;
- reconnect;
- spectator synchronization;
- post-match result confirmation.

Rules:
- show a visible "command received" state when useful;
- never make a player guess whether a command was accepted;
- server timestamps govern deadline validity;
- allow a reasonable grace policy for transient delay where competitive integrity permits;
- do not hide connection failure behind endless loading.

## Disconnect / Reconnect

If a player disconnects:
1. server preserves match state for a defined reconnect window;
2. reconnecting client receives an authoritative snapshot;
3. duplicate commands are rejected safely;
4. if the player fails to return, the ruleset applies timeout/forfeit/AI-handoff only if that mode explicitly supports it;
5. ranked reward/rating handling remains server-owned.

No final reconnect duration is locked until testing.

## Anti-Cheat / Integrity

Because tactical combat is server-authoritative:
- clients cannot author damage values;
- clients cannot change turn order;
- clients cannot spawn legal actions not exposed by the server;
- reward grants require server-confirmed match completion;
- ruleset/version mismatch blocks ranked entry;
- suspicious command rates or impossible sequences should be logged.

This does not replace platform security, account security or backend anti-abuse design.

## Cross-Progression

Campaign and online tactical play share the same Eco-Kin identities and player progression source of truth.

Competitive rules may apply normalization/caps to preserve fairness.

Online mode must not require players to obtain a duplicate "Arena version" of an Eco-Kin already recognized by the main game.

## Manuscript / War Mission Integration

The manuscript system may connect to online tactical play without forcing lore collection for competitive power.

Examples:
- War on Life manuscripts unlock historical Arena exhibition missions;
- Eco-Kin manuscripts reveal optional tactical tutorials or historical match scenarios;
- recovered records can unlock cosmetic banners, archive displays or narrative challenge variants;
- manuscript completion must not grant pay-to-win or mandatory ranked-stat advantages.

This keeps narrative discovery relevant to console online play while protecting competitive integrity.

## Accessibility

Online turn-based mode should support:
- scalable text/UI;
- high-contrast targeting indicators;
- redundant color + shape/icon status communication;
- configurable turn-timer accommodations in supported non-ranked/private modes;
- readable combat log/history;
- reduced camera motion option;
- remappable controls where platform policy permits;
- screen-reader-friendly menu architecture target where technically supported;
- clear connection/reconnect messaging.

## Vertical-Slice / Prototype Scope

The first proof should be deliberately small:
- one console/PC controller-ready tactical arena;
- two players or one player versus server-controlled opponent;
- small Eco-Kin team size;
- four basic command categories;
- authoritative turn state;
- one status effect;
- one elemental/resonance interaction;
- win/loss result;
- disconnect/reconnect simulation;
- return to real-time hub after match.

Do not build ranked ladders, tournament seasons, spectators, monetization or large-scale backend before the basic authoritative match is proven.

## Production Routing

- tactical rules / balance → `04_Systems`
- arena spaces → `05_Levels`
- controller UI / turn HUD → `06_UI_UX`
- battle presentation → `07_Art`
- tactical cues / announcer / feedback → `08_Audio`
- Unreal networking and gameplay implementation → `09_Technical`
- build/test/network evidence → `10_Production`

## Verification Gate

Nothing in this document claims that online turn-based combat currently exists.

Before status can change to VERIFIED, evidence must include at minimum:
- packaged build launch;
- online session establishment;
- authoritative command validation;
- deterministic/consistent result replication;
- controller navigation on target console-class input;
- disconnect/reconnect behavior;
- match completion and return transition;
- latency testing;
- accessibility pass;
- no duplicated progression/stat authority.

**Final status:** CONSOLE ONLINE SERVER TURN-BASED BATTLE MODE IS APPROVED-PENDING AS AN IN-GAME ECHOHEARTS MODE. REAL-TIME CAMPAIGN REMAINS INTACT. UNITY/CHIL-KIN PRODUCTION DRIFT REMAINS RETIRED; USEFUL TURN-BASED DESIGN INTENT IS MIGRATED INTO THE UNREAL/ECO-KIN ARCHITECTURE. IMPLEMENTATION NOT YET VERIFIED.
