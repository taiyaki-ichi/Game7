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
	namespace MaiState
	{
		class Launch : public StateBase<>
		{
			GameLib::DrawAnimation* mAnim;
			GameLib::Collider mStrength;
			GameLib::Collider mWeakness;

			int mCnt;

			Dir4 mGroundDir4;

		public:
			Launch(GameLib::DrawAnimation*, const Dir4& droundDir4);

			StateBase<>* Update() override;

			void BeginWorking() override;
			void BeginToRest() override;
		};
	}
}