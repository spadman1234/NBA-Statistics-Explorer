#pragma once

#include <string>

namespace nba_stats {
const char* GetStrContentsFromUrl(const char* url);
const char* GetStrContentsFromFile(std::string filename);
}