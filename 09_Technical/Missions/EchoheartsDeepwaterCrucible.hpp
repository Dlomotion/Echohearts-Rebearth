#pragma once
// Portable UE5.8.3-targeted design adapter; not a reflected Unreal module.
#include <array>
#include <cstdint>
#include <string_view>
namespace Echohearts::Missions {
enum class CrucibleMode : std::uint8_t { Solo, PartnerLink, TamerDuel, CooperativePurification, EnvironmentalSurvival };
struct TrainingAttributes { float Vibrance=0, Density=0, Harmony=0, Purity=0; };
struct CrucibleSession {
 CrucibleMode mode=CrucibleMode::Solo;
 bool tamerConsents=false, ecoKinConsents=false, duelRunning=false;
 bool tamerYielded=false, ecoKinYielded=false;
 float sharedStrain=0, safeStrainLimit=100;
 TrainingAttributes attributes{};
 bool CanContinue() const {
  return tamerConsents && ecoKinConsents && !tamerYielded && !ecoKinYielded &&
         safeStrainLimit>0 && sharedStrain>=0 && sharedStrain<safeStrainLimit;
 }
};
struct ExpansionQuest {std::string_view id,arc,title,requires;};
inline constexpr std::array<ExpansionQuest,36> DeepwaterCrucibleQuests{{
 {"DWT-01","Beneath the Living Tide","The Sunken Signal",""},
 {"DWT-02","Beneath the Living Tide","Pressure at the Threshold","DWT-01"},
 {"DWT-03","Beneath the Living Tide","The Coral Lanterns","DWT-02"},
 {"DWT-04","Beneath the Living Tide","The Trenchway Escort","DWT-03"},
 {"DWT-05","Beneath the Living Tide","The Unbroken Air Pocket","DWT-04"},
 {"DWT-06","Beneath the Living Tide","The Living Tide Restored","DWT-05"},
 {"CVN-01","The Hollowstone Expedition","The First Echo Below",""},
 {"CVN-02","The Hollowstone Expedition","The Crystal Fault","CVN-01"},
 {"CVN-03","The Hollowstone Expedition","The Lost Survey Line","CVN-02"},
 {"CVN-04","The Hollowstone Expedition","The Breathing Cavern","CVN-03"},
 {"CVN-05","The Hollowstone Expedition","The Vein Without a Scar","CVN-04"},
 {"CVN-06","The Hollowstone Expedition","Hollowstone Harmony","CVN-05"},
 {"SAN-01","Sanctuary Rising","The Annex Blueprint",""},
 {"SAN-02","Sanctuary Rising","Hands at the Heartroot","SAN-01"},
 {"SAN-03","Sanctuary Rising","The Purity Well Audit","SAN-02"},
 {"SAN-04","Sanctuary Rising","The Residents' Relay","SAN-03"},
 {"SAN-05","Sanctuary Rising","When the Bell Calls","SAN-04"},
 {"SAN-06","Sanctuary Rising","A Sanctuary Renewed","SAN-05"},
 {"MAT-01","Materials of Rebearth","What the Earth Gives",""},
 {"MAT-02","Materials of Rebearth","The Shed and the Gift","MAT-01"},
 {"MAT-03","Materials of Rebearth","The Safe Crystal Seam","MAT-02"},
 {"MAT-04","Materials of Rebearth","The Artificer's Ledger","MAT-03"},
 {"MAT-05","Materials of Rebearth","Repair Before Expansion","MAT-04"},
 {"MAT-06","Materials of Rebearth","The Catalyst Accord","MAT-05"},
 {"LNK-01","Anima-Link Trials","First Shared Pulse",""},
 {"LNK-02","Anima-Link Trials","The Yield Protocol","LNK-01"},
 {"LNK-03","Anima-Link Trials","The Partner's Choice","LNK-02"},
 {"LNK-04","Anima-Link Trials","The Strain Exchange","LNK-03"},
 {"LNK-05","Anima-Link Trials","Two Hearts in Balance","LNK-04"},
 {"LNK-06","Anima-Link Trials","The Linkmaster's Accord","LNK-05"},
 {"RCC-01","Resonance Crucible Circuit","The Dome Awakens",""},
 {"RCC-02","Resonance Crucible Circuit","Simulated Deepwater","RCC-01"},
 {"RCC-03","Resonance Crucible Circuit","The Cavern Scenario","RCC-02"},
 {"RCC-04","Resonance Crucible Circuit","The Society Raid Drill","RCC-03"},
 {"RCC-05","Resonance Crucible Circuit","The Cooperative Purification","RCC-04"},
 {"RCC-06","Resonance Crucible Circuit","The Crucible Exhibition","RCC-05"},
}};
} // namespace Echohearts::Missions
