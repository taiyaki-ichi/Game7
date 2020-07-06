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

		//íœ‚·‚é‚Æ‚«‚Æ‚©‚Ég‚¤
		GameLib::Collider mDefaultCollider;

	public:
		//posNum‚Í‚PˆÈã
		ActorEditorBase(SceneEditor* owner, std::string&& nameTag, int posInfoNum);
		virtual ~ActorEditorBase();

		//PosInfo‚Ö‚Ì“ü—Í
		void CustomizeUpdate() override final;

		virtual void ActorEditorUpdate() {}

		//PosInfo‚ª—LŒø‚È’l‚ğ‚Á‚½‚©‚Ç‚¤‚©
		bool IsOk();

		//
		virtual void Pause() = 0;
		virtual void Active() = 0;

		//json‚É‘‚«‚Ş‚æ‚¤
		Datas GetData();

		const std::string& GetActorName() const noexcept;
	};
}