#pragma once
#include"Actor/StageActorBase.hpp"

namespace Stage
{
	struct ActivePolicy {
		void operator()(GameLib::Actor* actor) {
			auto stageActorPtr = static_cast<ActorBase*>(actor);
			stageActorPtr->Active();
		}
	};

	struct PausePolicy {
		void operator()(GameLib::Actor* actor) {
			auto stageActorPtr = static_cast<ActorBase*>(actor);
			stageActorPtr->Pause();
		}
	};
}