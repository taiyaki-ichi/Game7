#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace Game::StageSelect
{
	class HexChip : GameLib::Actor
	{
		GameLib::DrawTexture mTexture;

	public:
		HexChip(GameLib::Actor*, GameLib::Vector2&&, std::string&&, int drawOrder = 0);
	};

}