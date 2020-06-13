#pragma once
#include<vector>
#include"SpaceCell.hpp"
#include"CollisionDetectinPolicy.hpp"

namespace GameLib
{

	constexpr int TREE_LEVEL = 4;
	constexpr int POWER_OF_FOUR[11] = { 1,4,16,64,256,1024,4096,16384,65536,262144,1048576 };
	constexpr int MAX_SPACECELL_NUM = (POWER_OF_FOUR[TREE_LEVEL + 1] - 1) / 3;

	
	template<typename T>
	class SpaceDivisionTree
	{
		SpaceCell<T>* mSpaceCellArray[MAX_SPACECELL_NUM];
		std::vector<LinerObject<T>*> mCollisionStack;

		//SerchTreeの再帰用
		template<typename Policy>
		std::vector<LinerObject<T>*> RecursionSearchTree(std::vector<LinerObject<T>*>&& collisionStack, int speaceCellNum) {
			LinerObject<T>* linerObj1 = mSpaceCellArray[speaceCellNum]->GetFirstLinerObject();
			LinerObject<T>* linerObj2 = nullptr;

			while (linerObj1)
			{
				linerObj2 = linerObj1->mNextLinerObject;
				while (linerObj2)
				{
					//////////////////////////////////////////////////////////////////////////////
					collisionDetectionNum++;
					Policy()(linerObj1->GetPtr(), linerObj2->GetPtr());
					linerObj2 = linerObj2->mNextLinerObject;
				}

				if (!collisionStack.empty())
					for (auto& linerObj : collisionStack) {
						///////////////////////////////////////////////////////////////////////////
						collisionDetectionNum++;
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

		//SpaceCellのhasLinerObjectFlagを立てる
		void ConveyResidtLinerObject(int spaceNum) {
			while (!mSpaceCellArray[spaceNum]->mHasLinerObject) {
				mSpaceCellArray[spaceNum]->mHasLinerObject = true;

				spaceNum = (spaceNum - 1) >> 2;
				if (spaceNum < 0)
					break;
			}
		}

	public:

		//デバック用
		int collisionDetectionNum;

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

		template<typename Policy>
		void SearchTree() {
			collisionDetectionNum = 0;
			//std::cout << mCollisionStack.capacity() << "\n";
			mCollisionStack.clear();
			mCollisionStack = RecursionSearchTree<Policy>(std::move(mCollisionStack), 0);
			std::cout << "collisiodetectiionnum : " << collisionDetectionNum << "\n";
		}

		void Regist(LinerObject<T>* obj, int num) {
			ConveyResidtLinerObject(num);
			mSpaceCellArray[num]->Push(obj);
		}

		//SpacecellのHasLinerObjectFlagを全部下げる
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