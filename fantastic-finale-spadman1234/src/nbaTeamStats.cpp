#include "nbaTeamStats.h"
#include <map>
#include <string>
#include "assert.h"

nba_stats::NbaTeamStats::NbaTeamStats() {}

nba_stats::NbaTeamStats::NbaTeamStats(std::map<std::string, std::string>& info,
                                      std::map<std::string, float>& stats) {
    info_ = info;
    stats_ = stats;
}

void nba_stats::NbaTeamStats::init(std::map<std::string, std::string>& info,
                                   std::map<std::string, float>& stats) {
    info_ = info;
    stats_ = stats;
}

float nba_stats::NbaTeamStats::GetStat(std::string statname) {
    return stats_[statname];
}

std::string nba_stats::NbaTeamStats::GetInfo(std::string infoid) {
    return info_[infoid];
}