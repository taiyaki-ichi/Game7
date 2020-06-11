#pragma once

namespace GameLib
{
	class LinerObject;

	class SpaceCell
	{
		LinerObject* mFirstLinerObject;
		int mThisSpaceNumber;

	public:
		SpaceCell(int spaceNum);
		~SpaceCell();


		//この分割空間にオブジェクトを追加
		bool Push(LinerObject* obj);

		LinerObject* GetFirstLinerObject() const noexcept {
			return mFirstLinerObject;
		}
	};
}