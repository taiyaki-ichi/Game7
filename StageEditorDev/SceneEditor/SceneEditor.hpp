#pragma once
#include"GameLib/include/Actor/Actor.hpp"

namespace StageEditor
{
	class SceneEditor : public GameLib::Actor
	{

	public:
		SceneEditor(GameLib::Actor* actor);
		virtual ~SceneEditor() = default;


		//Actorの生成
		void CreateActor(std::string&&);

		//Actorを編集中かどうか
		bool IsEdtingActor();

		//編集中の時にActorに文字列の情報を渡す
		void MessageToActor(std::string&&);

		//Invoke使う
		void BeginWorking();
		void BeginToRest();

		//編集中のActorの情報の表示
		void UpdateConsoleScreen();
	};

}