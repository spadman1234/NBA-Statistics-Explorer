#include "ofApp.h"
#include "jsonParser.h"
#include "nbaScraper.h"
#include "nbaTeamStats.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofBackground(80, 80, 80);
    std::string json = nba_stats::GetStrContentsFromUrl("http://data.nba.net/10s/prod/v1/2019/team_stats_rankings.json");
    nba_stats::NbaTeamStats hawksStats;
	nba_stats::GetTeamStatsFromJson(hawksStats, "hawks", json);
    auto ppg = hawksStats.GetStat("apg");
    printf("%g\n", ppg);
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
