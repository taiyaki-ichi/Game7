#include"PlayerStateManager.hpp"
#include"PlayerActive.hpp"
#include"PlayerDeath.hpp"
#include"PlayerFlag.hpp"

namespace Stage
{
	
	void PlayerStateManager::CustomizeUpdate()
	{
		if (CheckFlag(PlayerFlag::DEATH_FLAG)) 
			SetState(new PlayerDeath{ this,mAnim });
		
	}
	void PlayerStateManager::SetPosition(const GameLib::Vector2& pos)
	{
		if (mNowState)
		{
			auto playerState = static_cast<PlayerStateBase*>(mNowState);
			playerState->SetPosition(pos);
		}
	}
}