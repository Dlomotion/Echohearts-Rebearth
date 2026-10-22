# Combined Registry — Build Report (2026-10-20)

Built at Tay's direction ("combine the registry"). Sources: master registry (955 rows) + 17 intake fragments (176 rows; audit confirmed every fragment name already present in master, 0 missing).

Result: `echohearts-ecokin-COMBINED-registry.csv` — 948 unique identities, one row per name, duplicate-name groups merged by status precedence (canon/permanent > kept > pending > merge-duplicate > legacy > retired; DexID breaks ties). Every merge is recorded in the CombineNote column and below. Master registry kept untouched as provenance.

## Merged groups

- **Pebblegill** — 2 rows -> kept [PERMANENT DEX]; merged [PENDING REVIEW]
- **Shoebastion Marshwarden** — 2 rows -> kept [PERMANENT DEX]; merged [PENDING REVIEW]
- **Mossmask** — 2 rows -> kept [PERMANENT DEX]; merged [PENDING REVIEW]
- **Bubba** — 2 rows -> kept [PERMANENT DEX]; merged [PENDING REVIEW]
- **Terralume** — 2 rows -> kept [PERMANENT DEX]; merged [PENDING REVIEW]
- **Osiris** — 2 rows -> kept [PERMANENT DEX]; merged [LEGACY-HISTORICAL]
- **Sekhmet** — 2 rows -> kept [PERMANENT DEX]; merged [LEGACY-HISTORICAL]

Verification: parse-back clean; 948 rows, 948 unique names; no identity lost.
