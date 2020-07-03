#pragma once
#include"DrawBase.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"Color.hpp"

namespace GameLib
{
	class DrawCircle : public DrawBase
	{
		Vector2 mPosition;
		float mScale;

		float mRadius;

		Color mColor;

		bool mIsFill;

	public:
		DrawCircle(int drawOrder = 0);
		virtual ~DrawCircle() = default;

		void Draw() override final;

		void SetPosition(const Vector2& pos);
		void SetScale(float scale);
		void SetRadius(float radius);
		void SetColor(Color&& color);
		void SetIsFill(bool isFill);

		const Vector2& GetPosition() const noexcept;
		float GetScale() const noexcept;
		float GetRadius() const noexcept;
	};
}