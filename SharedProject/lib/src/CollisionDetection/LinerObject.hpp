#pragma once

namespace GameLib
{
	class Collider;
	class Cell;

	//空間オブジェクトに紐づけるよう
	class LinerObject
	{
		Collider* mCollider;

	public:
		LinerObject(Collider* collidr)
			:mCollider(collidr)
		{}
		~LinerObject() = default;

		//前と後ろ
		LinerObject* mPreObject;
		LinerObject* mNextObject;

		//所属する空間
		Cell* mCell;

		Collider* GetCollider() const noexcept {
			return mCollider;
		}
	};

}