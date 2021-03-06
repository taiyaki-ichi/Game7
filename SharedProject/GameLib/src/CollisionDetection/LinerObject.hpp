#pragma once

namespace GameLib
{
	template<typename T>
	class SpaceCell;

	template<typename T>
	class LinerObject
	{
		T* mPtr;

	public:
		LinerObject<T>* mPreLinerObject;
		LinerObject<T>* mNextLinerObject;
		//所属する空間
		SpaceCell<T>* mSpaceCell;

		LinerObject(T* obj)
			:mPtr(obj)
			, mPreLinerObject(nullptr)
			, mNextLinerObject(nullptr)
			,mSpaceCell(nullptr)
		{}
		~LinerObject() = default;

		T* GetPtr() const noexcept {
			return mPtr;
		}

		void RemoveSpaceCell() {
			if (mSpaceCell)
				mSpaceCell->RemoveList(this);
			mPreLinerObject = nullptr;
			mNextLinerObject = nullptr;
		}

	};
}