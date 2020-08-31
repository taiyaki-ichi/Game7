#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace Stage
{
	class Kakko : public GameLib::Actor
	{
		GameLib::Vector2 mPosition;

		float mWidth;
		float mHeight;

		int mCnt;

		GameLib::DrawTexture mTexture1;
		GameLib::DrawTexture mTexture2;
		GameLib::DrawTexture mTexture3;
		GameLib::DrawTexture mTexture4;

		float mMoveLength;

	public:
		Kakko(GameLib::Actor*);

		void CustomizeUpdate() override;

		void SetWidthAndHeight(float, float);
		void SetPosition(const GameLib::Vector2&);

		void SetTextureScale(float);
		void SetMoveLength(float);
	};
}