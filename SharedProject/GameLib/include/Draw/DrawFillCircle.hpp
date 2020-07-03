#pragma once
#include"DrawBase.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"Color.hpp"

namespace GameLib
{
	class DrawFillCircle : public DrawBase
	{
		Vector2 mPosition;
		float mScale;

		float mRadius;

		Color mColor;

	public:
		DrawFillCircle(int drawOrder = 0);
		virtual ~DrawFillCircle() = default;

		void Draw() override final;

		void SetPosition(const Vector2& pos);
		void SetScale(float scale);
		void SetRadius(float radius);
		void SetColor(Color&& color);

		const Vector2& GetPosition() const noexcept;
		float GetScale() const noexcept;
		float GetRadius() const noexcept;
	};
}