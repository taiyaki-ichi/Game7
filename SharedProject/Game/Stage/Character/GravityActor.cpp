#include"Game/Stage/Character/GravityActor.hpp"
#include "GravityActor.hpp"
#include"GameLib/include/Math/Numbers.hpp"

namespace Game::Stage
{
	float GravityActor::mGravity = 1.f;
	Dir4 GravityActor::mGravityDir4 = Dir4::Down;

	GameLib::Vector2 GravityActor::GetGravityVector2()
	{
		if (mGravityDir4 == Dir4::Down)
			return { 0.f,-mGravity };
		else if (mGravityDir4 == Dir4::Up)
			return { 0.f,mGravity };
		else if (mGravityDir4 == Dir4::Right)
			return { mGravity,0.f };
		else if (mGravityDir4 == Dir4::Left)
			return { -mGravity,0.f };
	}
	GameLib::Vector2 GravityActor::GetDir4Vec(const Dir4& dir, float size)
	{
		auto rot = [](GameLib::Vector2&& vec) {return GameLib::Vector2{ -vec.y,vec.x }; };
		GameLib::Vector2 vec{ 0.f,-size };
		for (int i = 0; i < static_cast<int>(dir) + static_cast<int>(mGravityDir4); ++i) {
			vec = rot(std::move(vec));
		}
		return vec;
	}
	Dir4Vec GravityActor::GetRoundedDir4Vec(const GameLib::Vector2& vec)
	{
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
	float GravityActor::GetDir4Size(const GameLib::Vector2& vec, const Dir4& dir)
	{
		auto dirVec = vec * GetDir4Vec(dir, 1.f);
		if (std::abs(dirVec.x) > std::abs(dirVec.y))
			return dirVec.x;
		else
			return dirVec.y;
	}

	float GravityActor::GetGravityRotation()
	{
		if (mGravityDir4 == Dir4::Down)
			return 0.f;
		else if (mGravityDir4 == Dir4::Up)
			return GameLib::PI;
		else if (mGravityDir4 == Dir4::Right)
			return GameLib::PI / 2.f;
		else
			return GameLib::PI * 3.f / 2.f;
	}

	GameLib::Vector2 GravityActor::GetVerticalFlippedVector2(const GameLib::Vector2& vec)
	{
		if (mGravityDir4 == Dir4::Down || mGravityDir4 == Dir4::Up)
			return { vec.x,-vec.y };
		else
			return { -vec.x,vec.y };
	}

	GameLib::Vector2 GravityActor::GetHolizonalFlippedVector2(const GameLib::Vector2& vec)
	{
		if (mGravityDir4 == Dir4::Down || mGravityDir4 == Dir4::Up)
			return { -vec.x,vec.y };
		else
			return { vec.x,-vec.y };
	}

	void GravityActor::UpdatePhysicsModel(PhysicsModel& model, const GameLib::Vector2& power, float horizonMaxSpeed, float virticalMaxSpeed)
	{
		if (mGravityDir4 == Dir4::Up || mGravityDir4 == Dir4::Down)
			model.Update(power, horizonMaxSpeed, virticalMaxSpeed);
		else
			model.Update(power, virticalMaxSpeed, horizonMaxSpeed);

		model.mRotation = GetGravityRotation();
	}

}