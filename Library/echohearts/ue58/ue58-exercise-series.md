# UE5.8 C++ Exercise Series — Learn From Your Own Subsystems

Your committed code has never compiled. These katas teach UE5.8 C++ *from your
own subsystems* — each one names a real file you committed, states one skill,
and ends with a compile check **you run on your own machine** (Windows, UE 5.8.3).
Exercises annotate and extend; they never rewrite your subsystems. A gap an
exercise exposes becomes the next lesson — it's flagged, not silently fixed.

## How a kata works
1. Open the named file and read the marked section.
2. Do the exercise (small, concrete).
3. Run the compile check on your machine.
4. If it fails, the error message *is* the lesson — read it before asking for help.

## Kata 1 — Reading a subsystem header
**File:** `Source/Echohearts/Public/Discovery/DiscoverySubsystem.h`
**Skill:** Recognize the UCLASS/UFUNCTION/GENERATED_BODY pattern every subsystem shares.
**Do:** Find the three delegate declarations at the top. In your own words, write one
sentence for each: what event does it broadcast, and who listens?
**Compile check:** Open the UE editor, enable the Echohearts plugin/module, and
compile the module. Pass = zero errors. (Expected gap: the Input checklist —
six Input Actions + IMC_Tamer must exist in-editor first; see
`docs/INPUT_SETUP_CHECKLIST.md`.)

## Kata 2 — USTRUCT data shapes
**File:** `Source/Echohearts/Public/Discovery/DiscoveryTypes.h`
**Skill:** Read USTRUCT/UPROPERTY data definitions; understand EditAnywhere vs
BlueprintReadOnly.
**Do:** Add one new `UPROPERTY` to a hunt struct: `int32 RequiredClues = 3;`
with `EditAnywhere, BlueprintReadWrite`. Do not change anything else.
**Compile check:** Compile the module. Pass = zero errors and the new property
visible in any Blueprint that references the struct.

## Kata 3 — Delegates in action
**File:** `Source/Echohearts/Public/Binding/BindingCeremonySubsystem.h`
**Skill:** Trace a dynamic multicast delegate from broadcast to listener.
**Do:** Find where the ceremony broadcasts stage changes (Approach → Attunement →
TheOffer → Alignment → Complete). Add a `UE_LOG` line in the broadcast for the
`Complete` stage: log the bound EcoKin's name.
**Compile check:** Compile; run the ceremony in PIE if possible. Pass = the log
line appears exactly once per completed ceremony.

## Kata 4 — TMap/TArray in practice
**File:** `Source/Echohearts/Public/Encounter/EncounterSubsystem.h`
**Skill:** Read TMap/TArray usage; understand `Find` vs `operator[]`.
**Do:** Find the spawner table lookup. Change one `operator[]` access on a map
that might miss into a `Find` + null check. (This is the single most common
UE crash pattern — worth learning here, safely.)
**Compile check:** Compile. Pass = zero errors. Then explain in one sentence why
`Find` is safer than `[]` here.

## Kata 5 — Your first small system
**File:** `Source/Echohearts/Public/Equipment/EquipmentSubsystem.h` (newest, smallest)
**Skill:** Write a new UFUNCTION end-to-end: declaration, definition, Blueprint exposure.
**Do:** Add `UFUNCTION(BlueprintPure) int32 GetEquippedCount() const;` — return the
number of currently equipped gear pieces. Implement it in the `.cpp`.
**Compile check:** Compile; call it from a test Blueprint. Pass = correct count
(0 with nothing equipped, N after equipping N pieces).

## Kata 6 — Capstone: wire two subsystems
**Files:** `DiscoverySubsystem.h` + `JournalSubsystem.h`
**Skill:** Make one subsystem call another through the GameInstance.
**Do:** When a treasure hunt completes, also call the Journal's `LogObservation`
for the cache location. (Hint: `GetGameInstance()->GetSubsystem<UJournalSubsystem>()`,
null-check it.)
**Compile check:** Full module compile + PIE run: complete a hunt, confirm the
journal entry appears. Pass = no crashes, entry logged once.

---

**What "done" looks like:** all six compile checks green on your machine. The
first green compile of your own game code is the milestone — everything after
that is iteration.
