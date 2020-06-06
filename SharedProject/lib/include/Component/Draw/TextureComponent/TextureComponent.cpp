#include "Texturecomponent.hpp"
#include"lib/include/Resource/ResourceManager.hpp"
#include"lib/include/Component/BasicActorInfo/BasicActorInfo.hpp"

namespace GameLib
{
	TextureComponent::TextureComponent(BasicActorInfo* info, const std::string& fileName, int drawOrder, int updateOrder)
		:SpriteComponent(info->GetOwner(), drawOrder, updateOrder)
		, mBasicActorInfo(info)
		, mAlpha(255)
		, mTextureFlip(TextureFlip::None)
		,mIsDrawing(true)
	{
		mTexture = ResourceManager::GetTexture(fileName);
	}

	TextureComponent::TextureComponent(BasicActorInfo* info, int drawOrder, int updateOrder)
		:SpriteComponent(info->GetOwner(), drawOrder, updateOrder)
		, mBasicActorInfo(info)
		, mTexture(nullptr)
		, mAlpha(255)
		, mTextureFlip(TextureFlip::None)
		, mIsDrawing(true)
	{
	}

	void TextureComponent::Draw() {
		if (mIsDrawing)
			DrawTexture(mTexture, mBasicActorInfo, mAlpha, mTextureFlip);
	}
	
}