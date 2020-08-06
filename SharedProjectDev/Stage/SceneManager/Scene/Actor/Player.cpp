#include"Player.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Player/PlayerActive.hpp"

namespace Stage
{
	GameLib::Vector2 Player::mPosition{};

	Player::Player(GameLib::Actor* sceneManager)
		:ActorBase{ sceneManager ,-10}
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
		mAnimation.SetAnimationFPS(20);

		
	}

	void Player::Update()
	{
		mStateManager.Update();
		mPosition = mAnimation.GetPosition();
		std::cout << mPosition.x << "," << mPosition.y << "\n";
	}

	void Player::BeginWorking()
	{
		mStateManager.BeginWorking();
		SetState(GameLib::Actor::State::Active);
		mAnimation.SetIsAutoDrawing(false);
	}

	void Player::BeginToRest()
	{
		mStateManager.BeginToRest();
		SetState(GameLib::Actor::State::Pause);
		mAnimation.SetIsAutoDrawing(true);
	}

	void Player::LoadData(std::vector<float>&& data)
	{
		
		mAnimation.SetPosition(GameLib::Vector2{ data[0],data[1] });
		mStateManager.SetStartState(new PlayerState::Active{ &mAnimation });
		
	}

	void Player::SetPosition(const GameLib::Vector2& pos)
	{
		mStateManager.SetPosiotion(pos);
		mPosition = pos;
	}

	
	const GameLib::Vector2& Player::GetPosition()
	{
		return mPosition;
	}

	void Player::ResetPotentialPower()
	{
		mStateManager.ResetPotentialPower();
	}

}