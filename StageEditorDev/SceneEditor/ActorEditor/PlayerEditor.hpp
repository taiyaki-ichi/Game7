#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace StageEditor
{
	class PlayerEditor : public ActorEditorBase
	{
		GameLib::DrawTexture mTexture;

	public:
		PlayerEditor(GameLib::Actor*);
		
		void Update() override {};

		void BeginWorking() override {};
		void BeginToRest() override {};
	};
}