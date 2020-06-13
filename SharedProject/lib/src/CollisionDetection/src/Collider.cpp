#include"lib/include/CollisionDetection/Collider.hpp"
#include"lib/include/Math/Vector2Func.hpp"
#include"lib/src/CollisionDetection/ColliderManager.hpp"

namespace GameLib
{


	Collider::Collider(Actor* owner, std::string&& nameTag, const Vector2& pos, float width, float heigth, float scale, float rot, Color&& color)
		:mOwner(owner)
		, mNameTag(std::move(nameTag))
		, mPosition(pos)
		, mWidth(width)
		, mHeigth(heigth)
		, mScale(scale)
		, mRotation(rot)
		, mColor(std::move(color))
		, mLine1()
		, mLine2()
		, mLine3()
		, mLine4()

	{
		auto vecs = GetRectangleVectors(mPosition, mWidth * mScale, mHeigth * mScale, mRotation);
		mLine1.SetPoints(vecs[0], vecs[1]);
		mLine2.SetPoints(vecs[1], vecs[2]);
		mLine3.SetPoints(vecs[2], vecs[3]);
		mLine4.SetPoints(vecs[3], vecs[0]);

		mLine1.SetDrawOrder(COLLIDER_DRAWORDER);
		mLine2.SetDrawOrder(COLLIDER_DRAWORDER);
		mLine3.SetDrawOrder(COLLIDER_DRAWORDER);
		mLine4.SetDrawOrder(COLLIDER_DRAWORDER);

		mLine1.SetColor(mColor);
		mLine2.SetColor(mColor);
		mLine3.SetColor(mColor);
		mLine4.SetColor(mColor);

		ColliderManager::Add(this);
	}

	Collider::~Collider()
	{
		ColliderManager::Remove(this);
	}

	void Collider::Set(const Vector2& pos, float width, float heigth, float scale, float rot)
	{
		mPosition = pos;
		mWidth = width;
		mHeigth = heigth;
		mScale = scale;
		mRotation = rot;

		auto vecs = GetRectangleVectors(mPosition, mWidth * mScale, mHeigth * mScale, mRotation);
		mLine1.SetPoints(vecs[0], vecs[1]);
		mLine2.SetPoints(vecs[1], vecs[2]);
		mLine3.SetPoints(vecs[2], vecs[3]);
		mLine4.SetPoints(vecs[3], vecs[0]);

		mLine1.SetColor(mColor);
		mLine2.SetColor(mColor);
		mLine3.SetColor(mColor);
		mLine4.SetColor(mColor);
	}
}