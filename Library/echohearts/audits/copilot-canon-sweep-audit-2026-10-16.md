# Copilot Instructions Canon Sweep — Drift Audit (2026-10-16)

**Scope:** `.github/copilot-instructions.md` on `main` in the 5 reachable repos.
**Unreachable (reported, not treated as done):** `IN2Deep-Studios/ECHOHEARTS-REBEARTH-` and `IN2Deep-Studios/ECHOHEARTS-REBEARTH-BUILD-` — 404 for the GitHub App; needs the repo-selection grant.
**Staging status:** corrected files ready for review (see below); review-branch creation blocked — GitHub write path hanging (no GitHub incident per status page; connector write stuck server-side).

## Method
Each file read in full from `main` and scanned line by line for: hyphenated/legacy creature spellings, capture/catch language, level-evolution language, "18 elements", generic stats (ATK/DEF/SPD/HP), Shadow as element/category, unreconciled "Keeper", capture-device language. Also verified locked terms present and correct.

## Drift found — one pattern, 11 lines
**"Eco-Kin" (hyphenated) → "EcoKin"** — canon rule: locked taxonomy; the creature is "EcoKin", no hyphen (legacy "Eco-Kin" spelling superseded 2026-10-05).

| Repo | Lines corrected |
|---|---|
| Echohearts-Rebearth | L23 ("125-ID Permanent Eco-Kin Dex" → "125-ID Permanent EcoKin Dex"), L30 (section heading "Eco-Kin intake" → "EcoKin intake"), L32 ("into the 125-ID Permanent Eco-Kin Dex" → "EcoKin Dex") |
| Echohearts | L31 (heading), L33 (#48/#49 bullet) |
| Echohearts-Ecokins | L31 (heading), L33 (#48/#49 bullet) |
| ECO-KIN-Game | L31 (heading), L33 (#48/#49 bullet) |
| echohearts-web | L31 (heading), L33 (#48/#49 bullet) |

"Last updated" line stamped 2026-10-16 (canon-spelling sweep) on each corrected file.

## Verified clean (no changes needed)
- Four attributes written as Vibrance/Density/Harmony/Purity — correct everywhere they appear
- Anima-Link named correctly; Growth Rite / Mutation / Shimmer rules referenced correctly
- No capture/catch language, no level-evolution mechanics, no "18 elements", no generic ATK/DEF/SPD/HP stats
- Shadow never miscategorized as element/category; no capture-device language; no unreconciled "Keeper"
- Purity/Corruption model reference is canon-consistent (corruption path vs Purity is mechanically meaningful)

## Corrected files (ready for review)
- `copilot-canon-sweep/echohearts-rebearth-instructions.md`
- `copilot-canon-sweep/echohearts-instructions.md`
- `copilot-canon-sweep/echohearts-ecokins-instructions.md`
- `copilot-canon-sweep/eco-kin-game-instructions.md`
- `copilot-canon-sweep/echohearts-web-instructions.md`

Each is the full corrected file, verified: zero hyphenated variants remain, locked terms intact. They will be pushed as one review branch per repo (no direct push to main) once the GitHub write path recovers.
