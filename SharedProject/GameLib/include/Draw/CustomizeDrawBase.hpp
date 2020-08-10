#pragma once
#include"DrawBase.hpp"

namespace GameLib
{

	class CustomizeDrawBase : public DrawBase
	{
	public:
		CustomizeDrawBase(int drawOrder = 0);
		virtual ~CustomizeDrawBase() = default;

		//Drawないで描写する場合
		//DrawBaseのIsAutoDrawingをFalseにしておく
		void Draw() override {};

	protected:
		//それぞれのDrawの前に使用する
		//描写する範囲を指定する
		void SetUpAndDrawRange();
		//描写しない範囲を指定する
		void SetUpNotDrawRange();
		//通常の描写
		void SetUpStanderdDraw();


		//描写する範囲を0でリセットする
		void ResetDrawRangeZero();

	};

}