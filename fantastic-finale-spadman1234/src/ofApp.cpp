#include "ofApp.h"
#include "jsonParser.h"
#include "nbaScraper.h"
#include "nbaTeamStats.h"
#include "nbaGame.h"


//--------------------------------------------------------------
void ofApp::setup() {

	const std::string API_KEY = "2cc356db0ca76add241dadd37a828808";

    ofBackground(80, 80, 80);

    std::string teamStatsJson = nba_stats::GetStrContentsFromUrl(
        "http://data.nba.net/10s/prod/v1/2019/team_stats_rankings.json");
    nba_stats::NbaTeamStats knicksStats;
    nba_stats::GetTeamStatsFromJson(knicksStats, "heat", teamStatsJson);
    std::cout << knicksStats.GetStat("orpg") << std::endl;

	std::string upcomingGamesJsonUrl =
        "https://203.cheapdatafeeds.com/api/json/odds-main/v1/basketball/"
        "nba?api-key=" +
        API_KEY;
	std::string upcomingGamesJson = nba_stats::GetStrContentsFromUrl(upcomingGamesJsonUrl.c_str());
    nba_stats::NbaGame game;
    nba_stats::GetUpcomingGameFromJson(game, 0, upcomingGamesJson);
    std::cout << game.getAwayTeam() << std::endl;
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
