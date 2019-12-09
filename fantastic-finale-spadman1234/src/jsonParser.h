#pragma once
#include <map>
#include <string>
#include "rapidjson/document.h"
#include "rapidjson/pointer.h"
#include "nbaTeamStats.h"
#include <iostream>
#include "nbaGame.h"


namespace nba_stats {
bool GetTeamStatsFromJson(NbaTeamStats &team, std::string teamcode, std::string json);
bool GetUpcomingGameFromJson(NbaGame &game, int gameNum, std::string json);
bool SetTeamWinsLossesFromJson(NbaTeamStats &team, std::string json);
}