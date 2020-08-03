#include"Gravity.hpp"

namespace Stage
{
	

	Dir4Vec Gravity::mDir4Vec = Gravity::DEFAULT_GRAVITY;

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

}