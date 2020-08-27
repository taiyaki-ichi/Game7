#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Stage/Utilty/State/StageStateManager.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"

namespace Stage
{
	class HeadBlock : public ActorBase
	{
		GameLib::DrawAnimation mAnim;
		StateManager<> mStateManager;
		GameLib::DrawRect mRect;

	public:
		HeadBlock(GameLib::Actor*);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadPosData(std::vector<GameLib::Vector2>&&) override;
	};
}