#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<unordered_map>

namespace StageEditor
{
	class PosInfo;
	class SceneEditor;

	struct ActorData {
		std::string mActorName;
		std::unordered_map<std::string, float> mDatas;
	};

	class ActorEditorBase : public GameLib::Actor
	{
		std::string mActorName;

		std::vector<PosInfo*> mPosInfos;
		int mPosInfoNum;

	public:
		//posNumは１以上
		ActorEditorBase(SceneEditor* owner, std::string&& nameTag, int posInfoNum);
		virtual ~ActorEditorBase();

		//PosInfoへの入力
		void CustomizeUpdate() override final;

		virtual void ActorEditorUpdate() {}

		//PosInfoが有効な値を持ったかどうか
		bool IsOk();

		//
		virtual void Pause() = 0;
		virtual void Active() = 0;

		//jsonに書き込むよう
		virtual ActorData GetDateObject();
	};
}