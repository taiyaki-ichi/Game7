#include"GameLib/include/Draw/DrawTexture.hpp"
#include"GameLib/include/Resource/ResourceManager.hpp"
#include"GameLib/src/Windows/Graphics.hpp"
#include"Manager/DrawManager.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"GameLib/src/Windows/Window.hpp"


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

	DrawTexture::DrawTexture(const Vector2& pos, float scale, float rot, int drawOrder)
		:DrawBase(drawOrder)
		, mPosition(pos)
		, mScale(scale)
		, mRotation(rot)
		, mAlpha(255)
		, mTextureFlip(TextureFlip::None)
		,mTexture(nullptr)
	{
	}

	DrawTexture::DrawTexture(int drawOrder)
		:DrawBase(drawOrder)
		, mPosition({0.f,0.f})
		,mScale(1.f)
		,mRotation(0.f)
		,mAlpha(255)
		,mTextureFlip(TextureFlip::None)
		,mTexture(nullptr)
	{
	}

	void DrawTexture::Draw()
	{
		Vector2 affinedPos = Affine(mPosition, Viewport::GetPos(), Viewport::GetRotation(), Viewport::GetScale());
		Vector2 pos = { affinedPos.x + GetWindowWidth() / 2.f,-affinedPos.y + GetWindowHeigth() / 2.f };
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
	void DrawTexture::SetPosition(const Vector2& pos)
	{
		mPosition = pos;
	}
	void DrawTexture::SetScale(float scale)
	{
		mScale = scale;
	}
	void DrawTexture::SetRotation(float rot)
	{
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