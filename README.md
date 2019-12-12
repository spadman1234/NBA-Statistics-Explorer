# Readme

## Overview
This application is an NBA statistics explorer that allows users to:
- View upcoming matchups and their spreads
- Explore team statistics
- Create custom linear regression models to predict win percentages for all 30 NBA teams

It was created in Visual Studio 2017. The only external dependency needed to compile is [libCurl](https://curl.haxx.se/libcurl/). Two other libraries ([RapidJSON](https://github.com/Tencent/rapidjson/) and [Regression Algorithms by Yacine Mahdid](https://github.com/yacineMahdid/Algorithms/tree/master/regression)) are included in the `/src` folder. These are contained in the `/rapidjson` and `/regression` folders respectively to be separated from the code written by me.

## Controls
The UI can be navigated with the `UP` and `DOWN` arrow keys. `ENTER` is used to make selections and `BACKSPACE` is used to go back. Press `R` to create a regression model. Press `ESCAPE` to exit.
