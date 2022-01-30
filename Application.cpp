#include "VendorAPIsPCH.h"
#include "Application.h"

Application::Application()
{
	mWindow = std::shared_ptr<MainWindow>(new MainWindow(800, 800));
}

Application::~Application()
{

}

/*Application(const Application& other)
{
mAppSettings = other.mAppSettings;
mWindow = std::move(other.mWindow);
}*/

bool Application::window1()
{
	bool es = false;
	//Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	mWindow->init();
	mWindow->show();
	return es;
}

bool Application::start()
{
	bool es = false;
	window1();
	return es;
}
