#pragma once
#include<vector>
#include<utility>
#include<optional>
#include<functional>

namespace StageEditor
{

	template<typename T>
	class Data
	{
		int mDataNum;
		std::vector<T> mData;
		std::optional<std::function<bool(int, const T&)>> mDataChecker;
	public:
		Data(int dataNum)
			:mDataNum{ dataNum }
			, mData{}
			, mDataChecker{std::nullopt}
		{}
		virtual ~Data() = default;

		void AddData(T&& pos) {
			if (mData.size() < mDataNum)
				if (!mDataChecker || mDataChecker.value()(mData.size(), pos))
					mData.emplace_back(std::move(pos));
		}

		void SetDataCecker(std::optional<std::function<bool(int, const T&)>>&& dataChecker)
		{
			mDataChecker = std::move(dataChecker);
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