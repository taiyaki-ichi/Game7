#pragma once
#include"lib/include/CollisionDetection/CollisionDetectionSetting.hpp"

namespace GameLib
{
	constexpr int POWER_OF_FOUR[11] = { 1,4,16,64,256,1024,4096,16384,65536,262144,1048576 };
	constexpr int MAX_SPACECELL_NUM = (POWER_OF_FOUR[TREE_MAX_LEVEL + 1] - 1) / 3;

	class CollisionDetectionSettingImpl : public CollisionDetectionSetting
	{
	private:
		//当たり判定を行う前に一括で計算
		//空間分割した際の最小のタテヨコ
		static float mUnitWidth;
		static float mUnitHeigth;

		static float mLeft;
		static float mRight;
		static float mTop;
		static float mBottom;

		static int mNowLevelCellNum;

	public:
		//当たり判定の行う前に呼び出してそれぞれの値を計算しておく
		static void ColcMembers() {
			mLeft = mPos.x - mWidth / 2.f;
			mRight = mPos.x + mWidth / 2.f;
			mTop = mPos.y - mHeigth / 2.f;
			mBottom = mPos.y + mHeigth / 2.f;

			mUnitWidth = (mRight - mLeft) / (1 << mLevel);
			mUnitHeigth = (mBottom - mTop) / (1 << mLevel);

			mNowLevelCellNum = (POWER_OF_FOUR[mLevel + 1] - 1) / 3;
		}

		static float GetLeft() noexcept {
			return mLeft;
		}
		static float GetTop() noexcept {
			return mTop;
		}
		static float GetUnitWidth() noexcept {
			return mUnitWidth;
		}
		static float GetUnitHeigth() noexcept {
			return mUnitHeigth;
		}

		static int GetNowLevelCellNum() noexcept {
			return mNowLevelCellNum;
		}
	};

}