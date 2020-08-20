#include"Trampoline.hpp"
#include"Trampoline/TrampolineParam.hpp"

namespace Stage
{
	Trampoline::Trampoline(GameLib::Actor* actor,Dir4&& dir)
		:ActorBase{actor}
		, mTexture{ "../Assets/Object/Trampoline/001.png" }
		, mCollider{"UpTrampoline"}
	{
		mTexture.SetScale(TrampolineParam::SCALE);
		
		mCollider.SetScale(TrampolineParam::SCALE);
		mCollider.SetWidthAndHeith(TrampolineParam::WIDTH, TrampolineParam::HEIGHT);
		mCollider.SetColor({ 0,255,0,255 });

		float rot = 0.f;
		if (dir == Dir4::Right)
		{
			rot = GameLib::PI * 3.f / 2.f;
			mCollider.SetNameTag("RightTrampoline");
		}
		else if (dir == Dir4::Down)
		{
			rot = GameLib::PI;
			mCollider.SetNameTag("DownTrampoline");
		}
		else if (dir == Dir4::Left)
		{
			rot = GameLib::PI / 2.f;
			mCollider.SetNameTag("LeftTrampoline");
		}
		
		mTexture.SetRotation(rot);
		mCollider.SetRotation(rot);	
	}

	void Trampoline::BeginWorking()
	{
		mTexture.SetIsAutoDrawing(true);
		mCollider.Active();
	}

	void Trampoline::BeginToRest()
	{
		mTexture.SetIsAutoDrawing(false);
		mCollider.Pause();
	}

	void Trampoline::LoadPosData(std::vector<GameLib::Vector2>&& data)
	{
		mTexture.SetPosition(data[0]);
		mCollider.SetPosition(data[0]);
	}
}