#pragma once
#include<vector>
#include<memory>

namespace GameLib
{
	//それぞれの基底クラス
	class DrawBase
	{
		int mDrawOrder;
		//自動で描画するかどうか
		bool  mIsAutoDrawing;

	public:
		DrawBase(int drawOrder = 0);
		virtual ~DrawBase();

		virtual void SetUpDraw() {};
		virtual void Draw() = 0;

		int GetDrawOrder()const noexcept;
		void SetDrawOrder(int order);

		bool GetIsAutoDrawing();
		void SetIsAutoDrawing(bool i);
	};
}