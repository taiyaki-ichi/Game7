#pragma once
#include<string>
#include<vector>
#include<unordered_map>
#include"SceneEditor/ActorEditor/ActorData.hpp"

namespace StageEditor
{
	void SaveStageData(std::string&& fileName, std::unordered_map<std::string,std::vector<ActorData>>&& data);
}