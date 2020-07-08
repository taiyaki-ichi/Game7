#include"Stage.hpp"
#include"Scene/Scene.hpp"
#include"CreateStage.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"Player.hpp"
#include"GameLib/include/CollisionDetection/CollisionDetectionSetting.hpp"

namespace Game::Stage
{
	Stage::Stage(GameLib::Actor* owner,std::string&& fileName)
		:GameLib::Actor{owner}
		, mStageScenes{}
	{
		CreateStage(this, std::move(fileName));
	}
	void Stage::CustomizeUpdate()
	{
		GameLib::Viewport::SetPos(mPlayer->GetPositon());
		GameLib::CollisionDetectionSetting::SetPos(mPlayer->GetPositon());
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
	void Stage::SetPlayer(Player::Actor* player)
	{
		mPlayer = player;
	}
}