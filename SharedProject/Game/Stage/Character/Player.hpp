#pragma once
#include"GravityActor.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"Game/Stage/PhysicsModel.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"Game/Stage/UtilityVectorFunction.hpp"
#include"GameLib/include/Math/Numbers.hpp"


namespace Game::Stage
{
	class Player : public GravityActor
	{
		constexpr static float MAX_HORIZON_SPEED = 5.5f;
		constexpr static float MAX_VERTICAL_SPEED = 21.f;
		constexpr static float JUMP_POWER_MAX = 9.f;
		constexpr static float JUMP_POWER_MIN = 7.f;
		constexpr static float RUN_POWER = 0.2f;
		constexpr static float JUMPING_GRAVITY_RATE = 0.8f;

		GameLib::DrawAnimation mAnimation;
		GameLib::Collider mCollider;

		PhysicsModel mPhysicsModel;

		constexpr static char ON_GROUND_FLAG = 0b00000001;
		char mFlags;

		int mJumpFlag;

	public:
		Player(Actor* owner, int updateOrder = 0);
		virtual ~Player() = default;
		void CustomizeUpdate() override;

	private:
		GameLib::Vector2 GetPowerPerFrame();
		void UpdateAnimation(const GameLib::Vector2& power);
		void UpdateCollider();

	};
}