#include"CycleLift.hpp"
#include"CycleLift/CycleLiftParam.hpp"
#include"Lift/Lift.hpp"

namespace Stage
{
	CycleLift::CycleLift(GameLib::Actor* actor)
		:ActorBase{actor}
		, mLift{}
		, mCircle{}
		, mIsClockwise{true}
		, mCnt{0}
	{
		mCircle.SetRadius(CycleLiftParam::CENTER_RADIUS);

		for (int i = 0; i < CycleLiftParam::LIFT_NUM; i++)
			mLift.emplace_back(new Lift{ this });
		
	}

	void CycleLift::Update()
	{
		using namespace CycleLiftParam;
		auto center = mCircle.GetPosition();
		float dir = (mIsClockwise) ? -1.f : 1.f;
		GameLib::Vector2 adjust{ RADIUS,0.f };
		for (int i = 0; i < LIFT_NUM; i++)
		{
			auto vec = GameLib::Vector2::Rotation(adjust, i * GameLib::PI * 2.f / static_cast<float>(LIFT_NUM) + mCnt * ROT_PER_FLAME * dir);
			mLift[i]->SetPosition(center + vec);
		}

		mCnt++;
	}

	void CycleLift::BeginWorking()
	{
		mCircle.SetIsAutoDrawing(true);
		for (auto ptr : mLift)
			ptr->BeginWorking();
	}

	void CycleLift::BeginToRest()
	{
		mCircle.SetIsAutoDrawing(false);
		for (auto ptr : mLift)
			ptr->BeginToRest();
	}

	void CycleLift::LoadPosData(std::vector<GameLib::Vector2>&& data)
	{
		mCircle.SetPosition(data[0]);
	}

	void CycleLift::LoadStringData(std::vector<std::string>&& data)
	{
		if (data[0] == "false")
			mIsClockwise = false;
	}
}