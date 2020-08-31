#include"IceGround.hpp"
#include"IceGround/IceGroundCollider.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include"IceGround/IceGroundParam.hpp"

namespace Stage
{

	void CreateCollider(GameLib::Vector2&& pos, float w, float h, std::vector<IceGroundCollider*>& result,GameLib::Actor* owner)
	{
	
		if (w > IceGroundParam::COLLIDER_MAX && h > IceGroundParam::COLLIDER_MAX)
		{
			CreateCollider(pos + GameLib::Vector2{ w / 4.f,h / 4.f }, w / 2.f, h / 2.f,result, owner);
			CreateCollider(pos + GameLib::Vector2{ w / 4.f,-h / 4.f }, w / 2.f, h / 2.f, result, owner);
			CreateCollider(pos + GameLib::Vector2{ -w / 4.f,h / 4.f }, w / 2.f, h / 2.f, result, owner);
			CreateCollider(pos + GameLib::Vector2{ -w / 4.f,-h / 4.f }, w / 2.f, h / 2.f, result, owner);
		}
		else if (w > IceGroundParam::COLLIDER_MAX)
		{
			CreateCollider(pos + GameLib::Vector2{ w / 4.f,0.f }, w / 2.f, h, result, owner);
			CreateCollider(pos + GameLib::Vector2{ -w / 4.f,0.f }, w / 2.f, h, result, owner);
		}
		else if (h > IceGroundParam::COLLIDER_MAX)
		{
			CreateCollider(pos + GameLib::Vector2{ 0.f,h / 4.f }, w, h / 2.f, result, owner);
			CreateCollider(pos + GameLib::Vector2{ 0.f,-h / 4.f }, w, h / 2.f, result, owner);
		}
		else
		{
			result.emplace_back(new IceGroundCollider{ owner,pos,w,h });
		}
	}

	IceGround::IceGround(GameLib::Actor* actor)
		:ActorBase{actor}
		, mTexture{}
		, mIceGroundCollider{}
	{
		
	}

	void IceGround::BeginWorking()
	{
		for (auto ptr : mIceGroundCollider)
			ptr->BeginWorking();
		mTexture.SetIsAutoDrawing(true);
	}

	void IceGround::BeginToRest()
	{
		for (auto ptr : mIceGroundCollider)
			ptr->BeginToRest();
		mTexture.SetIsAutoDrawing(false);
	}

	void IceGround::LoadPosData(std::vector<GameLib::Vector2>&& data)
	{
		float w = GameLib::GetDistanceX(data[0], data[1]);
		float h = GameLib::GetDistanceY(data[0], data[1]);
		auto pos = GameLib::GetCenter(data[0], data[1]);

		mTexture.SetWidthAndHeight(w, h);
		mTexture.SetPosition(pos);

		CreateCollider(std::move(pos), w, h, mIceGroundCollider, this);
	}
}