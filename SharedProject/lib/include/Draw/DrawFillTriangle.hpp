#pragma once
#include"DrawBase.hpp"
#include"lib/include/Math/Vector2.hpp"
#include"Color.hpp"

namespace GameLib
{
	class DrawFillTriangle : public DrawBase
	{
		Vector2 mPoint1;
		Vector2 mPoint2;
		Vector2 mPoint3;

		Color mColor;

	public:
		//3“_‚ÍŽžŒv‰ñ‚è
		DrawFillTriangle(const Vector2& p1 , const Vector2& p2, const Vector2& p3, Color&& color = { 0,0,0,255 }, int drawOrder = 0);
		virtual ~DrawFillTriangle() = default;

		void Draw() override final;

		void SetPoints(const Vector2& p1, const Vector2& p2, const Vector2& p3);

	};
}