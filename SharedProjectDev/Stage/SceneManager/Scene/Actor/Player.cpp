#include"Player.hpp"

namespace Stage
{
	Player::Player(GameLib::Actor* sceneManager)
		:ActorBase{ sceneManager }
		, mPos{}
	{

	}

	void Player::Active()
	{
	}

	void Player::Pause()
	{
	}

	void Player::LoadData(std::vector<float>&& data, std::unordered_map<std::string, std::string>&& stringData)
	{
	}

	std::optional<std::pair<std::string, std::string>> Player::GetWarpNameTag()
	{
		return std::nullopt;
	}

	void Player::Warp(const GameLib::Vector2& pos)
	{
	}

	const GameLib::Vector2& Player::GetPosition() const
	{
		return mPos;
	}

}