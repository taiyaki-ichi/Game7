#pragma once
#include"GameLib/include/Actor/Actor.hpp"

namespace StageEditor
{
	class ConsoleMessage;

	class StageEditor : public GameLib::Actor
	{
		//Actorを編集中かどうか
		//編集中ならSceneは変更させない、MessageはActorに送る
		bool mIsEditingActor;

		ConsoleMessage* mConsoleMessage;

	public:
		StageEditor(GameLib::Actor* actor);
		virtual ~StageEditor() = default;

		void CustomizeUpdate() override;

	private:


		//コンソールへの描写を更新、SceneEditorやActorEditorに伝播さす,ostreamを渡す？
		void UpdateConsoleScreen();

		//現在のデータをファイル名の場所に保存
		void SaveStage(std::string);

		//データをロード、test.jsonを更新
		void LoadStage(std::string);

		//コンソールからのメッセージの処理
		void ProcessMessage();


		//SceneEditorを加える
		void AddScene(std::string);
		//削除
		void RemoveScene(std::string);
		//現在表示されているSceneを変える
		void ChangeScene(std::string);



	};

}