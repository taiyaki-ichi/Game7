#pragma once
#include"ActorBase.hpp"
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
		Ground(Scene* scene, std::vector<float>&& initData);
		virtual ~Ground() = default;

		void Active() override;
		void Pause()override;

	};

}