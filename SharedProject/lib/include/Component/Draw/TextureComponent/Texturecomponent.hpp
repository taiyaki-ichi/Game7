#pragma once
#include<string>
#include"lib/include/Component/Draw/SpriteCompoent.hpp"
#include"lib/include/Component/Draw/TextureFlip.hpp"

namespace GameLib
{
	class CoordinateActor;
	class Texture;

	class TextureComponent : public SpriteComponent
	{
	public:
		TextureComponent(CoordinateActor* owner, const std::string& fileName, int drawOrder = 0, int updateOrder = 0);
		TextureComponent(CoordinateActor* owner, int drawOrder = 0, int updateOrder = 0);
		virtual ~TextureComponent() = default;

		virtual void Draw() override;

		void SetTexture(Texture* texture) {
			mTexture = texture;
		}
		void SetAlpha(int a) {
			mAlpha = a;
		}
		void SetTextureFilp(TextureFlip&& flip) {
			mTextureFlip = std::move(flip);
		}

		void SetIsDrawing(bool is) {
			mIsDrawing = is;
		}

	private:
		Texture* mTexture;
		CoordinateActor* mCoordinateActor;

		int mAlpha;

		TextureFlip mTextureFlip;

		bool mIsDrawing;
	};
}
