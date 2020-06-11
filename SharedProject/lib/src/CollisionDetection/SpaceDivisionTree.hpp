#pragma once
#include<list>
#include"CollisionDetectionSettingImpl.hpp"

namespace GameLib
{

	class LinerObject;
	class SpaceCell;
		
	class SpaceDivisionTree
	{
		SpaceCell** mSpaceCellArray;
		int mAllSpaceCellNum;

	public:
		SpaceDivisionTree();
		~SpaceDivisionTree();

		//木に登録
		bool Resist(LinerObject* linerObj);

		//木を操作し、当たり判定を実行
		void SearchTree();

		void CreateNewSpaceCell(int spaceNum);
		//spaceNumよりも子空間をdelete
		void DeleteSpaceCell(int spaceNum = 0);

	private:
		//SearcheTreeで再帰的に使用
		std::list<LinerObject*> RecursionSearchTree(std::list<LinerObject*>&& collisionStack, int speaceCellNum);

		

	};
}