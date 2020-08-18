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
		class Active : public StateBase<>
		{
			GameLib::DrawAnimation* mAnim;
			int mCnt;
			GameLib::Collider mCollider;
			GameLib::Vector2 mPos;

		public:
			Active(GameLib::DrawAnimation*);

			StateBase<>* Update() override;

			void BeginWorking() override;
			void BeginToRest() override;
		};
	}
}