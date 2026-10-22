# Data Tables — Separation Principle

**Status:** CONVENTION. No data tables are filed here yet.

## The rule

**Data tables live here. Art lives in `shared/`. Never mixed.**

This is the organizational method studied from shipped titles: game logic data
(scripts, tables, configs) ships and patches on a completely separate track
from artwork. A balance patch updates data; an art patch updates art; neither
drags the other along.

## What goes here

- Echohearts data is **CSV and JSON** (registries, manifests, tuning tables).
- We do **not** invent Lua files or any other game's script formats. Our data
  formats are our own.

## Layout (when data ships)

```
data/
├── DATA_README.md   ← this file
├── tuning/          ← balance/tuning tables
├── registry/       ← dex/registry snapshots referenced by builds
└── config/         ← platform/packaging configs
```

Each file gets a hash recorded wherever it is consumed (build notes, patch
notes). Data is CONCEPT until authored, IMPLEMENTED when filed here.
