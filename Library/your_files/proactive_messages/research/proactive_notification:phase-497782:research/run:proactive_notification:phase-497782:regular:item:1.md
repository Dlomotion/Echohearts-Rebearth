<!-- proactive-explanation:run:proactive_notification:phase-497782:regular:item:1 -->
# Epic's EAC v2 details verified — anti-cheat plan now concrete (no action needed)

## Lookup

`⁨muse.db⁩` references:

| Table | Keys |
| --- | --- |
| `agent.context_items` | `agent_id=4f49c401-64fb-473a-964b-500011666dc8`; `agent_id=be8bba36-fbf5-482d-83f6-a5dfba0dfe8b` |
| `agent.message_mailbox` | `submission_id=c3af819a-126c-17e2-d303-78dc76db0649` |
Prepared: ⁨2026-10-14T23:03:47Z⁩.

## Why this matters

Why this matters now: Tay's latest directive tonight (2026-10-14 21:32Z) was Linux groundwork + rebuilding anti-cheat for Linux. Epic announced the real EAC Linux v2 details today, and I verified them across 8 outlets reporting Epic's own 2026-10-14 technical announcement (Epic's 'Awesome Gaming on Linux Without Cheating' tech blog + launcher Preview announcement). Three facts Tay doesn't have yet: (1) EAC Linux v2 installs NO dedicated anti-cheat kernel module — it builds on existing Linux security features (signed kernels, signed kernel modules, TPM 2.0, Secure Boot with attestation, measured boot, eBPF tamper monitoring, and a systemd service active only while a protected game is running). That means our game-side 'no kernel-driver assumptions' design is aligned with Epic's own approach, not a compromise. (2) Players who don't meet the security config get a launch ERROR, not an account ban — a design note for our launcher when it matures past bootstrap: pre-flight the platform requirements and fail with a clear message, never a ban. (3) Epic pilots v2 in Fortnite first, then makes it available to other developers after validation — no developer SDK yet, so our Track 1 stays integration-path-only (standing rule: no code against an SDK we don't have). I checked our groundwork against Epic's distro floor (Ubuntu 22.04 LTS+, Fedora 43+, Debian 12+, x86_64): it already matches — the CI runs ubuntu-22.04 and the build scripts are toolchain-agnostic. What I completed: enriched the local docs/ANTI_CHEAT_LINUX_PLAN.md (DESIGN tier) with a new 'EAC Linux v2 — what Epic actually announced' section including a concrete target for our session-attestation interface: design it to eventually consume Secure Boot / measured-boot attestation quotes (TPM 2.0) as client assertions for server validation — the same signals EAC v2 will rely on — keeping the server-authoritative layer forward-compatible with Epic's SDK callbacks. Change recorded in the ledger. Remaining uncertainty: the doc lives in the local unpushed draft of IN2Deep-Studios/ECHOHEARTS-REBEARTH-BUILD-; pushing is still gated by the two already-known blockers (Muse GitHub App repo-selection grant for the two private repos; the ECO-KIN-Game branch push approval that timed out) — nothing new to decide there. No hard expiry; most useful while the Linux thread is live with Tay.

Selected for regular priority at ⁨2026-10-14T23:05:40.575178+00:00⁩. Record created ⁨2026-10-18T20:14:01.375145040+00:00⁩; delivery is not yet confirmed.


**Delivery outcome (⁨2026-10-18T20:14:49.486058+00:00⁩):** Sent. Queue state: `⁨delivered⁩`.
Reason: `⁨delivered⁩`.
`⁨agent.message_mailbox.submission_id=c3af819a-126c-17e2-d303-78dc76db0649⁩` resolves the delivery transcript.
<!-- proactive-outcome:proactive_notifier:run:proactive_notification:phase-497782:regular -->
