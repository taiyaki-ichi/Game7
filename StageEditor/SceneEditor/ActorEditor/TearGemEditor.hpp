#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace StageEditor
{
	class TearGemEditor : public ActorEditorBase
	{
		GameLib::DrawTexture mTexture;

		static std::vector<std::string> mNumbers;

	public:
		TearGemEditor(GameLib::Actor*);
		virtual ~TearGemEditor();

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void PrintStringDataInfo() override;

		static const std::vector<std::string>& GetNumbers();
		static void ResetNumbers();
	};
}