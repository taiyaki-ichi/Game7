#pragma once
#include"FloatInfo.hpp"
#include"GameLib/include/InputState/InputState.hpp"

namespace StageEditor
{
	FloatInfo::FloatInfo(EditingActorBase* owner, std::string& name)
		:InfoBase{owner,"Float",std::move(name)}
		, mFloat{0.f}
	{
	}
	
	void FloatInfo::EditingInfoUpdate()
	{
		if (GameLib::InputState::GetState(GameLib::MouseButton::Middle) == GameLib::ButtonState::Pressed)
			InfoConfirmed();
	}
	void FloatInfo::SetFloat(float f)
	{
		mFloat = f;
	}
	void FloatInfo::PrintInfo()
	{
		std::cout << mFloat << "\n";
	}
}