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

		constexpr static float MAX_SIZE = 300.f;

		Ground(Scene* scene, float left,float right,float bottom,float top);
		virtual ~Ground() = default;

		void Active() override;
		void Pause()override;

	};

	void CreateGround(Scene* scene, std::vector<float> data);

}