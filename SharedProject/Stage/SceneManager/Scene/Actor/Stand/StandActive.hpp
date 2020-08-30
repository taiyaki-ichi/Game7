#pragma once
#include"Stage/Utilty/State/StageStateBase.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"Stage/Utilty/Dir4Vec.hpp"

namespace GameLib
{
	class DrawAnimation;
}

namespace Stage
{
	namespace StandState
	{
		class Active : public StateBase<>
		{
			GameLib::DrawAnimation* mHeadAnim;
			GameLib::DrawAnimation* mBodyAnim;

			GameLib::Collider mCollider;

			int mCnt;

		public:
			Active(GameLib::DrawAnimation* head, GameLib::DrawAnimation* body);

			StateBase<>* Update() override;

			void BeginWorking() override;
			void BeginToRest() override;
		};
	}
}