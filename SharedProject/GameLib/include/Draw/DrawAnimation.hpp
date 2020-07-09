#pragma once
#include<vector>
#include"DrawTexture.hpp"
#include"GameLib/include/App.hpp"

namespace GameLib
{
	class DrawAnimation : public DrawTexture
	{
		using Animation = std::vector<Texture*>;
		std::vector<Animation> mAnimations;

		int mCurrentChannel;

		float mAnimationFPS;

		double mCurrentFrame;

	public:
		DrawAnimation(float animFPS = 24, const Vector2& pos = { 0.f,0.f }, float scale = 1.f, float rot = 0.f, int drawOrder = 0);
		virtual ~DrawAnimation() = default;

		//追加した順にチャンネルが当てられる
		void AddAnimation(std::vector<std::string>&& fileNames);

		//ActorのCusutomUpdateで毎フレーム呼び出す
		void Update(float gameFPS = DEFAULT_FPS);

		void SetChannel(int channel);
		void SetAnimationFPS(float animFPS);

		int GetChannel() const noexcept;

	};
}