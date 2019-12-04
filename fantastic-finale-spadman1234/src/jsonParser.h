#pragma once
#include <map>
#include <string>
#include "rapidjson/document.h"
#include "rapidjson/pointer.h"
#include "nbaTeamStats.h"
#include <iostream>

namespace nba_stats {
bool GetTeamStatsFromJson(NbaTeamStats &team, std::string teamcode, std::string json);
}