# Patches — Versioned Patch Convention

**Status:** CONVENTION / NOT IMPLEMENTED. No patch has been produced yet.

## The convention

- Patches are numbered: `v1`, `v2`, `v3`, … — plain, sequential, Echohearts' own.
- Each patch is a **delta** against the base install plus all previous patches.
  A patch never re-ships unchanged art.
- Patch contents are recorded in `patches/v<N>/PATCH_NOTES.md` (what changed,
  why, hash of every file) before the patch is considered real.
- Art patches and data patches ship separately: a balance change (data) must
  never force players to re-download gigabytes of textures (art).

## Layout (when patches exist)

```
patches/
├── PATCHES_README.md   ← this file
├── v1/
│   ├── PATCH_NOTES.md
│   └── ...changed files only...
└── v2/
    ├── PATCH_NOTES.md
    └── ...changed files only...
```

## Rules

1. Base install is immutable; patches layer on top.
2. Every patch file is hashed; hashes go in PATCH_NOTES.md.
3. A patch is CONCEPT until built, IMPLEMENTED when produced, and only
   RUNTIME VERIFIED after install + launch testing on a real device.
