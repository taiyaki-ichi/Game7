#pragma once
#include<vector>
#include<algorithm>
#include<iostream>

namespace GameLib
{

	template<typename T>
	struct Node {
		T* ptr;
		int order;
	};

	template<typename T>
	class Manager
	{

		std::vector<Node<T>> mNodes;


	public:
		Manager() = default;
		virtual ~Manager() {
			while (!mNodes.empty()) {
				auto ptr = mNodes.back().ptr;
				mNodes.pop_back();
				delete ptr;
			}
		}

		//èáî‘ïtÇ´
		void Add(Node<T>&& node) {

			auto iter = mNodes.begin();
			for (; iter != mNodes.end(); iter++)
				if (node.order < iter->order)
					break;
			mNodes.insert(iter, node);
		}

		//éwíËÇµÇ»Ç¢èÍçáÅAèáî‘ÇÕ0
		void Add(T* ptr) {
			Add({ ptr,0 });
		}

		void Remove(T* ptr) {
			auto iter = mNodes.begin();
			for (; iter != mNodes.end(); iter++)
				if (ptr == iter->ptr)
					break;
			if (iter!=mNodes.end())
				mNodes.erase(iter);
		}

		template<typename Policy>
		void Invoke() {
			for (auto node : mNodes)
				//Policy::func(node.ptr);
				Policy()(node.ptr);
		}

		void SetOrder(T* ptr, int order) {
			Remove(ptr);
			Add({ ptr,order });
		}

	};

}