# Eco-Kin Master Registry: October 9, 2026 Intake Audit

**Status: PROPOSED / NOT CANON APPROVED / NOT RUNTIME VERIFIED.** This is an intake and review record, not a replacement for the Permanent Dex, Master Bible, Data Dictionary, or ECO_KIN_ART_MANIFEST.

## Source and scope
- Source: user's uploaded `echohearts-ecokin-master-registry.csv` (554 rows); transformation from uploaded corrected registry `echohearts-ecokin-master-registry-CORRECTED.csv`. The committed plain-text CSV was reconstructed from file parsing and may normalize formatting of numeric cells (e.g. 56 → 56.0); it must be checked against the supplied workbook before approval.
- Intake file: [Corrected 554-row registry](./echohearts-ecokin-master-registry-CORRECTED.csv).
- The companion local QA/stats workbook `Echohearts_EcoKin_Registry_QA_Stats_2026-10-09.xlsx` was produced separately, **not uploaded in this PR**. It remains necessary to compare any further review changes.
- The fixed 125-ID Permanent Eco-Kin Dex remains protected and unchanged. There are 125 uniquely numbered entries and 429 unnumbered entries; unnumbered names must not get permanent IDs by inference.
- 127 entries have review flags and 23 unnumbered entries have *draft-only* proposed stat adjustments. Original imported stat values are retained alongside proposals.
- 68 numbered entries are `PENDING REVIEW`, one numbered entry (`DEX-112` / `Maat`) is `LEGACY-HISTORICAL`, while all 125 are source-marked `DEX-CONFIRMED`. Do **not** interpret `DEX-CONFIRMED` as final identity, balance, or implementation approval.
- Stat columns are Vibrance, Density, Harmony, Purity. All imported numeric values are within 0–100. Draft proposals are not automatically accepted balance changes.
- `Ecosystem` and `Environment` contain recurring placeholder-like entries; require species-specific biological and biome review.
- `Nature` remains the protected Guardian of Life and Legendary Humanoid-Kin with conditional Mutations. No ordinary evolution promotion is implied.
- `SourceRow` and other audit fields preserve reconciliation targets. The CSV's sorted order must not be used for permanent identity assignment.

## Promotion gates
1. Compare every protected ID/name and every source art link against the current Permanent Dex, Master Bible, historical naming archive and art manifest; reconcile conflicts instead of overwriting approved records.
2. Apply official Essence type mapping from `00_Canon_Lock/CANON_CORE_RULES.md`; use current approved canon terms over legacy taxonomy.
3. Resolve possible merges and growth/form candidates, name originality, reference/provenance, anatomy, ecology, habitat and autonomous Kindling/consent status. Retain retired items in the historical archive only.
4. Approve or reject each draft stat proposal with role-specific PvE/Arena tests and bi-directional Anima-Link regression; never auto-cap all species at 95 without approved balance rationale.
5. Produce machine-readable import contract and deterministic validator with separate warnings versus errors, then integrate only approved records through the existing UE5.8 data asset pipeline in `Dlomotion/ECHOHEARTS-REBEARTH-BUILD-`.
6. No merge to canon, asset migration, verified runtime claim, or publication without human canon review and retained required checks.

Related intake: [African concepts #48](https://github.com/Dlomotion/Echohearts-Rebearth/issues/48), [October visual wave #49](https://github.com/Dlomotion/Echohearts-Rebearth/issues/49).

This note is an audit/evidence boundary, **not** a persistent coding-agent instruction file.
