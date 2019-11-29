#pragma comment(lib, "urlmon.lib")

#include <urlmon.h>
#include <sstream>
#include <string>
#include "nbaScraper.h"

using namespace std;

string get_str_contents_from_url(wstring url) {
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
}