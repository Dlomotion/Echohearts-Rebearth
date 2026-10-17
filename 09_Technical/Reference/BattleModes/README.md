# Echohearts battle-mode reference contract

Standard-library Python 3.12, offline only. From this directory:

```sh
python3 -m unittest -v
```

This oracle models mode/server compatibility, session identity and current revision,
opt-in participation, eight carried bonded partners/one eligible active partner,
team balance and in-memory outcome idempotency. It has no socket, matchmaking,
identity provider, server process, Unreal dependency or combat damage implementation.

HostContext and completed_match_ids are trusted adapter outputs; never deserialize
them directly from a client request. Actual authoritative services must resolve
account permissions, approved Eco-Kin instances, relationship/care flags, safe sites,
match completion and outcomes. The model cannot verify their truth cryptographically.

admit defaults to join-time policy: started ranked/tournament matches reject late
join. Settlement validates the same fixed match with joining=False, because a
running match must be able to complete. Reward events are review intents only;
no standing, currency, story state, travel access or biological growth is granted.
Draws still emit review events; downstream policy decides their meaning.

The ledger is in-memory, single-process and non-durable, has no concurrent-write
protection and must be replaced by the existing persistence authority for production.
An identical repeated result returns no new events. Conflicting results fail closed.
Tests cover all eight modes with fixture identities; fixtures are not canonical data.

Local evidence: 2026-10-17, Python 3.12 standard-library unittest, 24 methods passed (including per-mode/subcase loops). Syntax parsing passed. No Unreal or hosted-server execution was performed.
