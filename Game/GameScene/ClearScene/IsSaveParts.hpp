#pragma once
#include"ClearScenePartsBase.hpp"
#include"Stage/Utilty/Button.hpp"
#include"GameLib/include/Draw/DrawFontText.hpp"

namespace Stage
{
	class Kakko;
}

namespace Game
{
	class IsSaveParts : public ClearScenePartsBase
	{
		Stage::Button mButtonA;
		Stage::Button mButtonD;

		Stage::Kakko* mKakko;

		GameLib::DrawFontText mIsSave;
		GameLib::DrawFontText mHai;
		GameLib::DrawFontText mIie;

		GameLib::DrawFontText mA;
		GameLib::DrawFontText mD;

		enum class Position
		{
			A,
			D
		};
		Position mPosition;

	public:
		IsSaveParts(GameLib::Actor*);

		void CustomizeUpdate() override;
	};
}