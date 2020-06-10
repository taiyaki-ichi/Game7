#pragma once

namespace GameLib
{
	//‚»‚ê‚¼‚ê‚ÌŠî’êƒNƒ‰ƒX
	class DrawBase
	{
		int mDrawOrder;

	public:
		DrawBase(int drawOrder = 0);
		virtual ~DrawBase();

		virtual void Draw() = 0;

		int GetDrawOrder()const noexcept;
		void SetDrawOrder(int order);
	};
}