# ECHOHEARTS: REBEARTH — VEILROOT HOLLOWS & THE QUIET MARKET

**Date:** 2026-09-29  
**Status:** APPROVED-PENDING WORLD/QUEST DIRECTION  
**Purpose:** Add one optional hidden biome and a secret black-market seller without introducing sentient trafficking, pay-to-win progression, outside-franchise structures or a parallel economy.

---

## 1. Hidden biome

# **Veilroot Hollows**

The Veilroot Hollows are a concealed subterranean biome beneath forgotten Meridian-era service tunnels and a damaged branch of the Sovereign Heartroot network.

The biome is intentionally absent from the player's normal map until discovered.

Visual identity:

- deep root caverns wrapped around abandoned Meridian conduits;
- dark mirror-water pools that reflect old Memory-Lattice fragments;
- hanging Flora growth with faint Aura/ Shade interaction effects;
- bioluminescent fungi and mineral veining;
- collapsed maintenance platforms reused by scavengers;
- pockets of clean ecology beside pockets still carrying Blight residue;
- low artificial light so living glow and old machinery define navigation.

The biome uses existing production Essences/tags. It does **not** create a new element.

## 2. Discovery rule

Veilroot Hollows should feel discovered rather than selected from a menu.

Possible discovery chain:

1. A.E.G.I.S. records an unexplained low-power maintenance ping after the player restores a nearby root corridor.
2. The signal appears only while the region is in an authored weather/time/world state.
3. The Core-Binder finds a sealed Meridian service door or natural root break.
4. A short environmental puzzle opens the first access route.
5. Entering the biome creates its Map/Archive entry.

Accessibility rule: once the player has legitimately discovered the entrance, A.E.G.I.S. may provide navigation assistance. The biome should not require pixel-perfect secret-wall hunting.

## 3. Ecology

Veilroot is not a dead criminal hideout. It is a living biome with its own restoration problem.

Ecological hooks may include:

- Heart Fruit vines that grow differently in low light;
- cave pollinators;
- root-fed fungi;
- Shade-adapted nocturnal Eco-Kin;
- subterranean water-cleaning organisms;
- abandoned utility heat creating artificial warm pockets;
- old Meridian pollutants that must be cleaned before some native life returns.

Any permanent Eco-Kin identity appearing here must come from the authoritative 125-ID Dex or later approved seasonal migration. The biome does not automatically create new species IDs.

## 4. Secret sub-location

# **The Quiet Market**

Hidden within a repurposed maintenance junction is a small illegal exchange known as the Quiet Market.

It is not a giant criminal city. It is a low-profile rotating trade node used by salvagers, smugglers, information brokers and people avoiding formal faction oversight.

The market exists to create moral/economic choice and worldbuilding—not to undermine every lawful vendor.

## 5. Secret seller

# **Rook Sable — “The Veilbroker”**

**Role:** secret black-market seller / salvage information broker  
**Disposition:** pragmatic, guarded, potentially reformable  
**Species/faction:** human NPC unless later story governance assigns another existing people/faction connection

Rook Sable buys and sells unregistered salvage, route information, old Meridian components, cosmetic goods and questionable field hardware.

Rook does **not** sell:

- living Eco-Kin;
- Eco-Eggs as property;
- sentient body parts;
- Bond contracts;
- forced-growth items;
- permanent competitive stat boosts;
- guaranteed-Bond/capture devices;
- premium-currency power advantages.

## 6. Quiet Market inventory families

Potential rotating inventory:

- salvaged A.E.G.I.S. cosmetic shells;
- rare dyes/patterns/outfits;
- obsolete but repairable Meridian scanner parts;
- field-trap cosmetic variants;
- non-sentient weather-baffle components;
- hidden route maps;
- old faction insignia/history collectibles;
- rumor dossiers that begin optional quests;
- Sanctuary decorations;
- repair materials;
- unregistered but non-sentient research samples;
- counterfeit or unstable hardware clearly marked by A.E.G.I.S. risk inspection.

Heart Fruit remains available through normal lawful play. The Quiet Market cannot monopolize it.

## 7. Inspection mechanic

Before buying questionable hardware, the player may use A.E.G.I.S. to inspect it.

Possible results:

```text
Authentic
Repaired
Unregistered
Counterfeit
Unstable
Stolen Provenance Suspected
Unknown
```

Inspection creates informed choice rather than random punishment.

## 8. Consequence model

Buying from the Quiet Market is not automatically evil.

The game tracks what the player supports.

Examples:

- buying harmless salvage/cosmetics has little consequence;
- buying stolen public-infrastructure components may hurt faction trust;
- returning a stolen component may create restitution/reform progress;
- purchasing a rumor can expose a larger exploitation ring;
- helping Rook establish legitimate salvage channels can reform the market;
- turning the market over to an authoritarian faction may solve one problem while creating another.

Suggested world-state concepts:

- `QuietMarket.Discovered`
- `QuietMarket.Trust`
- `QuietMarket.IllegalTradePressure`
- `QuietMarket.RestitutionProgress`
- `RookSable.Disposition`
- `Veilroot.EcologyRestoration`

These are design keys, not verified runtime fields.

## 9. Rook Sable story routes

Possible outcomes:

### A. Informant
Rook supplies route intelligence and exposes exploitative buyers.

### B. Legitimate Salvager
The player helps convert the Quiet Market into a regulated recovery/reuse exchange.

### C. Conditional Ally
Rook remains outside formal structures but agrees to emergency rules and helps during regional crises.

### D. Hostile Broker
If the player repeatedly sabotages or exploits the market, Rook may close access, sell information to rivals, or leave the region.

### E. U.N.I.T.Y. contribution
If reformed/allied, Rook's network can provide hidden evacuation routes, old infrastructure maps and supply access during the final U.N.I.T.Y. crisis.

## 10. Trap/Heart Fruit connection

Veilroot is a strong optional teaching space for advanced nonlethal fieldcraft.

Examples:

- Heart Fruit scent travels differently through cave air currents;
- Softfield Corrals must preserve narrow wildlife exits;
- Haven Mesh can guide cave-dwelling groups around a polluted water pocket;
- a rescued Eco-Kin can be Released back into the restored Hollow rather than automatically Bonded;
- Rook may initially sell crude illegal trap parts, giving the player an opportunity to dismantle/rebuild them into safe A.E.G.I.S.-compatible field components.

No contraband device bypasses Kindling consent.

## 11. Restoration payoff

Restoring Veilroot can visibly change:

- water clarity;
- fungal light density;
- root growth;
- wildlife return;
- legal/illegal trade balance;
- access tunnels;
- Heart Fruit cultivation;
- Sanctuary supply routes.

The Quiet Market's final state reflects player choices rather than disappearing automatically.

## 12. Production scope

Veilroot should remain optional and bounded.

First implementation target:

- one hidden entrance;
- one small cave loop;
- one restoration problem;
- one Heart Fruit/trap-and-release encounter;
- Rook Sable + one vendor screen;
- one inspect-before-buy interaction;
- one branch deciding whether a questionable component is bought, returned or reported;
- save/reload of discovery and seller disposition.

## 13. Verification boundary

This file establishes approved-pending world/story/system direction only.

It does not prove the biome, NPC, shop, AI, inventory, lighting, quests, map discovery or save state exists in UE5.8.
