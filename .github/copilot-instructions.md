# Echohearts: Rebearth — GitHub Copilot Instructions
Updated: 2026-10-09
Repository role: CANONICAL_DESIGN_AND_SYSTEM_CONTRACTS

## Authority and scope
This repository owns the canonical story, systems, contracts, and production governance. Preserve the existing MASTER_PROJECT_INDEX.md, Echohearts: Resonance Arena | Master Game Bible, ECO_KIN_ART_MANIFEST.md, Echohearts_Game_Data_Dictionary_v0.5.xlsx, and folders 00_Canon_Lock through 11_Publication plus 99_Reference_Retired_Needs_Redesign. Do not invent a second Master Bible, Dex, or production workflow. Check the actual files before changing canon. Do not claim unavailable files have been reviewed.

## Related repositories and boundaries
- Dlomotion/Echohearts-Rebearth — canonical design and system contracts (this repository).
- Dlomotion/ECHOHEARTS-REBEARTH-BUILD- — executable Unreal runtime authority; verify actual .uproject and engine version before editing.
- Dlomotion/echohearts-web — web presentation.
- Dlomotion/Echohearts-Ecokins — Eco-Kin support.
- Dlomotion/ECO-KIN-Game — legacy game support.
- Dlomotion/ECHOHEARTS-REBEARTH- — legacy Rebearth support.
- Dlomotion/Echohearts — legacy core support.
Changes across repositories require separate scoped branches/PRs and contract compatibility checks; do not copy one repository's entire source tree into another.

## Locked game architecture
Planet: Rebearth. Hub: Echohearts Sanctuary. Player: Frequency Tamer / Echoheart / Core-Binder. Device: A.E.G.I.S. Eco-Kin is the creature classification. Nature is a Legendary Humanoid-Kin with conditional Mutations, not standard evolution. The four attribute identifiers are Vibrance, Density, Harmony, and Purity; never substitute generic RPG stats. Anima-Link is a bidirectional pulse loop: Eco-Kin damage and combat strain impose tactical player health/stamina consequences. Maintain the existing 125-ID Permanent Eco-Kin Dex separately from the 1,120-name historical naming pool; do not promote archived names without approval. Preserve approved anime-toon visual identity, anatomy, silhouettes, and naming.

## Implementation languages
- Unreal Engine 5 C++ is authoritative for runtime modules, UObject/Actor systems, UHT-visible APIs, networking, and gameplay.
- Unreal Blueprints integrate with reviewed C++ contracts.
- COBOL may be used for isolated offline roster reconciliation, fixed-format exports, and auditable reports, with documented dialect/compiler, test fixtures, and UTF-8/data interchange contract. Never introduce COBOL as a direct Unreal module dependency.
- BASIC may be used for isolated utilities and prototypes after choosing a specific dialect (for example FreeBASIC or QB64-PE) and defining a repeatable build/test command. Never assume BASIC executes in Unreal directly.
- Python/PowerShell may support validation and CI where justified. Prefer one maintained implementation over redundant multi-language rewrites.

## Git, LFS and build safety
Use short-lived feature/fix branches and PRs; do not routinely commit directly to main. Inspect diff and tests before scoped commits. Do not force-push, delete branches, merge, or change protection without explicit authorization. Preserve useful project Build/ resources when present. Track Unreal .uasset and .umap with Git LFS; evaluate other binary extensions by size and workflow. LFS is not a binary merge strategy: coordinate locking/asset ownership. Never run untrusted public PR code on a persistent self-hosted runner. Use least-privilege CI permissions. Verify .uproject, actual engine install/version, Build.cs/Target.cs, UBT/UHT compile, cook/package, Git LFS round-trip, rollback, and runtime evidence before marking anything VERIFIED.

## AI code repair procedure
1. Inspect repository state, affected code, dependencies, and logs; reproduce the reported failure where possible.
2. Identify smallest root-cause patch; preserve contracts and avoid speculative classes.
3. For C++ validate Unreal reflection, ownership/GC, RPC authority, replication, save compatibility, threading, and performance.
4. Add meaningful tests and run available checks; distinguish not-run from pass.
5. Report precise file changes, commands, errors, test evidence, risks, and rollback instructions.
6. Search official Epic/Unreal guidance and licensed sources when necessary; record provenance. Never paste unlicensed third-party code.
7. Do not claim CI, compilation, packaging, editor testing, or runtime validation without actual logs/artifacts.

## Production requests
Work inside the existing unified Echohearts Daily Game Work pipeline. New mechanics, cinematic plans, art workflows, and cross-repository updates must reconcile with canon and ownership boundaries. Report PROPOSED, IMPLEMENTED, COMPILED, TESTED, and VERIFIED as distinct evidence gates.
