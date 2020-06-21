#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"Game/Dir4.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"Game/Dir4Vec.hpp"

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

		Dir4Vec GetRoundedDir4Vec(const GameLib::Vector2& vec) {
			Dir4 dir;
			float size;

			if (std::abs(vec.y) > std::abs(vec.x)) {
				if (vec.y > 0.f) {
					dir = Dir4::Up;
					size = vec.y;
				}
				else {
					dir = Dir4::Down;
					size = -vec.y;
				}
			}
			else {
				if (vec.x > 0.f) {
					dir = Dir4::Right;
					size = vec.x;
				}
				else {
					dir = Dir4::Left;
					size = -vec.x;
				}
			}
			int d = static_cast<int>(dir) - static_cast<int>(mGravityDir4);
			if (d < 0)
				d += 4;

			return Dir4Vec{ static_cast<Dir4>(d),size };
		}

		float GetDir4Size(const GameLib::Vector2& vec, const Dir4& dir) {
			auto dirVec = vec * GetSubjectiveDirVec(dir, 1.f);
			if (std::abs(dirVec.x) > std::abs(dirVec.y))
				return dirVec.x;
			else
				return dirVec.y;
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