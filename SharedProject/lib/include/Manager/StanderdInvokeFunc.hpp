#pragma once


namespace GameLib
{

	template<typename T>
	struct Update {
		void operator()(T* ptr) {
			ptr->Update();
		}
	};

}