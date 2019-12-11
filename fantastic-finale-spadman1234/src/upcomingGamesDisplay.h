#pragma once
#include "ofxGui.h"
#include "nbaGame.h"
#include "nbaTeamStats.h"

namespace user_interface {
class UpcomingGamesDisplay {
private:
    bool isVisible_;
	ofTrueTypeFont font;
	int selection_;
	int numGames_;
	std::vector<nba_stats::NbaGame> upcomingGames_;
	std::map<std::string, nba_stats::NbaTeamStats> teams_;

	std::string GetStringFromGame(nba_stats::NbaGame & game);

public:
    void setup(std::vector<nba_stats::NbaGame> & upcomingGames,
		std::map<std::string, nba_stats::NbaTeamStats> & teams);
	void draw();
	void handleInput(int keycode);
	static std::string BeautifyFloat(float val, int numDigitsAfterDecimal);
};
}