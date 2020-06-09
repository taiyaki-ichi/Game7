#pragma once
#include"lib/include/Component/Draw/TextureComponent/Texturecomponent.hpp"
#include<vector>

namespace GameLib
{
	class AnimComponent : public TextureComponent
	{
	public:
		AnimComponent(CoordinateInfo* info, std::vector<std::string>&& fileNames, double animFPS = 16.0, int drawOrder = 0, int updateOrder = 0);
		AnimComponent(CoordinateActor* owner, std::vector<std::string>&& fileNames, double animFPS = 16.0, int drawOrder = 0, int updateOrder = 0);
		virtual ~AnimComponent();

		void Update() override;

		void Play();
		void Stop();

	private:
		bool mIsPlaying;
		std::vector<Texture*> mTextures;

		double mCurrFrame;
		double mAnimFPS;

		
	};
}