#include "upcomingGamesDisplay.h"
#include "gameDisplay.h"

//-------------------------------------
const int Y_PADDING          = 50;
const int X_PADDING          = 50;
const int Y_OFFSET           = 50;
const int FONT_SIZE          = 30;
const std::string FONT_NAME  = "arial.ttf";
const int UP_ARROW_KEYCODE   = 57357;
const int DOWN_ARROW_KEYCODE = 57359;
const int ENTER_KEYCODE      = 13;
user_interface::GameDisplay gameDisplay;
//-------------------------------------

std::string user_interface::UpcomingGamesDisplay::GetStringFromGame(nba_stats::NbaGame & game) {
	std::string game_string = "";
	game_string = game_string + game.getAwayTeam() + " @ ";
	game_string = game_string + game.getHomeTeam();
	game_string = game_string + " " + BeautifyFloat(game.getHomeTeamHandicap(), 1);
	return game_string;
}


std::string user_interface::UpcomingGamesDisplay::BeautifyFloat(float val, int digitsAfterDecimal)
{
	std::string tr = std::to_string(val);
	if (val > 0 && digitsAfterDecimal == 1) {
		tr = "+" + tr;
	}
	return tr.substr(0, tr.find(".") + 1 + digitsAfterDecimal);
}

void user_interface::UpcomingGamesDisplay::setup(std::vector<nba_stats::NbaGame> & upcomingGames, 
												 std::map<std::string, nba_stats::NbaTeamStats> & teams) {
	assert(font.load(FONT_NAME, FONT_SIZE));
	isVisible_ = true;
	selection_ = 0;
	teams_ = teams;
	for (nba_stats::NbaGame game : upcomingGames) {
		if (game.getIsUpcoming()) {
			upcomingGames_.emplace_back(game);
		}
	}
	numGames_ = upcomingGames_.size();
}

void user_interface::UpcomingGamesDisplay::draw() {
	if(isVisible_) {
		font.drawString("UPCOMING GAMES:", X_PADDING, Y_PADDING);
		for (int i = 0; i < upcomingGames_.size(); i++) {
			if (selection_ == i) {
				ofSetColor(250, 255, 95);
			}
			else {
				ofSetColor(255, 255, 255);
			}

			font.drawString(GetStringFromGame(upcomingGames_.at(i)), X_PADDING, Y_PADDING + (i + 1) * Y_OFFSET);
		}
	}
	else {
		gameDisplay.draw();
	}
	ofSetColor(255, 255, 255);
}

void user_interface::UpcomingGamesDisplay::handleInput(int keycode)
{ 
	if (keycode == UP_ARROW_KEYCODE && selection_ > 0) {
		selection_ -= 1;
	}
	else if (keycode == DOWN_ARROW_KEYCODE && selection_ < numGames_ - 1) {
		selection_ += 1;
	}
	else if (keycode == ENTER_KEYCODE) {
		isVisible_ = false;
		gameDisplay.setup(upcomingGames_.at(selection_), teams_);
	}
}
