#pragma once
#include<memory>
#include<list>
#include<cmath>
#include"LinerObject.hpp"

#include<iostream>

namespace GameLib
{
	template<typename T>
	class SpaceDivisionTree;

	class Collider;
	struct SwitchDrawing;

	class ColliderManager
	{
	private:
		static std::list<LinerObject<Collider>> mColliders;

	public:

		static void Add(Collider* collider);

		static void Remove(Collider* collder);

		static void RegistSpaceDivisionTree(SpaceDivisionTree<Collider>& tree);

		static void SwitchAllColliderDraw();

	};



}