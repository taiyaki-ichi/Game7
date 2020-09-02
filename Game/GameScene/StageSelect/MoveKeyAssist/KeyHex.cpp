#include"KeyHex.hpp"
#include"KeyHexParam.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"

namespace Game
{
	KeyHex::KeyHex(GameLib::Actor* actor,int drawOrder)
		:GameLib::Actor{actor}
		, mText{ "../Assets/Font/mplus-1c-black.ttf" }
		, mTexture{ "../Assets/StageSelect/black-hex.png" }
		, mPosition{}
	{
		using namespace KeyHexParam;

		mText.SetSize(FONT_SIZE);
		mTexture.SetScale(TEXTURE_SCALE);

		mText.SetDrawOrder(drawOrder + 1);
		mTexture.SetDrawOrder(drawOrder);
	}

	void KeyHex::SetPosition(const GameLib::Vector2& pos)
	{
		mPosition = pos;
	}

	void KeyHex::SetText(std::string&& str)
	{
		mText.SetText(std::move(str));
	}

	void KeyHex::AdjustPosition()
	{
		mText.SetPosition(GameLib::Viewport::GetPos() + mPosition);
		mTexture.SetPosition(GameLib::Viewport::GetPos() + mPosition);
	}

}