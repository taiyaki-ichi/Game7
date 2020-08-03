#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"
#include<vector>

namespace Stage
{
	//GroundGenerator‚©‚ç¶¬
	class Ground : public ActorBase
	{
		GameLib::Collider mCollider;
		GameLib::DrawRect mDrawRect;

		GameLib::Vector2 mPosition;
		float mWidth;
		float mHeigth;

	public:

		constexpr static float MAX_SIZE = 300.f;

		Ground(GameLib::Actor* scene, float left, float right, float bottom, float top);
		virtual ~Ground() = default;

		void Active() override;
		void Pause()override;

		void LoadData(std::vector<float>&& floatData) override {};

	};


	//‘å‚«‚·‚¬‚é‚Æ“–‚½‚è”»’è‚ª³í‚É“­‚©‚È‚¢‚Ì‚Å•ªŠ„‚³‚¹‚é
	class GroundGenerator : public ActorBase
	{
	public:
		GroundGenerator(GameLib::Actor* scene);
		virtual ~GroundGenerator() = default;

		void Active() override {};
		void Pause() override {};

		//‚±‚±‚ÅGround‚ğ¶¬
		void LoadData(std::vector<float>&& floatData) override;
	};

}