# Synchronization Pipeline Correction Summary

Imported blueprint was accepted as a **source proposal**, then corrected before implementation.

Key fixes applied:
- retained existing Echohearts source-of-truth folders instead of creating a parallel AI-doc hierarchy;
- corrected UE5.7 references to UE5.8;
- replaced `git init` guidance with clone/fetch/feature-branch workflow;
- avoided blanket `Build/` ignore;
- avoided global PNG LFS tracking;
- added LFS lockable rules for `.uasset` / `.umap` and major DCC binaries;
- rejected automatic commit-after-build chaining;
- downgraded global stepped animation/shader/audio-pool claims to evidence-gated proposals;
- added public-repository self-hosted-runner security restrictions;
- kept Unreal CI inactive until a real `.uproject`, `Source/` module tree, and trusted runner exist;
- connected the rollout to the existing daily workflow and Issue #10 dependency chain.
