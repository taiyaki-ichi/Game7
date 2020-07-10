#pragma once
#include"WorpGateEditor.hpp"
#include"StageEditor/Console/ConsoleMessage.hpp"

namespace StageEditor
{
	WorpGateEditor::WorpGateEditor(SceneEditor* scene)
		:ActorEditorBase{scene,"WorpGate",1}
		, mThisNameTag{""}
		, mDestinationNameTag{""}
		, mThisWorpGateType{""}
	{
		mDefaultCollider.SetWidthAndHeith(50.f, 50.f);
		std::cout << "This NameTag: ";
	}
	void WorpGateEditor::ActorEditorUpdate()
	{
		auto pos = GetPosInfos();
		mDefaultCollider.SetPosition(pos[0]->GetPosition());

		auto str = ConsoleMessage::GetStrings();
		if (str.size() > 0.f) {
			if (mThisWorpGateType == "")
				mThisWorpGateType = str[0];
			else if (mThisNameTag == "")
				mThisNameTag = str[0];
			else
				mDestinationNameTag = str[0];
		}

	}
	bool WorpGateEditor::IsOK()
	{
		auto pos = GetPosInfos();
		return (mThisNameTag.size() > 0) && (mDestinationNameTag.size() > 0) && 
			(GetPosInfoNum() >= pos.size()) && (pos.back()->IsOK());
	}
	void WorpGateEditor::Active()
	{
		mDefaultCollider.Active();
	}
	void WorpGateEditor::Pause()
	{
		mDefaultCollider.Pause();
	}

	void WorpGateEditor::PrintActorInfo()
	{
		if (mThisWorpGateType == "") {
			std::cout << "This WorpGate Type: ";
		}
		else if (mThisNameTag == "") {
			std::cout << "This WorpGate Type: " << mThisWorpGateType << "\n";
			std::cout << "This NameTag: ";
		}
		else if(mDestinationNameTag==""){
			std::cout << "This WorpGate Type: " << mThisWorpGateType << "\n";
			std::cout << "This NameTag: " << mThisNameTag << "\n";
			std::cout << "Destination NameTag: ";
		}
		else {
			std::cout << "This WorpGate Type: " << mThisWorpGateType << "\n";
			std::cout << "This NameTag: " << mThisNameTag << "\n";
			std::cout << "Destination NameTag: " << mDestinationNameTag << "\n";
		}
	}
	const std::string& WorpGateEditor::GetWorpGateType() const noexcept
	{
		return mThisWorpGateType;
	}
	const std::string& WorpGateEditor::GetNameTag() const noexcept
	{
		return mThisNameTag;
	}
	const std::string& WorpGateEditor::GetDestinationNameGag() const noexcept
	{
		return mDestinationNameTag;
	}
	void WorpGateEditor::SetStringInfo(std::string&& type, std::string&& nameTag, std::string&& destinationNameTag)
	{
		mThisWorpGateType = std::move(type);
		mThisNameTag = std::move(nameTag);
		mDestinationNameTag = std::move(destinationNameTag);

	}
}