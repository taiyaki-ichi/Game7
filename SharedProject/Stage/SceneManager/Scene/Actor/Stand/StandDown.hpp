#pragma once
#include"Stage/Utilty/State/StageStateBase.hpp"

namespace GameLib
{
	class DrawAnimation;
}

namespace Stage
{
	namespace StandState
	{
		class Down : public StateBase<>
		{
			GameLib::DrawAnimation* mHeadAnim;
			GameLib::DrawAnimation* mBodyAnim;

			int mCnt;

		public:
			Down(GameLib::DrawAnimation* head, GameLib::DrawAnimation* body);

			StateBase<>* Update() override;

			void BeginWorking() override;
			void BeginToRest() override;
		};
	}
}