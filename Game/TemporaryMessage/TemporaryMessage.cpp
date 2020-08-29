#include"TemporaryMessage.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"

namespace Game
{
	TemporaryMessage::TemporaryMessage(GameLib::Actor* actor,int deathTime)
		:GameLib::Actor{actor}
		, mDeathTime{deathTime}
		, mCnt{0}
		, mText{ "../Assets/Font/mplus-1c-black.ttf" }
		, mPosition{}
	{

	}

	void TemporaryMessage::CustomizeUpdate()
	{
		if (mCnt >= mDeathTime)
			SetState(GameLib::Actor::State::Dead);
		mCnt++;

		auto pos = GameLib::Viewport::GetPos();
		mText.SetPosition(pos + mPosition);
	}

	void TemporaryMessage::SetPosition(const GameLib::Vector2& pos)
	{
		mPosition = pos;
		auto posV = GameLib::Viewport::GetPos();
		mText.SetPosition(posV + mPosition);
	}

	void TemporaryMessage::SetText(std::string&& tex)
	{
		mText.SetText(std::move(tex));
	}

	void TemporaryMessage::SetSize(GameLib::Font::Size&& size)
	{
		mText.SetSize(std::move(size));
	}
}