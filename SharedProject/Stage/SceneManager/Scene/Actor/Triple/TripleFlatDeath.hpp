#pragma once
#include"Stage/Utilty/State/StageStateBase.hpp"

namespace GameLib
{
	class DrawAnimation;
}

namespace Stage
{
	namespace TripleState
	{
		class FlatDeath : public StateBase<>
		{
			int mCnt;
		public:
			FlatDeath(GameLib::DrawAnimation* anim);
			virtual ~FlatDeath() = default;

			StateBase<>* Update() override;

			void BeginWorking() override {};
			void BeginToRest() override {};
		};
	}
}