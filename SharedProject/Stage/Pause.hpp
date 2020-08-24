#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"Utilty/DrawFlameRect.hpp"
#include"GameLib/include/Draw/DrawFontText.hpp"

namespace Stage
{
	class SceneManager;
	class CursorButton;

	class Pause : GameLib::Actor
	{
		//‰æ‘œ‚È‚Ç‚Ì•\Ž¦

		DrawFlameRect mFlameRect;

		SceneManager* mSceneManager;

		CursorButton* mResumeButton;
		GameLib::DrawFontText mResumeText;

		CursorButton* mReturnStageSelectButton;
		GameLib::DrawFontText mReturnStageSelectText;

	public:

		Pause(GameLib::Actor* stage,SceneManager* sceneManager);
		virtual ~Pause() = default;

		void CustomizeUpdate() override;

	};
}