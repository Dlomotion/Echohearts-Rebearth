# Approval Queue — Echohearts: Rebearth

**One place for every decision that's waiting on you.** Each entry has the live status (last verified 2026-10-15), the context, and a recommended default. Nothing here executes on its own — your explicit approval moves each item.

Nudge rule: anything still open gets a short weekly check-in until you rule on it.

---

## 1. Game-assets branch → PR #67 (draft)

- **What:** 47 CONCEPT assets on branch `content/game-assets-library` in `Dlomotion/Echohearts-Rebearth` — 34 Sanctuary assets (8 walls, 10 furniture, 8 accessories, 8 cosmetics) + 13 Rebearth region map vistas + manifests and readmes. 51 files, 6 commits.
- **Status:** Draft PR #67 is open, created 2026-10-12. Nothing has touched main.
- **Your call:** Approve the merge, request changes, or close the PR.
- **Note:** Assets currently sit at the repo root (`walls/`, `maps/`, …). They can be moved under `07_Art/` on the branch before merging if you prefer the canon layout.
- **Recommended default:** Approve with the `07_Art/` move — keeps the canon folder structure clean.
- **Waiting since:** 2026-10-12 (3 days)

## 2. Six `index.html` commits sitting on main

- **What:** The 4.39 MB web-prototype `index.html` was committed directly to `main` on six repos, against the no-direct-push-to-main rule.
- **Status (verified 2026-10-15):** The file is confirmed present on `main` in four repos — `Dlomotion/Echohearts-Rebearth`, `Dlomotion/Echohearts`, `Dlomotion/Echohearts-Ecokins`, `Dlomotion/ECO-KIN-Game`. The other two repos (`ECHOHEARTS-REBEARTH-`, `ECHOHEARTS-REBEARTH-BUILD-`) moved to the `IN2Deep-Studios` org, which I can't reach yet — their copies are unverified until access is granted.
- **Your call (per repo):** Revert the commit, or preserve it on a separate branch and restore `main`.
- **Recommended default:** Preserve each on an `archive/web-prototype-2026-10-05` branch, then revert `main` — history kept, main stays clean.
- **Waiting since:** 2026-10-05 (10 days)

## 3. Private-repo Copilot verification

- **What:** Copilot guidance needs to be confirmed live on your two private repos: `IN2Deep-Studios/ECHOHEARTS-REBEARTH-` and `IN2Deep-Studios/ECHOHEARTS-REBEARTH-BUILD-`.
- **Status (verified 2026-10-15):** Still unreachable — both return "not found" for the GitHub App. This is a repository-selection grant, not a code problem: an org admin needs to add the two repos to the app's installation.
- **Your call:** Grant access (via the Select repositories step), or defer.
- **Recommended default:** Grant — it unblocks Copilot across all seven repos and lets the private-repo comparisons proceed.
- **Waiting since:** 2026-10-14 (1 day)

## 4. Canon calls: Keeper + Celestine Bang

- **What:** Two open terminology rulings from the canon review.
  - **Keeper:** Proposed reconciliation — Frequency Tamer = the profession/class, Keeper = the relational term (what an aligned Ecoform calls its human), Core-Binder = the advanced specialization. This keeps your locked taxonomy intact (EcoKin = creature, Binding / Resonance Alignment / Release, no capture language).
  - **Celestine Bang:** Approve as canon terminology, or replace/retire it. Currently pending-review only — nothing promotes it without your word.
- **Status:** Both await your ruling. Pasted material keeps regenerating the old "Keeper"-as-class usage, so locking this stops the drift.
- **Recommended default:** Adopt the Keeper reconciliation; keep Celestine Bang parked as pending until you rule.
- **Waiting since:** 2026-10-05 (10 days)

## 5. Five creature names awaiting your picks

- **What:** Five recent Dex entries are canonized but unnamed. Options were offered 2026-10-14, all Dex-collision-checked (Glimmeron was dropped — it collided with an earlier batch creature).
- **Status:** Unanswered since 2026-10-14 (1 day). Batch-100 report notes the 1,120-name Master Historical Naming Pool is exhausted — once these are named, fresh batches will need a new name pool.
- **Your call:** Pick one per creature, or supply your own (your better-sounding-wins rule applies):
  1. **Blossom fox** (blossom-petal fur, antlered): Sakurine · Floressa · Petalume
  2. **Volcano dragon** (obsidian, lava veins): Obsidrax · Magmaran · Vulcanor — note: Obsidrax rhymes with Shardrax
  3. **Crystal figure** (gold-white archon mage): Prismaris · Auralith
  4. **Pink poodle butterfly**: Curlwing · Pompaline · Roseplume
  5. **Crystal gorilla** (a Gorilla Ecoform per your ruling): Gorilla (Emeraldform) · Gorilla (Verdiform)
- **Recommended default:** Any of the offered options pass collision checks — pick on sound.
- **Waiting since:** 2026-10-14 (1 day)

## 6. Open Dex flags needing your calls

- **What:** Flags from the canonization batches that only you can rule on. All reversible; originals preserved in the manifest.
- **Status (verified 2026-10-15 in FLAGS_RESOLUTION.md):**
  - **FLAG-22 (OPEN) — Egyptian myth-legacy watch:** Ankhvixen (Dex 466, fennec-fox blade warrior), Auriscarab (467, scarab-winged solar deity), Aquilor (468, eagle/falcon warrior), Khepralya (485, sunscroll oracle). Names are original (no real deity names used), but the visual language draws on Egyptian mythology.
  - **FLAG-23 (OPEN) — Torturecannon rename:** Dex 386 (cannon-armed sea turtle, Zoa/Torrent) — the name embeds "torture."
  - Also open but not yet queued for you: **FLAG-21** (Mangrovix vs Mangrovyx near-collision — one letter apart, high confusion risk) and **FLAG-24** (Aeritix vs Aerinix canonical spelling — board art says Aeritix).
- **Your call:** FLAG-22: keep the Egyptian-aesthetic entries or rework for distance from the mythic register. FLAG-23: approve a rename. FLAG-21: rename one, or keep as a deliberate pair. FLAG-24: lock the canonical spelling.
- **Recommended default:** FLAG-22 — keep (names are original); FLAG-23 — rename under your better-sounding-wins bar; FLAG-24 — lock Aeritix (matches the canonized board art).
- **Waiting since:** 2026-10-14 (1 day)

## 7. Copilot model pin + October 22 policy choice (deadline-sensitive)

- **What:** Finish Copilot setup across all seven Echohearts repos: automatic code review on, model pinned, and the new default policy set — timed before the October 19 model retirements and the October 22 policy change.
- **Status:** Plan accepted 2026-10-15; the model choice and the October 22 policy choice are still yours to supply. Private-repo verification stays blocked on the repo-selection grant (item 3 above); the five public repos can be verified once you decide.
- **Sharpened 2026-10-15 (from third-party write-ups of GitHub's changelog — now CONFIRMED against GitHub's own changelog, Sept 18 entry, see confirmation below):** the October 19 wave retires Gemini 3.7 Flash, GPT-5.5, GPT-5.4, GPT-5.4 mini, GPT-5 mini, and Grok 4.5. Replacements (Gemini 3.8 Flash, GPT-5.6 Sol / GPT-5.6 Luna, Grok 4.6) turn on automatically for Copilot Business/Enterprise under default model enablement unless the global default was switched off. The October 22 change: any Copilot feature still "Unconfigured" in Business/Enterprise settings follows the new default — which ships enabled — while anything explicitly set stays as-is. Individual/Pro plans are not part of that policy change. Whether the policy item touches you depends on your Copilot plan, which we haven't confirmed.
- **Confirmed 2026-10-15 (against GitHub's own changelog):** the October 19 retirement list matches exactly — Gemini 3.7 Flash, GPT-5.5, GPT-5.4, GPT-5.4 mini, GPT-5 mini, Grok 4.5, each with a suggested replacement (Gemini 3.8 Flash, GPT-5.6 Sol, GPT-5.6 Luna, Grok 4.6). The retirement spans Copilot Chat, inline edits, ask and agent modes, and completions across plans — the model picker changes for everyone on Oct 19, not only Business/Enterprise (GPT-5 mini was still listed on the Free tier as of Oct 8). No action is needed to remove retired models. The October 22 policy details check out too (announced Sept 24; choices Enabled / Disabled / Let organizations decide; Business/Enterprise only; explicit settings preserved; preview features stay opt-in). **Timing note:** the weekly nudge lands Monday 09:19 CT — on the retirement day itself — so if you want to pin a model before the wave rather than accept the auto-swapped default, this weekend beats waiting for the nudge.
- **Your call:** Which model to pin, and how to set the October 22 policy (accept the new default or keep the current behavior).
- **Recommended default:** None offered — the specifics of the October 22 policy change and the available models need your review before a recommendation is honest.
- **Deadline:** 2026-10-19 (model retirements), 2026-10-22 (policy change)
- **Waiting since:** 2026-10-15 (today)

## 8. Weekend build transfer route

- **What:** The 41 MB weekend build — uproject + 77 source files including the Summoning and Corruption systems, fusion rites, sanctuary residents, and the 14 phased boss fights — verified intact 2026-10-17 (110 files, uproject + SummoningSubsystem + CorruptionSubsystem confirmed present in the archive). It needs to get onto your Windows UE 5.8.3 machine for the compile gate.
- **Status:** Re-verified 2026-10-17 — the archive lists cleanly and includes everything from this week's builds. Remote-storage upload was blocked by current policy, so a download link can't be generated until that's permitted; the GitHub branch-push route needs your branch-creation approval per your standing rule.
- **Your call:** (a) Download link — generated the moment upload is permitted; or (b) push as a GitHub review branch for your approval.
- **Recommended default:** The GitHub review branch — reviewable, diffable, and it puts the code where Copilot can work on it next week. But it depends on your Windows workflow.
- **Waiting since:** 2026-10-16 (1 day)

## 9. Fusion/residents/bosses roster call + standing build offer

- **What:** 9 code files (Fusion/Sanctuary/Progression) — fusion rites Attunement → Harmonization → Sovereign Concord (no-sacrifice; unfuse restores); six sanctuary residents with anchors and two expansion tiers each; all 14 boss fights broken into phases with health thresholds, signature attacks, arenas, and world-state transitions. Your pasted roster was NOT imported — Terraria's cast stayed out per your methods-not-content rule; its fight craft (phases, thresholds, add waves, arena pressure) went into OUR mechanics instead. The residents keep their name ("Resonance Guardians" was tempting, but Guardians already belongs to your green-and-gold emblem).
- **Status:** Delivered 2026-10-16; local-only, uncompiled (Windows UE 5.8.3 build is the gate). The paste is reconciliation evidence, never canon.
- **Your call:** Veto or approve the roster call; rule on rite/resident names and fused Dex numbering (all vetoable). Standing offer stands: a custom weapon class or Resonance armor set built for these bosses — say the word and it's next.
- **Recommended default:** Keep our roster (methods-only per your IP rule); pick names on your better-sounding-wins bar.
- **Waiting since:** 2026-10-16 (1 day)

## 10. Dex 498–511 flags

- **What:** 14 creatures canonized and filed (498 Frostrelle … 511 Gelidrift); Dex 126–511 fully contiguous with no gaps or duplicate IDs. All names collision-clean vs Dex 1–497. Stats are ESTIMATED — open for your balancing pass.
- **Status (filed 2026-10-16):** Three flags await your calls:
  - **Vaeruun (500) vs Vaeluun (495):** ✅ **RESOLVED 2026-10-19 — Option A.** Tay ruled: keep both as an intentional light/dark counterpart pair (Rift-Temple Arbiter Vaeluun, Aura/celestial vs Rift-Crown Arbiter Vaeruun, Shade/rift). Guardrail: always use full titles in UI/Dex text so the spoken closeness never bites. No renames; originals untouched.
  - **Essence mappings (vetoable):** Radiant→Aura, Lunar→Shade, Aether→Aura, Crystal→Terra, Solar→Pyre, Iron→Terra, Chaos→Voltic, Spirit→Aura — all drift mapped per your 2026-10-14 rule; veto any and it gets re-filed.
  - **Card series:** entries 002, 004, 5, 06, 7, 008, 9, 10 present — entries 1 and 3 not yet seen; they'll slot in when they arrive.
- **Your call:** Keep both Vaeruun/Vaeluun with distinct roles, or rename one; accept or veto any essence mapping.
- **Recommended default:** Keep both with distinct roles; accept the mappings unless one offends the ear.
- **Waiting since:** 2026-10-16 (1 day)

---

## Decision log

| Date | Item | Ruling | Decided by |
|------|------|--------|------------|
| 2026-10-19 | Vaeruun (500) vs Vaeluun (495) name clash | Option A — keep both as intentional light/dark counterpart pair; full titles always in UI/Dex | Tay |
| 2026-10-19 | Copilot Oct 22 default policy for new features | Enabled — Tay chose deliberately (do-nothing would have flipped ON anyway); applies to Business/Enterprise orgs; Tay flips the setting himself at org Settings → Copilot → Policies | Tay |

_When you rule on an item, the ruling, date, and resulting action get recorded here so nothing is decided twice._
