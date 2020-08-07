#include"ActorEditorBase.hpp"
#include<iostream>
#include<string>

namespace StageEditor
{
	ActorEditorBase::ActorEditorBase(GameLib::Actor* actor,std::string&& nameTag,int posNum,int stringNum)
		:GameLib::Actor{ actor }
		, mPosData{posNum}
		, mStringData{stringNum}
		, mNameTag{std::move(nameTag)}
	{
	}

	bool ActorEditorBase::IsOK()
	{
		return mStringData.IsOK() && mPosData.IsOK();
	}

	void ActorEditorBase::AddData(std::string&& str)
	{
		mStringData.AddData(std::move(str));
	}

	void ActorEditorBase::AddData(GameLib::Vector2&& pos)
	{
		mPosData.AddData(std::move(pos));
	}

	void ActorEditorBase::PrintStringData()
	{
		int num = mStringData.GetDataNum();

		if (num > 0)
		{
			for (int i = 0; i <= num; i++) {
				std::cout << "String Data " << std::to_string(i) << ": ";

				if (i != num)
					std::cout << mStringData[i];

				std::cout << "\n";
			}
		}
	}

	ActorData ActorEditorBase::GetData()
	{
		std::vector<GameLib::Vector2> posData{};
		for (int i = 0; i < mPosData.GetDataNum(); i++)
			posData.emplace_back(mPosData[i]);

		std::vector<std::string> stringData{};
		for (int i = 0; i < mStringData.GetDataNum(); i++)
			stringData.emplace_back(mStringData[i]);

		return { mNameTag,std::move(posData),std::move(stringData) };
	}

	void ActorEditorBase::SetData(std::vector<float>&& floatData, std::vector<std::string>&& stringData)
	{
		for (int i = 0; i < floatData.size() / 2; i++)
			mPosData.AddData(GameLib::Vector2{ floatData[i * 2],floatData[i * 2 + 1] });
		for (int i = 0; i < stringData.size(); i++)
			mStringData.AddData(std::move(stringData[i]));
	}
}