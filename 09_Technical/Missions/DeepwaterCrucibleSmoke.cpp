#include "EchoheartsDeepwaterCrucible.hpp"
#include <cassert>
#include <set>
#include <string_view>
int main(){
 using namespace Echohearts::Missions;
 static_assert(DeepwaterCrucibleQuests.size()==36);
 std::set<std::string_view> ids;
 for(auto q:DeepwaterCrucibleQuests){ assert(ids.insert(q.id).second); assert(!q.title.empty()); }
 CrucibleSession s;
 assert(!s.CanContinue());
 s.tamerConsents=s.ecoKinConsents=true;
 assert(s.CanContinue());
 s.sharedStrain=100; assert(!s.CanContinue());
 s.sharedStrain=0; s.ecoKinYielded=true; assert(!s.CanContinue());
}
