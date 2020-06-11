#pragma once
#include<optional>

namespace GameLib
{
	class LinerObject;
	class SpaceCell
	{
		std::optional<LinerObject*> mFirstLinerObject;
		int mThisSpaceNumber;

	public:
		SpaceCell(int spaceNum);
		~SpaceCell();


		//この分割空間にオブジェクトを追加
		bool Push(LinerObject* obj);

		const std::optional<LinerObject*>& GetFirstLinerObject() const noexcept;

	};
}