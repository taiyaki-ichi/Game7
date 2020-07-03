#pragma once
#include"GameLib/include/Draw/DrawFillCircle.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include"GameLib/src/Windows/Window.hpp"
#include"GameLib/src/Windows/Graphics.hpp"

namespace GameLib
{
	DrawFillCircle::DrawFillCircle(int drawOrder)
		:DrawBase{drawOrder}
		, mPosition{0.f,0.f}
		, mScale{1.f}
		, mRadius{0.f}
		, mColor{0,0,0,255}
	{
	}
	void DrawFillCircle::Draw()
	{
		float wHalf = GetWindowWidth() / 2.f;
		float hHalf = GetWindowHeigth() / 2.f;
		float viewSca = Viewport::GetScale();
		Vector2 affinedPos = Affine(mPosition, Viewport::GetPos(), 0.f, viewSca);

		GraphycsDrawFillCircle(affinedPos.x + wHalf, -affinedPos.y + hHalf, mRadius * mScale * viewSca, mColor.R, mColor.G, mColor.B, mColor.A);
	}
	void DrawFillCircle::SetPosition(const Vector2& pos)
	{
		mPosition = pos;
	}
	void DrawFillCircle::SetScale(float scale)
	{
		mScale = scale;
	}
	void DrawFillCircle::SetRadius(float radius)
	{
		mRadius = radius;
	}
	void DrawFillCircle::SetColor(Color&& color)
	{
		mColor = std::move(color);
	}
	const Vector2& DrawFillCircle::GetPosition() const noexcept
	{
		return mPosition;
	}
	float DrawFillCircle::GetScale() const noexcept
	{
		return mScale;
	}
	float DrawFillCircle::GetRadius() const noexcept
	{
		return mRadius;
	}
}