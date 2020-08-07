#pragma once
#include"ActorEditor/ActorEditorBase.hpp"

namespace StageEditor
{
	struct BeginWorkingPolicy {
		void operator()(GameLib::Actor* actor) {
			auto actorEditorPtr = static_cast<ActorEditorBase*>(actor);
			actorEditorPtr->BeginWorking();
		}
	};

	struct BeginToRestPolicy {
		void operator()(GameLib::Actor* actor) {
			auto actorEditorPtr = static_cast<ActorEditorBase*>(actor);
			actorEditorPtr->BeginToRest();
		}
	};
}