#pragma once
#include <string>

namespace nba_stats {

class NbaGame {
private:
    std::string homeTeam_;
	std::string awayTeam_;
    std::string date_;
    bool isUpcoming_;
    int homeTeamPoints_;
    int awayTeamPoints_;
    float homeTeamHandicap_;
    bool isHomeTeamFavorite_;

public:
    NbaGame();
    void init(std::string homeTeam, std::string awayTeam, std::string date,
            bool isUpcoming, int homeTeamPoints, int awayTeamPoints,
            float homeTeamHandicap, bool isHomeTeamFavorite);
	std::string getHomeTeam();
    std::string getAwayTeam();
    std::string getDate();
    bool getIsUpcoming();
    int getHomeTeamPoints();
    int getAwayTeamPoints();
    float getHomeTeamHandicap();
    bool getIsHomeTeamFavorite();
    bool homeTeamWon();
};

}