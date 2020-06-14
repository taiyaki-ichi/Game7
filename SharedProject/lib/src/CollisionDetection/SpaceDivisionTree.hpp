#pragma once
#include<vector>
#include"SpaceCell.hpp"
#include"CollisionDetectinPolicy.hpp"
#include"ColliderManager.hpp"
#include"CollsionDetectionData.hpp"
#include"CollisionDetectionSettingImpl.hpp"

namespace GameLib
{
	class ColliderManager;
	class CollisionDetectionSettingImpl;

	template<typename T>
	class SpaceDivisionTree
	{
		SpaceCell<T>* mSpaceCellArray[MAX_SPACECELL_NUM];
		std::vector<LinerObject<T>*> mCollisionStack;

		//SerchTreeÇÃçƒãAóp
		template<typename Policy>
		std::vector<LinerObject<T>*> RecursionSearchTree(std::vector<LinerObject<T>*>&& collisionStack, int speaceCellNum) {
			LinerObject<T>* linerObj1 = mSpaceCellArray[speaceCellNum]->GetFirstLinerObject();
			LinerObject<T>* linerObj2 = nullptr;

			while (linerObj1)
			{
				linerObj2 = linerObj1->mNextLinerObject;
				while (linerObj2)
				{
					Policy()(linerObj1->GetPtr(), linerObj2->GetPtr());
					linerObj2 = linerObj2->mNextLinerObject;
				}

				if (!collisionStack.empty())
					for (auto& linerObj : collisionStack) {
						Policy()(linerObj1->GetPtr(), linerObj->GetPtr());
					}

				linerObj1 = linerObj1->mNextLinerObject;
			}

			bool isAddThisSpaceLinerObject = false;
			int addLinerObjectNum = 0;

			for (int i = 0; i < 4; i++)
			{
				int nextSpaceCellNum = speaceCellNum * 4 + 1 + i;
				if (nextSpaceCellNum < MAX_SPACECELL_NUM && mSpaceCellArray[nextSpaceCellNum]->mHasLinerObject)
				{
					if (!isAddThisSpaceLinerObject) {
						linerObj1 = mSpaceCellArray[speaceCellNum]->GetFirstLinerObject();
						while (linerObj1) {
							collisionStack.emplace_back(linerObj1);
							addLinerObjectNum++;
							linerObj1 = linerObj1->mNextLinerObject;
						}
					}
					isAddThisSpaceLinerObject = true;

					collisionStack = RecursionSearchTree<Policy>(std::move(collisionStack), nextSpaceCellNum);
				}
			}

			if (isAddThisSpaceLinerObject)
				for (int i = 0; i < addLinerObjectNum; i++)
					collisionStack.pop_back();

			return std::move(collisionStack);
		}

		//SpaceCellÇÃhasLinerObjectFlagÇóßÇƒÇÈ
		void ConveyResidtLinerObject(int spaceNum) {
			while (!mSpaceCellArray[spaceNum]->mHasLinerObject) {
				mSpaceCellArray[spaceNum]->mHasLinerObject = true;

				spaceNum = (spaceNum - 1) >> 2;
				if (spaceNum < 0)
					break;
			}
		}

	public:
		SpaceDivisionTree()
			:mSpaceCellArray()
			,mCollisionStack()
		{
			for (int i = 0; i < MAX_SPACECELL_NUM; i++)
				mSpaceCellArray[i] = new SpaceCell<Collider>();

			mCollisionStack.reserve(30);
		}
		~SpaceDivisionTree() {
			for (int i = 0; i < MAX_SPACECELL_NUM; i++)
				if (mSpaceCellArray[i])
					delete mSpaceCellArray[i];
		}

		void SearchTree() {

			CollisionDetectionSettingImpl::ColcMembers();
			ResetHasLinerObject(0);
			ColliderManager::RegistSpaceDivisionTree(*this);
			
			mCollisionStack.clear();
			mCollisionStack = RecursionSearchTree<ColiisionDetectionPolicy>(std::move(mCollisionStack), 0);
			
		}

		void Regist(LinerObject<T>* obj, int num) {
			ConveyResidtLinerObject(num);
			mSpaceCellArray[num]->Push(obj);
		}

		//SpacecellÇÃHasLinerObjectFlagÇëSïîâ∫Ç∞ÇÈ
		void ResetHasLinerObject(int spaceNum) {

			if (mSpaceCellArray[spaceNum]->mHasLinerObject) {
				mSpaceCellArray[spaceNum]->mHasLinerObject = false;
				for (int i = 0; i < 4; i++) {
					int childNum = spaceNum * 4 + 1 + i;
					if (childNum < MAX_SPACECELL_NUM && mSpaceCellArray[childNum]->mHasLinerObject)
						ResetHasLinerObject(childNum);
					
				}
			}
			
		}
		
	};


}