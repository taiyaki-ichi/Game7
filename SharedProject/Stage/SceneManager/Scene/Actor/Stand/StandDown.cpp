#include"StandDown.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"StandParam.hpp"
#include"StandActive.hpp"

namespace Stage
{
	namespace StandState
	{
		Down::Down(GameLib::DrawAnimation* head,GameLib::DrawAnimation* body)
			:StateBase<>{}
			, mHeadAnim{head}
			, mBodyAnim{ body }
			, mCnt{ 0 }
		{
			mHeadAnim->SetChannel(2);
			mBodyAnim->SetChannel(1);

			auto adjustHead = GameLib::Vector2{ 0.f,StandParam::DOWN_HEAD_ADJUST_UP };
			adjustHead = GameLib::Vector2::Rotation(adjustHead, mBodyAnim->GetRotation());
			mHeadAnim->SetPosition(mBodyAnim->GetPosition() + adjustHead);
		}

		StateBase<>* Down::Update()
		{
			if (mCnt >= StandParam::DOWN_TIME)
				return new Active{ mHeadAnim,mBodyAnim };

			mCnt++;

			return this;
		}

		void Down::BeginWorking()
		{

		}

		void Down::BeginToRest()
		{

		}

		
	}
}