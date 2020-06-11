#pragma once
#include<memory>
#include<list>
#include"lib/include/CollisionDetection/Collider.hpp"
#include"lib/include/Manager/Manager.hpp"
#include"lib/src/CollisionDetection/LinerObject.hpp"

namespace GameLib
{
	struct ColliderManagerRemove {
		bool operator()(Collider* removePtr, LinerObject* checkPtr) {
			if (removePtr == checkPtr->GetCollider()) {
				delete checkPtr;
				return true;
			}
			else
				return false;
		}
	};

	class ColliderManager
	{
	private:
		static OwnerManager<LinerObject> mColliders;

	public:

		static void Add(Collider* collider) {
			auto obj = new LinerObject(collider);
			mColliders.Add({ obj,0 });
		}

		static void Remove(Collider* collder) {
			mColliders.Remove<Collider, ColliderManagerRemove>(collder);
		}



	};




}