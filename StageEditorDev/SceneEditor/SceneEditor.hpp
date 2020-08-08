#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"BeginPolicy.hpp"
#include"ActorEditor/ActorData.hpp"
#include"ActorEditor/ActorEditorBase.hpp"

namespace StageEditor
{
	class ActorEditorBase;

	class SceneEditor : public GameLib::Actor
	{
		ActorEditorBase* mNowActorEditor;

	public:
		SceneEditor(GameLib::Actor* actor);
		virtual ~SceneEditor() = default;

		void CustomizeUpdate() override;

		//Actorの生成
		void CreateActor(std::string&&);

		//Actorを編集中かどうか
		bool IsEdtingActor();

		//編集中の時にActorに文字列の情報を渡す
		void ForwardStringData(std::string&&);

		//Invoke使う
		void BeginWorking() {
			InvokeActors<BeginWorkingPolicy>();
		}
		void BeginToRest() {
			InvokeActors<BeginToRestPolicy>();
		}

		//編集中のActorの情報の表示
		void UpdateConsoleScreen();

		std::vector<ActorData> GetData()
		{
			std::vector<ActorData> data{};
			auto func = [&data](GameLib::Actor* actor) {
				auto ptr = static_cast<ActorEditorBase*>(actor);
				data.emplace_back(ptr->GetData()); 
			};
			mOwnedActors.For_Each(func);

			return data;
		}

	};

}