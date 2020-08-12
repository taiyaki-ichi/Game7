#include"DrawHexMap.hpp"
#include"HexMapParam.hpp"
#include"GameLib/include/Math/Numbers.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"HexChip.hpp"

namespace Game::StageSelect
{
	DrawHexMap::DrawHexMap(GameLib::Actor* actor,const std::map<std::pair<int,int>,StageData>& data)
		:GameLib::Actor{ actor }
	{

		for (auto& d : data)
		{
			//std::cout <<"d"<< d.first.first << "," << d.first.second << "\n";
			//std::cout << hex.GetX() << "," << hex.GetY() << "\n";
			auto pos = d.first.first * HexMapParam::UNIT_X + d.first.second * HexMapParam::UNIT_Y;
			//std::cout << pos.x << "," << pos.y << "\n";
			
			std::string fileName;
			if (d.second.mStageState == StageState::Clear)
				fileName = std::string{ "../Assets/StageSelect/clear_hex.png" };
			else if (d.second.mStageState == StageState::Close)
				fileName = std::string{ "../Assets/StageSelect/batu_hex.png" };
			else
				fileName = std::string{ "../Assets/StageSelect/hex.png" };

			new HexChip{ this,std::move(pos) ,std::move(fileName) };
		}

	}
	
}