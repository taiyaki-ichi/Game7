#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"GameLib/include/Draw/DrawLine.hpp"

namespace StageEditor
{
	class StraightBeeEditor : public ActorEditorBase
	{
		GameLib::DrawTexture mBee;
		GameLib::DrawLine mLine;

	public:
		StraightBeeEditor(GameLib::Actor*);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;
	};

}