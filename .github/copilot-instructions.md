# Echohearts: Rebearth — GitHub Copilot Repository Instructions

Last updated: 2026-10-09  
Repository: `Dlomotion/Echohearts-Rebearth`  
Role: `CANON_CONTRACTS_PUBLIC_COORDINATION`

## Authority and routing

This repository is the source of truth for Echohearts: Rebearth canon, story, world, systems contracts, the 125-ID Permanent Eco-Kin Dex, production records, publication, and cross-repository coordination.

The executable Unreal Engine 5.8 runtime/build/evidence authority is:
`Dlomotion/ECHOHEARTS-REBEARTH-BUILD-`

Related repositories:
- `Dlomotion/echohearts-web` — web/presentation/supporting app surface.
- `Dlomotion/Echohearts-Ecokins` — Eco-Kin visual/archive/support content.
- `Dlomotion/ECO-KIN-Game` — legacy/prototype support only.
- `Dlomotion/ECHOHEARTS-REBEARTH-` — legacy Rebearth support only.
- `Dlomotion/Echohearts` — engine-independent C++/verification support.
- `Dlomotion/ECHOHEARTS-REBEARTH-BUILD-` — active UE5.8 executable implementation.

Do not create a second canon, second Permanent Dex, parallel GDD, competing Unreal runtime module, duplicate save authority, or duplicate implementation track. Reconcile incoming work into the existing authority split.

## Copilot execution behavior

When the user asks to create, implement, repair, expand, connect, or perfect something, do real repository work when the repository and permissions allow it. Do not stop at generic advice or disconnected snippets.

Before editing:
1. inspect README, MASTER_PROJECT_INDEX, canon locks, relevant registries, existing source, call sites, tests, workflows, branches, open PRs, and build/config files;
2. identify which repository owns the requested artifact;
3. identify conflicts with current canon or runtime contracts;
4. preserve existing approved work instead of replacing it with a parallel system;
5. use a focused branch/PR for non-trivial changes.

For code repair:
- read the exact diagnostic, failing command, working directory, toolchain, stdout/stderr, and nearby code;
- fix the root cause in the language/layer that owns it;
- keep declarations/definitions, interfaces, tests, schemas, and build rules synchronized;
- run the smallest available validation gate;
- never hide a failure, fake an API, fabricate a passing test, or convert a static check into a runtime claim.

## Canon locks

- Target planet: **Rebearth**.
- Creature classification: **Eco-Kin**.
- Player class: **Frequency Tamer / Core-Binder**.
- Apex entity **Nature** is a Legendary Humanoid-Kin using conditional Mutations; never call Nature a Legendary Monarch.
- Core public attributes are **Vibrance, Density, Harmony, Purity**. Do not replace them with generic RPG root stats.
- The **Anima-Link** is a bi-directional tactical pulse loop where combat strain and Eco-Kin damage can impose player stamina/health costs according to authored rules.
- A.E.G.I.S. is the physical bracer/interface for survival, scanning, bonding, and combat.
- The 125-ID Permanent Eco-Kin Dex is authoritative. Historical names, seasonal additions, forms, mutations, alternate spellings, and prototypes do not silently become DEX-126+.
- Preserve Eco-Kin agency. Bonding/Kindling is trust/consent driven and must not be rewritten as ownership or forced capture.
- Avoid derivative franchise names, copied characters, copied plots, unlicensed assets, and direct mythology imports unless explicitly requested for a clearly separated benchmark.

## Source-of-truth folder routing

Use the existing workflow:
`00_Canon_Lock`, `01_Story`, `02_World`, `03_EcoKin_Dex`, `04_Systems`, `05_Levels`, `06_UI_UX`, `07_Art`, `08_Audio`, `09_Technical`, `10_Production`, `11_Publication`, `99_Reference_Retired_Needs_Redesign`.

Route work through:
INTAKE -> AI MISTAKE PATCH -> CONTINUITY CHECK -> ORIGINALITY/IP CHECK -> CORRECT FOLDER -> STATUS -> GAME/STORY LINK -> IMPLEMENTATION EVIDENCE.

## Unreal Engine 5.8 implementation rules

Runtime implementation belongs in `Dlomotion/ECHOHEARTS-REBEARTH-BUILD-`.

- Runtime module: `Echohearts`.
- Export macro: `ECHOHEARTS_API`.
- Use clean UE5-compatible object-oriented C++ and Unreal-native systems.
- Keep `.generated.h` last among normal header includes.
- Use valid UCLASS/USTRUCT/UENUM/UINTERFACE/UPROPERTY/UFUNCTION declarations.
- Use server-authoritative state for authoritative multiplayer systems.
- Treat client input as intent, not truth.
- Prefer data-driven Primary Data Assets/Data Tables/Data Registry/Gameplay Tags where appropriate.
- Do not invent engine APIs, platform SDK behavior, RPC semantics, asset paths, maps, sockets, animation notifies, or certification status.

Current front-end/title-screen implementation candidate: BUILD PR #37. Extend or repair that implementation rather than creating a second front-end stack unless a deliberate migration is approved.

## Visual and UI requests

When the user supplies promotional/reference imagery and asks to create it in-game:
- use the image as composition/art-direction input;
- implement an original Echohearts UI using approved project art and nomenclature;
- preserve accessibility, controller/keyboard/touch navigation, scalable layouts, localization readiness, and aspect-ratio safety;
- do not copy third-party logos, characters, branded storefront badges, or protected assets into the game;
- do not claim a storefront release until that release exists and has evidence.

## COBOL and BASIC directive

COBOL and BASIC are approved **secondary engineering/tooling languages** when the user explicitly asks for them or when an owned legacy/offline utility benefits from them.

Approved uses include:
- deterministic offline data conversion;
- report generation;
- manifest/Dex/schema validation;
- migration utilities;
- build/test fixtures;
- regression harnesses;
- educational/toolchain demonstrations that do not become gameplay authority.

Preferred open tooling when available:
- GnuCOBOL for `.cob` / `.cbl`;
- FreeBASIC for `.bas`.

Rules:
- do not replace UE5.8 C++ gameplay, Unreal reflection, replication, save authority, or platform integration with COBOL/BASIC;
- do not replace JavaScript/TypeScript web ownership with COBOL/BASIC;
- keep COBOL/BASIC utilities isolated under a repository-appropriate tooling/prototype path;
- provide deterministic inputs/outputs and tests where practical;
- if the compiler/runtime is unavailable, mark the result static/unverified rather than claiming execution;
- use COBOL/BASIC because the requested tool benefits from them, not as a workaround for an unrelated C++/web error.

Canonical language-selection contract:
`09_Technical/LANGUAGE_DIAGNOSTIC_AND_TOOL_SELECTION_STANDARD_2026-10-06.md`

## Verification language

Use evidence-gated status:
- `STATIC CHECK PASSED`
- `REPOSITORY CONTRACT PASSED`
- `CI PREFLIGHT PASSED`
- `NOT VERIFIED — UE BUILD/RUNTIME EVIDENCE REQUIRED`

Never claim compiled, production-ready, fixed, secure, optimized, packaged, platform-certified, or VERIFIED without the corresponding real evidence.

## Final Copilot rule

Create what is requested when it fits the architecture; fix broken code instead of hiding it; preserve canon and repository ownership; keep changes reviewable and reversible; and leave a clear evidence trail showing what was actually checked.
