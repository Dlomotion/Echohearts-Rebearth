# Encounter and Kindling offline reference

Python 3.12 standard library. Run from this directory:

```sh
python3 -m unittest -v
```

Implemented: bounded habitat/candidate validation, deterministic weighted species
proposal, current-cell capacity/revision commit gate, ceremony sequence, refusal/
release/defer/interruption outcomes, fresh-revision consent/care checks and an
in-memory idempotent bond-review event ledger. Test fixture IDs are not Dex entries.

Not implemented: actor generation, position/collision/navigation queries, native AI, actual
relationship persistence, timers, UI/animation, engine callbacks or game servers.
SpawnProposal and Ceremony must remain host-owned. Constructing a dataclass is not
authentication; untrusted clients must never supply Evidence or approved registry sets.
The host resolves approved species/individual IDs and increments revision whenever
relevant state changes. Revision freshness here is not a wall-clock expiry system.

validate_spawn_commit requires host candidates, approved species and seed as keyword
inputs. It recomputes the full proposal against the current habitat and rejects a
changed species, fingerprint, seed, candidate table or habitat, including when an
adapter forgot to increment the habitat revision. These inputs must come from the
trusted host, never the requesting client. It also rechecks readiness, capacity and
revision; it does not
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

## Connected field-loop expansion

Added `field_loop_contract.py` and `test_field_loop_contract.py` in this same reference
lane, importing the existing encounter validation helpers rather than introducing a
second relationship implementation. Run both suites with:

```sh
python3 -m unittest -v
python3 -O -m unittest -v
```

Implemented offline references: authored cyclic weather phase lookup; bounded immutable
strain snapshot updates with stale/duplicate rejection; deterministic legal-action
selection; telegraph/objective-guarded boss transitions; capped crop time progression
and a harvest-pending proposal; approved base/form invitation checks; read-only advice
with stale-data and refusal handling. Includes a bridge from actual ceremony reference
readiness to late refusal, and one shared storm-state scenario across advice/AI/farming.

Host snapshots/registries here are trusted test inputs, not client claims. Required
form gates are supplied by species data; fixture gates are not universal Growth Rite
requirements. Strain costs and crop times use bounded integer fixture ticks/units,
not final game tuning. The weather loop is an authored schedule, not a forecast engine.
AI returns an action label, not a path, animation, technique execution or attack.

`StrainSnapshot` rejects a seen event ID rather than silently succeeding because this
bounded fixture does not retain payload/result receipts. At 1024 events it refuses
further updates. Production needs the existing owner's durable, payload-aware receipt
and checkpoint policy. The reference must never become an unbounded in-memory ledger.

Plots retain a time cursor to discard excluded drought/hazard/offline time. This does
not integrate a weather history: native progression must segment intervals at actual
weather/care/soil transitions rather than apply the current flag retroactively. The
caller supplies approved crop/plot records and host time; this fixture checks record
shape, not crop-registry membership. Harvest produces no item; `harvest_pending` must
be transacted with inventory in the existing owner and rolled back/reconciled there.

Form readiness returns only an invitation state. It cannot mutate a form, grant a
Dex record or write a reward. Boss resolution likewise awards nothing. Care advice
cannot create a bond. Native partner AI, behavior trees, actor spawning, databases,
UMG, animations, meshes, FX, weather visuals, multiplayer and save recovery remain
unimplemented by this reference.

Local follow-up evidence: 34 added unittest methods plus the existing 23 encounter
methods passed normally and under Python `-O` (57 per run). Existing battle reference:
24 methods passed. These are offline checks, not 81 implemented game systems or UE
Automation tests. Hosted Actions reports its own run status. No Windows/Unreal proof.

2026-10-18 correction evidence: five invalid acceptance subcases reproduced before
the commit check correction (species/fingerprint tampering and same-revision
weather/purity/biome changes). Added five test methods, including host-input changes,
required-input failure and population-order canonicalization. Full encounter/matrix/
field suite: 70 methods passed normally and under optimization; battle: 24 passed.
No durable spawn reservation, transaction or runtime implementation is established.

