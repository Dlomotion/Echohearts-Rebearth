# Seasonal Eco-Kin Quest Expansion — approved design direction

Seasonal Eco-Kin questlines extend the original Echohearts: REBEARTH campaign and its approved references; they do not replace the 42 Core Chronicles, 14 Continuum Anomalies, 200 Resonance Eddies, or 54 additional regional operations currently in draft PRs.

## Production rules
- Unique, persistent `SEA-{seasonId}-{questNumber}` quest IDs. No reuse of `CHR`, `ANO`, `EDY`, `RCH` or `RED` identifiers.
- The existing 125-ID Permanent Dex remains the release roster authority. Future Eco-Kin concepts first enter the existing historical/proposal review workflow, then gain approved Dex IDs through an explicit roster revision. Seasonal quests must not auto-create permanent species.
- Existing Echohearts art references and story continuity are source authority for visual design, powers, dialogue and geography. The proposed 648-species expansion is not silently substituted for the current Dex.
- Seasonal missions center on environmental restoration, community harmonization, resonance puzzles, voluntary Binding/Release and Anima-Link strain. Nature is never an encounter to defeat or bind.
- Expired seasonal content must preserve existing completion records; never delete player history. Cross-platform cloud synchronization must resolve stable mission IDs and versioned seasonal catalogs.
- Four fixed attributes: Vibrance, Density, Harmony, Purity. Nine Essences are not replacement attributes.
- New content must be original and not adapted from external game missions or creature identities.

## Implementation boundary
`EchoheartsSeasonalQuests.hpp` implements portable validation and prerequisites. It does **not** schedule seasons, authorize new canon entries, add Unreal reflected types, or create runtime assets. Those require integration with the existing UE5.8 module, SaveGame, secure cloud registry, mission events and build verification.

## Seasonal quest template (not a canonized species)
1. Survey seasonal frequency drift in an established region.
2. Restore a community/environmental node using two of the four Resonance Keys.
3. Investigate an approved Eco-Kin's altered seasonal behavior; avoid forced Binding.
4. Complete a cooperative Anima-Link restoration encounter.
5. Offer a repeatable post-season ecological maintenance activity.

Status: approved **production direction**, implementation patch **awaiting review and build validation**.
