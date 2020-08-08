#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Stage/Utilty/State/StageStateManager.hpp"

namespace Stage
{
	class Bee : public ActorBase
	{
		GameLib::DrawAnimation mAnim;
		StateManager<> mStateManager;

	public:
		Bee(GameLib::Actor* scene);
		virtual ~Bee() = default;

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		//data‚Ìsize‚ÅCircle‚©Straight‚Í”»•Ê
		void LoadPosData(std::vector<GameLib::Vector2>&& data) override;
	};

}