#include "regressionWizard.h"

//-------------------------------
const int NUM_STATS = 15;
const std::string STATS[NUM_STATS] = { "min",  "fgp",  "tpp", "ftp",  "orpg",
									  "drpg", "trpg", "apg", "tpg",  "spg",
									  "bpg",  "pfpg", "ppg", "oppg", "eff" };
const int FONT_SIZE = 30;
const int X_PADDING = 50;
const int Y_PADDING = 50;
const int Y_OFFSET = 50;
const int UP_ARROW_KEYCODE = 57357;
const int DOWN_ARROW_KEYCODE = 57359;
const int ENTER_KEYCODE = 13;
const int BACKSPACE_KEYCODE = 8;
const int R_KEYCODE = 114;
const char *CSV_FILENAME = "trainingdata.csv";
const int MAX_ITERATION = 10000;
const float LEARNING_RATE = 0.001;
const int NUM_TEAMS = 30;
//-------------------------------

LinearRegressionModel user_interface::RegressionWizard::createLinearRegressionModel()
{
	// Create csv file
	std::ofstream csvFile;
	csvFile.open(CSV_FILENAME);
	for (auto pair : teams_) {
		nba_stats::NbaTeamStats team = pair.second;
		csvFile << "1,";
		for (int i = 0; i < NUM_STATS; i++) {
			if (statSelections_[i]) {
				csvFile << team.GetStat(STATS[i]) << ",";
			}
			else {
				csvFile << "0,";
			}
		}
		// Add dependent variable at the end of each line
		csvFile << team.GetWinPercentage() * 100 << "\n";
	}
	csvFile.close();

	// Load into Dataset object
	Dataset data = read_csv(CSV_FILENAME);

	// Create LinearRegressionModel object
	model = LinearRegressionModel(data);

	// Train LinearRegressionModel
	model.train(MAX_ITERATION, LEARNING_RATE);
	model.print_weights();

	return model;
}

void user_interface::RegressionWizard::setup(std::map<std::string, nba_stats::NbaTeamStats> & teams)
{
	isVisible_ = true;
	modelCreated_ = false;
	font.load("arial.ttf", FONT_SIZE);
	selection_ = 0;
	for (bool b : statSelections_) {
		b = false;
	}
	teams_ = teams;
}

void user_interface::RegressionWizard::draw()
{
	if (isVisible_) {
		if (!modelCreated_) {
			font.drawString("Use [ENTER] to select the independent variables and [R] to create a model.", X_PADDING, Y_PADDING);
			for (int i = 0; i < NUM_STATS; i++) {
				if (selection_ == i) {
					ofSetColor(250, 255, 95);
				}
				else if (statSelections_[i]) {
					ofSetColor(51, 255, 51);
				}
				else {
					ofSetColor(255, 255, 255);
				}
				font.drawString(STATS[i], X_PADDING, Y_PADDING + (i + 2) * Y_OFFSET);
			}
		}
		else {
			font.drawString("Your model predicts the following win percentages:", X_PADDING, Y_PADDING);
			int n = 0;
			for (auto pair : teams_) {
				float statsArr[NUM_STATS + 1];
				statsArr[0] = 1;
				for (int i = 0; i < NUM_STATS; i++) {
					statsArr[i + 1] = pair.second.GetStat(STATS[i]);
				}
				float winpctg = model.predict(statsArr);
				std::string s = pair.second.GetInfo("name") + " - " + std::to_string(winpctg);
				if (n < 15) {
					font.drawString(s, X_PADDING, Y_PADDING + (n + 2) * Y_OFFSET);
				}
				else {
					font.drawString(s, ofGetWidth() / 2, Y_PADDING + (n - 13) * Y_OFFSET);
				}
				n++;
			}
		}
	}
}

bool user_interface::RegressionWizard::handleInput(int keycode)
{
	if (isVisible_) {
		if (!modelCreated_) {
			if (keycode == UP_ARROW_KEYCODE && selection_ > 0) {
				selection_ -= 1;
			}
			else if (keycode == DOWN_ARROW_KEYCODE && selection_ < NUM_STATS - 1) {
				selection_ += 1;
			}
			else if (keycode == ENTER_KEYCODE) {
				statSelections_[selection_] = !statSelections_[selection_];
			}
			else if (keycode == BACKSPACE_KEYCODE) {
				isVisible_ = false;
				return true;
			}
			else if (keycode == R_KEYCODE) {
				model = createLinearRegressionModel();
				modelCreated_ = true;
				selection_ = 0;
			}
		}
		else {
			if (keycode == UP_ARROW_KEYCODE && selection_ > 0) {
				selection_ -= 1;
			}
			else if (keycode == DOWN_ARROW_KEYCODE && selection_ < NUM_TEAMS) {
				selection_ += 1;
			}
			else if (keycode == ENTER_KEYCODE) {
				statSelections_[selection_] = !statSelections_[selection_];
			}
			else if (keycode == BACKSPACE_KEYCODE) {
				isVisible_ = false;
				return true;
			}
		}
	}
	return false;
}
