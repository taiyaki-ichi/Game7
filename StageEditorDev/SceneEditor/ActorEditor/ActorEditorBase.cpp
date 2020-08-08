#include"ActorEditorBase.hpp"
#include<iostream>
#include<string>
#include"GameLib/include/InputState/InputState.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"

namespace StageEditor
{
	ActorEditorBase::ActorEditorBase(GameLib::Actor* actor,std::string&& nameTag,int posNum,int stringNum)
		:GameLib::Actor{ actor }
		, mPosData{posNum}
		, mStringData{stringNum}
		, mNameTag{std::move(nameTag)}
		, mCollider{}
	{
		auto deathFunc = [this](const GameLib::Collider& c) {
			if (GameLib::InputState::GetState(GameLib::Key::Space) == GameLib::ButtonState::Pressed)
				SetState(GameLib::Actor::State::Dead);
		};
		mCollider.AddHitFunction("Cursor", std::move(deathFunc));
		mCollider.SetColor({ 0,255,0,255 });
	}

	void ActorEditorBase::CustomizeUpdate()
	{
		if (GameLib::InputState::GetState(GameLib::MouseButton::Middle) == GameLib::ButtonState::Pressed)
			mPosData.DefinePosDataBeck();

		//ƒJƒƒ‰‚ÌÀ•W‚©‚ç•ÏŠ·‚·‚é
		using namespace GameLib;
		auto pos = AffineInv(InputState::GetMousePos(), Viewport::GetPos(), Viewport::GetRotation(), Viewport::GetScale());
		mPosData.UpdatePosDataBack(std::move(pos));

		Update();
	}

	bool ActorEditorBase::IsOK()
	{
		return mStringData.IsOK() && mPosData.IsOK();
	}

	void ActorEditorBase::ForwardStringData(std::string&& str)
	{
		mStringData.AddData(std::move(str));
	}

	void ActorEditorBase::PrintStringData()
	{
		PrintStringDataInfo();

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
		for (int i = 0; i < floatData.size() / 2; i++) {
			mPosData.UpdatePosDataBack(GameLib::Vector2{ floatData[i * 2],floatData[i * 2 + 1] });
			mPosData.DefinePosDataBeck();
		}
		for (int i = 0; i < stringData.size(); i++)
			mStringData.AddData(std::move(stringData[i]));
	}

	void ActorEditorBase::BeginBeginWorking()
	{
		mCollider.Active();
		BeginWorking();
	}

	void ActorEditorBase::BeginBeginToRest()
	{
		mCollider.Pause();
		BeginToRest();
	}
}