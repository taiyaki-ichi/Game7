#pragma once
#include<string>
#include"lib/include/Math/Vector2.hpp"
#include"lib/include/Draw/DrawLine.hpp"
#include"lib/include/Actor/Actor.hpp"

namespace GameLib
{
	class Actor;

	constexpr int COLLIDER_DRAWORDER = 1000;

	class Collider
	{
		Vector2 mPosition;
		float mWidth;
		float mHeigth;
		float mScale;
		float mRotation;

		std::string mNameTag;

		Actor* mOwner;

		//当たり判定の領域の可視化用
		Color mColor;
		DrawLine mLine1;
		DrawLine mLine2;
		DrawLine mLine3;
		DrawLine mLine4;
		//描写するかどうか
		static bool mIsDrawing;

	public:
		Collider(Actor* owner, std::string&& nameTag = "", const Vector2& pos = { 0.f,0.f }, float width = 0.f, float heigth = 0.f
			, float scale = 1.f, float rot = 0.f, Color&& color = { 0,0,0,0 });
		virtual ~Collider();

		//Actorへの通知用
		void HitCollider(const Collider& collider) {
			mOwner->HitCollider(collider);
		}


		static void SetIsDrawing(bool d) {
			mIsDrawing = d;
		}

		void Set(const Vector2& pos, float width, float heigth, float scale, float rot);

		void SetNameTag(std::string&& nameTag) {
			mNameTag = std::move(nameTag);
		}

		const std::string& GetNameTag() const noexcept {
			return mNameTag;
		}
	};
}