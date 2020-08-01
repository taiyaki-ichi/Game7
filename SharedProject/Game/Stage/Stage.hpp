#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include<unordered_map>
#include<vector>
#include<optional>

namespace Game::Stage
{
	class Scene;
	namespace Player {
		class Actor;
	}
	class WarpBase;

	class Stage : public GameLib::Actor
	{
		//Stageに所属するSceneへの参照
		std::vector<Scene*> mStageScenes;
		Scene* mNowScene;
		
		std::vector<WarpBase*> mWarpGates;

		Player::Actor* mPlayer;

		int mFlag;

	public:
		Stage(GameLib::Actor* owner, std::string&& fileName, bool isDebug = false);
		virtual ~Stage() = default;

		void CustomizeUpdate() override;

		//CreateStageで使用
		Scene* AddScene(std::string&& sceneName);

		//CreateStageで使用、Playerの登録とスタート知るシーンの裂蹄
		void SetPlayerAndNowScene(Player::Actor* player,Scene* scene);

		const GameLib::Vector2& GetPlayerPos();
		void ResetPlayerPos(const GameLib::Vector2& pos);

		void AddWarpGate(WarpBase* warp);
		void RemoveWarpGate(WarpBase* warp);

		//次のWarpGateのNameTagを指定する。反転方法も指定したい
		void PlayerWarp(const std::string& destinationNameTag);

		void PlayerAcitve();
		void PlayerPause();

		//-1は失敗、1でクリア,2はポーズかな
		int GetStateFlag();
	};
}