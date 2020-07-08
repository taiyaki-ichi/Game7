#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"Game/Stage/PhysicsModel.hpp"

namespace Game::Stage::Player
{
	class Actor : public GameLib::Actor
	{

		GameLib::DrawAnimation mAnimation;

	public:
		Actor(GameLib::Actor* owner, std::vector<float>&& data);
		virtual ~Actor() = default;

		void CustomizeUpdate() override;

		void SetAnamtion(const GameLib::Vector2 & pos, float scale, float rot, int channel = -1);

		//アニメーションの位置を返す
		GameLib::Vector2 GetPositon();

	};


	class Active : public GameLib::Actor
	{
		constexpr static float MAX_HORIZON_SPEED = 7.f;
		constexpr static float MAX_VERTICAL_SPEED = 21.f;
		constexpr static float JUMP_POWER_MAX = 17.f;
		constexpr static float JUMP_POWER_MIN = 14.f;
		constexpr static float RUN_POWER = 0.3f;
		constexpr static float JUMPING_GRAVITY_RATE = 0.85f;

		GameLib::Collider mCollider;
		PhysicsModel mPhysicsModel;

		constexpr static char ON_GROUND_FLAG = 0b00000001;
		char mFlags;

		int mJumpFlag;

		//アニメーションへの参照
		GameLib::DrawAnimation* mAnimation;

	public:
		Active(Actor* player, GameLib::Vector2&& pos, GameLib::DrawAnimation* anim);
		virtual ~Active() = default;

		void CustomizeUpdate() override;

	private:
		GameLib::Vector2 GetPowerPerFrame();
		void UpdateAnimation(const GameLib::Vector2& power);
		void UpdateCollider();
	};

	class Death : GameLib::Actor
	{
		constexpr static int DEATH_CNT = 180;

		int mCnt;

		GameLib::Vector2 mPosition;
		float mScale;
		float mRotation;

		//アニメーションへの参照
		GameLib::DrawAnimation* mAnimation;

	public:
		Death(Actor* player, const PhysicsModel& model, GameLib::DrawAnimation* anim);
		virtual ~Death() = default;

		void CustomizeUpdate() override;

	};
}