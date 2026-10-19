# Cross-Platform / Polyglot Architecture Intake Audit — 2026-10-06

**Status:** PROPOSAL INTAKE / TECHNICAL CORRECTION — NOT YET VERIFIED  
**Runtime owner:** `Dlomotion/ECHOHEARTS-REBEARTH-BUILD-`  
**Canon/contracts owner:** `Dlomotion/Echohearts-Rebearth`

This audit routes the submitted platform, JSON, Python, Lua, Slate-editor, world-metric, combat, telemetry, seasonal, evolution/mutation, and benchmark material into the existing Echohearts workflow without promoting flawed snippets or outside identities into production.

## Accepted architecture direction

The following principles are retained:
- one UE5.8 C++ runtime authority;
- platform capability abstraction instead of scattered platform branches;
- static JSON fixtures for offline contract checks;
- Python for repository/build validation;
- Vibrance, Density, Harmony, and Purity as the four canonical project attributes;
- cross-platform save/network/platform claims gated by direct platform evidence;
- a shared ability-data contract may support multiple presentation/execution contexts while the main campaign remains real-time;
- telemetry may cover behavior, balance, performance/crash, engagement, security signals, and simulator outputs subject to privacy and platform policy;
- external titles may be studied only for transferable engineering/design lessons.

## Mandatory corrections before implementation

### 1. Module / include syntax
Submitted C++ snippets concatenate `#include` directives and declarations. Those forms do not compile. Production code must use separate includes, valid Unreal reflection layout, and the active module macro `ECHOHEARTS_API`, not `ECHOHEARTSREBEARTH_API`.

### 2. Platform abstraction
Do not equate operating system, storefront, online-service provider, and hardware family.

A production platform contract should separate at least:
- hardware family;
- distribution channel;
- online/cross-play provider;
- input capability profile;
- save capability profile;
- performance/device profile;
- privilege/entitlement gates.

`Steam_PC` is therefore not a sufficient hardware identity. Xbox/PlayStation SDK macros and APIs must not be guessed in public code. Restricted platform support is implemented only inside authorized SDK environments.

The submitted cross-play masks are repository routing values at most. They are **not certification parameters** and do not prove any platform pair can authenticate, invite, matchmake, reconnect, save, or cross-play.

### 3. Static manifests
The submitted universe validators disagree on whether normalized metrics are bounded by `[0,1]` or `[0,5]`. For offline fixtures, use an explicitly named normalized domain and require exactly:
`Vibrance`, `Density`, `Harmony`, `Purity`.

Do not assume that normalized fixture bounds redefine every production gameplay scale.

### 4. Lua execution
Do not merge the raw Lua bridge as submitted.
- Lua is not currently declared as a BUILD dependency.
- `luaL_openlibs` exposes libraries that are inappropriate for an untrusted/modding sandbox without explicit restriction.
- Submitted Lua scripts call C++ functions that were never registered into Lua.
- Raw arbitrary script execution must not mutate authoritative multiplayer state.
- Thread ownership, instruction/time limits, memory limits, file/network access, deterministic behavior, save/versioning, and platform packaging/licensing must be designed first.

If Lua is later approved, start with a bounded, data-oriented scripting surface and explicit allowlisted bindings.

### 5. In-editor “IDE” tab
Do not ship an arbitrary code-execution console in the editor module from this intake.
- The submitted Slate code is incomplete and uses editor-module assumptions that are not present in the current runtime descriptor.
- Editor utilities must live in an Editor module/plugin with the correct dependencies.
- A safer first tool is a read-only/command-gated validation panel that displays contract/build results rather than executing arbitrary buffers.

### 6. Standalone token converters
The repeated string-to-integer “tracking mask” utilities are rejected from production:
- assignments such as `char PrimitiveByteFootprint = CharacterTokenString;` are invalid C++;
- converting display strings to character codes does not validate memory safety, platform identity, IDE integrity, or build correctness;
- these utilities add noise without a production requirement.

If a stable identifier is needed, use explicit enums, Gameplay Tags, stable string/name IDs, GUIDs, or documented hashes with collision/version rules.

### 7. UniverseCoreEngine duplication
Several submitted versions define overlapping `UUniverseCoreEngine` / universe-metric ownership. Do not create parallel world-state managers. Consolidate any approved ecology state into one bounded subsystem/component architecture with clear server authority, persistence, replication, and World Partition lifecycle.

### 8. Combat contract
The main campaign stays real-time third-person. A shared technique definition may be interpreted by a separate Resonance Arena/tactical context, but this does not convert the whole game to turn-based combat.

Combat data must map back to the four project attributes and the Anima-Link loop rather than introducing a second generic HP/ATK/DEF/SPD stat authority.

### 9. Evolution / mutation intake
Do not import competitor-specific capture, duplicate-sacrifice, forced-genetic-compression, body-part harvesting, possession, or worker-exploitation loops.

Rejected as canon in current form:
- forced “genomic weakening” capture;
- consuming duplicate sentient Eco-Kin for rank;
- harvesting sentient body parts for grafting;
- body possession/consciousness overwrite;
- forced worker-task identity that ignores Eco-Kin autonomy;
- automatic promotion of benchmark species/classes/names.

Potentially reusable only after Echohearts redesign:
- ecology-driven adaptation;
- reversible/conditional mutations;
- branch choices tied to environment, Resonance, Purity, Stress, or Dimensional conditions;
- high-level Sanctuary work preferences and cooperative task protocols;
- ability synergies and environmental interaction;
- original base/logistics UX.

### 10. Seasonal roster intake
Seasonal/Holiday names remain **proposal/event-pool intake** and do not replace or extend the 125-ID Permanent Dex automatically.

Names or forms that directly mirror outside mythological/franchise identities, conflict with existing names, or duplicate one another must be routed through originality/continuity review before public canon. Forms such as Holy/Dark-Void variants are not automatically canon merely because a name was listed.

## Cross-platform evidence layers

### Offline / repository-only
Can prove:
- schema shape;
- unique IDs;
- required fields;
- normalized fixture bounds;
- target-channel naming;
- touch-UI intent;
- static Python syntax;
- module/path naming contracts.

Cannot prove:
- platform SDK compilation;
- storefront integration;
- account/privilege flows;
- cloud save;
- cross-play;
- suspend/resume;
- entitlement behavior;
- certification;
- thermal/battery behavior;
- frame-rate stability;
- packaged runtime.

### Authorized hardware / SDK
Required separately for each exact target:
- compile/cook/package/install/launch;
- input/device mapping;
- save and cloud conflict behavior;
- network identity/invite/matchmaking/reconnect;
- cross-play pair tests;
- performance/memory/thermal/battery;
- suspend/resume/background;
- crash recovery and update/rollback;
- certification requirements.

## Production order impact

This intake does **not** move ahead of the active gates:
1. executable UE5.8 BUILD foundation;
2. Issue #10 body/animation/runtime proof;
3. 4–6 Eco-Kin vertical slice;
4. Growth Rite proof;
5. Heart Fruit + trap/release proof;
6. Event Sovereign save/recovery proof;
7. bounded registry/UI/save;
8. first Oligarch;
9. environmental puzzle/Weather Pulse proof;
10. networking/destruction;
11. platform expansion and later seasonal/war content.

Cross-platform manifest/static validation can be prepared now, but platform runtime claims remain downstream of the first trustworthy Windows UE5.8 build/package/runtime gate.
