#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"StageStateManager.hpp"

namespace Stage
{
	template<typename T>
	class StateManager;

	template<typename T=char>
	class StateBase : public GameLib::Actor
	{
		T mFlags;

	public:
		StateBase(StateManager<T>* manger)
			:GameLib::Actor{manger}
			, mFlags{0}
		{}
		virtual ~StateBase() = default;

		virtual void Active() = 0;
		virtual void Pause() = 0;

		bool CheckFlag(T flag) {
			return mFlags & flag;
		}
		void UpFlag(T flag) {
			mFlags |= flag;
		}
		void DownFlag(T flag) {
			mFlags &= ~flag;
		}

	};


}