#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace StageEditor
{
	class TrampolineEditor : public ActorEditorBase
	{
		GameLib::DrawTexture mTexture;

	public:
		TrampolineEditor(GameLib::Actor*,std::string&&);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;
	};
}