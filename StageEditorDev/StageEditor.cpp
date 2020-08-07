#include"StageEditor.hpp"
#include"ConsoleMessage/ConsoleMessage.hpp"
#include"SceneEditor/SceneEditor.hpp"
#include"SaveFunc.hpp"
#include"LoadFunc.hpp"
#include"Cursor/Cursor.hpp"

namespace StageEditor
{
	
	StageEditor::StageEditor(GameLib::Actor* actor)
		:GameLib::Actor{actor}
		, mConsoleMessage{nullptr}
		, mNowSceneEditor{nullptr}
		, mSceneEditors{}
	{
		mConsoleMessage = new ConsoleMessage{ this };
		new Cursor{ this };

		UpdateConsoleScreen();
	}

	void StageEditor::CustomizeUpdate()
	{
		ProcessMessage();
	}

	void StageEditor::UpdateConsoleScreen()
	{
		std::system("cls");

		//ステージ情報の表示

		std::cout << " Scene\n";
		for (auto iter = mSceneEditors.begin(); iter != mSceneEditors.end(); iter++) {
			std::cout << "  |- " << iter->first;
			if (iter->second == mNowSceneEditor)
				std::cout << "  <---Nooooow!!!";
			std::cout << "\n";
		}
		std::cout << "\n";

		if (!mNowSceneEditor || !mNowSceneEditor->IsEdtingActor())
			std::cout << ">";


		if (mNowSceneEditor)
			mNowSceneEditor->UpdateConsoleScreen();
	}


	void StageEditor::SaveStage(std::string&& fileName)
	{
		std::unordered_map<std::string,std::vector<ActorData>> data{};
		for (auto& scene : mSceneEditors)
			data.emplace(scene.first, scene.second->GetData());

		SaveStageData(std::move(fileName), std::move(data));
	}

	void StageEditor::LoadStage(std::string&& fileName)
	{
		for (auto& prevScene : mSceneEditors)
			prevScene.second->SetState(GameLib::Actor::State::Dead);
		mSceneEditors.clear();

		LoadStageData(this, std::move(fileName));
	}

	void StageEditor::ProcessMessage()
	{
		auto strs = mConsoleMessage->GetMessage();
		if (strs.size() > 0)
		{
			//Sceneが一つもない場合、Actorを編集中じゃあない場合
			if (!mNowSceneEditor || !mNowSceneEditor->IsEdtingActor())
			{

				if (strs.size() == 3 && strs[0] == "add" && strs[1] == "scene")
					AddScene(std::move(strs[2]));
				if (strs.size() == 3 && strs[0] == "remove" && strs[1] == "scene")
					RemoveScene(std::move(strs[2]));
				if (strs.size() == 3 && strs[0] == "change" && strs[1] == "scene")
					ChangeScene(std::move(strs[2]));

				if (strs.size() == 2 && strs[0] == "create" && mNowSceneEditor)
					mNowSceneEditor->CreateActor(std::move(strs[1]));

				if (strs.size() == 3 && strs[0] == "save" && strs[1] == "as")
					SaveStage(std::move(strs[2]));
				if (strs.size() == 2 && strs[0] == "load")
					LoadStage(std::move(strs[1]));

				if (strs.size() == 1 && strs[0] == "help")
					Help();
			}
			//編集中の場合はそのActorへ
			else if(mNowSceneEditor->IsEdtingActor()){
				for (auto& s : strs)
					mNowSceneEditor->SendToActor(std::move(s));
			}

			mConsoleMessage->ClearMessage();

			UpdateConsoleScreen();
		}
	}


	SceneEditor* StageEditor::AddScene(std::string&& name)
	{
		//同じ名前のSceneは作らないmNowSceneがnullptrなら代入

		auto iter = mSceneEditors.find(name);
		if (iter == mSceneEditors.end())
		{
			auto scenePtr = new SceneEditor{ this };
			scenePtr->BeginToRest();
			mSceneEditors.emplace(name, scenePtr);

			if (!mNowSceneEditor) {
				mNowSceneEditor = scenePtr;
				mNowSceneEditor->BeginWorking();
			}

			return scenePtr;
		}

		return nullptr;
	}

	void StageEditor::RemoveScene(std::string&& name)
	{
		auto iter = mSceneEditors.find(name);
		if (iter != mSceneEditors.end())
		{
			if (iter->second == mNowSceneEditor)
				mNowSceneEditor = nullptr;
			iter->second->SetState(GameLib::Actor::State::Dead);
			mSceneEditors.erase(iter);
		}
	}

	void StageEditor::ChangeScene(std::string&& name)
	{
		auto iter = mSceneEditors.find(name);
		if (iter != mSceneEditors.end())
		{
			if (mNowSceneEditor)
				mNowSceneEditor->BeginToRest();

			iter->second->BeginWorking();
			mNowSceneEditor = iter->second;
		}
	}

	void StageEditor::Help()
	{

	}

}