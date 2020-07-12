#include"SlideObjectBase.hpp"
#include"BackGroundAdjustPos.hpp"


namespace Game::Stage::BackGround
{
	SlideObjectBase::SlideObjectBase(GameLib::Actor* owner,std::string&& fileName,const GameLib::Vector2& pos, float scale, float marginX, float marginY,float moveRateX, float moveRateY,int drawOrder)
		:GameLib::Actor{owner,100}
		, mPosition{pos}
		, mMoveRateX{moveRateX}
		, mMoveRateY{moveRateY}
		, mTexture{std::move(fileName)}
		, mMarginX{marginX}
		, mMarginY{marginY}
	{
		mTexture.SetDrawOrder(drawOrder);
		mTexture.SetScale(scale);
		mTexture.SetPosition(AdjustPos(mPosition, mMarginX, mMarginY, mMoveRateX, mMoveRateY));
	}
	void SlideObjectBase::CustomizeUpdate()
	{
		mTexture.SetPosition(AdjustPos(mPosition, mMarginX, mMarginY, mMoveRateX, mMoveRateY));
	}
}