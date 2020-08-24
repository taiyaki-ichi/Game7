#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"Utilty/DrawFlameRect.hpp"

namespace Stage
{
	class SceneManager;

	class Pause : GameLib::Actor
	{
		//‰æ‘œ‚È‚Ç‚Ì•\Ž¦

		DrawFlameRect mFlameRect;

		SceneManager* mSceneManager;

	public:

		Pause(GameLib::Actor* stage,SceneManager* sceneManager);
		virtual ~Pause() = default;

		void CustomizeUpdate() override;

	};
}