#pragma once
#include<map>
#include<vector>
#include"StageData.hpp"
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace Game::StageSelect
{
	class PlayerIcon;

	//std::vector<GameLib::DrawTexture> mHexTextures;こいつはここで生成
	class MapDrawer;

	class HexMap : public GameLib::Actor
	{
		std::map<std::pair<int,int>, StageData> mMap;

		//移動でき塚どうか判定、アイコンの場所によってカメラ移動、
		PlayerIcon* mPlayerIcon;

	public:
		//コンストラクタ内でMap生成、ほかでは特に何もしない
		HexMap(GameLib::Actor*);

		//移動、とか
		void CustomizeUpdate() override;


	};
}