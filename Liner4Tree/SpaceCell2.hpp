#pragma once
#include"LinerObject2.hpp"

namespace dev
{
	template<typename T>
	class SpaceCell
	{
		std::optional<LinerObject<T>> mFirstObject;

	public:
		SpaceCell()
			:mFirstObject(std::nullopt)
		{}
		~SpaceCell() = default;

		void Push(LinerObject<T>&& obj) {
			if (mFirstObject)
				mFirstObject = std::move(obj);
			else
			{
				obj.mNextLinerObject = &(mFirstObject.value());
				mFirstObject.value().mPreLinerObject = &obj;
				mFirstObject = std::move(obj);
			}
		}
	};
}