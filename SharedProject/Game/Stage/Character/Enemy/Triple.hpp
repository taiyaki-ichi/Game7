#pragma once
#include"Game/Stage/Character/GravityActor.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"Game/Stage/PhysicsModel.hpp"

namespace Game::Stage::Triple
{
	class State;

	class Actor : public GravityActor
	{
		State* mState;
		GameLib::DrawAnimation mAnimation;
		GameLib::Collider mBody;
		GameLib::Collider mWeakness;
		PhysicsModel mPhysicsModel;

	public:
		Actor(Actor* owenr, int updateOrder = 0);
		virtual ~Actor() = default;

		void CustomizeUpdate() override;
	};

	class State
	{
	public:
		virtual PhysicsModel Update(PhysicsModel&&) = 0;
	};

	class Active : public State
	{
	public:
		PhysicsModel Update(PhysicsModel&& model) override;
	};


}