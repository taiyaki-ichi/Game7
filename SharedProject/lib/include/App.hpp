#pragma once
#include<string>
#include<memory>

namespace GameLib
{

	class RootActor;

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

		//RootActorのポインタを渡しAppを開始さす
		virtual void Start(RootActor* rootActor) = 0;
	};

	//Appのポイントはここから入手	
	std::unique_ptr<App> CreatAppPtr(WindowData&& windowData);

}