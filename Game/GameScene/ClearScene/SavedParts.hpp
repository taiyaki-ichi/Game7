#pragma once
#include"ClearScenePartsBase.hpp"
#include"GameLib/include/Draw/DrawFontText.hpp"

namespace Game
{
	class SavedParts : public ClearScenePartsBase
	{
		GameLib::DrawFontText mSaved;

	public:
		SavedParts(GameLib::Actor*);

		void CustomizeUpdate() override;
	};
}