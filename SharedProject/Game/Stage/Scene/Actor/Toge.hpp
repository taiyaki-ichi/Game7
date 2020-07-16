#pragma once
#include"ActorBase.hpp"
#include"State/StateBase.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"State/StateManager.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"Game/Stage/PhysicsModel.hpp"

namespace Game::Stage::Toge
{
	class Actor : public ActorBase
	{
		GameLib::DrawAnimation mAnimation;

		StateManager mStateManager;

	public:
		Actor(Scene* scene, std::vector<float>&& data);
		virtual ~Actor() = default;

		bool UpdateOrNot() override;
		void ActorUpdate() override;

		void Active() override;
		void Pause() override;
	};

	class TogeActive : public StateBase
	{
		GameLib::Collider mCollider;
		GameLib::DrawAnimation* mAnim;

		PhysicsModel mPhsicsModel;

		float mTimer;

	public:
		TogeActive(GameLib::DrawAnimation* anim,GameLib::Vector2&& pos);
		virtual ~TogeActive() = default;

		StateBase* Update() override;

		void Active() override;
		void Pause() override;

		//PhysicsModelÇ©ÇÁColliderÇ∆AnimÇÃçsêi
		void Adjust();
		
	};
}