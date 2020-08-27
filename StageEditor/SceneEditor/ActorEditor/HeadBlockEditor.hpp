#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"

namespace StageEditor
{
	class HeadBlockEditor : public ActorEditorBase
	{
		GameLib::DrawTexture mTexture;
		GameLib::DrawRect mRect;

	public:
		HeadBlockEditor(GameLib::Actor*);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;
	};
}