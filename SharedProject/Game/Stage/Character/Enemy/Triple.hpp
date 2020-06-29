#pragma once
#include"Game/Stage/Character/GravityActor.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace Game::Stage::Triple
{
	class Actor : public GravityActor
	{
		GameLib::Actor* mStateActor;
		GameLib::DrawAnimation mAnimation;
		GameLib::Collider mBody;
		GameLib::Collider mWeakness;


	};
}