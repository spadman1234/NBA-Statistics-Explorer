#pragma comment(lib, "urlmon.lib")

#include "nbaScraper.h"
#include <urlmon.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <curl/curl.h>
#include "jsonParser.h"

using namespace std;

const char* TMP_FILENAME = "tmpdata";
const std::string API_KEY = "2cc356db0ca76add241dadd37a828808";
const std::string SPREADS_URL =
    "https://203.cheapdatafeeds.com/api/json/odds-main/v1/basketball/"
    "nba?api-key=" +
    API_KEY;
const char* TEAM_STATS_URL =
    "http://data.nba.net/10s/prod/v1/2019/team_stats_rankings.json";
const std::string RECORDS_URL =
    "http://data.nba.net/prod/v1/current/standings_all.json";

std::string nba_stats::GetStrContentsFromUrl(const char* url) {
	CURL *curl;
    curl = curl_easy_init();
	
	FILE *fp;
    fopen_s(&fp, "tmpdata", "wb");

	curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);

	auto result = curl_easy_perform(curl);
	
	std::string filecontents = "";

	fclose(fp);

	if (result != CURLE_OK) {
		std::cerr << curl_easy_strerror(result);
	}
	else {
		filecontents = GetStrContentsFromFile("tmpdata");
	}
	
    curl_easy_cleanup(curl);
    return filecontents;
}

std::string nba_stats::GetStrContentsFromFile(std::string filename) {
    // The following code is adapted from:
    // https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring
    std::ifstream t(filename);
    std::stringstream buffer;
    buffer << t.rdbuf();
    t.close();
    return buffer.str();
}

bool nba_stats::GetUpcomingGames(std::vector<NbaGame>& gamesVector) {
    std::string upcomingGamesJson =
        nba_stats::GetStrContentsFromUrl(SPREADS_URL.c_str());
    int i = 0;
    NbaGame game;
    while (nba_stats::GetUpcomingGameFromJson(game, i, upcomingGamesJson)) {
        gamesVector.emplace_back(game);
        i++;
	}
    return true;
}

bool nba_stats::GetTeams(std::map<std::string, NbaTeamStats>& teamMap) {
    const std::string TEAM_ABBREVIATIONS[30] = {
        "ATL", "BKN", "BOS", "CHA", "CHI", "CLE", "DAL", "DEN", "DET", "GSW",
        "HOU", "IND", "LAC", "LAL", "MEM", "MIA", "MIL", "MIN", "NOP", "NYK",
        "OKC", "ORL", "PHI", "PHX", "POR", "SAC", "SAS", "TOR", "UTA", "WAS"};
    const std::string teamStatsJson =
        nba_stats::GetStrContentsFromUrl(TEAM_STATS_URL);
    const std::string teamRecordsJson =
        nba_stats::GetStrContentsFromUrl(RECORDS_URL.c_str());

	for (std::string teamAbbreviation : TEAM_ABBREVIATIONS) {
        NbaTeamStats teamStats;
        GetTeamStatsFromJson(teamStats, teamAbbreviation, teamStatsJson);
        SetTeamWinsLossesFromJson(teamStats, teamRecordsJson);
        teamMap[teamAbbreviation] = teamStats;
	}
    return true;
}
