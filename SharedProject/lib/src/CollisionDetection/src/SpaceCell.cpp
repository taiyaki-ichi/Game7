#include"lib/src/CollisionDetection/SpaceCell.hpp"
#include"lib/src/CollisionDetection/LinerObject.hpp"

namespace GameLib
{
	SpaceCell::SpaceCell(int spaceNum)
		:mThisSpaceNumber(spaceNum)
		,mFirstLinerObject(nullptr)
	{
	}
	SpaceCell::~SpaceCell()
	{
	}
	bool SpaceCell::Push(LinerObject* obj)
	{
		if (!obj)
			return false;

		if (!mFirstLinerObject)
			mFirstLinerObject = obj;
		else 
		{
			obj->mNextObject = mFirstLinerObject;
			mFirstLinerObject->mPreObject = obj;
			mFirstLinerObject = obj;
		}

		return true;
	}
}