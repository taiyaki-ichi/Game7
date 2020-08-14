#pragma once
#include"Stage/Utilty/State/StageStateBase.hpp"
#include"Stage/Utilty/PhysicsModel.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace GameLib
{
	class DrawAnimation;
}

namespace Stage
{
	namespace FrogState
	{
		class Active : public StateBase<>
		{
			PhysicsModel mPhysicsModel;
			float mJumpSpeed;
			int mCnt;

			GameLib::Collider mStrength;
			GameLib::Collider mWeakness;

			GameLib::DrawAnimation* mAnim;

		public:
			Active(GameLib::DrawAnimation*, float jumpSpeed);
			virtual ~Active() = default;

			bool UpdateOrNot() override;
			StateBase<>* Update() override;

			void BeginWorking() override;
			void BeginToRest() override;

		private:
			void AdjustColliders();
			void AdjustAnim();
		};
	}
}