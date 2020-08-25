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
	namespace NailState
	{
		class Active : public StateBase<>
		{
			GameLib::DrawAnimation* mAnim;

			GameLib::Collider mStrength;
			GameLib::Collider mWeakness;

			Dir4 mDir;

		public:
			Active(GameLib::DrawAnimation*, Dir4&&);

			StateBase<>* Update() override;

			void BeginWorking() override;
			void BeginToRest() override;

		private:
			//アニメーションの位置によってColliderを更新
			void AdjustColiider();
		};
	}
}