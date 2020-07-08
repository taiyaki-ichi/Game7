#pragma once
#include<string>
#include<vector>
#include<unordered_map>
#include"StageEditor.hpp"

namespace StageEditor
{
	void SaveStageData(const std::string& stageName, std::unordered_map<std::string, std::vector<ActorData>>&& stageData, const std::string& fileName);

}