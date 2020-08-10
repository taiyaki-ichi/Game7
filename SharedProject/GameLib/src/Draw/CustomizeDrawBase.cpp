#include"GameLib/include/Draw/CustomizeDrawBase.hpp"
#include"GameLib/src/Windows/Graphics.hpp"


namespace GameLib
{
	CustomizeDrawBase::CustomizeDrawBase(int drawOrder)
		:DrawBase{drawOrder}
	{
	}

	void CustomizeDrawBase::SetUpAndDrawRange()
	{
		SetMaskStencilBufferState(1);
	}

	void CustomizeDrawBase::SetUpNotDrawRange()
	{
		SetMaskStencilBufferState(0);
	}
	void CustomizeDrawBase::SetUpStanderdDraw()
	{
		SetStanderdStencilBufferState();
	}
	void CustomizeDrawBase::ResetDrawRangeZero()
	{
		ClearStencilBuffer(0);
	}
}