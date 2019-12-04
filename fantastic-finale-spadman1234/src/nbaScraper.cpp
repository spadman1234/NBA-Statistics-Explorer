#pragma comment(lib, "urlmon.lib")

#include "nbaScraper.h"
#include <urlmon.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <curl/curl.h>

using namespace std;

const char* TMP_FILENAME = "tmpdata";

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
