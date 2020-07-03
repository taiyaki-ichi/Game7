#include"Tohoho.hpp"
#include"GameLib/include/Math/Numbers.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
namespace Game
{
	Tohoho::Tohoho()
		:CustomizeDrawBase(100)
		, mRadius{100.f}
		, mDrawRect{100}
		, mCircle{100}
	{
		using namespace GameLib;

		mDrawRect.Set(Vector2{ 0.f,0.f }, 1.f, 0.f);
		mDrawRect.SetWidthAndHeight(800.f, 600.f);
		mDrawRect.SetIsAutoDrawing(false);

		mCircle.SetRadius(100.f);
		mCircle.SetPosition(Vector2{ 0.f,0.f });
		mCircle.SetIsAutoDrawing(false);

	}
	void Tohoho::Draw()
	{
		using namespace GameLib;

		//ResetDrawRangeZero();
		//SetUpAndDrawRange();

		SetUpNotDrawRange();
		mCircle.SetPosition(Viewport::GetPos());
		mCircle.Draw();

		mDrawRect.SetPosition(Viewport::GetPos());
		mDrawRect.SetScale(1.f/Viewport::GetScale());

		SetUpStanderdDraw();
		mDrawRect.Draw();
	}
}