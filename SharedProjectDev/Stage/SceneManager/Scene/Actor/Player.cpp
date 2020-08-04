#include"Player.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Player/PlayerStateManager.hpp"

namespace Stage
{
	Player::Player(GameLib::Actor* sceneManager)
		:ActorBase{ sceneManager }
		, mAnimation{}
		, mStateManager{nullptr}
	{
		mAnimation.AddAnimation({ "../Assets/Player/stay001.png" });
		mAnimation.AddAnimation({ "../Assets/Player/run001.png","../Assets/Player/run002.png" ,"../Assets/Player/run003.png","../Assets/Player/run002.png" });
		mAnimation.AddAnimation({ "../Assets/Player/up.png" });
		mAnimation.AddAnimation({ "../Assets/Player/down.png" });
		mAnimation.AddAnimation({ "../Assets/Player/death.png" });
		mAnimation.SetScale(0.1f);
		mAnimation.SetDrawOrder(50);
	}

	void Player::Active()
	{
		if (mStateManager)
			mStateManager->Active();
		SetState(GameLib::Actor::State::Active);
		mAnimation.SetIsAutoDrawing(false);
	}

	void Player::Pause()
	{
		if (mStateManager)
			mStateManager->Pause();
		SetState(GameLib::Actor::State::Pause);
		mAnimation.SetIsAutoDrawing(true);
	}

	void Player::LoadData(std::vector<float>&& data)
	{
		mAnimation.SetPosition(GameLib::Vector2{ data[0],data[1] });
		mStateManager = new PlayerStateManager{ this,&mAnimation };
	}

	void Player::SetPosition(const GameLib::Vector2& pos)
	{
		if (mStateManager)
			mStateManager->SetPosition(pos);
	}

	
	const GameLib::Vector2& Player::GetPosition() const
	{
		return mAnimation.GetPosition();
	}

}