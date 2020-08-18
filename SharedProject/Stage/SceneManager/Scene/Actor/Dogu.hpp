#pragma once
#include"StageActorBase.hpp"
#include"Stage/Utilty/State/StageStateManager.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"

namespace Stage
{
	class Dogu : public ActorBase
	{
		GameLib::DrawAnimation mAnim;
		StateManager<> mStateManager;

	public:
		Dogu(GameLib::Actor*);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadPosData(std::vector<GameLib::Vector2>&&) override;
	};
}