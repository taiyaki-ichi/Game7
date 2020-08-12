#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace StageEditor
{
	class GemEditor : public ActorEditorBase
	{
		GameLib::DrawTexture mTexture;

	public:
		GemEditor(GameLib::Actor*);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;
	};
}