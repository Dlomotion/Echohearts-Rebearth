#pragma once
// Additive quest definitions; no UE reflected integration until the module is verified.
#include <array>
#include <cstdint>
#include <set>
#include <string>
#include <string_view>
namespace Echohearts::Missions {
struct FieldQuest { std::string_view id, arc, title, objective, prerequisite; };
inline constexpr std::array<FieldQuest,42> FieldResearchQuests{{
 {"MAP-01","Cartographer's Resonance","The First Survey Line","Map a safe Sanctuary-to-Deepwood route using A.E.G.I.S.",""},
 {"MAP-02","Cartographer's Resonance","The Unheard Landmark","Identify an unlogged landmark by its ambient Harmony signature","MAP-01"},
 {"MAP-03","Cartographer's Resonance","The Broken Trail","Reconstruct a storm-damaged Scout route without disturbing nests","MAP-02"},
 {"MAP-04","Cartographer's Resonance","Three Horizons","Survey three connected regions using existing travel routes","MAP-03"},
 {"MAP-05","Cartographer's Resonance","The Hidden Watershed","Chart a subterranean watershed and its natural outlets","MAP-04"},
 {"MAP-06","Cartographer's Resonance","The Living Atlas","Validate region survey evidence with the Chronicler","MAP-05"},
 {"RES-01","The Living Dex Initiative","A Record of Kindness","Observe an Eco-Kin without initiating Binding",""},
 {"RES-02","The Living Dex Initiative","An Echoprint in Context","Compare an approved Echoprint to habitat observations","RES-01"},
 {"RES-03","The Living Dex Initiative","Five Orders, One World","Document ecological roles across the five sentience Orders","RES-02"},
 {"RES-04","The Living Dex Initiative","The Patient Watch","Record feeding, shelter and migration behavior without interference","RES-03"},
 {"RES-05","The Living Dex Initiative","The Unaltered Record","Reject a forged observation and restore authentic research provenance","RES-04"},
 {"RES-06","The Living Dex Initiative","A Living Entry","Submit verified observations to D.A.H.L.I.A. for Dex review","RES-05"},
 {"LAB-01","The Sanctuary Research Wing","The Clean Bench","Prepare a contamination-free research station",""},
 {"LAB-02","The Sanctuary Research Wing","The Gifted Sample","Catalog a naturally shed or voluntarily gifted sample","LAB-01"},
 {"LAB-03","The Sanctuary Research Wing","Reading the Fracture","Analyze noninvasive corruption signatures without forced testing","LAB-02"},
 {"LAB-04","The Sanctuary Research Wing","The Control Habitat","Compare healthy and recovering ecosystem measurements","LAB-03"},
 {"LAB-05","The Sanctuary Research Wing","The Missing Reagent","Recover an ethical Catalyst substitute from an approved seam","LAB-04"},
 {"LAB-06","The Sanctuary Research Wing","Findings Without Harm","Publish research to the Chronicler without modifying Echoprints","LAB-05"},
 {"ECO-01","Roots of Recovery","Where the Water Stops","Trace and clear a blocked clean-water route",""},
 {"ECO-02","Roots of Recovery","The Seed Carriers","Restore pollination routes with willing Flora partners","ECO-01"},
 {"ECO-03","Roots of Recovery","The Quiet Bank","Stabilize eroding habitat without disrupting nesting Eco-Kin","ECO-02"},
 {"ECO-04","Roots of Recovery","The Returning School","Reopen a Torrent migration corridor","ECO-03"},
 {"ECO-05","Roots of Recovery","A Region Responds","Defend repaired Heartroot infrastructure from sabotage","ECO-04"},
 {"ECO-06","Roots of Recovery","The Imperfect Spring","Validate restoration gains and record remaining ecological scars","ECO-05"},
 {"KIN-01","The Kinward Stories","The First Recognition","Learn a selected approved Eco-Kin's natural habitat signals",""},
 {"KIN-02","The Kinward Stories","A Memory of Shelter","Discover the species' preferred refuge without disturbing it","KIN-01"},
 {"KIN-03","The Kinward Stories","The Choice to Help","Support an individual Eco-Kin without requiring Binding","KIN-02"},
 {"KIN-04","The Kinward Stories","The Long Way Home","Guide an individual safely through its native corridor","KIN-03"},
 {"KIN-05","The Kinward Stories","The Offered Resonance","Accept or decline an Eco-Kin's voluntary interaction","KIN-04"},
 {"KIN-06","The Kinward Stories","The Kinward Chronicle","Record the individual's story without creating a new Dex species","KIN-05"},
 {"MAT-01","The Responsible Harvest","What Was Shed","Gather naturally fallen and shed resources",""},
 {"MAT-02","The Responsible Harvest","The Safe Seam","Survey a Catalyst seam for ecological stability","MAT-01"},
 {"MAT-03","The Responsible Harvest","The Repair Ledger","Match approved materials to Sanctuary repair needs","MAT-02"},
 {"MAT-04","The Responsible Harvest","The Flooded Supply Cache","Recover abandoned supplies from a safe route","MAT-03"},
 {"MAT-05","The Responsible Harvest","The Artisan's Test","Craft a repair component without consuming any Eco-Kin","MAT-04"},
 {"MAT-06","The Responsible Harvest","Leave the Ground Whole","Restore the extraction site and validate its recovery","MAT-05"},
 {"RSC-01","The Rescue Network","The Missing Signal","Locate a missing Eco-Kin from noninvasive resonance traces",""},
 {"RSC-02","The Rescue Network","The Narrow Passage","Clear a collapsed route and escort trapped residents","RSC-01"},
 {"RSC-03","The Rescue Network","A Link Unbound","Break a forced link without harming either party","RSC-02"},
 {"RSC-04","The Rescue Network","The Deepwater Refuge","Guide stranded aquatic Eco-Kin through safe passages","RSC-03"},
 {"RSC-05","The Rescue Network","After the Storm","Coordinate Mender treatment and Sanctuary shelter","RSC-04"},
 {"RSC-06","The Rescue Network","The Safe Return","Return rescued Eco-Kin to suitable habitat or voluntary residency","RSC-05"},
}};
enum class EcoKinResearchStage : std::uint8_t { Observe=1, Study=2, Assist=3, Understand=4, Restore=5 };
inline std::string EcoKinResearchId(std::string_view approvedDexId, EcoKinResearchStage stage) {
 return std::string("KIN-RESEARCH-")+std::string(approvedDexId)+"-"+std::to_string(static_cast<unsigned>(stage));
}
inline bool CanStartEcoKinResearch(std::string_view dexId, EcoKinResearchStage stage,
 const std::set<std::string>& approvedDexIds, const std::set<std::string>& completed) {
 if (dexId.empty() || !approvedDexIds.count(std::string(dexId))) return false;
 const auto n=static_cast<unsigned>(stage);
 if(n<1 || n>5) return false;
 return n==1 || completed.count(EcoKinResearchId(dexId,static_cast<EcoKinResearchStage>(n-1)))>0;
}
inline bool CanStartFieldQuest(const FieldQuest& quest,const std::set<std::string>& completed){
 return quest.prerequisite.empty() || completed.count(std::string(quest.prerequisite))>0;
}
} // namespace Echohearts::Missions
