#include"GameLib/include/Draw/DrawRect.hpp"
#include"GameLib/src/Windows/Graphics.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include"GameLib/src/Windows/Window.hpp"

namespace GameLib
{
	DrawRect::DrawRect(int drawOrder)
		:DrawBase{ drawOrder }
		, mPosition{ 0.f,0.f }
		, mScale{ 1.f }
		, mRotation{ 0.f }
		, mWidth{ 0.f }
		, mHeight{0.f}
		, mColor{ 0,0,0,255 }
		, mIsFill{true}
	{
	}
	void DrawRect::Draw()
	{
		float wHalf = GetWindowWidth() / 2.f;
		float hHalf = GetWindowHeigth() / 2.f;
		float viewRot = Viewport::GetRotation();
		float viewSca = Viewport::GetScale();
		Vector2 affinedPos = Affine(mPosition, Viewport::GetPos(), -viewRot, viewSca);
		GraphycsDrawRect(affinedPos.x + wHalf, -affinedPos.y + hHalf, mWidth, mHeight, mScale * viewSca, mRotation - viewRot,
			mColor.R, mColor.G, mColor.B, mColor.A, mIsFill);
	}
	void DrawRect::Set(const Vector2& pos, float scale, float rot)
	{
		mPosition = pos;
		mScale = scale;
		mRotation = rot;
	}
	void DrawRect::SetWidthAndHeight(float w, float h)
	{
		mWidth = w;
		mHeight = h;
	}
	void DrawRect::SetPosition(const Vector2& pos)
	{
		mPosition = pos;
	}
	void DrawRect::SetScale(float scale)
	{
		mScale = scale;
	}
	void DrawRect::SetRotation(float rot)
	{
		mRotation = rot;
	}
	void DrawRect::SetColor(Color&& color)
	{
		mColor = std::move(color);
	}
	void DrawRect::SetIsFill(bool isFill)
	{
		mIsFill = isFill;
	}
	const Vector2& DrawRect::GetPosition() const noexcept
	{
		return mPosition;
	}
	float DrawRect::GetScale() const noexcept
	{
		return mScale;
	}
	float DrawRect::GetRotation() const noexcept
	{
		return mRotation;
	}
	float DrawRect::GetWidth() const noexcept
	{
		return mWidth;
	}
	float DrawRect::GetHeight() const noexcept
	{
		return mHeight;
	}
}