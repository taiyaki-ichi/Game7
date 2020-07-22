#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"

namespace Game::StageSelect
{
	class StageSelect;

	class WarpBox : public GameLib::Actor
	{
		GameLib::Collider mCollider;

		//BoxのTextureは768*768固定
		GameLib::DrawTexture mTexture;

		//isVaildがfalseの場合
		GameLib::DrawRect mRect;

	public:
		//StageNumから位置を決定,
		WarpBox(StageSelect* stageSelect, std::string&& textureFileName, int stageNum, bool isVaild);
		virtual ~WarpBox() = default;

		void CustomizeUpdate() override;

		//待機位置から出現さす
		void Up();
		//待機位置へ
		void Down();

	};
}