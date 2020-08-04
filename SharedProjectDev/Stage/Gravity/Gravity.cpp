#include"Gravity.hpp"
#include"GameLib/include/Math/Numbers.hpp"

namespace Stage
{
	

	Dir4Vec Gravity::mDir4Vec = Gravity::DEFAULT_GRAVITY;
	bool Gravity::mIsRotation = false;

	void Gravity::SetDir4Vec(const Dir4Vec& vec)
	{
		mDir4Vec = vec;
	}

	void Gravity::SetDir4Vec(Dir4Vec&& vec) {
		mDir4Vec = std::move(vec);
	}

	void Gravity::SetSize(float size)
	{
		mDir4Vec.mSize = size;
	}

	void Gravity::SetDir4(const Dir4& dir)
	{
		mDir4Vec.mDir4 = dir;
	}

	void Gravity::SetDir4(Dir4&& dir)
	{
		mDir4Vec.mDir4 = std::move(dir);
	}

	Dir4Vec Gravity::GetDir4Vec()
	{
		return mDir4Vec;
	}

	float Gravity::GetSize()
	{
		return mDir4Vec.mSize;
	}

	Dir4 Gravity::GetDir4()
	{
		return mDir4Vec.mDir4;
	}

	void Gravity::Reset()
	{
		mDir4Vec = DEFAULT_GRAVITY;
	}

	GameLib::Vector2 Gravity::GetVector2()
	{
		if (mDir4Vec.mDir4 == Dir4::Down)
			return { 0.f,-mDir4Vec.mSize };
		else if (mDir4Vec.mDir4 == Dir4::Up)
			return { 0.f,mDir4Vec.mSize };
		else if (mDir4Vec.mDir4 == Dir4::Right)
			return { mDir4Vec.mSize,0.f };
		else if (mDir4Vec.mDir4 == Dir4::Left)
			return { -mDir4Vec.mSize,0.f };
	}

	float Gravity::GetRotation()
	{
		auto gravityDir4 = Gravity::GetDir4();
		if (gravityDir4 == Dir4::Down)
			return 0.f;
		else if (gravityDir4 == Dir4::Up)
			return GameLib::PI;
		else if (gravityDir4 == Dir4::Right)
			return GameLib::PI / 2.f;
		else
			return GameLib::PI * 3.f / 2.f;
	}

	bool Gravity::IsRotation()
	{
		return mIsRotation;
	}

	void Gravity::StartRotation()
	{
		mIsRotation = true;
	}

	void Gravity::FinishRotation()
	{
		mIsRotation = false;
	}
}