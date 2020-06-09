#pragma once
#include<string>
#include"lib/src/Draw/DrawBase.hpp"
#include"lib/include/Math/Vector2.hpp"
#include"TextureFlip.hpp"

namespace GameLib
{
	class Texture;

	class DrawTexture : public DrawBase
	{

		//描写するテクスチャ
		Texture* mTexture;
		//場所
		Vector2 mPosition;
		//拡大率
		float mScale;
		//回転角
		float mRotation;
		//透明度
		int mAlpha;
		//フリップ
		TextureFlip mTextureFlip;


	public:
		DrawTexture(std::string&& fileName, const Vector2& pos = { 0.f,0.f }, float scale = 1.f, float rot = 0.f, int drawOrder = 0);
		virtual ~DrawTexture() = default;

		void Draw() override final;

		void SetTexture(std::string&& fileName);
		void SetTexture(Texture* texture);

		void Set(const Vector2& pos, float scale, float rot);
		void Set(Vector2&& pos, float scale, float rot);

		void SetAlpha(int a);
		void SetTextureFlip(TextureFlip&& flip);

	};
}