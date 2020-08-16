#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"HexVec.hpp"

namespace Game
{
	class ChoiceIcon : public GameLib::Actor
	{
		GameLib::DrawTexture mTexture;

		HexVec mPos;
		int mCnt;

	public:
		ChoiceIcon(GameLib::Actor*);

		void CustomizeUpdate() override;

		void SetPosision(const HexVec&);
		const HexVec& GetPosition() const;
	};

}