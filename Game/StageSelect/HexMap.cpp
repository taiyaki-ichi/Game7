#include"HexMap.hpp"
#include"DrawHexMap.hpp"
#include"PlayerIcon.hpp"

namespace Game::StageSelect
{
	HexMap::HexMap(GameLib::Actor* actor)
		:GameLib::Actor{ actor }
		, mMap{}
		, mPlayerIcon{nullptr}
	{
		mMap.emplace(std::make_pair(0,0), StageData{"",StageState::Clear});
		mMap.emplace(std::make_pair(1, 0), StageData{"",StageState::Open});
		mMap.emplace(std::make_pair(2, 0), StageData{"",StageState::Close});
		mMap.emplace(std::make_pair(3, 0), StageData{"",StageState::Close });
		mMap.emplace(std::make_pair(1, 1), StageData{ "",StageState::Close });
		mMap.emplace(std::make_pair(2, -1), StageData{ "",StageState::Close });

		new DrawHexMap{ this,mMap };

		new PlayerIcon{ this };
	}

	void HexMap::CustomizeUpdate()
	{

	}
}