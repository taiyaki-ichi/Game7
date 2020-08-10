#include"GameLib/include/Draw/DrawFillTriangle.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include"GameLib/src/Windows/Graphics.hpp"
#include"GameLib/src/Windows/Window.hpp"
#include<utility>

namespace GameLib
{
	DrawFillTriangle::DrawFillTriangle(const Vector2& p1, const Vector2& p2, const Vector2& p3, Color&& color, int drawOrder)
		:DrawBase(drawOrder)
		,mPoint1(p1)
		,mPoint2(p2)
		,mPoint3(p3)
		,mColor(std::move(color))
	{
		if (Vector2::Cross(mPoint2 - mPoint1, mPoint3 - mPoint1))
			std::swap(mPoint2, mPoint3);
	}

	void DrawFillTriangle::Draw()
	{
		float wHalf = GetWindowWidth() / 2.f;
		float hHalf = GetWindowHeigth() / 2.f;
		Vector2 affinedPos1 = Affine(mPoint1, Viewport::GetPos(), -Viewport::GetRotation(), Viewport::GetScale());
		Vector2 affinedPos2 = Affine(mPoint2, Viewport::GetPos(), -Viewport::GetRotation(), Viewport::GetScale());
		Vector2 affinedPos3 = Affine(mPoint3, Viewport::GetPos(), -Viewport::GetRotation(), Viewport::GetScale());
		Vector2 pos1 = { affinedPos1.x + wHalf,-affinedPos1.y + hHalf };
		Vector2 pos2 = { affinedPos2.x + wHalf,-affinedPos2.y + hHalf };
		Vector2 pos3 = { affinedPos3.x + wHalf,-affinedPos3.y + hHalf };
		GraphicsDrawFillTriangle(pos1.x, pos1.y, pos2.x, pos2.y, pos3.x, pos3.y, mColor.R, mColor.G, mColor.B, mColor.A);
	}

	void DrawFillTriangle::SetPoints(const Vector2& p1, const Vector2& p2, const Vector2& p3)
	{
		mPoint1 = p1;
		mPoint2 = p2;
		mPoint3 = p3;
		if (Vector2::Cross(mPoint2 - mPoint1, mPoint3 - mPoint1))
			std::swap(mPoint2, mPoint3);
	}
}