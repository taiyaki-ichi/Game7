#pragma once
#include<utility>
#include<string>

namespace Stage
{
	enum class Dir4
	{
		Down,
		Right,
		Up,
		Left
	};

	struct Dir4Vec
	{
		Dir4 mDir4;
		float mSize;

		constexpr Dir4Vec(const Dir4& dir4,float size)
			:mDir4(dir4)
			,mSize(size)
		{}

		constexpr Dir4Vec(Dir4&& dir4,float size)
			:mDir4(std::move(dir4))
			,mSize(size)
		{}
	};

	inline Dir4 StringToDir4(const std::string& str)
	{
		if (str == "Right")
			return Dir4::Right;
		else if (str == "Left")
			return Dir4::Left;
		else if (str == "Up")
			return Dir4::Up;
		else
			return Dir4::Down;
	}

	inline std::string Dir4ToString(const Dir4& dir)
	{
		if (dir == Dir4::Right)
			return "Right";
		else if (dir == Dir4::Left)
			return "Left";
		else if (dir == Dir4::Up)
			return  "Up";
		else
			return "Down";
	}

}