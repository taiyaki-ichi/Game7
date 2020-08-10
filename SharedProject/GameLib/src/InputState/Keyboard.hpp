#pragma once
#include"GameLib/include/InputState/InputStateInfo.hpp"

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