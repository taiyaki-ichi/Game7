#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawFontText.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace Game
{
	class KeyHex : public GameLib::Actor
	{
		GameLib::DrawFontText mText;
		GameLib::DrawTexture mTexture;

		GameLib::Vector2 mPosition;

	public:
		KeyHex(GameLib::Actor*, int drawOrder = 0);

		void SetPosition(const GameLib::Vector2&);
		void SetText(std::string&&);

		void AdjustPosition();
	};
}