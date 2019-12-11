#pragma once
#include "ofxGui.h"
#include "nbaGame.h"
#include "nbaTeamStats.h"

namespace user_interface {
class GameDisplay {
private:
	bool isVisible_;
	ofTrueTypeFont font;
	nba_stats::NbaGame game_;
	nba_stats::NbaTeamStats hometeam_;
	nba_stats::NbaTeamStats awayteam_;

	void drawTeamStats(nba_stats::NbaTeamStats & team, bool leftSide);

public:
	void setup(nba_stats::NbaGame & game, std::map<std::string, nba_stats::NbaTeamStats> & teams);
	void draw();
};
}