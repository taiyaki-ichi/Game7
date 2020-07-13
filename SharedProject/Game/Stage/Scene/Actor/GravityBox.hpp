#pragma once
#include"ActorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"Game/Dir4.hpp"

namespace Game::Stage
{
	class GravityBox : public ActorBase
	{
		GameLib::DrawTexture mTexture;
		GameLib::Collider mCollider;
		GameLib::Collider mCollider2;


		int mRotationCnt;
		GameLib::Vector2 mVec;
		constexpr static float DELTA_ROT = 0.1f;
		float mRot;

		Dir4 mDir4;

	public:
		GravityBox(Scene* scene, std::vector<float>&& data);
		virtual ~GravityBox() = default;

		void ActorUpdate() override;

		void Active() override;
		void Pause() override;

	};
}