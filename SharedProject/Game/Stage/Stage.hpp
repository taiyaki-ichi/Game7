#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<unordered_map>

namespace Game::Stage
{
	class Scene;

	class Stage : public GameLib::Actor
	{
		//Stage‚ÉŠ‘®‚·‚éScene‚Ö‚ÌQÆ
		std::unordered_map<std::string, Scene*> mStageScenes;

	public:
		Stage(GameLib::Actor* owner);
		virtual ~Stage() = default;

		void CustomizeUpdate() override;

		void SceneActive(std::string& sceneName);
		void ScenePause(std::string& sceneName);
	};
}