#include"Stage.hpp"
#include"Scene/Scene.hpp"

namespace Game::Stage
{
	Stage::Stage(GameLib::Actor* owner)
		:GameLib::Actor{owner}
		, mStageScenes{}
	{
	}
	void Stage::CustomizeUpdate()
	{
	}

	void Stage::SceneActive(std::string& sceneName)
	{
		auto i = mStageScenes.find(sceneName);
		if (i != mStageScenes.end())
			i->second->Active();
	}
	void Stage::ScenePause(std::string& sceneName)
	{
		auto i = mStageScenes.find(sceneName);
		if (i != mStageScenes.end())
			i->second->Pause();
	}
	Scene* Stage::AddScene(std::string&& sceneName)
	{
		auto ptr = new Scene(this);
		mStageScenes.emplace(std::move(sceneName), ptr);
		ptr->Pause();
		return ptr;
	}
}