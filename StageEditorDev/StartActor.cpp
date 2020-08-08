#include"StartActor.hpp"
#include"StageEditor.hpp"
#include"Stage/Stage.hpp"
#include"GameLib/include/InputState/InputState.hpp"

namespace StageEditor
{
	StartActor::StartActor()
		:GameLib::RootActor{}
		, mStageEditor{nullptr}
		, mStage{nullptr}
	{
		mStageEditor = new StageEditor{ this };
	}

	void StartActor::CustomizeUpdate()
	{
		if (mStageEditor&&mStageEditor->GetCheckFlag())
		{
			mStageEditor->SetState(GameLib::Actor::State::Dead);
			mStageEditor = nullptr;
			mStage = new Stage::Stage{ this,"tmp.json" };
		}
		else if (mStage && GameLib::InputState::GetState(GameLib::Key::no0) == GameLib::ButtonState::Pressed)
		{
			mStage->SetState(GameLib::Actor::State::Dead);
			mStage = nullptr;
			mStageEditor = new StageEditor{ this };
		}
	}
}