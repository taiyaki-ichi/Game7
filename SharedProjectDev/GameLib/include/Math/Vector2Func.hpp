#pragma once
#include"Vector2.hpp"
#include<cmath>
#include<utility>
#include<algorithm>
#include<vector>

#include<iostream>

namespace GameLib
{

	//原点を中心にrot分回転
	inline Vector2 Rotation(Vector2&& vec, float rot) {

		if (rot == 0.f)
			return std::move(vec);

		float x = vec.x * std::cos(rot) - vec.y * std::sin(rot);
		float y = vec.x * std::sin(rot) + vec.y * std::cos(rot);

		return { x,y };
	}

	//centerと中心にrot回転
	inline Vector2 Rotation(Vector2&& vec, float rot, const Vector2& center) {
		auto v = Rotation(vec - center, rot);
		return v + center;
	}
	inline Vector2 Rotation(const Vector2& vec, float rot, const Vector2& center) {
		auto v = Rotation(vec - center, rot);
		return v + center;
	}

	//アフィン変換
	inline Vector2 Affine(const Vector2& vec, Vector2&& unitVecX, Vector2&& unitVecY, const Vector2& origin) {
		float x = unitVecX.x * vec.x + unitVecY.x * vec.y + origin.x;
		float y = unitVecX.y * vec.x + unitVecY.y * vec.y + origin.y;
		return { x,y };
	}

	inline Vector2 AffineInv(const Vector2& vec, Vector2&& unitVecX, Vector2&& unitVecY, const Vector2& origin) {
		float x = -unitVecY.y * vec.x + unitVecY.x * vec.x - unitVecY.x * origin.y + origin.x * unitVecY.y;
		float y = unitVecX.y * vec.y - unitVecX.x * vec.y - origin.x * unitVecX.y + unitVecX.x * origin.y;
		float waru = unitVecY.x * unitVecX.y - unitVecX.x * unitVecY.y;
		return { x / waru,y / waru };
	}

	//座標形の中心と倍率と角度からアフィン変換
	inline Vector2 Affine(const Vector2& vec, const Vector2& center, float rot, float scale) {
		Vector2 unitVecX = Rotation({ 1.f,0.f }, rot) * scale;
		Vector2 unitVecY = Rotation({ 0.f,1.f }, rot) * scale;
		return Affine(vec, std::move(unitVecX), std::move(unitVecY), -center * scale);

	}

	inline Vector2 AffineInv(const Vector2& vec, const Vector2& center, float rot, float scale) {
		Vector2 unitVecX = Rotation({ 1.f,0.f }, rot) * scale;
		Vector2 unitVecY = Rotation({ 0.f,1.f }, rot) * scale;
		return AffineInv(vec, std::move(unitVecX), std::move(unitVecY), -center * scale);
	}

	//反時計回りの4っつのベクトルみたいな
	inline std::vector<Vector2> GetCounterclockwise4Vec() {
		
		std::vector<Vector2> v = {
			Vector2{1.f,1.f},
			Vector2{-1.f,1.f},
			Vector2{-1.f,-1.f},
			Vector2{1.f,-1.f}
		};
		
		//std::cout << "a" << std::endl;
		return v;
	}


	inline std::vector<Vector2> GetRectangleVectors(const Vector2& center,float width,float heigth,float rot) {
		std::vector<Vector2> vecs = GetCounterclockwise4Vec();
		std::vector<Vector2> result;
		std::transform(vecs.begin(), vecs.end(), std::back_inserter(result),
			[center, width, heigth, rot](const Vector2& vec) {return Rotation(Vector2{ vec.x * width / 2.f,vec.y * heigth / 2.f }, rot) + center; });

		return result;
	}

	//p1とp2からなる直線とq1とq2からなる直線の交差判定
	inline bool CrossingDetection(const Vector2& p1, const Vector2& p2, const Vector2& q1, const Vector2& q2) {
		if (Vector2::Cross(p2 - p1, q1 - p1) * Vector2::Cross(p2 - p1, q2 - p1) < 0&&
			Vector2::Cross(q2 - q1, p1 - q1) * Vector2::Cross(q2 - q1, p2 - q1) < 0)
			return true;
		else
			return false;
	}

	//ある点が四角形の内側かどうか、4つの点は反時計回り
	inline bool IsInsideRect(const Vector2& p, const std::vector<Vector2>& point) {
		if (Vector2::Cross(point[3] - point[0], p - point[3]) > 0)
			return false;
		if (Vector2::Cross(point[2] - point[3], p - point[2]) > 0)
			return false;
		if (Vector2::Cross(point[1] - point[2], p - point[1]) > 0)
			return false;
		if (Vector2::Cross(point[0] - point[1], p - point[0]) > 0)
			return false;

		return true;
	}



	inline bool CollisionDetection(std::vector<Vector2>&& rect1, std::vector<Vector2>&& rect2) 
	{

		//点が含まれているか
		for (const auto& p : rect1)
			if (IsInsideRect(p, rect2))
				return true;
		for (const auto& p : rect2)
			if (IsInsideRect(p, rect1))
				return true;
		
		
		
		//線が交差しているか
		bool flag = false;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				if (i == 3 && j == 3)
					flag = CrossingDetection(rect1[3], rect1[0], rect2[3], rect2[0]);
				else if (i == 3)
					flag = CrossingDetection(rect1[3], rect1[0], rect2[j], rect2[j + 1]);
				else if (j == 3)
					flag = CrossingDetection(rect1[i], rect1[i + 1], rect2[3], rect2[0]);
				else
					flag = CrossingDetection(rect1[i], rect1[i + 1], rect2[j], rect2[j + 1]);

				if (flag)
					return true;
			}
			
		
		return false;

	}

	//a,bの距離
	inline float GetLength(const GameLib::Vector2& a, const GameLib::Vector2& b)
	{
		float dx = a.x - b.x;
		float dy = a.y - b.y;
		return std::sqrt(dx * dx + dy * dy);
	}

	//直線abcが時計回りかどうか
	inline bool IsClockwise(const GameLib::Vector2& a, const GameLib::Vector2& b, const GameLib::Vector2& c)
	{
		GameLib::Vector2 vec1 = b - a;
		GameLib::Vector2 vec2 = c - b;
		return GameLib::Vector2::Cross(vec1, vec2) > 0.f;
	}

	//a,bのx方向の距離
	inline float GetDistanceX(const GameLib::Vector2& a, const GameLib::Vector2& b)
	{
		return std::abs(a.x - b.x);
	}
	//yの距離
	inline float GetDistanceY(const GameLib::Vector2& a, const GameLib::Vector2& b)
	{
		return std::abs(a.y - b.y);
	}

	//a,bの真ん中
	inline GameLib::Vector2 GetCenter(const GameLib::Vector2& a, const GameLib::Vector2& b)
	{
		float minX = (a.x < b.x) ? a.x : b.x;
		float mixY = (a.y < b.y) ? a.y : b.y;
		float w = GetDistanceX(a, b);
		float h = GetDistanceY(a, b);
		return { minX + w / 2.f,mixY + h / 2.f };

	}

}