#include"PosInfo.hpp"
#include"GameLib/include/InputState/InputState.hpp"

namespace StageEditor
{
	PosInfo::PosInfo(GameLib::Actor* owner)
		:GameLib::Actor(owner)
		, mPosition{ 0.f,0.f }
		, mIsOK{ false }
	{
		
	}
	void PosInfo::CustomizeUpdate()
	{
		if (!mIsOK)
		{
			mPosition = GameLib::InputState::GetMousePos();
			if (GameLib::InputState::GetState(GameLib::MouseButton::Middle) == GameLib::ButtonState::Pressed)
				mIsOK = true;
		}
	}
	bool PosInfo::IsOK()
	{
		return mIsOK;
	}
	const GameLib::Vector2& PosInfo::GetPosition()
	{
		return mPosition;
	}
}