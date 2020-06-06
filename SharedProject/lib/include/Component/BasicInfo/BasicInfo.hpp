#pragma once
#include<utility>
#include"lib/include/Component/Component.hpp"
#include"lib/include/Math/Vector2.hpp"

namespace GameLib
{
	

	class BasicInfo : public Component
	{
		Vector2 mPosition;
		float mScale;
		float mRotation;


	public:
		BasicInfo(Actor* owner, int updateOeder = 0)
			:Component(owner, updateOeder)
			, mPosition()
			,mScale(1.f)
			,mRotation(1.f)
		{}

		BasicInfo(Actor* owner,const Vector2& pos ,int updateOeder = 0)
			:Component(owner, updateOeder)
			, mPosition(pos)
			, mScale(1.f)
			, mRotation(1.f)
		{}

		BasicInfo(Actor* owner, Vector2&& pos, int updateOeder = 0)
			:Component(owner, updateOeder)
			, mPosition(std::move(pos))
			, mScale(1.f)
			, mRotation(1.f)
		{}

		BasicInfo(Actor* owner,const Vector2& pos ,float scale=1.f,float rot=1.f,int updateOeder = 0)
			:Component(owner, updateOeder)
			, mPosition(pos)
			, mScale(scale)
			, mRotation(rot)
		{}

		BasicInfo(Actor* owner, Vector2&& pos, float scale = 1.f, float rot = 1.f, int updateOeder = 0)
			:Component(owner, updateOeder)
			, mPosition(std::move(pos))
			, mScale(scale)
			, mRotation(scale)
		{}

		virtual ~BasicInfo() = default;


		const Vector2& GetPosition() const { return mPosition; }
		void SetPosition(const Vector2& pos) { mPosition = pos; }
		void SetPosition(Vector2&& pos) { mPosition = std::move(pos); }

		float GetScale() const { return mScale; }
		void SetScale(float scale) { mScale = scale; }

		float GetRotation() const { return mRotation; }
		void SetRotation(float rotation) { mRotation = rotation; }
	};
}