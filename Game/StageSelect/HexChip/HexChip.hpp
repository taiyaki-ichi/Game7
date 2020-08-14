#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace Game
{
	class HexChip : GameLib::Actor
	{
		GameLib::DrawTexture mTexture;

	public:

		HexChip(GameLib::Actor*, const std::pair<int, int>&, std::string&&, int drawOrder = 0);

	};

}