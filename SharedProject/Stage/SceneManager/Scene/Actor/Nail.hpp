#pragma once
#include"Stage/SceneManager/Scene/Actor/StageActorBase.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Stage/Utilty/Dir4Vec.hpp"
#include"Stage/Utilty/State/StageStateManager.hpp"

namespace Stage
{
	class Nail : public ActorBase
	{
		GameLib::DrawAnimation mAnim;
		StateManager<> mStateManager;

	public:
		Nail(GameLib::Actor*, Dir4&&,const GameLib::Vector2&);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadPosData(std::vector<GameLib::Vector2>&&) override {};
	};
}