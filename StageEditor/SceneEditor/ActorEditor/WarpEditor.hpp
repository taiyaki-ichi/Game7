#pragma once
#include"ActorEditorBase.hpp"

namespace StageEditor
{
	class WarpEditor : public ActorEditorBase
	{
		std::string mThisWorpGateType;
		std::string mThisNameTag;
		std::string mDestinationNameTag;

	public:
		WarpEditor(SceneEditor* scene);
		virtual ~WarpEditor() = default;

		void ActorEditorUpdate() override;

		bool IsOK() override;

		void Active() override;
		void Pause() override;

		void PrintActorInfo() override;

		const std::string& GetWorpGateType() const noexcept;
		const std::string& GetNameTag()const noexcept;
		const std::string& GetDestinationNameGag()const noexcept;

		void SetStringInfo(std::string&& type, std::string&& nameTag, std::string&& destinationNameTag);
	};
}