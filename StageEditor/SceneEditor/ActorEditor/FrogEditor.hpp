#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"GameLib/include/Draw/DrawLine.hpp"

namespace StageEditor
{
	class FrogEditor : public ActorEditorBase
	{
		GameLib::DrawLine mLine;
		GameLib::DrawTexture mTexture;

	public:
		FrogEditor(GameLib::Actor*);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;
	};
}