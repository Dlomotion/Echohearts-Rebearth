# LFS Asset Policy

Status: **TECHNICAL STANDARD — PARTIAL IMPLEMENTATION**

Tracked with Git LFS and marked lockable where appropriate:
- `.uasset`
- `.umap`
- `.fbx`
- `.blend`
- `.psd`

Other large binary formats may use LFS as defined in `.gitattributes`.

PNG/JPEG are not globally forced into LFS. Small UI/reference images remain normal Git files; large source art should use an approved path-specific LFS rule if repository growth justifies it.

For shared Unreal binary assets, acquire an LFS lock before editing when concurrent changes are likely. Never hand-merge binary package/map conflicts.
