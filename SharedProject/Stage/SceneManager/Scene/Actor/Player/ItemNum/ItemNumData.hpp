#pragma once
#include<array>

namespace Stage
{
	//’Ê’m—p
	struct ItemNumData {
		int mLifeNum;
		int mGemNum;
		std::array<bool, 3> mTearGemCnt;
		ItemNumData(int life, int gem,const std::array<bool, 3>& tear)
			:mLifeNum{ life }, mGemNum{ gem }, mTearGemCnt{tear}
		{};
	};
}