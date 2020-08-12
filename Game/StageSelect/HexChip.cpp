#include"HexChip.hpp"
#include"HexMapParam.hpp"

namespace Game::StageSelect
{
	HexChip::HexChip(GameLib::Actor* actor,GameLib::Vector2&& pos, std::string&& fileName)
		:GameLib::Actor{ actor }
		, mTexture{ std::move(fileName) }
	{
		mTexture.SetPosition(std::move(pos));
		mTexture.SetScale(HexMapParam::TEXTURE_SCALE);
	}
}