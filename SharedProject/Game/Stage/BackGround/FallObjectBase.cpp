#include"FallObjectBase.hpp"
#include"BackGroundAdjustPos.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"Game/Stage/Gravity.hpp"
#include"BackGroundAdjustPos.hpp"

namespace Game::Stage::BackGround
{


	//VirwPortÇÃïœçXÇë“Ç¬ÇΩÇﬂUpdateOrderÇÕëÂÇ´Ç¢
	FallObjectBase::FallObjectBase(GameLib::Actor* owner, std::string&& fileName, GameLib::Vector2&& startPos, float startRot, float scale, GameLib::Vector2&& deltaPos, float deltaRot, float moveRate,int drawOrder)
		:GameLib::Actor{owner,100}
		, mTexture{std::move(fileName)}
		, mPosition{std::move(startPos)}
		, mDeltaPos{std::move(deltaPos)}
		, mDeltaRot{deltaRot}
		, mMoveRate{moveRate}
	{
		mTexture.SetPosition(mPosition);
		mTexture.SetScale(scale);
		mTexture.SetRotation(startRot);
		mTexture.SetDrawOrder(drawOrder);
	}

	void FallObjectBase::CustomizeUpdate()
	{
		mPosition += Gravity::GetGravityVector2();
		mPosition += mDeltaPos;
		mPosition = AdjustPos(std::move(mPosition));

		mTexture.SetPosition(AdjustPos(mPosition, mMoveRate));
		mTexture.SetRotation(mTexture.GetRotation() + mDeltaRot);

	}

}