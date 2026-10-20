"""Behavioral regressions for offline contracts, not native engine verification."""
from dataclasses import replace
import unittest
from encounter_contract import Rejected, Ceremony, Evidence, transition, BondReviewLedger
from field_loop_contract import (
    WeatherPhase, weather_at, StrainSnapshot, apply_strain,
    ActionOption, select_action, BossSnapshot, advance_boss,
    PlotSnapshot, advance_plot, request_harvest, form_readiness, advice_for,
)


class FieldLoopTests(unittest.TestCase):
    def test_strain_revision_exhaustion_is_explicit_without_mutation(self):
        state = StrainSnapshot("fixture.partner", 20, 100, 2**31 - 2)
        last = apply_strain(state, "last.event", 1, state.revision)
        self.assertEqual(last.revision, 2**31 - 1)
        with self.assertRaisesRegex(Rejected, "^revision_exhausted$"):
            apply_strain(last, "next.event", 1, last.revision)
        self.assertEqual(last.amount, 21)
        self.assertNotIn("next.event", last.events)

    def test_boss_revision_exhaustion_never_wraps(self):
        state = BossSnapshot("fixture.boss", "warning", 2**31 - 2)
        last = advance_boss(state, "respond", state.revision, True, False, True)
        with self.assertRaisesRegex(Rejected, "^revision_exhausted$"):
            advance_boss(last, "stabilize", last.revision, True, True, True)
        self.assertEqual((last.phase, last.revision), ("response", 2**31 - 1))

    def test_plot_at_max_revision_allows_read_only_retry(self):
        state = PlotSnapshot("fixture.plot", "fixture.crop", 0, 10, 0, 2**31 - 2)
        last = advance_plot(state, 1, 10, True, True, False)
        self.assertIs(advance_plot(last, 1, 10, True, True, False), last)
        with self.assertRaisesRegex(Rejected, "^revision_exhausted$"):
            advance_plot(last, 2, 10, True, True, False)

    def test_harvest_at_max_revision_does_not_reserve(self):
        ripe = PlotSnapshot("fixture.plot", "fixture.crop", 10, 10, 10, 2**31 - 1, "ready")
        with self.assertRaisesRegex(Rejected, "^revision_exhausted$"):
            request_harvest(ripe, ripe.revision, True)
        self.assertEqual(ripe.phase, "ready")

    def test_ceremony_revision_exhaustion_does_not_authorize_bond(self):
        state = Ceremony("fixture.encounter", "fixture.player", "fixture.individual", "calm", 2**31 - 2)
        snapshot = Evidence(state.individual_id, state.revision, True, True, True, True, False, True, True)
        last = transition(state, "invite", snapshot)
        with self.assertRaisesRegex(Rejected, "^revision_exhausted$"):
            transition(last, "accept", replace(snapshot, revision=last.revision))
        self.assertEqual(last.phase, "invited")

    def setUp(self):
        self.weather = (WeatherPhase("fair", 10), WeatherPhase("storm", 5, True))
        self.strain = StrainSnapshot("fixture.partner", 20, 100)
        self.plot = PlotSnapshot("fixture.plot", "fixture.crop", 0, 10, 0)
        self.registry = frozenset({("fixture.base", "fixture.shimmer")})
        self.gates = frozenset({"ecology", "relationship", "story", "care"})

    def choose(self, options, **kw):
        args = dict(target_known=True, sight_confirmed=True, healing=False, ceremony=False, unsafe=False)
        args.update(kw)
        return select_action(options, **args)

    def form(self, **kw):
        args = dict(base_id="fixture.base", form_id="fixture.shimmer", registry=self.registry,
                    required_gates=self.gates, observed_gates=self.gates, consent=True, healing=False)
        args.update(kw)
        return form_readiness(**args)

    def advice(self, **kw):
        args = dict(observed_tick=0, now=5, max_age=10, emergency=False, consent=True, hazard=False, known=True)
        args.update(kw)
        return advice_for(**args)

    def test_weather_exact_boundary_and_rejoin(self):
        self.assertEqual(weather_at(self.weather, 0, 9).phase_id, "fair")
        self.assertEqual(weather_at(self.weather, 0, 10).phase_id, "storm")
        self.assertEqual(weather_at(self.weather, 0, 10), weather_at(self.weather, 0, 10))
        self.assertEqual(weather_at(self.weather, 0, 15).cycle, 1)
        self.assertEqual(weather_at(self.weather, 0, 15).phase_id, "fair")

    def test_weather_large_gap_is_bounded_lookup(self):
        snapshot = weather_at(self.weather, 0, 10**12)
        self.assertEqual((snapshot.phase_id, snapshot.elapsed, snapshot.cycle), ("storm", 0, (10**12) // 15))

    def test_weather_invalid_duration_duplicate_and_empty(self):
        for phases in [(), (WeatherPhase("x", 0),), (WeatherPhase("x", 2), WeatherPhase("x", 3))]:
            with self.subTest(phases=phases), self.assertRaises(Rejected):
                weather_at(phases, 0, 0)

    def test_weather_clock_validation(self):
        for now in [True, -1, 1.0, float("nan"), 2**54]:
            with self.subTest(now=now), self.assertRaises(Rejected):
                weather_at(self.weather, 0, now)
        with self.assertRaises(Rejected):
            weather_at(self.weather, 4, 3)

    def test_weather_schedule_overflow(self):
        with self.assertRaises(Rejected):
            weather_at((WeatherPhase("a", 2**53 - 1), WeatherPhase("b", 1)), 0, 0)

    def test_strain_budget_refuses_without_mutation(self):
        with self.assertRaises(Rejected):
            apply_strain(self.strain, "hit.1", 81, 0)
        self.assertEqual(self.strain.amount, 20)
        self.assertEqual(self.strain.events, frozenset())

    def test_strain_duplicate_does_not_double_apply(self):
        changed = apply_strain(self.strain, "hit.1", 10, 0)
        with self.assertRaisesRegex(Rejected, "duplicate"):
            apply_strain(changed, "hit.1", 10, 0)
        self.assertEqual(changed.amount, 30)

    def test_strain_stale_and_oversized_inputs(self):
        with self.assertRaisesRegex(Rejected, "stale"):
            apply_strain(self.strain, "hit.1", 1, 1)
        for delta in [True, float("inf"), float("nan"), 10**1000]:
            with self.subTest(delta_type=type(delta)), self.assertRaises(Rejected):
                apply_strain(self.strain, "hit.1", delta, 0)

    def test_strain_recovery_never_goes_negative(self):
        self.assertEqual(apply_strain(self.strain, "rest.1", -20, 0).amount, 0)
        with self.assertRaises(Rejected):
            apply_strain(self.strain, "rest.1", -21, 0)

    def test_strain_zero_event_does_not_refund_charge(self):
        changed = apply_strain(self.strain, "recall.1", 0, 0)
        self.assertEqual(changed.amount, self.strain.amount)
        self.assertFalse(hasattr(changed, "device_charge"))

    def test_strain_history_full_fails_closed(self):
        state = replace(self.strain, events=frozenset(f"event.{i}" for i in range(1024)))
        with self.assertRaisesRegex(Rejected, "history_full"):
            apply_strain(state, "new.event", 1, 0)

    def test_ai_rejects_impossible_high_score_attack(self):
        options = (ActionOption("attack", 9999, True, True, True, True, True),
                   ActionOption("guard", 1, True, True, True))
        self.assertEqual(self.choose(options, sight_confirmed=False), "guard")
        self.assertEqual(self.choose(options, target_known=False), "guard")

    def test_ai_filters_permission_navigation_cooldown(self):
        for fields in [(False, True, True), (True, False, True), (True, True, False)]:
            with self.subTest(fields=fields):
                self.assertEqual(self.choose((ActionOption("attack", 99, *fields),)), "hold")

    def test_ai_preserves_welfare_and_ceremony(self):
        options = (ActionOption("attack", 99, True, True, True),)
        self.assertEqual(self.choose(options, healing=True), "defer")
        self.assertEqual(self.choose(options, ceremony=True), "defer")
        self.assertEqual(self.choose(options, unsafe=True), "seek_safety")

    def test_ai_ties_ignore_input_order(self):
        options = (ActionOption("guard", 2, True, True, True), ActionOption("cover", 2, True, True, True))
        self.assertEqual(self.choose(options), "cover")
        self.assertEqual(self.choose(tuple(reversed(options))), "cover")

    def test_ai_duplicate_and_nonfinite_scores_rejected(self):
        action = ActionOption("guard", 2, True, True, True)
        for options in [(action, action), (replace(action, utility=float("nan")),)]:
            with self.subTest(options=options), self.assertRaises(Rejected):
                self.choose(options)

    def test_boss_cannot_skip_telegraph(self):
        state = BossSnapshot("fixture.boss")
        warning = advance_boss(state, "activate", 0, True, False, False)
        with self.assertRaisesRegex(Rejected, "telegraph"):
            advance_boss(warning, "respond", 1, True, False, False)
        with self.assertRaisesRegex(Rejected, "sequence"):
            advance_boss(warning, "resolve", 1, True, True, True)

    def test_boss_full_restoration_sequence(self):
        state = BossSnapshot("fixture.boss")
        for action in ("activate", "respond", "stabilize", "resolve"):
            state = advance_boss(state, action, state.revision, True, True, True)
        self.assertEqual(state.phase, "resolved")
        self.assertFalse(hasattr(state, "reward"))
        with self.assertRaisesRegex(Rejected, "terminal"):
            advance_boss(state, "resolve", state.revision, True, True, True)

    def test_boss_abort_is_terminal(self):
        state = advance_boss(BossSnapshot("fixture.boss"), "activate", 0, False, False, False)
        self.assertEqual(state.phase, "aborted")
        with self.assertRaises(Rejected):
            advance_boss(state, "activate", 1, True, True, True)

    def test_boss_stale_revision_and_unfinished_objective(self):
        state = BossSnapshot("fixture.boss", "response", 2)
        with self.assertRaisesRegex(Rejected, "stale"):
            advance_boss(state, "stabilize", 1, True, True, True)
        with self.assertRaisesRegex(Rejected, "incomplete"):
            advance_boss(state, "stabilize", 2, True, False, True)

    def test_farming_offline_cap_discards_excess_elapsed(self):
        changed = advance_plot(self.plot, 1000, 3, True, True, False)
        self.assertEqual((changed.elapsed, changed.last_tick), (3, 1000))
        same = advance_plot(changed, 1000, 3, True, True, False)
        self.assertEqual(same, changed)
        self.assertEqual(advance_plot(changed, 1001, 3, True, True, False).elapsed, 4)

    def test_farming_drought_and_hazard_do_not_bank_growth(self):
        for soil, water, hazard in [(False, True, False), (True, False, False), (True, True, True)]:
            with self.subTest(soil=soil, water=water, hazard=hazard):
                dry = advance_plot(self.plot, 5, 10, soil, water, hazard)
                self.assertEqual(dry.elapsed, 0)
                wet = advance_plot(dry, 6, 10, True, True, False)
                self.assertEqual(wet.elapsed, 1)

    def test_farming_rejects_clock_rollback(self):
        with self.assertRaises(Rejected):
            advance_plot(replace(self.plot, last_tick=10), 9, 3, True, True, False)

    def test_farming_invalid_time_and_state(self):
        for bad in [replace(self.plot, duration=0), replace(self.plot, elapsed=11),
                    replace(self.plot, phase="ready"), replace(self.plot, last_tick=True)]:
            with self.subTest(bad=bad), self.assertRaises(Rejected):
                advance_plot(bad, 10, 10, True, True, False)

    def test_harvest_reservation_is_not_inventory_award(self):
        ripe = advance_plot(self.plot, 10, 10, True, True, False)
        pending = request_harvest(ripe, ripe.revision, True)
        self.assertEqual(pending.phase, "harvest_pending")
        self.assertEqual(pending.crop_id, self.plot.crop_id)
        self.assertFalse(hasattr(pending, "inventory"))
        with self.assertRaises(Rejected):
            request_harvest(pending, pending.revision, True)

    def test_harvest_failure_leaves_crop_ready(self):
        ripe = advance_plot(self.plot, 10, 10, True, True, False)
        for revision, available in [(0, True), (ripe.revision, False)]:
            with self.subTest(revision=revision, available=available), self.assertRaises(Rejected):
                request_harvest(ripe, revision, available)
        self.assertEqual(ripe.phase, "ready")

    def test_form_every_missing_gate_is_denied(self):
        for gate in self.gates:
            with self.subTest(gate=gate):
                self.assertEqual(self.form(observed_gates=self.gates - {gate}), "requirements_unmet")

    def test_form_refusal_healing_and_identity_preserved(self):
        self.assertEqual(self.form(consent=False), "partner_declined")
        self.assertEqual(self.form(healing=True), "healing_withdrawal")
        self.assertEqual(self.form(), "invitation_ready")
        self.assertEqual(self.registry, frozenset({("fixture.base", "fixture.shimmer")}))

    def test_form_unknown_pair_empty_requirements_rejected(self):
        for kw in [dict(base_id="other.base"), dict(form_id="other.form"), dict(required_gates=frozenset())]:
            with self.subTest(kw=kw), self.assertRaises(Rejected):
                self.form(**kw)

    def test_dahlia_fresh_refusal_cannot_be_overridden(self):
        self.assertEqual(self.advice(consent=False), "respect_refusal")
        self.assertEqual(self.advice(hazard=True), "wait_for_safe_approach")

    def test_dahlia_stale_unknown_and_future_readings(self):
        self.assertEqual(self.advice(now=11), "reading_unavailable")
        self.assertEqual(self.advice(known=False), "reading_unavailable")
        with self.assertRaises(Rejected):
            self.advice(observed_tick=6)

    def test_dahlia_emergency_care_is_not_bonding(self):
        self.assertEqual(self.advice(emergency=True, known=False, consent=False), "seek_safe_care")

    def test_encounter_kindling_and_advice_share_refusal(self):
        state = Ceremony("fixture.encounter", "fixture.player", "fixture.individual")
        evidence = Evidence("fixture.individual", 0, True, True, True, True, False, True, True)
        for action in ("observe", "protect", "calm", "invite", "accept"):
            state = transition(state, action, replace(evidence, revision=state.revision))
        self.assertEqual(state.phase, "bond_ready")
        refused = replace(evidence, revision=state.revision, consent=False)
        self.assertEqual(self.advice(consent=refused.consent), "respect_refusal")
        with self.assertRaises(Rejected):
            BondReviewLedger().commit(state, refused)
        self.assertEqual(transition(state, "refuse", refused).phase, "refused")

    def test_connected_storm_recovery_loop(self):
        # One deterministic host snapshot drives multiple consumers consistently.
        storm = weather_at(self.weather, 0, 10)
        self.assertEqual(self.advice(hazard=storm.hazard), "wait_for_safe_approach")
        self.assertEqual(self.choose((), unsafe=storm.hazard), "seek_safety")
        self.assertEqual(advance_plot(self.plot, 10, 10, True, True, storm.hazard).elapsed, 0)
        strained = apply_strain(self.strain, "storm.exposure.1", 10, 0)
        rested = apply_strain(strained, "safe.rest.1", -10, 1)
        self.assertEqual(rested.amount, self.strain.amount)
        self.assertEqual(self.form(consent=False), "partner_declined")


if __name__ == "__main__":
    unittest.main()

