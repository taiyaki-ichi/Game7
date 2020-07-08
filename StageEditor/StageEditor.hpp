#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<unordered_map>
#include"SceneEditor/SceneEditor.hpp"

namespace StageEditor
{
	class SceneEditor;
	class Camera;

	class StageEditor : public GameLib::Actor
	{
		
		std::string mStageName;
		
		SceneEditor* mNowEditingScene;
		std::unordered_map<std::string, SceneEditor*> mStageScenes;

		Camera* mCamera;

		void DeleteScene(const std::string& sceneName);
		void ChangeScene(const std::string& sceneName);

		void PrintStageInfo();

	public:
		StageEditor(GameLib::Actor* owner);
		virtual ~StageEditor() = default;

		//セーブ、ロード、Sceneの追加削除、現在編集中のシーンの変更
		void CustomizeUpdate() override;

		SceneEditor* AddScene(const std::string& sceneName);
	};
}