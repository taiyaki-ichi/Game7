#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"


namespace Game::Stage::BackGround
{
	class SlideObjectBase : public GameLib::Actor
	{
		GameLib::Vector2 mPosition;

		float mMarginX;
		float mMarginY;

		float mMoveRateX;
		float mMoveRateY;

		GameLib::DrawTexture mTexture;

	public:
		SlideObjectBase(GameLib::Actor* owner, std::string&& fileName,const GameLib::Vector2& pos,float scale, float marginX,float marginY,float moveRateX, float moveRateY,int drawOrder);
		virtual ~SlideObjectBase() = default;

		void CustomizeUpdate() override;
	};
}