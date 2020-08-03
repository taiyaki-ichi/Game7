#pragma once
#include"DrawBase.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"Color.hpp"

namespace GameLib
{

	class DrawLine : public DrawBase
	{
		Vector2 mPoint1;
		Vector2 mPoint2;

		Color mColor;

	public:
		DrawLine(const Vector2& p1 = { 0.f,0.f }, const Vector2& p2 = { 0.f,0.f }, const Color& color = { 0,0,0,255 }, int drawOrder = 0);
		virtual ~DrawLine();

		void Draw() override final;

		void SetPoints(const Vector2& p1, const Vector2& p2);
		void SetPoints(Vector2&& p1, Vector2&& p2);

		void SetColor(Color&& color);
		void SetColor(const Color& color);
	};

}