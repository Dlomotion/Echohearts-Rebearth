# World Explorer terrain and flight

Status: APPROVED-PENDING game integration; browser authoring prototype implemented separately in the web repository.

The requested exploration controls tune mountain height/steepness and canyon depth/width. Flight supports inertia, pitch, bank/roll, heading and gravity. A.E.G.I.S. presents a north-up mini-map, compass, ground clearance, airspeed and predicted terrain-contact warnings. Pause/reset and touch controls provide safe authoring iteration.

The prototype uses deterministic procedural terrain, bounded simulation steps and terrain-contact recovery. Exported JSON records tuning and explicitly declares `runtimeVerified: false`. It is an authoring study, not an Unreal landscape or verified gameplay build. Browser presets do not establish canonical world scale, speed, gravity or final balancing.

Integrate through the actual existing flight/terrain/HUD components once their source is located. The supplied UI notes cite `feature/ui-systems-2026-10-25`; that branch was not found in the inspected Dlomotion checkout/remote. Do not create duplicate replacement gameplay components from that claim alone.

Unreal acceptance requires UHT/UBT build, tests of control/frame-rate behavior and collision queries against actual terrain, HUD input/accessibility checks, and retained runtime evidence. No UE5.8 verification is asserted here.

For Safehold, Heritage, expressions and presentation use [the owner ruling](../00_Canon_Lock/SAFEHOLD_HERITAGE_PRESENTATION_RULINGS_2026-10-23.md). Existing permanent IDs and approved portraits remain authoritative.
