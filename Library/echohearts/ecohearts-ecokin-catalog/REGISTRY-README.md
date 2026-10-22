# Echohearts: Rebearth — EcoKin Master Registry

**File:** `echohearts-ecokin-master-registry.csv`
**Date built:** 2026-10-05
**Rows:** 554 (125 permanent Dex + 429 historical/archive names)

## What this file is
A working, reconciliation-level registry of every EcoKin name recovered from the project materials: the 125-ID Permanent Dex (production authority) plus every name found in the seasonal lists, roster pastes, creature-candidate tables, name-generation drafts, and share-link summaries. It is a **working document, not canon**. Nothing in this file promotes a name to canon, changes a Dex ID, or overrides the locked constraints (Rebearth, Frequency Tamer / Core-Binder, EcoKin = creature / Ecoform = form, Vibrance / Density / Harmony / Purity, Anima-Link bidirectional, Nature = Legendary Humanoid-Kin, Shadow = condition not species).

## Column definitions
| Column | Meaning |
|---|---|
| Name | EcoKin name as recovered |
| DexID | `DEX-001` … `DEX-125` for permanent Dex identities; blank for archive-only names |
| Status | One of: `LOCKED CANON` (Nature only), `PERMANENT DEX`, `EVOLUTION-FORM`, `PENDING REVIEW`, `RENAME REQUIRED`, `LEGACY-HISTORICAL`, `RETIRED`, `MERGE-DUPLICATE` (per the Eco-Kin Name Governance Lock) |
| Order | `Zoa` / `Flora` / `Myko` / `Proto` / `Monera` — the five Orders of Sentience, inferred from name morphology where unknown. `Humanoid-Kin` appears once (Nature — she is the locked exception, not an Order) |
| Essence | One of the nine Essences: `Flora, Torrent, Pyre, Terra, Aero, Glaze, Voltic, Aura, Shade` — inferred from name morphology / legacy element where unknown |
| Vibrance / Density / Harmony / Purity | 1–100. **The only stats. Never ATK/HP/SPD/DEF.** Deterministic name-based estimates (see DataQuality) |
| Ecosystem | Food-web role (e.g. apex predator, canopy pollinator, soil engineer, abyssal scavenger) |
| Environment | Biome/habitat using canon regions (Echohearts Sanctuary, Sky Haven, Great Plains, Blackfell, Arkam, Cinderfall, Azure Coastline, Silica Glade Fracture, Neon Sea, Rotting Maw, Scorched Barrens, Steel Frost, Crystal Desert, Shadowed Highlands, Boiling Abyss, plus generic wilds/farmland/warrens) |
| EncounterRank | `Common / Uncommon / Rare / Unique / Alpha / Omega / Legendary` (locked ladder — encounter classification, not a power stat) |
| DataQuality | `DEX-CONFIRMED` = identity confirmed in the 125-ID Dex (name + ID; **stats are still estimated** — the real xlsx was never uploaded, so no real stat numbers exist in any source). `ESTIMATED` = every value on the row is proposed/inferred, never canon |

## The DataQuality rule
- `DEX-CONFIRMED` rows: the *identity* (name + DexID + registry status) is confirmed against the recovered 125-ID registry. Stats, Order, Essence, ecosystem, environment, and rank are still estimates until the real Data Dictionary xlsx is uploaded and reviewed.
- `ESTIMATED` rows: archive names from rosters, seasonal lists, and candidate tables. All values are proposed. These names are **not** playable canon, do not hold Dex IDs, and are not promoted by this file.
- Nothing is labeled `VERIFIED` — verification requires a real UE5.8 runtime, which does not exist yet.

## Row count achieved
- **554 rows total** (125 permanent Dex + 429 archive).
- By status: PERMANENT DEX 55 · LOCKED CANON 1 · PENDING REVIEW 484 · LEGACY-HISTORICAL 4 · MERGE-DUPLICATE 5 · RETIRED 3 · RENAME REQUIRED 2.
- By DataQuality: DEX-CONFIRMED 125 · ESTIMATED 429.

## What's still missing
- The full 1,120-name historical pool was **not fully recoverable**: only the 125 Dex names, the ~172 seasonal names, the 51-name roster, the Guardian Beast extras, the §4 candidate table, the name-generation drafts, and scattered share-link names could be reconstructed from the available sources (~550 names). Roughly **half the pool** (including the ~180-name roster from link #20, the 185-entry Dex V2 names, and the 1,120-name alphabetical list itself) exists only in the ChatGPT share-link sessions and was never pasted or exported in full. **Do not invent filler** — the missing names must come from the real `Echohearts_Game_Data_Dictionary.xlsx` when Tay uploads it.
- Flagged names stay flagged, not silently fixed: `Flare-Vulpix` (RENAME REQUIRED), `Googley Eyes` (RENAME REQUIRED), `Dr. Evil Sylar` (RETIRED), `King Luther` / `King Luthar` (MERGE-DUPLICATE), `Zebrask` (MERGE-DUPLICATE → ZebraskA DEX-026), `THOTH` / `Osiris` / `Sekhmet` / `Maat` (LEGACY-HISTORICAL — note DEX-112 Maat keeps its Expansion registry row in the Dex set), `Chaos Woof` (MERGE-DUPLICATE → Pupular DEX-035), `Nuture` (MERGE-DUPLICATE → Nurture DEX-003), `Nova Star` (PENDING REVIEW — collision with Nova DEX-032).
- Outside-film copies (Korben Dallas, Mondoshawan Matrix) and cut names (Dr. Evil, Sylar, Ken Jen, Keisha) are **excluded entirely**, per the consolidation package.
- Stat numbers are deterministic name-hash estimates with morphology biases (crusher/golem/titan → Density; swift/wisp → Vibrance; guardian/warden → Harmony; pure/divine → Purity; blight/void → Purity penalty). They are placeholders for game-design tuning, not balance data.
