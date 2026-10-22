# Echohearts Game Asset Pack — Sanctuary Building Set

**Status:** CONCEPT (all 34 assets). Generated 2026-10-05. Pending Tay's review before any engine import.

## Contents

| Category | Folder | Count | Purpose |
|---|---|---|---|
| Walls | `walls/` | 8 | Sanctuary/home-base wall panels — SanctuaryWood, StoneHearth, CrystalVein, BambooGrove, AegisSteel, LivingMoss, GlazeIce, PyreEmber |
| Furniture | `furniture/` | 10 | Placeable Sanctuary furniture — canopy bed, round table, chair pair, bookshelf, Aegis console, planter box, moss couch, star rug, crystal lamp, storage chest |
| Accessories | `accessories/` | 8 | EcoKin wearables/gear — leaf scarf, trail saddle, resonance collar, explorer hat, travel pack, sun goggles, wing charms, harmony bell |
| Cosmetics | `cosmetics/` | 8 | Tamer outfits (explorer, guardian, scholar, festival) + EcoKin pattern swatches (floral, ember, frost, starlight) |
| **Total** | | **34** | |

## Art direction

- Stylized cozy-fantasy, warm soft lighting, clean readable silhouettes.
- Nature + ancient-tech crystal motifs, green/gold accents — consistent with Echohearts branding.
- Walls: flat front-on swatches filling the frame. Items: single item centered on light warm-gray studio background, three-quarter view.
- All designs are original — no outside-game assets copied.

## Files

- `GAME_ASSET_MANIFEST.csv` — per-asset registry: `asset_id, name, category, filename, relative_path, intended_blueprint, status, notes`.
- Intended Blueprint/data targets: `BP_Wall_*` actors, `DT_Furniture`, `DT_Accessory`, `DT_Cosmetic` data tables.

## Evidence level

**CONCEPT.** These are source images only. They are NOT imported into Unreal, NOT Blueprint-implemented, and NOT runtime-verified. Import into UE5.8 as textures/sprite assets, then promote through the normal evidence chain (IMPLEMENTED → COMPILED → TESTED → RUNTIME VERIFIED).

## Notes

- Folders also contain small `media-generation-*.json` sidecar files from the generation pipeline (provenance bookkeeping); safe to delete.
- Filenames follow the `ASSET_<Category>_<Name>_v1.jpg` convention — keep this convention for future packs.
