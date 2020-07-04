#include"InfoBase.hpp"
#include"StageEditor/EditingActor/EditingActorBase.hpp"

namespace StageEditor
{

	InfoBase::InfoBase(EditingActorBase* owner, std::string&& infoType, std::string&& infoName)
		:GameLib::Actor{ owner }
		, mInfoType{ std::move(infoType) }
		, mInfoName{ std::move(infoName) }
		, mInfoState{ InfoState::Stay }
	{
		owner->AddInfoBase(this);
	}

	void InfoBase::CustomizeUpdate()
	{
		if (mInfoState == InfoState::Editing)
			EditingInfoUpdate();
	}


	bool InfoBase::IsOK()
	{
		return mInfoState == InfoState::Confirmed;
	}

	void InfoBase::Print()
	{
		std::cout << mInfoName << "(" << mInfoType << ") : ";
		if (mInfoState == InfoState::Stay)
			std::cout << " - ";
		else
			PrintInfo();
	}

	void InfoBase::InfoConfirmed()
	{
		mInfoState = InfoState::Confirmed;
	}
}