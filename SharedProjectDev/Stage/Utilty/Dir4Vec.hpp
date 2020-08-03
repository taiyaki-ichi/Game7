#pragma once
#include<utility>

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
}