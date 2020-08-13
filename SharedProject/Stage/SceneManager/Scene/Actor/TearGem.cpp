#include"TearGem.hpp"
#include"TearGem/TearGemParam.hpp"

namespace Stage
{
	TearGem::TearGem(GameLib::Actor* actor)
		:ActorBase{ actor }
		, mTexture{ "../Assets/Item/Gem/tear.png" }
		, mPosition{}
		, mNumber{}
		, mCollider{"TearGem"}
		, mCnt{0}
	{
		mTexture.SetScale(TearGemParam::SCALE);

		mCollider.SetScale(TearGemParam::SCALE);
		mCollider.SetWidthAndHeith(TearGemParam::WIDTH, TearGemParam::HEIDHT);
		mCollider.SetColor({ 0,255,0,255 });
	}

	void TearGem::Update()
	{
		auto adjust = std::sin(mCnt / 30.f) * GameLib::Vector2{ 0.f, TearGemParam::MOVE_LENGTH_Y };
		mTexture.SetPosition(mPosition + adjust);
		mCollider.SetPosition(mPosition + adjust + GameLib::Vector2{ 0.f,TearGemParam::COLLIDER_ADJUST_Y });
		mCnt++;
	}

	void TearGem::BeginWorking()
	{
		mTexture.SetIsAutoDrawing(true);
		mCollider.Active();
	}

	void TearGem::BeginToRest()
	{
		mTexture.SetIsAutoDrawing(false);
		mCollider.Pause();
	}

	void TearGem::LoadPosData(std::vector<GameLib::Vector2>&& data)
	{
		mPosition = std::move(data[0]);
	}

	void TearGem::LoadStringData(std::vector<std::string>&& data)
	{
		if (data[0] == "1")
			mNumber = 1;
		else if (data[0] == "2")
			mNumber = 2;
		else if (data[0] == "3")
			mNumber = 3;
	}

}