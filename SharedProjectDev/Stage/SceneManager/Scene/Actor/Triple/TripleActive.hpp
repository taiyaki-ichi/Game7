#pragma once
#include"Stage/Utilty/State/StageStateBase.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"Stage/Utilty/PhysicsModel.hpp"
#include"Stage/Utilty/Dir4Vec.hpp"

namespace GameLib
{
	class DrawAnimation;
}

namespace Stage
{
	namespace TripleState
	{

		class Active : public StateBase<>
		{
			GameLib::Collider mBody;
			GameLib::Collider mWeakness;
			GameLib::Collider mStrength;

			PhysicsModel mPhysicsModel;
			Dir4 mDir4;

			bool mFlatDeathFlag;

			GameLib::DrawAnimation* mAnimation;

		public:
			Active(GameLib::DrawAnimation* anim);
			virtual ~Active() = default;

			bool UpdateOrNot() override;
			StateBase<>* Update() override;

			void BeginWorking() override;
			void BeginToRest() override;

		private:
			//ïœçXÇîΩâf
			void ReflectAnimation();
			void ReflectCollider();
		};

	}
}