#pragma once
#include"DrawBase.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"Color.hpp"

namespace GameLib
{
	class DrawRect : public DrawBase
	{
		Vector2 mPosition;
		float mScale;
		float mRotation;

		float mWidth;
		float mHeight;

		Color mColor;

		bool mIsFill;

	public:
		DrawRect(int drawOrder = 0);
		virtual ~DrawRect() = default;

		void Draw() override final;

		void Set(const Vector2& pos, float scale, float rot);
		void SetWidthAndHeight(float w, float h);
		void ResetPosition(const Vector2& pos);
		void SetScale(float scale);
		void SetRotation(float rot);
		void SetColor(Color&& color);
		void SetIsFill(bool isFill);

		const Vector2& GetPosition() const noexcept;
		float GetScale() const noexcept;
		float GetRotation() const noexcept;
		float GetWidth() const noexcept;
		float GetHeight() const noexcept;
	};
}