#pragma once

namespace nba_stats {
class NbaTeamStats {
private:
    std::string city_;
	std::string teamname_;
    std::string abbreviation_;
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
    NbaTeamStats(std::string city, std::string teamname,
                 std::string abbreviation, std::map<std::string, float> &stats);
	float GetStat(std::string statname);
    std::string GetCity();
    std::string GetTeamName();
    std::string GetAbbreviation();
};
}