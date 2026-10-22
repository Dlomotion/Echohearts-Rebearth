#pragma once
// Additive seasonal content definitions; portable C++17.
// Actual UE5.8 gameplay events and persistent profiles require integration.
#include <cstdint>
#include <set>
#include <string>
#include <vector>
namespace Echohearts::Missions {
enum class SeasonalState : std::uint8_t { Planned, Available, Retired };
struct SeasonalQuest {
 std::string seasonId; // stable content namespace, never re-used
 std::string questId;
 std::string title;
 std::string objective;
 std::string prerequisiteMissionId;
 std::string ecoKinReferenceId; // approved existing Dex ID or empty; no automatic canon promotion
 SeasonalState state;
};
inline bool IsValidSeasonalQuest(const SeasonalQuest& q) {
 return !q.seasonId.empty() && !q.questId.empty() &&
        q.questId.find("SEA-"+q.seasonId+"-")==0 &&
        !q.title.empty() && !q.objective.empty();
}
inline bool CanStartSeasonalQuest(const SeasonalQuest& q,
 const std::set<std::string>& completed, const std::set<std::string>& approvedEcoKinIds) {
 if (!IsValidSeasonalQuest(q) || q.state!=SeasonalState::Available) return false;
 if (!q.prerequisiteMissionId.empty() && !completed.count(q.prerequisiteMissionId)) return false;
 if (!q.ecoKinReferenceId.empty() && !approvedEcoKinIds.count(q.ecoKinReferenceId)) return false;
 return true;
}
inline bool ValidateSeasonalCatalog(const std::vector<SeasonalQuest>& quests) {
 std::set<std::string> ids;
 for(const auto& q:quests)
  if(!IsValidSeasonalQuest(q) || !ids.insert(q.questId).second) return false;
 return true;
}
} // namespace Echohearts::Missions
