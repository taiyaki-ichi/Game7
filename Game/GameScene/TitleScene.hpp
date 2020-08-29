#pragma once
#include"GameSceneBase.hpp"
#include"TitleScene/Button.hpp"
#include"TitleScene/CursorPos.hpp"

namespace Game
{
	class TitleScene : public SceneBase
	{
		Button mButtonA;
		Button mButtonD;

		CursorPos mCursorPos;

	public:
		TitleScene(GameLib::Actor*,const GameData&);

		void CustomizeUpdate() override;
	};
}