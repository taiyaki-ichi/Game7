#pragma once
#include"GameLib/include/Actor/RootActor.hpp"
#include"Console/ConsoleMessage.hpp"
#include"GameLib/include/Draw/DrawCircle.hpp"
#include"StageEditor.hpp"
#include"Game/Stage/Stage.hpp"
#include"GameLib/include/InputState/InputState.hpp"

namespace StageEditor
{
	class StartActor : public GameLib::RootActor
	{
	public:
		StartActor()
			:GameLib::RootActor{}
			,mStageEditor{nullptr}
			, mStage{nullptr}
		{
			mStageEditor = new StageEditor{ this };
			new ConsoleMessage{ this };
			
		}
		virtual ~StartActor() = default;

		void CustomizeUpdate() override {
			
			if (GameLib::InputState::GetState(GameLib::Key::no0) == GameLib::ButtonState::Pressed) {
				if (mStageEditor) {
					mStageEditor->SetState(GameLib::Actor::State::Dead);
					mStageEditor = nullptr;
					mStage = new Game::Stage::Stage{ this,"test.json" };
				}
				else {
					mStage->SetState(GameLib::Actor::State::Dead);
					mStage = nullptr;
					mStageEditor = new StageEditor{ this };
				}
			}
			
		}

	private:
		StageEditor* mStageEditor;
		Game::Stage::Stage* mStage;

	};
}