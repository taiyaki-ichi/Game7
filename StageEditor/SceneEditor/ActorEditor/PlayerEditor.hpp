#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace StageEditor
{
	class PlayerEditor : public ActorEditorBase
	{
		GameLib::DrawTexture mTexture;

		static int mCnt;

	public:
		PlayerEditor(GameLib::Actor*);
		virtual ~PlayerEditor();
		
		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		static int GetNum();
	};
}