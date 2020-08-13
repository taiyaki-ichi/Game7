#include"Player.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Player/PlayerActive.hpp"
#include"Player/Life/Life.hpp"
#include"Player/PlayerParam.hpp"
#include"Player/ItemNum/ItemNum.hpp"

namespace Stage
{
	GameLib::Vector2 Player::mPosition{};

	Player::Player(GameLib::Actor* sceneManager)
		:ActorBase{ sceneManager ,10}
		, mAnimation{}
		, mStateManager{nullptr}
		, mLife{nullptr}
		,mItemNum{nullptr}
	{
		mAnimation.AddAnimation({ "../Assets/Player/stay001.png" });
		mAnimation.AddAnimation({ "../Assets/Player/run001.png","../Assets/Player/run002.png" ,"../Assets/Player/run003.png","../Assets/Player/run002.png" });
		mAnimation.AddAnimation({ "../Assets/Player/up.png" });
		mAnimation.AddAnimation({ "../Assets/Player/down.png" });
		mAnimation.AddAnimation({ "../Assets/Player/stay001.png" ,"../Assets/to-mei.png" });
		mAnimation.AddAnimation({ "../Assets/Player/run001.png","../Assets/to-mei.png","../Assets/Player/run002.png" ,"../Assets/to-mei.png",
			"../Assets/Player/run003.png","../Assets/to-mei.png","../Assets/Player/run002.png" ,"../Assets/to-mei.png" });
		mAnimation.AddAnimation({ "../Assets/Player/up.png","../Assets/to-mei.png" });
		mAnimation.AddAnimation({ "../Assets/Player/down.png","../Assets/to-mei.png" });
		mAnimation.AddAnimation({ "../Assets/Player/death.png" });
		mAnimation.SetScale(0.1f);
		mAnimation.SetDrawOrder(50);
		mAnimation.SetAnimationFPS(20);

		mLife = new Life{ this ,PlayerParam::LIFE_POSITION };
		mItemNum = new ItemNum{ this,PlayerParam::ITEMNUM_POSITION,5,10 };
		
	}

	void Player::Update()
	{
		mStateManager.Update();
		mPosition = mAnimation.GetPosition();
		//std::cout <<"player pos:"<< mPosition.x << "," << mPosition.y << "\n";
		mLife->AdjustPos();
		mItemNum->AdjustPos();
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

	void Player::LoadPosData(std::vector<GameLib::Vector2>&& data)
	{
		mAnimation.SetPosition(data[0]);
		mStateManager.SetStartState(new PlayerState::Active{ &mAnimation ,mLife ,mItemNum });
		
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

	bool Player::CheckFlag(char f) {
		return mStateManager.CheckFlag(f);
	}
}