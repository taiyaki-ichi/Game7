#include"CreateWarp.hpp"
#include"Actor/GuruWarp.hpp"

namespace Game::Stage
{
	WarpBase* CreateWarp(Scene* scene, std::string&& warpGateType,std::vector<float>&& data = {})
	{
		if (warpGateType == "Guru")
			return new GuruWarp{ scene ,std::move(data) };

		return nullptr;
	}
}