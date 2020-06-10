#include"lib/include/Draw/DrawBase.hpp"
#include"Manager/DrawManager.hpp"
#include "..\..\include\Draw\DrawBase.hpp"

namespace GameLib
{
	DrawBase::DrawBase(int drawOrder)
		:mDrawOrder(drawOrder)
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
}