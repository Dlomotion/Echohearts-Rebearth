#include "EchoheartsFieldResearchQuests.hpp"
#include <cassert>
#include <set>
#include <string>
int main(){
 using namespace Echohearts::Missions;
 static_assert(FieldResearchQuests.size()==42);
 std::set<std::string> ids;
 for(const auto& q:FieldResearchQuests){assert(ids.insert(std::string(q.id)).second);assert(!q.objective.empty());}
 std::set<std::string> approved{"APPROVED-DEX-ID"};
 std::set<std::string> completed;
 assert(!CanStartEcoKinResearch("UNKNOWN",EcoKinResearchStage::Observe,approved,completed));
 assert(CanStartEcoKinResearch("APPROVED-DEX-ID",EcoKinResearchStage::Observe,approved,completed));
 assert(!CanStartEcoKinResearch("APPROVED-DEX-ID",EcoKinResearchStage::Study,approved,completed));
 completed.insert(EcoKinResearchId("APPROVED-DEX-ID",EcoKinResearchStage::Observe));
 assert(CanStartEcoKinResearch("APPROVED-DEX-ID",EcoKinResearchStage::Study,approved,completed));
 assert(!CanStartFieldQuest(FieldResearchQuests[1],{}));
 assert(CanStartFieldQuest(FieldResearchQuests[1],{"MAP-01"}));
}
