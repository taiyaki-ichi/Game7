#pragma once
#include"lib/include/CollisionDetection/Collider.hpp"
#include<optional>

namespace GameLib
{

	//空間オブジェクトに紐づけるよう
	class LinerObject
	{
		Collider* mCollider;

	public:
		LinerObject(Collider* collidr)
			:mCollider(collidr)
			,mPreObject(std::nullopt)
			,mNextObject(std::nullopt)
		{}
		~LinerObject() = default;

		//前と後ろ
		std::optional<LinerObject*> mPreObject;
		std::optional<LinerObject*> mNextObject;

		Collider* GetCollider() const noexcept {
			return mCollider;
		}
	};

}