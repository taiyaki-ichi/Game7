#include"StageEditor.hpp"
#include"ConsoleMessage/ConsoleMessage.hpp"
#include"SceneEditor/SceneEditor.hpp"
#include"SaveFunc.hpp"
#include"LoadFunc.hpp"
#include"Cursor/Cursor.hpp"
#include"SceneEditor/CreateActorEditor.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace StageEditor
{
	
	StageEditor::StageEditor(GameLib::Actor* actor)
		:GameLib::Actor{actor}
		, mConsoleMessage{nullptr}
		, mNowSceneEditor{nullptr}
		, mSceneEditors{}
		, mCheckFlag{false}
	{
		mConsoleMessage = new ConsoleMessage{ this };
		new Cursor{ this };

		LoadStage("tmp.json");
		UpdateConsoleScreen();

		GameLib::Collider::SetIsDebug(true);

	}

	void StageEditor::CustomizeUpdate()
	{
		ProcessMessage();
	}

	void StageEditor::UpdateConsoleScreen()
	{
		std::system("cls");

		//ステージ情報の表示

		std::cout << " Stage\n";
		for (auto iter = mSceneEditors.begin(); iter != mSceneEditors.end(); iter++) {
			std::cout << "  |- " << iter->first;
			if (iter->second == mNowSceneEditor)
				std::cout << "  <---Nooooow!!!";
			std::cout << "\n";
		}
		std::cout << "\n";

		
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
			bool helpFlag = false;
			//Sceneが一つもない場合、Actorを編集中じゃあない場合
			if (!mNowSceneEditor || !mNowSceneEditor->IsEdtingActor())
			{

				//
				if (strs.size() == 3 && strs[0] == "add" && strs[1] == "scene")
					AddScene(std::move(strs[2]));
				if (strs.size() == 3 && strs[0] == "remove" && strs[1] == "scene")
					RemoveScene(std::move(strs[2]));
				if (strs.size() == 3 && strs[0] == "change" && strs[1] == "scene")
					ChangeScene(std::move(strs[2]));

				if (strs.size() == 1 && mNowSceneEditor)
					mNowSceneEditor->CreateActor(std::move(strs[0]));

				if (strs.size() == 3 && strs[0] == "save" && strs[1] == "as")
					SaveStage("../Data/Stage/" + std::move(strs[2]) + ".json");
				if (strs.size() == 2 && strs[0] == "load")
					LoadStage("../Data/Stage/" + std::move(strs[1]) + ".json");

				if(strs.size()==1&&strs[0]=="save")
					SaveStage("tmp.json");
				if (strs.size() == 1 && strs[0] == "check")
					mCheckFlag = true;

				if (strs.size() == 1 && strs[0] == "help")
					helpFlag = true;
			}
			//編集中の場合はそのActorへ
			else if(mNowSceneEditor->IsEdtingActor()){
				for (auto& s : strs)
					mNowSceneEditor->ForwardStringData(std::move(s));
			}

			mConsoleMessage->ClearMessage();
			UpdateConsoleScreen();

			if (helpFlag)
				Help();

			if (mCheckFlag)
				std::system("cls");
			else
				mConsoleMessage->RunGetMessageThread();

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
		std::cout << "\n\ncommand list\n";
		std::cout << " add scene SCENE_NAME\n";
		std::cout << " remove scene SCENE_NAME\n";
		std::cout << " change scene SCENE_NAME\n";
		std::cout << " save as FILE_NAME\n";
		std::cout << " load FILE_NAME\n";
		std::cout << " save\n";
		std::cout << " check\n";


		auto names = GetAllActorEditorName();
		for (auto& name : names)
			std::cout << name << "\n";

		std::cout << "\n";
		std::cout << ">";
	}

	bool StageEditor::GetCheckFlag() const
	{
		return mCheckFlag;
	}
}