#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace StageEditor
{
	class MaiEditor : public ActorEditorBase
	{
		GameLib::DrawTexture mTexture;

	public:
		MaiEditor(GameLib::Actor*,std::string&&);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;
	};
}