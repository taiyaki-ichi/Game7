#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Player/PlayerStateManager.hpp"

namespace Stage
{

	class Player : public ActorBase
	{
		GameLib::DrawAnimation mAnimation;
		PlayerState::Manager mStateManager;


		static GameLib::Vector2 mPosition;

	public:
		Player(GameLib::Actor* scene);
		virtual ~Player() = default;

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadData(std::vector<float>&& data) override;

		void SetPosition(const GameLib::Vector2& pos);

		//Animationの位置
		static const GameLib::Vector2& GetPosition();

		//速度などのリセット
		void ResetPotentialPower();

	
	};
}