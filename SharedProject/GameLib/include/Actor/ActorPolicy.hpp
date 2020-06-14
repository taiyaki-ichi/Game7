#pragma once
#include"Actor.hpp"

namespace GameLib
{
	template<typename T>
	struct UpdatePolicy {
		void operator()(T* actor) {
			if (actor->GetState() == T::State::Active)
				actor->Update();
		}
	};

	template<typename T>
	struct DeadObjectDeletePolicy {
		void operator()(T* actor) {
			if (actor->GetState() == T::State::Dead)
				delete actor;
		}
	};
}
