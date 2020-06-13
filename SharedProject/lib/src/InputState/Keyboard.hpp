#pragma once
#include"lib/include/InputState/InputStateInfo.hpp"
#include"lib/include/Math/Vector2.hpp"

namespace GameLib
{
	class KeyboardBase;

	class Keyboard
	{
		KeyboardBase* mInputKeyboard;

	public:
		Keyboard();
		~Keyboard();

		void Update();

		bool GetValue(Key&& key);
		ButtonState GetState(Key&& key);
	};
}