#pragma once
#include<map>
#include<vector>
#include<string>

namespace Game
{
	const std::map<std::pair<int, int>, std::vector<std::string>> gStageData =
	{
		{std::make_pair(1,0),{"stage001.json","easy","1"}},
		{std::make_pair(2,0),{"stage002.json","easy","2"}},
		{std::make_pair(3,0),{"stage003.json","nomal","3"}},
		{std::make_pair(4,0),{"stage003.json","nomal","4"}},
		{std::make_pair(5,0),{"stage003.json","nomal","5"}},

		{std::make_pair(-1,1),{"save"}},
		{std::make_pair(0,-1),{"title"}},
		{std::make_pair(0,0),{"start"}},
	};

	//
	const std::map<std::pair<int, int>, std::vector<std::string>> gSpecialStageData =
	{
		{std::make_pair(-1,1),{"save"}},
		{std::make_pair(0,-1),{"title"}},
		{std::make_pair(0,0),{"start"}},
	};
}