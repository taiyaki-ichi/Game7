#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"Stage/Utilty/Dir4Vec.hpp"

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
		int mCoolDownCnt;

		//Ç±ÇÃÉtÉåÅ[ÉÄÇÃä‘ÇÕãNìÆÇ≥ÇπÇ»Ç¢
		constexpr static int COOLDOWN_TIME = 30;

		GameLib::Vector2 mPosition;
		float mRotation;

		Dir4 mNextDir;
		//1or-1
		int mDeltaRotDir;

	public:
		//dirNumÇÕ2Ç©4
		GravityBox(GameLib::Actor* scene,int dirNum);
		virtual ~GravityBox() = default;

		bool UpdateOrNot() override;
		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadPosData(std::vector<GameLib::Vector2>&& data) override;
		void LoadStringData(std::vector<std::string>&& data) override;
	};
}