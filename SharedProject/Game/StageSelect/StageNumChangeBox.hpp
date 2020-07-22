#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"
#include"GameLib/include/Draw/DrawFontText.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace Game::StageSelect
{
	class StageSelect;

	class StageNumChangeBox : public GameLib::Actor
	{
		GameLib::DrawFontText mNumText;
		GameLib::DrawFontText mStageText;
		GameLib::DrawRect mRect;
		GameLib::Collider mCollider;

		int mCooldownCnt;

	public:
		StageNumChangeBox(StageSelect* owner, const GameLib::Vector2& pos);
		virtual ~StageNumChangeBox() = default;

		void CustomizeUpdate() override;

	};
}