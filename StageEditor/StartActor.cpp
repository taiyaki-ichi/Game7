#include"StartActor.hpp"
#include"StageEditor.hpp"
#include"Stage/Stage.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace StageEditor
{
	StartActor::StartActor(GameLib::Actor* actor)
		:GameLib::Actor{actor}
		, mStageEditor{nullptr}
		, mStage{nullptr}
	{
		mStageEditor = new StageEditor{ this };
	}

	void StartActor::CustomizeUpdate()
	{
		if (mStageEditor&&mStageEditor->GetCheckFlag())
		{
			GameLib::Collider::SetIsDebug(false);

			mStageEditor->SetState(GameLib::Actor::State::Dead);
			mStageEditor = nullptr;
			mStage = new Stage::Stage{ this,"tmp.json" };
		}
		else if (mStage && GameLib::InputState::GetState(GameLib::Key::no0) == GameLib::ButtonState::Pressed)
		{
			GameLib::Collider::SetIsDebug(true);

			mStage->SetState(GameLib::Actor::State::Dead);
			mStage = nullptr;
			mStageEditor = new StageEditor{ this };
		}
	}
}