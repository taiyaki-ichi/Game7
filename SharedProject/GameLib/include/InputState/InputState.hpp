#pragma once
#include"GameLib/src/InputState/Keyboard.hpp"
#include"GameLib/src/InputState/Mouse.hpp"

namespace GameLib
{
	
	class InputState
	{
		static Mouse mMouse;
		static Keyboard mKeyboard;

	public:
		static bool GetValue(Key&& key);
		static bool GetValue(MouseButton&& mouseButton);

		static ButtonState GetState(Key&& key);
		static ButtonState GetState(MouseButton&& mouseButton);

		static Vector2 GetMousePos();
		static Vector2 GetRerativeMousePos();

		static void Update();
	};
}