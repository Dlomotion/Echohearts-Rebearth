#include "EchoheartsRegionalExpansion.hpp"
#include <cassert>
#include <set>
int main() {
 using namespace Echohearts::Missions;
 const auto base=BuildRegistry();
 const auto extra=BuildRegionalExpansion();
 assert(base.size()==256 && extra.size()==54);
 std::set<std::string> ids;
 for(const auto& m:base) assert(ids.insert(Id(m.category,m.number)).second);
 for(const auto& m:extra) assert(ids.insert(m.id).second);
 unsigned regional=0,side=0;
 for(const auto& m:extra) {
  if(m.kind==OperationKind::RegionalChronicle) ++regional; else ++side;
  if(m.id=="RED-537") assert(!CanStartRegional(m,{},false,125));
 }
 assert(regional==17 && side==37);
 std::set<std::string> completed;
 for(unsigned n=501;n<=536;++n) completed.insert("RED-"+std::to_string(n));
 for(const auto& m:extra) if(m.id=="RED-537") {
  assert(!CanStartRegional(m,completed,true,124));
  assert(CanStartRegional(m,completed,true,125));
 }
 return 0;
}
