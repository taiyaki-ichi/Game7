#include"Tohoho.hpp"
#include"GameLib/include/Math/Numbers.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
namespace Game
{
	Tohoho::Tohoho()
		:CustomizeDrawBase(100)
		, mRadius{100.f}
		, mRect{100}
	{
		using namespace GameLib;

		for (int i = 0; i < TRIANGLE_NUM; i++) {
			auto t = DrawFillTriangle{};
			t.SetIsAutoDrawing(false);
			mTriangles.emplace_back(std::move(t));
		}

		mRect.Set(Vector2{ 0.f,0.f }, 1.f, 0.f);
		mRect.SetWidthAndHeight(800.f, 600.f);
		mRect.SetIsAutoDrawing(false);

	}
	void Tohoho::Draw()
	{
		using namespace GameLib;

		float num = static_cast<float>(TRIANGLE_NUM);

		float scale = Viewport::GetScale();
		Vector2 center = Viewport::GetPos();
		Vector2 p1{ mRadius * std::cos(PI * 2.f / num) * scale + center.x,mRadius * std::sin(PI * 2.f / num) * scale + center.y };
		Vector2 p2;

		for (int i = 0; i < TRIANGLE_NUM; i++) {
			p2 = p1;
			p1 = Vector2{ mRadius * std::cos(-PI * 2.f / num * i) * scale + center.x,mRadius * std::sin(-PI * 2.f / num * i) * scale + center.y };
			mTriangles[i].SetPoints(center, p1, p2);
		}

		//ResetDrawRangeZero();
		//SetUpAndDrawRange();

		SetUpNotDrawRange();
		for (int i = 0; i < TRIANGLE_NUM; i++)
			mTriangles[i].Draw();

		mRect.SetPosition(Viewport::GetPos());
		mRect.SetScale(1.f/Viewport::GetScale());

		SetUpStanderdDraw();
		mRect.Draw();
	}
}