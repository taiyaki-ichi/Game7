#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"StageStateManager.hpp"

namespace Stage
{
	template<typename T>
	class StateManager;

	//XV‚·‚é‚©‚µ‚È‚¢‚©‚ğ×‚©‚­’²®‚µ‚½‚¢‚Ì‚ÅActor‚©‚ç”h¶‚³‚¹‚È‚¢
	template<typename T=char>
	class StateBase
	{
		T mFlags;

	public:
		StateBase()
			: mFlags{0}
		{}
		virtual ~StateBase() = default;

		virtual void BeginWorking() = 0;
		virtual void BeginToRest() = 0;

		virtual StateBase<T>* Update() { return this; };

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