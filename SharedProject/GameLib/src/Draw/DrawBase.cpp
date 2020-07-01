#include"GameLib/include/Draw/DrawBase.hpp"
#include"GameLib/src/Draw/Manager/DrawManager.hpp"

namespace GameLib
{
	DrawBase::DrawBase(int drawOrder)
		:mDrawOrder(drawOrder)
		,mIsDrawing(true)
	{
		DrawManager::Add(this);
	}
	DrawBase::~DrawBase()
	{
		DrawManager::Remove(this);
	}
	int DrawBase::GetDrawOrder() const noexcept
	{
		return mDrawOrder;
	}
	void DrawBase::SetDrawOrder(int order)
	{
		if (mDrawOrder != order)
		{
			mDrawOrder = order;
			DrawManager::Remove(this);
			DrawManager::Add(this);
		}
	}
	bool DrawBase::GetIsDrawing()
	{
		return mIsDrawing;
	}
	void DrawBase::SetIsDrawing(bool i)
	{
		mIsDrawing = i;
	}
}