# AI / External Research Intake Rule

Status: **TECHNICAL STANDARD**

Do not seed new chats with a stale monolithic prompt containing every historical mechanic. Use the repository source-of-truth documents as the primary context, then provide the specific work item and relevant evidence.

For imported AI/chat/tutorial material:
1. record source/provenance;
2. compare against current canon and UE5.8 documentation;
3. search the repository for existing implementation;
4. deduplicate;
5. classify as CANON, PROPOSAL, REFERENCE/RETIRED, CONFLICT-NEEDS-DECISION, or TECHNICAL-TASK;
6. rewrite external/generic naming into Echohearts-native architecture only where approved;
7. implement on a scoped branch;
8. require build/runtime evidence before VERIFIED.

Unrelated phrases such as music/album-team instructions must not enter the game-development system prompt or repository canon.
