#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace Stage
{
	class IceGroundCollider : public GameLib::Actor
	{
		GameLib::Collider mCollider;

	public:
		IceGroundCollider(GameLib::Actor* actor, const GameLib::Vector2&, float, float);

		void BeginWorking();
		void BeginToRest();
	};
}