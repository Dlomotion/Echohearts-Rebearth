# Regional Operations expansion — review patch

This adds **17 regional campaign operations** (`RCH-1..17`) and **37 side operations** (`RED-501..537`) alongside, **not instead of**, the existing 42 Core Chronicles / 14 Anomalies / 200 Eddy slots. The 17 operations are regional story modules, not a second numbered core campaign. Existing completion identifiers remain unchanged.

The user's 504–515 range comprises twelve IDs for nine Essence vaults. 504–512 are nine unique vault calibrations, while 513–515 are linked network stabilization challenges. 518–530 are thirteen distinct Archive alignment trials. These additional details are design proposals, not preapproved canon.

**Canon and QA constraints:** proposed place names, guardian identities and nine Essence labels require review against the existing story bible. 648 species is not approved: the Permanent Dex remains 125 IDs. No ownership, capture, lethal encounter, generic levels or Nature binding. Completion gating for RED-537 uses the approved 125-ID Dex plus RED-501..536, and does not replace existing EDY-200. A true cross-system quest event bridge and actual UE5.8 SaveGame integration are not included.

Portable smoke test:
```sh
c++ -std=c++17 -I09_Technical/Missions 09_Technical/Missions/RegionalExpansionSmoke.cpp -o /tmp/echohearts-regional-test
/tmp/echohearts-regional-test
```
Do not claim a successful engine build or playable content until UE5.8 UHT/compiler and runtime validation.
