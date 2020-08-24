#include"TearDisplay.hpp"
#include"ItemNumParam.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"Stage/Utilty/AdjustRot.hpp"

namespace Stage
{
	TearDisplay::TearDisplay(const GameLib::Vector2& pos)
		:mTexture1{ "../Assets/Item/Gem/tear_frame.png" }
		, mTexture2{ "../Assets/Item/Gem/tear_frame.png" }
		, mTexture3{ "../Assets/Item/Gem/tear_frame.png" }
		, mAdjustPos{pos}
	{
		mTexture2.SetScale(ItemNumParam::TEAR_SCALE);
		mTexture1.SetScale(ItemNumParam::TEAR_SCALE);
		mTexture3.SetScale(ItemNumParam::TEAR_SCALE);

		mTexture1.SetDrawOrder(ItemNumParam::DRAWORDER);
		mTexture2.SetDrawOrder(ItemNumParam::DRAWORDER);
		mTexture3.SetDrawOrder(ItemNumParam::DRAWORDER);

		AdjustPos();
	}

	void TearDisplay::Get(int num)
	{
		if (num == 1)
			mTexture1.SetTexture("../Assets/Item/Gem/tear.png");
		else if (num == 2)
			mTexture2.SetTexture("../Assets/Item/Gem/tear.png");
		else if (num == 3)
			mTexture3.SetTexture("../Assets/Item/Gem/tear.png");
	}

	void TearDisplay::AdjustPos()
	{
		/*
		auto center = GameLib::Viewport::GetPos();
		float rot = GameLib::Viewport::GetRotation();
		mTexture2.SetPosition(GameLib::Vector2::Rotation(center + mAdjustPos, -rot));
		mTexture1.SetPosition(GameLib::Vector2::Rotation(center + mAdjustPos + GameLib::Vector2{ -ItemNumParam::TEAR_DISPLAY_LENGTH_X,0.f }, -rot));
		mTexture3.SetPosition(GameLib::Vector2::Rotation(center + mAdjustPos + GameLib::Vector2{ ItemNumParam::TEAR_DISPLAY_LENGTH_X,0.f }, -rot));

		mTexture1.SetRotation(rot);
		mTexture2.SetRotation(rot);
		mTexture3.SetRotation(rot);
		*/

		float viewRot = AdjustRot(GameLib::Viewport::GetRotation());
		int i = 0;
		for (; i < 4; i++)
		{
			if (std::abs(GameLib::PI / 2.f * static_cast<float>(i) - viewRot) < 0.01f)
			{
				GameLib::Vector2 pos = GameLib::Viewport::GetPos();
				float rot = GameLib::Viewport::GetRotation();

				float dir = 1.f;
				if (i == 1 || i == 3)
					dir = -1.f;

				mTexture1.SetIsAutoDrawing(true);
				mTexture2.SetIsAutoDrawing(true);
				mTexture3.SetIsAutoDrawing(true);

				mTexture2.SetPosition(GameLib::Vector2::Rotation(pos + mAdjustPos, -rot*dir));
				mTexture1.SetPosition(GameLib::Vector2::Rotation(pos + mAdjustPos + GameLib::Vector2{ -ItemNumParam::TEAR_DISPLAY_LENGTH_X,0.f }, -rot*dir));
				mTexture3.SetPosition(GameLib::Vector2::Rotation(pos + mAdjustPos + GameLib::Vector2{ ItemNumParam::TEAR_DISPLAY_LENGTH_X,0.f }, -rot * dir));

				mTexture1.SetRotation(rot);
				mTexture2.SetRotation(rot);
				mTexture3.SetRotation(rot);

				break;
			}
		}

		if (i == 4) {
			mTexture1.SetIsAutoDrawing(false);
			mTexture2.SetIsAutoDrawing(false);
			mTexture3.SetIsAutoDrawing(false);
		}
		

	}
}