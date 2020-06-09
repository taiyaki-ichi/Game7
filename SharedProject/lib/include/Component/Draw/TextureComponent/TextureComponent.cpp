#include "Texturecomponent.hpp"
#include"lib/include/Resource/ResourceManager.hpp"
#include"lib/include/Actor/CoordinateActor.hpp"

namespace GameLib
{
	TextureComponent::TextureComponent(CoordinateActor* owner, const std::string& fileName, int drawOrder, int updateOrder)
		:SpriteComponent(owner, drawOrder, updateOrder)
		, mCoordinateActor(owner)
		, mAlpha(255)
		, mTextureFlip(TextureFlip::None)
		,mIsDrawing(true)
	{
		mTexture = ResourceManager::GetTexture(fileName);
	}

	TextureComponent::TextureComponent(CoordinateActor* owner, int drawOrder, int updateOrder)
		:SpriteComponent(owner, drawOrder, updateOrder)
		, mCoordinateActor(owner)
		, mTexture(nullptr)
		, mAlpha(255)
		, mTextureFlip(TextureFlip::None)
		, mIsDrawing(true)
	{
	}

	void TextureComponent::Draw() {
		if (mIsDrawing)
			DrawTexture(mTexture, mCoordinateActor->GetPosition(),mCoordinateActor->GetRotation(),
				mCoordinateActor->GetScale(), mAlpha, mTextureFlip);
	}
	
}