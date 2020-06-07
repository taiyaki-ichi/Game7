#include"lib/include/Component/Draw/SpriteCompoent.hpp"
#include"lib/src/DrawManager/DrawManager.hpp"
#include"lib/include/Component/BasicActorInfo/BasicActorInfo.hpp"
#include"lib/src/Windows/Graphics.hpp"
#include"lib/src/Windows/Window.hpp"

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
		GraphicsDrawTexture(texture, info->GetPosition().x + GetWindowWidth() / 2.f, info->GetPosition().y + GetWindowHeigth() / 2.f
			, info->GetRotation(), info->GetScale(), alpha, static_cast<int>(flip));
	}

	void SpriteComponent::DrawLine(const Vector2& p1, const Vector2& p2, const Color& color)
	{
		float wHalf = GetWindowWidth() / 2.f;
		float hHalf = GetWindowHeigth() / 2.f;
		GraphicsDrawLine(p1.x + wHalf, p1.y + hHalf, p2.x + wHalf, p2.y + hHalf, color.R, color.G, color.B, color.A);
	}

	void SpriteComponent::DrawFillTriangle(const Vector2& p1, const Vector2& p2, const Vector2& p3, const Color& color)
	{
		float wHalf = GetWindowWidth() / 2.f;
		float hHalf = GetWindowHeigth() / 2.f;
		GraphicsDrawFillTriangle(p1.x + wHalf, p1.y + hHalf, p2.x + wHalf, p2.y + hHalf, p3.x + wHalf, p3.y + hHalf, color.R, color.G, color.B, color.A);
	}

}