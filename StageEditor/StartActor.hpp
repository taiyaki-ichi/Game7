#pragma once
#include"GameLib/include/Actor/RootActor.hpp"
#include"GameLib/include/Draw/DrawCircle.hpp"
#include"StageEditor.hpp"
#include"Game/Stage/Stage.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace StageEditor
{
	class StartActor : public GameLib::RootActor
	{
	public:
		StartActor()
			:GameLib::RootActor{}
			,mStageEditor{nullptr}
			, mStage{nullptr}
		, mUpdateStageEditorFlag{ false }
		{
			GameLib::Collider::SetIsDebug(true);

			mStageEditor = new StageEditor{ this };

			
		}
		virtual ~StartActor() = default;

		void CustomizeUpdate() override {
			
			if (mUpdateStageEditorFlag) {
				mStageEditor->SetState(GameLib::Actor::State::Dead);
				mStageEditor = new StageEditor{ this };
			}

			if (GameLib::InputState::GetState(GameLib::Key::RightShift) == GameLib::ButtonState::Pressed) {
				if (mStageEditor) {

					mStageEditor->SetState(GameLib::Actor::State::Dead);
					mStageEditor = nullptr;
					mStage = new Game::Stage::Stage{ this,"test.json" ,true};

					GameLib::Viewport::SetPos(GameLib::Vector2{ 0.f,0.f });
					GameLib::Viewport::SetScale(1.f);
					GameLib::Viewport::SetRotation(0.f);
				}
				else {
					GameLib::Collider::SetIsDebug(true);

					mStage->SetState(GameLib::Actor::State::Dead);
					mStage = nullptr;
					mStageEditor = new StageEditor{ this };

					GameLib::Viewport::SetPos(GameLib::Vector2{ 0.f,0.f });
					GameLib::Viewport::SetScale(1.f);
					GameLib::Viewport::SetRotation(0.f);
				}
			}

			mUpdateStageEditorFlag = false;
			
		}

		void UpdateStageEditor() {
			mUpdateStageEditorFlag = true;
		}

	private:
		StageEditor* mStageEditor;
		Game::Stage::Stage* mStage;

		bool mUpdateStageEditorFlag;

	};
}