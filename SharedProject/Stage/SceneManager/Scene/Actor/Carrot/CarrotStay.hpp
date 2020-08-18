#pragma once
#include"Stage/Utilty/State/StageStateBase.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace GameLib
{
	class DrawAnimation;
}

namespace Stage
{
	namespace CarrotState
	{
		class Stay : public StateBase<>
		{
			GameLib::DrawAnimation* mAnim;
			GameLib::Collider mCollider;

		public:
			Stay(GameLib::DrawAnimation*);

			StateBase<>* Update() override;

			void BeginWorking() override;
			void BeginToRest() override;
		};
	}
}