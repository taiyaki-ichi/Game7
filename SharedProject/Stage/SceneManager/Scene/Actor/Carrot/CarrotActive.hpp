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
	namespace CarrotState
	{
		class Active : public StateBase<>
		{
			GameLib::DrawAnimation* mAnim;
			GameLib::Collider mWeakness;
			GameLib::Collider mStrength;

			PhysicsModel mPhysicsModel;

		public:
			Active(GameLib::DrawAnimation*);

			StateBase<>* Update() override;

			void BeginWorking() override;
			void BeginToRest() override;

		private:
			GameLib::Vector2 GetPowerPerFrame();

			void AdjustAnim();
			void AdjustColliders();
		};
	}
}