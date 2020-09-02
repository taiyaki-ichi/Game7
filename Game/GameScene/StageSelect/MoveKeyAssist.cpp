#include"MoveKeyAssist.hpp"
#include"MoveKeyAssist/KeyHex.hpp"
#include"MoveKeyAssist/MoveKeyAssistParam.hpp"
#include"GameLib/include/Math/Numbers.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"

namespace Game
{
	MoveKeyAssist::MoveKeyAssist(GameLib::Actor* actor,int drawOrder)
		:GameLib::Actor{actor}
		, mIconTexture{ "../Assets/Player/icon.png" }
		, mKeyHex{}
	{
		mIconTexture.SetScale(MoveKeyAssistParam::ICON_TEXTURE_SCALE);
		mIconTexture.SetDrawOrder(drawOrder);

		for (int i = 0; i < 6; i++)
			mKeyHex.emplace_back(new KeyHex{ this,drawOrder });
		//D‚©‚ç”½ŽžŒv‰ñ‚è
		mKeyHex[0]->SetText("D");
		mKeyHex[1]->SetText("E");
		mKeyHex[2]->SetText("W");
		mKeyHex[3]->SetText("A");
		mKeyHex[4]->SetText("Z");
		mKeyHex[5]->SetText("X");
	}

	void MoveKeyAssist::SetPosition(const GameLib::Vector2& pos)
	{
		mPosition = pos;
		auto adjust = GameLib::Vector2{ MoveKeyAssistParam::HEX_DISTAMCE,0.f };
		for (int i = 0; i < 6; i++)
		{
			mKeyHex[i]->SetPosition(adjust + pos);
			adjust = GameLib::Vector2::Rotation(adjust, GameLib::PI * 2.f / 6.f);
		}
	}

	void MoveKeyAssist::AdjustPosition()
	{
		mIconTexture.SetPosition(GameLib::Viewport::GetPos() + mPosition);
		for (auto ptr : mKeyHex)
			ptr->AdjustPosition();
	}


}