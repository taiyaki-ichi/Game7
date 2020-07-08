#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"

namespace Game::Stage
{

	class Ground : public ActorBase
	{
		GameLib::Collider mCollider;
		GameLib::DrawRect mDrawRect;

		GameLib::Vector2 mPosition;
		float mWidth;
		float mHeigth;

	public:
		Ground(Scene* scene, GameLib::Vector2&& pos, float width, float height);
		virtual ~Ground() = default;

	};

}