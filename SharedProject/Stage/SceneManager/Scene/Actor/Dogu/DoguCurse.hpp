#pragma once
#include"Stage/Utilty/State/StageStateBase.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace GameLib
{
	class DrawAnimation;
}

namespace Stage
{
	namespace DoguState
	{
		class Curse : public StateBase<>
		{
			GameLib::DrawAnimation* mAnim;
			GameLib::Collider mCurseCollider;
			GameLib::Collider mBodyCollider;

			int mCnt;

		public:
			Curse(GameLib::DrawAnimation*);

			StateBase<>* Update() override;

			void BeginWorking() override;
			void BeginToRest() override;
		};
	}
}