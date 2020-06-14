#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"GameLib/include/Resource/ResourceManager.hpp"
#include<algorithm>

namespace GameLib
{
	DrawAnimation::DrawAnimation(float animFPS, const Vector2& pos, float scale, float rot, int drawOrder)
		:DrawTexture(pos,scale,rot,drawOrder)
		,mAnimationFPS(animFPS)
		,mAnimations()
		,mCurrentChannel(0)
		,mCurrectFrame(0.0)
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
			mCurrectFrame += static_cast<double>(mAnimationFPS / gameFPS);

			while (mCurrectFrame >= mAnimations[mCurrentChannel].size())
				mCurrectFrame -= mAnimations[mCurrentChannel].size();
			
			SetTexture(mAnimations[mCurrentChannel][static_cast<int>(mCurrectFrame)]);
		}
	}

	void DrawAnimation::SetChannel(int channel)
	{
		if (mCurrentChannel != channel&& 0 <= channel && channel < mAnimations.size()) {
			mCurrentChannel = channel;
			mCurrectFrame = 0.0;
			SetTexture(mAnimations[mCurrentChannel][0]);
		}
	}

	void DrawAnimation::SetAnimationFPS(float animFPS)
	{
		mAnimationFPS = animFPS;
	}
}