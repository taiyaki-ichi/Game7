#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace Stage
{
	class Apple;

	class GravityBox : public ActorBase
	{

		GameLib::Collider mCollider;
		GameLib::Collider mCollider2;

		GameLib::DrawTexture mTexture;

		Apple* mApple;

		int mRotationCnt;
		constexpr static float DELTA_ROT = 0.1f;

		GameLib::Vector2 mPosition;
		float mRotation;

	public:
		GravityBox(GameLib::Actor* scene);
		virtual ~GravityBox() = default;

		bool UpdateOrNot() override;
		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadData(std::vector<float>&& data) override;
	};
}