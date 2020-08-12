#pragma once
#include"HexMapParam.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include<utility>

namespace Game::StageSelect
{

	using PairVec = std::pair<int, int>;

	inline GameLib::Vector2 ToVector2(const PairVec& pair)
	{
		auto x = static_cast<float>(pair.first) * HexMapParam::UNIT_X;
		auto y = static_cast<float>(pair.second) * HexMapParam::UNIT_Y;
		return x + y;
	}

	inline PairVec AddPair(const PairVec& pair1, const PairVec& pair2)
	{
		return std::make_pair(pair1.first + pair2.first, pair1.second + pair2.second);
	}
	

	const PairVec DIR_E_PAIR = std::make_pair(0, 1);
	const PairVec DIR_D_PAIR = std::make_pair(1, 0);
	const PairVec DIR_X_PAIR = std::make_pair(1, -1);
	const PairVec DIR_W_PAIR = std::make_pair(-1, 1);
	const PairVec DIR_A_PAIR = std::make_pair(-1, 0);
	const PairVec DIR_Z_PAIR = std::make_pair(0, -1);

}