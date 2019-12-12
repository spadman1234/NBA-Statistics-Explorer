#pragma once
#include "ofxGui.h"
#include "nbaGame.h"
#include "nbaTeamStats.h"
#include "regression/model.h"

namespace user_interface {
class RegressionWizard {
private:
	bool isVisible_;
	bool modelCreated_;
	ofTrueTypeFont font;
	int selection_;
	bool statSelections_[14];
	std::map<std::string, nba_stats::NbaTeamStats> teams_;
	LinearRegressionModel model;

	LinearRegressionModel createLinearRegressionModel();

public:
	void setup(std::map<std::string, nba_stats::NbaTeamStats> & teams);
	void draw();
	bool handleInput(int keycode);
};
}