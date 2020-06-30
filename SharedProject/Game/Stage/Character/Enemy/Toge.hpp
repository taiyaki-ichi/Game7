#pragma once
#include"Game/Stage/Character/GravityActor.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"Game/Stage/PhysicsModel.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace Game::Stage::Toge
{
	class Actor : public GameLib::Actor
	{
		GameLib::DrawAnimation mAnimation;

	public:
		Actor(GameLib::Actor* actor,GameLib::Vector2&& pos, int updateOrder = 0);
		virtual ~Actor() = default;

		void CustomizeUpdate() override;

		void SetAnimation(const GameLib::Vector2& pos, float scale, float rot, float channel = -1);
	};

	class Active : public GravityActor
	{
		GameLib::Collider mBody;
		PhysicsModel mPhysicsModel;

		int mCnt;

	public:
		Active(Actor* toge,GameLib::Vector2&& pos);
		virtual ~Active() = default;

		void CustomizeUpdate() override;
	};
}