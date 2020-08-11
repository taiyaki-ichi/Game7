#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"
#include<vector>

namespace Stage
{
	//GroundGenerator���琶��
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

		void BeginWorking() override;
		void BeginToRest()override;

		void LoadPosData(std::vector<GameLib::Vector2>&& floatData) override {};

	};


	//�傫������Ɠ����蔻�肪����ɓ����Ȃ��̂ŕ���������
	class GroundGenerator : public ActorBase
	{
	public:
		GroundGenerator(GameLib::Actor* scene);
		virtual ~GroundGenerator() = default;

		void BeginWorking() override {};
		void BeginToRest() override {};

		//������Ground�𐶐�
		void LoadPosData(std::vector<GameLib::Vector2>&&) override;
	};

}