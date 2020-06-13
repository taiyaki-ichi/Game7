#pragma once
#include<optional>

namespace dev
{

	template<typename T>
	class LinerObject
	{
		T* mPtr;

	public:
		LinerObject<T>* mPreLinerObject;
		LinerObject<T>* mNextLinerObject;

		LinerObject(T* obj)
			:mPtr(obj)
			, mPreLinerObject(nullptr)
			, mNextLinerObject(nullptr)
		{}
		~LinerObject() = default;

		T* GetPtr() const noexcept {
			return mPtr;
		}

	};
}