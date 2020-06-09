#pragma once
#include"Actor.hpp"
#include"lib/include/Math/Vector2.hpp"

namespace GameLib
{
	class CoordinateActor : public Actor
	{
		//ç¿ïW
		Vector2 mPosition;
		//âÒì]
		float mRotation;
		//î{ó¶
		float mScale;


	public:
		CoordinateActor(Actor* owner, const Vector2& pos = { 0.f,0.f }, float rot = 1.f, float scale = 1.f, int updateOrder = 0)
			:Actor(owner, updateOrder)
			,mPosition(pos)
			,mRotation(rot)
			,mScale(scale)
		{}
		CoordinateActor(Actor* owner, Vector2&& pos = { 0.f,0.f }, float rot = 1.f, float scale = 1.f, int updateOrder = 0)
			:Actor(owner, updateOrder)
			, mPosition(std::move(pos))
			, mRotation(rot)
			, mScale(scale)
		{}

		virtual ~CoordinateActor() = default;

		const Vector2& GetPosition() const { return mPosition; }
		void SetPosition(const Vector2& pos) { mPosition = pos; }
		void SetPosition(Vector2&& pos) { mPosition = std::move(pos); }

		float GetScale() const { return mScale; }
		void SetScale(float scale) { mScale = scale; }

		float GetRotation() const { return mRotation; }
		void SetRotation(float rotation) { mRotation = rotation; }

	};

}