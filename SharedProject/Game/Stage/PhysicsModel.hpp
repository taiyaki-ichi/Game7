#pragma once
#include<utility>
#include"GameLib/include/Math/Vector2.hpp"

namespace Game::Stage
{
	class PhysicsModel
	{

		GameLib::Vector2 mPosiotion;
		GameLib::Vector2 mVelocity;

		float mMaxVelocityX;
		float mMaxVelocityY;

	public:
		PhysicsModel(GameLib::Vector2&& pos, GameLib::Vector2&& velocity = {0.f,0.f},float maxVelocityX=-1.f,float maxVelocityY=-1.f)
			:mPosiotion(std::move(pos))
			,mVelocity(std::move(velocity))
			,mMaxVelocityX(maxVelocityX)
			,mMaxVelocityY(maxVelocityY)
		{}
		virtual ~PhysicsModel() = default;

		void Update(const GameLib::Vector2& power) {
			mVelocity += power;

			if (mMaxVelocityX > 0.f && std::abs(mVelocity.x) > mMaxVelocityX)
				mVelocity.x = (mVelocity.x > 0) ? mMaxVelocityX : -mMaxVelocityX;
			if (mMaxVelocityY > 0.f && std::abs(mVelocity.y) > mMaxVelocityY)
				mVelocity.y = (mVelocity.y > 0) ? mMaxVelocityY : -mMaxVelocityY;

			mPosiotion += mVelocity;
		}

		const GameLib::Vector2& GetPosition() const noexcept {
			return mPosiotion;
		}
		void AdjustPosiotion(const GameLib::Vector2& pos) {
			mPosiotion += pos;
		}

		void ResetVelocityX() {
			mVelocity.x = 0.f;
		}
		void ResetVelocityY() {
			mVelocity.y = 0.f;
		}

		void Friction(float xRate, float yRate) {
			mVelocity.x *= xRate;
			mVelocity.y *= yRate;
		}

		const GameLib::Vector2& GetVelocity() const noexcept {
			return mVelocity;
		}
	};
}