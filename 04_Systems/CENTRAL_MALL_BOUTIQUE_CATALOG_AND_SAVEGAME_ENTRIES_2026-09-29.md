# ECHOHEARTS: REBEARTH — CENTRAL MALL BOUTIQUE CATALOG & WARDROBE SAVE CONTRACT

**Date:** 2026-09-29  
**Status:** APPROVED-PENDING SYSTEM DIRECTION / TECHNICAL IMPLEMENTATION NOT YET VERIFIED  
**Purpose:** Preserve the requested commerce/boutique hub while separating static catalog definitions from versioned player cosmetic state and keeping all purchases presentation-first.

---

## 1. Commerce-hub direction

The working commerce location is the **Central Mall / Meridian Exchange** inside the broader Echohearts civilization network.

Exact level placement remains subject to the current world/level registry.

Potential storefronts from the intake may remain as original working names:

- **The Tectonic Thread** — outfits and practical fieldwear;
- **Prismatic Leylines** — patterns, dyes and visual customization;
- **A.E.G.I.S. Core Fabrications** — cosmetic shells, scanner frames and non-pay-to-win hardware skins.

These shops do not sell sentient Eco-Kin or permanent competitive stat superiority.

## 2. Intake code audit

The pasted `std::map` + manual text serializer is a useful data sketch only.

Corrections:

1. Static shop definitions and runtime player ownership were mixed conceptually.
2. The custom `[WardrobeSaveProfile]` text format has no schema version, migration, integrity validation or atomic save behavior.
3. Deserialization accepts arbitrary IDs without confirming those IDs exist in the catalog.
4. Equipped items are not validated against the player's unlocked set.
5. Duplicate cosmetic IDs can be loaded repeatedly.
6. The parser treats any opening profile marker as valid and never verifies the requested Binder/account identity.
7. `std::cout` is not a UMG interface or runtime proof.
8. The code is not Unreal SaveGame serialization and should not be called compiled/production-ready.

## 3. Static catalog definition

Recommended authored fields:

```text
VendorID
DisplayNameKey
LocationID
SpecialtyTags
InventoryPolicyID
CatalogEntries[]
SeasonAvailabilityTags
FactionRequirements
DiscoveryRequirements
```

Catalog entry:

```text
CosmeticID
CosmeticType
DisplayNameKey
PreviewAssetID
PriceDefinitionID
UnlockRequirementTags
TradablePolicy
AvailabilityTags
```

Player-facing names should use localization-ready text keys.

## 4. Player wardrobe state

Recommended persistent state:

```text
SaveSchemaVersion
EquippedOutfitID
EquippedPatternID
EquippedAegisShellID
UnlockedCosmeticIDs
FavoriteCosmeticIDs
LastVisitedVendorID
```

The save stores IDs/state, not duplicate static catalog definitions.

## 5. Load validation

On load:

1. migrate old schema if required;
2. deduplicate unlocked IDs;
3. discard/quarantine unknown IDs rather than crashing;
4. verify equipped IDs still exist;
5. verify equipped IDs are unlocked or default-authorized;
6. restore a safe default if an asset has been retired;
7. preserve a migration log for debugging.

## 6. Purchase transaction

A purchase should be authoritative and atomic:

```text
Request purchase(VendorID, CosmeticID)
→ validate vendor/catalog/availability
→ validate currency/material source
→ reserve cost
→ grant CosmeticID
→ persist transaction
→ acknowledge to client
```

Do not trust a client-provided price.

## 7. Economy boundary

The Central Mall may use the project's established ordinary economy/currency direction.

Do not introduce a new premium currency merely because this file adds shops.

Cosmetic commerce may include:

- outfits;
- dyes/patterns;
- hairstyles/accessories where character art supports them;
- A.E.G.I.S. shells;
- profile frames;
- Sanctuary decorations;
- emotes;
- music/UI presentation unlocks.

It must not sell:

- Eco-Kin ownership;
- paid Bond probability;
- permanent PvP stat advantage;
- exclusive required Growth Rite power;
- one-time Event Sovereign victory.

## 8. Quiet Market relationship

The lawful Central Mall and **Veilroot's Quiet Market** are intentionally different economies.

Central Mall:

- transparent catalog;
- known provenance;
- ordinary consumer/customization goods;
- faction/legal oversight.

Quiet Market:

- rotating salvage;
- uncertain provenance;
- rumor/route information;
- rare cosmetics;
- unregistered non-sentient hardware;
- inspect-before-buy risk.

The Quiet Market does not replace normal progression or make lawful shops useless.

## 9. Rook Sable catalog isolation

Rook Sable's inventory must be authored through a separate rotating catalog policy.

Suggested states:

```text
QuietMarketCatalogID
DiscoveryState
RookDisposition
RestitutionState
RegionalHeatOrScrutiny
InventoryRotationSeedOrSchedule
```

If deterministic rotation is used, it must not expose exploitable client-authoritative seeds.

## 10. Save transaction boundary

Wardrobe/unlock data should participate in the broader versioned SaveGame/account-state contract.

A raw text buffer may be used only as a test fixture or export/debug representation—not as the authoritative production save format.

## 11. Verification boundary

This document does not prove working vendors, currencies, UMG screens, purchases, SaveGame migration or marketplace persistence.

Status remains **NOT YET VERIFIED** until real UE5.8 implementation and runtime evidence exist.
