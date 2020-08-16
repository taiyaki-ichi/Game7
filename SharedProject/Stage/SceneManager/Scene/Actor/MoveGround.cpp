#include"MoveGround.hpp"
#include"MoveGround/MoveGroundParam.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"

namespace Stage
{
	MoveGround::MoveGround(GameLib::Actor* actor)
		:ActorBase{actor}
		, mCollider{"Ground"}
		, mRect{}
		, mLine{}
	{
		mRect.SetColor({ 50,50,50,255 });
		mLine.SetDrawOrder(-1);
	}

	void MoveGround::Update()
	{
		auto pos = mCollider.GetPosition();
		pos += mVelocity;

		if ((pos - mPos1).Length() <= MoveGroundParam::GROUND_SPEED/2.f)
		{
			pos = mPos1;
			mVelocity = mPos2 - mPos1;
			mVelocity.Normalize();
			mVelocity *= MoveGroundParam::GROUND_SPEED;
		}
		else if ((pos - mPos2).Length() <= MoveGroundParam::GROUND_SPEED/2.f)
		{
			pos = mPos2;
			mVelocity = mPos1 - mPos2;
			mVelocity.Normalize();
			mVelocity *= MoveGroundParam::GROUND_SPEED;
		}

		mCollider.SetPosition(pos);
		mRect.SetPosition(pos);
	}

	void MoveGround::BeginWorking()
	{
		mCollider.Active();
		mRect.SetIsAutoDrawing(true);
		mLine.SetIsAutoDrawing(true);
	}

	void MoveGround::BeginToRest()
	{
		mCollider.Pause();
		mRect.SetIsAutoDrawing(false);
		mLine.SetIsAutoDrawing(false);
	}

	void MoveGround::LoadPosData(std::vector<GameLib::Vector2>&& data)
	{
		float w = GameLib::GetDistanceX(data[0], data[1]);
		float h = GameLib::GetDistanceY(data[0], data[1]);
		auto c = GameLib::GetCenter(data[0], data[1]);

		mCollider.SetWidthAndHeith(w, h);
		mCollider.SetPosition(c);

		mRect.SetWidthAndHeight(w, h);
		mRect.SetPosition(c);

		mPos1 = c;
		mPos2 = data[2];

		mLine.SetPoints(std::move(c), std::move(data[2]));
	}
}