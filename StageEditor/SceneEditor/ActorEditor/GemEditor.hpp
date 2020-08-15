#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace StageEditor
{
	class GemEditor : public ActorEditorBase
	{
		GameLib::DrawTexture mTexture;

		static int mCnt;

	public:
		GemEditor(GameLib::Actor*);
		virtual ~GemEditor();

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		static int GetNum();
	};
}