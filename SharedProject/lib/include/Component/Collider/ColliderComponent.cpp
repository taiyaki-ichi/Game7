
#include"ColliderComponent.hpp"
#include"lib/include/Actor/CoordinateActor.hpp"
#include"lib/include/Math/Vector2Func.hpp"
#include<algorithm>

namespace GameLib
{

	bool ColliderComponent::mIsDrawing = true;

	ColliderComponent::ColliderComponent(CoordinateActor* owner,std::string&& name, float width, float heigth, Color&& color, int updateOrder)
		:SpriteComponent(owner, 1000, updateOrder)
		,mCoordinateActor(owner)
		,mName(std::move(name))
		, mWidth(width)
		, mHeight(heigth)
		, mColor(std::move(color))
	{
	}

	ColliderComponent::~ColliderComponent()
	{
	}

	std::optional<std::function<void(ColliderComponent*, ColliderComponent*)>> ColliderComponent::GetHitFunction(const std::string& name)
	{
		auto iter = mHitFunctions.find(name);
		if (iter != mHitFunctions.end())
			return std::optional<std::function<void(ColliderComponent*, ColliderComponent*)>>(iter->second);

		return std::nullopt;
	}

	void ColliderComponent::Draw()
	{
		if (mIsDrawing)
		{
			float s = mCoordinateActor->GetScale();
			auto vecs = GetRectangleVectors(mCoordinateActor->GetPosition(), mWidth*s, mHeight*s, mCoordinateActor->GetRotation());
			for (int i = 0; i < 3; i++)
				DrawLine(vecs[i], vecs[i + 1], mColor);
			DrawLine(vecs[3], vecs[0], mColor);

		}
	}

	void ColliderComponent::SetWidthAndHeigth(float w, float h)
	{
		mWidth = w;
		mHeight = h;
	}

	void ColliderComponent::SetColor(Color&& color)
	{
		mColor = std::move(color);
	}

	void ColliderComponent::SetName(std::string&& name)
	{
		mName = std::move(name);
	}

	void ColliderComponent::SetIsDrawing(bool d)
	{
		mIsDrawing = d;
	}

}