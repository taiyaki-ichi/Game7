#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace StageEditor
{
	class GuruWarpEditor : public ActorEditorBase
	{
		GameLib::DrawTexture mTexture;

	public:
		GuruWarpEditor(GameLib::Actor*);

		void Update() override;
		
		void BeginWorking() override;
		void BeginToRest() override;

		void PrintStringDataInfo() override;
	};

}