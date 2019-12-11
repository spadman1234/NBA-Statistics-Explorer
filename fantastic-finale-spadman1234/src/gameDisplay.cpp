#include "gameDisplay.h"
#include "upcomingGamesDisplay.h"

//-------------------------------------
const std::map<std::string, std::string> NAME_TO_NICKNAME_MAP = {
{"Atlanta Hawks", "ATL"}, {"Brooklyn Nets","BKN"}, {"Boston Celtics", "BOS"}, 
{"Charlotte Hornets", "CHA"}, {"Chicago Bulls", "CHI"}, {"Cleveland Cavaliers", "CLE"}, 
{"Dallas Mavericks", "DAL"}, {"Denver Nuggets", "DEN"}, {"Detroit Pistons", "DET"}, 
{"Golden State Warriors", "GSW"}, {"Houston Rockets", "HOU"}, {"Indiana Pacers", "IND"}, 
{"Los Angeles Clippers", "LAC"}, {"Los Angeles Lakers", "LAL"}, {"Memphis Grizzlies", "MEM"}, 
{"Miami Heat", "MIA"}, {"Milwaukee Bucks", "MIL"}, {"Minnesota Timberwolves", "MIN"}, 
{"New Orleans Pelicans", "NOP"}, {"New York Knicks", "NYK"}, {"Oklahoma City Thunder", "OKC"}, 
{"Orlando Magic", "ORL"}, {"Philadelphia 76ers", "PHI"}, {"Phoenix Suns", "PHX"}, 
{"Portland Trail Blazers", "POR"}, {"Sacramento Kings", "SAC"}, {"San Antonio Spurs", "SAS"}, 
{"Toronto Raptors", "TOR" }, { "Utah Jazz", "UTA" }, { "Washington Wizards", "WAS" } };

const int FONT_SIZE = 30;
const int X_PADDING = 50;
const int Y_PADDING = 50;
const int Y_OFFSET = 50;
const int NUM_STATS = 15;
const std::string STATS[NUM_STATS] = { "min",  "fgp",  "tpp", "ftp",  "orpg",
									  "drpg", "trpg", "apg", "tpg",  "spg",
									  "bpg",  "pfpg", "ppg", "oppg", "eff" };


void user_interface::GameDisplay::drawTeamStats(nba_stats::NbaTeamStats & team, bool leftSide)
{
	if (leftSide) {
		font.drawString(team.GetInfo("name"), 
			ofGetWidth() / 2 - X_PADDING - font.stringWidth(team.GetInfo("name")), 
			Y_PADDING);
		std::string record = std::to_string(team.GetWins()) + " - " + std::to_string(team.GetLosses());
		font.drawString(record, ofGetWidth() / 2 - X_PADDING - font.stringWidth(record),
			Y_PADDING + Y_OFFSET);
		for (int i = 0; i < NUM_STATS; i++) {
			std::string toPrint = user_interface::UpcomingGamesDisplay::BeautifyFloat(team.GetStat(STATS[i]), 2);
			font.drawString(toPrint, ofGetWidth() / 2 - X_PADDING - font.stringWidth(toPrint), Y_PADDING + (i + 3) * Y_OFFSET);
		}
	}
	else {
		font.drawString(team.GetInfo("name"), ofGetWidth() / 2 + X_PADDING, Y_PADDING);
		font.drawString(std::to_string(team.GetWins()) + " - " + std::to_string(team.GetLosses()),
			ofGetWidth() / 2 + X_PADDING, 
			Y_PADDING + Y_OFFSET);
		for (int i = 0; i < NUM_STATS; i++) {
			font.drawString(user_interface::UpcomingGamesDisplay::BeautifyFloat(team.GetStat(STATS[i]), 2), ofGetWidth() / 2 + X_PADDING, Y_PADDING + (i + 3) * Y_OFFSET);
		}
	}
}

void user_interface::GameDisplay::setup(nba_stats::NbaGame & game, std::map<std::string, nba_stats::NbaTeamStats>& teams)
{
	game_ = game;
	std::string hometeamAbbreviation = NAME_TO_NICKNAME_MAP.at(game_.getHomeTeam());
	std::string awayteamAbbreviation = NAME_TO_NICKNAME_MAP.at(game_.getAwayTeam());
	hometeam_ = teams[hometeamAbbreviation];
	awayteam_ = teams[awayteamAbbreviation];
	isVisible_ = true;
	font.load("arial.ttf", FONT_SIZE);
}

void user_interface::GameDisplay::draw()
{
	if (isVisible_) {
		drawTeamStats(hometeam_, false);
		drawTeamStats(awayteam_, true);
		font.drawString("@", ofGetWidth() / 2 - font.stringWidth("@") / 2, Y_PADDING);
		for (int i = 0; i < NUM_STATS; i++) {
			font.drawString(STATS[i], ofGetWidth() / 2 - 6 * X_PADDING, Y_PADDING + (i + 3) * Y_OFFSET);
		}
	}
}

// Returns true if the parent UI should become visible
bool user_interface::GameDisplay::handleInput(int keycode) {
	if (isVisible_) {
		if (keycode == 8) {
			isVisible_ = false;
			return true;
		}
	}
	return false;
}