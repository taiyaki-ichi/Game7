#include"GameLib/include/Draw/DrawFontText.hpp"
#include"GameLib/include/Resource/ResourceManager.hpp"
#include"GameLib/src/Windows/Graphics.hpp"
#include"GameLib/src/Windows/Window.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include "..\..\include\Draw\DrawFontText.hpp"

namespace GameLib
{
	DrawFontText::DrawFontText(int drawOrder)
		:DrawBase{drawOrder}
		, mText{""}
		, mFont{nullptr}
		, mSize{Font::Size::Size_24}
		, mPosition{}
		, mColor{0,0,0,255}
	{
	}
	DrawFontText::DrawFontText(const std::string& fileName,int drawOrder)
		:DrawFontText{drawOrder}
	{
		mFont = ResourceManager::GetFont(fileName);
	}
	void DrawFontText::Draw()
	{
		if (mFont) {
			Vector2 affinedPos = Affine(mPosition, Viewport::GetPos(), -Viewport::GetRotation(), Viewport::GetScale());
			Vector2 pos = { affinedPos.x + GetWindowWidth() / 2.f,-affinedPos.y + GetWindowHeigth() / 2.f };
			GraphycsDrawText(mFont, mSize, mText, pos.x, pos.y, mColor.R, mColor.G, mColor.B, mColor.A);
		}
	}
	void DrawFontText::SetText(const std::string& text)
	{
		mText = text;
	}
	void DrawFontText::SetText(std::string&& text)
	{
		mText = std::move(text);
	}
	void DrawFontText::SetSize(const Font::Size& size)
	{
		mSize = size;
	}
	void DrawFontText::SetSize(Font::Size&& size)
	{
		mSize = std::move(size);
	}
	void DrawFontText::SetPosition(const GameLib::Vector2& pos)
	{
		mPosition = pos;
	}
	void DrawFontText::SetColor(const GameLib::Color& color)
	{
		mColor = color;
	}
	void DrawFontText::SetColor(Color&& color)
	{
		mColor = std::move(color);
	}
	const std::string& DrawFontText::GetText() const
	{
		return mText;
	}
}