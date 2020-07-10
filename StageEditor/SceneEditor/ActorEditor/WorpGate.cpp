#pragma once
#include"WorpGate.hpp"

namespace StageEditor
{
	WorpGate::WorpGate(SceneEditor* scene)
		:ActorEditorBase{scene,"WorpGate",1}
		, mThisNameTag{""}
		, mDestinationNameTag{""}
	{
		mDefaultCollider.SetWidthAndHeith(50.f, 50.f);
	}
	void WorpGate::ActorEditorUpdate()
	{
		auto pos = GetPosInfos();
		mDefaultCollider.SetPosition(pos[0]->GetPosition());
	}
	bool WorpGate::IsOK()
	{
		auto pos = GetPosInfos();
		return (mThisNameTag.size() > 0) && (mDestinationNameTag.size() > 0) && 
			(GetPosInfoNum() >= pos.size()) && (pos.back()->IsOK());
	}
}