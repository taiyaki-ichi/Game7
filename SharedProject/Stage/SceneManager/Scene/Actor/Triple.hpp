#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Stage/Utilty/State/StageStateManager.hpp"

namespace Stage
{
	class Triple : public ActorBase
	{
		GameLib::DrawAnimation mAnimation;

		StateManager<> mStateManager;

	public:
		Triple(GameLib::Actor* scene);
		virtual ~Triple() = default;

		//StateManagerÇÃçXêV
		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadPosData(std::vector<GameLib::Vector2>&& data);
	};
}