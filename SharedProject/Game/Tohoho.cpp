#include"Tohoho.hpp"
#include"GameLib/include/Math/Numbers.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
namespace Game
{
	Tohoho::Tohoho()
		:CustomizeDrawBase(100)
		, mRadius{100.f}
		, mRect{100}
		, mCircle{100}
	{
		using namespace GameLib;

		mRect.Set(Vector2{ 0.f,0.f }, 1.f, 0.f);
		mRect.SetWidthAndHeight(800.f, 600.f);
		mRect.SetIsAutoDrawing(false);

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

		mRect.SetPosition(Viewport::GetPos());
		mRect.SetScale(1.f/Viewport::GetScale());

		SetUpStanderdDraw();
		mRect.Draw();
	}
}