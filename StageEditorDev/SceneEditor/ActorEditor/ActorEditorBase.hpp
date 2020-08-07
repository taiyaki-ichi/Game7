#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"Data/Data.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"ActorData.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace StageEditor
{


	class ActorEditorBase : public GameLib::Actor
	{
	protected:
		Data<GameLib::Vector2> mPosData;
		Data<std::string> mStringData;

		//スペースで削除する用の当たり判定
		//派生クラスでタテヨコ位置などを設定
		GameLib::Collider mCollider;

	private:
		//この名前でJsonに記述される
		std::string mNameTag;

	public:
		ActorEditorBase(GameLib::Actor* actor, std::string&& nameTage, int posDataNum, int stringDataNum);
		virtual ~ActorEditorBase() = default;

		bool IsOK();

		void AddData(GameLib::Vector2&& pos);
		void AddData(std::string&& str);

		void PrintStringData();

		virtual void BeginWorking() = 0;
		virtual void BeginToRest() = 0;

		//jsonファイル作成用
		ActorData GetData();

		//loadStageで初期化の際に使用
		void SetData(std::vector<float>&& floatData, std::vector<std::string>&& stringData);
	};


}