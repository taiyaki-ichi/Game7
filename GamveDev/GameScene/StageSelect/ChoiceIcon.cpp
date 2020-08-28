#include"ChoiceIcon.hpp"
#include"StageSelectParam.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"HexChip/ToVector2.hpp"

namespace Game
{
	ChoiceIcon::ChoiceIcon(GameLib::Actor* actor)
		:GameLib::Actor{ actor }
		, mTexture{ "../Assets/StageSelect/icon.png" }
		, mPosX{}
		, mPosY{}
		, mCnt{ 0 }
	{
		mTexture.SetScale(StageSelectParam::ICON_SCALE);
	}

	void ChoiceIcon::CustomizeUpdate()
	{
		//mTexture.SetPosition(GameLib::InputState::GetMousePos() + GameLib::Vector2{ 0.f,HexMapParam::ICON_TEXTURE_ADJUST_Y });
		auto adjust = std::sin(mCnt / 20.f) * GameLib::Vector2{ 0.f,StageSelectParam::ICON_MOVE_LENGHT / 2.f };
		adjust += GameLib::Vector2{ 0.f,StageSelectParam::ICON_TEXTURE_ADJUST_Y };

		mTexture.SetPosition(ToVector2(mPosX, mPosY) + adjust);
		mCnt++;
	}

	void ChoiceIcon::SetPosision(int x,int y)
	{
		mPosX = x;
		mPosY = y;
	}

}