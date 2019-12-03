#include "jsonParser.h"

namespace nba_stats {
nba_stats::NbaTeamStats GetTeamStatsFromJson(std::string teamcode, const char* json) {
    rapidjson::Document document;
    document.Parse(json);
    assert(document.HasMember("league"));
    return NULL;
}
}