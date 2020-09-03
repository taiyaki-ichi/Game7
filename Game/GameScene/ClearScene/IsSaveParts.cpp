#include"IsSaveParts.hpp"
#include"IsSaveParam.hpp"
#include"Stage/Utilty/Kakko.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"ClearSceneFlag.hpp"

namespace Game
{
	IsSaveParts::IsSaveParts(GameLib::Actor* actor)
		:ClearScenePartsBase{actor}
		, mButtonA{}
		, mButtonD{}
		, mKakko{nullptr}
		, mIsSave{ "../Assets/Font/mplus-1c-black.ttf" }
		, mHai{ "../Assets/Font/mplus-1c-black.ttf" }
		, mIie{ "../Assets/Font/mplus-1c-black.ttf" }
		, mA{ "../Assets/Font/mplus-1c-black.ttf" }
		, mD{ "../Assets/Font/mplus-1c-black.ttf" }
		, mPosition{Position::A}
	{
		using namespace IsSaveParam;

		mButtonA.SetPosition(BUTTON_A_POSITION);
		mButtonA.SetWidthAndHeightAndFlameWidth(BUTTON_WIDTH, BUTTON_HEIGHT, BUTTOB_FLAME_WIDTH);

		mButtonD.SetPosition(BUTTON_D_POSITION);
		mButtonD.SetWidthAndHeightAndFlameWidth(BUTTON_WIDTH, BUTTON_HEIGHT, BUTTOB_FLAME_WIDTH);

		mKakko = new Stage::Kakko{ this };
		mKakko->SetWidthAndHeight(KAKKO_WIDTH, KAKKO_HEIGHT);
		mKakko->SetMoveLength(KAKKO_MOVE_LENGTH);
		mKakko->SetTextureScale(KAKKO_TEXTURE_SCALE);

		mIsSave.SetText("セーブしますか？");
		mIsSave.SetSize(ISSAVE_FONT_SIZE);
		mIsSave.SetPosition(ISSAVE_TEXT_POSITION);
		mIsSave.SetDrawOrder(1);

		mHai.SetText("はい");
		mHai.SetPosition(BUTTON_A_POSITION);
		mHai.SetSize(HAI_IIE_FONT_SIZE);
		mHai.SetDrawOrder(1);

		mIie.SetText("いいえ");
		mIie.SetPosition(BUTTON_D_POSITION);
		mIie.SetSize(HAI_IIE_FONT_SIZE);
		mIie.SetDrawOrder(1);

		mA.SetText("A");
		mA.SetPosition(BUTTON_A_POSITION + BUTTON_TAG_ADJUST);
		mA.SetSize(BUTTON_TAG_FONT_SIZE);
		mA.SetDrawOrder(1);

		mD.SetText("D");
		mD.SetPosition(BUTTON_D_POSITION + BUTTON_TAG_ADJUST);
		mD.SetSize(BUTTON_TAG_FONT_SIZE);
		mD.SetDrawOrder(1);

		//初期位置はA
		mPosition = Position::A;
		mButtonA.ChangeDark();
		mButtonD.ChangeWhite();
		mKakko->SetPosition(BUTTON_A_POSITION);
	}

	void IsSaveParts::CustomizeUpdate()
	{
		if (GameLib::InputState::GetState(GameLib::Key::Space) == GameLib::ButtonState::Pressed)
		{
			if (mPosition == Position::A)
				UpFlag(ClearSceneFlag::GO_SAVED_FLAG);
			else if (mPosition == Position::D)
				UpFlag(ClearSceneFlag::GO_TITLE_FLAG);
		}

		//D->A
		if (GameLib::InputState::GetState(GameLib::Key::A) == GameLib::ButtonState::Pressed &&
			mPosition == Position::D)
		{
			mPosition = Position::A;
			mKakko->SetPosition(IsSaveParam::BUTTON_A_POSITION);
			mButtonA.ChangeDark();
			mButtonD.ChangeWhite();
		}

		if (GameLib::InputState::GetState(GameLib::Key::D) == GameLib::ButtonState::Pressed &&
			mPosition == Position::A)
		{
			mPosition = Position::D;
			mKakko->SetPosition(IsSaveParam::BUTTON_D_POSITION);
			mButtonD.ChangeDark();
			mButtonA.ChangeWhite();
		}


	}
}