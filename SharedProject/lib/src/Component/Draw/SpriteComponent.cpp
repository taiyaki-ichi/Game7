#include"lib/include/Component/Draw/SpriteCompoent.hpp"
#include"lib/src/DrawManager/DrawManager.hpp"
#include"lib/include/Component/BasicActorInfo/BasicActorInfo.hpp"
#include"lib/src/Windows/Graphics.hpp"
#include"lib/src/Windows/Window.hpp"
#include"lib/include/Viewport/Viewport.hpp"
#include"lib/include/Math/Vector2Func.hpp"

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


	//y*-1,(x,y)+(windowWidth/2.f,windowHeigth/2.f)‚ÅWindows‚ÌÀ•WŒn‚Ö•ÏŠ·
	Vector2&& ToWindowsPoint(Vector2&& vec) {
		return { vec.x + GetWindowWidth() / 2.f,-vec.y + GetWindowHeigth()/2.f };
	}

	void SpriteComponent::DrawTexture(Texture* texture, BasicActorInfo* info,int alpha,const TextureFlip& flip)
	{
		Vector2 affinedPos = Affine(info->GetPosition(), Viewport::GetPos(), Viewport::GetRotation(), Viewport::GetScale());
		Vector2 pos = ToWindowsPoint(std::move(affinedPos));
		GraphicsDrawTexture(texture, pos.x, pos.y
			, info->GetRotation() + Viewport::GetRotation(), info->GetScale() * Viewport::GetScale(), alpha, static_cast<int>(flip));
	}

	void SpriteComponent::DrawLine(const Vector2& p1, const Vector2& p2, const Color& color)
	{
		Vector2 affinedPos1 = Affine(p1, Viewport::GetPos(), Viewport::GetRotation(), Viewport::GetScale());
		Vector2 affinedPos2 = Affine(p2, Viewport::GetPos(), Viewport::GetRotation(), Viewport::GetScale());
		Vector2 pos1 = ToWindowsPoint(std::move(affinedPos1));
		Vector2 pos2 = ToWindowsPoint(std::move(affinedPos2));
		GraphicsDrawLine(pos1.x, pos1.y, pos2.x, pos2.y, color.R, color.G, color.B, color.A);
	}

	void SpriteComponent::DrawFillTriangle(const Vector2& p1, const Vector2& p2, const Vector2& p3, const Color& color)
	{
		float wHalf = GetWindowWidth() / 2.f;
		float hHalf = GetWindowHeigth() / 2.f;
		Vector2 affinedPos1 = Affine(p1, Viewport::GetPos(), Viewport::GetRotation(), Viewport::GetScale());
		Vector2 affinedPos2 = Affine(p2, Viewport::GetPos(), Viewport::GetRotation(), Viewport::GetScale());
		Vector2 affinedPos3 = Affine(p3, Viewport::GetPos(), Viewport::GetRotation(), Viewport::GetScale());
		Vector2 pos1 = ToWindowsPoint(std::move(affinedPos1));
		Vector2 pos2 = ToWindowsPoint(std::move(affinedPos2));
		Vector2 pos3 = ToWindowsPoint(std::move(affinedPos3));
		GraphicsDrawFillTriangle(affinedPos1.x + wHalf, affinedPos1.y + hHalf, affinedPos2.x + wHalf, affinedPos2.y + hHalf, 
			affinedPos3.x + wHalf, affinedPos3.y + hHalf, color.R, color.G, color.B, color.A);
	}

}