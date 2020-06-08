#include"CollisionDetectionSetting.hpp"

namespace GameLib
{
	//èâä˙íl
	float CollisionDetectionSetting::mHeigth = 0.f;
	float CollisionDetectionSetting::mWidth = 0.f;
	Vector2 CollisionDetectionSetting::mPos = Vector2();
	unsigned int CollisionDetectionSetting::mLevel = 0;

	float CollisionDetectionSetting::mUnitWidth;
	float CollisionDetectionSetting::mUnitHeigth;

	float CollisionDetectionSetting::mLeft;
	float CollisionDetectionSetting::mRight;
	float CollisionDetectionSetting::mTop;
	float CollisionDetectionSetting::mBottom;
	const int CollisionDetectionSetting::mPow[10] = { 1,4,16,64,256,1024,4096,16384,65536,262144 };
}