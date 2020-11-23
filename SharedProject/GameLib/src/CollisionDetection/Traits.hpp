#pragma once
#include"CollisionDetectionLib/include/traits.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include<utility>

namespace collision_detection
{
	/*
	template<typename T>
	struct range_traits
	{
		//Tが完全に収まるできるだけ小さい範囲を返す
		//left,right,bottom,topの順
		//テンプレートを特殊化して使用
		inline static std::tuple<float, float, float, float> get_range(const T&);
	};
	*/

	template<>
	struct range_traits<GameLib::Collider>
	{
		static std::tuple<float, float, float, float> get_range(const GameLib::Collider& collider) {

			float scale = collider.GetScale();
			float width = collider.GetWidth() * scale;
			float heigth = collider.GetHeigth() * scale;
			const auto& pos = collider.GetPosition();

			float halfUnitSize = std::sqrt(width * width + heigth * heigth) / 2.f;

			//return { pos.x - halfUnitSize, pos.y - halfUnitSize, pos.x + halfUnitSize, pos.y + halfUnitSize };
			return { pos.x - halfUnitSize,pos.x + halfUnitSize, pos.y - halfUnitSize, pos.y + halfUnitSize };
		}
	};

	/*
	template<>
	struct shape_traits<GameLib::Collider>
	{
		static unsigned int get_vertex_num(const GameLib::Collider&) {
			return 4;
		}

		//仮
		static float get_vertex_x(const GameLib::Collider& c, unsigned int vertexNum) {

			
			float width = c.GetWidth();
			float height = c.GetHeigth();
			float rot = c.GetRotation();
			const auto& center = c.GetPosition();
			float scale = c.GetScale();

			GameLib::Vector2 vec{ width / 2.f * scale,height / 2.f * scale };
			vec = GameLib::Vector2::Rotation(vec, GameLib::PI / 2.f * vertexNum + rot) + center;

			return vec.x;
		}
		static float get_vertex_y(const GameLib::Collider& c, unsigned int vertexNum) {
			
			float width = c.GetWidth();
			float height = c.GetHeigth();
			float rot = c.GetRotation();
			const auto& center = c.GetPosition();
			float scale = c.GetScale();

			GameLib::Vector2 vec{ width / 2.f * scale,height / 2.f * scale };
			vec = GameLib::Vector2::Rotation(vec, GameLib::PI / 2.f * vertexNum + rot) + center;

			return vec.y;

		}
	};
	*/
}