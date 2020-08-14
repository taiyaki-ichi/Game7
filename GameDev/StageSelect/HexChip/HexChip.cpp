#include"HexChip.hpp"
#include"HexChipParam.hpp"
#include"ToVector2.hpp"

namespace Game
{
	HexChip::HexChip(GameLib::Actor* actor, const std::pair<int, int>& pairPos, std::string&& fileName, int darwOrder)
		:GameLib::Actor{ actor }
		, mTexture{ std::move(fileName) }
	{
		mTexture.SetPosition(ToVector2(pairPos));
		mTexture.SetScale(HexChipParam::TEXTURE_SCALE);
		mTexture.SetDrawOrder(darwOrder);

		/*
		if (type == Type::BlackCircle)
			mTexture.SetTexture("../Assets/StageSelect/circle_hex.png");
		else if(type==Type::Circle)
			mTexture.SetTexture("../Assets/StageSelect/clear_hex.png");
		else if(type==Type::Cross)
			mTexture.SetTexture("../Assets/StageSelect/batu_hex.png");
		else
			mTexture.SetTexture("../Assets/StageSelect/hex.png");
			*/
	}
}