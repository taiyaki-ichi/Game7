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
	{
		mRect1.SetWidthAndHeight(1000.f, 1000.f);
		mRect2.SetWidthAndHeight(1000.f, 1000.f);
		mRect3.SetWidthAndHeight(1000.f, 1000.f);
		mRect4.SetWidthAndHeight(1000.f, 1000.f);
		mRect5.SetWidthAndHeight(1000.f, 1000.f);
		mRect6.SetWidthAndHeight(1000.f, 1000.f);

		/*
		mRect3.SetColor({ 230,230,230,255 });
		mRect2.SetColor({ 180,180,180,255 });
		mRect1.SetColor({ 130,130,130,255 });
		mRect6.SetColor({ 230,230,230,255 });
		mRect5.SetColor({ 180,180,180,255 });
		mRect4.SetColor({ 130,130,130,255 });
		*/
		mRect3.SetColor({ 120,120,120,255 });
		mRect2.SetColor({ 100,100,100,255 });
		mRect1.SetColor({ 70,70,70,255 });
		mRect6.SetColor({ 120,120,120,255 });
		mRect5.SetColor({ 100,100,100,255 });
		mRect4.SetColor({ 70,70,70,255 });


		mRect1.SetDrawOrder(-200);
		mRect2.SetDrawOrder(-150);
		mRect3.SetDrawOrder(-100);
		mRect4.SetDrawOrder(-200);
		mRect5.SetDrawOrder(-150);
		mRect6.SetDrawOrder(-100);
	}

	void Cave::CustomizeUpdate()
	{
		AdjustPos();
	}

	void Cave::AdjustPos()
	{
		auto pos = GameLib::Viewport::GetPos();
		pos = GameLib::Vector2::Rotation(pos, GameLib::Viewport::GetRotation());

		mRect1.SetPosition(GameLib::Vector2{ pos.x,-500.f + pos.y });
		mRect2.SetPosition(GameLib::Vector2{ pos.x,-600.f + pos.y });
		mRect3.SetPosition(GameLib::Vector2{ pos.x,-700.f + pos.y });
		mRect4.SetPosition(GameLib::Vector2{ pos.x,+500.f + pos.y });
		mRect5.SetPosition(GameLib::Vector2{ pos.x,+600.f + pos.y });
		mRect6.SetPosition(GameLib::Vector2{ pos.x,+700.f + pos.y });

	}
}