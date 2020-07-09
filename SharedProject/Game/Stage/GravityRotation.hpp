#pragma once
#include"GameLib/include/Actor/Actor.hpp"

namespace Game::Stage
{
	class GravityRotaion : public GameLib::Actor
	{
		int mRotationCnt;

		constexpr static float DELTA_ROT = 0.1f;

	public:
		GravityRotaion(GameLib::Actor* owner);
		virtual ~GravityRotaion() = default;

		void CustomizeUpdate() override;

	};
}