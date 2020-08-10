#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"GameLib/include/Resource/ResourceManager.hpp"
#include<algorithm>
#include "..\..\include\Draw\DrawAnimation.hpp"

namespace GameLib
{
	DrawAnimation::DrawAnimation(float animFPS, const Vector2& pos, float scale, float rot, int drawOrder)
		:DrawTexture(pos,scale,rot,drawOrder)
		,mAnimationFPS(animFPS)
		,mAnimations()
		,mCurrentChannel(0)
		,mCurrentFrame(0.0)
	{
	}

	void DrawAnimation::AddAnimation(std::vector<std::string>&& fileNames)
	{
		Animation animation;
		std::transform(fileNames.begin(), fileNames.end(), std::back_inserter(animation),
			[](std::string& name) {return ResourceManager::GetTexture(std::move(name)); });
		mAnimations.emplace_back(std::move(animation));
	}

	void DrawAnimation::Update(float gameFPS)
	{
		if (0 <= mCurrentChannel && mCurrentChannel < mAnimations.size())
		{
			mCurrentFrame += static_cast<double>(mAnimationFPS / gameFPS);

			while (mCurrentFrame >= mAnimations[mCurrentChannel].size())
				mCurrentFrame -= mAnimations[mCurrentChannel].size();
			
			SetTexture(mAnimations[mCurrentChannel][static_cast<int>(mCurrentFrame)]);
		}
	}

	void DrawAnimation::SetChannel(int channel)
	{
		if (mCurrentChannel != channel&& 0 <= channel && channel < mAnimations.size()) {
			mCurrentChannel = channel;
			mCurrentFrame = 0.0;
			SetTexture(mAnimations[mCurrentChannel][0]);
		}
	}

	void DrawAnimation::SetAnimationFPS(float animFPS)
	{
		mAnimationFPS = animFPS;
	}
	int DrawAnimation::GetChannel() const noexcept
	{
		return mCurrentChannel;
	}
}