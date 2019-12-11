#include "jsonParser.h"

namespace nba_stats {
bool GetTeamStatsFromJson(NbaTeamStats &team, std::string teamAbbreviation, std::string json) {
    std::string kTeamStatNames[15] = {"min",  "fgp",  "tpp", "ftp",  "orpg",
                                  "drpg", "trpg", "apg", "tpg",  "spg",
                                  "bpg",  "pfpg", "ppg", "oppg", "eff"};

    rapidjson::Document document;
    document.Parse(json.c_str());
    assert(document.HasMember("league"));

    std::map<std::string, float> statmap;
    std::map<std::string, std::string> infomap;
    
	// Populate statmap with data from JSON
    int numTeams = document["league"]["standard"]["regularSeason"]["teams"].GetArray().Size();
    for (int i = 0; i < numTeams; i++) {
        if (document["league"]["standard"]["regularSeason"]["teams"][i]
                    ["abbreviation"].GetString() == teamAbbreviation) {
            for (std::string str : kTeamStatNames) {
                statmap[str] = std::stof(document["league"]["standard"]["regularSeason"]["teams"][i][str.c_str()]["avg"].GetString());
			}

            infomap["city"] =
				document["league"]["standard"]["regularSeason"]["teams"][i]["name"].GetString();
            infomap["name"] =
				document["league"]["standard"]["regularSeason"]["teams"][i]["nickname"].GetString();
            infomap["abbreviation"] = 
				document["league"]["standard"]["regularSeason"]["teams"][i]["abbreviation"].GetString();

            team.init(infomap, statmap);
            return true;
        }
	}
    return false;
}
bool GetUpcomingGameFromJson(NbaGame &game, int gameNum, std::string json) {
    rapidjson::Document document;
    document.Parse(json.c_str());
    assert(document.HasMember("games"));

	std::string gameId = std::to_string(gameNum);
    if (!document["games"].HasMember(gameId.c_str())) {
		return false;
    }
	auto gameJson = document["games"][gameId.c_str()].GetObject();
	
    std::string awayTeam = gameJson["awayTeam"].GetString();
    std::string homeTeam = gameJson["homeTeam"].GetString();
    std::string date = gameJson["startDate"].GetString();
	float homeTeamHandicap = 0;
	bool isHomeTeamFavored = false;
	if (gameJson.HasMember("gameSpreadHomeHandicap")) {
		homeTeamHandicap = std::stof(gameJson["gameSpreadHomeHandicap"].GetString());
		isHomeTeamFavored = (homeTeamHandicap < 0);
	}
	bool isUpcoming = true;
	std::string isLive = gameJson["isLive"].GetString();
	if (isLive.compare("1") == 0) {
		isUpcoming = false;
	}

	game.init(homeTeam, awayTeam, date, isUpcoming, 0, 0, homeTeamHandicap,
                       isHomeTeamFavored);
    return true;
}
bool SetTeamWinsLossesFromJson(NbaTeamStats &team, std::string json) { 
	rapidjson::Document document;
    document.Parse(json.c_str());

    std::string teamAbbreviation = team.GetInfo("abbreviation");

	int numTeams = document["league"]["standard"]["teams"].GetArray().Size();
    for (int i = 0; i < numTeams; i++) {
            if (document["league"]["standard"]["teams"][i]["teamSitesOnly"]
                        ["teamTricode"].GetString() == teamAbbreviation) {
				int wins = std::stoi(document["league"]["standard"]["teams"][i]["win"].GetString());
                int losses = std::stoi(document["league"]["standard"]["teams"][i]["loss"].GetString());
                team.SetWinsLosses(wins, losses);
                return true;
            }
	}
	return false;
}
}