#include"CircleCurtain.hpp"
#include"Game/Window.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"

#include<iostream>

namespace Game::Stage
{
	CircleCurtain::CircleCurtain(const GameLib::Vector2& nowPlayerPos, const GameLib::Vector2& nextPlayerPos)
		:CurtainBase{}
		, mRadius{800.f}
		, mRect{}
		, mCircle{}
		, mNowPlayerPos{nowPlayerPos}
		, mNextPlayerPos{nextPlayerPos}
		, mMode{0}
	{
		SetDrawOrder(100);
	
		mCircle.SetPosition(mNowPlayerPos);
		mCircle.SetRadius(mRadius);

		mRect.SetWidthAndHeight(WINDOW_WIDTH, WINDOW_HEIGHT);

		mCircle.SetIsAutoDrawing(false);
		mRect.SetIsAutoDrawing(false);
	}

	void CircleCurtain::Update()
	{
		if (mMode == 0) {
			mRadius -= 15.f;
			if (mRadius < 0.f)
				mRadius = 0.f;
		}
		else {
			mRadius += 15.f;
			if (mRadius > WINDOW_WIDTH)
				mRadius = WINDOW_WIDTH;
		}
	}
	bool CircleCurtain::IsClosed()
	{
		return mRadius <= 0.f;
	}
	void CircleCurtain::Open()
	{
		mMode = 1;
		mCircle.SetPosition(mNextPlayerPos);
	}
	bool CircleCurtain::IsOpened()
	{
		//std::cout << "mode: " << mMode << "\n";
		//std::cout << mRadius << "\n";
		return (mMode == 1 && mRadius > 500.f);
	}


	void CircleCurtain::Draw()
	{
		using namespace GameLib;


		mCircle.SetRadius(mRadius);

		SetUpNotDrawRange();
		mCircle.Draw();

		mRect.SetPosition(Viewport::GetPos());
		mRect.SetScale(1.f / Viewport::GetScale());
		mRect.SetRotation(Viewport::GetRotation());

		SetUpStanderdDraw();
		mRect.Draw();


	}
}