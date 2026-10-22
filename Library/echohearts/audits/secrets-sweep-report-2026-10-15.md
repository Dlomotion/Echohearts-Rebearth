# Exposure Report — Public Web Prototype & Repos
**Date:** 2026-10-15 · **Scope:** public surfaces only · **Mode:** read-only (nothing public was changed)

## Bottom line
**Nothing was exposed.** No API keys, tokens, passwords, private keys, email addresses, payment keys, or credentials were found anywhere on your public prototype or in your public repos. No fixes were needed, so no local changes were made either.

## What was checked
1. **Your live prototype** (the public Pages site) — read the full rendered page: a design-targets page with no forms, no scripts calling outside services, no email addresses, and no external links.
2. **The `index.html` copies on main** in `Echohearts-Rebearth`, `Echohearts`, `Echohearts-Ecokins`, and `ECO-KIN-Game` (one "Add index.html" commit each) — scanned via code search for secret patterns.
3. **All public repo contents** (Dlomotion org) — searched for: `api_key`, `AKIA` (AWS keys), `password`, `discord`/`discord.gg`, `webhook`, `firebase`, `mailto:`, `stripe`, `javascript:`, `location.href`, plus filenames `.env`, `.pem`, `credentials`.
4. **URL-launching patterns** from the recent Unreal security disclosure (CVE-2026-14765, published Oct 14 2026 — insecure default URL-scheme filter on the LaunchURL node, CVSS 7.7). Checked whether anything on the public surface launches URLs from untrusted input.
5. **Private repos** — out of scope; not touched.

## Findings

### 1. `http://` string in the published page — benign (info)
- **Location:** `Dlomotion/echohearts-web` → `index.html` (the single `http://` match site-wide)
- **What it is:** the standard `http://www.w3.org/2000/svg` namespace identifier inside the page's embedded icon (a data-URI favicon). It is a name, not a network request — the browser never fetches it.
- **Severity:** none. No action needed; "fixing" it would break the icon.

### 2. Unreal URL-launching disclosure — no applicable surface (info)
- **What was checked:** CVE-2026-14765 affects Unreal Engine games (≤ 5.8.0) that load user content containing Blueprints and launch URLs without a scheme filter.
- **Result:** your public prototype is a static web page, not a UE game — there is nothing here that launches URLs from untrusted input. Nothing to fix on the public surface.
- **For later:** worth one line in your UE build checklist — when the game client can open links, set an explicit allowed-scheme list (https only) rather than relying on the engine default. Your 5.8.3 lock is newer than the affected versions, but the hardening habit still applies.

### 3. Word matches that are not secrets (info)
- 4 hits for "password": one is game-design prose ("a puzzle … rather than a generic password"), three are your own "never commit secrets/passwords" policy lines in Copilot instruction files.
- 3 hits for "stripe": all creature-design words ("striped hindquarters", "ZuriStripe") — not payment keys.

## Decision list
- [ ] **No secrets to rotate** — none were found, so there is nothing to revoke or reissue.
- [ ] **No changes needed** on the prototype, the repos, or the published site.
- [ ] **Optional:** I can re-run this sweep any time — say after the next prototype publish or before a launch.

## Verification notes
- All checks were read-only: no commits, pushes, merges, or publishes.
- Private repositories were not accessed.
- Any secret found would have been redacted here — none was.
