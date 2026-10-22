#pragma once
// Echohearts mission registry patch; portable C++17 core, no Unreal dependencies.
// Adapt through the existing UE5.8 mission subsystem; not a replacement for canon.
#include <array>
#include <cstdint>
#include <string>
#include <unordered_set>
#include <vector>

namespace Echohearts::Missions {
enum class Category : std::uint8_t { Chronicle, Anomaly, Eddy };
enum class Status : std::uint8_t { Placeholder, Draft };
struct Definition {
    Category category;
    std::uint16_t number;
    std::string title;
    Status status;
    std::string objective;
};
inline std::string Id(Category category, unsigned number) {
    const char* prefix = category == Category::Chronicle ? "CHR" :
                         category == Category::Anomaly ? "ANO" : "EDY";
    return std::string(prefix) + "-" + (number < 10 ? "00" : number < 100 ? "0" : "") + std::to_string(number);
}
inline std::vector<Definition> BuildRegistry() {
    std::vector<Definition> result;
    result.reserve(256);
    for (unsigned n = 1; n <= 42; ++n) result.push_back({Category::Chronicle, static_cast<std::uint16_t>(n), "", Status::Placeholder, ""});
    for (unsigned n = 1; n <= 14; ++n) result.push_back({Category::Anomaly, static_cast<std::uint16_t>(n), "", Status::Placeholder, ""});
    for (unsigned n = 1; n <= 200; ++n) result.push_back({Category::Eddy, static_cast<std::uint16_t>(n), "", Status::Placeholder, ""});
    auto draft = [&](Category c, unsigned n, const char* title, const char* objective) {
        for (auto& m : result) if (m.category == c && m.number == n) {
            m.title = title; m.objective = objective; m.status = Status::Draft; return;
        }
    };
    draft(Category::Chronicle,1,"The First Pulse","Awaken Echoheart and select foundational companion; reconcile Spark terminology");
    draft(Category::Chronicle,2,"Outlining the Wild Grids","Survey three unstable zones and place three pylons");
    draft(Category::Chronicle,3,"The Royale Ingress","Register for an arena trial and complete introductory synchronization clash");
    draft(Category::Chronicle,4,"Hotel Prime Investigations","Locate and dispel the fourth-floor distortion; location provisional");
    draft(Category::Chronicle,5,"Securing the Outskirts","Purify the Zone 3 perimeter threat");
    draft(Category::Chronicle,9,"Unlocking the Transcendence Ring","Solve refraction puzzle and confront archive guardian; artifact provisional");
    draft(Category::Chronicle,15,"The Rogue Transcendent Threat","Track and pacify unstable entity");
    draft(Category::Chronicle,25,"Purifying the Central Core","Escort cleansing device; shield integrity must remain above 40 percent");
    draft(Category::Chronicle,35,"Climbing the Tournament Ranks","Complete five consecutive arena challenges");
    draft(Category::Chronicle,36,"The Prism Spire Siege","Defend energy conduit for three waves");
    draft(Category::Chronicle,40,"Binding the Prime Archons","Resolve dual-force encounter through Binding; entities provisional");
    draft(Category::Chronicle,42,"The Infinite Inception","Resolve final encounter and unlock postgame bracket");
    draft(Category::Anomaly,1,"Distant Echoes","Scan fracture and trace acoustic frequency");
    draft(Category::Anomaly,7,"Lost In Time","Navigate inverted-gravity environment and retrieve keycard");
    draft(Category::Anomaly,14,"The Final Rift","Complete final fracture encounter for cosmetics");
    draft(Category::Eddy,12,"Spark Catalyst Procurement","Collect five shards and deliver to craftsperson; reward requires canon review");
    draft(Category::Eddy,45,"The Luminescent Tracker","Safely locate and Bind rare glowing Eco-Kin variant; identity requires Dex review");
    draft(Category::Eddy,199,"The Grand Finale Trials","Complete Eddies 1 through 198 before endurance challenge");
    draft(Category::Eddy,200,"Absolute Inception","Secret finale unlocked by all Chronicles, Anomalies and Eddies 1-199");
    return result;
}
class Progress {
public:
    bool Complete(const Definition& mission) {
        if (mission.status != Status::Draft || !CanStart(mission)) return false;
        completed_.insert(Id(mission.category, mission.number));
        return true;
    }
    bool Has(Category category, unsigned number) const { return completed_.count(Id(category, number)) != 0; }
    bool CanStart(const Definition& mission) const {
        if (mission.status != Status::Draft) return false;
        if (mission.category == Category::Eddy && mission.number == 199) {
            for (unsigned n = 1; n <= 198; ++n) if (!Has(Category::Eddy,n)) return false;
        }
        if (mission.category == Category::Eddy && mission.number == 200) {
            for (unsigned n = 1; n <= 42; ++n) if (!Has(Category::Chronicle,n)) return false;
            for (unsigned n = 1; n <= 14; ++n) if (!Has(Category::Anomaly,n)) return false;
            for (unsigned n = 1; n <= 199; ++n) if (!Has(Category::Eddy,n)) return false;
        }
        return true;
    }
    std::vector<std::string> ExportCompleted() const { return {completed_.begin(), completed_.end()}; }
    void ImportCompleted(const std::vector<std::string>& ids, const std::vector<Definition>& registry) {
        completed_.clear();
        for (const auto& id : ids) for (const auto& mission : registry)
            if (mission.status == Status::Draft && id == Id(mission.category, mission.number))
                completed_.insert(id);
    }
private:
    std::unordered_set<std::string> completed_;
};
} // namespace Echohearts::Missions
