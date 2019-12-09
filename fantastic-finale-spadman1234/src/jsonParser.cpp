#include "jsonParser.h"

namespace nba_stats {
bool GetTeamStatsFromJson(NbaTeamStats &team, std::string teamcode, std::string json) {
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
        //std::cout << document["league"]["standard"]["regularSeason"]["teams"][i]["teamcode"].GetString() << std::endl;
        if (document["league"]["standard"]["regularSeason"]["teams"][i]
                    ["teamcode"].GetString() == teamcode) {
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
	auto gameJson = document["games"][gameId.c_str()].GetObject();
	
    std::string awayTeam = gameJson["awayTeam"].GetString();
    std::string homeTeam = gameJson["homeTeam"].GetString();
    std::string date = gameJson["startDate"].GetString();
    float homeTeamHandicap = std::stof(gameJson["gameSpreadHomeHandicap"].GetString());
    bool isHomeTeamFavored = (homeTeamHandicap < 0);

	game.init(homeTeam, awayTeam, date, true, 0, 0, homeTeamHandicap,
                       isHomeTeamFavored);
    return true;
}
}