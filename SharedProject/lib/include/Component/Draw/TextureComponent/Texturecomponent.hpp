#pragma once
#include<string>
#include"lib/include/Component/Draw/SpriteCompoent.hpp"
#include"lib/include/Component/BasicActorInfo/BasicActorInfo.hpp"
#include"lib/include/Resource/ResourceManager.hpp"
#include"lib/include/Component/Draw/TextureFlip.hpp"
#include"lib/include/Resource/Texture.hpp"


namespace GameLib
{
	class BasicActorInfo;
	class Texture;

	class TextureComponent : public SpriteComponent
	{
	public:
		TextureComponent(BasicActorInfo* info,const std::string& fileName, int drawOrder = 0, int updateOrder = 0)
			:SpriteComponent(info->GetOwner(),drawOrder,updateOrder)
			, mBasicActorInfo(info)
			,mAlpha(255)
			,mTextureFlip(TextureFlip::None)
		{
			mTexture = ResourceManager::GetTexture(fileName);
		}
		virtual ~TextureComponent() = default;

		virtual void Draw() override
		{
			DrawTexture(mTexture, mBasicActorInfo, mAlpha, mTextureFlip);
		}

	private:
		Texture* mTexture;
		BasicActorInfo* mBasicActorInfo;

		int mAlpha;

		TextureFlip mTextureFlip;
	};
}
