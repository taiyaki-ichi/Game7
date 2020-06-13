#pragma once
#include<array>
#include<iostream>
#include"SpaceCell2.hpp"

namespace dev
{
	constexpr int LEVEL = 2;
	constexpr int SPACECELL_NUM = 21;

	template<typename T>
	class SpaceDivisionTree
	{
		std::array<std::optional<SpaceCell<T>>, SPACECELL_NUM> mSpaceCellArray;

	public:
		SpaceDivisionTree()
			:mSpaceCellArray()
		{
			mSpaceCellArray[0] = SpaceCell<T>();
			for (int i = 1; i < SPACECELL_NUM; i++)
				mSpaceCellArray[i] = std::nullopt;
		}
		~SpaceDivisionTree() = default;



		void Regist(LinerObject<T>&& obj, int num) {
			if (!mSpaceCellArray[num])
				CreateNewSpaceCell(num);

			mSpaceCellArray[num].value().Push(std::move(obj));
		}

		void CreateNewSpaceCell(int spaceNum) {
			while (!mSpaceCellArray[spaceNum])
			{
				mSpaceCellArray[spaceNum] = SpaceCell<T>();
				//e‹óŠÔ‚Ö
				spaceNum = (spaceNum - 1) >> 2;
				if (spaceNum >= SPACECELL_NUM);
				break;
			}
		}

		void DeleteSpaceCell(int spaceNum = 0) {
			for (int i = 0; i < 4; i++) {
				int childNum = spaceNum * 4 + 1 + i;
				if (mSpaceCellArray[childNum]) {
					DeleteSpaceCell(childNum);
					mSpaceCellArray[childNum] = std::nullopt;
				}
			}
		}

		void PrintArray() {
			for (int i = 0; i < SPACECELL_NUM; i++) {
				std::cout << i << " : ";
				if (mSpaceCellArray[i])
					std::cout << "1\n";
				else
					std::cout << "0\n";
			}
			
		}

	};

}
