#pragma once
#include"Actor.hpp"
#include"lib/include/Math/Vector2.hpp"
#include"lib/include/Component/CoordinateInfoInfo/CoordinateInfo.hpp"

namespace GameLib
{
	class CoordinateActor : public Actor
	{
		CoordinateInfo* mCoordinateInfo;


	public:
		CoordinateActor(Actor* owner, const Vector2& pos = { 0.f,0.f }, float scale = 1.f, float rot = 0.f, int updateOrder = 0)
			:Actor(owner, updateOrder)
		{
			mCoordinateInfo = new CoordinateInfo(this, pos, scale, rot);
		}
		CoordinateActor(Actor* owner, Vector2&& pos = { 0.f,0.f }, float scale = 1.f, float rot = 0.f, int updateOrder = 0)
			:Actor(owner, updateOrder)
		{
			mCoordinateInfo = new CoordinateInfo(this, std::move(pos), scale, rot);
		}
		virtual ~CoordinateActor() = default;

		CoordinateInfo* GetCoordinateInfo() const noexcept {
			return mCoordinateInfo;
		}


	};
}