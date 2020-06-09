#pragma once
#include"lib/include/Component/Component.hpp"
#include"Color.hpp"
#include"TextureFlip.hpp"
namespace GameLib
{

	class Actor;
	class Texture;
	class CoordinteInfo;
	class Vector2;

	class SpriteComponent : public Component
	{
	public:
		SpriteComponent(Actor* actor,int drawOrder = 0, int updateOrde = 0);
		virtual ~SpriteComponent();

		virtual void Draw(){}

		int GetDrawOrder() const noexcept {
			return mDrawOrder;
		}

	private:
		int mDrawOrder;

	protected:
		//Draw“à‚ÅŽg—p
		void DrawTexture(Texture* texture, CoordinteInfo* info,int alpha = 255, const TextureFlip& flip = TextureFlip::None);
		void DrawLine(const Vector2& p1, const Vector2& p2, const Color& color = { 0,0,0,255 });
		void DrawFillTriangle(const Vector2& p1, const Vector2& p2, const Vector2& p3, const Color& color = { 0,0,0,255 });
		

	};
}