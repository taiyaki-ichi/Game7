#include"Kakko.hpp"
#include"KakkoParam.hpp"
#include"GameLib/include/Math/Numbers.hpp"

namespace Stage
{
	Kakko::Kakko(GameLib::Actor* actor,int drawOder)
		:GameLib::Actor{ actor }
		, mPosition{}
		, mWidth{}
		, mHeight{}
		, mCnt{}
		, mTexture1{ "../Assets/TitleScene/kakko.png" }
		, mTexture2{ "../Assets/TitleScene/kakko.png" }
		, mTexture3{ "../Assets/TitleScene/kakko.png" }
		, mTexture4{ "../Assets/TitleScene/kakko.png" }
		, mMoveLength{}
		, mRot{}
	{
		using namespace KakkoParam;

		/*
		mTexture1.SetScale(TEXTURE_SCALE);
		mTexture2.SetScale(TEXTURE_SCALE);
		mTexture3.SetScale(TEXTURE_SCALE);
		mTexture4.SetScale(TEXTURE_SCALE);
		*/

		SetTexturesRot();

		mTexture1.SetDrawOrder(drawOder);
		mTexture2.SetDrawOrder(drawOder);
		mTexture3.SetDrawOrder(drawOder);
		mTexture4.SetDrawOrder(drawOder);
	}

	void Kakko::CustomizeUpdate()
	{
	
		SetTexturesRot();

		auto xy = mMoveLength * std::sin(mCnt * KakkoParam::ROT_PER_FLAME);
		auto moveAdjust = GameLib::Vector2{ xy,xy };

		auto updateTexture = [this, &moveAdjust](GameLib::DrawTexture& texture,GameLib::Vector2&& adjust)
		{
			float rot = texture.GetRotation();
			texture.SetPosition(mPosition + adjust + GameLib::Vector2::Rotation(moveAdjust, rot));
		};

		auto adjust1 = GameLib::Vector2::Rotation({ mWidth / 2.f,mHeight / 2.f }, mRot);
		updateTexture(mTexture1, std::move(adjust1));
		auto adjust2 = GameLib::Vector2::Rotation({ -mWidth / 2.f,mHeight / 2.f }, mRot);
		updateTexture(mTexture2, std::move(adjust2));
		auto adjust3 = GameLib::Vector2::Rotation({ -mWidth / 2.f,-mHeight / 2.f }, mRot);
		updateTexture(mTexture3, std::move(adjust3));
		auto adjust4 = GameLib::Vector2::Rotation({ mWidth / 2.f,-mHeight / 2.f }, mRot);
		updateTexture(mTexture4, std::move(adjust4));

		mCnt++;
	}

	void Kakko::SetWidthAndHeight(float w, float h)
	{
		mWidth = w;
		mHeight = h;
	}

	void Kakko::SetPosition(const GameLib::Vector2& pos)
	{
		mPosition = pos;
	}

	void Kakko::SetMoveLength(float l)
	{
		mMoveLength = l;
	}

	void Kakko::SetTextureScale(float scale)
	{
		mTexture1.SetScale(scale);
		mTexture2.SetScale(scale);
		mTexture3.SetScale(scale);
		mTexture4.SetScale(scale);
	}

	void Kakko::SetRotation(float rot)
	{
		mRot = rot;
	}

	void Kakko::SetTexturesRot()
	{
		mTexture1.SetRotation(mRot);
		mTexture2.SetRotation(GameLib::PI / 2.f + mRot);
		mTexture3.SetRotation(GameLib::PI + mRot);
		mTexture4.SetRotation(GameLib::PI / 2.f * 3.f + mRot);
	}
}