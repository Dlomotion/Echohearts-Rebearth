# Runtime Cache — Generated On-Device, Never Committed

**Status:** CONVENTION.

## The rule

Anything the game **generates at runtime** — rendered level caches, shader
caches, downloaded bundle caches, temporary working files — lives here (or in
the platform-equivalent on-device directory) and is **never committed** to the
repository.

- Caches are **evictable**: the game must survive their deletion by
  regenerating them. If deleting a cache breaks the game, it's not a cache,
  it's a bug.
- Caches are **versioned**: a cache key includes the content version it was
  built from, so a patch never reads a stale cache.
- Caches are **sized**: the game sets a budget and evicts oldest-first.

## Layout

```
runtime_cache/
├── README.md     ← this file
├── .gitignore    ← ignores everything below except this README
├── levels/       ← per-level runtime render data (generated on-device)
├── shaders/      ← compiled shader caches (generated on-device)
└── downloads/    ← in-progress / verified bundle downloads (generated on-device)
```

Nothing in this tree ships with the game. It is all produced on first run.
