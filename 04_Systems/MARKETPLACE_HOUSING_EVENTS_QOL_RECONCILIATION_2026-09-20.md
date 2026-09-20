# Marketplace, Housing, Cross-Region Events & QoL Reconciliation

Status: APPROVED SYSTEM DIRECTION / STANDALONE CORE LOGIC VERIFIED / UE5.8 INTEGRATION NOT YET VERIFIED

## Purpose
This document reconciles the older Unity-era marketplace, player-house, event-manager, and daily-mission proposals into the current Echohearts: Rebearth design without reintroducing retired gacha, creature-commerce, forced-labor, or duplicate system architecture.

The competitive goal is not to copy Summoners War or another monster-taming game. Echohearts should outperform genre expectations through a living restoration economy, meaningful player ownership, low-friction daily play, world-state events, ethical Eco-Kin agency, strong tactical depth, and transparent progression.

## 1. Marketplace Economy Logic

### Allowed marketplace categories
- purified/refined materials
- crafted consumables
- legal building components
- furniture and housing decorations
- cosmetic-only player and A.E.G.I.S. items
- approved non-sentient collectibles

### Forbidden marketplace categories
- Eco-Kin
- Eco-Kin eggs
- sentient partners
- extracted creature cores
- forced-work contracts
- power sold for premium currency
- raw Blight Husk as ordinary trade stock

### Market model
Use a server-authoritative listing market with escrow/reservation rather than direct client-to-client trust.

Core transaction path:
`listing request -> validate identity/item/category/quantity -> reserve seller stock -> validate price band and listing cap -> publish listing -> buyer request -> reserve buyer funds -> atomic transfer -> tax/sink -> persistence -> receipt/event id`

Marketplace safeguards:
- bounded listing quantity
- bounded price band around a trusted reference price or designer floor/ceiling
- listing fee and sale tax as economic sinks
- per-account active-listing limits
- idempotent transaction IDs
- server-side inventory and wallet authority
- rate limiting and exploit telemetry
- price-history UI based on completed transactions, not client claims
- no hidden odds or premium rerolls

Regional economy hooks may adjust reference prices from supply, demand, route safety, restoration health, disaster state, and seasonal production, but all movement must remain designer-capped so a simulation cannot destroy progression.

## 2. Player Housing & Furniture System

Player housing is an extension of the Sanctuary and settlement-restoration fantasy, not a disconnected apartment minigame.

### Core housing features
- player-owned personal quarters / Sanctuary home plot
- modular rooms and outdoor restoration plots
- grid/snap placement with rotation and collision checks
- furniture categories: seating, storage presentation, lighting, wall decor, trophies, plants, crafting-adjacent decor, Eco-Kin-safe habitat enrichment
- saved layout presets
- move, rotate, remove, undo/redo
- favorite/lock furniture to prevent accidental sale or dismantle
- accessibility path-clearance checks for required interaction routes
- optional co-op guest permissions: visit, interact, decorate-with-permission, never alter ownership without authorization

### Eco-Kin agency rule
Housing can provide optional comfort and enrichment spaces. It must never turn Eco-Kin into furniture, passive generators, forced workers, or tradeable property.

### Progression philosophy
Housing rewards should be primarily expression, collection display, convenience, social identity, and restoration storytelling. Avoid combat-stat pressure that would make decoration mandatory for competitive viability.

## 3. Cross-Region Event Timers

Cross-region events use authoritative UTC/world time. Client device time is presentation only and must never decide rewards or eligibility.

Event definitions should contain:
- EventID
- eligible RegionTags
- first start UTC
- duration
- recurrence or explicit schedule windows
- prerequisite story/world-state tags
- participation rules
- reward contract
- visible world-state delta
- catch-up/late-entry rules

A single event may affect several regions differently. Example: a Blight storm can intensify wildlife stress in Vespera, alter traversal in Skyforge, and create purification objectives in Azuredeep while sharing one authoritative event identity.

Use Unreal timers only to refresh local presentation while the game is running. Event truth should be derived from absolute authoritative timestamps so reconnects, travel, sleep/resume, and offline periods cannot desynchronize the event calendar.

## 4. Daily Missions Improved

Daily play should respect the player's time and reinforce Echohearts' identity rather than become repetitive chores.

### Standard daily package
- 3 primary daily missions
- categories diversified where possible so the three missions do not repeat the same activity
- mission pool filtered by story progress and unlocked regions
- no standard daily that requires a rare spawn, low-probability drop, specific paid item, or owning a specific Eco-Kin
- one free reroll per day, no premium reroll economy
- claim-all support
- progress counts even if the player did not manually pin the mission when the action is objectively eligible
- one optional catch-up reserve for a missed day, capped to prevent hoarding/FOMO exploitation

Preferred categories:
- Restoration
- Eco-Kin Care
- Exploration
- Crafting/Building
- Arena/EchoDeck
- Community/Co-op optional objective

Daily rewards should support normal progression without making login streaks mandatory for core power.

## 5. QoL Improvements

Priority QoL package:
- claim all eligible mission rewards
- favorites/lock for items and furniture
- smart inventory filters and search
- compare current marketplace price with recent completed-price range
- bulk craft/build preview before committing resources
- pin/unpin objectives from A.E.G.I.S.
- event calendar with local-time display plus authoritative server-time source
- reconnect-safe mission/event progress
- autosave after meaningful authoritative transactions, using supported async save paths where applicable
- clear failure reasons for marketplace, housing placement, crafting, and event eligibility
- color + icon + text states so important information is not color-only

## 6. Competitive Differentiation

Echohearts should not compete by adding more grind. Its advantage should come from systems feeding the same world fantasy:

`restore the land -> settlements recover -> regional supply improves -> marketplace conditions change -> housing/Sanctuary expands -> new missions/events unlock -> Eco-Kin relationships deepen -> world visibly changes`

This creates a feedback loop competitors cannot reproduce merely by copying rune optimization, daily checklists, or summoning cadence.

## 7. Technical Contract

The standalone core introduced in `09_Technical/MetaSystems/EchoheartsMetaSystemsCore.hpp` verifies four bounded behaviors:
1. marketplace validation, price-band protection, fees/taxes, and Eco-Kin trade prohibition
2. housing grid placement, rotation, overlap, bounds, and removal
3. cross-region recurring event-window evaluation
4. deterministic daily mission selection with rare-spawn chores excluded

Production Unreal implementation must remain data-driven using Primary Data Assets / data tables and Gameplay Tags where appropriate. Permanent multiplayer outcomes must use server authority and the BCT-001 transaction contract.

## Verification status
- system reconciliation: VERIFIED AS REPOSITORY ARTIFACT
- standalone C++17 domain core: VERIFIED BY LOCAL COMPILE/EXECUTION
- GitHub CI: pending on feature branch until workflow run completes
- UE5.8 project integration: NOT YET VERIFIED because the current repository contains no `.uproject` or `Source/` tree
- backend persistence, marketplace security, multiplayer race handling, economy balance, and live event operations: NOT YET VERIFIED

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.
