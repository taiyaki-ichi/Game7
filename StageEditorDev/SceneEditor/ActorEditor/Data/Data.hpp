#pragma once
#include<vector>
#include<utility>

namespace StageEditor
{

	template<typename T>
	class Data
	{
		int mDataNum;
		std::vector<T> mData;

	public:
		Data(int dataNum)
			:mDataNum{ dataNum }
			, mData{}
		{}
		virtual ~Data() = default;

		void AddData(T&& pos) {
			if (mData.size() < mDataNum)
				mData.emplace_back(std::move(pos));
		}

		//データが有効な値で埋められているかどうか
		bool IsOK() const {
			return mData.size() >= mDataNum;
		}

		int GetDataNum() const {
			return mData.size();
		}

		int GetMaxDataNum() const{
			return mDataNum;
		}

		const T& operator[](int n) const {
			return mData[n];
		}
	};


}