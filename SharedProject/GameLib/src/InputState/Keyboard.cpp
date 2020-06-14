#include"Keyboard.hpp"
#include"GameLib/src/Windows/Input.hpp"

namespace GameLib
{
	Keyboard::Keyboard()
	{
		mInputKeyboard = new KeyboardBase();
	}
	Keyboard::~Keyboard()
	{
		delete mInputKeyboard;
	}
	void Keyboard::Update()
	{
		mInputKeyboard->Update();
	}
	bool Keyboard::GetValue(Key&& key)
	{
		return mInputKeyboard->GetKeyValue(static_cast<unsigned char>(key));
	}
	ButtonState Keyboard::GetState(Key&& key)
	{
		int state = mInputKeyboard->GetKeyState(static_cast<int>(key));
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