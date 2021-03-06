#pragma once
#include"LinerObject.hpp"

namespace GameLib
{
	template<typename T>
	class SpaceCell
	{
		LinerObject<T>* mFirstLinerObject;

	public:

		//木の構造のこのSpaceCellや子や孫にLinerObjectを持つかどうか
		bool mHasLinerObject;

		SpaceCell()
			:mFirstLinerObject(nullptr)
			,mHasLinerObject(false)
		{}
		~SpaceCell() = default;

		void Push(LinerObject<T>* obj) {
			obj->mSpaceCell = this;

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

		void RemoveList(LinerObject<T>* obj) {
			if (mFirstLinerObject == obj) {
				mFirstLinerObject = obj->mNextLinerObject;
				if (mFirstLinerObject)
					mFirstLinerObject->mPreLinerObject = nullptr;
			}
			else {
				if (obj->mPreLinerObject)
					obj->mPreLinerObject->mNextLinerObject = obj->mNextLinerObject;

				if (obj->mNextLinerObject)
					obj->mNextLinerObject->mPreLinerObject = obj->mPreLinerObject;
			}
		}
	};
}