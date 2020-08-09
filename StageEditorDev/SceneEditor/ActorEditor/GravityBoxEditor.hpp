#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace StageEditor
{
	class GravityBoxEditor : public ActorEditorBase
	{
		GameLib::DrawTexture mTexture4;
		GameLib::DrawTexture mTexture2;

		GameLib::DrawTexture mApple;
	public:
		GravityBoxEditor(GameLib::Actor*);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void PrintStringDataInfo() override;

	};
}