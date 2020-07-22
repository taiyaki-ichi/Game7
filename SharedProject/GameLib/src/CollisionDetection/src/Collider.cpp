#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"GameLib/include/Draw/DrawLine.hpp"
#include"GameLib/src/CollisionDetection/ColliderManager.hpp"
#include "..\..\..\include\CollisionDetection\Collider.hpp"


namespace GameLib
{
	bool Collider::mIsDebug = false;

	void Collider::SetDrawRect()
	{
		mDrawRect.Set(mPosition, mScale, mRotation);
		mDrawRect.SetWidthAndHeight(mWidth, mHeigth);
	}
	Collider::Collider(std::string&& nameTag, const Vector2& pos, float width, float heigth, float scale, float rot,Color&& color )
		: mNameTag(std::move(nameTag))
		, mPosition(pos)
		, mWidth(width)
		, mHeigth(heigth)
		, mScale(scale)
		, mRotation(rot)
		, mDrawRect{ COLLIDER_DRAWORDER }
		, mDoCollisionDetection{true}
		, mRerativePos{}
		, mPrevPos{pos}
	{
		SetDrawRect();
		mDrawRect.SetIsFill(false);
		SetColor(std::move(color));

		ColliderManager::Add(this);

		if (mIsDebug)
			mDrawRect.SetIsAutoDrawing(true);
		else
			mDrawRect.SetIsAutoDrawing(false);
	}

	Collider::~Collider()
	{
		ColliderManager::Remove(this);
	}

	void Collider::AddHitFunction(std::string&& nameTag, std::function<void(const Collider&)>&& hitFunc)
	{
		mHitFunctions.emplace(std::move(nameTag), std::move(hitFunc));
	}

	void Collider::AddHitFunction(std::string&& nameTag, const std::function<void(const Collider&)>& hitFunc)
	{
		mHitFunctions.emplace(std::move(nameTag), hitFunc);
	}

	std::optional<std::function<void(const Collider&)>> Collider::GetHitFunction(const std::string& nameTag)
	{

		auto iter = mHitFunctions.find(nameTag);
		if (iter != mHitFunctions.end())
			return iter->second;
		else
			return std::nullopt;

	}


	void Collider::SetIsDrawing(bool b)
	{
		mDrawRect.SetIsAutoDrawing(b);
	}

	void Collider::SetIsDebug(bool b)
	{
		mIsDebug = b;
		ColliderManager::SetAllIsDrawing(b);
	}

	void Collider::Set(const Vector2& pos, float width, float heigth, float scale, float rot)
	{
		mPosition = pos;
		mWidth = width;
		mHeigth = heigth;
		mScale = scale;
		mRotation = rot;

		SetDrawRect();
	}
	void Collider::Set(const Vector2& pos, float scale, float rot)
	{
		mPosition = pos;
		mScale = scale;
		mRotation = rot;

		SetDrawRect();
	}
	void Collider::SetPosition(const Vector2& pos)
	{
		mPosition = pos;
		SetDrawRect();
	}
	void Collider::SetWidthAndHeith(float w, float h)
	{
		mWidth = w;
		mHeigth = h;
		SetDrawRect();
	}
	void Collider::SetRotation(float rot)
	{
		mRotation = rot;
		while (mRotation < 0.f)
			mRotation += PI * 2.f;
		while (mRotation >= PI * 2.f)
			mRotation -= PI * 2.f;
		SetDrawRect();
	}
	void Collider::SetScale(float s)
	{
		mScale = s;
		SetDrawRect();
	}
	void Collider::SetNameTag(std::string&& nameTag)
	{
		mNameTag = std::move(nameTag);
	}
	void Collider::SetDoCollisionDetection(bool a)
	{
		mDoCollisionDetection = a;
	}
	void Collider::SetColor(Color&& color)
	{
		mDrawRect.SetColor(std::move(color));
	}
	const std::string& Collider::GetNameTag() const noexcept
	{
		return mNameTag;
	}
	float Collider::GetWidth() const noexcept
	{
		return mWidth;
	}
	float Collider::GetHeigth() const noexcept
	{
		return mHeigth;
	}
	float Collider::GetScale() const noexcept
	{
		return mScale;
	}
	const Vector2& Collider::GetPosition() const noexcept
	{
		return mPosition;
	}
	float Collider::GetRotation() const noexcept
	{
		return mRotation;
	}
	bool Collider::GetDoCollisionDetection()
	{
		return mDoCollisionDetection;
	}
	void Collider::Active()
	{
		mDoCollisionDetection = true;
		if (mIsDebug == true)
			mDrawRect.SetIsAutoDrawing(true);

	}
	void Collider::Pause()
	{
		mDoCollisionDetection = false;
		if (mIsDebug == true)
			mDrawRect.SetIsAutoDrawing(false);
	}
	const Vector2& Collider::GetRerativePos() const
	{
		return mRerativePos;
	}
	void Collider::UpdatePosInfo()
	{
		mRerativePos = mPosition - mPrevPos;
		mPrevPos = mPosition;
	}
}