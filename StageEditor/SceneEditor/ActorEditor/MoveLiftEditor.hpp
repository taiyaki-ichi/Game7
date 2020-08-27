#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"GameLib/include/Draw/DrawLine.hpp"

namespace StageEditor
{
	class MoveLiftEditor : public ActorEditorBase
	{
		GameLib::DrawTexture mTexture;
		GameLib::DrawLine mLine;

	public:
		MoveLiftEditor(GameLib::Actor*);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;
	};
}