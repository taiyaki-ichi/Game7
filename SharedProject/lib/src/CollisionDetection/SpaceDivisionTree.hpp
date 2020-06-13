#pragma once
#include<list>
#include<array>
#include<optional>
#include"CollisionDetectionSettingImpl.hpp"
#include"SpaceCell.hpp"

namespace GameLib
{

	class LinerObject;
	class SpaceCell;
		
	class SpaceDivisionTree
	{
		std::array<std::optional<SpaceCell>, MAX_SPACECELL_NUM> mSpaceCellArray;

	public:
		SpaceDivisionTree();
		~SpaceDivisionTree();

		//木に登録
		bool Resist(LinerObject* linerObj);

		//木を操作し、当たり判定を実行
		void SearchTree();

		void CreateNewSpaceCell(int spaceNum);
		//spaceNumよりも子空間をdelete
		void DeleteSpaceCell(int spaceNum);

		//
		int GetCellNum();

	private:
		//SearcheTreeで再帰的に使用
		std::list<LinerObject*> RecursionSearchTree(std::list<LinerObject*>&& collisionStack, int speaceCellNum);

		

	};
}