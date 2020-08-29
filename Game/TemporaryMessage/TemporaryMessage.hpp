#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawFontText.hpp"

namespace Game
{
	class TemporaryMessage : public GameLib::Actor
	{
		GameLib::DrawFontText mText;

		int mCnt;
		const int mDeathTime;

		GameLib::Vector2 mPosition;

	public:
		TemporaryMessage(GameLib::Actor*, int);

		void CustomizeUpdate() override;

		void SetText(std::string&&);
		void SetSize(GameLib::Font::Size&&);
		void SetPosition(const GameLib::Vector2&);
	};
}