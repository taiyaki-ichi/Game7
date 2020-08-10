#pragma once
#include"GameLib/include/InputState/InputStateInfo.hpp"
#include"GameLib/include/Math/Vector2.hpp"

namespace GameLib
{
	class MouseBase;

	class Mouse
	{
		MouseBase* mInputMouse;

	public:
		Mouse();
		~Mouse();

		//–ˆƒtƒŒ[ƒ€ŒÄ‚Î‚ê‚é
		void Update();

		Vector2 GetMousePos();
		Vector2 GetRerativeMousePos();

		bool GetValue(MouseButton&& mouseButton);
		ButtonState GetState(MouseButton&& mouseButton);

	};
}