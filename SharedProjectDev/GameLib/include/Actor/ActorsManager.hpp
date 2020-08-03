#pragma once
#include"GameLib/include/Manager/Manager.hpp"
#include"Actor.hpp"
#include<vector>

namespace GameLib
{
	class Actor;

	template<typename T>
	class ActorsManager : public OwnerManager<T>
	{
	public:
		ActorsManager()
			:OwnerManager<T>()
		{}
		virtual ~ActorsManager() = default;

		void DeleteDeadActors() {
			std::vector<Node<T>> deadActors{};
			std::remove_copy_if(OwnerManager<T>::mNodes.begin(), OwnerManager<T>::mNodes.end(), std::back_inserter(deadActors),
				[](Node<T>& node) {return node.Ptr->GetState() != Actor::State::Dead; });
			
			while (!deadActors.empty()) {
				auto ptr = deadActors.back().Ptr;
				deadActors.pop_back();
				delete ptr;
			}
			
		}
	};
}