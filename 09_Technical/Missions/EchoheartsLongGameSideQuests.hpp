#pragma once
#include <array>
#include <string_view>
namespace Echohearts::Missions {
struct LongGameQuest { std::string_view id,title,location,objective; };
inline constexpr std::array<LongGameQuest,24> LongGameSideQuests{{
 {"SQ-018", "The Bell That Wouldn't Ring", "Sanctuary", "Restore the Resonance Bell while protecting the perimeter"},
 {"SQ-019", "Roots Beneath the Floor", "Wetland Forge", "Reroute living Heartroot conduits beneath unstable machinery"},
 {"SQ-020", "The Last Dry Crossing", "Great Plains", "Escort a herd through floodwaters without losing trust"},
 {"SQ-021", "Glasswind Warning", "Red Canyons", "Reactivate three survey beacons in crystal winds"},
 {"SQ-022", "A Promise in the Reeds", "Moonlit Bayou", "Reunite two separated Eco-Kin through Harmony signals"},
 {"SQ-023", "The Unfinished Nest", "Deepwood", "Repair a canopy nesting site using naturally fallen materials"},
 {"SQ-024", "The Borrowed Echoprint", "Sanctuary", "Trace forged observations without altering authentic Echoprints"},
 {"SQ-025", "Under the Floodgate", "Coralus", "Dismantle a pressure trap while holding a safe Torrent corridor"},
 {"SQ-026", "The Quiet Furnace", "Volcanic Ridge", "Repair geothermal regulation without disturbing resting Eco-Kin"},
 {"SQ-027", "A Map of Moving Stars", "Sky Isles", "Recover a Scout expedition using shifting flight currents"},
 {"SQ-028", "The Hollow Orchard", "Deepwood", "Restore a silent grove's natural pollination cycle"},
 {"SQ-029", "The Broken Chorus", "Frostwind Peaks", "Reunite a herd through coordinated calls during a whiteout"},
 {"SQ-030", "The Third Watch", "Sanctuary", "Protect three restoration structures from nonlethal sabotage"},
 {"SQ-031", "The Weight of Water", "Wetland Forge", "Stabilize a flooded district with Density and Torrent"},
 {"SQ-032", "No Signal at Dawn", "Open Range", "Investigate an A.E.G.I.S. relay linked to forced-link sweeps"},
 {"SQ-033", "The Living Compass", "Moonridge", "Navigate using a willing companion's resonance"},
 {"SQ-034", "A Thousand Small Repairs", "Sanctuary", "Coordinate resident repair jobs after Society Pressure damage"},
 {"SQ-035", "The Crystal Debt", "Red Canyons", "Return stolen Catalyst materials and repair a damaged seam"},
 {"SQ-036", "The Skyward Medicine Run", "Skycurrents", "Deliver medicine through crosswinds with safe Anima-Link pacing"},
 {"SQ-037", "Echoes Under Glass", "Prism Cloud Temples", "Align light and Harmony to recover an authentic archive"},
 {"SQ-038", "The Unclaimed Path", "Deepwood", "Restore a migration corridor without requiring Binding"},
 {"SQ-039", "The Lanterns of Coralus", "Coralus Depths", "Guide an underwater school with gentle resonance beacons"},
 {"SQ-040", "What the Shelter Remembers", "Sanctuary", "Review ecological consequences of previous restoration choices"},
 {"SQ-041", "The Heartroot Vigil", "Sanctuary", "Coordinate defense, purification and rebuilding of a Sanctuary"},
}};
}
