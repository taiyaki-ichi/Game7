#pragma once
#include"Stage/Utilty/State/StageStateBase.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace GameLib
{
	class DrawAnimation;
}

namespace Stage
{
	namespace BeeState
	{
		class StraightActive : public StateBase<>
		{
			GameLib::Vector2 mCenter;
			GameLib::Vector2 mRadiusVec;

			GameLib::DrawAnimation* mAnim;

			GameLib::Collider mWeakness;
			GameLib::Collider mStrength;

			int mCnt;

		public:
			StraightActive(GameLib::DrawAnimation* anim, GameLib::Vector2&& center,GameLib::Vector2&& radius);
			virtual ~StraightActive() = default;

			StateBase<>* Update() override;

			void BeginWorking() override;
			void BeginToRest() override;
		};
	}
}