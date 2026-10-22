# First-Build Triage Runbook — UE 5.8.3

For the first local build of Echohearts: Rebearth on your PC. I can't see or
drive your machine — this guide tells you exactly what to check, what the
common failures are asking for, and what to send back so the fix gets made here.

## Section 1 — Input mapping verification (do this before you build)

The C++ binds six input actions and loads one mapping context, but the assets
themselves don't exist yet — you create them once, in the editor. Until they
exist, the Tamer won't move, and that's normal.

**Step 1 — Create the 6 Input Actions** (Content Browser → right-click →
Input → Input Action, in `Content/Input/`):

| Asset | Value Type |
|---|---|
| IA_Move | Axis 2D (Vector2D) |
| IA_Look | Axis 2D (Vector2D) |
| IA_Jump | Digital (bool) |
| IA_Interact | Digital (bool) |
| IA_Scan | Digital (bool) |
| IA_Dodge | Digital (bool) |

**Step 2 — Create the Mapping Context** (right-click → Input → Input Mapping
Context, name it `IMC_Tamer`):

| Action | Keys |
|---|---|
| IA_Move | W / A / S / D, gamepad left stick |
| IA_Look | Mouse X/Y, gamepad right stick |
| IA_Jump | Space, gamepad face button bottom |
| IA_Interact | E, gamepad face button top |
| IA_Scan | Q, gamepad left shoulder |
| IA_Dodge | Left Shift, gamepad right shoulder |

**Step 3 — Wire the Blueprints.** Tamer character Blueprint (child of
FrequencyTamerCharacter) → Class Defaults → assign each IA_ action to its
matching slot (MoveAction, LookAction, JumpAction, InteractAction, ScanAction,
DodgeAction). Tamer PlayerController Blueprint → Class Defaults → assign
IMC_Tamer to the mapping-context slot.

**Step 4 — Confirm.** Press Play: WASD moves, mouse looks, Space jumps,
E interacts, Q scans, Shift dodges. If the character moves, input is live and
any remaining problem is in the build — send it back.

## Section 2 — What the common first-build failures are asking for

Nothing in this package has ever compiled, so the first build is the honest
gate: ~140 C++ files, module name `Echohearts`, engine 5.8, with the Enhanced
Input plugin switched on in the project file. These are the failures you're
most likely to meet, in plain language.

**1. "The character doesn't move" — not a build failure.** It's asking for
Section 1 above. The code binds action *names*; the assets don't exist until
you make them. Five minutes in the editor, no paste-back needed.

**2. The editor asks to rebuild missing modules (or mentions a missing
Echohearts DLL).** It's asking for the first compile — say yes and let it run.
140 files takes a while (plan 20–40 minutes on a first build). It's only a
problem if it *fails* with an error; slowness alone is normal.

**3. Red squiggles in Visual Studio ("cannot open source file") but the build
succeeds.** It's asking for patience, not a fix — IntelliSense lags behind the
build. Trust the Output panel's build result, not the squiggles.

**4. Errors mentioning EnhancedInput.** It's asking whether the plugin is
actually enabled — the project file has it switched on, but if you copied the
project or regenerated files oddly, confirm Enhanced Input is enabled in the
editor's Plugins list, then rebuild. Paste back the exact error lines.

**5. Linker errors mentioning the Echohearts module ("unresolved external").**
It's usually asking for a clean rebuild — stale objects from an interrupted
first compile. In the editor: clean, then rebuild. If it survives a clean
rebuild, paste back the full error text.

**6. The build fails on a file you didn't touch.** It's asking you to look at
the *first* error in the Output panel, not the last — later errors are often
knock-on effects. Paste back starting from the first error.

**The paste-back rule (the clean line):**
- **Comes back here:** anything from the Output panel during compile, any
  C++ error, anything that fails the same way twice.
- **Stays with you (5-minute in-editor fixes):** creating the 6 input actions,
  creating IMC_Tamer, assigning them in the Blueprints, enabling a plugin,
  pressing rebuild, waiting out a long first compile.

## Section 3 — Paste-back template

Copy this, fill it in, send it as-is:

```
What I was doing: (e.g. "pressed Build in the editor", "pressed Play")
Checklist step I was on: (e.g. "Section 1, Step 3" or "first compile")
Exact error text — from the Output panel, copy-pasted, starting at the FIRST error:

[paste here]

What I already tried: (e.g. "clean + rebuild", "confirmed plugin enabled")
```

What doesn't help: a screenshot of the whole screen, a paraphrase ("it said
something about input"), or an error from a different project. The exact text
from the Output panel is what the fix gets built from.
