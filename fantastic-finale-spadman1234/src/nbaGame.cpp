#include "nbaGame.h"
#include <string>

namespace nba_stats {
NbaGame::NbaGame() {}
void NbaGame::init(std::string homeTeam, std::string awayTeam, std::string date,
                 bool isUpcoming, int homeTeamPoints, int awayTeamPoints,
                 float homeTeamHandicap, bool isHomeTeamFavorite) {
    homeTeam_ = homeTeam;
    awayTeam_ = awayTeam;
    date_ = date;
    isUpcoming_ = isUpcoming;
    homeTeamPoints_ = homeTeamPoints;
    awayTeamPoints_ = awayTeamPoints;
    homeTeamHandicap_ = homeTeamHandicap;
    isHomeTeamFavorite_ = isHomeTeamFavorite;
}
std::string NbaGame::getHomeTeam() { return homeTeam_; }
std::string NbaGame::getAwayTeam() { return awayTeam_; }
std::string NbaGame::getDate() { return date_; }
bool NbaGame::getIsUpcoming() { return isUpcoming_; }
int NbaGame::getHomeTeamPoints() { return homeTeamPoints_; }
int NbaGame::getAwayTeamPoints() { return awayTeamPoints_; }
float NbaGame::getHomeTeamHandicap() { return homeTeamHandicap_; }
bool NbaGame::getIsHomeTeamFavorite() { return isHomeTeamFavorite_; }
bool NbaGame::homeTeamWon() { return (homeTeamPoints_ > awayTeamPoints_); }
}  // namespace nba_stats