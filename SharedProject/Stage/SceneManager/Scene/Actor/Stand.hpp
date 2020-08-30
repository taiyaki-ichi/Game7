#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Stage/Utilty/State/StageStateManager.hpp"
#include"Stage/Utilty/Dir4Vec.hpp"

namespace Stage
{
	class Stand : public ActorBase
	{
		GameLib::DrawAnimation mBodyAnim;
		GameLib::DrawAnimation mHeadAnim;

		StateManager<> mStageManager;

	public:
		Stand(GameLib::Actor*,Dir4&&);

		bool UpdateOrNot() override;
		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadPosData(std::vector<GameLib::Vector2>&&) override;
	};
}