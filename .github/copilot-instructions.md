# Echohearts: Rebearth — GitHub Copilot Instructions

## Authority and scope
Work inside the existing Echohearts development workflow. Do not create a second Master Bible, duplicate Dex, parallel canon, or replacement project. The authoritative references, when present, are MASTER_PROJECT_INDEX.md, Echohearts: Resonance Arena | Master Game Bible, ECO_KIN_ART_MANIFEST.md, Echohearts_Game_Data_Dictionary_v0.5.xlsx, and the established 00_Canon_Lock through 11_Publication folders plus 99_Reference_Retired_Needs_Redesign. If unavailable, ask for them; never invent their contents. Preserve the 125-ID Permanent Eco-Kin Dex separately from the 1,120-name historical naming archive. Historical names are not automatically production canon.

## Game identity
Planet: Rebearth. Central restored hub: Echohearts Sanctuary. Creature classification: Eco-Kin. Player identity: Frequency Tamer / Echoheart / Core-Binder. A.E.G.I.S. is the physical survival, scan, bond and combat bracer. Nature is a Legendary Humanoid-Kin with conditional Mutations, not ordinary evolution. Preserve approved Anime-toon art and user-supplied designs. Avoid unrelated franchise references and generic RPG terminology.

## Implementation
- Unreal Engine C++/Blueprint architecture is the gameplay source of truth. Follow the project's actual engine version and .uproject; target UE5.8 only where supported by installed tools and project metadata.
- All gameplay attribute logic must use Vibrance, Density, Harmony, and Purity; do not introduce generic Strength, Mana or Agility fields.
- Implement the bi-directional Anima-Link pulse: Eco-Kin combat strain/damage propagates defined tactical costs to the Core-Binder, with explicit bounds and tests.
- Favor clean, modular, object-oriented UE C++; validate UHT reflection macros, includes, Build.cs module dependencies, replication and save/profile boundaries. Secure cloud sync: no secrets in source, least privilege, platform-neutral interfaces.
- COBOL and BASIC are optional *external tooling* languages only, for isolated data conversion/reporting with documented inputs/outputs and tests. Do not put COBOL or BASIC into UE runtime modules or claim Unreal compiles them natively.
- VS Code settings/tasks and GitHub Actions must reflect actual checked-in paths; do not hardcode user-specific absolute paths. User's intended local project root is C:\Users\Owens\OneDrive\Documents\Unreal Projects\Echohearts\, but cloud GitHub cannot access that folder automatically.
- Use Git LFS for approved large binary assets, preserving original art. Do not silently move, regenerate, rename or overwrite approved assets.

## Repository boundaries
Dlomotion/Echohearts-Rebearth is the primary Unreal/canon integration repository. Coordinate, without blindly copying files or duplicating authority, with Dlomotion/echohearts-web, Dlomotion/Echohearts-Ecokins, Dlomotion/ECO-KIN-Game, Dlomotion/ECHOHEARTS-REBEARTH-, Dlomotion/ECHOHEARTS-REBEARTH-BUILD-, and Dlomotion/Echohearts. Inspect each repo's actual content before proposing changes. Prefer small topic branches and reviewed PRs; do not force-push or merge without review.

## Verification gates
Mark repository static inspection separately from runtime verification. Never label UE editor load, Git LFS round trip, UHT/compile, Development package, trusted runner, gameplay or rollback VERIFIED without actual corresponding evidence. Report NOT YET VERIFIED and exact blockers. For every change: explain affected files, expected behavior, reproducible tests, and rollback path. Preserve PR #14 / issues #12 and #13 dependency-gate principles where applicable.
