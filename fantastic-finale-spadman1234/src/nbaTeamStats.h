#pragma once
#include <map>

namespace nba_stats {
class NbaTeamStats {
private:
    std::string kTeamStatNames[15] = {"min",  "fgp",  "tpp", "ftp",  "orpg",
                                      "drpg", "trpg", "apg", "tpg",  "spg",
                                      "bpg",  "pfpg", "ppg", "oppg", "eff"};
	std::map<std::string, std::string> info_;
    std::map<std::string, float> stats_;
    /*
	float min_;  //average minutes
    float fgp_;  //field goal percentage
    float tpp_;
    float ftp_;  //free throw percentage
    float orpg_; //offensive rebounds per game
    float drpg_; //defensive rebounds per game
    float trpg_; //total rebounds per game
    float apg_;  //assists per game
    float tpg_;  //turnovers per game
    float spg_;  //steals per game
    float bpg_;  //blocks per game
    float pfpg_; //personal fouls per game
    float ppg_;  //points per game
    float oppg_; //opponents points per game
    float eff_;  //efficiency
	*/
public:
    nba_stats::NbaTeamStats::NbaTeamStats();
	NbaTeamStats(std::map<std::string, std::string>& info,
                 std::map<std::string, float>& stats);
    void init(std::map<std::string, std::string>& info,
                  std::map<std::string, float>& stats);
    float GetStat(std::string statid);
    std::string GetInfo(std::string infoid);
};
}