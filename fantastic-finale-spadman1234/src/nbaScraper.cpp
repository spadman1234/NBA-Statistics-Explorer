#pragma comment(lib, "urlmon.lib")

#include "nbaScraper.h"
#include <urlmon.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <curl/curl.h>

using namespace std;

string nbaScraper::get_str_contents_from_url(const char* url) {
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
		filecontents = get_str_contents_from_file("tmpdata");
	}
	
    curl_easy_cleanup(curl);
    return filecontents;
}


/*string nbaScraper::get_str_contents_from_url(wstring url) {
    // The following code is adapted from:
    // https://stackoverflow.com/questions/1011339/how-do-you-make-a-http-request-with-c/51959694#51959694
    IStream* stream;
    HRESULT result = URLOpenBlockingStream(0, url.c_str(), &stream, 0, 0);
    if (result != 0) {
        return "";
    }
    char buffer[100];
    unsigned long bytesRead;
    stringstream ss;
    stream->Read(buffer, 100, &bytesRead);
    while (bytesRead > 0U) {
        ss.write(buffer, (long long)bytesRead);
        stream->Read(buffer, 100, &bytesRead);
    }
    stream->Release();
    string resultString = ss.str();
    return resultString;
} */

std::string nbaScraper::get_str_contents_from_file(std::string filename) {
    // The following code is adapted from:
    // https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring
    std::ifstream t(filename);
    std::stringstream buffer;
    buffer << t.rdbuf();
    t.close();
    return buffer.str();
}
