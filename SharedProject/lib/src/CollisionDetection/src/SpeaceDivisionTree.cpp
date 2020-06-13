#include"lib/src/CollisionDetection/SpaceDivisionTree.hpp"
#include"lib/src/CollisionDetection/LinerObject.hpp"
#include"lib/src/CollisionDetection/CollisionDetectionSettingImpl.hpp"
#include"lib/include/CollisionDetection/Collider.hpp"
#include"lib/src/CollisionDetection/MortonNumber.hpp"
#include"lib/include/Math/Vector2Func.hpp"
#include"lib/src/CollisionDetection/SpaceCell.hpp"

#include<iostream>
#include "..\SpaceDivisionTree.hpp"

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
		:mSpaceCellArray()
	{
		mSpaceCellArray[0] = SpaceCell(0);
		for (int i = 1; i < MAX_SPACECELL_NUM; i++) {
			mSpaceCellArray[i] = std::nullopt;
		}
		
	}

	SpaceDivisionTree::~SpaceDivisionTree()
	{
	}

	bool SpaceDivisionTree::Resist(LinerObject* linerObj)
	{
		linerObj->mNextObject = std::nullopt;
		linerObj->mPreObject = std::nullopt;

		auto collider = linerObj->GetCollider();
		float scale = collider->GetScale();
		float width = collider->GetWidth();
		float heigth = collider->GetHeigth();
		auto pos = collider->GetPosition();

		//squrt使って精密にやるか？？
		float halfUnitSize = (width * scale + heigth * scale) / 2.f;

		int spaceCellNum = GetMortonNumber(pos.x - halfUnitSize, pos.y - halfUnitSize, pos.x + halfUnitSize, pos.y + halfUnitSize);
		if (spaceCellNum < CollisionDetectionSettingImpl::GetNowLevelCellNum())
		{
			//空間オブジェクトがない場合作成
			if (!mSpaceCellArray[spaceCellNum])
				CreateNewSpaceCell(spaceCellNum);

			return mSpaceCellArray[spaceCellNum].value().Push(linerObj);
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
		while (!mSpaceCellArray[spaceNum])
		{
			mSpaceCellArray[spaceNum] = SpaceCell(spaceNum);

			//親空間へ
			spaceNum = (spaceNum - 1) >> 2;
			if (spaceNum >=CollisionDetectionSettingImpl::GetNowLevelCellNum());
				break;
		}
	}

	void SpaceDivisionTree::DeleteSpaceCell(int spaceNum)
	{
		
		/*
		for (int i = 0; i < 4; i++)
		{
			int childNum = spaceNum * 4 + 1 + i;
			if (childNum < MAX_SPACECELL_NUM && mSpaceCellArray[childNum]) {
				DeleteSpaceCell(childNum);
				delete mSpaceCellArray[childNum].value();
				mSpaceCellArray[childNum] = std::nullopt;
				std::cout << "a";
			}
		}
		*/
		for(int i=1;i< MAX_SPACECELL_NUM;i++)
			if (mSpaceCellArray[i]) 
				mSpaceCellArray[i] = std::nullopt;

	}

	int SpaceDivisionTree::GetCellNum()
	{
		int sum = 0;
		for (int i = 0; i < CollisionDetectionSettingImpl::GetNowLevelCellNum(); i++) 
			if (mSpaceCellArray[i])
				sum++;

		return sum;
	}


	std::list<LinerObject*> SpaceDivisionTree::RecursionSearchTree(std::list<LinerObject*>&& collisionStack, int speaceCellNum)
	{
		std::optional<LinerObject*> linerObj1 = mSpaceCellArray[0].value().GetFirstLinerObject();
		std::optional<LinerObject*> linerObj2 = std::nullopt;

		while (linerObj1)
		{
			//mSpeaceCellArrayに連なる線形リストとの当たり判定(linerObj1以降の線形リスト)
			//すなわち同じ分割された空間内のColliderとの当たり判定
			linerObj2 = linerObj1.value()->mNextObject;
			while (linerObj2)
			{
				DoCollisionDetection(linerObj1.value(), linerObj2.value());
				linerObj2 = linerObj2.value()->mNextObject;
				//std::cout << "a";
				
			}

			//collisionStackにあるColliderとの当たり判定、つまり
			//linerObj1が属する分割された空間にまたがるような、また
			//linerObj1が属する分割された空間より大きな分割空間に属するColliderとの当たり判定
			if (!collisionStack.empty())
			{
				for (auto linerObj : collisionStack)
				{
					DoCollisionDetection(linerObj1.value(), linerObj);
				}
			}

			linerObj1 = linerObj1.value()->mNextObject;
		}
		//speaceCellNumの子空間の処理
		//子空間に井熊にこのspeaceCellNum番目の空間のLinerObjectをCollisionStackに入れたかどうか
		bool childFlag = false;
		//子空間のオブジェクトの数
		unsigned int objNum = 0;
		//unsigned int i;
		unsigned int nextSpaceCellNum;
		int levelNum = CollisionDetectionSettingImpl::GetNowLevelCellNum();
		for (int i = 0; i < 4; i++)
		{
			nextSpaceCellNum = speaceCellNum * 4 + 1 + i;
			if (nextSpaceCellNum < levelNum&&mSpaceCellArray[nextSpaceCellNum])
			{
				if (childFlag == false) {
					linerObj1 = mSpaceCellArray[speaceCellNum].value().GetFirstLinerObject();
					while (linerObj1) {
						collisionStack.emplace_back(linerObj1.value());
						objNum++;
						linerObj1 = linerObj1.value()->mNextObject;
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