#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"Data/Data.hpp"
#include"Data/PosData.hpp"
#include"ActorData.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace StageEditor
{


	class ActorEditorBase : public GameLib::Actor
	{
	protected:
		PosData mPosData;
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

		void CustomizeUpdate() override final;
		virtual void Update() {};

		//SceneEditorから文字列が送られてくる
		void ForwardStringData(std::string&& str);
		
		//入力されたデータ、次のデータが何番目に入力されるかの表示
		void PrintStringData();
		//PrintStringDataの前に呼び出される、何番目のデータがなんのデータかの説明用
		virtual void PrintStringDataInfo() {};

		void BeginBeginWorking();
		void BeginBeginToRest();
		virtual void BeginWorking() = 0;
		virtual void BeginToRest() = 0;

		//jsonファイル作成用
		ActorData GetData();

		//loadStageで初期化の際に使用
		void SetData(std::vector<float>&& floatData, std::vector<std::string>&& stringData);
	};


}