# Sanctuary resident quest prerequisites

Date: 2026-10-19. Source: the owner's Sanctuary quest / Sky Isles update in chat. **APPROVED-PENDING** design direction; individual objective data and runtime implementation are not supplied by this summary. Preserve the six existing resident roles and their arrival conditions.

## The six chains

Each resident has a three-quest chain **in addition to** their existing arrival condition. The update supplies these chain names:

| Resident | Three-quest chain |
| --- | --- |
| Mender | Hands That Remember |
| Artificer | What the Shed Leaves Behind |
| Chronicler | The Memory of Rebearth |
| Bondkeeper | The Shape of Trust |
| Purifier | Walk Them Back |
| Scout | Maps of the Healing World |

This establishes eighteen quest slots. Their individual titles, objectives, thresholds, rewards and service/tier mappings are not present in the supplied diff. Do not manufacture those details or describe eighteen implemented quests as delivered.

Quests use measures the game already tracks: **Kindling percentage, Growth Rites, Dex registration count, region restoration, boss progression/eras, and corruption walked back**. Read these from their owning systems. A quest must not create a competing trust meter, Dex count, restoration authority or purification counter. Repeated delivery of one event must not count it twice.

## Arrival, services and expansion

The chains unlock deeper resident services and expansion tiers. They supplement the existing resident arrival, infrastructure/anchor, service and progression requirements. They do not silently delay arrival behind all three quests, replace an existing boss gate, grant a missing anchor, or disable established base services. The exact quest-to-service mapping must come from the filed objective data.

The roles remain Mender, Artificer, Chronicler, Bondkeeper, Purifier and Scout. This update does not rename existing named care NPCs or replace Nurse Calla continuity. The earlier user-requested Nurse Nicky, Nurse Betty and Nurse Becky remain distinct named-care additions to reconcile through existing resident definitions, not duplicate healing authorities.

## Two hard rules

1. **Losing a fight never fails a quest.** A loss must not mark the quest failed, erase earned progress, revoke a completed milestone or remove an earned service. Retry and recovery remain available.
2. **Every prerequisite is visible, with progress shown.** Present the requirement, authoritative current value, target and completion state, alongside the resident's arrival/service requirements. Explain blocked conditions through text/icons as well as color. If an objective has not been configured, display that fact rather than an invented target or false completion.

Whether an unfinished objective uses a live threshold or a once-earned milestone is not specified for every measure. Configure that explicitly per objective; do not assume a temporary Kindling or restoration change should erase progress. Completed quests and earned unlocks remain durable.

## Integration and persistence contract

Extend the existing mission, resident and save systems after reading their actual source. Keep stable quest/service identities separate from vetoable display names. Persist completion and reward/unlock grants so reloading, reconnecting or retrying completion cannot grant twice. Apply each completion and its service unlock as one authoritative transaction; failed validation leaves the prior state intact.

Progress comes from the existing authoritative event/state sources. Use durable boss milestones for completed story gates; comparing only the current era label can make a completed requirement disappear in later eras. A client widget may display progress but cannot award completion.

This is a contract for those existing systems, not a new quest manager, NPC registry, save schema or Unreal module in the public canon repository.

## Relationship to Skyhold

[The Sky Isles update](../02_World/SKY_ISLES_AND_SKYHOLD_2026-10-19.md) records the five isles, the Blightstorm access milestone and Skyhold's three crafting tiers. No resident-to-bench or quest-to-star mapping is inferred. The three existing Skyisland layout templates remain separate proposed base layouts.

## Implementation acceptance

- Arrival and anchor checks continue to work independently of deeper-service quests.
- Losing a fight preserves incomplete quest progress and completed rewards.
- Repeating a progress event or completion request cannot duplicate progress, rewards or services.
- Save/load and reconnect retain completed quests and unlocked services.
- Each configured prerequisite exposes the same current/target values used by authoritative validation.
- All six chains contain exactly three authored quests before content is called complete.
- Missing objective definitions or service mappings refuse completion with an explicit reason.

No native compilation, quest execution, UI, save migration or gameplay verification is established by this design update.
