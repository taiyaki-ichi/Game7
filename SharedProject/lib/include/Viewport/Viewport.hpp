#pragma once
#include<utility>
#include"lib/include/Math/Vector2.hpp"

namespace GameLib
{
	class Viewport
	{
		//カメラの位置
		static Vector2 mPos;
		//角度
		static float mRotation;
		//すけ
		static float mScale;

	public:
		static void SetPos(const Vector2& pos) noexcept {
			mPos = pos;
		}
		static void SetPos(Vector2&& pos) noexcept {
			mPos = std::move(pos);
		}
		static const Vector2& GetPos() noexcept {
			return mPos;
		}

		static void SetRotation(float rot) noexcept {
			mRotation = rot;
		}

		static float GetRotation() noexcept {
			return mRotation;
		}

		static void SetScale(float s) noexcept {
			mScale = s;
		}
		static float GetScale() noexcept {
			return mScale;
		}

	};
}