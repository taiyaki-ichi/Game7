#pragma once
#include"GravityActor.hpp"

namespace Game::Stage
{
	class GravityManager : public GravityActor
	{
		constexpr static int ROTATION_FLAME = 20;

		float mDeltRotation;
		int mCnt;

	public:
		GravityManager(Actor* owner, int updateOrder = 0);
		virtual ~GravityManager() = default;

		void CustomizeUpdate() override;

	};
}