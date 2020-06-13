#pragma once
#include<list>
#include<algorithm>
#include<iostream>
#include"ManagerPolicy.hpp"

namespace GameLib
{

	template<typename T,typename DestructorPolicy>
	class ManagerBase;

	//このManagerのデストラクタが呼ばれた際コンテナ内にあるポインタの開放も担う
	template<typename T>
	using OwnerManager = ManagerBase<T, OwnerManagerDestructorPolicy<T>>;

	//このManagerのデストラクタが呼ばれてもコンテナにあるポインタは開放されない
	template<typename T>
	using WeakManager = ManagerBase<T, WeakManagerDestructorPolicy<T>>;



	template<typename T,typename DestructorPolicy>
	class ManagerBase
	{

		std::list<Node<T>> mNodes;


	public:
		ManagerBase() = default;
		virtual ~ManagerBase() {
			DestructorPolicy()(std::move(mNodes));
		}

		//順番指定
		void Add(Node<T>&& node) {

			auto iter = mNodes.begin();
			for (; iter != mNodes.end(); iter++)
				if (node.Order < iter->Order)
					break;
			mNodes.insert(iter, node);
		}

		//指定しない場合、順番は0
		void Add(T* ptr) {
			Add({ ptr,0 });
		}

		template<typename U,typename RemovePolicy=DefaltRemovePolicy<U>>
		void Remove(U* ptr) {
			auto iter = mNodes.begin();
			for (; iter != mNodes.end(); iter++)
				if (RemovePolicy()(ptr,iter->Ptr))
					break;
			if (iter!=mNodes.end())
				mNodes.erase(iter);
		}

		template<typename Policy>
		void Invoke() {
			auto iter = mNodes.begin();
			while (iter != mNodes.end()) {
				if (iter->Ptr) {
					Policy()(iter->Ptr);
					iter++;
				}
				else
					iter = mNodes.erase(iter);
			}
			
		}

		void SetOrder(T* ptr, int order) {
			Remove(ptr);
			Add({ ptr,order });
		}

	};


}