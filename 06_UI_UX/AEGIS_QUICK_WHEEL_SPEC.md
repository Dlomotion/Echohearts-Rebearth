# A.E.G.I.S. Quick Wheel Specification

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

## Goal
Keep high-pressure field actions understandable without forcing players through deep menus.

## Quick Wheel Slots
1. Scan
2. Calm
3. Care Item
4. Eco-Kin Command
5. Map Pulse
6. Field Tool
7. Journal
8. Retreat / Call Help

## Interaction Rules
- Open/close must be fast and readable.
- Dangerous actions require clear confirmation feedback.
- Context-sensitive recommendations may highlight a slot but never auto-force the player choice.
- Tooltips use plain language first, lore terminology second.
- Accessibility support: remapping, hold/toggle behavior, icon + text labels, scalable UI, high-contrast state indicators, subtitle/caption support for sound cues.

## Mini-Game Entry Rule
Mini-games reached from the Quick Wheel should launch from an existing field action rather than adding a separate generic arcade menu. Examples:
- Scan can enter A.E.G.I.S. Signal Trace.
- Calm can enter Kindling Rhythm when a valid Calm Window exists.
- Field Tool can enter Purity Flow or repair/calibration interactions when context permits.

The player must always be able to understand why the mini-game opened and what its outcome changes in the world.

## UX Success Criteria
- New player can identify Scan, Care, and Eco-Kin Command without tutorial text after first onboarding.
- No more than two interactions to reach a common field action.
- Menu does not hide critical danger information.
- Calm/Rescue actions are as accessible as combat actions.
- Mini-game entry never hides an urgent retreat/cancel path.

Status: DESIGN SPEC, NOT YET VERIFIED.
