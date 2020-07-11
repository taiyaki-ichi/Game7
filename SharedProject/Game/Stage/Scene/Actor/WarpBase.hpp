#pragma once
#include"ActorBase.hpp"
#include"GameLib/include/Math/Vector2.hpp"


namespace Game::Stage
{
	class WarpBase : public ActorBase
	{
		std::string mThisNameTag;
		std::string mDestinationNameTag;

		GameLib::Vector2 mPosition;

	public:
		WarpBase(Scene* scene,const GameLib::Vector2& pos);
		virtual ~WarpBase();

		void SetStringInfo(std::string&& nameTag, std::string&& destinationNameTag);

		const GameLib::Vector2& GetPosition() const noexcept;
		const std::string& GetNameTag() const noexcept;

		//DestinationNameTagへワープ
		void WarpPlayer();

		//プレーやがここに飛んでくるときの通知用
		virtual void PlayerWarpHere() {};
	};
}