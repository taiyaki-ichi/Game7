#include"AnimComponent.hpp"
#include"lib/include/Resource/ResourceManager.hpp"
#include"lib/include/Actor/CoordinateActor.hpp"
namespace GameLib
{

	AnimComponent::AnimComponent(CoordinateInfo* info, std::vector<std::string>&& fileNames, double animFPS, int drawOrder, int updateOrder)
		:TextureComponent(info, drawOrder, updateOrder)
		, mIsPlaying(true)
		,mAnimFPS(animFPS)
		,mCurrFrame(0.0)
	{
		for (auto& name : fileNames)
			mTextures.emplace_back(ResourceManager::GetTexture(std::move(name)));
		SetTexture(mTextures[0]);
	}

	AnimComponent::AnimComponent(CoordinateActor* owner, std::vector<std::string>&& fileNames, double animFPS, int drawOrder, int updateOrder)
		:AnimComponent(owner->GetCoordinateInfo(),std::move(fileNames),animFPS,drawOrder,updateOrder)
	{
	}

	AnimComponent::~AnimComponent()
	{
	}

	void AnimComponent::Update()
	{
		if (mIsPlaying && !mTextures.empty())
		{
			//ŒÅ’è60FPS
			mCurrFrame += mAnimFPS / 60.0;
			//Šª‚«–ß‚µ
			while (mCurrFrame >= mTextures.size())
				mCurrFrame -= mTextures.size();
			
			SetTexture(mTextures[static_cast<int>(mCurrFrame)]);

		}
	}

	void AnimComponent::Play()
	{
		mIsPlaying = true;
	}

	void AnimComponent::Stop()
	{
		mIsPlaying = false;
	}

}