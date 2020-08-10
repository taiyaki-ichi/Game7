#include"GameLib/include/InputState/InputState.hpp"
#include"GameLib/src/Windows/Input.hpp"
#include"Keyboard.hpp"
#include"Mouse.hpp"

namespace GameLib
{
	Mouse InputState::mMouse;
	Keyboard InputState::mKeyboard;

	bool InputState::GetValue(Key&& key)
	{
		return mKeyboard.GetValue(std::move(key));
	}
	bool InputState::GetValue(MouseButton&& mouseButton)
	{
		return mMouse.GetValue(std::move(mouseButton));
	}
	ButtonState InputState::GetState(Key&& key)
	{
		return mKeyboard.GetState(std::move(key));
	}
	ButtonState InputState::GetState(MouseButton&& mouseButton)
	{
		return mMouse.GetState(std::move(mouseButton));
	}
	Vector2 InputState::GetMousePos()
	{
		return mMouse.GetMousePos();
	}
	Vector2 InputState::GetRerativeMousePos()
	{
		return mMouse.GetRerativeMousePos();
	}
	void InputState::Update()
	{
		mMouse.Update();
		mKeyboard.Update();
	}
}