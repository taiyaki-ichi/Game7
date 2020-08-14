#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Stage/Utilty/State/StageStateManager.hpp"

namespace Stage
{
	class Frog : public ActorBase
	{
		GameLib::DrawAnimation mAnim;
		StateManager<> mStateManager;

	public:
		Frog(GameLib::Actor*);
		virtual ~Frog() = default;

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadPosData(std::vector<GameLib::Vector2>&&) override;
	};
}