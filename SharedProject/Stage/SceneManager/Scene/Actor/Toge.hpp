#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Stage/Utilty/State/StageStateManager.hpp"

namespace Stage
{

	class Toge : public ActorBase
	{
		GameLib::DrawAnimation mAnimation;

		StateManager<> mStateManager;

	public:
		Toge(GameLib::Actor* scene);
		virtual ~Toge() = default;

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadPosData(std::vector<GameLib::Vector2>&& data) override;
	};

}