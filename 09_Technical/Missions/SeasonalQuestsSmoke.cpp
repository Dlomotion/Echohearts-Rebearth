#include "EchoheartsSeasonalQuests.hpp"
#include <cassert>
int main(){
 using namespace Echohearts::Missions;
 SeasonalQuest q{"S01","SEA-S01-001","Seasonal Drift Survey","Stabilize a local frequency node","CHR-001","",SeasonalState::Available};
 assert(IsValidSeasonalQuest(q));
 assert(ValidateSeasonalCatalog({q}));
 assert(!ValidateSeasonalCatalog({q,q}));
 assert(!CanStartSeasonalQuest(q,{},{}));
 assert(CanStartSeasonalQuest(q,{"CHR-001"},{}));
 q.ecoKinReferenceId="DEX-001";
 assert(!CanStartSeasonalQuest(q,{"CHR-001"},{}));
 assert(CanStartSeasonalQuest(q,{"CHR-001"},{"DEX-001"}));
 return 0;
}
