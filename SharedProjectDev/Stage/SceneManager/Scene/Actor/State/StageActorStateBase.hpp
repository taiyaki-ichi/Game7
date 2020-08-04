#pragma once

namespace Stage
{

	class StateBase
	{
		char mFlags;

	public:
		StateBase()
			:mFlags{0}
		{}
		virtual ~StateBase() = default;

		virtual StateBase* Update() {
			return this;
		}

		virtual void Active() = 0;
		virtual void Pause() = 0;

		bool CheckFlag(char flag) {
			return mFlags & flag;
		}
		void UpFlag(char flag) {
			mFlags |= flag;
		}
		void DownFlag(char flag) {
			mFlags &= ~flag;
		}

	};

}