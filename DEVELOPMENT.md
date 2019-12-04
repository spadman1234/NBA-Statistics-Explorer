# Final Project Development Log
## 11/18
- Collected all APIs needed to collect data and read documentation
	- [https://cheapdatafeeds.com/](https://cheapdatafeeds.com/) - previous 4 years of NBA scores and live spreads
	- [https://github.com/swar/nba_api](https://github.com/swar/nba_api) - Python interface to interact with NBA.com's API for stats and scores

## 11/21
- Refreshed myself on how multiple regression models work  by reading the following:
	- [https://www.kaggle.com/wduckett/beane-and-depodesta-s-regression-roadmap](https://www.kaggle.com/wduckett/beane-and-depodesta-s-regression-roadmap)
	- [https://towardsdatascience.com/linear-regression-moneyball-part-1-b93b3b9f5b53](https://towardsdatascience.com/linear-regression-moneyball-part-1-b93b3b9f5b53)
	- [https://blog.minitab.com/blog/adventures-in-statistics-2/how-to-identify-the-most-important-predictor-variables-in-regression-models](https://blog.minitab.com/blog/adventures-in-statistics-2/how-to-identify-the-most-important-predictor-variables-in-regression-models)
- Researched existing NBA regression models and noted which variables were used most often (so I can scrape this data)
- Watched tutorials on ofxGui

## 11/29
- Decided to use C++ to get statistics directly from NBA.com's API rather than use Python and nba_api
- Wrote code to download data from the web
	- Currently broken so I downloaded the current stats so I have local data to work with temporarily
- Installed RapidJSON to parse JSON in C++

## 11/30
- Installed libCurl for network operations
- Wrote working code to use libCurl to download JSON data from the web
- Began looking for a new data source (NBA.com's API not working)

## 12/1
- Found a new NBA stats API to use: data.nba.net
- Tested downloading updated team and player stats from this API

## 12/3
- Wrote nbaTeamStats class to store any team's updated statistics in a hash map
- Wrote code to populate the class's hash map from JSON data from the internet
- Tested the class
