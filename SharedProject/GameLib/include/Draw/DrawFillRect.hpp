#pragma once
#include"DrawBase.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"Color.hpp"

namespace GameLib
{
	class DrawFillRect : public DrawBase
	{
		Vector2 mPosition;
		float mScale;
		float mRotation;

		float mWidth;
		float mHeight;

		Color mColor;

	public:
		DrawFillRect(int drawOrder = 0);
		virtual ~DrawFillRect() = default;

		void Draw() override;

		void Set(const Vector2& pos, float scale, float rot);
		void SetWidthAndHeight(float w, float h);
		void SetPosition(const Vector2& pos);
		void SetScale(float scale);
		void SetRotation(float rot);
		void SetColor(Color&& color);

		const Vector2& GetPosition() const noexcept;
		float GetScale() const noexcept;
		float GetRotation() const noexcept;
		float GetWidth() const noexcept;
		float GetHeight() const noexcept;
	};
}