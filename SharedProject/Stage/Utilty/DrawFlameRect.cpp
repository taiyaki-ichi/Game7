#include"DrawFlameRect.hpp"

namespace Stage
{
	DrawFlameRect::DrawFlameRect(int drawOrder)
		:GameLib::CustomizeDrawBase{drawOrder}
		, mRect{}
		, mFlame{}
		, mBlank{}
		, mFlameWidth{0.f}
	{
		mRect.SetIsAutoDrawing(false);
		mFlame.SetIsAutoDrawing(false);
		mBlank.SetIsAutoDrawing(false);

		mRect.SetColor({ 255,255,255,255 });
		mFlame.SetColor({ 0,0,0,255 });
	}

	void DrawFlameRect::Draw()
	{
		SetUpStanderdDraw();
		mRect.Draw();

		float h = mRect.GetHeight();
		float w = mRect.GetWidth();

		mBlank.SetWidthAndHeight(w - mFlameWidth, h - mFlameWidth);

		SetUpNotDrawRange();
		mBlank.Draw();

		mFlame.SetWidthAndHeight(w, h);

		SetUpStanderdDraw();
		mFlame.Draw();
	}

	void DrawFlameRect::SetFlameWidth(float w)
	{
		mFlameWidth = w;
	}

	void DrawFlameRect::SetWidthAndHeight(float w, float h)
	{
		mRect.SetWidthAndHeight(w, h);
	}

	void DrawFlameRect::SetFlameColor(GameLib::Color&& c)
	{
		mFlame.SetColor(std::move(c));
	}

	void DrawFlameRect::SetRotation(float rot)
	{
		mRect.SetRotation(rot);
		mFlame.SetRotation(rot);
		mBlank.SetRotation(rot);
	}

	void DrawFlameRect::SetRectColor(GameLib::Color&& c)
	{
		mRect.SetColor(std::move(c));
	}


	void DrawFlameRect::SetPosition(const GameLib::Vector2& pos)
	{
		mRect.SetPosition(pos);
		mFlame.SetPosition(pos);
		mBlank.SetPosition(pos);
	}

	const GameLib::Vector2& DrawFlameRect::GetPosition() const
	{
		return mRect.GetPosition();
	}

	float DrawFlameRect::GetWidth() const
	{
		return mRect.GetWidth();
	}

	float DrawFlameRect::GetHeight() const
	{
		return mRect.GetHeight();
	}
}