#pragma once
#include <map>
#include <string>
#include "rapidjson/document.h"
#include "nbaTeamStats.h"

namespace nba_stats {
nba_stats::NbaTeamStats GetTeamStatsFromJson(std::string teamcode, const char* json);
}