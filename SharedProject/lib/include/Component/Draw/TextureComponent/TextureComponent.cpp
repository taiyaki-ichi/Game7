#include "Texturecomponent.hpp"
#include"lib/include/Resource/ResourceManager.hpp"
#include"lib/include/Component/CoordinateInfoInfo/CoordinateInfo.hpp"
#include"lib/include/Actor/CoordinateActor.hpp"

namespace GameLib
{
	TextureComponent::TextureComponent(CoordinateInfo* info, const std::string& fileName, int drawOrder, int updateOrder)
		:SpriteComponent(info->GetOwner(), drawOrder, updateOrder)
		, mBasicActorInfo(info)
		, mAlpha(255)
		, mTextureFlip(TextureFlip::None)
		,mIsDrawing(true)
	{
		mTexture = ResourceManager::GetTexture(fileName);
	}

	TextureComponent::TextureComponent(CoordinateInfo* info, int drawOrder, int updateOrder)
		:SpriteComponent(info->GetOwner(), drawOrder, updateOrder)
		, mBasicActorInfo(info)
		, mTexture(nullptr)
		, mAlpha(255)
		, mTextureFlip(TextureFlip::None)
		, mIsDrawing(true)
	{
	}

	TextureComponent::TextureComponent(CoordinateActor* owner, int drawOrder, int updateOrder)
		:TextureComponent(owner->GetCoordinateInfo(),drawOrder,updateOrder)
	{
	}

	TextureComponent::TextureComponent(CoordinateActor* owner, const std::string& fileName, int drawOrdr, int update)
		:TextureComponent(owner->GetCoordinateInfo(),fileName,drawOrdr,update)
	{
	}

	void TextureComponent::Draw() {
		if (mIsDrawing)
			DrawTexture(mTexture, mBasicActorInfo, mAlpha, mTextureFlip);
	}
	
}