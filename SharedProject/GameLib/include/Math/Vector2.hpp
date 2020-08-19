#pragma once
#include<cmath>

namespace GameLib
{

	class Vector2
	{
	public:
		float x;
		float y;

		Vector2()
			:x(0.f)
			,y(0.f)
		{}

		template<typename T,typename U>
		Vector2(T inX,U inY)
			:x(static_cast<float>(inX))
			,y(static_cast<float>(inY))
		{}

		friend Vector2 operator+(const Vector2& a, const Vector2& b) {
			return { a.x + b.x,a.y + b.y };
		}

		friend Vector2 operator-(const Vector2& a, const Vector2& b)
		{
			return { a.x - b.x,a.y - b.y };
		}

		friend Vector2 operator*(const Vector2& a, const Vector2& b)
		{
			return { a.x * b.x,a.y * b.y };
		}

		friend Vector2 operator*(const Vector2& vec, float scalar)
		{
			return { vec.x * scalar, vec.y * scalar };
		}
		friend Vector2 operator*(float scalar, const Vector2& vec)
		{
			return { vec.x * scalar, vec.y * scalar };
		}

		friend Vector2 operator/(const Vector2& vec, float scalar)
		{
			return { vec.x / scalar, vec.y / scalar };
		}
		friend Vector2 operator/(float scalar, const Vector2& vec)
		{
			return  { vec.x / scalar, vec.y / scalar };
		}
		friend Vector2 operator-(const Vector2& vec)
		{
			return  { -vec.x , -vec.y };
		}

		Vector2& operator+=(const Vector2& right)
		{
			x += right.x;
			y += right.y;
			return *this;
		}

		//引き算の代入演算子
		Vector2& operator-=(const Vector2& right)
		{
			x -= right.x;
			y -= right.y;
			return *this;
		}

		Vector2& operator/=(float sca)
		{
			x /= sca;
			y /= sca;
			return *this;
		}
		Vector2& operator*=(float sca)
		{
			x *= sca;
			y *= sca;
			return *this;
		}

		//ベクトルの長さの二乗
		float LengthSq() const
		{
			return (x * x + y * y);
		}

		//ベクトルの長さ
		float Length() const
		{
			return (std::sqrt(LengthSq()));
		}

		void Normalize()
		{
			float length = Length();
			x /= length;
			y /= length;
		}

		//ベクトルの内積
		static float Dot(const Vector2& a, const Vector2& b)
		{
			return (a.x * b.x + a.y * b.y);
		}

		//ベクトルの外積のｚ
		static float Cross(const Vector2& a, const Vector2& b)
		{
			return (a.x * b.y - a.y * b.x);
		}

		static Vector2 Rotation(const Vector2& a, float rot)
		{

			float x = a.x * std::cos(rot) - a.y * std::sin(rot);
			float y = a.x * std::sin(rot) + a.y * std::cos(rot);
			return Vector2(x, y);
		}

	};
}