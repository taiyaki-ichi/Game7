#pragma once
#include"ActorBase.hpp"
#include"State/StateManager.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace Game::Stage::Bee
{
	class Actor : public ActorBase
	{
		GameLib::DrawAnimation mAnim;

		StateManager mStateManager;

	public:
		Actor(Scene* scene, std::vector<float>&& data);
		virtual ~Actor() = default;

		bool UpdateOrNot() override;
		void ActorUpdate() override;

		void Active() override;
		void Pause() override;
	};

	class StraightActive :public StateBase
	{
		GameLib::Vector2 mCenter;
		GameLib::Vector2 mRadiusVec;

		GameLib::DrawAnimation* mAnim;

		GameLib::Collider mWeakness;
		GameLib::Collider mStrength;

		constexpr static float ROT_DISTANCE = 2.f;

		int mCnt;

	public:
		StraightActive(GameLib::DrawAnimation* anim, std::vector<float>&& data);
		virtual ~StraightActive() = default;

		StateBase* Update() override;
		
		void Active() override;
		void Pause()override;

	};

	class CircleActive : public StateBase
	{
		GameLib::Vector2 mCenter;
		GameLib::Vector2 mRadiusVec;

		GameLib::DrawAnimation* mAnim;

		GameLib::Collider mWeakness;
		GameLib::Collider mStrength;

		constexpr static float ROT_DISTANCE = 2.f;

		float mDir;
		int mCnt;

	public:
		CircleActive(GameLib::DrawAnimation* anim,std::vector<float>&& data);
		virtual ~CircleActive() = default;

		StateBase* Update()override;

		void Active() override;
		void Pause() override;
	};
}
