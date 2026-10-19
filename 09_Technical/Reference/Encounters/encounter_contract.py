"""Offline encounter/Kindling oracle. No actor spawning or real relationship writes."""
from dataclasses import dataclass, replace
import hashlib
import json
import math
import re
import struct


class Rejected(ValueError):
    pass


def require(condition, reason):
    if not condition:
        raise Rejected(reason)


def ident(value):
    return type(value) is str and re.fullmatch(r"[A-Za-z0-9_.:-]{1,96}", value) is not None


def integer(value, maximum):
    return type(value) is int and 0 <= value <= maximum


def unit(value):
    return type(value) in (float, int) and 0 <= value <= 1 and math.isfinite(value)


@dataclass(frozen=True)
class Habitat:
    cell_id: str
    biome: str
    weather: str
    day_phase: str
    revision: int
    ready: bool
    spawn_safe: bool
    purity: float
    capacity: int
    active_instances: tuple[str, ...]


@dataclass(frozen=True)
class Candidate:
    species_id: str
    biomes: tuple[str, ...]
    weather: tuple[str, ...]
    day_phases: tuple[str, ...]
    minimum_purity: float
    weight: int


@dataclass(frozen=True)
class SpawnProposal:
    cell_id: str
    expected_revision: int
    species_id: str
    fingerprint: str


def _spawn_fingerprint(habitat, allowed, seed):
    """Version 1 canonical hash input, after propose_spawn has validated values.

    Tag lists are membership sets; population and candidates have stable ordering.
    IEEE binary64 big-endian hex normalizes int/float and both zero signs without
    rounding distinct finite values. This is a reference hash, not a wire protocol.
    """
    def unit_bits(value):
        return struct.pack(">d", 0.0 if value == 0 else float(value)).hex()

    payload = ["Echohearts.SpawnProposal", 1,
               [habitat.cell_id, habitat.biome, habitat.weather, habitat.day_phase,
                habitat.revision, habitat.ready, habitat.spawn_safe,
                unit_bits(habitat.purity), habitat.capacity,
                sorted(habitat.active_instances)],
               [[c.species_id, sorted(set(c.biomes)), sorted(set(c.weather)),
                 sorted(set(c.day_phases)), unit_bits(c.minimum_purity), c.weight]
                for c in allowed], seed]
    encoded = json.dumps(payload, ensure_ascii=True, separators=(",", ":"),
                         allow_nan=False).encode("ascii")
    return hashlib.sha256(encoded).hexdigest()


def propose_spawn(habitat, candidates, approved_species, seed):
    require(type(habitat) is Habitat, "invalid_habitat")
    require(all(ident(x) for x in (habitat.cell_id, habitat.biome, habitat.weather, habitat.day_phase)), "invalid_identity")
    require(integer(habitat.revision, 2**31-1) and integer(seed, 2**31-1), "invalid_revision_or_seed")
    require(unit(habitat.purity) and integer(habitat.capacity, 64), "invalid_habitat_bounds")
    require(type(habitat.active_instances) is tuple and all(ident(x) for x in habitat.active_instances), "invalid_population")
    require(len(set(habitat.active_instances)) == len(habitat.active_instances), "duplicate_individual")
    require(habitat.ready is True and habitat.spawn_safe is True, "cell_unavailable")
    require(len(habitat.active_instances) < habitat.capacity, "population_full")
    require(type(candidates) is tuple and len(candidates) <= 128, "invalid_candidates")
    require(type(approved_species) is frozenset and all(ident(x) for x in approved_species), "invalid_registry")
    allowed, seen = [], set()
    for candidate in candidates:
        require(type(candidate) is Candidate and ident(candidate.species_id), "invalid_candidate")
        require(candidate.species_id not in seen, "duplicate_candidate")
        seen.add(candidate.species_id)
        require(candidate.species_id in approved_species, "unapproved_species")
        require(unit(candidate.minimum_purity) and integer(candidate.weight, 10000) and candidate.weight > 0, "invalid_candidate_bounds")
        for values in (candidate.biomes, candidate.weather, candidate.day_phases):
            require(type(values) is tuple and 1 <= len(values) <= 32 and all(ident(x) for x in values), "invalid_candidate_tags")
        if (habitat.biome in candidate.biomes and habitat.weather in candidate.weather
            and habitat.day_phase in candidate.day_phases and habitat.purity >= candidate.minimum_purity):
            allowed.append(candidate)
    require(bool(allowed), "no_eligible_species")
    allowed.sort(key=lambda x: x.species_id)
    digest = _spawn_fingerprint(habitat, allowed, seed)
    pick = int(digest, 16) % sum(x.weight for x in allowed)
    for candidate in allowed:
        if pick < candidate.weight:
            return SpawnProposal(habitat.cell_id, habitat.revision, candidate.species_id, digest)
        pick -= candidate.weight
    raise Rejected("selection_failed")


def validate_spawn_commit(proposal, current, *, candidates, approved_species, seed):
    """Recompute from current trusted host inputs; a digest is not authorization.

    Native integration must keep validation and population reservation atomic and
    resolve these inputs on the host, never from a client's proposed registry/seed.
    This pure check neither consumes a proposal nor prevents replay on its own.
    """
    require(type(proposal) is SpawnProposal and type(current) is Habitat, "invalid_proposal")
    require(integer(proposal.expected_revision, 2**31-1) and integer(current.revision, 2**31-1), "invalid_revision")
    require(current.cell_id == proposal.cell_id and current.revision == proposal.expected_revision, "stale_spawn")
    require(current.ready is True and current.spawn_safe is True, "cell_unavailable")
    require(integer(current.capacity, 64) and type(current.active_instances) is tuple,
            "invalid_population")
    require(all(ident(x) for x in current.active_instances)
            and len(set(current.active_instances)) == len(current.active_instances), "invalid_population")
    require(len(current.active_instances) < current.capacity, "population_full")
    expected = propose_spawn(current, candidates, approved_species, seed)
    require(proposal == expected, "spawn_proposal_mismatch")
    return True


@dataclass(frozen=True)
class Evidence:
    """Trusted host evidence, not client-supplied permission flags."""
    individual_id: str
    revision: int
    observed: bool
    protected: bool
    calm: bool
    consent: bool
    healing: bool
    safe: bool
    eligible: bool


@dataclass(frozen=True)
class Ceremony:
    encounter_id: str
    owner_id: str
    individual_id: str
    phase: str = "encountered"
    revision: int = 0


def transition(state, action, evidence):
    require(type(state) is Ceremony and type(evidence) is Evidence, "invalid_ceremony")
    require(all(ident(x) for x in (state.encounter_id, state.owner_id, state.individual_id)), "invalid_identity")
    require(integer(state.revision, 2**31-2) and integer(evidence.revision, 2**31-2), "invalid_revision")
    require(evidence.individual_id == state.individual_id and evidence.revision == state.revision, "stale_evidence")
    require(type(action) is str and action in {"observe", "protect", "calm", "invite", "accept", "refuse", "release", "defer", "interrupt"}, "unknown_action")
    for flag in (evidence.observed, evidence.protected, evidence.calm, evidence.consent,
                 evidence.healing, evidence.safe, evidence.eligible):
        require(type(flag) is bool, "invalid_evidence")
    require(type(state.phase) is str and state.phase in {"encountered", "observed", "protected", "calm", "invited", "bond_ready"}, "terminal_or_invalid_phase")
    if action in {"refuse", "release", "defer", "interrupt"}:
        phase = {"refuse": "refused", "release": "released", "defer": "deferred", "interrupt": "deferred"}[action]
        return replace(state, phase=phase, revision=state.revision+1)
    require(evidence.safe and not evidence.healing and evidence.eligible, "not_safe_to_proceed")
    expected = {"encountered": "observe", "observed": "protect", "protected": "calm", "calm": "invite", "invited": "accept"}
    require(expected.get(state.phase) == action, "wrong_sequence")
    if action == "observe":
        require(evidence.observed, "observation_missing")
    if action == "protect":
        require(evidence.observed and evidence.protected, "protection_missing")
    if action in {"calm", "invite", "accept"}:
        require(evidence.observed and evidence.protected and evidence.calm, "calm_evidence_missing")
    if action in {"invite", "accept"}:
        require(evidence.consent, "consent_required")
    phase = {"observe": "observed", "protect": "protected", "calm": "calm", "invite": "invited", "accept": "bond_ready"}[action]
    return replace(state, phase=phase, revision=state.revision+1)


class BondReviewLedger:
    """Single-process proposal idempotency; never writes the actual bond service."""
    def __init__(self):
        self._by_individual = {}

    def commit(self, state, evidence):
        require(type(state) is Ceremony and state.phase == "bond_ready", "bond_not_ready")
        require(type(evidence) is Evidence and evidence.individual_id == state.individual_id
                and evidence.revision == state.revision, "stale_evidence")
        require(integer(state.revision, 2**31-1) and type(evidence.revision) is int, "invalid_revision")
        require(all(ident(x) for x in (state.owner_id, state.individual_id, state.encounter_id)), "invalid_identity")
        require(all(x is True for x in (evidence.observed, evidence.protected, evidence.calm,
                                       evidence.consent, evidence.safe, evidence.eligible))
                and evidence.healing is False, "bond_not_authorized")
        identity = (state.owner_id, state.encounter_id)
        previous = self._by_individual.get(state.individual_id)
        if previous is not None:
            require(previous == identity, "individual_already_resolved")
            return None
        self._by_individual[state.individual_id] = identity
        return ("bond_review", state.owner_id, state.individual_id, state.encounter_id)


