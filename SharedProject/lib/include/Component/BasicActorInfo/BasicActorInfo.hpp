#pragma once
#include<utility>
#include<type_traits>
#include"lib/include/Component/Component.hpp"
#include"lib/include/Math/Vector2.hpp"

namespace GameLib
{

	class BasicActorInfo : public Component
	{
		Vector2 mPosition;
		float mScale;
		float mRotation;

	public:
		BasicActorInfo(Actor* owner, int updateOeder = 0)
			:Component(owner, updateOeder)
			, mPosition()
			,mScale(1.f)
			,mRotation(0.f)
		{}

		BasicActorInfo(Actor* owner,const Vector2& pos ,float scale=1.f,float rot=0.f,int updateOeder = 0)
			:Component(owner, updateOeder)
			, mPosition(pos)
			, mScale(scale)
			, mRotation(rot)
		{}

		BasicActorInfo(Actor* owner, Vector2&& pos, float scale = 1.f, float rot = 0.f, int updateOeder = 0)
			:Component(owner, updateOeder)
			, mPosition(std::move(pos))
			, mScale(scale)
			, mRotation(rot)
		{}

		virtual ~BasicActorInfo() = default;


		const Vector2& GetPosition() const { return mPosition; }
		void SetPosition(const Vector2& pos) { mPosition = pos; }
		void SetPosition(Vector2&& pos) { mPosition = std::move(pos); }

		float GetScale() const { return mScale; }
		void SetScale(float scale) { mScale = scale; }

		float GetRotation() const { return mRotation; }
		void SetRotation(float rotation) { mRotation = rotation; }

	
	};
}