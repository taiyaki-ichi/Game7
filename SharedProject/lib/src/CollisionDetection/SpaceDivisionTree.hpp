#pragma once
#include<list>
#include"SpaceCell.hpp"
#include"CollisionDetectinPolicy.hpp"

namespace GameLib
{
	constexpr int LEVEL = 6;
	constexpr int SPACECELL_NUM = 1365;

	template<typename T>
	class SpaceDivisionTree
	{
		SpaceCell<T>* mSpaceCellArray[SPACECELL_NUM];


		//SerchTreeÇÃçƒãAóp
		template<typename Policy>
		std::list<LinerObject<T>*> RecursionSearchTree(std::list<LinerObject<T>*>&& collisionStack, int speaceCellNum) {
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
					for (auto linerObj : collisionStack)
						Policy()(linerObj1->GetPtr(), linerObj->GetPtr());

				linerObj1 = linerObj1->mNextLinerObject;
			}

			bool isAddThisSpaceLinerObject = false;
			int addLinerObjectNum = 0;

			for (int i = 0; i < 4; i++)
			{
				int nextSpaceCellNum = speaceCellNum * 4 + 1 + i;
				if (nextSpaceCellNum < SPACECELL_NUM && mSpaceCellArray[nextSpaceCellNum])
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

	public:
		SpaceDivisionTree()
			:mSpaceCellArray()
		{
			mSpaceCellArray[0] = new SpaceCell<T>();
			for (int i = 1; i < SPACECELL_NUM; i++)
				mSpaceCellArray[i] = nullptr;
		}
		~SpaceDivisionTree() {
			for (int i = 0; i < SPACECELL_NUM; i++)
				if (mSpaceCellArray[i])
					delete mSpaceCellArray[i];
		}

		template<typename Policy>
		void SearchTree() {
			delete mSpaceCellArray[0];
			mSpaceCellArray[0] = new SpaceCell<T>();
			std::list<LinerObject<T>*> collsionStack;
			RecursionSearchTree<Policy>(std::move(collsionStack), 0);
		}

		void Regist(LinerObject<T>* obj, int num) {
			if (!mSpaceCellArray[num])
				CreateNewSpaceCell(num);

			mSpaceCellArray[num]->Push(obj);
		}

		void CreateNewSpaceCell(int spaceNum) {
			while (!mSpaceCellArray[spaceNum])
			{
				mSpaceCellArray[spaceNum] = new SpaceCell<T>();
				//êeãÛä‘Ç÷
				spaceNum = (spaceNum - 1) >> 2;
				if (spaceNum >= SPACECELL_NUM)
					break;
			}
		}

		void DeleteSpaceCell(int spaceNum = 0) {
			for (int i = 0; i < 4; i++) {
				int childNum = spaceNum * 4 + 1 + i;
				if (mSpaceCellArray[childNum]) {
					DeleteSpaceCell(childNum);
					delete mSpaceCellArray[childNum];
					mSpaceCellArray[childNum] = nullptr;
				}
			}
		}


	};


}