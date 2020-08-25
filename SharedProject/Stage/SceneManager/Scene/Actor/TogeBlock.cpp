#include"TogeBlock.hpp"
#include"TogeBlock/TogeBlockParam.hpp"

namespace Stage
{
	TogeBlock::TogeBlock(GameLib::Actor* actor)
		:ActorBase{actor}
		, mTexture{ "../Assets/Object/TogeBlock/001.png" }
		, mCollder{ "TogeBlock" }
	{
		using namespace TogeBlockParam;

		mTexture.SetScale(SCALE);

		mCollder.SetWidthAndHeith(WIDTH, HEIGHT);
		mCollder.SetScale(SCALE);
		mCollder.SetColor({ 0,0,255,255 });
	}

	void TogeBlock::BeginWorking()
	{
		mTexture.SetIsAutoDrawing(true);
		mCollder.Active();
	}

	void TogeBlock::BeginToRest()
	{
		mTexture.SetIsAutoDrawing(false);
		mCollder.Pause();
	}

	void TogeBlock::LoadPosData(std::vector<GameLib::Vector2>&& data)
	{
		mTexture.SetPosition(data[0]);
		mCollder.SetPosition(data[0]);
	}
}