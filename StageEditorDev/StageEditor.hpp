#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<unordered_map>

namespace StageEditor
{
	class ConsoleMessage;
	class SceneEditor;

	class StageEditor : public GameLib::Actor
	{
		ConsoleMessage* mConsoleMessage;

		SceneEditor* mNowSceneEditor;
		std::unordered_map<std::string, SceneEditor*> mSceneEditors;



	public:
		StageEditor(GameLib::Actor* actor);
		virtual ~StageEditor() = default;

		void CustomizeUpdate() override;


		//SceneEditorを加える
		//LoadFuncでも使用
		SceneEditor* AddScene(std::string&&);

	private:
		//コンソールへの描写を更新、SceneEditorやActorEditorに伝播さす
		//Sceneの状態とActorの個数
		void UpdateConsoleScreen();

		//現在のデータをファイル名の場所に保存
		void SaveStage(std::string&&);

		//データをロード、test.jsonを更新
		void LoadStage(std::string&&);

		//コンソールからのメッセージの処理
		void ProcessMessage();

		//削除
		void RemoveScene(std::string&&);
		//現在表示されているSceneを変える
		void ChangeScene(std::string&&);

		//コマンド一覧の表示
		void Help();

	};

}