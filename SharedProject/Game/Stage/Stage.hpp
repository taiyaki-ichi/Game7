#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include<unordered_map>

namespace Game::Stage
{
	class Scene;
	namespace Player {
		class Actor;
	}

	class Stage : public GameLib::Actor
	{
		//Stageに所属するSceneへの参照
		std::unordered_map<std::string, Scene*> mStageScenes;

		Player::Actor* mPlayer;

	public:
		Stage(GameLib::Actor* owner,std::string&& fileName);
		virtual ~Stage() = default;

		void CustomizeUpdate() override;

		void SceneActive(std::string& sceneName);
		void ScenePause(std::string& sceneName);

		//CreateStageで使用
		Scene* AddScene(std::string&& sceneName);

		//CreateStageで使用
		void SetPlayer(Player::Actor* player);

		const GameLib::Vector2& GetPlayerPos();
	};
}