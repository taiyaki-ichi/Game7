#include"GameLib/include/Draw/DrawLine.hpp"
#include<utility>
#include"GameLib/include/Math/Vector2Func.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"GameLib/src/Windows/Window.hpp"
#include"GameLib/src/Windows/Graphics.hpp"
#include"Manager/DrawManager.hpp"



namespace GameLib
{

	DrawLine::DrawLine(const Vector2& p1, const Vector2& p2, const Color& color, int drawOrder)
		:DrawBase(drawOrder)
		, mPoint1(p1)
		, mPoint2(p2)
		, mColor(color)
	{
	}

	DrawLine::~DrawLine()
	{
	}

	void DrawLine::Draw()
	{
		Vector2 affinedPos1 = Affine(mPoint1, Viewport::GetPos(), Viewport::GetRotation(), Viewport::GetScale());
		Vector2 affinedPos2 = Affine(mPoint2, Viewport::GetPos(), Viewport::GetRotation(), Viewport::GetScale());
		Vector2 pos1 = { affinedPos1.x + GetWindowWidth() / 2.f,-affinedPos1.y + GetWindowHeigth() / 2.f };
		Vector2 pos2 = { affinedPos2.x + GetWindowWidth() / 2.f,-affinedPos2.y + GetWindowHeigth() / 2.f };
		GraphicsDrawLine(pos1.x, pos1.y, pos2.x, pos2.y, mColor.R, mColor.G, mColor.B, mColor.A);
	}
	void DrawLine::SetPoints(const Vector2& p1, const Vector2& p2)
	{
		mPoint1 = p1;
		mPoint2 = p2;
	}
	void DrawLine::SetPoints(Vector2&& p1, Vector2&& p2)
	{
		mPoint1 = std::move(p1);
		mPoint2 = std::move(p2);
	}
	void DrawLine::SetColor(Color&& color)
	{
		mColor = std::move(color);
	}
	void DrawLine::SetColor(const Color& color)
	{
		mColor = color;
	}
}