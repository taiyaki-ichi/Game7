#pragma once
#include"PlayerStateBase.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"Stage/Utilty/PhysicsModel.hpp"

namespace GameLib
{
	class DrawAnimation;
}

namespace Stage::PlayerState
{
	class Active : public StateBase
	{
		GameLib::Collider mCollider;
		PhysicsModel mPhysicsModel;

		//数フレームの間はジャンプを可能にするためのフラグ
		int mJumpFlag;

		//アニメーションへの参照
		GameLib::DrawAnimation* mAnimation;

	public:
		Active(GameLib::DrawAnimation* anim);
		virtual ~Active() = default;

		Stage::StateBase<char>* Update() override;

		//Stageの最中はPlayerがActivePauseを利用することなくね？？
		void BeginWorking() override {};
		void BeginToRest() override {};

		void SetPosition(const GameLib::Vector2 & pos) override;


	private:
		//physicsModelに基づいてColliderを更新
		void AdjustCollider();

		//そのフレームでの力の合計を取得
		GameLib::Vector2 GetPowerPerFrame();

		//Animの更新、フレーム毎に呼び出し
		//パワーを引数に向きを変える
		void UpdateAnimation(GameLib::Vector2 && power);

	};
}