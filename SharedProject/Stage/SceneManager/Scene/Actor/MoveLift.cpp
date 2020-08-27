#include"MoveLift.hpp"
#include"MoveLift/MoveLiftParam.hpp"
#include"Lift/Lift.hpp"

namespace Stage
{
	MoveLift::MoveLift(GameLib::Actor* actor)
		:ActorBase{actor}
		, mLift{nullptr}
		, mP1{}
		, mP2{}
		, mVelocity{}
		, mLine{}
	{
		mLift = new Lift{ this };
	}

	void MoveLift::Update()
	{
		auto pos = mLift->GetPosition();
		pos += mVelocity;

		if ((mP1 - pos).Length() <= MoveLiftParam::SPEED/2.f)
		{
			pos = mP1;
			mVelocity = mP2 - mP1;
			mVelocity.Normalize();
			mVelocity *= MoveLiftParam::SPEED;
		}

		if ((mP2 - pos).Length() <= MoveLiftParam::SPEED/2.f)
		{
			pos = mP2;
			mVelocity = mP1 - mP2;
			mVelocity.Normalize();
			mVelocity *= MoveLiftParam::SPEED;
		}

		mLift->SetPosition(pos);
	}

	void MoveLift::BeginWorking()
	{
		mLift->BeginWorking();
		mLine.SetIsAutoDrawing(true);
	}

	void MoveLift::BeginToRest()
	{
		mLift->BeginToRest();
		mLine.SetIsAutoDrawing(false);
	}

	void MoveLift::LoadPosData(std::vector<GameLib::Vector2>&& data)
	{
		mP1 = data[0];
		mP2 = data[1];

		mLift->SetPosition(data[0]);

		mLine.SetPoints(data[0], data[1]);
	}
}