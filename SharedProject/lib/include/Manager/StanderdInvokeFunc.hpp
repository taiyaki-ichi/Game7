#pragma once


namespace GameLib
{

	template<typename T>
	struct UpdatePolicy {
		void operator()(T* ptr) {
			ptr->Update();
		}
	};

}