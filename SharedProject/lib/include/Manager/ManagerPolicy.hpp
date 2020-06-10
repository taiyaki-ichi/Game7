#pragma once
#include"Node.hpp"

namespace GameLib
{

	template<typename T>
	struct OwnerManagerDestructorPolicy {
		void operator()(std::vector<Node<T>>&& nodes) {
			while (!nodes.empty()) {
				auto ptr = nodes.back().Ptr;
				nodes.pop_back();
				delete ptr;
			}
		}
	};

	template<typename T>
	struct WeakManagerDestructorPolicy {
		void operator()(std::vector<Node<T>>&& nodes) {
			nodes.clear();
		}
	};

	template<typename T>
	struct DefaltRemovePolicy {
		bool operator()(T* removePtr, T* checkPtr) {
			if (removePtr == checkPtr)
				return true;
			else
				return false;
		}
	};
}