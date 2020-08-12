#include"DrawHexMap.hpp"
#include"HexMapParam.hpp"
#include"GameLib/include/Math/Numbers.hpp"
#include"Hex.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"HexChip.hpp"

namespace Game::StageSelect
{
	DrawHexMap::DrawHexMap(GameLib::Actor* actor,const std::map<std::pair<int,int>,StageData>& data)
		:GameLib::Actor{ actor }
	{
		const auto unitX = GameLib::Vector2{ HexMapParam::HEX_LENGTH * HexMapParam::TEXTURE_SCALE,0.f };
		const auto unitY = GameLib::Vector2::Rotation(unitX, GameLib::PI / 3.f);
		//const auto unitZ = GameLib::Vector2::Rotation(unitX, -GameLib::PI / 3.f);

		//std::cout << "x: " << unitX.x << "," << unitX.y << "\n";
		//std::cout << "y: " << unitY.x << "," << unitY.y << "\n";
		//std::cout << "z: " << unitZ.x << "," << unitZ.y << "\n";

		for (auto& d : data)
		{
			//std::cout <<"d"<< d.first.first << "," << d.first.second << "\n";
			auto hex = ToHex(d.first);
			std::cout << hex.GetX() << "," << hex.GetY() << "\n";
			auto pos = hex.GetX() * unitX + hex.GetY() * unitY;
			//std::cout << pos.x << "," << pos.y << "\n";
			new HexChip{ this,std::move(pos) };
		}

	}
	
}