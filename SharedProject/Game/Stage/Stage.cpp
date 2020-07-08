#include"Stage.hpp"
#include"Scene/StageScene.hpp"

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
}