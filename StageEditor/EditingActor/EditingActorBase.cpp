#include"EditingActorBase.hpp"
#include"Info/InfoBase.hpp"

namespace StageEditor
{
	EditingActorBase::EditingActorBase(GameLib::Actor* owner, std::string nameTag)
		:GameLib::Actor{owner}
		, mNameTag{std::move(mNameTag)}
		, mInfoBases{}
		, mEditingInfoBaseNum{0}
	{

	}
	void EditingActorBase::CustomizeUpdate()
	{
		std::system("cls");
		std::for_each(mInfoBases.begin(), mInfoBases.end(), [](InfoBase* base) {
			base->Print(); });

		if (mEditingInfoBaseNum < mInfoBases.size()&& mInfoBases[mEditingInfoBaseNum]->IsOK()) 
			mEditingInfoBaseNum++;
		
	}
	void EditingActorBase::AddInfoBase(InfoBase* infoBase)
	{
		mInfoBases.emplace_back(infoBase);
	}
	bool EditingActorBase::IsOk()
	{
		return mEditingInfoBaseNum >= mInfoBases.size();
	}
}