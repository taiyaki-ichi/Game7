#pragma once
#include"Stage/Utilty/State/StageStateBase.hpp"

namespace GameLib
{
	class DrawAnimation;
}

namespace Stage
{
	namespace BeeState
	{
		class FallDeath : public StateBase<>
		{
			GameLib::DrawAnimation* mAnim;

		public:
			FallDeath(GameLib::DrawAnimation*);

			StateBase<>* Update() override;

			void BeginWorking() override {};
			void BeginToRest() override {};
		};
	}
}