#include"GravityFunc.hpp"
#include"Gravity.hpp"

namespace Stage
{
	GameLib::Vector2 GetVector2(const Dir4& dir4, float size)
	{
		auto rot = [](GameLib::Vector2&& vec) {return GameLib::Vector2{ -vec.y,vec.x }; };
		GameLib::Vector2 vec{ 0.f,-size };
		for (int i = 0; i < static_cast<int>(dir4) + static_cast<int>(Gravity::GetDir4()); ++i) {
			vec = rot(std::move(vec));
		}
		return vec;
	}


	Dir4Vec GetDir4Vec(const GameLib::Vector2& vec)
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
		int d = static_cast<int>(dir) - static_cast<int>(Gravity::GetDir4());
		if (d < 0)
			d += 4;

		return Dir4Vec{ static_cast<Dir4>(d),size };
	}


	float GetDir4DirectionSize(const GameLib::Vector2& vec, const Dir4& dir4)
	{
		auto dirVec = vec * GetVector2(dir4, 1.f);
		if (std::abs(dirVec.x) > std::abs(dirVec.y))
			return dirVec.x;
		else
			return dirVec.y;
	}


	GameLib::Vector2 GetVertialFlippedVector2(const GameLib::Vector2& vec)
	{
		if (Gravity::GetDir4() == Dir4::Down || Gravity::GetDir4() == Dir4::Up)
			return { vec.x,-vec.y };
		else
			return { -vec.x,vec.y };
	}


	GameLib::Vector2 GetHolizonalFlippedVector2(const GameLib::Vector2& vec)
	{
		if (Gravity::GetDir4() == Dir4::Down || Gravity::GetDir4() == Dir4::Up)
			return { -vec.x,vec.y };
		else
			return { vec.x,-vec.y };

	}

	void UpdatePhysicsModelWithGravity(PhysicsModel& model, const GameLib::Vector2& power, float horizonMaxSpeed, float virticalMaxSpeed, bool isRotaion)
	{
		if (Gravity::GetDir4() == Dir4::Up || Gravity::GetDir4() == Dir4::Down)
			model.Update(power, horizonMaxSpeed, virticalMaxSpeed);
		else
			model.Update(power, virticalMaxSpeed, horizonMaxSpeed);

		if (isRotaion)
			model.mRotation = Gravity::GetRotation();
	}
}