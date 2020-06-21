#pragma once
#include"Dir4.hpp"
#include"GameLib/include/Math/Vector2.hpp"

namespace Game
{

	class Dir4Vec
	{
	public:

		Dir4 mDir4;
		float mSize;

		Dir4Vec()
			:mDir4(Dir4::Right)
			,mSize(0.f)
		{}

		Dir4Vec(const Dir4& dir,float s)
			:mDir4(dir)
			,mSize(s)
		{}

		GameLib::Vector2 GetVector2() {
			if (mDir4 == Dir4::Right)
				return { mSize,0.f };
			else if (mDir4 == Dir4::Left)
				return { -mSize,0.f };
			else if (mDir4 == Dir4::Up)
				return { 0.f,mSize };
			else
				return { 0.f,-mSize };
		}
	};

}