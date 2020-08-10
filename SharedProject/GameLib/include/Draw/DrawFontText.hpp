#pragma once
#include<string>
#include"DrawBase.hpp"
#include"GameLib/include/Resource/Font.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"Color.hpp"

namespace GameLib
{

	class DrawFontText : public DrawBase
	{
		std::string mText;
		Font* mFont;
		Font::Size mSize;
		GameLib::Vector2 mPosition;
		Color mColor;

	public:
		DrawFontText(int drawOrder = 0);
		DrawFontText(const std::string& fileName, int drawOrder = 0);
		virtual ~DrawFontText() = default;

		void Draw() override final;

		void SetText(const std::string& text);
		void SetText(std::string&& text);
		void SetSize(const Font::Size& size);
		void SetSize(Font::Size&& size);
		void SetPosition(const GameLib::Vector2& pos);
		void SetColor(const GameLib::Color& color);
		void SetColor(Color&& color);

		const std::string& GetText() const;
	};
}