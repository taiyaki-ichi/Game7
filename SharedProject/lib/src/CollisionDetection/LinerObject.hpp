#pragma once

namespace GameLib
{
	class Collider;

	//空間オブジェクトに紐づけるよう
	class LinerObject
	{
		Collider* mCollider;

	public:
		LinerObject(Collider* collidr)
			:mCollider(collidr)
			,mPreObject(nullptr)
			,mNextObject(nullptr)
		{}
		~LinerObject() = default;

		//前と後ろ
		LinerObject* mPreObject;
		LinerObject* mNextObject;

		Collider* GetCollider() const noexcept {
			return mCollider;
		}
	};

}