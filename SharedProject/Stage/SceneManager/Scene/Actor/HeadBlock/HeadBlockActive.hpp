#pragma once
#include"Stage/Utilty/State/StageStateBase.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace GameLib
{
	class DrawAnimation;
}

namespace Stage
{
	namespace HeadBlockState
	{
		class Active : public StateBase<>
		{
			GameLib::DrawAnimation* mAnim;
			GameLib::DrawRect mRect;
			GameLib::Collider mCollider;

			int mCnt;

		public:
			Active(GameLib::DrawAnimation*);

			StateBase<>* Update() override;

			void BeginWorking() override;
			void BeginToRest() override;
		};
	}
}