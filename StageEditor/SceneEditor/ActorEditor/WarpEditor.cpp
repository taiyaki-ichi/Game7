#pragma once
#include"WarpEditor.hpp"
#include"StageEditor/Console/ConsoleMessage.hpp"

namespace StageEditor
{
	WarpEditor::WarpEditor(SceneEditor* scene)
		:ActorEditorBase{scene,"Warp",1}
		, mThisNameTag{""}
		, mDestinationNameTag{""}
		, mThisWorpGateType{""}
	{
		mDefaultCollider.SetWidthAndHeith(50.f, 50.f);
	}
	void WarpEditor::ActorEditorUpdate()
	{
		auto pos = GetPosInfos();
		mDefaultCollider.ResetPosition(pos[0]->GetPosition());

		auto str = ConsoleMessage::GetStrings();
		if (str.size() > 0.f) {
			if (mThisWorpGateType == "")
				mThisWorpGateType = str[0];
			else if (mThisNameTag == "")
				mThisNameTag = str[0];
			else if (mDestinationNameTag == "")
				mDestinationNameTag = str[0];
		}

	}
	bool WarpEditor::IsOK()
	{
		auto pos = GetPosInfos();
		return (mThisNameTag.size() > 0) && (mDestinationNameTag.size() > 0) && 
			(GetPosInfoNum() >= pos.size()) && (pos.back()->IsOK());
	}
	void WarpEditor::Active()
	{
		mDefaultCollider.Active();
	}
	void WarpEditor::Pause()
	{
		mDefaultCollider.Pause();
	}

	void WarpEditor::PrintActorInfo()
	{
		if (mThisWorpGateType == "") {
			std::cout << "This Warp Type: ";
		}
		else if (mThisNameTag == "") {
			std::cout << "This Warp Type: " << mThisWorpGateType << "\n";
			std::cout << "This NameTag: ";
		}
		else if(mDestinationNameTag==""){
			std::cout << "This Warp Type: " << mThisWorpGateType << "\n";
			std::cout << "This NameTag: " << mThisNameTag << "\n";
			std::cout << "Destination NameTag: ";
		}
		else {
			std::cout << "This Warp Type: " << mThisWorpGateType << "\n";
			std::cout << "This NameTag: " << mThisNameTag << "\n";
			std::cout << "Destination NameTag: " << mDestinationNameTag << "\n";
		}
	}
	const std::string& WarpEditor::GetWorpGateType() const noexcept
	{
		return mThisWorpGateType;
	}
	const std::string& WarpEditor::GetNameTag() const noexcept
	{
		return mThisNameTag;
	}
	const std::string& WarpEditor::GetDestinationNameGag() const noexcept
	{
		return mDestinationNameTag;
	}
	void WarpEditor::SetStringInfo(std::string&& type, std::string&& nameTag, std::string&& destinationNameTag)
	{
		mThisWorpGateType = std::move(type);
		mThisNameTag = std::move(nameTag);
		mDestinationNameTag = std::move(destinationNameTag);

	}
}