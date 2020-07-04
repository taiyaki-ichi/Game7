#include"ActorEditorBase.hpp"
#include"PosInfo/PosInfo.hpp"
#include"StageEditor/SceneEditor/SceneEditor.hpp"

namespace StageEditor
{
	ActorEditorBase::ActorEditorBase(SceneEditor* owner, std::string&& nameTag, int posInfoNum)
		:GameLib::Actor{ owner }
		, mActorName{ std::move(nameTag) }
		, mPosInfos{}
		, mPosInfoNum{ posInfoNum }
	{
		owner->AddActorEditor(this);
		mPosInfos.emplace_back(new PosInfo(this));
	}

	ActorEditorBase::~ActorEditorBase()
	{
		auto sceneEditor = static_cast<SceneEditor*>(mOwner);
		sceneEditor->RemoveActorEditor(this);
	}

	void ActorEditorBase::CustomizeUpdate()
	{
		if (mPosInfos.back()->IsOK() && mPosInfos.size() < mPosInfoNum)
			mPosInfos.emplace_back(new PosInfo(this));

		ActorEditorUpdate();
	}

	bool ActorEditorBase::IsOk()
	{
		return mPosInfoNum >= mPosInfos.size();
	}

	ActorData ActorEditorBase::GetDateObject()
	{
		std::unordered_map<std::string, float> data = {
			{"PosX",mPosInfos[0]->GetPosition().x},
			{"PosY",mPosInfos[0]->GetPosition().y}
		};
		return { mActorName,data };
	}
}