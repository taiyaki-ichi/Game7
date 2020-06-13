#include"lib/include/Draw/DrawTexture.hpp"
#include"lib/include/Resource/ResourceManager.hpp"
#include"lib/src/Windows/Graphics.hpp"
#include"Manager/DrawManager.hpp"
#include"lib/include/Math/Vector2Func.hpp"
#include"lib/include/Viewport/Viewport.hpp"
#include"lib/src/Windows/Window.hpp"

namespace GameLib
{
	DrawTexture::DrawTexture(std::string&& fileName, const Vector2& pos, float scale, float rot, int drawOrder)
		:DrawBase(drawOrder)
		,mPosition(pos)
		,mScale(scale)
		,mRotation(rot)
		,mAlpha(255)
		,mTextureFlip(TextureFlip::None)
	{
		mTexture = ResourceManager::GetTexture(std::move(fileName));
	}

	void DrawTexture::Draw()
	{
		Vector2 affinedPos = Affine(mPosition, Viewport::GetPos(), Viewport::GetRotation(), Viewport::GetScale());
		Vector2 pos = { affinedPos.x + GetWindowWidth() / 2.f,affinedPos.y + GetWindowHeigth() / 2.f };
		GraphicsDrawTexture(mTexture, pos.x, pos.y, mScale * Viewport::GetScale(), mRotation + Viewport::GetRotation(),
			mAlpha, static_cast<int>(mTextureFlip));
	}

	void DrawTexture::SetTexture(std::string&& fileName)
	{
		mTexture = ResourceManager::GetTexture(std::move(fileName));
	}

	void DrawTexture::SetTexture(Texture* texture)
	{
		mTexture = texture;
	}

	void DrawTexture::Set(const Vector2& pos, float scale, float rot)
	{
		mPosition = pos;
		mScale = scale;
		mRotation = rot;
	}
	void DrawTexture::Set(Vector2&& pos, float scale, float rot)
	{
		mPosition = std::move(pos);
		mScale = scale;
		mRotation = rot;
	}
	void DrawTexture::SetAlpha(int a)
	{
		mAlpha = a;
	}
	void DrawTexture::SetTextureFlip(TextureFlip&& flip)
	{
		mTextureFlip = std::move(flip);
	}
}