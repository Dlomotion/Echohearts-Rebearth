# index.html Repair Dossier — Six Repos
**Date:** 2026-10-15 · **Read-only investigation. Nothing changed on any repo.**

## What happened
On 2026-10-05, a 4.39 MB web-prototype `index.html` was committed directly to `main` on six repos (author: ECHOHEART), against the no-direct-push-to-main rule. The file is harmless content-wise (the prototype page, verified clean in the secrets sweep), but it doesn't belong on `main` in repos that aren't the web prototype's home.

## Per-repo status and options

| # | Repo | Commit | Status | Option A (recommended): preserve + revert | Option B: plain revert |
|---|---|---|---|---|---|
| 1 | `Dlomotion/Echohearts-Rebearth` | `b2a54cfb` "Add index.html" (2026-10-05) | Confirmed on main | Branch `archive/web-prototype-2026-10-05` from the commit, then revert on main | Revert commit on main directly |
| 2 | `Dlomotion/Echohearts` | `0a5fb6a8` "Add index.html" (2026-10-05) | Confirmed on main | Same as above | Same as above |
| 3 | `Dlomotion/Echohearts-Ecokins` | `a5745554` "Add index.html" (2026-10-05) | Confirmed on main | Same as above | Same as above |
| 4 | `Dlomotion/ECO-KIN-Game` | `e5882feb` "Add index.html" (2026-10-05) | Confirmed on main | Same as above | Same as above |
| 5 | `Dlomotion/ECHOHEARTS-REBEARTH-BUILD-` | Unknown | **Unverifiable** — repo moved to `IN2Deep-Studios` (private, unreachable) | Decide after access granted | Decide after access granted |
| 6 | `Dlomotion/ECHOHEARTS-REBEARTH-` | Unknown | **Unverifiable** — repo moved to `IN2Deep-Studios` (private, unreachable) | Decide after access granted | Decide after access granted |

**Why A is recommended:** the prototype is a real piece of project history (published 2026-10-05, page live). Preserving it on an archive branch keeps the history; reverting main restores branch hygiene. Nothing is lost either way.

## What happens after you choose (per repo)
1. Create `archive/web-prototype-2026-10-05` at the bad commit (Option A only).
2. Open a revert PR against `main` (draft).
3. You review and merge — main is never touched without your explicit approval.

## Your six calls
Reply with A or B per repo (e.g. "A for 1–4, decide 5–6 later"). Repos 5–6 stay parked until the private org is reachable.
