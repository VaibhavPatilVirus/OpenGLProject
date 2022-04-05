#include "VendorAPIsPCH.h"
#include "Application.h"

Application::Application()
{
	mWindow = nullptr;
	doRun = true;
}

Application::~Application()
{

}

/*Application(const Application& other)
{
mAppSettings = other.mAppSettings;
mWindow = std::move(other.mWindow);
}*/

void Application::Init()
{
	WindowData winData;
	winData.size.mWidth = 800;
	winData.size.mHeight = 800;
	winData.mTitle = "Application Window";
	mWindow = std::shared_ptr<Window>(Window::createWindow(winData));
}

void Application::terminate()
{
	
}

bool Application::start()
{
	bool es = false;
	Init();
	mWindow->makeCurrentContext();
	mWindow->enableDepthTest();

	while (mWindow->isRunning())
	{
		
		std::mutex m;
		m.lock();
		mWindow->draw();
		m.unlock();
	}
	terminate();
	return es;
}
