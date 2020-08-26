#include"CircleCurtain.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"Stage/WindowSize.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"

namespace Stage
{

	CircleCurtain::CircleCurtain()
		:GameLib::CustomizeDrawBase{}
		, mCircle{}
		, mRect{}
		, mStateFlag{0}
	{
		SetDrawOrder(100);

		mCircle.SetIsAutoDrawing(false);
		mRect.SetIsAutoDrawing(false);

		mCircle.SetRadius(MAX_RADIUS);

		mRect.SetWidthAndHeight(WindowSize::WIDTH*2.f, WindowSize::HEIGHT*2.f);
		mRect.SetPosition(GameLib::Viewport::GetPos());
		mRect.SetScale(1.f / GameLib::Viewport::GetScale());
		mRect.SetRotation(GameLib::Viewport::GetRotation());
	}

	void CircleCurtain::TurnDark(const GameLib::Vector2& pos)
	{
		mCircle.SetPosition(pos);
		mStateFlag = 1;
	}

	bool CircleCurtain::IsDark()
	{
		return mStateFlag == 2;
	}

	void CircleCurtain::TurnBright(const GameLib::Vector2& pos)
	{
		mCircle.SetPosition(pos);
		mStateFlag = 3;
	}

	bool CircleCurtain::IsBright()
	{
		return mStateFlag == 4;
	}

	void CircleCurtain::Update()
	{

		if (mStateFlag == 1) {
			float r = mCircle.GetRadius();
			r -= RADIUS_SPEED;
			if (r < 0.f) {
				r = 0.f;
				mStateFlag = 2;
			}
			mCircle.SetRadius(r);
		}

		if (mStateFlag == 3) {
			float r = mCircle.GetRadius();
			r += RADIUS_SPEED;
			if (r > MAX_RADIUS) {
				r = MAX_RADIUS;
				mStateFlag = 4;
			}
			mCircle.SetRadius(r);
		}
	

		float rot = GameLib::Viewport::GetRotation();
		auto center = GameLib::Viewport::GetPos();

		mRect.SetPosition(GameLib::Vector2::Rotation(center, rot));
		mRect.SetScale(1.f / GameLib::Viewport::GetScale());
		mRect.SetRotation(rot);
	}

	void CircleCurtain::Draw()
	{
		SetUpNotDrawRange();
		mCircle.Draw();

		SetUpStanderdDraw();
		mRect.Draw();
	}


}