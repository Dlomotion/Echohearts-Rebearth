#include "EchoheartsMissionRegistry.hpp"
#include <cassert>
#include <set>
int main() {
    using namespace Echohearts::Missions;
    auto missions = BuildRegistry();
    assert(missions.size() == 256);
    std::set<std::string> ids;
    unsigned draft = 0;
    for (const auto& m : missions) {
        assert(ids.insert(Id(m.category,m.number)).second);
        if (m.status == Status::Draft) ++draft;
    }
    assert(draft == 19);
    Progress progress;
    for (const auto& m : missions) {
        if (m.category == Category::Eddy && (m.number == 199 || m.number == 200))
            assert(!progress.CanStart(m));
        if (m.status == Status::Placeholder) assert(!progress.Complete(m));
    }
    assert(progress.Complete(missions.front()));
    assert(progress.Has(Category::Chronicle,1));
    Progress loaded;
    loaded.ImportCompleted(progress.ExportCompleted(),missions);
    assert(loaded.Has(Category::Chronicle,1));
    return 0;
}
