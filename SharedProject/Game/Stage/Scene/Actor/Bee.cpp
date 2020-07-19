#include"Bee.hpp"
#include"Utility/IsInScope.hpp"
#include"Game/Window.hpp"
#include"Game/Stage/Gravity.hpp"
#include"Utility/AdjustRot.hpp"

namespace Game::Stage::Bee
{
	Actor::Actor(Scene* scene, std::vector<float>&& data)
		:ActorBase{ scene }
		, mAnim{}
		, mStateManager{}
	{
		mAnim.AddAnimation({
			"../Assets/Enemy/Bee/active001.png",
			"../Assets/Enemy/Bee/active002.png",
			"../Assets/Enemy/Bee/active003.png",
			"../Assets/Enemy/Bee/active002.png"
		});
		mAnim.AddAnimation({ "../Assets/Enemy/Bee/fall.png" });
		mAnim.SetAnimationFPS(8);
		mAnim.SetScale(0.08f);

		GameLib::Collider weakness{};
		weakness.SetScale(0.08f);
		weakness.SetWidthAndHeith(500.f, 200.f);
		weakness.SetColor({ 255,0,0,255 });

		GameLib::Collider strength{};
		strength.SetScale(0.08f);
		strength.SetWidthAndHeith(500.f, 200.f);
		strength.SetColor({ 0,0,255,255 });

		std::cout << "a";

		if (data.size() == 4)
			mStateManager.SetState(new StraightActive{ &mAnim,std::move(data) });
		else
			mStateManager.SetState(new CircleActive{ &mAnim,std::move(data) });

	}

	bool Actor::UpdateOrNot() {
		auto pos = mAnim.GetPosition();
		return IsInScope(pos, WINDOW_WIDTH + 200.f, WINDOW_WIDTH + 200.f) && StageIsNotRotation();
	}

	void Actor::ActorUpdate() {
		mAnim.Update();
		mStateManager.Update();
	}

	void Actor::Active() {
		mAnim.SetIsAutoDrawing(true);
		mStateManager.Active();
	}

	void Actor::Pause() {
		mAnim.SetIsAutoDrawing(false);
		mStateManager.Pause();
	}

	


	StraightActive::StraightActive(GameLib::DrawAnimation* anim, std::vector<float>&& data)
		:StateBase{}
		,mAnim{anim}
		,mWeakness{}
		,mStrength{}
		, mCenter{ GameLib::Vector2{data[0],data[1]} /2.f + GameLib::Vector2{data[2],data[3]}/2.f }
		,mRadiusVec{ GameLib::Vector2{data[0],data[1]} / 2.f - GameLib::Vector2{data[2],data[3]} / 2.f}
		,mCnt{0}
	{
		/*
		for (int i = 0; i < 4; i++)
			std::cout << i << ": " << data[i] << "\n";
		mCenter = GameLib::Vector2{ data[0] + data[2],data[1] + data[3] } / 2.f;
		*/
		mWeakness.SetScale(0.08f);
		mWeakness.SetWidthAndHeith(500.f, 200.f);
		mWeakness.SetColor({ 255,0,0,255 });
		
		mStrength.SetScale(0.08f);
		mStrength.SetWidthAndHeith(500.f, 200.f);
		mStrength.SetColor({ 0,0,255,255 });
	}

	StateBase* StraightActive::Update()
	{

		float rate = 0.03f;
		float rot = mCnt * rate;
		auto pos = mCenter + std::cos(rot) * mRadiusVec;;

		//std::cout << "center: " << mCenter.x << "," << mCenter.y << "\n";
		//std::cout << "pos: " << pos.x << "," << pos.y << "\n";
		mAnim->SetPosition(pos);
		//mAnim->SetPosition();

		mWeakness.SetPosition(pos + Gravity::GetVector2(Dir4::Up, 10.f));
		mStrength.SetPosition(pos + Gravity::GetVector2(Dir4::Down, 10.f));
		
		rot = AdjustRot(rot);
		if (rot < GameLib::PI)
			mAnim->SetRotation(-std::atan2(mRadiusVec.x, mRadiusVec.y) + GameLib::PI / 2.f);
		else
			mAnim->SetRotation(-std::atan2(mRadiusVec.x, mRadiusVec.y) - GameLib::PI / 2.f);

		mCnt++;
		
		return this;
	}

	void StraightActive::Active()
	{
		mWeakness.Active();
		mStrength.Active();
	}

	void StraightActive::Pause()
	{
		mWeakness.Pause();
		mStrength.Pause();
	}

	CircleActive::CircleActive(GameLib::DrawAnimation* anim,std::vector<float>&& data)
		:StateBase{}
		, mAnim{anim}
		,mCenter{data[0],data[1]}
		, mRadiusVec{ GameLib::Vector2{data[2],data[3]} - GameLib::Vector2{data[0],data[1]} }
		,mDir{0}
		,mCnt{0}
		, mWeakness{}
		, mStrength{}
	{
		auto p1 = GameLib::Vector2{ data[0],data[1] };
		auto p2 = GameLib::Vector2{ data[2],data[3] };
		auto p3 = GameLib::Vector2{ data[4],data[5] };

		if (GameLib::Vector2::Cross(p2 - p1, p3 - p2) > 0.f) 
			mDir = 1.f;
		else 
			mDir = -1.f;
		
		mWeakness.SetScale(0.08f);
		mWeakness.SetWidthAndHeith(500.f, 200.f);
		mWeakness.SetColor({ 255,0,0,255 });

		mStrength.SetScale(0.08f);
		mStrength.SetWidthAndHeith(500.f, 200.f);
		mStrength.SetColor({ 0,0,255,255 });
	}

	StateBase* CircleActive::Update()
	{

		float rate = 0.03f;
		auto adjust = GameLib::Vector2::Rotation(mRadiusVec, mCnt * rate * mDir);
		auto pos = mCenter + adjust;

		mAnim->SetPosition(pos);
		mWeakness.SetPosition(pos + Gravity::GetVector2(Dir4::Up, 10.f));
		mStrength.SetPosition(pos + Gravity::GetVector2(Dir4::Down, 10.f));

		float rot = -std::atan2(adjust.x, adjust.y);

		if (mDir < 0.f)
			mAnim->SetRotation(rot + GameLib::PI);
		else
			mAnim->SetRotation(rot);


		mCnt++;

		return this;
	}

	void CircleActive::Active()
	{
		mWeakness.Active();
		mStrength.Active();
	}

	void CircleActive::Pause()
	{
		mWeakness.Pause();
		mStrength.Pause();
	}

}