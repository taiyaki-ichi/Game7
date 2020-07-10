#pragma once
#include<string>
#include<vector>

namespace Game::Stage
{
	class Scene;
	class WarpBase;

	WarpBase* CreateWarp(Scene* scene, std::string&& warpGateType, std::vector<float>&& data);
}