#include"HexChip.hpp"
#include"HexMapParam.hpp"

namespace Game::StageSelect
{
	HexChip::HexChip(GameLib::Actor* actor,GameLib::Vector2&& pos)
		:GameLib::Actor{ actor }
		, mTexture{ "../Assets/StageSelect/hex.png" }
	{
		mTexture.SetPosition(std::move(pos));
		mTexture.SetScale(HexMapParam::TEXTURE_SCALE);
	}
}