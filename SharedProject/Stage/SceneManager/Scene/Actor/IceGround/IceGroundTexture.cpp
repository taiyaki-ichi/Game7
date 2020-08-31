#include"IceGroundTexture.hpp"
#include"IceGroundTextureParam.hpp"
#include"GameLib/include/Math/Numbers.hpp"

#include<iostream>

namespace Stage
{
	IceGroundTexture::IceGroundTexture(int order)
		:GameLib::CustomizeDrawBase{order}
		, mRect{}
		, mRect2{}
	{

		mRect.SetIsAutoDrawing(false);
		mRect.SetIsFill(true);
		mRect.SetColor({ 50,50,50,100 });

		mRect2.SetIsAutoDrawing(false);
		mRect2.SetIsFill(true);
		mRect2.SetColor({ 20,20,20,100 });
		mRect2.SetRotation(GameLib::PI / 4.f);
	}

	void IceGroundTexture::Draw()
	{
		SetUpStanderdDraw();
		mRect.Draw();

		ResetDrawRangeZero();

		SetUpAndDrawRange();
		mRect.Draw();
		
		auto myPos = mRect.GetPosition();
		float w = mRect.GetWidth();
		float h = mRect.GetHeight();

		using namespace IceGroundTextureParam;

		mRect2.SetWidthAndHeight(w + h, LINE_WIDTH);

		auto pos = GameLib::Vector2{ -w / 2.f,h / 2.f } + myPos;
		auto deltaPos = GameLib::Vector2{ w,h };
		deltaPos.Normalize();
		deltaPos = { 1.f,-1.f };
		deltaPos *= LINE_WIDTH * std::sqrt(2.f);
		deltaPos = GameLib::Vector2::Rotation(deltaPos, std::atan2(w, h) - GameLib::PI / 4.f);
		auto endPos= GameLib::Vector2{ w / 2.f,-h / 2.f } + myPos;

		while (pos.x < endPos.x || pos.y > endPos.y)
		{
			
			mRect2.SetPosition(pos);

			SetUpStanderdDraw();
			mRect2.Draw();

			pos += deltaPos;
		}

	}

	void IceGroundTexture::SetWidthAndHeight(float w, float h)
	{
		mRect.SetWidthAndHeight(w, h);
	}

	void IceGroundTexture::SetPosition(const GameLib::Vector2& pos)
	{
		mRect.SetPosition(pos);
	}
}