# The Sky Isles and Skyhold

Date: 2026-10-19. Source: the owner's Sanctuary quest / Sky Isles update in chat. **APPROVED-PENDING** direction: the owner states that the Sky Isles are canonized. Names remain vetoable. This records the supplied direction; it does not establish a built region, imported map or runtime implementation.

## Geography and restoration

The Sky Isles are a floating archipelago held aloft by resonance lift. They rose as Rebearth healed and continue to grow as restoration progresses: restoration made visible in geography. The amount and timing of further growth are not specified in this update and must not be turned into invented numerical gates.

| Isle | Supplied direction |
| --- | --- |
| Galeward Spires | Named isle; detailed ecology, encounters and map placement remain to be authored. |
| Sunshard Terraces | Named isle; detailed ecology, encounters and map placement remain to be authored. |
| Mistveil Gardens | Named isle; detailed ecology, encounters and map placement remain to be authored. |
| Rift Anchorage | Shade-touched, at the archipelago's edge; Vaeruun's shadow lingers here. This story reference does not assign a Dex number, rename Vaeruun/Vaeluun, or resolve their separate naming review. |
| Stormcrown | Named isle; detailed ecology, encounters and map placement remain to be authored. |

Access unlocks after Blightstorm, at the **Skies Clear** milestone. Travel is by **flight or ride only, never teleportation**. Use the recorded completion milestone, rather than `CurrentEra == SkiesClear`, so later world eras retain access. The unlock does not waive ordinary traversal, streaming, landing or safety checks.

## Skyhold

Skyhold is the sky-base annex. Its supplied crafting sequence is:

**Warden's Bench → Chordwork Atelier → Sovereign Forge**

These three tiers are gated by resource star tiers, using shed/gifted materials only. Exact star requirements, recipes, costs, capacities and tier-specific outputs were not supplied; leave them unconfigured until the actual design data is available. Do not infer them from tier position or from another workstation model.

Reuse existing Sanctuary construction, inventory, resource provenance and save authority. Placement and crafting must validate provenance, reserve/consume inputs and grant the result once. Failed validation changes nothing; retries must not duplicate a building or output. Ground-Sanctuary/Skyhold ownership and inventory-sharing policy remain unspecified.

## Relationship to existing layout work

[The three Sanctuary layout proposals](../04_Systems/SKYISLAND_SANCTUARY_THREE_BLUEPRINTS_2026-10-19.md) describe Starter, Refinery and Recovery **base layouts**, not three geographic isles. They remain proposed templates; this update supplies five geographic isles and one annex. No layout-to-isle assignment is inferred.

The earlier T0–T4 workstation capability table remains a proposal and does not add two tiers to Skyhold's supplied three-bench sequence. Its mining/refinery inputs do not authorize exceptions to Skyhold's shed/gifted-material rule. Reconcile individual recipes through the existing resource registry rather than silently mixing the scopes.

Resident progression is defined in [the Sanctuary quest-chain update](../04_Systems/SANCTUARY_RESIDENT_QUEST_CHAINS_2026-10-19.md).

## Implementation acceptance

- Defeating Blightstorm unlocks access once; advancing to later eras does not relock it.
- A real map supports flight/ride arrival, a safe landing and return route, and no teleport shortcut.
- Save/load preserves the unlock, approved restoration-growth state and Skyhold construction/crafting state.
- Tier prerequisites and their progress are visible; unknown requirements are shown as unconfigured, not guessed.
- Crafting rejects unapproved material provenance and duplicate transaction rewards.
- Vetoing a display name does not change stable world/building identity or invalidate saves.

Engine compile, map creation, traversal, save/load, server authority and packaging remain **NOT YET VERIFIED**. The native BUILD repository is inaccessible in this session; no runtime code is installed by this document.
