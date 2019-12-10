#pragma once
#include "ofxGui.h"
#include "nbaGame.h"

namespace user_interface {
class UpcomingGamesDisplay {
private:
    bool isVisible_;
	ofTrueTypeFont font;
	int selection_;
	int numGames_;
	std::vector<nba_stats::NbaGame> upcomingGames_;

	std::string GetStringFromGame(nba_stats::NbaGame & game);
	std::string BeautifySpread(float val);

public:
    void setup(std::vector<nba_stats::NbaGame> & upcomingGames);
	void draw();
};
}