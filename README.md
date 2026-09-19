# Echohearts-Rebearth

Official development repository for **ECHOHEARTS: REBEARTH**.

## Heart Statement

Echohearts becomes great when players feel three things:

1. **This world needs me.**
2. **These Eco-Kin are alive.**
3. **My choices changed Rebearth.**

## Current Production Direction

- Unreal Engine 5.8 is the sole production runtime target.
- Eco-Kin are autonomous sentient partners, not inventory objects.
- Main campaign combat is real-time; Harmony Circuit/EchoDeck cover tactical/turn-based simulation.
- Sanctuary restoration, wild tracking, Havenlink rescue, EcoDex research, world-state consequences and the Living Planet response form the core loop.
- Mini-games must reinforce existing systems rather than create disconnected filler.
- Public website work must distinguish implemented, canon, approved-pending and in-development material.

## Current Technical Gate

1. Build `EchoheartsEditor` under UE 5.8.
2. Run `Echohearts.Partners.CommandBuffer`.
3. Test reload/recovery at 150/250/350 ms plus travel/reconnect/late join.
4. Implement `ECO-API-001`.
5. Implement the smallest `BCT-001` reservation/commit/rollback kernel.

Until those tests exist, runtime claims remain **NOT YET VERIFIED**.

## Source of Truth
See `MASTER_PROJECT_INDEX.md` for the authoritative project routing and current technical documents.

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.
