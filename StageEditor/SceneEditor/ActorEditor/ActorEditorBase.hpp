#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include<vector>

namespace StageEditor
{
	class PosInfo;
	class SceneEditor;

	using Datas = std::vector<float>;

	class ActorEditorBase : public GameLib::Actor
	{
		std::string mActorName;

		std::vector<PosInfo*> mPosInfos;
		int mPosInfoNum;

	protected:
		const std::vector<PosInfo*>& GetPosInfos();

		//削除するときとかに使う
		GameLib::Collider mDefaultCollider;

	public:
		//posNumは１以上
		ActorEditorBase(SceneEditor* owner, std::string&& nameTag, int posInfoNum);
		virtual ~ActorEditorBase();

		//PosInfoへの入力
		void CustomizeUpdate() override final;

		virtual void ActorEditorUpdate() {}

		//PosInfoが有効な値を持ったかどうか
		bool IsOk();

		//Colliderと描画のコントロール
		virtual void Pause() = 0;
		virtual void Active() = 0;

		//jsonに書き込むよう
		Datas GetData();
		const std::string& GetActorName() const noexcept;

		//jsonから読み込むとき用
		void SetData(std::vector<float>&& data);
	};
}