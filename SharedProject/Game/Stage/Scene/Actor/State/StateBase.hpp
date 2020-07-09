#pragma once

namespace Game::Stage
{

	class StateBase
	{
	public:
		StateBase() = default;
		virtual ~StateBase() = default;

		virtual StateBase* Update() {
			return this;
		}

		virtual int GetFlag() {
			return 0;
		}

		virtual void Active() = 0;
		virtual void Pause() = 0;
	};

}