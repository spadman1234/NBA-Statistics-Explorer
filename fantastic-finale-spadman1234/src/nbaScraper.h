#pragma once

#include <map>
#include <string>
#include <vector>
#include "jsonParser.h"
#include "nbaGame.h"

namespace nba_stats {



std::string GetStrContentsFromUrl(const char* url);
std::string GetStrContentsFromFile(std::string filename);
bool GetUpcomingGames(std::vector<NbaGame>& gamesVector);
bool GetTeams(std::map<std::string, NbaTeamStats>& teamMap);
}  // namespace nba_stats