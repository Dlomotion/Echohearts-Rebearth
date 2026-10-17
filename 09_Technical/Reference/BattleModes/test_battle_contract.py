from dataclasses import replace
import unittest
from battle_contract import (Partner, Participant, Session, HostContext, Result,
                             Rejected, RULES, admit, SettlementLedger)


def fixture(mode="ranked_duel", server="ranked_arena", count=2):
    participants = tuple(Participant(f"player:{i}", i % 2,
                        (Partner(f"instance:{i}"),), f"instance:{i}", True) for i in range(count))
    session = Session("match:1", "server:1", server, mode, "build:1", "rules:1",
                      "season:1", "region:1", 1, participants)
    ids = frozenset(p.player_id for p in participants)
    host = HostContext("server:1", "build:1", "rules:1", "season:1", "region:1", 1, ids, ids, True, True)
    return session, host


class BattleTests(unittest.TestCase):
    def setUp(self):
        self.s, self.h = fixture()

    def rejects(self, reason, s=None, h=None):
        with self.assertRaisesRegex(Rejected, "^" + reason + "$"):
            admit(s or self.s, h or self.h)

    def test_valid_ranked(self):
        self.assertTrue(admit(self.s, self.h).ranked)

    def test_all_modes_have_valid_fixture(self):
        for name, rule in RULES.items():
            with self.subTest(mode=name):
                s, h = fixture(name, sorted(rule.servers)[0], rule.players[0])
                if not rule.teams:
                    s = replace(s, participants=tuple(replace(p, team=0) for p in s.participants))
                self.assertIs(admit(s, h), rule)

    def test_unknown_mode(self):
        self.rejects("unknown_mode", replace(self.s, mode="forced_capture"))

    def test_server_isolation(self):
        self.rejects("server_mode_mismatch", replace(self.s, server_kind="public_pve"))

    def test_malformed_server(self):
        self.rejects("server_mode_mismatch", replace(self.s, server_kind=[]))

    def test_scope_fields(self):
        for field in ("server_id", "build", "ruleset", "season", "region", "revision"):
            with self.subTest(field=field):
                value = 2 if field == "revision" else "different"
                self.rejects("stale_or_wrong_session", replace(self.s, **{field: value}))

    def test_revision_bool(self):
        self.rejects("invalid_revision", replace(self.s, revision=True))

    def test_ranked_late_join_denied(self):
        self.rejects("late_join_disabled", replace(self.s, started=True))

    def test_raid_late_join_allowed(self):
        s, h = fixture("discordance_response", "event_raid", 4)
        s = replace(s, started=True, participants=tuple(replace(p, team=0) for p in s.participants))
        self.assertTrue(admit(s, h).late_join)

    def test_unsafe_site(self):
        for field in ("habitat_safe", "arrival_safe"):
            self.rejects("unsafe_site", h=replace(self.h, **{field: False}))

    def test_unauthorized_player(self):
        self.rejects("unauthorized_player", h=replace(self.h, permitted_players=frozenset()))

    def test_refusal(self):
        p = replace(self.s.participants[0], accepted=False)
        self.rejects("challenge_not_accepted", replace(self.s, participants=(p, self.s.participants[1])))

    def test_no_forced_or_unavailable_partner(self):
        for change, reason in (({"bonded": False}, "unbonded_partner"),
                               ({"willing": False}, "active_partner_unavailable"),
                               ({"healing": True}, "active_partner_unavailable"),
                               ({"ceremony": True}, "active_partner_unavailable")):
            p = self.s.participants[0]
            p = replace(p, partners=(replace(p.partners[0], **change),))
            self.rejects(reason, replace(self.s, participants=(p, self.s.participants[1])))

    def test_duplicate_players(self):
        self.rejects("duplicate_player", replace(self.s, participants=(self.s.participants[0],)*2))

    def test_duplicate_individual(self):
        p = replace(self.s.participants[1], partners=self.s.participants[0].partners,
                    active_id=self.s.participants[0].active_id)
        self.rejects("duplicate_partner", replace(self.s, participants=(self.s.participants[0], p)))

    def test_carried_limit(self):
        p = replace(self.s.participants[0], partners=tuple(Partner(f"many:{i}") for i in range(9)))
        self.rejects("carried_limit", replace(self.s, participants=(p,self.s.participants[1])))

    def test_team_balance(self):
        p = replace(self.s.participants[1], team=0)
        self.rejects("team_composition", replace(self.s, participants=(self.s.participants[0],p)))

    def result(self, **changes):
        r = Result("match:1", "ranked_duel", "season:1", "server:1", 1, ("player:0",))
        return replace(r, **changes)

    def test_settlement_once_in_running_match(self):
        ledger = SettlementLedger()
        s = replace(self.s, started=True)
        events = ledger.settle(s, self.h, self.result(), frozenset({"match:1"}))
        self.assertEqual(len(events), 2)
        self.assertEqual(events[0][2], "standing_review")
        self.assertEqual(ledger.settle(s, self.h, self.result(), frozenset({"match:1"})), ())

    def test_result_not_completed(self):
        with self.assertRaisesRegex(Rejected, "match_not_completed"):
            SettlementLedger().settle(self.s, self.h, self.result(), frozenset())

    def test_result_wrong_server_and_season(self):
        for field in ("server_id", "season", "mode", "match_id", "revision"):
            with self.subTest(field=field), self.assertRaisesRegex(Rejected, "result_scope_mismatch"):
                value = 2 if field == "revision" else "other"
                SettlementLedger().settle(self.s, self.h, self.result(**{field:value}), frozenset({"match:1"}))

    def test_conflicting_replay(self):
        ledger = SettlementLedger()
        ledger.settle(self.s, self.h, self.result(), frozenset({"match:1"}))
        with self.assertRaisesRegex(Rejected, "conflicting_replay"):
            ledger.settle(self.s, self.h, self.result(winner_ids=("player:1",)), frozenset({"match:1"}))

    def test_ghost_has_no_rank(self):
        s, h = fixture("ghost_trial", "offline", 1)
        r = Result(s.match_id, s.mode, s.season, s.server_id, s.revision, ("player:0",))
        self.assertEqual(SettlementLedger().settle(s, h, r, frozenset({s.match_id}))[0][2], "participation_review")

    def test_mixed_winner_rejected(self):
        with self.assertRaisesRegex(Rejected, "mixed_winning_teams"):
            SettlementLedger().settle(self.s, self.h, self.result(winner_ids=("player:0","player:1")), frozenset({"match:1"}))

    def test_draw_is_valid(self):
        self.assertEqual(len(SettlementLedger().settle(self.s, self.h, self.result(winner_ids=()), frozenset({"match:1"}))),2)


if __name__ == "__main__":
    unittest.main()
