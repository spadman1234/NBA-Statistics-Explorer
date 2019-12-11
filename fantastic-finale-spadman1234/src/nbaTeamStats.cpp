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
	avgPointDifferential_ = stats_["ppg"] - stats_["oppg"];
}

float nba_stats::NbaTeamStats::GetStat(std::string statname) {
    return stats_[statname];
}

std::string nba_stats::NbaTeamStats::GetInfo(std::string infoid) {
    return info_[infoid];
}

void nba_stats::NbaTeamStats::SetWinsLosses(int wins, int losses) {
    wins_ = wins;
    losses_ = losses;
    winpctg_ = (float)wins / (float)(losses + wins);
}

int nba_stats::NbaTeamStats::GetWins() { return wins_; }

int nba_stats::NbaTeamStats::GetLosses() { return losses_; }

float nba_stats::NbaTeamStats::GetWinPercentage() { return winpctg_; }

float nba_stats::NbaTeamStats::GetAvgPointDifferential() { return avgPointDifferential_; }