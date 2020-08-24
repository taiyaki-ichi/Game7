#include"CursorButton.hpp"
#include"IsInScope.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"

namespace Stage
{
	CursorButton::CursorButton(GameLib::Actor* actor, int drawOrder)
		:GameLib::Actor{ actor }
		, mFlameRect{ drawOrder }
		, mIsClicked{ false }
	{
		mFlameRect.SetFlameWidth(10.f);
	}

	void CursorButton::CustomizeUpdate()
	{
		auto pos = mFlameRect.GetPosition();
		float w = mFlameRect.GetWidth();
		float h = mFlameRect.GetHeight();

		float left = pos.x - w / 2.f;
		float right = pos.x + w / 2.f;
		float bottom = pos.y - h / 2.f;
		float top = pos.y + h / 2.f;

		auto cursorPos = GameLib::InputState::GetMousePos() + GameLib::Viewport::GetPos();
		//std::cout << cursorPos.x << "," << cursorPos.y << "\n";
		bool isIn = left <= cursorPos.x && cursorPos.x <= right && bottom <= cursorPos.y && cursorPos.y <= top;

		if (isIn && GameLib::InputState::GetState(GameLib::MouseButton::Middle) == GameLib::ButtonState::Pressed)
		{
			mFlameRect.SetRectColor({ 150,150,150,255 });
			mIsClicked = true;
		}
		else if (isIn) {
			mFlameRect.SetRectColor({ 200,200,200,255 });
			mIsClicked = false;
		}
		else {
			mFlameRect.SetRectColor({ 255,255,255,255 });
			mIsClicked = false;
		}
	}

	void CursorButton::SetWidthAndHeight(float w, float h)
	{
		mFlameRect.SetWidthAndHeight(w, h);
	}

	void CursorButton::SetPosition(const GameLib::Vector2& pos)
	{
		mFlameRect.SetPosition(pos);
	}

	bool CursorButton::IsClicked() const
	{
		return mIsClicked;
	}

}