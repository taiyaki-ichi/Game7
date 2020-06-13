#pragma once
#include<memory>
#include<list>
#include<cmath>
#include"lib/include/CollisionDetection/Collider.hpp"
#include"lib/include/Manager/Manager.hpp"
#include"lib/src/CollisionDetection/LinerObject.hpp"
#include"SpaceDivisionTree.hpp"
#include"MortonNumber.hpp"

#include<iostream>

namespace GameLib
{

	class ColliderManager
	{
	private:
		static std::list<LinerObject<Collider>> mColliders;

	public:

		static void Add(Collider* collider) {
			mColliders.emplace_back(LinerObject(collider));
		}

		static void Remove(Collider* collder) {
			auto iter = mColliders.begin();
			for (; iter != mColliders.end(); iter++)
				if (iter->GetPtr() == collder)
					break;

			if (iter != mColliders.end())
				mColliders.erase(iter);
				
		}

		static void RegistSpaceDivisionTree(SpaceDivisionTree<Collider>& tree) {
			for (auto& linerObj : mColliders) {
				linerObj.RemoveSpaceCell();

				auto collider = linerObj.GetPtr();
				float scale = collider->GetScale();
				float width = collider->GetWidth() * scale;
				float heigth = collider->GetHeigth() * scale;
				auto pos = collider->GetPosition();

				//squrtégÇ¡Çƒê∏ñßÇ…Ç‚ÇÈÇ©ÅHÅH
				float halfUnitSize = std::sqrt(width * width + heigth * heigth) / 2.f;

				int spaceCellNum = GetMortonNumber(pos.x - halfUnitSize, pos.y - halfUnitSize, pos.x + halfUnitSize, pos.y + halfUnitSize);

				//std::cout << collider->GetNameTag() << " : " << spaceCellNum << "\n";

				if (0 <= spaceCellNum && spaceCellNum < MAX_SPACECELL_NUM)
					tree.Regist(&linerObj, spaceCellNum);
			}
		}

	};




}