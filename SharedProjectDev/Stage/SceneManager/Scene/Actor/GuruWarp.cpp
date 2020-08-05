#include"GuruWarp.hpp"

namespace Stage
{
	GuruWarp::GuruWarp(GameLib::Actor* actor)
		:WarpBase{ actor }
		, mTexture{ "../Assets/Object/WarpGate/grugru.png" }
		, mCollder{}
		, mCnt{0}
	{
		mTexture.SetScale(0.1f);
		mCollder.SetWidthAndHeith(20.f, 20.f);
		mCollder.SetColor({ 0,255,0,255 });

		auto hitPlayer = [this](const GameLib::Collider& c) {
			if (mCnt == 0) {
				WarpPlayer();
				mCollder.Pause();
			}
		};
		mCollder.AddHitFunction("Player", std::move(hitPlayer));
	}

	void GuruWarp::Update()
	{
		if (mCnt > 0)
			mCnt--;
		mTexture.SetRotation(mTexture.GetRotation() + 0.03f);
	}

	void GuruWarp::BeginWorking()
	{
		mCollder.Active();
		mTexture.SetIsAutoDrawing(true);
	}

	void GuruWarp::BeginToRest()
	{
		mCollder.Pause();
		mTexture.SetIsAutoDrawing(false);
	}

	void GuruWarp::LoadData(std::vector<float>&& data)
	{
		auto pos = GameLib::Vector2{ data[0],data[1] };
		mTexture.SetPosition(pos);
		mCollder.SetPosition(std::move(pos));
	}

	void GuruWarp::PlayerWarpHere()
	{
		mCnt = WAIT_TIME;
	}

	const GameLib::Vector2& GuruWarp::GetPosition() const
	{
		return mTexture.GetPosition();
	}

}