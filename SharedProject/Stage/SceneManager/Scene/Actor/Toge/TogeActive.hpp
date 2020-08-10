#pragma once
#include"Stage/Utilty/State/StageStateBase.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"Stage/Utilty/PhysicsModel.hpp"

namespace GameLib
{
	class DrawAnimation;
}

namespace Stage
{
	namespace TogeState
	{

		class Active : public StateBase<>
		{
			GameLib::Collider mCollider;
			GameLib::DrawAnimation* mAnim;

			PhysicsModel mPhysicsModel;

			int mCnt;

		public:
			Active(GameLib::DrawAnimation* anim);
			virtual ~Active() = default;

			bool UpdateOrNot() override;
			StateBase* Update() override;

			void BeginWorking() override;
			void BeginToRest() override;

		private:
			void ReflectAnimation();
			void ReflectCollider();
		};

	}
}