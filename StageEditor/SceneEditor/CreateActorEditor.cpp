#include"CreateActorEditor.hpp"
#include"ActorEditor/GroundEditor.hpp"
#include"ActorEditor/PlayerEditor.hpp"
#include"ActorEditor/CameraEditor.hpp"
#include"ActorEditor/TripleEditor.hpp"
#include"ActorEditor/WarpEditor.hpp"
#include"ActorEditor/GravityBoxEditor.hpp"
#include"ActorEditor/TogeEditor.hpp"
#include"ActorEditor/BeeEditor.hpp"

namespace StageEditor
{

	ActorEditorBase* CreateActorEditor(SceneEditor* sceneEditor, const std::string& actorName, std::vector<float>&& data)
	{
		ActorEditorBase* ptr = nullptr;
		
		////////////////////////////////////////////////////////////////////
		//ここにEditngActorBaseの派生クラスを追加していく、、めんどすぎる
		////////////////////////////////////////////////////////////////////

		if (actorName == "Ground")
			ptr = new GroundEditor{ sceneEditor };
		if (actorName == "Player")
			ptr = new PlayerEditor{ sceneEditor };
		if (actorName == "Camera")
			ptr = new CameraEditor{ sceneEditor };
		if (actorName == "Triple")
			ptr = new TripleEditor{ sceneEditor };
		if (actorName == "Warp")
			ptr = new WarpEditor{ sceneEditor };
		if (actorName == "GravityBox")
			ptr = new GravityBoxEditor{ sceneEditor };
		if (actorName == "Toge")
			ptr = new TogeEditor{ sceneEditor };
		if (actorName == "StraightBee")
			ptr = new StraightBeeEditor{ sceneEditor };
		if (actorName == "CircleBee")
			ptr = new CircleBeeEditor{ sceneEditor };



		///////////////////////////////////////////////////////////////////

		if (ptr && data.size() > 0)
			ptr->SetData(std::move(data));

		return ptr;
	}

}