# EchoCode Card System — Canon Reconciliation

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

Status: APPROVED-PENDING SYSTEM DESIGN
Verification: historical card/UI concepts are preserved; physical manufacturing, redemption backend, economy, legal/compliance, tabletop balance and UE5.8 integration are NOT YET VERIFIED.

## Purpose
Preserve the user's physical trading-card + digital EchoCode idea while reconciling it with current Echohearts canon, sentient Eco-Kin ethics, the locked 12-element system, current public stats and the existing EchoDeck / Harmony Circuit / Resonance Arena simulation space.

## Core product rule
An official Echohearts card can exist in three connected forms:
1. **Collectible** — physical/digital art and set collection.
2. **Playable** — tabletop or approved digital EchoDeck/Harmony Circuit play.
3. **Connected** — an EchoCode may unlock eligible game content.

The historical principle remains valid: **cards unlock opportunities, not automatic domination.**

## Sentient-partner correction
Eco-Kin are autonomous sentient partners. Therefore an Eco-Kin card or EchoCode must not sell, transfer, store or instantly grant ownership of the living Eco-Kin.

Correct reward patterns include:
- EchoDeck/Harmony Circuit representation of an Eco-Kin;
- cosmetic variant or approved visual customization;
- lore/EcoDex entry after appropriate discovery rules;
- side quest or authored encounter lead;
- Kindling opportunity or habitat clue;
- Sanctuary decoration;
- approved gear/cosmetic;
- balanced technique-training opportunity;
- event access that still follows normal story/eligibility rules.

Forbidden reward patterns include:
- instant ownership of a sentient Eco-Kin;
- paid max-level partner;
- paid-only unbeatable move or stat advantage;
- creature trading/transfer as a commodity;
- forced Growth Rite/evolution;
- extracted creature cores, eggs or body parts as monetized rewards.

## EchoCode lifecycle — design target
Historical flow is retained conceptually:
`Card → hidden one-time EchoCode / QR → A.E.G.I.S. redemption UI → server validation → account reward entitlement → redemption state recorded → local presentation`

Production security requirements:
- never trust the client to validate codes or assign rewards;
- store only the minimum redemption data needed;
- use high-entropy non-sequential codes;
- one-time or explicitly bounded reuse policy;
- rate-limit attempts;
- prevent reward replay/idempotency errors;
- validate product/set/reward status server-side;
- log redemption outcome without exposing secrets;
- keep QR presentation separate from the actual authorization decision;
- do not put raw production secrets in card art or client data.

No backend code is authorized by this document. Implementation waits for the existing technical gates and an approved account/backend architecture.

## Historical archetype translation
Historical `Frost-Kin`, `Light-Kin` and `Storm-Kin` are **card archetype / presentation labels**, not new core elements.

Working mappings:
- **Frost** → primarily Hydro, with frost/chill status tags and optional Lunar support where justified.
- **Light** → Radiant and/or Solar depending on species and ability.
- **Storm** → Aero and Volt.

Locked core elements remain:
Solar, Lunar, Hydro, Magma, Aero, Flora, Volt, Terra, Iron/Tech, Spirit, Chaos, Radiant.

## Public card stats
The historical VIT / AGS / VEL / RSN / SYNC package is retired as the public identity system.

Any publication-facing Eco-Kin identity card should use the current four attributes when stats are shown:
- Vibrance
- Density
- Harmony
- Purity

Tabletop-specific combat values may exist as **card-game-only values** after balance work, but must be visibly separated from the canonical Eco-Kin identity stats and must not redefine campaign stats.

## Card categories
Approved-pending category structure:
- Eco-Kin cards
- Ability / Technique cards
- Ancient Tech / Gear cards
- Sanctuary / Field cards
- Growth Rite / Form Quest cards
- Rift / Event cards
- Legendary / Lore cards

Names, quantities and individual rewards remain set-design decisions rather than canon facts until approved.

## Genesis Bloom
`Echohearts: Genesis Bloom` remains an APPROVED-PENDING first-set concept.

Historical `95-card` composition and booster odds are SOURCE/PROPOSAL only. They require:
- game-balance review;
- manufacturing and collation feasibility;
- consumer-protection / promotional-code review;
- regional legal/compliance review;
- age-appropriate purchase design;
- duplicate/reward-fairness analysis;
- accessibility and readability review;
- monetization review against the no-pay-to-win rule.

## Tabletop / EchoDeck rules
Historical tabletop ideas are preserved as prototypes:
- 3 active Eco-Kin concept;
- bench/roster concept;
- Essence resource;
- Circle Balance Gauge;
- victory by combat, restoration, balance or mission objective.

These belong to the **EchoDeck / Harmony Circuit / Resonance Arena simulation layer**, not the real-time campaign combat system. Final deck size, bench count, turn structure and win conditions are pending dedicated balance/testing.

## Community Card Forge
Preserve the community idea, with governance safeguards.

Community voting may inform:
- animal/body-plan inspiration;
- biome;
- personality;
- element direction;
- signature ability direction;
- alternate art themes.

A winning vote does **not** automatically become canon. Every selected concept must pass originality/IP, canon, anatomy, safety, balance, narrative, accessibility and production review. Creator credit/permissions/releases must be documented before publication.

## Glow Worm integration
Glow Worm is a valid historical featured-card candidate, especially for a luminous/support deck direction. Its old `Light-Kin` label must be reconciled to the locked element system. The card represents Glow Worm; it does not transfer ownership of the living Eco-Kin.

## Production acceptance criteria
Before this system can be called VERIFIED:
1. approved card schema and visual template;
2. approved entitlement/reward matrix;
3. server-side redemption threat model;
4. duplicate/replay/idempotency tests;
5. monetization/no-P2W review;
6. physical print/QR readability test;
7. accessibility test;
8. EchoDeck rules prototype and balance sessions;
9. UE5.8 UI/backend integration evidence;
10. provenance/rights ledger for all card art.

Final status: **SYSTEM DIRECTION PRESERVED / CANON-CORRECTED / NOT YET VERIFIED**.
