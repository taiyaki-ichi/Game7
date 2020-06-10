#pragma once
#include<list>

namespace GameLib
{

	class LinerObject;

	class SpaceDivisionTree
	{
		LinerObject** mSpeaceCellArray;
		int mAllSpeaceCellNum;

	public:
		SpaceDivisionTree();
		~SpaceDivisionTree();

		//木に登録
		bool Resist(LinerObject* linerObj);

		//木を操作し、当たり判定を実行
		void SearchTree();

		//木をリセット
		void Reset();

	private:
		//SearcheTreeで再帰的に使用
		std::list<LinerObject*> RecursionSearchTree(std::list<LinerObject*>&& collisionStack, int speaceCellNum);

		//リストに登録
		void ResistListTail(LinerObject* resistObj, LinerObject* listObj);

	};
}