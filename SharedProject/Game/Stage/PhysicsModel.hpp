#pragma once
#include<utility>
#include"GameLib/include/Math/Vector2.hpp"

namespace Game::Stage
{
	struct PhysicsModel
	{

		GameLib::Vector2 mPosiotion;
		GameLib::Vector2 mVelocity;
		float mScale;
		float mRotation;

		PhysicsModel(GameLib::Vector2&& pos, GameLib::Vector2&& velocity = {0.f,0.f},float scale=1.f,float rot=0.f)
			:mPosiotion(std::move(pos))
			,mVelocity(std::move(velocity))
			, mScale(scale)
			,mRotation(rot)
		{}
		virtual ~PhysicsModel() = default;

		//１フレームのかかる力から速度と位置の更新,maxSpeedは<0.fの時無効
		void Update(const GameLib::Vector2& power, float maxSpeedX = -1.f, float maxSpeedY = -1.f) {
			mVelocity += power;

			if (maxSpeedX > 0.f && std::abs(mVelocity.x) > maxSpeedX)
				mVelocity.x = (mVelocity.x < 0.f) ? -maxSpeedX : maxSpeedX;
			if (maxSpeedY > 0.f && std::abs(mVelocity.y) > maxSpeedY)
				mVelocity.y = (mVelocity.y < 0.f) ? -maxSpeedY : maxSpeedY;

			mPosiotion += mVelocity;
		}

		//摩擦みたいな
		void Friction(float xRate, float yRate) {
			mVelocity.x *= xRate;
			mVelocity.y *= yRate;
		}
	};
}