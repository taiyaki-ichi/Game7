#pragma once
#include<vector>
#include<memory>

namespace GameLib
{
	//‚»‚ê‚¼‚ê‚ÌŠî’êƒNƒ‰ƒX
	class DrawBase
	{
		int mDrawOrder;
		//Ž©“®‚Å•`‰æ‚·‚é‚©‚Ç‚¤‚©
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