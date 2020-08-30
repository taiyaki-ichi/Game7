#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace StageEditor
{
	class StandEditor : public ActorEditorBase
	{
		GameLib::DrawTexture mTexture;

	public:
		StandEditor(GameLib::Actor*, std::string&&);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;
	};
}