"""Offline field-loop acceptance reference. No UE actors, saves, rewards or bonds.

All inputs describe a trusted host snapshot in tests, never client permissions.
Time uses integer host ticks. Numeric caps are fixture limits, not game balance.
"""
from dataclasses import dataclass, replace
from encounter_contract import Rejected, require, ident, integer, MAX_REVISION, next_revision


MAX_TICK = 2**53 - 1


def tick(value):
    return integer(value, MAX_TICK)


def flags(*values):
    require(all(type(x) is bool for x in values), "invalid_flags")


@dataclass(frozen=True)
class WeatherPhase:
    phase_id: str
    duration: int
    hazard: bool = False


@dataclass(frozen=True)
class WeatherSnapshot:
    phase_id: str
    cycle: int
    elapsed: int
    hazard: bool


def weather_at(phases, epoch, now):
    require(type(phases) is tuple and 1 <= len(phases) <= 16, "invalid_weather_schedule")
    require(tick(epoch) and tick(now) and now >= epoch, "invalid_clock")
    seen = set()
    for phase in phases:
        require(type(phase) is WeatherPhase and ident(phase.phase_id), "invalid_weather_phase")
        require(phase.phase_id not in seen, "duplicate_weather_phase")
        seen.add(phase.phase_id)
        require(integer(phase.duration, MAX_TICK) and phase.duration > 0, "invalid_weather_duration")
        flags(phase.hazard)
    total = sum(p.duration for p in phases)
    require(total <= MAX_TICK, "weather_cycle_overflow")
    cycle, offset = divmod(now - epoch, total)
    for phase in phases:
        if offset < phase.duration:
            return WeatherSnapshot(phase.phase_id, cycle, offset, phase.hazard)
        offset -= phase.duration
    raise Rejected("weather_selection_failed")


@dataclass(frozen=True)
class StrainSnapshot:
    subject_id: str
    amount: int
    capacity: int
    revision: int = 0
    events: frozenset[str] = frozenset()


def apply_strain(state, event_id, delta, expected_revision):
    """Pure snapshot return; real Anima-Link owner must transact and persist it."""
    require(type(state) is StrainSnapshot and ident(state.subject_id) and ident(event_id), "invalid_strain_identity")
    require(integer(state.capacity, 10**6) and state.capacity > 0
            and integer(state.amount, state.capacity), "invalid_strain_bounds")
    require(integer(state.revision, MAX_REVISION) and integer(expected_revision, MAX_REVISION), "invalid_revision")
    require(type(state.events) is frozenset and len(state.events) <= 1024
            and all(ident(x) for x in state.events), "invalid_strain_history")
    require(type(delta) is int and -state.capacity <= delta <= state.capacity, "invalid_strain_delta")
    # Exact retry on the original revision is allowed only for an identical payload.
    # This fixture does not store payloads, so callers must reject duplicates outright.
    require(event_id not in state.events, "duplicate_strain_event")
    require(expected_revision == state.revision, "stale_strain")
    require(len(state.events) < 1024, "strain_history_full")
    next_amount = state.amount + delta
    require(0 <= next_amount <= state.capacity, "strain_budget_exceeded")
    return replace(state, amount=next_amount, revision=next_revision(state.revision), events=state.events | {event_id})


@dataclass(frozen=True)
class ActionOption:
    action_id: str
    utility: int
    permitted: bool
    reachable: bool
    cooldown_ready: bool
    requires_target: bool = False
    requires_sight: bool = False


def select_action(options, target_known, sight_confirmed, healing, ceremony, unsafe):
    flags(target_known, sight_confirmed, healing, ceremony, unsafe)
    require(type(options) is tuple and len(options) <= 32, "invalid_action_options")
    seen, valid = set(), []
    for option in options:
        require(type(option) is ActionOption and ident(option.action_id), "invalid_action")
        require(option.action_id not in seen, "duplicate_action")
        seen.add(option.action_id)
        require(type(option.utility) is int and -10000 <= option.utility <= 10000, "invalid_utility")
        flags(option.permitted, option.reachable, option.cooldown_ready, option.requires_target, option.requires_sight)
        if (option.permitted and option.reachable and option.cooldown_ready
            and (not option.requires_target or target_known)
            and (not option.requires_sight or sight_confirmed)):
            valid.append(option)
    if healing or ceremony:
        return "defer"
    if unsafe:
        return "seek_safety"  # Intent only; a native navigation query still owns the route.
    if not valid:
        return "hold"
    return sorted(valid, key=lambda x: (-x.utility, x.action_id))[0].action_id


@dataclass(frozen=True)
class BossSnapshot:
    encounter_id: str
    phase: str = "dormant"
    revision: int = 0


def advance_boss(state, action, expected_revision, safe, objective_complete, telegraph_elapsed):
    require(type(state) is BossSnapshot and ident(state.encounter_id), "invalid_boss")
    require(integer(state.revision, MAX_REVISION) and integer(expected_revision, MAX_REVISION), "invalid_revision")
    require(expected_revision == state.revision, "stale_boss_phase")
    flags(safe, objective_complete, telegraph_elapsed)
    require(type(state.phase) is str and state.phase in {"dormant", "warning", "response", "recovery", "resolved", "aborted"}, "invalid_boss_phase")
    require(type(action) is str and action in {"activate", "respond", "stabilize", "resolve", "abort"}, "invalid_boss_action")
    require(state.phase not in {"resolved", "aborted"}, "terminal_boss_phase")
    if action == "abort" or not safe:
        return replace(state, phase="aborted", revision=next_revision(state.revision))
    required = {"dormant": "activate", "warning": "respond", "response": "stabilize", "recovery": "resolve"}
    require(required.get(state.phase) == action, "wrong_boss_sequence")
    if action == "respond":
        require(telegraph_elapsed, "boss_telegraph_active")
    if action in {"stabilize", "resolve"}:
        require(objective_complete, "boss_objective_incomplete")
    next_phase = {"activate": "warning", "respond": "response", "stabilize": "recovery", "resolve": "resolved"}[action]
    return replace(state, phase=next_phase, revision=next_revision(state.revision))


@dataclass(frozen=True)
class PlotSnapshot:
    plot_id: str
    crop_id: str
    elapsed: int
    duration: int
    last_tick: int
    revision: int = 0
    phase: str = "growing"


def validate_plot(state):
    require(type(state) is PlotSnapshot and ident(state.plot_id) and ident(state.crop_id), "invalid_plot_identity")
    require(integer(state.duration, MAX_TICK) and state.duration > 0
            and integer(state.elapsed, state.duration) and tick(state.last_tick), "invalid_plot_time")
    require(integer(state.revision, MAX_REVISION), "invalid_revision")
    require(type(state.phase) is str and state.phase in {"growing", "ready", "harvest_pending"}, "invalid_plot_phase")
    require((state.phase == "growing" and state.elapsed < state.duration)
            or (state.phase in {"ready", "harvest_pending"} and state.elapsed == state.duration), "inconsistent_plot_phase")


def advance_plot(state, now, offline_cap, soil_ok, water_ok, hazard):
    validate_plot(state)
    require(tick(now) and now >= state.last_tick and tick(offline_cap), "invalid_plot_clock")
    flags(soil_ok, water_ok, hazard)
    require(state.phase == "growing", "plot_not_growing")
    if now == state.last_tick:
        return state
    delta = min(now - state.last_tick, offline_cap) if soil_ok and water_ok and not hazard else 0
    elapsed = min(state.duration, state.elapsed + delta)
    return replace(state, elapsed=elapsed, last_tick=now, revision=next_revision(state.revision),
                   phase="ready" if elapsed == state.duration else "growing")


def request_harvest(state, expected_revision, inventory_ready):
    validate_plot(state)
    flags(inventory_ready)
    require(integer(expected_revision, MAX_REVISION) and expected_revision == state.revision, "stale_plot")
    require(state.phase == "ready", "crop_not_ready")
    require(inventory_ready, "inventory_unavailable")
    # No inventory award: actual owner must atomically persist reservation plus grant.
    return replace(state, phase="harvest_pending", revision=next_revision(state.revision))


def form_readiness(base_id, form_id, registry, required_gates, observed_gates, consent, healing):
    require(ident(base_id) and ident(form_id), "invalid_form_identity")
    require(type(registry) is frozenset and len(registry) <= 4096, "invalid_form_registry")
    for record in registry:
        require(type(record) is tuple and len(record) == 2 and all(ident(x) for x in record), "invalid_form_registry")
    require((base_id, form_id) in registry, "unapproved_base_form")
    require(type(required_gates) is frozenset and 1 <= len(required_gates) <= 32
            and all(ident(x) for x in required_gates), "invalid_required_gates")
    require(type(observed_gates) is frozenset and len(observed_gates) <= 32
            and all(ident(x) for x in observed_gates), "invalid_observed_gates")
    flags(consent, healing)
    if not consent:
        return "partner_declined"
    if healing:
        return "healing_withdrawal"
    if not required_gates <= observed_gates:
        return "requirements_unmet"
    return "invitation_ready"  # Not form commit, species creation or a reward.


def advice_for(observed_tick, now, max_age, emergency, consent, hazard, known):
    require(tick(observed_tick) and tick(now) and now >= observed_tick and tick(max_age), "invalid_advice_clock")
    flags(emergency, consent, hazard, known)
    if emergency:
        return "seek_safe_care"  # Welfare prompt never creates a bond.
    if not known or now - observed_tick > max_age:
        return "reading_unavailable"
    if not consent:
        return "respect_refusal"
    if hazard:
        return "wait_for_safe_approach"
    return "observe_without_pressure"

