#include"lib/src/CollisionDetection/CollisionDetectionSettingImpl.hpp"

namespace GameLib
{

	float CollisionDetectionSettingImpl::mUnitWidth;
	float CollisionDetectionSettingImpl::mUnitHeigth;

	float CollisionDetectionSettingImpl::mLeft;
	float CollisionDetectionSettingImpl::mRight;
	float CollisionDetectionSettingImpl::mTop;
	float CollisionDetectionSettingImpl::mBottom;
	const int CollisionDetectionSettingImpl::mPow[10] = { 1,4,16,64,256,1024,4096,16384,65536,262144 };
}