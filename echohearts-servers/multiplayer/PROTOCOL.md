# EchoHearts multiplayer protocol (line-based, UTF-8, \n-terminated)

## Connect
TCP to the server port (default **7777**). Max 8 players — a 9th gets `FULL`.

## Client -> Server
| Command | Meaning |
|---|---|
| `HELLO <name>` | Join the world. Server replies `WELCOME id=<n> ...` and tells everyone you joined. |
| `POS <x> <y> <z>` | Your position. The server is authoritative for enemies, HP of enemies, boss, score, and time. |
| `HIT <enemyId> <rawDamage>` | You hit an enemy. Server applies defence (boss 6, monster 2, imp 0), crits are client-declared damage — server trusts the raw value for now, min 1 after defence. |
| `SUMMON_BOSS` | Summon the Heartbreaker boss if none is alive. |
| `CHAT <text>` | Broadcast chat to all players. |
| `STATE` | Ask for a one-off world snapshot. |
| `PING` | Server replies `PONG`. |

## Server -> Client (broadcast ~10x/sec plus events)
| Message | Meaning |
|---|---|
| `WELCOME id=<n> world=EchoHearts-Rebearth maxPlayers=8` | You are in. |
| `STATE time=<0-3599> night=<0/1> players=<n> enemies=<n> boss=<0/1>` | World header, followed by one `PLAYER` line per player and one `ENEMY` line per enemy. |
| `PLAYER id=.. name=.. x=.. y=.. z=.. hp=.. score=..` | A player in the world. |
| `ENEMY id=.. kind=imp/monster/boss x=.. z=.. hp=.. maxHp=.. [enraged=1]` | An enemy the server is simulating. |
| `EVENT <text>` | Something happened: a join/leave, a defeat, `Heartbreaker has awoken!`, `Heartbreaker ENRAGED!`, a boss defeat + Rebirth. |
| `CHAT <name>: <text>` | Chat from a player. |
| `PONG` | Reply to `PING`. |

## Rules the server enforces (Terraria-style)
- One shared world, one shared day/night cycle (1800+ = night, spawns faster and monsters are stronger at night).
- Enemy stats: Imp 20 HP / 12 dmg · Monster 60 HP / 20 dmg / 2 defence · Boss 660 HP / 35 dmg / 6 defence, enrages below 25% HP.
- Boss returns periodically while players are in the world, and can be summoned with `SUMMON_BOSS`.
- Score belongs to the player who lands the killing blow.
