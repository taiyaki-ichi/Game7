#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"GameLib/include/Draw/DrawLine.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"

namespace Stage
{
	class MoveGround : public ActorBase
	{
		GameLib::Collider mCollider;
		GameLib::DrawRect mRect;
		GameLib::DrawLine mLine;

		GameLib::Vector2 mPos1;
		GameLib::Vector2 mPos2;

		GameLib::Vector2 mVelocity;

	public:
		MoveGround(GameLib::Actor*);
		
		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadPosData(std::vector<GameLib::Vector2>&& data) override;
	};
}