"""Echohearts battle admission/settlement reference; no network or Unreal runtime."""
from dataclasses import dataclass
import re


class Rejected(ValueError):
    pass


def identifier(value):
    return type(value) is str and re.fullmatch(r"[A-Za-z0-9_.:-]{1,96}", value) is not None


def require(condition, reason):
    if not condition:
        raise Rejected(reason)


@dataclass(frozen=True)
class Rules:
    players: tuple[int, int]
    servers: frozenset[str]
    teams: tuple[int, ...]
    ranked: bool = False
    simulation: bool = False
    late_join: bool = False


RULES = {
    "field_training": Rules((1, 1), frozenset({"offline", "private_coop", "public_pve"}), (1,)),
    "echo_duel": Rules((2, 2), frozenset({"casual_arena"}), (1, 1), simulation=True),
    "ranked_duel": Rules((2, 2), frozenset({"ranked_arena"}), (1, 1), ranked=True, simulation=True),
    "relay_teams": Rules((4, 4), frozenset({"casual_arena"}), (2, 2), simulation=True),
    "discordance_response": Rules((1, 4), frozenset({"private_coop", "event_raid"}), (), late_join=True),
    "tactical_arena": Rules((2, 2), frozenset({"casual_arena"}), (1, 1), simulation=True),
    "ghost_trial": Rules((1, 1), frozenset({"offline", "casual_arena"}), (1,), simulation=True),
    "circuit_final": Rules((2, 2), frozenset({"tournament"}), (1, 1), ranked=True, simulation=True),
}


@dataclass(frozen=True)
class Partner:
    instance_id: str
    bonded: bool = True
    willing: bool = True
    healing: bool = False
    ceremony: bool = False


@dataclass(frozen=True)
class Participant:
    player_id: str
    team: int
    partners: tuple[Partner, ...]
    active_id: str
    accepted: bool


@dataclass(frozen=True)
class Session:
    match_id: str
    server_id: str
    server_kind: str
    mode: str
    build: str
    ruleset: str
    season: str
    region: str
    revision: int
    participants: tuple[Participant, ...]
    started: bool = False


@dataclass(frozen=True)
class HostContext:
    """Trusted adapter output, never deserialized directly from a client request."""
    server_id: str
    build: str
    ruleset: str
    season: str
    region: str
    revision: int
    authenticated_players: frozenset[str]
    permitted_players: frozenset[str]
    habitat_safe: bool
    arrival_safe: bool


def admit(session, host, *, joining=True):
    require(type(session) is Session and type(host) is HostContext, "invalid_envelope")
    require(type(session.mode) is str and session.mode in RULES, "unknown_mode")
    rules = RULES[session.mode]
    require(type(session.server_kind) is str and session.server_kind in rules.servers, "server_mode_mismatch")
    for field in ("match_id", "server_id", "build", "ruleset", "season", "region"):
        require(identifier(getattr(session, field)), "invalid_identity")
    for field in ("server_id", "build", "ruleset", "season", "region", "revision"):
        require(getattr(session, field) == getattr(host, field), "stale_or_wrong_session")
    require(type(session.revision) is int and 0 <= session.revision < 2**31, "invalid_revision")
    require(type(host.revision) is int, "invalid_revision")
    require(type(session.started) is bool, "invalid_started_flag")
    require(not joining or not session.started or rules.late_join, "late_join_disabled")
    require(host.habitat_safe is True and host.arrival_safe is True, "unsafe_site")
    require(type(session.participants) is tuple, "invalid_participants")
    require(rules.players[0] <= len(session.participants) <= rules.players[1], "player_count")
    require(type(host.authenticated_players) is frozenset and type(host.permitted_players) is frozenset,
            "invalid_authority_context")
    players, individuals, teams = set(), set(), {}
    for player in session.participants:
        require(type(player) is Participant and identifier(player.player_id), "invalid_player")
        require(player.player_id not in players, "duplicate_player")
        players.add(player.player_id)
        require(player.player_id in host.authenticated_players and player.player_id in host.permitted_players,
                "unauthorized_player")
        require(player.accepted is True, "challenge_not_accepted")
        require(type(player.team) is int and 0 <= player.team <= 1, "invalid_team")
        teams[player.team] = teams.get(player.team, 0) + 1
        require(type(player.partners) is tuple and 1 <= len(player.partners) <= 8, "carried_limit")
        available = set()
        for partner in player.partners:
            require(type(partner) is Partner and identifier(partner.instance_id), "invalid_partner")
            require(partner.instance_id not in individuals, "duplicate_partner")
            individuals.add(partner.instance_id)
            require(partner.bonded is True, "unbonded_partner")
            require(type(partner.willing) is bool and type(partner.healing) is bool
                    and type(partner.ceremony) is bool, "invalid_partner_flags")
            if partner.willing and not partner.healing and not partner.ceremony:
                available.add(partner.instance_id)
        require(identifier(player.active_id) and player.active_id in available, "active_partner_unavailable")
    if rules.teams:
        require(tuple(teams[k] for k in sorted(teams)) == rules.teams, "team_composition")
    else:
        require(set(teams) == {0}, "raid_must_cooperate")
    return rules


@dataclass(frozen=True)
class Result:
    match_id: str
    mode: str
    season: str
    server_id: str
    revision: int
    winner_ids: tuple[str, ...]


class SettlementLedger:
    """In-memory idempotency example. Not a durable distributed reward service."""
    def __init__(self):
        self._settled = {}

    def settle(self, session, host, result, completed_match_ids):
        require(type(result) is Result and type(completed_match_ids) is frozenset, "invalid_result")
        rules = admit(session, host, joining=False)
        require(session.match_id in completed_match_ids, "match_not_completed")
        for field in ("match_id", "mode", "season", "server_id", "revision"):
            require(getattr(result, field) == getattr(session, field), "result_scope_mismatch")
        require(type(result.revision) is int, "invalid_revision")
        require(type(result.winner_ids) is tuple and all(identifier(x) for x in result.winner_ids), "invalid_winners")
        require(len(set(result.winner_ids)) == len(result.winner_ids), "duplicate_winner")
        players = {p.player_id: p.team for p in session.participants}
        require(all(x in players for x in result.winner_ids), "unknown_winner")
        if result.winner_ids:
            winning_teams = {players[x] for x in result.winner_ids}
            require(len(winning_teams) == 1, "mixed_winning_teams")
            team = next(iter(winning_teams))
            require(set(result.winner_ids) == {x for x in players if players[x] == team}, "partial_winning_team")
        # Order does not change the meaning of an outcome.
        fingerprint = (result.mode, result.season, result.server_id, result.revision, tuple(sorted(result.winner_ids)))
        previous = self._settled.get(result.match_id)
        if previous is not None:
            require(previous == fingerprint, "conflicting_replay")
            return ()
        self._settled[result.match_id] = fingerprint
        # Authorization events only: no currency, roster, world or rank is mutated.
        event = "standing_review" if rules.ranked else "participation_review"
        return tuple((result.match_id, player.player_id, event) for player in session.participants)
