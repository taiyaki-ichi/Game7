#pragma once
#include"Game/Stage/GravityActor.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"Game/Stage/PhysicsModel.hpp"

namespace Game::Stage::Triple
{
	
	class Actor : public GameLib::Actor
	{
		GameLib::DrawAnimation mAnimation;

	public:
		Actor(GameLib::Actor* owenr,GameLib::Vector2&& pos, int updateOrder = 0);
		virtual ~Actor() = default;

		void CustomizeUpdate() override;
		
		//physicsModelの更新をアニメーションに反映
		void ReflectAnimation(const GameLib::Vector2& pos, float scale, float rot, int cannel = -1);
	};

	class Active : public GravityActor
	{
		constexpr static float RUN_POWER = 0.1f;
		constexpr static float MAX_SPEED = 1.f;

		GameLib::Collider mBody;
		GameLib::Collider mWeakness;
		GameLib::Collider mStrength;

		PhysicsModel mPhysicsModel;

		Dir4 mDir4;

		bool mFlatDeathFlag;

	public:
		Active(GameLib::Actor* owner,GameLib::Vector2&& pos);
		~Active() = default;
		
		void CustomizeUpdate() override;

	private:
		void ReflectCollider();
		void ReflectAnimation();

		GameLib::Vector2 GetPowerPerFrame();
	};

	class FlatDead : public GravityActor
	{
		constexpr static int DEATH_CNT = 30;

		int mCnt;

	public:
		FlatDead(GameLib::Actor* owner,PhysicsModel& model,Dir4& dir);
		~FlatDead() = default;
		
		void CustomizeUpdate() override;

	};

	




}