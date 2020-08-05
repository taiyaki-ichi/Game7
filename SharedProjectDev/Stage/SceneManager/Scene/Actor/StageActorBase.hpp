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
	public:

		ActorBase(GameLib::Actor* owner, int updateOrder = 0);
		virtual ~ActorBase() = default;

		void CustomizeUpdate() override final;

		//更新するかどうか、Actorが画面外で落下しないようにするためなどに使用
		//デフォルトはステージが回転中出なければ更新
		virtual bool UpdateOrNot() {
			return StageIsNotRotation();
		}

		//UpdateOrNotがtrueの時CustomizeUpdate内で呼び出される
		virtual void Update() {}

		virtual void BeginWorking() = 0;
		virtual void BeginToRest() = 0;

		virtual void LoadData(std::vector<float>&& data) = 0;


	private:
		//UpdateOrNotで使用可、ステージが回転中じゃあなければtrue
		bool StageIsNotRotation();
	};
}