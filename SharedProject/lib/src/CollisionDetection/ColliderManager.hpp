#pragma once
#include<memory>
#include<list>
#include"lib/include/CollisionDetection/Collider.hpp"
#include"lib/include/Manager/Manager.hpp"
#include"lib/src/CollisionDetection/LinerObject.hpp"
#include"SpaceDivisionTree.hpp"
namespace GameLib
{

	class ColliderManager
	{
	private:
		static std::list<LinerObject*> mColliders;

	public:

		static void Add(Collider* collider) {
			auto obj = new LinerObject(collider);
			mColliders.emplace_back(obj);
		}

		static void Remove(Collider* collder) {
			auto iter = mColliders.begin();
			for (; iter != mColliders.end(); iter++)
				if ((*iter)->GetCollider() == collder)
					break;

			if (iter != mColliders.end())
			{
				auto linerObj = *iter;
				mColliders.erase(iter);
				delete linerObj;
			}
				
		}

		static void RegistSpaceDivisionTree(SpaceDivisionTree* tree) {
			std::cout << "collide num  :" << mColliders.size() << "\n";
			for (auto obj : mColliders)
				tree->Resist(obj);
		}

	};




}