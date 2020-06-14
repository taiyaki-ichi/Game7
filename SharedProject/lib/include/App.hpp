#pragma once
#include<string>
#include<memory>
#include<type_traits>
#include"Actor/RootActor.hpp"
namespace GameLib
{
	struct WindowData {
		std::string WindowName;
		float WindowWidth;
		float WindowHeigth;
	};


	class App
	{
	protected:
		App() = default;

	public:
		virtual ~App() = default;

		//RootActorの型を渡しAppスタート
		template<typename StartActor,typename ...Args>
		void Start(Args&& ...args) {
			static_assert(std::is_base_of_v<RootActor,StartActor>, "RootActor is not base of StartActor");
			RootActor* rootActor = new StartActor(std::forward<Args>(args)...);
			StartImpl(rootActor);
		}

	private:
		virtual void StartImpl(RootActor* rootActor) = 0;
	};

	//Appのポインタはここから入手	
	std::unique_ptr<App> CreatAppPtr(WindowData&& windowData);

}