# Proposed patch: the living encounter on-ramp

2026-10-17. Source review only; NOT A PLAYABLE OR COMPILED UNREAL RELEASE.

Added twenty expanded missing-system workstreams with inputs, behavior, safety,
acceptance and dependencies. Added a first playable Field Academy encounter/Kindling
brief with input contexts, screen states, minimal content inventory and eight scenario
runs. Mapped 'Binding ceremony' to existing voluntary Kindling rather than creating
a second capture/bond system. Clarified identity-preserving Shimmer, Strain, farming,
D.A.H.L.I.A., weather, enemies/bosses and content production without promoting new species.

Added an offline habitat/Kindling reference and tests. Host-ready cells propose only
approved eligible species under capacity, with deterministic selection. Ceremony
cannot skip observation/protection/calm, bypass healing or invent consent. Refusal,
release/defer/interruption are first-class outcomes, including after bond readiness
but before commit. Duplicate same-encounter bond reviews emit no new event; a second
owner cannot resolve the same individual through the in-memory ledger.

Fixed during reference review: deterministic population selection now canonicalizes
active-instance ordering; enormous invalid purity integers are rejected before float
conversion can overflow. Spawn commit gates also validate duplicate population records.

Preserved existing source-of-truth hierarchy, the PR #70 battle contracts, approved
Eco-Kin/art authority, one-active partner, free safe recall, and production gates.
The report's eighteen systems/two compile fixes remain user-reported until actual
BUILD sources and Windows logs can be inspected. No existing native implementation
was replaced and no unverified .uasset/.umap or fake mesh/animation was manufactured.
