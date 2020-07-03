#include"GameLib/include/Draw/DrawFillRect.hpp"
#include"GameLib/src/Windows/Graphics.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include"GameLib/src/Windows/Window.hpp"

namespace GameLib
{
	DrawFillRect::DrawFillRect(int drawOrder)
		:DrawBase{ drawOrder }
		, mPosition{ 0.f,0.f }
		, mScale{ 1.f }
		, mRotation{ 0.f }
		, mWidth{ 0.f }
		, mHeight{0.f}
		, mColor{ 0,0,0,255 }
	{
	}
	void DrawFillRect::Draw()
	{
		float wHalf = GetWindowWidth() / 2.f;
		float hHalf = GetWindowHeigth() / 2.f;
		float viewRot = Viewport::GetRotation();
		float viewSca = Viewport::GetScale();
		Vector2 affinedPos = Affine(mPosition, Viewport::GetPos(), -viewRot, viewSca);
		GraphycsDrawFillRect(affinedPos.x + wHalf, -affinedPos.y + hHalf, mWidth, mHeight, mScale * viewSca, mRotation - viewRot,
			mColor.R, mColor.G, mColor.B, mColor.A);
	}
	void DrawFillRect::Set(const Vector2& pos, float scale, float rot)
	{
		mPosition = pos;
		mScale = scale;
		mRotation = rot;
	}
	void DrawFillRect::SetWidthAndHeight(float w, float h)
	{
		mWidth = w;
		mHeight = h;
	}
	void DrawFillRect::SetPosition(const Vector2& pos)
	{
		mPosition = pos;
	}
	void DrawFillRect::SetScale(float scale)
	{
		mScale = scale;
	}
	void DrawFillRect::SetRotation(float rot)
	{
		mRotation = rot;
	}
	void DrawFillRect::SetColor(Color&& color)
	{
		mColor = std::move(color);
	}
	const Vector2& DrawFillRect::GetPosition() const noexcept
	{
		return mPosition;
	}
	float DrawFillRect::GetScale() const noexcept
	{
		return mScale;
	}
	float DrawFillRect::GetRotation() const noexcept
	{
		return mRotation;
	}
	float DrawFillRect::GetWidth() const noexcept
	{
		return mWidth;
	}
	float DrawFillRect::GetHeight() const noexcept
	{
		return mHeight;
	}
}