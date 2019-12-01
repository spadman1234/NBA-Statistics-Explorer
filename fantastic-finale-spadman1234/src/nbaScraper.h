#pragma once

#include <string>

namespace nbaScraper {
//const char *TMP_FILE = "tmpdata";
std::string get_str_contents_from_url(const char* url);
std::string get_str_contents_from_file(std::string filename);
}