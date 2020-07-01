#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"GameLib/include/Draw/DrawLine.hpp"
#include"GameLib/src/CollisionDetection/ColliderManager.hpp"
#include "..\..\..\include\CollisionDetection\Collider.hpp"


namespace GameLib
{

	Collider::Collider(std::string&& nameTag, const Vector2& pos, float width, float heigth, float scale, float rot,Color&& color )
		: mNameTag(std::move(nameTag))
		, mPosition(pos)
		, mWidth(width)
		, mHeigth(heigth)
		, mScale(scale)
		, mRotation(rot)
		, mLine1()
		, mLine2()
		, mLine3()
		, mLine4()

	{
		CalcLinesPoint();

		mLine1.SetDrawOrder(COLLIDER_DRAWORDER);
		mLine2.SetDrawOrder(COLLIDER_DRAWORDER);
		mLine3.SetDrawOrder(COLLIDER_DRAWORDER);
		mLine4.SetDrawOrder(COLLIDER_DRAWORDER);

		SetColor(std::move(color));

		ColliderManager::Add(this);
	}

	Collider::~Collider()
	{
		ColliderManager::Remove(this);
	}

	void Collider::SwitchAllColliderDraw()
	{
		ColliderManager::SwitchAllColliderDraw();
	}

	void Collider::SwitchDraw()
	{
		bool b = mLine1.GetIsDrawing();
		mLine1.SetIsDrawing(!b);
		mLine2.SetIsDrawing(!b);
		mLine3.SetIsDrawing(!b);
		mLine4.SetIsDrawing(!b);
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
	}
}