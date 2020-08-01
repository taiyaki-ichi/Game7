#include"StageWarpBox.hpp"
#include"Game/Stage/UtilityVectorFunction.hpp"

namespace Game::StageSelect
{



	WarpBox::WarpBox(GameLib::Actor* stageSelect, std::string&& textureFileName, int stageNum, bool isVaild)
		:GameLib::Actor{ stageSelect }
		, mCollider{}
		, mTexture{ std::move(textureFileName) }
		, mRect{}
		, mFlag{0}
	{


		mTexture.SetScale(0.1f);
		mTexture.SetDrawOrder(-10);

		mRect.SetWidthAndHeight(768.f, 768.f);
		mRect.SetScale(0.1f);
		mRect.SetDrawOrder(-10.f);

		mCollider.SetWidthAndHeith(768.f, 768.f);
		mCollider.SetScale(0.1f);

		if (isVaild) {
			mRect.SetIsAutoDrawing(false);
		}
		else {
			mTexture.SetIsAutoDrawing(false);
			mCollider.SetDoCollisionDetection(false);
		}

		mCollider.SetNameTag("Ground");

		auto hitPlayer = [this](const GameLib::Collider& c) {
			auto adjust = Stage::GetParallelRectAdjustVec(mCollider, c);
			if (adjust.y > 0.f) {

				//auto stageSelectPtr = static_cast<StageSelect*>(mOwner);
				//stageSelectPtr->GoStage(mStageNum);
				mFlag = 1;
			}
		};

		mCollider.AddHitFunction("Player", std::move(hitPlayer));

	}
	void WarpBox::CustomizeUpdate()
	{

	}
	void WarpBox::SetPosition(const GameLib::Vector2& pos)
	{
		mRect.SetPosition(pos);
		mTexture.SetPosition(pos);
		mCollider.SetPosition(pos);
	}
	const GameLib::Vector2& WarpBox::GetPosition() const
	{
		return mTexture.GetPosition();
	}

	int WarpBox::GetFlag()
	{
		return mFlag;
	}
	
}