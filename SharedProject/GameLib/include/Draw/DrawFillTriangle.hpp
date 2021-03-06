#pragma once
#include"DrawBase.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"Color.hpp"
#include<utility>

namespace GameLib
{
	class DrawFillTriangle : public DrawBase
	{
		Vector2 mPoint1;
		Vector2 mPoint2;
		Vector2 mPoint3;

		Color mColor;

	public:
		//3点は時計回り
		DrawFillTriangle(const Vector2& p1 = { 0.f,0.f }, const Vector2& p2 = { 0.f,0.f }, const Vector2& p3 = {0.f,0.f},
			Color&& color = { 0,0,0,255 }, int drawOrder = 0);

		virtual ~DrawFillTriangle() = default;

		void Draw() override final;

		void SetPoints(const Vector2& p1, const Vector2& p2, const Vector2& p3);
		void SetColor(Color&& color) {
			mColor = std::move(color);
		}
	};
}