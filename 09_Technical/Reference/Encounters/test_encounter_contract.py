from dataclasses import replace
import math
import unittest
from encounter_contract import (Habitat, Candidate, Ceremony, Evidence, Rejected,
    propose_spawn, validate_spawn_commit, transition, BondReviewLedger)


def habitat(**changes):
    return replace(Habitat("cell:fixture", "biome:fixture", "clear", "day", 1,
                           True, True, .8, 2, ()), **changes)


def candidate(**changes):
    return replace(Candidate("species:fixture", ("biome:fixture",), ("clear",),
                             ("day",), .5, 1), **changes)


def evidence(state, **changes):
    return replace(Evidence(state.individual_id, state.revision, True, True, True,
                            True, False, True, True), **changes)


def ready():
    state = Ceremony("encounter:fixture", "owner:fixture", "individual:fixture")
    for action in ("observe", "protect", "calm", "invite", "accept"):
        state = transition(state, action, evidence(state))
    return state


class EncounterTests(unittest.TestCase):
    def proposal(self, h=None, cs=None, approved=frozenset({"species:fixture"}), seed=7):
        return propose_spawn(h or habitat(), (candidate(),) if cs is None else cs, approved, seed)

    def commit(self, proposal, current, **changes):
        host = dict(candidates=(candidate(),), approved_species=frozenset({"species:fixture"}), seed=7)
        host.update(changes)
        return validate_spawn_commit(proposal, current, **host)

    def test_commit_rechecks_host_registry_seed_and_candidates(self):
        for change in (dict(approved_species=frozenset()), dict(seed=8),
                       dict(candidates=(candidate(weight=2),))):
            with self.subTest(change=change), self.assertRaises(Rejected):
                self.commit(self.proposal(), habitat(), **change)

    def test_commit_requires_trusted_inputs(self):
        with self.assertRaises(TypeError):
            validate_spawn_commit(self.proposal(), habitat())

    def test_commit_population_order_remains_canonical(self):
        current = habitat(capacity=4, active_instances=("a", "b"))
        proposal = self.proposal(h=current)
        self.assertTrue(self.commit(proposal, replace(current, active_instances=("b", "a"))))

    def test_determinism(self):
        self.assertEqual(self.proposal(), self.proposal())

    def test_numeric_representation_does_not_change_proposal(self):
        for first, second in ((0, 0.0), (1, 1.0), (0.0, -0.0)):
            with self.subTest(first=first, second=second):
                a = self.proposal(h=habitat(purity=first), cs=(candidate(minimum_purity=first),))
                b = self.proposal(h=habitat(purity=second), cs=(candidate(minimum_purity=second),))
                self.assertEqual(a, b)

    def test_candidate_tag_sets_have_canonical_order(self):
        a = candidate(biomes=("other", "biome:fixture"), weather=("clear", "storm"))
        b = replace(a, biomes=tuple(reversed(a.biomes)), weather=("storm", "clear", "clear"))
        self.assertEqual(self.proposal(cs=(a,)), self.proposal(cs=(b,)))

    def test_version_one_fixed_fingerprints(self):
        # Reviewed canonical preimage and digests are documented in README.md.
        self.assertEqual(self.proposal(seed=7).fingerprint,
                         "eabefd2eb1d94a21bff83b8f7ca4838ebb3724d0d995bc5ad4ee3252cc08e5cf")
        self.assertEqual(self.proposal(seed=8).fingerprint,
                         "b5c51e831a2de0152ee60a99fdd3c7210861e66a65bb044075c50c90df5b2290")

    def test_distinct_purity_bits_are_not_rounded_together(self):
        a = self.proposal(h=habitat(purity=.8))
        b = self.proposal(h=habitat(purity=math.nextafter(.8, 1.0)))
        self.assertNotEqual(a.fingerprint, b.fingerprint)
        with self.assertRaisesRegex(Rejected, "spawn_proposal_mismatch"):
            self.commit(a, habitat(purity=math.nextafter(.8, 1.0)))

    def test_equivalent_numeric_snapshot_survives_commit_revalidation(self):
        current = habitat(purity=1.0)
        proposal = self.proposal(h=habitat(purity=1))
        self.assertTrue(self.commit(proposal, current))

    def test_equivalent_snapshots_choose_same_weighted_species(self):
        a = candidate(minimum_purity=0, weather=("clear", "storm"))
        b = candidate(species_id="species:second", minimum_purity=1, weight=3)
        registry = frozenset({a.species_id, b.species_id})
        for seed in range(16):
            with self.subTest(seed=seed):
                first = self.proposal(h=habitat(purity=1), cs=(a, b), approved=registry, seed=seed)
                second = self.proposal(h=habitat(purity=1.0), cs=(
                    replace(b, minimum_purity=1.0),
                    replace(a, minimum_purity=-0.0, weather=("storm", "clear", "clear"))),
                    approved=registry, seed=seed)
                self.assertEqual(first, second)

    def test_candidate_order_independent(self):
        a, b = candidate(), candidate(species_id="species:second", weight=3)
        allowed = frozenset({a.species_id,b.species_id})
        self.assertEqual(self.proposal(cs=(a,b),approved=allowed), self.proposal(cs=(b,a),approved=allowed))

    def test_population_order_independent(self):
        self.assertEqual(self.proposal(h=habitat(capacity=4,active_instances=("a","b"))),
                         self.proposal(h=habitat(capacity=4,active_instances=("b","a"))))

    def test_unloaded_or_unsafe(self):
        for field in ("ready", "spawn_safe"):
            with self.assertRaisesRegex(Rejected, "cell_unavailable"):
                self.proposal(h=habitat(**{field:False}))

    def test_population_cap(self):
        with self.assertRaisesRegex(Rejected, "population_full"):
            self.proposal(h=habitat(active_instances=("a","b")))

    def test_duplicate_individual(self):
        with self.assertRaisesRegex(Rejected, "duplicate_individual"):
            self.proposal(h=habitat(active_instances=("a","a")))

    def test_unknown_species(self):
        with self.assertRaisesRegex(Rejected, "unapproved_species"):
            self.proposal(approved=frozenset())

    def test_habitat_filters(self):
        for change in ({"biome":"other"},{"weather":"storm"},{"day_phase":"night"},{"purity":.1}):
            with self.subTest(change=change), self.assertRaisesRegex(Rejected,"no_eligible_species"):
                self.proposal(h=habitat(**change))

    def test_candidate_bounds(self):
        for change in ({"weight":True},{"weight":0},{"weight":10001},{"minimum_purity":float('nan')},
                       {"minimum_purity":10**1000},
                       {"biomes":[]},{"species_id":"../bad"}):
            with self.subTest(change=change), self.assertRaises(Rejected):
                self.proposal(cs=(candidate(**change),))

    def test_duplicate_species(self):
        with self.assertRaisesRegex(Rejected, "duplicate_candidate"):
            self.proposal(cs=(candidate(),candidate()))

    def test_stale_commit(self):
        with self.assertRaisesRegex(Rejected, "stale_spawn"):
            self.commit(self.proposal(), habitat(revision=2))
        self.assertTrue(self.commit(self.proposal(), habitat()))

    def test_commit_capacity_rechecked(self):
        with self.assertRaisesRegex(Rejected, "population_full"):
            self.commit(self.proposal(), habitat(active_instances=("a","b")))

    def test_commit_rejects_tampered_species_and_fingerprint(self):
        proposal = self.proposal()
        for change in ({"species_id": "species:unapproved"}, {"fingerprint": "0" * 64}):
            with self.subTest(change=change), self.assertRaises(Rejected):
                self.commit(replace(proposal, **change), habitat())

    def test_commit_rechecks_same_revision_habitat_eligibility(self):
        for change in ({"weather": "storm"}, {"purity": .1}, {"biome": "other"}):
            with self.subTest(change=change), self.assertRaises(Rejected):
                self.commit(self.proposal(), habitat(**change))

    def test_revision_and_seed_types(self):
        for value in (True,-1,2**31,float('nan')):
            with self.assertRaises(Rejected): self.proposal(seed=value)

    def test_kindling_full_sequence(self):
        self.assertEqual(ready().phase,"bond_ready")

    def test_cannot_skip_sequence(self):
        state = Ceremony("encounter:fixture","owner:fixture","individual:fixture")
        with self.assertRaisesRegex(Rejected,"wrong_sequence"):
            transition(state,"accept",evidence(state))

    def test_no_fabricated_evidence(self):
        state = Ceremony("encounter:fixture","owner:fixture","individual:fixture")
        with self.assertRaisesRegex(Rejected,"observation_missing"):
            transition(state,"observe",evidence(state,observed=False))

    def test_ceremony_revocation_at_every_step(self):
        state = Ceremony("encounter:fixture","owner:fixture","individual:fixture")
        for action in ("observe","protect","calm","invite","accept"):
            refused = transition(state,"refuse",evidence(state,consent=False))
            self.assertEqual(refused.phase,"refused")
            state = transition(state,action,evidence(state))
        self.assertEqual(transition(state,"refuse",evidence(state,consent=False)).phase,"refused")

    def test_pending_bond_rechecks_consent_and_care(self):
        state=ready()
        for change in ({"consent":False},{"healing":True},{"safe":False},{"eligible":False}):
            with self.assertRaisesRegex(Rejected,"bond_not_authorized"):
                BondReviewLedger().commit(state,evidence(state,**change))

    def test_terminal_safety_outcomes(self):
        state=ready()
        for action,phase in (("release","released"),("defer","deferred"),("interrupt","deferred")):
            ended=transition(state,action,evidence(state))
            self.assertEqual(ended.phase,phase)
            with self.assertRaisesRegex(Rejected,"bond_not_ready"):
                BondReviewLedger().commit(ended,evidence(ended))

    def test_stale_or_wrong_individual(self):
        state=ready()
        for change in ({"revision":0},{"individual_id":"other"}):
            with self.assertRaisesRegex(Rejected,"stale_evidence"):
                BondReviewLedger().commit(state,evidence(state,**change))

    def test_duplicate_bond_review(self):
        state=ready(); ledger=BondReviewLedger()
        self.assertEqual(ledger.commit(state,evidence(state))[0],"bond_review")
        self.assertIsNone(ledger.commit(state,evidence(state)))

    def test_individual_cannot_be_claimed_by_second_owner(self):
        state=ready();ledger=BondReviewLedger();ledger.commit(state,evidence(state))
        other=replace(state,owner_id="other")
        with self.assertRaisesRegex(Rejected,"individual_already_resolved"):
            ledger.commit(other,evidence(other))

    def test_healing_blocks_proceed_but_not_defer(self):
        state=Ceremony("encounter:fixture","owner:fixture","individual:fixture")
        with self.assertRaisesRegex(Rejected,"not_safe_to_proceed"):
            transition(state,"observe",evidence(state,healing=True))
        self.assertEqual(transition(state,"defer",evidence(state,healing=True)).phase,"deferred")


if __name__ == '__main__': unittest.main()


