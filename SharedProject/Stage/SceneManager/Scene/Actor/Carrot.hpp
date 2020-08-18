#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Stage/Utilty/State/StageStateManager.hpp"

namespace Stage
{
	class Carrot : public ActorBase
	{
		GameLib::DrawAnimation mAnim;
		StateManager<> mStateManager;

	public:
		Carrot(GameLib::Actor*);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadPosData(std::vector<GameLib::Vector2>&&) override;
	};
}