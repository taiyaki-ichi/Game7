#pragma once
#include<utility>
#include"GameLib/include/Math/Vector2.hpp"

namespace GameLib
{

	//当たり判定を行う範囲とその中心の座標
	class CollisionDetectionSetting
	{
	protected:
		//セッティングできる値
		static float mWidth;
		static float mHeigth;
		static Vector2 mPos;


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
		static void SetHeight(float h) noexcept {
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
		

	};

}