#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace Stage
{
	class TearGem : public ActorBase
	{
		GameLib::DrawTexture mTexture;
		GameLib::Vector2 mPosition;
		GameLib::Collider mCollider;

		int mCnt;

		//ステージの何番目のGemなのか、獲得したかしてないかの情報に使いたい
		int mNumber;

	public:
		TearGem(GameLib::Actor*);

		bool UpdateOrNot() override;
		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadPosData(std::vector<GameLib::Vector2>&&) override;
		void LoadStringData(std::vector<std::string>&&) override;

	};
}