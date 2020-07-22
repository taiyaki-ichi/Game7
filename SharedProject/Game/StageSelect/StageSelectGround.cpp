#include"StageSelectGround.hpp"
#include"StageSelect.hpp"

namespace Game::StageSelect
{
	Ground::Ground(StageSelect* stageSelect, const GameLib::Vector2& pos, float w, float h)
		:GameLib::Actor{stageSelect}
		, mCollider{}
		, mRect{}
	{
		mCollider.SetNameTag("Ground");

		mCollider.SetPosition(pos);
		mRect.SetPosition(pos);

		mCollider.SetWidthAndHeith(w, h);
		mRect.SetWidthAndHeight(w, h);

		mRect.SetColor({ 50,50,50,255 });

	}
	void Ground::SetPosition(const GameLib::Vector2& pos)
	{
		mCollider.SetPosition(pos);
		mRect.SetPosition(pos);
	}
	void Ground::SetWidthAndHeight(float w, float h)
	{
		mCollider.SetWidthAndHeith(w, h);
		mRect.SetWidthAndHeight(w, h);
	}
}