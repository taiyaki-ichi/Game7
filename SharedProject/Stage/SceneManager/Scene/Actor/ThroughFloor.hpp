#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace Stage
{
	class Pole;

	class ThroughFloor : public ActorBase
	{
		std::vector<Pole*> mPole;
		GameLib::Collider mCollider;

	public:
		ThroughFloor(GameLib::Actor*);

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadPosData(std::vector<GameLib::Vector2>&& data) override;

	};
}