#include"Mouse.hpp"
#include"lib/src/Windows/Input.hpp"

namespace GameLib
{

	Mouse::Mouse()
	{
		mInputMouse = new MouseBase();
	}
	Mouse::~Mouse()
	{
		delete mInputMouse;
	}
	void Mouse::Update()
	{
		mInputMouse->Update();
	}

	Vector2 Mouse::GetMousePos()
	{
		return { mInputMouse->GetPositionX(), mInputMouse->GetPositionY() };
	}

	Vector2 Mouse::GetRerativeMousePos()
	{
		return { mInputMouse->GetRelativePosX(), mInputMouse->GetRelativePosY() };
	}

	bool Mouse::GetValue(MouseButton&& mouseButton)
	{
		return mInputMouse->GetMouseButtonValue(static_cast<int>(mouseButton));
	}
	ButtonState Mouse::GetState(MouseButton&& mouseButton)
	{
		int state = mInputMouse->GetMouseButtonState(static_cast<int>(mouseButton));
		if (state == 0)
			return ButtonState::None;
		else if (state == 1)
			return ButtonState::Pressed;
		else if (state == 2)
			return ButtonState::Held;
		else
			return ButtonState::Released;

	}
}