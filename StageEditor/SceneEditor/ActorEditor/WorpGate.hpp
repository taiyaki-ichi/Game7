#pragma once
#include"ActorEditorBase.hpp"

namespace StageEditor
{
	class WorpGate : public ActorEditorBase
	{
		std::string mThisNameTag;
		std::string mDestinationNameTag;

	public:
		WorpGate(SceneEditor* scene);
		virtual ~WorpGate() = default;

		void ActorEditorUpdate() override;

		bool IsOK() override;
	};
}