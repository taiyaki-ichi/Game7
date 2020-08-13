#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Player/PlayerStateManager.hpp"
#include"Player/ItemNum/ItemNumData.hpp"

namespace Stage
{
	class Life;
	class ItemNum;

	class Player : public ActorBase
	{
		GameLib::DrawAnimation mAnimation;
		PlayerState::Manager mStateManager;

		static GameLib::Vector2 mPosition;

		Life* mLife;
		ItemNum* mItemNum;

	public:
		Player(GameLib::Actor* scene,int lifeNum,int gemNum);
		virtual ~Player() = default;

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadPosData(std::vector<GameLib::Vector2>&& data) override;

		void SetPosition(const GameLib::Vector2& pos);

		//Animationの位置
		static const GameLib::Vector2& GetPosition();

		//速度などのリセット
		void ResetPotentialPower();

		bool CheckFlag(char);

		ItemNumData GetItemNumData();
	};
}