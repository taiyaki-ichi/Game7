#include"PlayerIcon.hpp"
#include"HexMapParam.hpp"
#include"GameLib/include/InputState/InputState.hpp"

namespace Game::StageSelect
{
	PlayerIcon::PlayerIcon(GameLib::Actor* actor)
		:GameLib::Actor{ actor }
		, mTexture{ "../Assets/StageSelect/icon.png" }
		, mPairPos{}
		, mCnt{0}
	{
		mTexture.SetScale(HexMapParam::ICON_SCALE);
	}

	void PlayerIcon::CustomizeUpdate()
	{
		//mTexture.SetPosition(GameLib::InputState::GetMousePos() + GameLib::Vector2{ 0.f,HexMapParam::ICON_TEXTURE_ADJUST_Y });
		auto adjust = std::sin(mCnt / 20.f) * GameLib::Vector2{ 0.f,HexMapParam::ICON_MOVE_LENGHT / 2.f };
		adjust += GameLib::Vector2{ 0.f,HexMapParam::ICON_TEXTURE_ADJUST_Y };
		mTexture.SetPosition(ToVector2(mPairPos) + adjust);
		mCnt++;
	}

	void PlayerIcon::SetPosision(const PairVec& pos)
	{
		mPairPos = pos;
	}

	const PairVec& PlayerIcon::GetPosition() const
	{
		return mPairPos;
	}

}