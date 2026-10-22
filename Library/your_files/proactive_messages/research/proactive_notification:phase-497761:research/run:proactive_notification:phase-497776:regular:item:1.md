<!-- proactive-explanation:run:proactive_notification:phase-497776:regular:item:1 -->
# New fact for the UE decision: 5.8.3 installer can stick on "Initializing" — confirmed workaround

## Lookup

`⁨muse.db⁩` references:

| Table | Keys |
| --- | --- |
| `agent.context_items` | `agent_id=0474295f-aeec-4441-8123-7a8111bd1808`; `agent_id=c2856736-bde1-4b60-af85-d6394595ae13` |
| `agent.message_mailbox` | `submission_id=92bd9719-9315-3ba5-2870-34c5df5d4ebf` |
Prepared: ⁨2026-10-14T02:04:48Z⁩.

## Why this matters

Why this matters now: Tay's UE build-target decision (lock 5.8.3 vs. keep taking hotfixes, asked Oct 12) is still parked, and today brought one genuinely new, concrete fact for it: an Epic Developer Community forum thread dated Oct 13, 2026 reports that Unreal Engine 5.8.3 (and 5.7.3) installers get stuck on "Initializing." Another user confirmed today that clearing everything in C:\ProgramData\Epic\EpicGamesLauncher\Data\Manifests (zip them as backup first) lets the 5.8.3 update complete. Source thread: https://forums.unrealengine.com/t/unreal-engine-5-8-3-and-5-7-3-cannot-be-installed-stuck-on-initializing/2835738 (search result index 6; also corroborates the earlier-verified fact that 5.8.3 released Sept 22, 2026 — no newer hotfix found in today's search). Not established: whether Tay will hit this (he has not installed the engine yet); MCP plugin remains experimental per current coverage — no new status. Suggested delivery shape: tiny footnote-style heads-up attached to the parked UE decision — "when you go to install 5.8.3, known issue + confirmed fix, so don't panic at a stuck installer." No expiry known; useful until he installs the engine.

Selected for regular priority at ⁨2026-10-14T17:33:07.711620+00:00⁩. Record created ⁨2026-10-18T20:13:42.876132093+00:00⁩; delivery is not yet confirmed.


**Delivery outcome (⁨2026-10-18T20:14:01.240780+00:00⁩):** Not sent. Queue state: `⁨suppressed⁩`.
Reason: `⁨revalidation_declined⁩`.
`⁨agent.message_mailbox.submission_id=92bd9719-9315-3ba5-2870-34c5df5d4ebf⁩` resolves the delivery transcript.
<!-- proactive-outcome:proactive_notifier:run:proactive_notification:phase-497776:regular -->
