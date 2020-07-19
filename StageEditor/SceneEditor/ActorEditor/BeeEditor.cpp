#include"BeeEditor.hpp"

namespace StageEditor
{
	StraightBeeEditor::StraightBeeEditor(SceneEditor* scene)
		:ActorEditorBase{scene,"StraightBee",2}
		, mTexture{"../Assets/Enemy/Bee/active001.png"}
		, mLine{}
	{
		mTexture.SetScale(0.08f);

		mDefaultCollider.SetScale(0.08f);
		mDefaultCollider.SetWidthAndHeith(500.f, 500.f);

	}
	void StraightBeeEditor::ActorEditorUpdate()
	{
		auto pos = GetPosInfos();

		if (pos.size() == 1) {
			mTexture.SetPosition(pos[0]->GetPosition());
			mDefaultCollider.SetPosition(pos[0]->GetPosition());
		}
		else {
			auto p1 = pos[0]->GetPosition();
			auto p2 = pos[1]->GetPosition();

			mTexture.SetPosition(p2);
			mDefaultCollider.SetPosition(p2);
			mLine.SetPoints(p1, p2);

			auto vec = p2 - p1;
			mTexture.SetRotation(-std::atan2(vec.x, vec.y) - GameLib::PI / 2.f);
		}
	}
	void StraightBeeEditor::Active()
	{
		mTexture.SetIsAutoDrawing(true);
		mLine.SetIsAutoDrawing(true);
		mDefaultCollider.Active();
	}
	void StraightBeeEditor::Pause()
	{
		mTexture.SetIsAutoDrawing(false);
		mLine.SetIsAutoDrawing(false);
		mDefaultCollider.Pause();
	}

	CircleBeeEditor::CircleBeeEditor(SceneEditor* scene)
		:ActorEditorBase{scene,"CircleBee",3}
		,mTexture{"../Assets/Enemy/Bee/active001.png"}
		, mCircle{}
	{
		mTexture.SetScale(0.08f);

		mCircle.SetIsFill(false);

		mDefaultCollider.SetScale(0.08f);
		mDefaultCollider.SetWidthAndHeith(500.f, 500.f);
	}

	void CircleBeeEditor::ActorEditorUpdate()
	{
		auto pos = GetPosInfos();

		if (pos.size() == 1) {
			mTexture.SetPosition(pos[0]->GetPosition());
			mDefaultCollider.SetPosition(pos[0]->GetPosition());
		}
		else if (pos.size() == 2) {
			auto p1 = pos[0]->GetPosition();
			auto p2 = pos[1]->GetPosition();
			auto vec = p2 - p1;

			mCircle.SetPosition(p1);
			mCircle.SetRadius(vec.Length());

			mTexture.SetPosition(p2);
			mTexture.SetRotation(-std::atan2(vec.x, vec.y));

			mDefaultCollider.SetPosition(p2);
		}
		else {
			auto p1 = pos[0]->GetPosition();
			auto p2 = pos[1]->GetPosition();
			auto p3 = pos[2]->GetPosition();
			auto vec1 = p2 - p1;
			auto vec2 = p3 - p2;

			mCircle.SetPosition(p1);
			mCircle.SetRadius(vec1.Length());

			float rot;
			if (GameLib::Vector2::Cross(vec1, vec2) < 0.f)
				rot = -std::atan2(vec1.x, vec1.y) - GameLib::PI;
			else
				rot = -std::atan2(vec1.x, vec1.y);
			
			auto vec = GameLib::Vector2::Rotation(GameLib::Vector2{ 20.f,0.f }, rot);

			mTexture.SetPosition(p2 - vec);
			mTexture.SetRotation(rot);

			mDefaultCollider.SetPosition(p2 - vec);
		}

		
	}

	void CircleBeeEditor::Active()
	{
		mTexture.SetIsAutoDrawing(true);
		mCircle.SetIsAutoDrawing(true);
		mDefaultCollider.Active();
	}

	void CircleBeeEditor::Pause()
	{
		mTexture.SetIsAutoDrawing(false);
		mCircle.SetIsAutoDrawing(false);
		mDefaultCollider.Pause();
	}
}