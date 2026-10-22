#pragma once
// Additive regional mission expansion; C++17 data only.
// Names/regions/Essences in this intake remain subject to canon review.
#include "EchoheartsMissionRegistry.hpp"
#include <set>
namespace Echohearts::Missions {
enum class OperationKind { RegionalChronicle, Community, Vault, Stabilization, ArchiveTrial, Shrine, Finale };
struct RegionalOperation {
    std::string id;
    OperationKind kind;
    std::string title;
    std::string objective;
    unsigned region; // 0 means multiple regions or a hub
    bool postgame;
    bool authored;
};
inline std::vector<RegionalOperation> BuildRegionalExpansion() {
    std::vector<RegionalOperation> out;
    out.reserve(54);
    const char* titles[] = {
      "The Frozen Valley","Shattered Sanctuary","The Spire Assault","The Sound-Well Mandate",
      "The Obsidian Breach","The Magma Warden","The Sand-Scorched Outpost",
      "Expedition to the Glacial Shelf","The Frost Sovereign","The Submerged Vault",
      "The Archivist Promotion","The Cloud-Grid Ascension","Awakening the Sages",
      "The Citadel Inversion","The Gateway Alignment","The Matrix Intervention",
      "The Grand Unification Symphony"
    };
    const char* objectives[] = {
      "Stabilize a frozen cavern and support a research team",
      "Shield young Eco-Kin at a sanctuary from discordant frequencies",
      "Defend acoustic monuments while soothing distressed Eco-Kin",
      "Initialize Archive monitoring without expanding the approved Dex",
      "Stabilize a geothermal rift before the valley ecosystem is damaged",
      "Purify a distressed geothermal guardian through thermal resonance",
      "Retune a remote communication array",
      "Survey unstable density fluctuations along a glacial route",
      "Calm a frost guardian with precisely timed Density pulses",
      "Explore submerged ruins and recover resonance records",
      "Complete calibration assessments to qualify as a senior Chronicler",
      "Restore sky-watchers' communications and secure a safe ascent",
      "Align nine acoustic monoliths through cooperative field puzzles",
      "Protect the ancient stronghold from frequency discordance",
      "Align ridge prisms to open the route to the Core Matrix",
      "Free Eco-Kin from an artificial alignment engine",
      "Synchronize Vibrance, Density, Harmony and Purity to restore the stream"
    };
    const unsigned regions[] = {9,1,4,0,6,6,2,9,9,5,0,7,0,8,12,13,13};
    for (unsigned i=0;i<17;++i)
      out.push_back({"RCH-"+std::to_string(i+1),OperationKind::RegionalChronicle,titles[i],objectives[i],regions[i],false,true});
    auto add=[&](unsigned id,OperationKind k,const std::string& title,const std::string& objective,unsigned region,bool postgame,bool authored=true) {
      out.push_back({"RED-"+std::to_string(id),k,title,objective,region,postgame,authored});
    };
    add(501,OperationKind::Community,"A Basic Resonance","Help an injured surveyor regulate distress using Harmony",1,false);
    add(502,OperationKind::Community,"The Lost Frequencies","Recover misplaced tuning forks through field scanning",0,false);
    add(503,OperationKind::Community,"Canopy Repair","Gather fallen resin to repair a frequency dampener",3,false);
    const char* essences[]={"Flora","Magma","Frost","Marine","Aero","Geo","Static","Umbral","Astral"};
    for(unsigned n=504;n<=512;++n) add(n,OperationKind::Vault,std::string(essences[n-504])+" Vault Calibration","Reach and align a unique Essence vault using approved traversal and resonance skills",0,false);
    for(unsigned n=513;n<=515;++n) add(n,OperationKind::Vault,"Vault Network Stabilization "+std::to_string(n-512),"Rebalance linked vault nodes after the nine calibrations",0,false);
    add(516,OperationKind::Stabilization,"Cleansing the Coastlines","Remove pollution from a coastal habitat without harming Eco-Kin",1,false);
    add(517,OperationKind::Stabilization,"The Geologist's Riddle","Recover naturally shed mineral samples for equipment calibration",2,false);
    for(unsigned n=518;n<=530;++n) add(n,OperationKind::ArchiveTrial,"Archive Alignment Trial "+std::to_string(n-517),"Complete a nonlethal regional frequency challenge",0,false);
    for(unsigned n=531;n<=536;++n) add(n,OperationKind::Shrine,"Shrine Resonance "+std::to_string(n-530),"Restore a dormant shrine and earn voluntary guardian trust",n%2?10u:11u,true);
    add(537,OperationKind::Finale,"Absolute Inception","Document the approved Permanent Dex and resolve the optional origin encounter",13,true);
    return out;
}
inline bool CanStartRegional(const RegionalOperation& op,
                            const std::set<std::string>& completed,
                            bool mainCampaignComplete,
                            unsigned documentedApprovedDexEntries) {
    if (!op.authored || (op.postgame && !mainCampaignComplete)) return false;
    if (op.id=="RED-537") {
        if (documentedApprovedDexEntries < 125) return false;
        for(unsigned n=501;n<=536;++n)
            if (!completed.count("RED-"+std::to_string(n))) return false;
    }
    if (op.id=="RCH-17" && !completed.count("RCH-16")) return false;
    return true;
}
} // namespace Echohearts::Missions
