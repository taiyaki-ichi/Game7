#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace Game
{
	class HexChip : public GameLib::Actor
	{
		GameLib::DrawTexture mTexture;

	public:
		HexChip(GameLib::Actor*, int, int, std::string&&, int drawOrder = 0);

	};

}