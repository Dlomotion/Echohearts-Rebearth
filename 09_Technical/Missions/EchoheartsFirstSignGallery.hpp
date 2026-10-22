#pragma once
#include <string_view>
namespace Echohearts::Missions {
inline constexpr std::string_view FirstSignQuestId="HUNT-FIRST-SIGN";
struct ResearchGallerySubmission {
 std::string_view approvedDexId;
 bool approvedDexRecord=false;
 bool photoVerified=false;
 bool provenanceVerified=false;
 bool invasiveCollection=false;
 bool consentBoundaryRespected=false;
 constexpr bool CanExhibit() const {
  return !approvedDexId.empty() && approvedDexRecord && photoVerified &&
   provenanceVerified && !invasiveCollection && consentBoundaryRespected;
 }
};
enum class FirstSignStage { Briefing, ReadTrail, VerifyHabitat, ObserveAtDistance, Photograph, SubmitToChronicler };
} // namespace Echohearts::Missions
