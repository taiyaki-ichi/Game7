#pragma once
#include"LinerObject.hpp"

namespace GameLib
{
	template<typename T>
	class SpaceCell
	{
		LinerObject<T>* mFirstLinerObject;

	public:
		SpaceCell()
			:mFirstLinerObject(nullptr)
		{}
		~SpaceCell() = default;

		void Push(LinerObject<T>* obj) {
			if (!mFirstLinerObject)
				mFirstLinerObject = obj;
			else
			{
				obj->mNextLinerObject = mFirstLinerObject;
				mFirstLinerObject->mPreLinerObject = obj;
				mFirstLinerObject = obj;
			}
		}

		LinerObject<T>* GetFirstLinerObject() const noexcept {
			return mFirstLinerObject;
		}
	};
}