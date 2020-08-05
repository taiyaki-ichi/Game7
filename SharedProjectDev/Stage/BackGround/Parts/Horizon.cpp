#include"Horizon.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"

namespace Stage::BackGround
{
	Horizon::Horizon(GameLib::Actor* owner)
		:GameLib::Actor{ owner }
		, mRect1{}
		, mRect2{}
		, mRect3{}
	{
		mRect1.SetWidthAndHeight(1000.f, 1000.f);
		mRect2.SetWidthAndHeight(1000.f, 1000.f);
		mRect3.SetWidthAndHeight(1000.f, 1000.f);

		mRect1.SetColor({ 230,230,230,255 });
		mRect2.SetColor({ 180,180,180,255 });
		mRect3.SetColor({ 130,130,130,255 });

		mRect1.SetDrawOrder(-200);
		mRect2.SetDrawOrder(-150);
		mRect3.SetDrawOrder(-100);
	}

	void Horizon::CustomizeUpdate()
	{
		auto pos = GameLib::Viewport::GetPos();
		float rate1 = 0.9f;
		float rate2 = 0.7f;
		float rate3 = 0.5f;

		//StageÇÃèdóÕÇ≈ÇÕÇ»Ç≠ÅAViewPortÇÃRotàÀë∂Ç…ÇµÇΩ
		pos = GameLib::Vector2::Rotation(pos, GameLib::Viewport::GetRotation());

		mRect1.SetPosition(GameLib::Vector2{ pos.x,-400.f + pos.y * rate1 });
		mRect2.SetPosition(GameLib::Vector2{ pos.x,-500.f + pos.y * rate2 });
		mRect3.SetPosition(GameLib::Vector2{ pos.x,-600.f + pos.y * rate3 });

	}
}