#include"lib/include/Component/Draw/SpriteCompoent.hpp"
#include"lib/src/DrawManager/DrawManager.hpp"
#include"lib/include/Component/BasicActorInfo/BasicActorInfo.hpp"
#include"lib/src/Windows/Graphics.hpp"

namespace GameLib
{
	SpriteComponent::SpriteComponent(Actor* owner, int drawOrder, int updateOrde)
		:Component(owner,updateOrde)
		,mDrawOrder(drawOrder)
	{
		DrawManager::Add(this);

	}

	SpriteComponent::~SpriteComponent() {
		DrawManager::Remove(this);
	}

	void SpriteComponent::DrawTexture(Texture* texture, BasicActorInfo* info,int alpha,const TextureFlip& flip)
	{
		GraphicsDrawTexture(texture, info->GetPosition().x, info->GetPosition().y, info->GetRotation(),info->GetScale(), alpha, static_cast<int>(flip));
	}

	void SpriteComponent::DrawLine(const Vector2& p1, const Vector2& p2, const Color& color)
	{
		GraphicsDrawLine(p1.x, p1.y, p2.x, p2.y, color.R, color.G, color.B, color.A);
	}

	void SpriteComponent::DrawFillTriangle(const Vector2& p1, const Vector2& p2, const Vector2& p3, const Color& color)
	{
		GraphicsDrawFillTriangle(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, color.R, color.G, color.B, color.A);
	}

}