#include"StageEditor.hpp"
#include"SceneEditor/SceneEditor.hpp"
#include"Console/ConsoleMessage.hpp"
#include"GameLib/include/InputState/InputState.hpp"

namespace StageEditor
{

	StageEditor::StageEditor(GameLib::Actor* owner)
		:GameLib::Actor{owner}
		, mNowEditingScene{nullptr}
		,mScenes{}
		, mStageName{""}
	{
		PrintStageInfo();
	}

	void StageEditor::AddScene(const std::string& sceneName)
	{
		mScenes.emplace(sceneName, new SceneEditor(this));
		if (mNowEditingScene == nullptr) {
			mNowEditingScene = mScenes.begin()->second;
			mNowEditingScene->Active();
		}
	}
	void StageEditor::DeleteScene(const std::string& sceneName)
	{
		auto i = mScenes.find(sceneName);
		if (i != mScenes.end()) {
			i->second->SetState(GameLib::Actor::State::Dead);
			auto ptr = i->second;
			if (i->second == mNowEditingScene) {
				if (mScenes.size() > 1) {
					mNowEditingScene = mScenes.begin()->second;
					mNowEditingScene->Active();
				}
				else
					mNowEditingScene = nullptr;
			}
			mScenes.erase(i);	
		}
	}
	void StageEditor::ChangeScene(const std::string& sceneName)
	{
		auto i = mScenes.find(sceneName);
		if (i != mScenes.end()) {
			mNowEditingScene->Pause();
			mNowEditingScene = i->second;
			mNowEditingScene->Active();
		}
	}
	void StageEditor::PrintStageInfo()
	{
		std::cout << "StageName: " << mStageName << "\n";
		for (auto iter = mScenes.begin(); iter != mScenes.end(); iter++) {
			std::cout << " * " << iter->first;
			if (iter->second == mNowEditingScene)
				std::cout << " <-Now!!!";
			std::cout << "\n";
		}
		std::cout << "\n\n";
		std::cout << ">";
	}

	void StageEditor::CustomizeUpdate()
	{
		if (GameLib::InputState::GetState(GameLib::Key::Enter) == GameLib::ButtonState::Pressed)
		{
			auto strings = ConsoleMessage::GetStrings();

			if (strings.size() == 3 && strings[1] == "scene") {
				if (strings[0] == "add")
					AddScene(strings[2]);
				else if (strings[0] == "change")
					ChangeScene(strings[2]);
				else if (strings[0] == "delete")
					DeleteScene(strings[2]);
			}

			if (strings.size() == 3 && strings[0] == "set" && strings[1] == "stagename")
				mStageName = strings[2];
			

			PrintStageInfo();
		}

	}
}