#include"StageWarpBox.hpp"
#include"StageSelect.hpp"

namespace Game::StageSelect
{



	WarpBox::WarpBox(StageSelect* stageSelect, std::string&& textureFileName, int stageNum, bool isVaild)
		:GameLib::Actor{ stageSelect }
		, mCollider{}
		, mBox{ GameLib::DrawRect{} }
		, mTexture{ std::move(textureFileName) }
		,mStageNum{stageNum}
	{
		/*
		if (isVaild) {
			auto texture = GameLib::DrawTexture{ std::move(textureFileName) };
			texture.SetScale(0.1f);
			mBox = texture;
		}
		else {
			auto& rect = std::get<GameLib::DrawRect>(mBox);
			rect.SetWidthAndHeight(768.f, 768.f);
			rect.SetScale(0.1f);
		}
		*/

		mTexture.SetScale(0.1f);
		mTexture.SetDrawOrder(-10);

		mCollider.SetWidthAndHeith(768.f, 768.f);
		mCollider.SetScale(0.1f);

		//
		//
		mCollider.SetNameTag("Ground");
		//

	}
	void WarpBox::CustomizeUpdate()
	{

	}
	void WarpBox::SetPosition(const GameLib::Vector2& pos)
	{
		//std::visit([this, pos](auto& box) {box.SetPosition(pos); }, mBox);
		mTexture.SetPosition(pos);
		mCollider.SetPosition(pos);
	}
	const GameLib::Vector2& WarpBox::GetPosition() const
	{
		//return std::visit([this](auto& box)->const GameLib::Vector2& {return box.GetPosition(); }, mBox);
		return mTexture.GetPosition();
	}
	
}