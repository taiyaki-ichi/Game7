#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"StageData.hpp"
#include<map>

namespace Game::StageSelect
{
	class DrawHexMap : public GameLib::Actor
	{
	public:
		DrawHexMap(GameLib::Actor*, const std::map<std::pair<int,int>, StageData>&);
		virtual ~DrawHexMap() = default;
	};
}