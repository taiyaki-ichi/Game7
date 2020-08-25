#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Stage/Utilty/State/StageStateManager.hpp"
#include"Stage/Utilty/Dir4Vec.hpp"

namespace Stage
{
	class Mai : public ActorBase
	{
		GameLib::DrawAnimation mAnim;
		StateManager<> mStateManager;

		Dir4 mGroundDir;

	public:
		Mai(GameLib::Actor*,Dir4&& dir);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadPosData(std::vector<GameLib::Vector2>&&) override;
	};
}