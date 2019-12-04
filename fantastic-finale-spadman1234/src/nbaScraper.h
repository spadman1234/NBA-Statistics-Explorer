#pragma once

#include <string>

namespace nba_stats {
std::string GetStrContentsFromUrl(const char* url);
std::string GetStrContentsFromFile(std::string filename);
}