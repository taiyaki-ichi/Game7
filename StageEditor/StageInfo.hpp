#pragma once
#include<string>
#include<vector>

namespace StageEditor
{
	struct StageInfo {
		std::string StageName;
		std::vector<std::string> mStageSceneNames;
	};
}