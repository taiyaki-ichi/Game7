#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/Draw/DrawLine.hpp"

namespace Stage
{
	class Lift;

	class MoveLift : public ActorBase
	{
		Lift* mLift;
		GameLib::Vector2 mP1;
		GameLib::Vector2 mP2;

		GameLib::Vector2 mVelocity;

		GameLib::DrawLine mLine;

	public:
		MoveLift(GameLib::Actor*);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadPosData(std::vector<GameLib::Vector2>&&);
	};
}