#pragma once
#include"Stage/Utilty/State/StageStateBase.hpp"
#include"GameLib/include/Math/Vector2.hpp"

namespace GameLib
{
	class DrawAnimation;
}

namespace Stage
{
	namespace DoguState
	{
		class Stay : public StateBase<>
		{
			GameLib::DrawAnimation* mAnim;

			int mCnt;

			GameLib::Vector2 mPos;

		public:
			Stay(GameLib::DrawAnimation*);

			StateBase<>* Update() override;

			void BeginWorking() override {};
			void BeginToRest() override {};
		};
	}
}