#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<string>

namespace StageEditor
{
	class InfoBase;

	class EditingActorBase : public GameLib::Actor
	{
		std::string mNameTag;

		std::vector<InfoBase*> mInfoBases;

		int mEditingInfoBaseNum;


	public:
		EditingActorBase(GameLib::Actor* owner,std::string nameTag);
		virtual ~EditingActorBase() = default;

		void CustomizeUpdate() override;

		void AddInfoBase(InfoBase* infoBase);

		bool IsOk();

	};
}