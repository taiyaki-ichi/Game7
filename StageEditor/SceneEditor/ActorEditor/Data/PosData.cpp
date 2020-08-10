#include"PosData.hpp"

namespace StageEditor
{
	PosData::PosData(int size)
		:mSize{size}
		, mPosData{}
		, mDefinedBackData{false}
	{}

	void PosData::UpdatePosDataBack(GameLib::Vector2&& pos)
	{
		if (!IsOK())
		{
			if (mDefinedBackData) {
				mPosData.emplace_back(std::move(pos));
				mDefinedBackData = false;
			}
			else if (mPosData.size() == 0)
			{
				mPosData.emplace_back(std::move(pos));
			}
			else 
			{
				mPosData.pop_back();
				mPosData.emplace_back(std::move(pos));
			}
		}
	}

	void PosData::DefinePosDataBeck()
	{
		mDefinedBackData = true;
	}

	bool PosData::IsOK() const
	{
		return mDefinedBackData && (mSize == mPosData.size());
	}

	int PosData::GetDataNum() const
	{
		return mPosData.size();
	}

	const GameLib::Vector2& PosData::operator[](int n) const
	{
		return mPosData[n];
	}
}