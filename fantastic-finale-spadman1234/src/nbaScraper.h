#pragma once

#include <string>

namespace nbaScraper {
std::string get_str_contents_from_url(std::wstring url);
std::string get_str_contents_from_file(std::string filename);
}