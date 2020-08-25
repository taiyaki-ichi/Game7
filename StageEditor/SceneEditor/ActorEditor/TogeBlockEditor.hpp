#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace StageEditor
{
	class TogeBlockEditor : public ActorEditorBase
	{
		GameLib::DrawTexture mTexture;

	public:
		TogeBlockEditor(GameLib::Actor*);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;
	};
}