#pragma once
#include<utility>
#include"lib/include/Math/Vector2.hpp"

namespace GameLib
{	
	constexpr unsigned int TREE_MAX_LEVEL = 9;

	//当たり判定を行う範囲とその中心の座標
	class CollisionDetectionSetting
	{
	private:
		//セッティングできる値
		static float mWidth;
		static float mHeigth;
		static Vector2 mPos;
		//最大値はは9で10層の空間に分割できる
		static unsigned int mLevel;


		//当たり判定を行う前に一括で計算
		//空間分割した際の最小のタテヨコ
		static float mUnitWidth;
		static float mUnitHeigth;

		static float mLeft;
		static float mRight;
		static float mTop;
		static float mBottom;

		static const int mPow[10];

	public:

		static float GetWidth() noexcept {
			return mWidth;
		}
		static void SetWidth(float w) noexcept {
			mWidth = w;
		}
		static float GetHeight() noexcept {
			return mHeigth;
		}
		static void SetHeigth(float h) noexcept {
			mHeigth = h;
		}
		static const Vector2& GetPos() noexcept {
			return mPos;
		}
		static void SetPos(const Vector2& pos) noexcept {
			mPos = pos;
		}
		static void SetPos(Vector2&& pos) noexcept {
			mPos = std::move(pos);
		}
		static unsigned int GetLevel()noexcept {
			return mLevel;
		}
		static void SetLevel(unsigned int l)noexcept {
			if (l < 0)
				mLevel = 0;
			else if (TREE_MAX_LEVEL < l)
				mLevel = TREE_MAX_LEVEL;
			else
				mLevel = l;

		}


		//当たり判定の行う前に呼び出してそれぞれの値を計算しておく
		static void ColcMembers() {
			mLeft = mPos.x - mWidth / 2.f;
			mRight = mPos.x + mWidth / 2.f;
			mTop = mPos.y - mHeigth / 2.f;
			mBottom = mPos.y + mHeigth / 2.f;
			
			mUnitWidth = (mRight - mLeft) / (1 << mLevel);
			mUnitHeigth = (mBottom - mTop) / (1 << mLevel);
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

		static int GetPowerOfFour(int num) {
			return mPow[num];
		}

	};

}