#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"GameLib/include/Draw/DrawCircle.hpp"

namespace StageEditor
{
	class CircleBeeEditor : public ActorEditorBase
	{
		GameLib::DrawTexture mBee;
		GameLib::DrawCircle mCircle;

	public:
		CircleBeeEditor(GameLib::Actor*);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

	};
}