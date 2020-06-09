#include"DrawBase.hpp"
#include"Manager/DrawManager.hpp"

namespace GameLib
{
	DrawBase::DrawBase(int drawOrder)
		:mDrawOrder(drawOrder)
	{
		DrawManager::Add(this);
	}
}