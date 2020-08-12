#pragma once
#include<string>

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
		//StageState mStageState;

		StageData(std::string a)
			:mFileName{a}
		{}

	};
}