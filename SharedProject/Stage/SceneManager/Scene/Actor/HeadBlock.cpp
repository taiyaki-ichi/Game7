#include"HeadBlock.hpp"
#include"HeadBlock/HeadBlockParam.hpp"
#include"HeadBlock/HeadBlockFlag.hpp"
#include"HeadBlock/HeadBlockActive.hpp"

namespace Stage
{
	HeadBlock::HeadBlock(GameLib::Actor* actor)
		:ActorBase{actor}
		, mAnim{}
		, mRect{}
		, mStateManager{}
	{
		using namespace HeadBlockParam;

		mAnim.AddAnimation({ "../Assets/Object/HeadBlock/stay.png" });
		mAnim.AddAnimation({ "../Assets/Object/HeadBlock/mugyu.png" });
		mAnim.AddAnimation({ "../Assets/Object/HeadBlock/he.png" });

		mAnim.SetDrawOrder(HEAD_ANIM_DRAWORDER);
		mAnim.SetScale(SCALE);

		mRect.SetWidthAndHeight(WIDTH, HEIGHT);
		mRect.SetScale(SCALE);
		mRect.SetDrawOrder(WHITE_RECT_DRAWORDER);
		mRect.SetColor({ 255,255,255,255 });
	}

	void HeadBlock::Update()
	{
		mAnim.Update();
		mStateManager.Update();

		mRect.SetPosition(mAnim.GetPosition());
		mRect.SetRotation(mAnim.GetRotation());

		if (mStateManager.CheckFlag(HeadBlockFlag::DEATH_FLAG))
			SetState(GameLib::Actor::State::Dead);
	}

	void HeadBlock::BeginWorking()
	{
		mAnim.SetIsAutoDrawing(true);
		mRect.SetIsAutoDrawing(true);
		mStateManager.BeginWorking();
	}

	void HeadBlock::BeginToRest()
	{
		mAnim.SetIsAutoDrawing(false);
		mRect.SetIsAutoDrawing(false);
		mStateManager.BeginToRest();
	}

	void HeadBlock::LoadPosData(std::vector<GameLib::Vector2>&& data)
	{
		mAnim.SetPosition(data[0]);
		mRect.SetPosition(data[0]);

		mStateManager.SetStartState(new HeadBlockState::Active{ &mAnim });
	}
}