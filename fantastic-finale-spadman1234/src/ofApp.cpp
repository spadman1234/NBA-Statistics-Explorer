#include "ofApp.h"
#include <map>
#include "jsonParser.h"
#include "nbaGame.h"
#include "nbaScraper.h"
#include "nbaTeamStats.h"
#include "upcomingGamesDisplay.h"

std::vector<nba_stats::NbaGame> upcomingGames;
std::map<std::string, nba_stats::NbaTeamStats> teams;
user_interface::UpcomingGamesDisplay upcomingGamesDisplay;
//--------------------------------------------------------------
void ofApp::setup() {
    ofBackground(50, 50, 50);

    nba_stats::GetUpcomingGames(upcomingGames);
    nba_stats::GetTeams(teams);

    upcomingGamesDisplay.setup(upcomingGames, teams);
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() { upcomingGamesDisplay.draw();  }

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	upcomingGamesDisplay.handleInput(key);
}

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
