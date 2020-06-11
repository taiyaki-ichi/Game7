#include"lib/src/CollisionDetection/SpaceDivisionTree.hpp"
#include"lib/src/CollisionDetection/LinerObject.hpp"
#include"lib/src/CollisionDetection/CollisionDetectionSettingImpl.hpp"
#include"lib/include/CollisionDetection/Collider.hpp"
#include"lib/src/CollisionDetection/MortonNumber.hpp"
#include"lib/include/Math/Vector2Func.hpp"
#include"lib/src/CollisionDetection/SpaceCell.hpp"

#include<iostream>

namespace GameLib
{

	//RecursionSearchTree内で使用、当たり判定を行い当たっているならActorに通知
	void DoCollisionDetection(LinerObject* obj1, LinerObject* obj2)
	{
		auto collider1 = obj1->GetCollider();
		auto collider2 = obj2->GetCollider();

		float s1 = collider1->GetScale();
		float s2 = collider2->GetScale();

		auto vecs1 = GetRectangleVectors(collider1->GetPosition(), collider1->GetWidth() * s1, collider1->GetWidth() * s1, collider1->GetRotation());
		auto vecs2 = GetRectangleVectors(collider2->GetPosition(), collider2->GetWidth() * s2, collider2->GetWidth() * s2, collider2->GetRotation());

		if (CollisionDetection(std::move(vecs1), std::move(vecs2)))
		{
			collider1->HitCollider(*collider2);
			collider2->HitCollider(*collider1);
		}
	}


	SpaceDivisionTree::SpaceDivisionTree()
	{
		mAllSpaceCellNum = (CollisionDetectionSettingImpl::GetPowerOfFour(TREE_MAX_LEVEL+1) - 1) / 3;
		mSpaceCellArray = new SpaceCell * [mAllSpaceCellNum];
		mSpaceCellArray[0] = new SpaceCell(0);
		for (int i = 1; i < mAllSpaceCellNum; i++) {
			mSpaceCellArray[i] = nullptr;
		}
		
	}

	SpaceDivisionTree::~SpaceDivisionTree()
	{
		DeleteSpaceCell(0);
		delete mSpaceCellArray[0];
		delete[] mSpaceCellArray;
	
	}

	bool SpaceDivisionTree::Resist(LinerObject* linerObj)
	{
		linerObj->mNextObject = nullptr;
		linerObj->mNextObject = nullptr;

		auto collider = linerObj->GetCollider();
		float scale = collider->GetScale();
		float width = collider->GetWidth();
		float heigth = collider->GetHeigth();
		auto pos = collider->GetPosition();

		//squrt使って精密にやるか？？
		float halfUnitSize = (width * scale + heigth * scale) / 2.f;

		int spaceCellNum = GetMortonNumber(pos.x - halfUnitSize, pos.y + halfUnitSize, pos.x + halfUnitSize, pos.y - halfUnitSize);

		if (spaceCellNum < mAllSpaceCellNum)
		{
			//空間オブジェクトがない場合作成
			if (!mSpaceCellArray[spaceCellNum])
				CreateNewSpaceCell(spaceCellNum);

			mSpaceCellArray[spaceCellNum]->Push(linerObj);

			return true;
		}

		return false;
	}

	void SpaceDivisionTree::SearchTree()
	{
		std::list<LinerObject*> collisionStack;
		RecursionSearchTree(std::move(collisionStack), 0);
	}

	void SpaceDivisionTree::CreateNewSpaceCell(int spaceNum)
	{
		while (mSpaceCellArray[spaceNum] == nullptr)
		{
			mSpaceCellArray[spaceNum] = new SpaceCell(spaceNum);

			//親空間へ
			spaceNum = (spaceNum - 1) >> 2;
			if (spaceNum >= mAllSpaceCellNum)
				break;
		}
	}

	void SpaceDivisionTree::DeleteSpaceCell(int spaceNum)
	{
		for (int i = 0; i < 4; i++)
		{
			int childNum = spaceNum * 4 + 1 + i;
			if (childNum < mAllSpaceCellNum && !mSpaceCellArray[childNum]) {
				DeleteSpaceCell(childNum);
				delete mSpaceCellArray[childNum];
			}
		}

	}


	std::list<LinerObject*> SpaceDivisionTree::RecursionSearchTree(std::list<LinerObject*>&& collisionStack, int speaceCellNum)
	{
		LinerObject* linerObj1 = mSpaceCellArray[0]->GetFirstLinerObject();
		LinerObject* linerObj2 = nullptr;

		while (linerObj1)
		{
			//mSpeaceCellArrayに連なる線形リストとの当たり判定(linerObj1以降の線形リスト)
			//すなわち同じ分割された空間内のColliderとの当たり判定
			linerObj2 = linerObj1->mNextObject;
			while (linerObj2)
			{
				DoCollisionDetection(linerObj1, linerObj2);
				linerObj2 = linerObj2->mNextObject;
			}

			//collisionStackにあるColliderとの当たり判定、つまり
			//linerObj1が属する分割された空間にまたがるような、また
			//linerObj1が属する分割された空間より大きな分割空間に属するColliderとの当たり判定
			if (!collisionStack.empty())
			{
				for (auto linerObj : collisionStack)
				{
					DoCollisionDetection(linerObj1, linerObj);
				}
			}

			linerObj1 = linerObj1->mNextObject;
		}
		
		//speaceCellNumの子空間の処理
		//子空間に井熊にこのspeaceCellNum番目の空間のLinerObjectをCollisionStackに入れたかどうか
		bool childFlag = false;
		//子空間のオブジェクトの数
		unsigned int objNum = 0;
		unsigned int i;
		unsigned int nextSpaceCellNum;

		for (int i = 0; i < 4; i++)
		{
			nextSpaceCellNum = speaceCellNum * 4 + 1 + i;
			//
			if (nextSpaceCellNum < CollisionDetectionSetting::GetLevel()&&mSpaceCellArray[nextSpaceCellNum])
			{
				if (childFlag == false) {
					linerObj1 = mSpaceCellArray[speaceCellNum]->GetFirstLinerObject();
					while (linerObj1) {
						collisionStack.emplace_back(linerObj1);
						objNum++;
						linerObj1 = linerObj1->mNextObject;
					}
				}

				childFlag = true;
				collisionStack = RecursionSearchTree(std::move(collisionStack), nextSpaceCellNum);
			}
		}

		//この関数に戻ってきたらここで追加した分削除
		if (childFlag)
			for (int i = 0; i < objNum; i++)
				collisionStack.pop_back();

		return std::move(collisionStack);
	}





}