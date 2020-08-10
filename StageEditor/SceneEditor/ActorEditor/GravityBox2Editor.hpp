#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace StageEditor
{
	//2•ûŒü‚É‰ñ“]
	class GravityBox2Editor : public ActorEditorBase
	{
		GameLib::DrawTexture mBox;
		GameLib::DrawTexture mApple;

	public:
		GravityBox2Editor(GameLib::Actor*);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void PrintStringDataInfo() override;
		
	};
}