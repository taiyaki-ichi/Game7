#pragma once
#include"Actor/StageActorBase.hpp"

namespace Stage
{
	struct BeginWorkingPolicy {
		void operator()(GameLib::Actor* actor) {
			auto stageActorPtr = static_cast<ActorBase*>(actor);
			stageActorPtr->BeginWorking();
		}
	};

	struct BeginToRestPolicy {
		void operator()(GameLib::Actor* actor) {
			auto stageActorPtr = static_cast<ActorBase*>(actor);
			stageActorPtr->BeginToRest();
		}
	};
}