#include"StageNumChangeBox.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"StageSelect.hpp"
#include"Game/Stage/UtilityVectorFunction.hpp"

namespace Game::StageSelect
{

	StageNumChangeBox::StageNumChangeBox(StageSelect* owner, const GameLib::Vector2& pos)
		:GameLib::Actor{owner}
		, mRect{}
		, mNumText{"../Assets/Font/mplus-1c-black.ttf"}
		, mStageText{ "../Assets/Font/mplus-1c-black.ttf" }
		, mCollider{}
		, mCooldownCnt{0}
	{
		mRect.SetPosition(pos);
		mNumText.SetPosition(pos);
		mCollider.SetPosition(pos);

		mRect.SetWidthAndHeight(70.f, 70.f);
		mCollider.SetWidthAndHeith(70.f, 70.f);

		mCollider.SetNameTag("Ground");

		mRect.SetColor({ 50,50,50,255 });

		mNumText.SetText("1");
		mNumText.SetColor({ 255,255,255,255 });
		mNumText.SetSize(GameLib::Font::Size::Size_60);
		mNumText.SetDrawOrder(10);

		mStageText.SetText("Stage");
		mStageText.SetColor({ 0,0,0,255 });
		mStageText.SetSize(GameLib::Font::Size::Size_72);
		mStageText.SetDrawOrder(10);
		mStageText.SetPosition(pos + GameLib::Vector2{ 0.f,80.f });

		auto hitPlayer = [this](const GameLib::Collider& c) {
			auto adjust = Stage::GetParallelRectAdjustVec(mCollider, c);
			if (mCooldownCnt == 0 && adjust.y > 0.f) {

				int num = std::stoi(mNumText.GetText());
				num++;
				if (num > STAGE_NUM)
					num = 1;
				mNumText.SetText(std::to_string(num));
				auto stageSelect = static_cast<StageSelect*>(mOwner);
				stageSelect->ChangeStageNum(num);
				mCooldownCnt = 30;
			}
		};
		mCollider.AddHitFunction("Player", std::move(hitPlayer));

	}
	void StageNumChangeBox::CustomizeUpdate()
	{
		if (mCooldownCnt > 0)
			mCooldownCnt--;

	}
}