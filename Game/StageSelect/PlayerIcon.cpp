#include"PlayerIcon.hpp"
#include"HexMapParam.hpp"
#include"GameLib/include/InputState/InputState.hpp"

namespace Game::StageSelect
{
	PlayerIcon::PlayerIcon(GameLib::Actor* actor)
		:GameLib::Actor{ actor }
		, mTexture{ "../Assets/StageSelect/icon.png" }
	{
		mTexture.SetScale(HexMapParam::ICON_SCALE);
	}

	void PlayerIcon::CustomizeUpdate()
	{
		mTexture.SetPosition(GameLib::InputState::GetMousePos() + GameLib::Vector2{ 0.f,HexMapParam::ICON_TEXTURE_ADJUST_Y });
	}

}