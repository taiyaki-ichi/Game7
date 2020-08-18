#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace StageEditor
{
	class CarrotEditor : public ActorEditorBase
	{
		GameLib::DrawTexture mTexture;

	public:
		CarrotEditor(GameLib::Actor*);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;
	};
}