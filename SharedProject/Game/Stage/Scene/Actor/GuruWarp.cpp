#include"GuruWarp.hpp"

namespace Game::Stage
{
	GuruWarp::GuruWarp(Scene* scene,std::vector<float>&& data)
		:WarpBase{ scene,GameLib::Vector2{data[0],data[1]} }
		, mTexture{"../Assets/Object/WarpGate/grugru.png"}
		, mCollder{}
	{
		mTexture.SetScale(0.1f);
		mCollder.SetWidthAndHeith(30.f, 30.f);
		mCollder.SetColor({ 0,255,0,255 });

		auto pos = GameLib::Vector2{ data[0],data[1] };
		mTexture.ResetPosition(pos);
		mCollder.ResetPosition(pos);
		mCollder.Active();

		auto hitPlayer = [this](const GameLib::Collider& c) {
			WarpPlayer();
			mCollder.Pause();
		};
		mCollder.AddHitFunction("Player", std::move(hitPlayer));

	}

	void GuruWarp::UpdateActor()
	{
		mTexture.SetRotation(mTexture.GetRotation() + 0.03f);
	}
	void GuruWarp::Active()
	{
		mTexture.SetIsAutoDrawing(true);
		mCollder.Active();
	}
	void GuruWarp::Pause()
	{
		mTexture.SetIsAutoDrawing(false);
		mCollder.Pause();
	}
}