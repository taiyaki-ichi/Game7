#include"HexMap.hpp"
#include"DrawHexMap.hpp"

namespace Game::StageSelect
{
	HexMap::HexMap(GameLib::Actor* actor)
		:GameLib::Actor{ actor }
		, mMap{}
		, mPlayerIcon{nullptr}
	{
		mMap.emplace(std::make_pair(0,0), StageData{"a"});
		mMap.emplace(std::make_pair(1, 0), StageData{"b"});
		mMap.emplace(std::make_pair(2, 0), StageData{"c"});
		mMap.emplace(std::make_pair(3, 0), StageData{"d"});
		mMap.emplace(std::make_pair(1, 1), StageData{ "d" });
		mMap.emplace(std::make_pair(2, -1), StageData{ "d" });

		for (auto& a : mMap)
		{
			std::cout << a.first.first << "," << a.first.second << "\n";
		}

		new DrawHexMap{ this,mMap };
	}

	void HexMap::CustomizeUpdate()
	{

	}
}