#pragma once
#include"GameLib/include/Draw/DrawCircle.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include"GameLib/src/Windows/Window.hpp"
#include"GameLib/src/Windows/Graphics.hpp"

namespace GameLib
{
	DrawCircle::DrawCircle(int drawOrder)
		:DrawBase{drawOrder}
		, mPosition{0.f,0.f}
		, mScale{1.f}
		, mRadius{0.f}
		, mColor{0,0,0,255}
		, mIsFill{true}
	{
	}
	void DrawCircle::Draw()
	{
		float wHalf = GetWindowWidth() / 2.f;
		float hHalf = GetWindowHeigth() / 2.f;
		float viewSca = Viewport::GetScale();
		Vector2 affinedPos = Affine(mPosition, Viewport::GetPos(), 0.f, viewSca);

		GraphycsDrawCircle(affinedPos.x + wHalf, -affinedPos.y + hHalf, mRadius * mScale * viewSca, mColor.R, mColor.G, mColor.B, mColor.A, mIsFill);
	}
	void DrawCircle::ResetPosition(const Vector2& pos)
	{
		mPosition = pos;
	}
	void DrawCircle::SetScale(float scale)
	{
		mScale = scale;
	}
	void DrawCircle::SetRadius(float radius)
	{
		mRadius = radius;
	}
	void DrawCircle::SetColor(Color&& color)
	{
		mColor = std::move(color);
	}
	void DrawCircle::SetIsFill(bool isFill)
	{
		mIsFill = isFill;
	}
	const Vector2& DrawCircle::GetPosition() const noexcept
	{
		return mPosition;
	}
	float DrawCircle::GetScale() const noexcept
	{
		return mScale;
	}
	float DrawCircle::GetRadius() const noexcept
	{
		return mRadius;
	}
}