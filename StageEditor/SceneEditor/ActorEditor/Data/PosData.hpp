#pragma once
#include"GameLib/include/Math/Vector2.hpp"
#include<vector>

namespace StageEditor
{
	class PosData
	{
		int mSize;
		std::vector<GameLib::Vector2> mPosData;

		//末尾の要素が確定されたデータかどうか
		bool mDefinedBackData;

	public:
		PosData(int size);
		virtual ~PosData() = default;

		//末尾の要素を更新
		void UpdatePosDataBack(GameLib::Vector2&& pos);

		//末尾の要素を確定さす
		void DefinePosDataBeck();

		//データが確定したかどうか
		bool IsOK() const;

		int GetDataNum() const;

		const GameLib::Vector2& operator[](int n) const;
	};
}