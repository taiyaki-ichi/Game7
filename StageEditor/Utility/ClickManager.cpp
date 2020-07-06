#include"ClickManager.hpp"
#include"GameLib/include/InputState/InputState.hpp"

namespace StageEditor
{
	int ClickManager::mCnt = -1;

	bool ClickManager::mClickedFlag = false;
	bool ClickManager::mDoubleClickedFlag = false;

	ClickManager::ClickManager(GameLib::Actor* owner)
		:GameLib::Actor(owner,50)
	{
	}

	void ClickManager::CustomizeUpdate()
	{
		using namespace GameLib;

		if (mCnt > 0)
			mCnt--;

		mClickedFlag = false;
		mDoubleClickedFlag = false;

		if (InputState::GetState(MouseButton::Middle) == ButtonState::Pressed) {
			if (mCnt < 0)
				mCnt = DOUBLE_CLICK_TIME;
			else if (mCnt >= 0) {
				mDoubleClickedFlag = true;
				mCnt = -1;
			}
		}

		if (mCnt == 0) {
			mClickedFlag = true;
			mCnt = -1;
		}
	}

	bool ClickManager::Clicked()
	{
		return mClickedFlag;
	}

	bool ClickManager::DoubleClicked()
	{
		return mDoubleClickedFlag;
	}
}