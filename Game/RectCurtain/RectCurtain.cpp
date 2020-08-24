#include"RectCurtain.hpp"
#include"RectCurtainParam.hpp"
#include"Stage/WindowSize.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"

namespace Game
{
	RectCurtain::RectCurtain(GameLib::Actor* actor)
		:GameLib::Actor{ actor ,100}
		, mRect{}
		, mState{0}
	{
		mRect.SetColor({ 0,0,0,255 });
		mRect.SetWidthAndHeight(Stage::WindowSize::WIDTH, 0.f);
		mRect.SetPosition({ GameLib::Viewport::GetPos().x,Stage::WindowSize::HEIGHT / 2.f });
		mRect.SetDrawOrder(100);
		mRect.SetRotation(GameLib::Viewport::GetRotation());
	}

	void RectCurtain::CustomizeUpdate()
	{
		float h = mRect.GetHeight();
		if (mState != 0)
		{
			h += (mState == -1) ? RectCurtainParam::SPEED : -RectCurtainParam::SPEED;

			if (h < 0.f) {
				h = 0.f;
				mState = 0;
			}
			if (h > RectCurtainParam::MAX_HEIGHT) {
				h = RectCurtainParam::MAX_HEIGHT;
				mState = 0;
			}
		}
		mRect.SetWidthAndHeight(Stage::WindowSize::WIDTH, h);

		using namespace GameLib;
		mRect.SetRotation(Viewport::GetRotation());
		auto adjust = Vector2::Rotation(Vector2{ 0.f,Stage::WindowSize::HEIGHT / 2.f - h / 2.f }, -Viewport::GetRotation());
		auto pos = AffineInv(adjust, Viewport::GetPos(), -Viewport::GetRotation(), Viewport::GetScale());
		mRect.SetPosition(std::move(pos));
	}

	bool RectCurtain::IsOpen()
	{
		return mRect.GetHeight() <= 0.f;
	}

	bool RectCurtain::IsClose()
	{
		return mRect.GetHeight() >= RectCurtainParam::MAX_HEIGHT;
	}

	void RectCurtain::Open()
	{
		mState = 1;

		using namespace GameLib;
		mRect.SetRotation(Viewport::GetRotation());
		auto adjust = Vector2::Rotation(Vector2{ 0.f,Stage::WindowSize::HEIGHT / 2.f - RectCurtainParam::MAX_HEIGHT / 2.f }, -Viewport::GetRotation());
		auto pos = AffineInv(adjust, Viewport::GetPos(), -Viewport::GetRotation(), Viewport::GetScale());
		mRect.SetPosition(std::move(pos));
	}

	void RectCurtain::Close()
	{
		mState = -1;

		using namespace GameLib;
		mRect.SetRotation(Viewport::GetRotation());
		auto adjust = Vector2::Rotation(Vector2{ 0.f,Stage::WindowSize::HEIGHT / 2.f }, -Viewport::GetRotation());
		auto pos = AffineInv(adjust, Viewport::GetPos(), -Viewport::GetRotation(), Viewport::GetScale());
		mRect.SetPosition(std::move(pos));
	}
	
}