#pragma once
#include"ActorBase.hpp"

namespace Game::Stage
{
	class WorpGateBase : public ActorBase
	{
		std::string mThisNameTag;
		std::string mDestinationNameTag;

	public:
		WorpGateBase(Scene* scene, std::string&& worpGateType);
		virtual ~WorpGateBase() = default;

		void SetStringInfo(std::string&& nameTag, std::string&& destinationNameTag);
	};
}