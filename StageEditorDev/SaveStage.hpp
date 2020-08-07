#pragma once
#include<string>
#include<vector>
#include"SceneEditor/ActorEditor/ActorData.hpp"

namespace StageEditor
{
	void SaveStageData(std::string&& fileName, std::vector<std::vector<ActorData>>&& data);
}