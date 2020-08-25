#pragma once
#include"Stage/SceneManager/Scene/Actor/StageActorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"Stage/Utilty/Dir4Vec.hpp"
#include"Stage/Utilty/State/StageStateManager.hpp"

namespace Stage
{
	class Nail : public ActorBase
	{
		GameLib::DrawTexture mTexture;
		StateManager<> mStateManager;

		Dir4 mDir;

	public:
		Nail(GameLib::Actor*, Dir4&&);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;
	};
}