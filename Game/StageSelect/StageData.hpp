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
		StageState mStageState;

		StageData(const std::string& fileName,StageState&& state)
			:mFileName{fileName}
			, mStageState{state}
		{}

	};
}