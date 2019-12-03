#include "nbaTeamStats.h"
#include <string>
#include <map>

nba_stats::NbaTeamStats::NbaTeamStats(std::string city, std::string teamname,
                                      std::string abbreviation,
                                      std::map<std::string, float> &stats) {
    city_ = city;
    teamname_ = teamname;
    abbreviation_ = abbreviation;
    stats_ = stats;
}

float nba_stats::NbaTeamStats::GetStat(std::string statname) {
    return stats_[statname];
}

std::string nba_stats::NbaTeamStats::GetCity() { return city_; }

std::string nba_stats::NbaTeamStats::GetTeamName() { return teamname_; }

std::string nba_stats::NbaTeamStats::GetAbbreviation() { return abbreviation_; }
