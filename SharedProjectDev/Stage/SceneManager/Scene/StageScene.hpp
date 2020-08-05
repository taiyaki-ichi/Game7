#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"ActorInfo.hpp"
#include"StageActorPolicy.hpp"

namespace Stage
{
	class Player;
	class Camera;

	//所有するAcotrはStageActorBaseの派生のみ
	//StageActorPolicy使いたいから
	class Scene : public GameLib::Actor
	{

		Camera* mCamera;

	public:
		Scene(GameLib::Actor* manager);
		virtual ~Scene() = default;

		//Playerがこのシーンに叙属しているのであればそのdataはPlayerに渡す
		//また、このシーンをActiveに
		//Playerがいないなら最初はPause
		void CreateActors(std::vector<ActorInfo>&& actorInfos,Player* player);

		void AdjustCameraPosiotion();

		void BeginWorking() {
			SetState(GameLib::Actor::State::Active);
			InvokeActors<BeginWorkingPolicy>();
		}
		void BeginToRest() {
			SetState(GameLib::Actor::State::Pause);
			InvokeActors<BeginToRestPolicy>();
		}

	
	};

}