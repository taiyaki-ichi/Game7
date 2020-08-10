#pragma once
#include"GameLib/include/Actor/Actor.hpp"

namespace Stage
{
	class SceneManager;

	class Pause : GameLib::Actor
	{
		//‰æ‘œ‚È‚Ç‚Ì•\Ž¦


		SceneManager* mSceneManager;

	public:

		Pause(GameLib::Actor* stage,SceneManager* sceneManager);
		virtual ~Pause() = default;

		void CustomizeUpdate() override;

	};
}