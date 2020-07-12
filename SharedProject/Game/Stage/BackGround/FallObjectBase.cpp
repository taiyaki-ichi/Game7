#include"FallObjectBase.hpp"
#include"BackGroundAdjustPos.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"Game/Stage/Gravity.hpp"
#include"BackGroundAdjustPos.hpp"

namespace Game::Stage::BackGround
{


	//VirwPortÇÃïœçXÇë“Ç¬ÇΩÇﬂUpdateOrderÇÕëÂÇ´Ç¢
	FallObjectBase::FallObjectBase(GameLib::Actor* owner, std::string&& fileName, GameLib::Vector2&& startPos, float startRot, float scale, GameLib::Vector2&& deltaPos, float deltaRot, float margin, float moveRateX, float moveRateY,int drawOrder)
		:GameLib::Actor{owner,100}
		, mTexture{std::move(fileName)}
		, mPosition{std::move(startPos)}
		, mDeltaPos{std::move(deltaPos)}
		, mDeltaRot{deltaRot}
		, mMoveRateX{moveRateX}
		, mMoveRateY{moveRateY}
		, mMargin{margin}
	{
		mTexture.SetPosition(AdjustPos(mPosition, mMargin, mMargin, mMoveRateX, mMoveRateY));
		mTexture.SetScale(scale);
		mTexture.SetRotation(startRot);
		mTexture.SetDrawOrder(drawOrder);
	}

	void FallObjectBase::CustomizeUpdate()
	{
		mPosition += Gravity::GetGravityVector2();
		mPosition += mDeltaPos;
		mPosition = AdjustPos(std::move(mPosition), mMargin, mMargin);

		mTexture.SetPosition(AdjustPos(mPosition, mMargin, mMargin, mMoveRateX, mMoveRateY));
		mTexture.SetRotation(mTexture.GetRotation() + mDeltaRot);

	}

}