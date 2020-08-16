#include"HexChip.hpp"
#include"HexChipParam.hpp"
#include"ToVector2.hpp"

namespace Game
{

	HexChip::HexChip(GameLib::Actor* actor, int x, int y, std::string&& fileName, int drawOrder)
		:GameLib::Actor{ actor }
		, mTexture{ std::move(fileName) }
	{
		mTexture.SetPosition(ToVector2(x, y));
		mTexture.SetScale(HexChipParam::TEXTURE_SCALE);
		mTexture.SetDrawOrder(drawOrder);

	}

}