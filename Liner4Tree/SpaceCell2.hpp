#pragma once
#include"LinerObject2.hpp"

namespace dev
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