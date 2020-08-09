#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace StageEditor
{

	//4•ûŒü‚É‰ñ“]
	class GravityBox4Editor : public ActorEditorBase
	{
		GameLib::DrawTexture mBox;
		GameLib::DrawTexture mApple;

	public:
		GravityBox4Editor(GameLib::Actor*);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void PrintStringDataInfo() override;
	};
}