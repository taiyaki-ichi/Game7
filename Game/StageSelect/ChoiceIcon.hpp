#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"PairVec.hpp"

namespace Game
{
	class ChoiceIcon : public GameLib::Actor
	{
		GameLib::DrawTexture mTexture;

		PairVec mPairPos;
		int mCnt;

	public:
		ChoiceIcon(GameLib::Actor*);

		void CustomizeUpdate() override;

		void SetPosision(const PairVec&);
		const PairVec& GetPosition() const;
	};

}