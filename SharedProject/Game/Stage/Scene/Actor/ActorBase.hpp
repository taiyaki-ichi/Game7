#pragma once
#include"GameLib/include/Actor/Actor.hpp"

namespace Game::Stage
{
	class Scene;

	class ActorBase : public GameLib::Actor
	{
	public:
		ActorBase(Scene* scene,int updateOrder = 0);
		virtual ~ActorBase();

		void CustomizeUpdate() override final;

		//更新するかどうか、Actorが画面外で落下しないようにするためなどに使用
		//デフォルトでtrueを返す
		virtual bool UpdateOrNot();
		virtual void ActorUpdate() {}

		//ColliderやDraw系のオンオフ
		virtual void Active() = 0;
		virtual void Pause() = 0;

		Scene* GetScene();

	protected:
		//UpdateOrNotで使用可、ステージが回転中じゃあなければtrue
		bool StageIsNotRotation();
	};
}