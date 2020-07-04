#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<unordered_map>

namespace StageEditor
{
	class ActorEditorBase;
	struct ActorData;

	class SceneEditor : public GameLib::Actor
	{

		//現在編集中のActorがあるかどうかの判定に使用
		ActorEditorBase* mNowEditingActor;
		//ActorEditorへの参照
		std::vector<ActorEditorBase*> mActorEditors;

	public:
		SceneEditor(GameLib::Actor* owenr);
		virtual ~SceneEditor() = default;

		//ActorEditorの作製
		void CustomizeUpdate() override;

		//ActorEditorBase内で使用
		void AddActorEditor(ActorEditorBase* actor);
		void RemoveActorEditor(ActorEditorBase* actor);

		std::vector<ActorData> GetActorDataObject();

		void Active();
		void Pause();

		//現在Actorを編集中かどうか
		bool IsNowEditingActor();
	};
}