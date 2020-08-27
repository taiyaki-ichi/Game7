#include"Cave.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"

namespace Stage
{
	Cave::Cave(GameLib::Actor* actor)
		:GameLib::Actor{actor}
		, mRect1{}
		, mRect2{}
		, mRect3{}
		, mRect4{}
		, mRect5{}
		, mRect6{}
		, mRectCenter{}
	{
		mRect1.SetWidthAndHeight(1000.f, 1000.f);
		mRect2.SetWidthAndHeight(1000.f, 1000.f);
		mRect3.SetWidthAndHeight(1000.f, 1000.f);
		mRect4.SetWidthAndHeight(1000.f, 1000.f);
		mRect5.SetWidthAndHeight(1000.f, 1000.f);
		mRect6.SetWidthAndHeight(1000.f, 1000.f);
		mRectCenter.SetWidthAndHeight(1000.f, 1000.f);
		
		mRect3.SetColor({ 230,230,230,255 });
		mRect2.SetColor({ 180,180,180,255 });
		mRect1.SetColor({ 130,130,130,255 });
		mRect6.SetColor({ 230,230,230,255 });
		mRect5.SetColor({ 180,180,180,255 });
		mRect4.SetColor({ 130,130,130,255 });

		mRectCenter.SetColor({ 80,80,80,255 });
		
		mRect1.SetDrawOrder(-200);
		mRect2.SetDrawOrder(-150);
		mRect3.SetDrawOrder(-100);
		mRect4.SetDrawOrder(-200);
		mRect5.SetDrawOrder(-150);
		mRect6.SetDrawOrder(-100);

		mRectCenter.SetDrawOrder(-250);
	}

	void Cave::CustomizeUpdate()
	{
		AdjustPos();
	}

	void Cave::AdjustPos()
	{
		auto pos = GameLib::Viewport::GetPos();
		pos = GameLib::Vector2::Rotation(pos, GameLib::Viewport::GetRotation());

		float rate1 = 0.9f;
		float rate2 = 0.8f;
		float rate3 = 0.7f;

		mRect1.SetPosition(GameLib::Vector2{ pos.x,-600.f + pos.y * rate1 });
		mRect2.SetPosition(GameLib::Vector2{ pos.x,-700.f + pos.y * rate2 });
		mRect3.SetPosition(GameLib::Vector2{ pos.x,-900.f + pos.y * rate3 });
		mRect4.SetPosition(GameLib::Vector2{ pos.x,+600.f + pos.y * rate1 });
		mRect5.SetPosition(GameLib::Vector2{ pos.x,+700.f + pos.y * rate2 });
		mRect6.SetPosition(GameLib::Vector2{ pos.x,+900.f + pos.y * rate3 });

		mRectCenter.SetPosition(pos);

	}
}