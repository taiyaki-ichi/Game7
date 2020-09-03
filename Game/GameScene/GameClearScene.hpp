#pragma once
#include"GameSceneBase.hpp"

namespace Game
{
	class ClearScenePartsBase;

	class ClearScene : public SceneBase
	{
		ClearScenePartsBase* mClearSceneBase;

	public:
		ClearScene(GameLib::Actor*,const GameData&);

		void CustomizeUpdate();
	};
}