#include"Kakko.hpp"
#include"KakkoParam.hpp"
#include"GameLib/include/Math/Numbers.hpp"

namespace Game
{
	Kakko::Kakko(GameLib::Actor* actor)
		:GameLib::Actor{actor}
		, mPosition{}
		, mWidth{}
		, mHeight{}
		, mCnt{}
		, mTexture1{"../Assets/TitleScene/kakko.png"}
		, mTexture2{ "../Assets/TitleScene/kakko.png" }
		, mTexture3{ "../Assets/TitleScene/kakko.png" }
		, mTexture4{ "../Assets/TitleScene/kakko.png" }
	{
		using namespace KakkoParam;

		mTexture1.SetScale(TEXTURE_SCALE);
		mTexture2.SetScale(TEXTURE_SCALE);
		mTexture3.SetScale(TEXTURE_SCALE);
		mTexture4.SetScale(TEXTURE_SCALE);

		mTexture2.SetRotation(GameLib::PI / 2.f);
		mTexture3.SetRotation(GameLib::PI);
		mTexture4.SetRotation(GameLib::PI / 2.f * 3.f);
	}

	void Kakko::CustomizeUpdate()
	{
		auto posAdjust = GameLib::Vector2{ mWidth / 2.f,mHeight / 2.f };
		auto xy = KakkoParam::MOVE_LENGTH * std::sin(mCnt * KakkoParam::ROT_PER_FLAME);
		auto moveAdjust = GameLib::Vector2{ xy,xy };

		auto updateTexture = [this, &posAdjust, &moveAdjust](GameLib::DrawTexture& texture)
		{
			float rot = texture.GetRotation();
			texture.SetPosition(mPosition + GameLib::Vector2::Rotation(posAdjust, rot) + GameLib::Vector2::Rotation(moveAdjust, rot));
		};

		updateTexture(mTexture1);
		updateTexture(mTexture2);
		updateTexture(mTexture3);
		updateTexture(mTexture4);

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


}