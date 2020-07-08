#pragma once
#include<string>
#include<vector>

namespace Game::Stage
{
	class ActorBase;
	class Scene;

	void CreateActor(Scene* scene, std::string&& actorName, std::vector<float>&& data = {});
}