#include"BlinderRect.hpp"
#include"BlinderParam.hpp"

namespace Stage
{
	BlinderRect::BlinderRect()
		:CustomizeDrawBase{30}
		, mRect{}
		, mCircle{}
	{
		mCircle.SetRadius(BlinderParam::RADIUS);

		mRect.SetColor({ 50,50,50,255 });

		mRect.SetIsAutoDrawing(false);
		mCircle.SetIsAutoDrawing(false);
	}

	void BlinderRect::Draw()
	{
		SetUpNotDrawRange();
		mCircle.Draw();

		SetUpStanderdDraw();
		mRect.Draw();
	}

	void BlinderRect::SetPlayerPos(const GameLib::Vector2& pos)
	{
		mCircle.SetPosition(pos);
	}

	void BlinderRect::SetRect(const GameLib::Vector2& pos, float w, float h)
	{
		mRect.SetPosition(pos);
		mRect.SetWidthAndHeight(w, h);
	}
}