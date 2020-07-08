#include"ActorEditorBase.hpp"
#include"PosInfo/PosInfo.hpp"
#include"StageEditor/SceneEditor/SceneEditor.hpp"
#include"StageEditor/Utility/ClickManager.hpp"
#include"StageEditor/StageEditor.hpp"

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

		auto stageEditorPtr = static_cast<StageEditor*>(mOwner->GetOwner());
		stageEditorPtr->IncrementSumNum(mActorName);
	}

	ActorEditorBase::~ActorEditorBase()
	{
		auto sceneEditor = static_cast<SceneEditor*>(mOwner);
		sceneEditor->RemoveActorEditor(this);

		auto stageEditorPtr = static_cast<StageEditor*>(mOwner->GetOwner());
		stageEditorPtr->DecrementSumNum(mActorName);
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

	ActorData ActorEditorBase::GetData()
	{
		std::vector<float> data{};
		for (auto iter = mPosInfos.begin(); iter != mPosInfos.end(); iter++) {
			data.emplace_back((*iter)->GetPosition().x);
			data.emplace_back((*iter)->GetPosition().y);
		}
		return { mActorName,data };
	}


	void ActorEditorBase::SetData(std::vector<float>&& data)
	{
		if (data.size() / 2 == mPosInfoNum) {
			mPosInfos.clear();
			for (int i = 0; i < mPosInfoNum; i++) {
				GameLib::Vector2 vec{ data[i * 2],data[i * 2 + 1] };
				auto posInfo = new PosInfo(this, std::move(vec));
				mPosInfos.emplace_back(posInfo);
			}
		}
		else
			SetState(GameLib::Actor::State::Dead);
	}

}