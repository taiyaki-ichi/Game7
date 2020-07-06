#include"ActorEditorBase.hpp"
#include"PosInfo/PosInfo.hpp"
#include"StageEditor/SceneEditor/SceneEditor.hpp"
#include"StageEditor/Utility/ClickManager.hpp"

#include<iostream>

namespace StageEditor
{
	const std::vector<PosInfo*>& ActorEditorBase::GetPosInfos()
	{
		return mPosInfos;
	}
	ActorEditorBase::ActorEditorBase(SceneEditor* owner, std::string&& nameTag, int posInfoNum)
		:GameLib::Actor{ owner }
		, mActorName{ std::move(nameTag) }
		, mPosInfos{}
		, mPosInfoNum{ posInfoNum }
		, mDefaultCollider{}
	{
		owner->AddActorEditor(this);
		mPosInfos.emplace_back(new PosInfo(this));

		mDefaultCollider.SetColor({ 0,255,0,255 });

		auto deleteFunc = [this](const GameLib::Collider c) {
			if (ClickManager::DoubleClicked())
				SetState(Actor::State::Dead);
		};
		
		mDefaultCollider.AddHitFunction("Cursor", std::move(deleteFunc));
		mDefaultCollider.Active();
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

	std::vector<float> ActorEditorBase::GetData()
	{
		std::vector<float> data{};
		for (auto iter = mPosInfos.begin(); iter != mPosInfos.end(); iter++) {
			data.emplace_back((*iter)->GetPosition().x);
			data.emplace_back((*iter)->GetPosition().y);
		}
		return data;
	}

	const std::string& ActorEditorBase::GetActorName() const noexcept
	{
		return mActorName;
	}

}