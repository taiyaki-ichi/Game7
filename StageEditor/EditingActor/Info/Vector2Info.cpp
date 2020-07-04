#include"Vector2Info.hpp"
#include"GameLib/include/InputState/InputState.hpp"

namespace StageEditor
{

	Vector2Info::Vector2Info(EditingActorBase* owner, std::string& infoName)
		:InfoBase{ owner,std::string{"Vector2"},std::move(infoName) }
		, mVector2{0.f,0.f}
	{
	}
	void Vector2Info::EditingInfoUpdate()
	{
		mVector2 = GameLib::InputState::GetMousePos();
		if (GameLib::InputState::GetState(GameLib::MouseButton::Middle) == GameLib::ButtonState::Pressed)
			InfoConfirmed();
	}
	
	void Vector2Info::PrintInfo()
	{
		std::cout << "(" << mVector2.x << "," << mVector2.y << ")\n";
	}
}