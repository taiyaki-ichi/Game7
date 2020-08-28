#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameData.hpp"

namespace Game
{
	class SceneBase : public GameLib::Actor
	{
	protected:
		GameData mGameData;

	private:
		unsigned int mFlag;
	protected:
		void UpFlag(unsigned int);
		void DownFlag(unsigned int);

	public:
		SceneBase(GameLib::Actor*, const GameData&);

		//ゲームデータの変更を反映させる必要があるとき
		//Gameクラスが呼び出す
		const GameData& GetGameData() const;

		bool CheckFlag(unsigned int);
		//どれか1つでも立っていればtrue
		bool CheckFlag();
	};
}