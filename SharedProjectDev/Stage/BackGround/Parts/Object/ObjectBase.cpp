#include"ObjectBase.hpp"
#include"ObjectAdjustPos.hpp"

namespace Stage::BackGround
{
	ObjectBase::ObjectBase(GameLib::Actor* owner, std::string&& fileName, int drawOrder)
		:GameLib::Actor{ owner,100 }
		, mPosition{  }
		, mMoveRateX{ }
		, mMoveRateY{  }
		, mTexture{ std::move(fileName) }
		, mMarginX{  }
		, mMarginY{  }
	{
		mTexture.SetDrawOrder(drawOrder);
		mTexture.SetPosition(AdjustPos(mPosition, mMarginX, mMarginY, mMoveRateX, mMoveRateY));
	}
	void ObjectBase::CustomizeUpdate()
	{
		mTexture.SetPosition(AdjustPos(mPosition, mMarginX, mMarginY, mMoveRateX, mMoveRateY));
	}
	void ObjectBase::SetPosition(const GameLib::Vector2& pos)
	{
		mPosition = pos;
	}
	const GameLib::Vector2& ObjectBase::GetPosition() const
	{
		return mPosition;
	}

	void ObjectBase::SetScale(float s)
	{
		mTexture.SetScale(s);
	}

	void ObjectBase::SetMarginXY(float x, float y)
	{
		mMarginX = x;
		mMarginY = y;
	}

	void ObjectBase::SetMoveRateXY(float x, float y)
	{
		mMoveRateX = x;
		mMoveRateY = y;
	}

}