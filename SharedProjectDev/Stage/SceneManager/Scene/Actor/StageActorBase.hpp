#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include<vector>
#include<unordered_map>
#include<string>

namespace Stage
{
	class ActorBase : public GameLib::Actor
	{
	protected:
		//コンストラクタ内では使えない
		const GameLib::Vector2& GetPlayerPos() const;

	public:

		ActorBase(GameLib::Actor* owner);
		virtual ~ActorBase() = default;

		virtual void Active() = 0;
		virtual void Pause() = 0;

		virtual void LoadData(std::vector<float>&& data, std::unordered_map<std::string, std::string>&& stringData) = 0;

	};
}