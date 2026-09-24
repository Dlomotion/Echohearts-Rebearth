# Git / LFS Recovery Checklist

Status: **TECHNICAL-TASK — NOT YET VERIFIED**

Before any large asset migration or history rewrite:

- create a recovery branch/tag;
- confirm remote origin and expected branch;
- ensure working tree is clean;
- back up irreplaceable source art outside the repository;
- verify `git lfs env` and tracked patterns;
- validate that current LFS objects are pushed;
- do not rewrite shared history while collaborators have unpushed work;
- after migration, perform a fresh clone in a clean directory;
- run `git lfs pull`;
- open representative `.uasset` / `.umap` content in UE5.8;
- verify branch protection and required checks still apply;
- record the migration commit/tag and rollback command.

Do not delete local source copies until the fresh-clone verification succeeds.
