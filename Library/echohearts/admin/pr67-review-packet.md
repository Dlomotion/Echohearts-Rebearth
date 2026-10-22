# PR #67 Review Packet — Game Asset Library
**One page. Read-only review — nothing merged, nothing changed on the branch.**

## What it is
Draft PR #67 on `Dlomotion/Echohearts-Rebearth`, branch `content/game-assets-library` → `main`. Opened 2026-10-12 by Tay. 6 commits, **51 files**, ~30 MB.

## The 51 files
| Group | Files | Size |
|---|---|---|
| `walls/` — 8 Sanctuary wall designs | ASSET_Wall_*_v1.jpg | 7.7 MB |
| `furniture/` — 10 Sanctuary furniture pieces | ASSET_Furniture_*_v1.jpg | 4.6 MB |
| `accessories/` — 8 Eco-Kin accessories | ASSET_Accessory_*_v1.jpg | 3.0 MB |
| `cosmetics/` — 8 outfit/pattern designs | ASSET_Cosmetic_*_v1.jpg | 5.1 MB |
| `maps/` — 13 Rebearth region vistas (all 13 regions) | MAP_*_v1.jpg + README.md | 9.2 MB |
| Manifests + readme | GAME_ASSET_MANIFEST.csv, MAP_THUMBNAIL_MANIFEST.csv, README.md | — |

All 47 assets are CONCEPT art (JPG renders, not engine imports). No code, no canon-doc changes, no deletions. Asset names are Echohearts-original.

## Placement: root vs `07_Art`
Everything sits at the **repo root** (`walls/`, `maps/`, …). The repo's canon art lane is `07_Art/` (currently holds intake manifests only). Two clean options:
- **A — merge as-is:** fastest; root folders are clearly named and the manifests document them.
- **B — move under `07_Art/` first:** matches the 00–11 canon structure; one extra commit on the branch before merging.

## Risks & checks
- **Canon:** clean — no renames of locked terms, no new Dex entries, no mechanics.
- **Size:** ~30 MB of JPGs on the branch; fine for Git (no LFS needed at this size).
- **Reversibility:** merge is a normal PR merge; reverting later is one click.
- **Evidence tier:** CONCEPT — these are source images, not UE imports or Blueprint implementations.

## Recommendation
**Approve — option A (merge as-is), or B if you want the canon layout.** The content is safe either way; placement is the only judgment call.

## Exact merge command
On the PR page, click **"Ready for review"**, then **Merge pull request** → **Confirm merge**. Or via CLI:
```
gh pr merge 67 --repo Dlomotion/Echohearts-Rebearth --merge
```
(Use `--squash` instead of `--merge` if you want the 6 commits collapsed into one.)
