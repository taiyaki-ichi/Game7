#pragma once
#include<string>
#include"PairVec.hpp"
#include<map>

namespace Game::StageSelect
{

	enum class StageState
	{
		Clear,
		Open,
		Close,
	};

	struct StageData
	{
		std::string mFileName;
		StageState mStageState;

		StageData(const std::string& fileName,StageState&& state)
			:mFileName{fileName}
			, mStageState{state}
		{}
	};

	struct StageInfo
	{
		std::string mFileName;
		std::string mLevel;

		StageInfo(std::string&& fileName, std::string&& level)
			: mFileName{ std::move(fileName) }
			, mLevel{ std::move(level) }
		{

		}
	};

	const std::map<PairVec, StageInfo> gStageInfo =
	{
		{std::make_pair(1,0),{"stage001.json","easy"}},
		{std::make_pair(2,0),{"stage002.json","easy"}},
		{std::make_pair(3,0),{"stage003.json","nomal"}},
		{std::make_pair(4,0),{"stage003.json","nomal"}},
		{std::make_pair(5,0),{"stage003.json","nomal"}},

	};

}