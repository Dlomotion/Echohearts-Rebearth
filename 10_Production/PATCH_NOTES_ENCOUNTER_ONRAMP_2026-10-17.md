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

## Follow-up: concrete delivery and connected field-loop checks

Expanded all twenty existing workstreams with owner-data requirements, state/failure
flows, transaction/recovery boundaries, content deliverables and acceptance scenarios.
Kept the same existing index and design ownership. Added no new Permanent Dex identity,
form unlock, map coordinate, extra public attribute or second runtime.

Added original offline references for weather, Strain, legal enemy decisions, guarded
boss phases, restoration crop progress, Shimmer invitation eligibility and read-only
D.A.H.L.I.A. advice. Connected ceremony late refusal to the adviser and shared one storm
snapshot among ecology consumers. Fixed a test expectation during development: weather
elapsed time is local to the current phase, not the entire cycle offset.

Evidence: 34 new methods; combined encounter reference 57 methods passed normally and
with Python optimization; existing battle reference 24 methods passed. Hosted CI runs
both encounter modes and the battle regression. This does not confirm the reported
Corruption compile fixes or count eighteen actual implemented native systems.

Eleven supplied art files are now readable and recorded by original filename/hash
in the existing art intake manifest. They are visual references, not code or imported
assets. One reported upload is still unavailable; its manifest entry says pending import.
No art binary is copied into the public repository without identity/provenance review.

Pending: actual BUILD access, source-owner/API inspection, input/actor/relationship/
inventory/save integration, original DCC meshes and rigs, animations, UI assets, level
placement, UHT/UBT/PIE/package, server tests and target-hardware profiling. Preserve the
existing foundation/Issue #10 production order; these references do not bypass it.
