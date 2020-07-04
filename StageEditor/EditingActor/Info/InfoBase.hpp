#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<string>

namespace StageEditor
{
	class EditingActorBase;

	class InfoBase : public GameLib::Actor
	{
		enum class InfoState {
			Stay,
			Editing,
			Confirmed,
		};

		//Vector2とかfloatかDir2とか
		std::string mInfoType;

		//PosとかColorとか
		std::string mInfoName;

		InfoState mInfoState;


		virtual void PrintInfo() = 0;

	protected:
		//情報を獲得したら呼び出す
		void InfoConfirmed();

	public:
		InfoBase(EditingActorBase* owner, std::string&& infoType, std::string&& infoName);
		virtual ~InfoBase() = default;

		void CustomizeUpdate() override final;
		//情報の決定方法と終了条件（InfoConfirmedを呼ぶ）
		virtual void EditingInfoUpdate() = 0;

		//InfoStateがConfirmedかどうか
		bool IsOK();

		//情報の表示
		void Print();

		//jsonへの出力用関数、あとで
		//void hoge()=0;
	};
}