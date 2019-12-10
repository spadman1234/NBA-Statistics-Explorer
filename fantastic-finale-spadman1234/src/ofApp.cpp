#include "ofApp.h"
#include "jsonParser.h"
#include "nbaScraper.h"
#include "nbaTeamStats.h"
#include "nbaGame.h"
#include <map>


//--------------------------------------------------------------
void ofApp::setup() {

    ofBackground(50, 50, 50);

	std::vector<nba_stats::NbaGame> upcomingGames;
    nba_stats::GetUpcomingGames(upcomingGames);
    
	std::map<std::string, nba_stats::NbaTeamStats> teams;
    nba_stats::GetTeams(teams);
    std::cout << teams["NYK"].GetWinPercentage() << std::endl;

	/*
    std::string teamStatsJson = nba_stats::GetStrContentsFromUrl(TEAM_STATS_URL);
    nba_stats::NbaTeamStats knicksStats;
    nba_stats::GetTeamStatsFromJson(knicksStats, "knicks", teamStatsJson);
    std::cout << knicksStats.GetInfo("name") << std::endl;

	std::string recordsJson = nba_stats::GetStrContentsFromUrl(RECORDS_URL.c_str());
    nba_stats::SetTeamWinsLossesFromJson(knicksStats, recordsJson);
    std::cout << "wins: " << knicksStats.GetWins() << std::endl;
    std::cout << "losses: " << knicksStats.GetLosses() << std::endl;
    std::cout << "win pctg: " << knicksStats.GetWinPercentage() << std::endl;

	
	std::string upcomingGamesJson = nba_stats::GetStrContentsFromUrl(SPREADS_URL.c_str());
    nba_stats::NbaGame game;
    nba_stats::GetUpcomingGameFromJson(game, 0, upcomingGamesJson);
    std::cout << game.getIsHomeTeamFavorite() << std::endl;
	*/
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
