#include"Gravity.hpp"
#include"GameLib/include/Math/Numbers.hpp"

namespace Game::Stage
{
	float Gravity::mSize = 1.f;
	Dir4 Gravity::mDir4 = Dir4::Down;



	Gravity::Gravity(GameLib::Actor* owner)
		:GameLib::Actor{owner}
	{
	}

	void Gravity::CustomizeUpdate()
	{
	}

	GameLib::Vector2 Gravity::GetGravityVector2()
	{
		if (mDir4 == Dir4::Down)
			return { 0.f,-mSize };
		else if (mDir4 == Dir4::Up)
			return { 0.f,mSize };
		else if (mDir4 == Dir4::Right)
			return { mSize,0.f };
		else if (mDir4 == Dir4::Left)
			return { -mSize,0.f };
	}

	GameLib::Vector2 Gravity::GetVector2(const Dir4& dir4, float size)
	{
		auto rot = [](GameLib::Vector2&& vec) {return GameLib::Vector2{ -vec.y,vec.x }; };
		GameLib::Vector2 vec{ 0.f,-size };
		for (int i = 0; i < static_cast<int>(dir4) + static_cast<int>(mDir4); ++i) {
			vec = rot(std::move(vec));
		}
		return vec;
	}

	Dir4Vec Gravity::GetDir4Vec(const GameLib::Vector2& vec)
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
		int d = static_cast<int>(dir) - static_cast<int>(mDir4);
		if (d < 0)
			d += 4;

		return Dir4Vec{ static_cast<Dir4>(d),size };
	}

	float Gravity::GetDir4Size(const GameLib::Vector2& vec, const Dir4& dir4)
	{
		auto dirVec = vec * GetVector2(dir4, 1.f);
		if (std::abs(dirVec.x) > std::abs(dirVec.y))
			return dirVec.x;
		else
			return dirVec.y;
	}

	float Gravity::GetGravityRotation()
	{
		if (mDir4 == Dir4::Down)
			return 0.f;
		else if (mDir4 == Dir4::Up)
			return GameLib::PI;
		else if (mDir4 == Dir4::Right)
			return GameLib::PI / 2.f;
		else
			return GameLib::PI * 3.f / 2.f;
	}

	GameLib::Vector2 Gravity::GetVerticalFlippedVector2(const GameLib::Vector2& vec)
	{
		if (mDir4 == Dir4::Down || mDir4 == Dir4::Up)
			return { vec.x,-vec.y };
		else
			return { -vec.x,vec.y };
	}

	GameLib::Vector2 Gravity::GetHolizonalFlippedVector2(const GameLib::Vector2& vec)
	{
		if (mDir4 == Dir4::Down || mDir4 == Dir4::Up)
			return { -vec.x,vec.y };
		else
			return { vec.x,-vec.y };
	}

	void Gravity::UpdatePhysicsModel(PhysicsModel& model, const GameLib::Vector2& power, float horizonMaxSpeed, float virticalMaxSpeed, bool isRotaion)
	{
		if (mDir4 == Dir4::Up || mDir4 == Dir4::Down)
			model.Update(power, horizonMaxSpeed, virticalMaxSpeed);
		else
			model.Update(power, virticalMaxSpeed, horizonMaxSpeed);

		if (isRotaion)
			model.mRotation = GetGravityRotation();
	}

	float Gravity::GetGravitySize() noexcept
	{
		return mSize;
	}

	const Dir4& Gravity::GetGravityDir4() noexcept
	{
		return mDir4;
	}

	void Gravity::SetGravityDir4(const Dir4& dir4)
	{
		mDir4 = dir4;
	}

	/*
	void Gravity::SetSize(float s)
	{
		mSize = s;
	}

	void Gravity::SetDir4(const Dir4& dir4)
	{
		mDir4 = dir4;
	}

	void Gravity::SetDir4Vec(const Dir4Vec& dir4Vec)
	{
		mSize = dir4Vec.mSize;
		mDir4 = dir4Vec.mDir4;
	}
	*/

}