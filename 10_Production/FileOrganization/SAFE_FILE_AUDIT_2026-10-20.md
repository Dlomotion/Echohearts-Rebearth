# Safe file organization audit — 2026-10-20

Status: INVENTORY / NON-DESTRUCTIVE. No source files moved, renamed, merged or deleted.

## Authority and classification
The existing MASTER_PROJECT_INDEX.md and canonical 00_Canon_Lock–11_Publication and 99_Reference_Retired_Needs_Redesign structure is authoritative. Do not create another master canon or permanent Dex. Protect the 125-ID Permanent Dex; historical naming pool is not an approved promotion list. Do not treat image variants, source assets or historical creature names as disposable duplicates.

## Connected GitHub findings (README-level audit)
- Dlomotion/Echohearts-Rebearth: master canon, story, world, systems, registry.
- Dlomotion/Echohearts-Ecokins: visual archive, approved art references and intake.
- Dlomotion/Echohearts: standalone C++ verification and reusable domain logic.
- Dlomotion/EcoKin-A.i.: AI/NPC navigation and ecology feature workspace.
- Dlomotion/EcoKin-patch: patch/regression/repair workspace.
- Dlomotion/echohearts-web: web presentation and supporting apps.
- Dlomotion/ECHOHEARTS-REBEARTH-BUILD-: expected executable UE5.8 authority, but inaccessible to this connection during audit; cannot claim runtime inventory complete.
- Dlomotion/ECO-KIN-Game: README not readable during audit; no claim of full coverage.

This is NOT a full Git tree/content/dependency audit; repository-specific READMEs were checked, not every object, branch, LFS pointer, or PR.

## Windows local drives
Local C:, D:, E: cannot be browsed through the current chat session. Use tools/ReadOnly-EchoheartsInventory.ps1 on the Windows machine. It inventories metadata and optionally SHA-256 hashes without moving or deleting anything. Reports should be generated OUTSIDE scanned folders and reviewed before any changes. Avoid scanning all system folders unnecessarily; start with known Echohearts project directories and local backup locations. Keep sensitive files and local credentials out of public GitHub.

## Proposed decision register (no actions yet)
1. Exact-byte duplicate: SHA-256 + byte size match. Flag for review, not automatic deletion. Git LFS pointers are not proof of asset equality.
2. Near-duplicate: same name/different hashes. Flag as possible versions; preserve both pending semantic review.
3. Source of truth: canonical docs in master repository; other repositories use links/manifest references and compatible schemas.
4. UE source: retain Unreal module path and UHT reflected type filenames; never mass-move or rename without include/asset redirector/build verification.
5. Blender/Unity/visual assets: preserve editable sources, license provenance, rig/animation dependency chains and asset manifests.
6. Story and Dex: never overwrite approved canon with generated drafts; use intake status and traceable review.
7. Backups: maintain immutable recovery copy and test restore before approving any cleanup.
8. Git: make changes on review branches; inspect diff, tests and links before merge. Never force-push, rewrite history, delete branches or bulk-rename in this audit.

## Review gates before any future move
File owner, source authority, incoming references, import/build scripts, case-sensitive path compatibility, UE asset redirectors, Git LFS tracking, asset licensing, rollback plan, test evidence and explicit approval.
