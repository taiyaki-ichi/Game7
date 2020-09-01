#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"Utilty/DrawFlameRect.hpp"
#include"GameLib/include/Draw/DrawFontText.hpp"
#include"Utilty/Button.hpp"

namespace Stage
{
	class SceneManager;
	class Kakko;

	class Pause : GameLib::Actor
	{
		//‰æ‘œ‚È‚Ç‚Ì•\Ž¦

		DrawFlameRect mFlameRect;

		SceneManager* mSceneManager;

		Button mResumeButton;
		GameLib::DrawFontText mResumeText;

		Button mReturnStageSelectButton;
		GameLib::DrawFontText mReturnStageSelectText;

		enum class Position
		{
			Resume,
			ReturnSelect
		};
		Position mPosition;

		Kakko* mKakko;

		GameLib::DrawFontText mPauseText;

		GameLib::DrawFontText mA;
		GameLib::DrawFontText mD;

		static int mNum;

	public:

		Pause(GameLib::Actor* stage,SceneManager* sceneManager);
		virtual ~Pause();

		void CustomizeUpdate() override;

		static int GetNum();

	};
}