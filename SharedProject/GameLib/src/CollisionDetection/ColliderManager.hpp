#pragma once
#include<memory>
#include<vector>
#include<cmath>
#include<iostream>
#include"CollisionDetectionLib/include/tree.hpp"
#include"Traits.hpp"

namespace GameLib
{
	class Collider;

	class ColliderManager
	{
	private:
		static std::vector<Collider*> mColliders;

	public:

		static void Add(Collider* collider);

		static void Remove(Collider* collder);

		static void TreeRegist(collision_detection::tree<Collider>& tree);

		static void SetAllIsDrawing(bool b);

	};



}