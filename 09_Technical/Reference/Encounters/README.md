# Encounter and Kindling offline reference

Python 3.12 standard library. Run from this directory:

```sh
python3 -m unittest -v
```

Implemented: bounded habitat/candidate validation, deterministic weighted species
proposal, current-cell capacity/revision commit gate, ceremony sequence, refusal/
release/defer/interruption outcomes, fresh-revision consent/care checks and an
in-memory idempotent bond-review event ledger. Test fixture IDs are not Dex entries.

Not implemented: actor generation, position/collision/navigation queries, AI, actual
relationship persistence, timers, UI/animation, engine callbacks or game servers.
SpawnProposal and Ceremony must remain host-owned. Constructing a dataclass is not
authentication; untrusted clients must never supply Evidence or approved registry sets.
The host resolves approved species/individual IDs and increments revision whenever
relevant state changes. Revision freshness here is not a wall-clock expiry system.

validate_spawn_commit rechecks cell readiness, capacity and revision; it does not
consume a spawn token or create an entity. The host must use a durable reservation,
unique individual ID and replay-safe spawn transaction, and revalidate all ecology/
geometry constraints. The proposal fingerprint is a deterministic correlation value,
not a signature or proof of authority. Seeds and candidate table schema/version must
be controlled by the host for cross-version replay.

BondReviewLedger emits an intent for the existing bond service. It has no durable or
cross-process locks and cannot adjudicate real multi-player races. Persistent consent,
existing relationship policy and individual uniqueness must be checked atomically by
that service. Cancellation after a committed bond is a separate relationship action,
not replaying the ceremony. Existing bonds are never overwritten by this oracle.

The twenty-workstream design is a derived delivery register, not a verified scan of
the user-reported eighteen implemented/twenty absent systems. Those audit counts and
Corruption compile fixes require the actual report and BUILD source to independently confirm.

Local evidence 2026-10-17: Python 3.12 standard-library unittest ran 23 methods (with per-case loops), exit 0. No Unreal execution. Dlomotion/EcoKin-patch is now accessible as the repair/QA lane; it has policies/templates, not gameplay runtime source.
