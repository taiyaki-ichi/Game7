#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"Game/Dir4.hpp"
#include"GameLib/include/Math/Vector2.hpp"

#include<iostream>

namespace Game::Stage
{
	class GravityActor : public GameLib::Actor
	{
	protected:
		static float mGravity;
		static Dir4 mGravityDir4;

		GameLib::Vector2 GetGravityVec() {
			if (mGravityDir4 == Dir4::Down)
				return { 0.f,-mGravity };
			else if (mGravityDir4 == Dir4::Up)
				return { 0.f,mGravity };
			else if (mGravityDir4 == Dir4::Right)
				return { mGravity,0.f };
			else if(mGravityDir4 == Dir4::Left)
				return { -mGravity,0.f };
		}

		//重力の方向を下としたときの、大きさsizeの向きdirなベクトル
		GameLib::Vector2 GetSubjectiveDirVec(const Dir4& dir, float size) {
			auto rot = [](GameLib::Vector2&& vec) {return GameLib::Vector2{ -vec.y,vec.x }; };
			GameLib::Vector2 vec{ 0.f,-size };
			for (int i = 0; i < static_cast<int>(dir) + static_cast<int>(mGravityDir4); ++i) {
				vec = rot(std::move(vec));
			}
			return vec;
		}

	public:
		GravityActor(Actor* owner,int udpateOder=0)
			:Actor(owner,udpateOder)
		{}
		virtual ~GravityActor() = default;

		static const float GetGravity() noexcept {
			return mGravity;
		}
		static void SetGravity(float g) noexcept {
			mGravity = g;
		}
		static const Dir4& GetGravityDir4() noexcept {
			return mGravityDir4;
		}
		static void SetGraviyuDir4(Dir4&& d) noexcept {
			mGravityDir4 = std::move(d);
		}
		static void SeGravityDir4(const Dir4& g) noexcept {
			mGravityDir4 = g;
		}


	};
}