#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace StageEditor
{
	class TogeEditor : public ActorEditorBase
	{
		GameLib::DrawTexture mTexture;

	public:
		TogeEditor(GameLib::Actor*);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;
	};
}