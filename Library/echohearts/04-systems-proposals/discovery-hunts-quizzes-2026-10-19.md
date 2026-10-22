# Discovery — Hunts, Quizzes & Secret Items (2026-10-19)

**Status:** CONCEPT + code (`Source/Echohearts/Public|Private/Discovery/`) · IMPLEMENTED / NOT COMPILED / NOT TESTED / NOT RUNTIME VERIFIED. Tay's directive 2026-10-19: "add treasure hunts across the maps... educational strategies and topics about EcoKin's and quizzes for extra loot... optional for gamers... secret items." All names vetoable. Routes to 04_Systems.

## The idea
Not everything in Rebearth is main story. The **Discovery** layer is optional side content for players who want to roam, learn, and hunt: treasure hunts strung across regions, quizzes that teach real EcoKin knowledge for real loot, and secret items hidden where only the curious look. Nothing here gates progression — it's all for fun, and for the unique things only the curious earn.

## Pillar 1: Treasure hunts
Clue chains hidden across the map. Each hunt is 4–6 clues; a clue is a riddle, a landmark, or an A.E.G.I.S. scan anomaly. Solving a clue marks the next on your map — never a waypoint, always a riddle. The final clue leads to a **cache**: shed/gifted resource bundles, star-tier materials, cosmetics, or a secret item.

**Rules:**
- Clues are found by exploring, scanning, and reading the world — never bought.
- A hunt can be abandoned and resumed; clues stay solved.
- Caches are one-per-tamer (no farming), but hunts are replayable as stories.
- The Scout's region intel can hint at a hunt's starting region — never the solution.

**Founding hunts (examples):**
1. **The Warden's Cache** (Twilight Woods) — 5 clues following an old warden's patrol route. Reward: Grovewarden cosmetic set + Silver-star Flora bundle.
2. **Sunshard Vault** (Sky Isles) — 6 clues across the isles; final cache needs a flying partner. Reward: secret item **Dawnlens** (see below).
3. **Tidecaller's Hoard** (coastal regions) — 4 clues in tidepools and sea caves; one clue only appears at low tide. Reward: Gold-star Torrent bundle + unique glide trail.

## Pillar 2: EcoKin quizzes
The **Chronicler** hosts quizzes at the Sanctuary (and later at Skyhold). Topics teach real game knowledge — **educational strategies**, not trivia for its own sake:

| Topic | What it teaches |
|-------|-----------------|
| The Four Attributes | Vibrance / Density / Harmony / Purity — what each does, why no ATK/HP |
| The Nine Essences | Flora, Torrent, Pyre, Terra, Aero, Glaze, Voltic, Aura, Shade — strengths and pairings |
| The Five Orders | Zoa, Flora, Myko, Proto, Monera — who belongs where |
| The Anima-Link | Bidirectional strain; why your partner's pain is yours |
| Growth Rites | Rites vs evolution; Kindling, ecology, catalysts |
| Echoprints | Identity is permanent; forms never replace the approved look |
| Binding | Resonance Alignment; the offer; why "capture" isn't a word here |
| Corruption & Purification | The five stages; walking back vs forcing |
| Habitats & Ecology | Where EcoKin live and why; restoration matters |

**Rules:**
- Each quiz is 5 questions, multiple choice, drawn from the topic pool.
- **Wrong answers never punish.** The Chronicler explains the right answer — that's the point: learning.
- Completion (not perfection) earns loot: resource bundles scaled to topic depth; perfect scores earn a bonus cache.
- Quizzes unlock as you encounter their topics in the world — no quiz on corruption before you've seen blight.

Full question bank: `files/04-systems-proposals/quiz-question-bank-2026-10-19.md`.

## Pillar 3: Secret items
Unique items hidden in the world — behind hunt caches, quiz mastery, hard-to-reach places, and pure exploration. Every secret item has a **hint** (never a marker) and a **story** (never just stats).

**Rules:**
- Secret items are unique looks or small conveniences — never power you can't get elsewhere, never required for anything.
- No duplicates: one per tamer, forever.
- Hints are riddles; the community can share them, the game never spoils them.

**Founding secret items (examples):**
| Item | Hint | Found via |
|------|------|-----------|
| **Dawnlens** | "Where the first light lands, look through it." | Sunshard Vault hunt cache |
| **Prism Collar** | "It chose the one who healed the grove." | Prismara hidden mission, perfect completion |
| **Tidecaller's Bell** | "Ring it where the tide forgets to return." | Tidecaller's Hoard hunt cache |
| **Chronicler's Quill** | "Answer everything the old one asks." | Perfect scores on all nine quiz topics |
| **Riftwalker's Step** | "The dark isle keeps what the light drops." | Rift Anchorage exploration (Sky Isles) |

## Code: what was built
- `DiscoveryTypes.h` — `FHuntClue`, `FTreasureHuntDef` (region tags, ordered clues, cache rewards, secret item), `FQuizQuestion`, `FQuizTopicDef`, `FSecretItemDef`.
- `DiscoverySubsystem.h/.cpp` — `UGameInstanceSubsystem`: `RegisterTreasureHunt`, `BeginHunt`, `SolveClue`, `RegisterQuizTopic`, `SubmitQuizAnswers`, `UnlockSecretItem`; delegates `OnHuntCompleted(HuntId, CacheRewards)`, `OnQuizCompleted(TopicId, PerfectScore)`, `OnSecretItemUnlocked(ItemId)`.
- Hunts and quizzes are data-driven; the question bank ships as data the Chronicler reads.

## What this means in play
Main story for the heart, Discovery for the wanderer. Roam far, learn true things, find what isn't marked — and come home with something nobody else has.
