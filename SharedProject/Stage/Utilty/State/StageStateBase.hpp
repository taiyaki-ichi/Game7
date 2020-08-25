#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"StageStateManager.hpp"

namespace Stage
{
	template<typename T>
	class StateManager;

	//çXêVÇ∑ÇÈÇ©ÇµÇ»Ç¢Ç©Çç◊Ç©Ç≠í≤êÆÇµÇΩÇ¢ÇÃÇ≈ActorÇ©ÇÁîhê∂Ç≥ÇπÇ»Ç¢
	template<typename T=unsigned char>
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

		virtual bool UpdateOrNot() {
			return true;
		}

		StateBase<T>* UpdateState() {
			if (UpdateOrNot())
				return Update();
			else
				return this;
		}

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