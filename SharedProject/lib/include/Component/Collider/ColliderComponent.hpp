#pragma once
#include<utility>
#include<string>
#include<unordered_map>
#include<functional>
#include<optional>
#include"lib/include/Component/Draw/SpriteCompoent.hpp"
#include"lib/include/Math/Vector2.hpp"


namespace GameLib
{
	class CoordinateActor;

	class ColliderComponent : public SpriteComponent
	{
		//基本情報
		CoordinateActor* mCoordinateActor;
		float mWidth;
		float mHeight;
		Vector2 mAdjust;
		//識別用タグ
		std::string mName;

		//描写される際の色
		Color mColor;

		//描写するかどうか
		static bool mIsDrawing;

		//当たったColliderComponentのNameタグと呼び出すべき関数を保持
		//void(ColliderComponent*, ColliderComponent*)の第一引数が自身のColliderComponennt、第二が衝突しているCollider
		std::unordered_map<std::string, std::function<void(ColliderComponent*, ColliderComponent*)>> mHitFunctions;


	public:
		ColliderComponent(CoordinateActor* owner,std::string&& name, float width, float heigth, Color&& color = { 0,0,0,255 }, int updateOrder = 0);
		virtual ~ColliderComponent();

		//あるColliderComponentと衝突する可能性がある場合、すなわち同じ分割された空間内ににあるとき
		//呼び出すべき関数があるなら詳しい当たり判定を実行
		//そうでないならnulloptを返し当たり判定を行わない
		std::optional<std::function<void(ColliderComponent*, ColliderComponent*)>> GetHitFunction(const std::string& name);


		virtual void Draw() override;

		void SetWidthAndHeigth(float w, float h);
		void SetColor(Color&& color);
		void SetName(std::string&& name);

		static void SetIsDrawing(bool d);

	
	
	};

}