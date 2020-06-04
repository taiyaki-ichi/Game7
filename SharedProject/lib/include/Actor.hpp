#pragma once
#include"Manager.hpp"

namespace GameLib
{

	class Component;


	struct ActorInfo;


	class Actor
	{
	public:
		Actor(Actor* owner) 
			:mOwner(owner)
		{
			//updateOrderを導入するか
			owner->Add(this);
		}
		virtual ~Actor() {
			mOwner->Remove(this);
		}

		virtual void Update() {

		}

		//ActorInfo経由で状態変更？？めんどそう。。


		void Add(Actor*);
		void Add(Component*);
		void Remove(Actor*);
		void Remove(Component*);


	private:
		Actor* mOwner;

		Manager<Actor>* mOwnedActors;
		Manager<Component>* mComponent;

		ActorInfo* mActorInfo;

		
	};

}