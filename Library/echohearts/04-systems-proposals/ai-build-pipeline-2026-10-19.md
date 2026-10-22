# The AI Build Pipeline — Prompt to Playable, Canon-Guarded (2026-10-19)

**Status:** CONCEPT + process documentation. Routes to 09_Technical (implementation path) and 10_Production (canon review). This formalizes what the team already does — it invents no new structure.

**Source:** Tay's ad-copy image ("Build Unreal Games with AI. Turn prompts into playable Unreal worlds with AI." — `workspace/user/files/6943_77_7v6w.jpg`, uploaded 2026-10-19 night). The ad describes the actual workflow of this project: prompts through katas and Copilot into UE5 code. This doc writes it down so every contributor — human or AI — follows the same canon-guarded path.

## The pipeline, end to end

1. **Prompt (Tay or Love).** The intent enters as plain language — a system, a creature batch, a fix. Tay's word is the canon authority; Love's job is to translate intent into a buildable spec without inventing canon.
2. **Canon triage.** Before anything is written, the idea passes the canon lock checklist (`echohearts-canon-lock-checklist.md`): taxonomy (EcoKin/Ecoform), the four attributes (Vibrance/Density/Harmony/Purity — never ATK/HP/SPD/DEF), Binding language (never capture), no sacrifice, no teleportation, Shadow-as-condition, original-only IP. Pasted material (usually ChatGPT) is **reconciliation evidence, never auto-canon** — it gets a keep-vs-violation triage, and only the method survives.
3. **Spec as data asset.** Systems are specced as markdown design docs first (the `04-systems-proposals` convention), then expressed as UE data assets / C++ headers. Data-first: designers and AI iterate on the asset, not the engine.
4. **Code generation (Copilot + agents).** `.github/copilot-instructions.md` is the live prompt contract on every repo — canon locks, UE5.8 rules, the originality firewall. Copilot works issues; background agents build branches. Nothing merges without review; nothing goes direct to main.
5. **Compile gate (UE 5.8.3).** Tay's machine is the honest gate: the first green compile happens there (kata 1 ends with it). Evidence tiers hold: CANON vs SYSTEM CONTRACT vs IMPLEMENTED vs RUNTIME VERIFIED — a doc is not proof the build compiles, and a compile is not proof it runs.
6. **Playtest loop.** Wild encounters, the Binding ceremony, the katas — each system earns RUNTIME VERIFIED only in-engine. Build errors Tay sends back are the next turn of work, not failures.

## The guardrails (non-negotiable, for humans and AIs alike)

- **Tay is the canon authority.** Canon names, flags, branch creation before any GitHub push, merges, anything irreversible or publicly visible — his call, always.
- **The Dex is production authority.** 125-ID permanent Dex; Forms Registry keeps forms attached to base Eco-Kin; every creature has an immutable Echoprint — approved appearance is never silently replaced.
- **No new Bibles, Dexes, or structures.** Everything routes into the existing 00_Canon_Lock through 11_Publication workflow via the routing table.
- **Reversible by default.** Every creative choice stays reversible and attributed; Tay gets a diff plus a short decision list, never a dump.
- **Original-only IP.** Inspiration is fine; reproduction is not. The Ryn & Sera catch (MTG "Rin & Seri" renamed, WotC art reference-only) is the template: catch it, rename it, file the original art as reference-only, tell Tay plainly.

## Onboarding a new contributor (human or AI)

1. Read the canon lock checklist and the alignment notes.
2. Run kata 1 of the UE5.8 exercise series — end with a green compile on your machine.
3. Pick work from the approval queue; open a branch; open a PR.
4. Wait for review. Nothing merges on your own authority.

## Open calls (Tay's)

1. Should this pipeline doc live in the repos themselves (CONTRIBUTING.md on each of the three IN2Deep-Studios repos) once the GitHub write path is fixed?
2. Copilot model pin: GPT-5.6 Sol deliberately, or let GitHub auto-swap (retirements landed 2026-10-19 with no breakage)?
