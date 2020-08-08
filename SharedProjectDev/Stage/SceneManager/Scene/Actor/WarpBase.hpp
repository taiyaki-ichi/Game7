#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/Math/Vector2.hpp"

namespace Stage
{

	class WarpBase : public ActorBase
	{
	private:
		std::string mNameTag;
		std::string mDestinationNameTag;

	public:

		//データ取得用
		constexpr static char TYPE[] = "WarpType";
		constexpr static char NAMETAG[] = "NameTag";
		constexpr static char DESTINATION_NAMETAG[] = "DestinationNameTag";

		WarpBase(GameLib::Actor* scene);
		virtual ~WarpBase();

		const std::string& GetNameTag() const;

		//Warpの時Playerの移動に使用
		virtual const GameLib::Vector2& GetPosition() const = 0;

		//Playerがここに飛んでくるときの通知用
		virtual void PlayerWarpHere() {};

	protected:
		//PlayerをWarpさすとき呼び出す
		void WarpPlayer();

		void SetNameTags(std::string&& my, std::string&& dedtiantion);

	};
}