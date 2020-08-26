#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawCircle.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace StageEditor
{
	class CycleLiftEditor : public ActorEditorBase
	{
		GameLib::DrawCircle mCircle;
		GameLib::DrawTexture mLift1;
		GameLib::DrawTexture mLift2;
		GameLib::DrawTexture mLift3;
		GameLib::DrawTexture mLift4;

	public:
		CycleLiftEditor(GameLib::Actor*);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void PrintStringDataInfo() override;
	};
}