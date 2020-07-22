#include"StageEditor.hpp"
#include"SceneEditor/SceneEditor.hpp"
#include"Console/ConsoleMessage.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"Utility/EditorCamera.hpp"
#include"Utility/ClickManager.hpp"
#include"Utility/Cursor.hpp"
#include"FileFunc.hpp"
#include"GameLib/include/CollisionDetection/CollisionDetectionSetting.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"Game/Window.hpp"
#include"Console/ConsoleMessage.hpp"
#include<fstream>
#include"StartActor.hpp"

namespace StageEditor
{

	StageEditor::StageEditor(GameLib::Actor* owner)
		:GameLib::Actor{owner}
		, mNowEditingScene{nullptr}
		,mStageScenes{}
		, mStageName{""}
		, mPlayerNum{0}
		, mReDrawFlag{false}
	{
		new ConsoleMessage{ this };

		mCamera = new EditorCamera(this);
		mCamera->Reset();
		new Cursor(this);
		new ClickManager(this);

		LoadStageData(this, "test.json");
		PrintStageInfo();

	}

	SceneEditor* StageEditor::AddScene(const std::string& sceneName)
	{
		auto ptr = new SceneEditor(this);
		mStageScenes.emplace(sceneName, ptr);
		if (mNowEditingScene == nullptr) {
			mNowEditingScene = mStageScenes.begin()->second;
			mNowEditingScene->Active();
		}

		return ptr;

	}

	void StageEditor::IncrementSumNum(const std::string& actorName)
	{
		if (actorName == "Player")
			mPlayerNum++;


		mReDrawFlag = true;
	}
	void StageEditor::DecrementSumNum(const std::string& actorName)
	{
		if (actorName == "Player")
			mPlayerNum--;

		mReDrawFlag = true;
	}
	void StageEditor::ResetSumNum()
	{
		mPlayerNum = 0;

		mReDrawFlag = true;

	}
	void StageEditor::ReDraw()
	{
		mReDrawFlag = true;
	}
	void StageEditor::DeleteScene(const std::string& sceneName)
	{
		auto i = mStageScenes.find(sceneName);
		if (i != mStageScenes.end()) {
			i->second->SetState(GameLib::Actor::State::Dead);
			auto ptr = i->second;
			mStageScenes.erase(i);

			if (ptr == mNowEditingScene) {
				if (mStageScenes.size() > 0) {
					mNowEditingScene = mStageScenes.begin()->second;
					mNowEditingScene->Active();
					mCamera->Reset();
				}
				else
					mNowEditingScene = nullptr;
			}	
		}
	}
	void StageEditor::ChangeScene(const std::string& sceneName)
	{
		auto i = mStageScenes.find(sceneName);
		if (i != mStageScenes.end() && !mNowEditingScene->IsNowEditingActor()) {
			mNowEditingScene->Pause();
			mNowEditingScene = i->second;
			mNowEditingScene->Active();
			mCamera->Reset();
		}
	}
	void StageEditor::PrintStageInfo()
	{
		std::system("cls");

		std::cout << "Stage\n";
		if (mStageName.size() == 0)
			std::cout << " Name: --- \n";
		else
			std::cout << " Name: " << mStageName << "\n";


		std::cout << " Scene:\n";
		for (auto iter = mStageScenes.begin(); iter != mStageScenes.end(); iter++) {
			std::cout << "  |- " << iter->first;
			if (iter->second == mNowEditingScene)
				std::cout << " <-Now!!!";
			std::cout << "\n";
		}
		std::cout << "\n";

		std::cout << "PlayerNum: " << mPlayerNum << "\n";

		std::cout << ">";
		
		if (mNowEditingScene)
			mNowEditingScene->PrintSceneInfo();
	}

	void StageEditor::CustomizeUpdate()
	{
		GameLib::CollisionDetectionSetting::SetPos(GameLib::Viewport::GetPos());
		float scale = GameLib::Viewport::GetScale();
		GameLib::CollisionDetectionSetting::SetWidth(Game::WINDOW_WIDTH *2.f/ scale);
		GameLib::CollisionDetectionSetting::SetHeight(Game::WINDOW_HEIGHT*2.f / scale);

		//std::cout << "w: " << GameLib::CollisionDetectionSetting::GetWidth() << "  h: " << GameLib::CollisionDetectionSetting::GetHeight() << "  ";
		//std::cout << "pos: " << GameLib::CollisionDetectionSetting::GetPos().x << "," << GameLib::CollisionDetectionSetting::GetPos().y << "\n";

		auto strings = ConsoleMessage::GetStrings();

		if (strings.size() == 3 && strings[1] == "scene") {
			if (strings[0] == "add")
				AddScene(strings[2]);
			else if (strings[0] == "change")
				ChangeScene(strings[2]);
			else if (strings[0] == "delete")
				DeleteScene(strings[2]);
		}

		if (strings.size() == 3 && strings[0] == "set" && strings[1] == "StageName")
			mStageName = strings[2];
			

		if (strings.size() > 0 || mReDrawFlag)
			PrintStageInfo();

		if (strings.size() == 1 && strings[0] == "save") {
			std::unordered_map<std::string, std::vector<ActorData>> tmp{};
			for (auto iter = mStageScenes.begin(); iter != mStageScenes.end(); iter++)
				tmp.emplace(iter->first, iter->second->GetData());
			SaveStageData(mStageName, std::move(tmp), "test.json");
		}

		if (strings.size() == 3 && strings[0] == "save" && strings[1] == "as") {
			std::unordered_map<std::string, std::vector<ActorData>> tmp{};
			for (auto iter = mStageScenes.begin(); iter != mStageScenes.end(); iter++)
				tmp.emplace(iter->first, iter->second->GetData());
			SaveStageData(mStageName, std::move(tmp), "../Data/Stage/" + strings[2] + ".json");
		}
		
		if (strings.size() == 2 && strings[0] == "load") {
			std::ifstream file{ "../Data/Stage/" + strings[1] + ".json" ,std::ios::in };
			if (file.is_open()) {

				std::ofstream testFile{ "test.json", std::ios::out };

				std::istreambuf_iterator<char> iit(file);
				std::istreambuf_iterator<char> end;
				std::ostreambuf_iterator<char> oit(testFile);
				std::copy(iit, end, oit);

				//SetState(GameLib::Actor::State::Dead);
				auto startActorPtr = static_cast<StartActor*>(mOwner);
				startActorPtr->UpdateStageEditor();
			}
		}
		
		mReDrawFlag = false;

		//float rot = GameLib::Viewport::GetRotation();
		//GameLib::Viewport::SetRotation(rot + 0.01f);

	}
}